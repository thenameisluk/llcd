#pragma once

template<typename T>
llcd::vector<T>::vector():size(0){
    data = nullptr;
}
template<typename T>
llcd::vector<T>::~vector(){
    for(uint32_t i = 0; i < size; i++){
        delete data[i];
    }
    delete [] data;
}
template<typename T>
llcd::vector<T>::vector(vector<T>& v):size(v.size){
    data = new T*[size];
    for (uint32_t i = 0; i < size; i++){
        data[i] = new T(v[i]);
    }
}
template<typename T>
uint32_t llcd::vector<T>::Size(){
    return size;
}
template<typename T>
T& llcd::vector<T>::operator[](uint32_t i){
    if(i>=size){
        throw exception(104,"no in range");
    }
    return *(data[i]);
}
template<typename T>
void llcd::vector<T>::push(T t){
    T** newData = new T*[size+1];
    for (uint32_t i = 0; i < size; i++){
        newData[i] = data[i];
    }
    newData[size] = new T(t);
    delete [] data;
    data = newData;
    size++;
}
template<typename T>
void llcd::vector<T>::forEach(std::function<void(T&)> f){
    for (uint32_t i = 0; i < size; i++){
        f(*(data[i]));
    }
}
template<typename T>
void llcd::vector<T>::forEach(std::function<void(T&,uint32_t)> f){
    for (uint32_t i = 0; i < size; i++){
        f(*(data[i]),i);
    }
}
template<typename T>
void llcd::vector<T>::forEachDel(std::function<bool(T&)> f){
    uint32_t sizeNow = size;
    for (uint32_t i = 0; i < size; i++){
        if(f(*(data[i]))){
            delete data[i];
            data[i] = nullptr;
            sizeNow--;
        }
    }
    if(sizeNow!=size){
        T** newData = new T*[sizeNow];
        uint32_t realI = 0;
        for(uint32_t i = 0;i<size;i++){
            if(data[i]!=nullptr){
                newData[realI] = data[i];
                realI++;
            }
        }
        delete [] data;
        data = newData;
        size = sizeNow;
    }
}
template<typename T>
void llcd::vector<T>::putOnTop(uint32_t i){
    if(i>=size){
        throw exception(104,"no in range");
    }
    T* temp = data[i];
    for(uint32_t j = i;j>0;j--){
        data[j] = data[j-1];
    }
    data[0] = temp;
}
template<typename T>
void llcd::vector<T>::putOnBottom(uint32_t i){
    if(i>=size){
        throw exception(104,"no in range");
    }
    T* temp = data[i];
    for(uint32_t j = i;j<size;j++){
        data[j] = data[j+1];
    }
    data[size-1] = temp;
}