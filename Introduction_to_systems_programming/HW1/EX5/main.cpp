#include <iostream>
#include <vector>
#include <iomanip>
#include "mathutils.h"

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    
    std::vector<int> numbers;
    std::cout << "Enter " << n << " integers:" << std::endl;
    
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }
    
    // חישוב והדפסת הממוצע
    double avg = MathUtils::getAverage(numbers);
    std::cout << "Average: " << std::fixed << std::setprecision(1) << avg << std::endl;
    
    // הדפסת מספרים ראשוניים
    std::cout << "Prime numbers: ";
    MathUtils::printPrimes(numbers);
    
    // הדפסת מספרים מושלמים
    std::cout << "Perfect numbers: ";
    MathUtils::printPerfectNumbers(numbers);
    
    return 0;
}