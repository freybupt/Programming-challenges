#include<iostream>
using namespace std;

static int bound = 100;
int main(){
	int sum1 = 0;
	int sum2 = 0;
	
	for(int i = 1; i <= bound; i++){
		sum1 += i*i;
		sum2 += i;
	}
	sum2 = sum2*sum2;
	
	int diff = sum2 - sum1;
	cout<<"the difference is "<<diff<<endl;
}