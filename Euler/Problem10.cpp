#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
using namespace std;
bool isPrime(unsigned long number){
    bool flag = true;
	if(number%2 == 0 && number != 2)
        flag=false;
    else{
        for(unsigned long i = 3; i < number/2 ; i+=2){
            if(number%i == 0){
                flag = false;
                break;
            }
        }
        
    }	
    if (flag) {
        cout<<number<<" is prime!"<<endl;
    }
//    else{
//        cout<<number<<" is not prime!"<<endl;
//    }
	return flag;
}


int main(){
    long sum = 2;
    for (int i = 3; i < 2000000; i++) {
        if (isPrime(i)) {
            sum += i;
            cout<<"sum: "<<sum<<endl;
        }
    }
    cout<<"result: "<<sum<<endl;
    return 1;
}


//1179908154