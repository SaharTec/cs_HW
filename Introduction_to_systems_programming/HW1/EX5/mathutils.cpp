
#include <iostream>
#include <vector>
#include <numeric> 
#include <cmath>

namespace MathUtils {

    //מספרים ראשוניים
    bool isPrime(int num){
        if(num <= 1) return false;
        if(num == 2) return true;
        if(num % 2 == 0) return false;
        for(int i = 3; i * i <= num; i += 2){ 
            if(num % i == 0) return false;
        }
        return true;
    }

    //בדיקת מספר מושלם
    bool printPerfectNumbers(int num){
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
    double getAverage(const std::vector<int>& numbers){
        if(numbers.empty()) return 0.0;

        int sum = 0;
        for(int num : numbers){
            sum += num;
        }
        return double(sum) / numbers.size();
    }

    void printPrimes(const std:: vector<int>& numbers){
        std::cout <<"prime numbers: ";

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

    void printPerfectNumbers(const std::vector<int>& numbers) {
        bool foundAny = false;
        for (int num : numbers) {
            if (printPerfectNumbers(num)) {
                if (foundAny) {
                    std::cout << " ";
                }
                std::cout << num;
                foundAny = true;
            }
        }
        if (!foundAny) {
            std::cout << "None";
        }
        std::cout << std::endl;
    }
}