#include "data.hpp"
#include "exception.hpp"
#include <fstream>
#include <iostream>

//lString

//to-do

//dataArray

uint8_t* llcd::data::dataArray::getData(){
    return data;
};
uint32_t llcd::data::dataArray::getSize(){
    return size;
};
llcd::data::dataArray::dataArray(){
    this->size = 0;
    this->data = nullptr;
}
llcd::data::dataArray::dataArray(const char* filename){
    std::ifstream file_in(filename, std::ios::binary);
    file_in.seekg(0, file_in.end);
    size_t file_size = file_in.tellg();
    file_in.seekg(0, file_in.beg);
    data = new uint8_t[file_size];
    file_in.read(reinterpret_cast<char*>(data), file_size);
    file_in.close();
};
llcd::data::dataArray::dataArray(uint8_t* data,uint32_t size){
    this->size = size;
    if(this->size==0)this->data = nullptr;
    else{
        this->data = new uint8_t[size];
        for(uint32_t i = 0;i<size;i++){
            this->data[i] = data[i];
        }
    }
    
};
llcd::data::dataArray::dataArray(dataArray& data){
    this->size = data.size;
    if(this->size==0)this->data = nullptr;
    else{
        this->data = new uint8_t[this->size];
        for(uint32_t i = 0;i<this->size;i++){
            this->data[i] = data.data[i];
        }
    }
};
llcd::data::dataArray::~dataArray(){
    if(this->data==0||this->data==nullptr)return;
    else{
        delete [] this->data;
    }
};
void llcd::data::dataArray::save(const char* filename){
    std::ofstream outfile(filename, std::ios::binary);
    outfile.write(reinterpret_cast<char*>(this->data), size);
    outfile.flush();
    outfile.close();
};
void llcd::data::dataArray::reSize(uint32_t size){
    if(this->size==size)return;
    
    if(size==0){
        if(this->data==nullptr)return;
        
        delete [] this->data;
        this->data = nullptr;

        return;
    }
    uint8_t* newData = new uint8_t[size];
    for(uint32_t i = 0;i<size;i++){
        if(this->size>i)newData[i] = this->data[i];
        else newData[i] = 0;
    }
    delete [] this->data;
    this->data = newData;
    this->size = size;
};
void llcd::data::dataArray::push(uint8_t value){
    reSize(this->size+1);
    data[this->size-1] = value;
};
bool llcd::data::dataArray::getBit(uint32_t place,uint8_t bit){
    if(place>=this->size)return false;
    return bool((this->data[place]>>(bit&0b00000111))&0b00000001);
};
uint8_t& llcd::data::dataArray::operator[](uint32_t place){
    if(place>=this->size)throw llcd::exception(e_outFoBounce_error,"you are trying to access value that is not inside this dataArray");
    return this->data[place];
};
void print(){
    //to-do
    throw(llcd::exception(0,"print not implemented"));
}
void printArray(){
    //to-do
    throw(llcd::exception(0,"printArray not implemented"));
}

//helper function

//tells you how much bytes you need for a number
uint8_t llcd::data::staticDSize(uint32_t value){
    if(value<2)return 1;
    else{
        uint32_t candidate = 2;
        uint32_t possible = 4;
        while (true)
        {
            if(value<possible)return candidate;
            candidate++;
            possible<<=1;
        }
        
    }
}

//PbView

llcd::data::PbView::PbView(dataArray& data):data(data.getData()){
    reset();
};
llcd::data::PbView::PbView(uint8_t* data):data(data){
    reset();
};
void llcd::data::PbView::reset(){
    place = 0;
    bit = 0;
    nowValue = data[place];
};
//reads one bit
bool llcd::data::PbView::readBit(){
    bit>>=1;
    if(bit==0){
        place++;
        nowValue = data[place];
        bit = 0b10000000;
    }
    return nowValue&(bit);
};
//reads data like 11110 where 110 is 3 and 0 is 1
uint32_t llcd::data::PbView::readDynamic(){
    uint32_t out = 1;
    while (readBit())
    {
        //increment until get 0 bit
        out++;
    }
    return out;
    
};
//reads data like 10110 where 101(3) is 5 and 0(1) is 1
uint32_t llcd::data::PbView::readStatic(uint8_t size){
    uint32_t out = 0;
    for(uint8_t i = 0;i<size;i++){
        out<<=1;
        out|=readBit();
    }
    return out;
};

//PbReader

llcd::data::PbReader::PbReader(dataArray& data):data(data){
    reset();
};
llcd::data::PbReader::PbReader(dataArray data):data(data){
    reset();
};
//resets the reading place to begining
void llcd::data::PbReader::reset(){
    place = 0;
    bit = 0;
    nowValue = data[place];
};
//reads one bit
bool llcd::data::PbReader::readBit(){
    bit>>=1;
    if(bit==0){
        place++;
        nowValue = data[place];
        bit = 0b10000000;
    }
    return nowValue&(bit);
};
// reads sequence like this 1111110 where zero is terminator
// and returns lengh from 1 to 2^32-2
uint32_t llcd::data::PbReader::readDynamic(){
    uint32_t out = 1;
    while (readBit())
    {
        //increment until get 0 bit
        out++;
    }
    return out;
    
};
//reads seqence of bits like 1101101 which lenght you specify
uint32_t llcd::data::PbReader::readStatic(uint8_t size){
    uint32_t out = 0;
    for(uint8_t i = 0;i<size;i++){
        out<<=1;
        out|=readBit();
    }
    return out;
};

//PbWriter
llcd::data::PbWriter::PbWriter(){
    clear();
};
//clears everyting
void llcd::data::PbWriter::clear(){
    data.reSize(0);
    current = 0;
    bit=0b10000000;
};
//writes exactly one bit
void llcd::data::PbWriter::writeBit(bool value){
    if(bit==0){
        bit = 0b10000000;
        data.push(current);
        current = 0;
    }
    if(value)current|=bit;
    bit>>=1;
};
//writes value like 1111111110 where 1 is 0 and 4 is 1110
void llcd::data::PbWriter::writeDynamic(uint32_t value){
    for(uint32_t i = 0;i<value-1;i++){
        writeBit(true);
    }
    if(value!=0)writeBit(false);
};
//wites value like 101001 where 3(4) is 100 and 3(5) is 101
void llcd::data::PbWriter::writeStatic(uint32_t value,uint8_t size){
    for(uint8_t i = 0;i<size;i++){
        writeBit((value>>(size-(1+i)))&1);
    }
};
//gives you data you've written
llcd::data::dataArray llcd::data::PbWriter::exportData(){
    dataArray out = data;
    if(bit!=0b10000000)out.push(current);
    return out;
};

//bJson