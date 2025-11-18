#include "assignutils.h" 
#include <iostream>
#include <cstring>
#include <vector>
#include <cctype> 
using namespace std;

// QUESION 1:
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

// QUESION 2:
void printArray(const int* arr, int size){
    if(size <= 0){
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    for(int i = 0; i < size ; ++i){
        if( i <= size -1 ){
            cout << arr[i] << (i == size - 1 ? "" : ", ");
        }
    }cout << "]" << endl;
}

int* filterAboveThreshold(const int* arr, int size, int threshold, int& newSize){
    newSize = 0;
    
    for(int i = 0; i < size; ++i){ 
        if(arr[i] > threshold){
            newSize++;
        }
    }

    int* filterd = new int[newSize]; 
    int j = 0;
    
    for(int i = 0; i < size; ++i){ 
        if(arr[i] > threshold){
            filterd[j++] = arr[i];
        }
    }
    return filterd;
}


// QUESION 3:
void readVector(vector<int>& vec){
    
    cout << "Enter " << vec.size() << " integers:" << endl;
    for(int i = 0 ; i < vec.size() ; i++){
        cin >> vec[i];
    }

}
void modifyVector(vector<int>& vec){
    int prev = vec[0];

    for(int i = 1; i < vec.size(); i++){
        int curr = vec[i];
        vec[i] = prev + vec[i];
        prev = curr;
    }

    for(int i = 0; i < vec.size(); i++){
        cout << vec[i];
        if(i < vec.size() -1) cout << ", ";
    }
    cout << endl;

}

// QUESION 4: 
void reverseAndCapitalize(char* str){
    if( str == nullptr || str[0] == '\0') return;
    
    int len = strlen(str);

    for(int i = 0; i < len / 2; i++){
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }

    for(int i = 0; i < len; i++){
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        } else if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }

}
