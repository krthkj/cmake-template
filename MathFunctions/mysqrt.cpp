#include <cmath>
//#include "MathFunctions.h"
double mysqrt(double x){
    double result;
#if defined (HAVE_LOG) && defined (HAVE_EXP)
    result = exp(log(x)*0.5);
#else // otherwise use an iterative approach
    result = sqrt(x);
    // result = exp(log(x)*0.5);
#endif
    return result;
}
