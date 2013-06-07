#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int number){
    bool flag = true;
    if (number == 1) {
        flag = false;
    }
	if(number%2 == 0 && number != 2)
        flag=false;
    else{
        for(int i = 2; i < number ; i++){
            if(number%i == 0){
                flag = false;
                break;
            }
        }
        
    }

	return flag;
}

int getSomeOfPrimeDevider(int number){
	int sum = 0;
	for(int i = 2; i < number; i++){
		if(number%i == 0 && isPrime(i)){
			sum += i;
		}
	}
	return sum;
}

int getFibonacci(int index){
	if(index < 1)
		return 1;
	else{
		return getFibonacci(index-1)+getFibonacci(index-2);	
	}
}


int main(){
	int result = 0;
	for(int i = 3; i < 1000000; i++){
		result = getFibonacci(i);
		cout<<"Fibonacci "<<i<<" is "<<result<<endl;
		if(result > 227000 && isPrime(result) ){
			cout<<"result is "<<result<<endl;
			break;
		}
	}
	result +=1;
	cout<<getSomeOfPrimeDevider(result)<<endl;
	return 1;
	
}