#include "config.h"

#ifdef USE_MYMATH
#include "MathFunctions.h"
#else
#include <cmath>
#endif

#include <iostream>
#include <cstdlib>
#include <cstdio>

int main (int argc, char *argv[]){
    std::cout<< argv[0]<<" version is "<<justDoIt_VERSION_MAJOR<<"."<<justDoIt_VERSION_MINOR<<std::endl;
#ifdef HAVE_PRINTF
    std::cout<<"floolwing is printf()"<<std::endl;
    printf("This is my prntf command\n");
#else
std::cout<<"no printf"<<std::endl;

#endif

    if (argc<2){
        std::cout<< "Usage: "<<argv[0]<<" number"<<std::endl;
    }
    else{
        double inVal = atof(argv[1]);
        // if (inVal<0) inVal*=-1;

#ifdef HAVE_PRINTF
        std::cout<< "HAVE_PRINTF Enable"<< std::endl;
#else
        std::cout<< "HAVE_PRINTF disable"<< std::endl;
#endif

#ifdef HAVE_EXP
        std::cout<< "HAVE_EXP Enable"<< std::endl;
#else
        std::cout<< "HAVE_EXP disable"<< std::endl;
#endif

#ifdef HAVE_LOG
        std::cout<< "HAVE_LOG Enable"<< std::endl;
#else
        std::cout<< "HAVE_LOG disable"<< std::endl;
#endif
#ifdef HAVE_MEMSET
        std::cout<< "HAVE_MEMSET Enable"<< std::endl;
#endif
#ifdef USE_MYMATH
        std::cout<< "MyMAth Enable"<< std::endl;
#endif
#ifdef USE_MYMATH
        double outVal = mysqrt(inVal);
#else
        double outVal = sqrt(inVal);
#endif

        std::cout<<"The square root of "<< inVal<< " is "<<outVal <<std::endl;


    }
    return 0;
}
