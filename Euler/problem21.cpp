#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
using namespace std;

int getSumOfFactor(int number){
    int sum  = 0;
//    cout<<"Factors of "<<number<<" is ";
    for (int i = 1; i < number; i++) {
        if (number%i == 0) {
//            cout<<i<<"\t";
            sum += i;
        }
    }
//    cout<<"\n"<<endl;
    return sum;
}


int main(){
    clock_t begin = clock();
    int sumNumber = 0;
    for (int  i = 1; i < 10000; i++) {
        int sumOfFactor = getSumOfFactor(i);
        if (i == getSumOfFactor(sumOfFactor) && sumOfFactor != i) {
            sumNumber += i;
            cout<<"Amicable number: "<<i<<" and "<<sumOfFactor<<endl;
        }
    }
    
    cout<<sumNumber<<endl;
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"Time elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}


