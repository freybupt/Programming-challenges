#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
#include<fstream>
using namespace std;


int main(){
    clock_t begin = clock();
    int totalSum = 0;
    for (int i = 2; i < 10000000; i++) {
        stringstream ss;
        ss << i;
        string numberString = ss.str();
        int digitNumber = numberString.size();
        int oneDigit = i;
        int sum = 0;
        for (int j = 0 ; j < digitNumber; j++) {
            int leftNumber = oneDigit%10;
            oneDigit = oneDigit/10;
            sum += pow(leftNumber, 5);
        }
        
        if (sum == i) {
            totalSum += sum;
            cout<<"Sum is "<<sum<<endl;
            cout<<"Is equal to itself: "<<i<<endl;
        }
        else{
            cout<<"Distance: "<<abs(sum - i)<<endl;
        }
        
    }
    
    cout<<"Total sum: "<<totalSum<<endl;
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"Time elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}


