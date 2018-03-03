#include "config.h"
#include <cmath>

#include <iostream>
#include <cstdlib>

int main (int argc, char *argv[]){
    std::cout<< argv[0]<<" version is "<<justDoIt_VERSION_MAJOR<<"."<<justDoIt_VERSION_MINOR<<std::endl;

    if (argc<2){
        return 1;
    }

    // create a source file with a table of square roots
    FILE *fout = fopen(argv[1],"w");
    if (!fout){
        return 1;
    }
    int num = atoi(argv[1]);
    double result=0;
    fprintf(fout,"double sqrtTable[] = {\n");
    for (int i = 0; i < num; ++i){
        result = sqrt(static_cast<double>(i));
        fprintf(fout,"%g,\n",result);
    }
    // close the table with a zero
    fprintf(fout,"0};\n");
    fclose(fout);
    return 0;
}
