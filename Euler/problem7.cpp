#include<iostream>
using namespace std;


bool isPrime(unsigned long number){
    bool flag = true;
	if(number%2 == 0 && number != 2)
        flag=false;
    else{
        for(unsigned long i = 4; i < number ; i++){
            if(number%i == 0){
                flag = false;
                break;
            }
        }

    }
	
    if (flag) {
        cout<<number<<" is prime!"<<endl;
    }
    else{
//        cout<<number<<" is not prime!"<<endl;
    }
	return flag;
}

int main(){
    int count = 0;
    int i;
	for(i = 2; count <= 10001; i++){
        if (isPrime(i)) {
            count++;
            cout<<"Index: "<<count<<" is prime number"<<i<<endl;
        }
	}
    cout<<i-1<<" is prime number"<<endl;
}

//104743