/*
a great pice of code

coded and delivered by L team
code by luk the oop programmer
debbugged by zoz the glaceon

it may break everything it touches
or something i dont know why
some people state that but yes

also no touch touch credits
without premission but if
you want you can modify code
itself so yes
*/

#pragma once
#include "stdint.h"
#include <memory>

namespace llcd{
    namespace data{
        //light string that i trues
        class lString{
            private:
                char* data;
                uint8_t size;
            public:
                lString(uint32_t intV);
                lString(const char* text);
                lString(const char* text,uint8_t size);
                lString(lString& text);
                uint8_t getSize();
                char& at();
                void push(char c);
                void append(lString& text);
                void append(lString text);
                void toInt();
                lString fromTo(uint8_t place,uint8_t size);
                const char* c_str();
        };
        //contains data
        class dataArray{
            private:
                uint8_t* data;
                uint32_t size;
            public:
                uint8_t* getData();
                uint32_t getSize();
                dataArray();
                dataArray(const char* filename);
                dataArray(uint8_t* data,uint32_t size);
                dataArray(dataArray& data);
                ~dataArray();
                void save(const char* filename);
                void reSize(uint32_t size);
                void push(uint8_t value);
                bool getBit(uint32_t place,uint8_t bit);
                uint8_t& operator[](uint32_t place);
                void print();
                void printArray();
        };

        uint8_t staticDSize(uint32_t value);// 0101101
        //like string view but kinda diffrent
        class PbView{
            private:
                uint32_t place = 0;
                uint8_t bit = 0;
                uint8_t nowValue = 0;
                uint8_t* data;
            public:
                PbView(dataArray& data);
                PbView(uint8_t* data);
                //takes the pointer to start of the array
                void reset();
                bool readBit();
                uint32_t readDynamic();
                uint32_t readStatic(uint8_t size);
        };
        //reads data from dataArray
        class PbReader{
            private:
                uint32_t place = 0;
                uint8_t bit = 0;
                uint8_t nowValue = 0;
                dataArray data;
            public:
                PbReader(dataArray& data);
                PbReader(dataArray data);
                //takes the pointer to start of the array
                void reset();
                bool readBit();
                uint32_t readDynamic();
                uint32_t readStatic(uint8_t size);
        };
        //writes data
        class PbWriter{
            private:
                uint8_t current;
                uint8_t bit;
                dataArray data;
            public:
                PbWriter();
                void clear();
                void writeBit(bool value);
                void writeDynamic(uint32_t value);
                void writeStatic(uint32_t value,uint8_t size);
                dataArray exportData();
        };
        class bJson{
            //to-do
        };
    }
}