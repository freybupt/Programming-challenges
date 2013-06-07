#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
#include<fstream>
using namespace std;

static int size = 1001;
int main(){
    clock_t begin = clock();
    
    int startNumber = 1;
    unsigned long increment = 2;
    unsigned long sum = 1;
    unsigned long nextNumber = startNumber;
    for(int i = 0; i <= size-3; i = i+2){
        for (int j = 0; j < 4; j++) {
            nextNumber = nextNumber +increment;
            cout<<nextNumber<<endl;
            sum = sum + nextNumber;
        }
        
        cout<<increment<<'\n'<<endl;
        cout<<"Sum is: "<<sum<<" for "<<i+3<<" grid"<<endl;
        increment +=2;
    }
    
    cout<<"Sum: "<<sum<<endl;
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"Time elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}


