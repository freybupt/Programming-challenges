#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
#include<fstream>
using namespace std;

inline int factorial(int x) {
    return (x == 1 ? x : x * factorial(x - 1));
}

int bucketSize(int numberOfIndex){
    return factorial(numberOfIndex);
}

int main(){
    clock_t begin = clock();
    
    int sum = 1000000;
    
    for (int i = 9; i > 0; i --) {
        for (int j = 0; j < 10 ; j++) {
            if (j*bucketSize(i) <= sum && (j+1)*bucketSize(i) > sum) {
                cout<<"Index: "<<j<<" at the "<<i<<" round"<<endl;
                sum = sum - j*bucketSize(i);
//                cout<<"Sum is"<<sum<<endl;
            }
        }
    }
    
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"Time elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}


