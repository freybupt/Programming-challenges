#include<iostream>
using namespace std;


int fibonacci(int index){
	if(index < 0) return NULL;
	else if(index == 0)	return 0;
	else if(index == 1) return 1;
	else{
		return fibonacci(index-1) + fibonacci(index-2);
	}
}

int main(){
	int sum = 0;
	for(int i = 0; sum < 4000000; i++){
		if(fibonacci(i)%2 == 0)
			sum += fibonacci(i);
	}
	cout<<sum<<endl;
}