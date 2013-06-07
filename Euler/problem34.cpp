#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
#include<fstream>
#include<vector>

using namespace std;

inline unsigned long factorial(int x) {
    return ((x == 1 || x == 0) ? 1 : x * factorial(x - 1));
}

int main(){
    clock_t begin = clock();
    
    unsigned long finalSum = 0;
    for (unsigned long i = 3; i < 9999999; i++) { //7 times 9! is less than 9999999
        unsigned long sum = 0;
        cout<<"Number: "<<i<<endl;
        unsigned long temp = i;
        do {
            int digit = temp%10;
            temp = temp/10;
            cout<<"factorial("<<digit<<") = "<<factorial(digit)<<endl;
            sum += factorial(digit);
        } while (temp >= 1);
        
        cout<<"Sum is "<<sum<<"\n"<<endl;
        if (sum == i) {
            cout<<i<<" is curious number!"<<endl;
            finalSum += i;
        }
    }
    
    cout<<"Final sum "<<finalSum<<endl;
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"Time elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}


