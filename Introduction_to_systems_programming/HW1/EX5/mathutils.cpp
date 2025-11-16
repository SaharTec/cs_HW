
#include "mathutils.h"
#include <iostream>
#include <cmath>

namespace MathUtils {

    //מספרים ראשוניים
    bool isPrime(int num){
        if(num <= 1) return false;
        if(num == 2) return true;
        if(num > 2){
            
            for(int i  = 3 ; i <= sqrt(num); i +=2){
                if(num % i == 0)return false;
            }return true;
        }
    }

    //בדיקת מספר מושלם
    bool isperfectNum(int num){
        if(num <= 1) return false;

        int sum = 0;

        for(int i = 0; i < num ; i++){
            if(num % i == 0){
                sum += i;
            }
        }
        return sum;
    }

    //בדיקת ממוצע
    double average(const std::vector<int>& numbers){
        if(numbers.empty()) return 0.0;

        int sum = 0;
        for(int num : numbers){
            sum += num;
        }
        return double(sum) / numbers.size();
    }

    void printPrime(const std:: vector<int>& numbers){
        std::cout <<"prime numbers";

        bool foundPrime = false;
        for(int num : numbers){
            if(isPrime(num)){
                if(foundPrime) std::cout <<",";
                std::cout << num;
                foundPrime = true;
            }
        }
        if(!foundPrime){
            std::cout<<"None";
        }
        std::cout << std::endl;
    }

    void printPerfectNum(const std:: vector<int>& numbers){
        std::cout <<"perfect numbers";

        bool foundPerfect = false;
        for(int num : numbers){
            if(isperfectNum(num)){
                if (foundPerfect) std::cout << " ";
                std::cout << num;
                foundPerfect = true;
            }
        }
        if (!foundPerfect) {
            std::cout << "None";
        }
        std::cout << std::endl;
    }
}