#ifndef MATHUTILS_H
#define MATHUTILS_H

#include <vector>

namespace MathUtils {
    // פונקציה שמקבלת רפרנס לוקטור של מספרים שלמים ומחזירה את ממוצע המספרים בו
    double getAverage(const std::vector<int>& numbers);
    
    // פונקציה שמקבלת רפרנס לוקטור של מספרים שלמים ומדפיסה את כל המספרים הראשוניים בו
    void printPrimes(const std::vector<int>& numbers);
    
    // פונקציה שמקבלת רפרנס לוקטור של מספרים שלמים ומדפיסה את כל המספרים המושלמים בו
    void printPerfectNumbers(const std::vector<int>& numbers);
}

#endif