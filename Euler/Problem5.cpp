#include<iostream>
using namespace std;

int main(){
	int bound = 20;
	bool flag = true;
	int i = 0;
	for(i = bound; flag; i++){
		flag = false;
		for(int j = 2; j <= bound; j++){
			if(i%j != 0){
				flag = true;
				break;
			}
		}
		if(!flag){
			break;
		}
	}
	cout<<"the number is "<<i<<endl;
}