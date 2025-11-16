#include "assignutils.h" 
#include <iostream>
#include <cstring>
#include <cctype> 

/**
 * Q1
 */

 bool isVowel(char c){
    return (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u');
}

char* duplicateVowels(const char* str){
    if(str == nullptr){
        return nullptr;
    }

    size_t og_len = strlen(str);
    size_t new_len = 0;

    for(size_t i = 0; i < og_len ; i++){
        if(isVowel(str[i] == true)){
            new_len = new_len + 2;
        }
        else{
            new_len = new_len +1 ;
        }
    }
    size_t new_size = new_len + 1;
    char* new_str = new char[new_size];

    size_t j = 0;
    for(size_t i = 0; i < og_len; i++){
        char curr_char = str[i];
        if(isVowel(curr_char)){
            new_str[j++] = curr_char;
            new_str[j++] = curr_char;
        }else{
            new_str[j++] = curr_char;
        }
    }
    new_str[j++] = '\0';
    return new_str;
}

/**
 * Q2
 */
void printArray(const int* arr, int size){
    if(size <= 0){
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    for(int i = 0; i < size ; i++){
        if( i <= size -1 ){
            cout << arr[i] << (i == size - 1 ? "" : ", ");
        }
    }cout << "]" << endl;
}

int* filterAboveThreshold(const int* arr, int size, int threshold, int& newSize){
    newSize = 0;
    
    for(int i = 0; i < size; i++){ 
        if(arr[i] > threshold){
            newSize++;
        }
    }

    int* filterd = new int[newSize]; 
    int j = 0;
    
    for(int i = 0; i < size; i++){ 
        if(arr[i] > threshold){
            filterd[j++] = arr[i];
        }
    }
    return filterd;
}
