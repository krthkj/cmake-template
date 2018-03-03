#include <iostream>
#include <cmath>
#include "config.h"

int main (int argc, char *argv[]){
    std::cout<< argv[0]<<" version is "<<justDoIt_VERSION_MAJOR<<"."<<justDoIt_VERSION_MINOR<<std::endl;
    if (argc<2){
        std::cout<< "Usage: "<<argv[0]<<" number"<<std::endl;
    }
    else{
        double inVal = atof(argv[1]);
        double outVal = sqrt(inVal);
        std::cout<<"The square root of "<< inVal<< " is "<<outVal <<std::endl;
    }
    return 0;
}
