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

int getAmountToExchange(vector<int> expenses){
    int amountToExchange = 0;
    int numberOfPeople = expenses.size();
    
    long average = 0;
    long total = 0;
    for (int i = 0; i < numberOfPeople; i++) {
        total += expenses[i];
    }
    average = roundToNearest((double)total/numberOfPeople);
    int totalReceived = 0;
    int totalGiven = 0;
    for (int i = 0; i < numberOfPeople; i++) {
        long diff = expenses[i] - average;
        if (diff > 0) {
            totalReceived += diff;
        }
        else{
            totalGiven -= diff;
        }
    }
    amountToExchange = totalReceived < totalGiven? totalReceived : totalGiven;
    return amountToExchange;
}

int main() {
    
  int N; cin >> N;
    while (N > 0) {
        vector<int> numbers;
        double exchangeNumber = 0.0;
        double exchangeNumber2 = 0.0;
        for(int t = 0; t < N; t++) {
            double input;
            cin>>input;
            int inputNumber = roundToNearest(input*100);
            numbers.push_back(inputNumber);
        }

        int amount = getAmountToExchange(numbers);
        cout<<"$"<<amount/100<<".";
        if(amount%100 < 10)
            cout<<"0";
        
        cout<<amount%100<<endl;
        
        cin>>N;
    }
  
  return 0;
}

