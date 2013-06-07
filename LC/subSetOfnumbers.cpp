#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int sumTable[6][100] = {0};

	int numbers[] = {3, 4, 9, 14, 15, 19, 28, 37, 47, 50, 54, 56, 59, 61, 70, 73, 78, 81, 92, 95, 97, 99};
	int size = size=sizeof(numbers)/sizeof(int);
	
	for(int i = 0; i < size; i++){
		sumTable[0][numbers[i]] = 1;
	}
	
	//not working
	for(int m = 0; m < 6; m++){
		cout<<"Round "<<m<<"\n"<<endl;
		for(int i = size-1; i>0; i--){
			for(int j = i-1; j>0; j--){
				int numberLeft = numbers[i] - numbers[j];
				if(sumTable[m][numberLeft]>0 && numbers[j] != numberLeft){
//					cout<<numbers[i]<<" - "<<numbers[j]<<" = "<<numberLeft<<endl;
//					cout<<"Number "<<numbers[i]<<endl;
					sumTable[m+1][numbers[i]] += sumTable[m][numberLeft];
				}
			}
		}
		for(int i = 0; i < 100; i++){
		cout<<i<<'\t'<<sumTable[m][i]<<"\n"<<endl;
		}
	}
	
	
	int sumNumber = 0;
	for(int i = 1; i < 6; i++){
		for(int j = 0; j <size; j++){
			sumNumber +=sumTable[i][numbers[j]];
		}
	}
	cout<<"final sum: "<<sumNumber<<endl;
}

//179
/*
The Greplin Programming Challenge
	
	The End
	
	----------------------------------------

	Congratulations.  You completed the challenge.  Your completion code is 25014-14071-77755.
	
	We'd love to talk to you - send your completion code, the code you wrote
	during the challenge, and your resume to
	
	jobs+i+solved+the+challenge@greplin.com
	
	Even if you're not looking for a job, we'd love to hear what you thought
 	about the challenge.
 	
 	*/