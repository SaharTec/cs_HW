#include <iostream>
#include <vector>
#include <iomanip>
#include "mathutils.h"
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> numbers;
    cout << "Enter " << n << " integers:" << endl;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }
    
    // חישוב והדפסת הממוצע
    double avg = MathUtils::getAverage(numbers);
    cout << "Average: " << fixed << setprecision(1) << avg << endl;
    
    // הדפסת מספרים ראשוניים
    cout << "Prime numbers: ";
    MathUtils::printPrimes(numbers);
    
    // הדפסת מספרים מושלמים
    cout << "Perfect numbers: ";
    MathUtils::printPerfectNumbers(numbers);
    
    return 0;
}