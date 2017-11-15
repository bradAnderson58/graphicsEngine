
#include "headers/vector_math/MathFunctions.h"
#include <cmath>

int MathFunctions::factorial(int n) {  // TODO: Memoize this
    int retval = 1;
    if (n > 0) {
        retval = n * factorial(n - 1);
    }
    
    return retval;
}

int MathFunctions::binomialFactorial(int n, int k) {
    int nFactorial = factorial(n);
    int kFactorial = factorial(k) * factorial(n - k);
    
    return nFactorial / kFactorial;
}

float MathFunctions::clampedCos(float n) {
    float retval = cos(n);
    return (retval > 0) ? retval : 0;
}
