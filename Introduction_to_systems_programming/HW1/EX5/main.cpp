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
    
    // חישוב והצגת ממוצע
    double avg = MathUtils::getAverage(numbers);
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Average: " << avg << std::endl;
    
    // הצגת מספרים ראשוניים
    MathUtils::printPrimes(numbers);
    
    // הצגת מספרים מושלמים
    MathUtils::printPerfectNumbers(numbers);
    
    return 0;
}