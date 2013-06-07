#include <iostream>
#include <cmath>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <iomanip>
#include <numeric>

using namespace std;

double roundToNearest(double num) {
    return (num > 0.0) ? floor(num + 0.5) : ceil(num - 0.5);
}


int main() {
    
  int N; cin >> N;
    while (N > 0) {
        vector<int> numbers;
        int exchangeNumber = 0;
        int exchangeNumber2 = 0;
        for(int t = 0; t < N; t++) {
            double input;
            cin>>input;
            int inputNumber = roundToNearest(input*100);
            numbers.push_back(inputNumber);
        }
        
        int average = roundToNearest(accumulate(numbers.begin(), numbers.end(), 0.0)/ numbers.size());
        for(int t = 0; t < N; t++) {
            if (numbers[t] > average) {
                int change = numbers[t]- average;
                exchangeNumber = exchangeNumber + change;
            }
            else if(numbers[t] < average){
                int change = average - numbers[t];
                exchangeNumber2 = exchangeNumber2 + change;
            }
        }
        
        int amount = exchangeNumber < exchangeNumber2? exchangeNumber: exchangeNumber2;
        cout<<"$"<<amount/100<<".";
        if(amount%100 < 10)
            cout<<"0";
        
        cout<<amount%100<<endl;
    
    
        cin>>N;
    }
  
  return 0;
}

