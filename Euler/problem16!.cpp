#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
using namespace std;


int main(){
    clock_t begin = clock();
    
    
    unsigned long input = pow(2, 50);
    
    
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"Time elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}


