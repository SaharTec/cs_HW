
#include <iostream>
#include <vector>
#include <numeric> 
#include <cmath>
using namespace std;

namespace MathUtils {

    //בדיקת ממוצע
    double getAverage(vector<int>& numbers){
        if(numbers.empty()) return 0.0;

        int sum = 0;
        for(int num : numbers){
            sum += num;
        }
        return double(sum) / numbers.size();
    }

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
    bool isPerfectNumber(int num){
        if(num <= 1) return false;

        int sum = 0;

        for(int i = 1; i < num; i++){ 
            if(num % i == 0){
                sum += i;
            }
        }
        return sum == num;  
    }

    
   void printPrimes(vector<int>& numbers){
    bool foundPrime = false;  
    for(int num : numbers){
        if(isPrime(num)){
            if(foundPrime) cout << ", ";
            cout << num;
            foundPrime = true;
        }
    }
    if(!foundPrime){
        cout << "None";
    }
    cout << endl;
}

    void printPerfectNumbers(vector<int>& numbers) {
        bool foundAny = false;
        for (int num : numbers) {
            if (isPerfectNumber(num)) {
                if (foundAny) {
                    cout << " ";
                }
                cout << num;
                foundAny = true;
            }
        }
        if (!foundAny) {
            cout << "None";
        }
        cout << endl;
    }
}