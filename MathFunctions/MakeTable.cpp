#include "config.h"
#include <cmath>

#include <fstream>
#include <cstdlib>
using namespace std;
int main (int argc, char *argv[]){

    if (argc<2){
        return 1;
    }

    // create a source file with a table of square roots
    ofstream fout;
    fout.open(argv[1]);
    if (!fout.is_open()){
        return 1;
    }
    int num = atoi(argv[1]);
    double result=0;
    fout << "double sqrtTable[] = {\n";
    for (int i = 0; i < num; ++i){
        result = sqrt(static_cast<double>(i));
        fout<<result<<",\n";
    }
    // close the table with a zero
    fout<<"0};\n";
    fout.close();
    return 0;
}
