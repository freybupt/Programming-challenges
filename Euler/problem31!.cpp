#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
#include<fstream>
using namespace std;

int S[] = {0, 1, 2, 5, 10, 20, 50, 100, 200};
int count(int n, int m){
    if(n == 0)
        return 1;
    else if(n < 0)
        return 0;
    else if(m <= 0 && n >=1){
        return 0;
    }
    else{
        return count(n, m-1) + count(n - S[m], m);
    }
}


int main(){
    clock_t begin = clock();
    cout<<"Result: "<<count(200, 8)<<endl;
        
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"Time elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}


