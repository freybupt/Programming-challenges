#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
using namespace std;

unsigned long sizeSum = 0;
int main(){
    clock_t begin = clock();
    //one, two, three, four, five, six, seven, eight, nine, ten
    //eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen
    static int sizeOfNumber1to19[19] = {3,3,5,4,4,3,5,5,4,3,\
        6,6,8,8,7,7,9,8,8};
    //twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety
    static int sizeOfNumber20to90[8] = {6,6,5,5,5,7,6,6};
    static int sizeOfHundred = 7;
    static int sizeOfThousand = 8;
    static int sizeOfAnd = 3;
    int sumOf1to9 = 0;
    
    for (int i=0; i<9; i++) {
        sumOf1to9 += sizeOfNumber1to19[i];
    }
    cout<<"sumOf1to9 "<<sumOf1to9<<endl;
    
    int sumOf1to19 = 0;
    for (int i=0; i<19; i++) {
        sumOf1to19 += sizeOfNumber1to19[i];
    }
    cout<<"sumOf1to19 "<<sumOf1to19<<endl;
    
    int sumOf20to99 = 0;
    for (int i = 0; i<8; i++) {
        sumOf20to99 +=sizeOfNumber20to90[i]*10+sumOf1to9;
    }
    cout<<"sumOf20to99 "<<sumOf20to99<<endl;
    
    int sumOf1to99 = sumOf1to19 + sumOf20to99;
    cout<<"sumOf1to99 "<<sumOf1to99<<endl;
    
    
    sizeSum = sumOf1to99; //up to 99
    
    for (int i=0; i<9; i++) { //for 100 to 999
        sizeSum += (sizeOfNumber1to19[i] + sizeOfHundred)*100 + sizeOfAnd*99 + sumOf1to99;
    }
    
    sizeSum += sizeOfNumber1to19[0] + sizeOfThousand;
    
    
    cout<<"Sum is "<<sizeSum<<endl;
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"Time elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}


