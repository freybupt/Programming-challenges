#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
using namespace std;

//int getNumberOfFactor(long number){
//    int factorNumber = 1;
//    if (number != 1) {
//        factorNumber = 2;
//        unsigned long j = 2;
//        while(j <= number){
//            if (number%j == 0 || number == j) {
//                number = number/j;
//                factorNumber++;
////                cout<<"j is  "<<j<<endl;
////                cout<<"number is "<<number<<endl;
//            }
//            else
//                j += 1;
//        }
//    }
//    
//    return factorNumber;
//}

unsigned long getNumberOfFactor(long number){
    unsigned long factorNumber = 1;
    for (unsigned long i = 1; i<=sqrt(number); i++) {
        if (number%i == 0) {
            factorNumber+=2;
        }
    }
    return factorNumber;
}

unsigned long getTriangleNumber(unsigned long index){
    if (index%2 == 0) {
        long result = (index*index + index)/2;
        return result;
    }
    else{
        long result = (index+1)*floor(index/2)+(index+1)/2;
        return result;
    }
}

int main(){
    unsigned long tNumber = 0;
    unsigned long numberOfFactors = 0;
    for (unsigned long i = 1; numberOfFactors <=500; i++) {
        tNumber = getTriangleNumber(i);
        cout<<"Triangle number "<<tNumber<<" at index: "<<i<<endl;
        numberOfFactors = getNumberOfFactor(tNumber);
        if (numberOfFactors>300) {
            cout<<tNumber<<" : "<<numberOfFactors<<endl;
        }
        
    }
    
    return 1;
}


