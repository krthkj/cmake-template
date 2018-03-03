#include "config.h"

#ifdef USE_MYMATH
#include "MathFunctions.h"
#else
#include <cmath>
#endif

#include <iostream>
#include <cstdlib>

int main (int argc, char *argv[]){
    std::cout<< argv[0]<<" version is "<<justDoIt_VERSION_MAJOR<<"."<<justDoIt_VERSION_MINOR<<std::endl;
    if (argc<2){
        std::cout<< "Usage: "<<argv[0]<<" number"<<std::endl;
    }
    else{
        double inVal = atof(argv[1]);
        // if (inVal<0) inVal*=-1;
#ifdef USE_MYMATH
        double outVal = mysqrt(inVal);
        std::cout<< "Using myMath"<<std::endl;
#else
        double outVal = sqrt(inVal);
#endif
        std::cout<<"The square root of "<< inVal<< " is "<<outVal <<std::endl;
    }
    return 0;
}
