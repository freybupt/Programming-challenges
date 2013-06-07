#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int getMaxPalindrome{
	int max = 0;
	for(int i  = 999; i > 0; i--){
 	  for(int j = i; j > 0; j--){
 		int p = i*j;
 		//check if p is palindrome
 		string r;
 		ostringstream convert;
 		convert<<p;
 		r = convert.str();
 		string r1 = r;
 		reverse(r.begin(), r.end());
 		cout<<r<<endl;
 		if (r1.compare(r) == 0){
 			cout<<r<<" is palindrome!"<<endl;
 			int result;
			stringstream(r) >> result;
 			if(result > max){
 				max = result;
 			}
 		}
 	}
}
cout<<"the max number is "<<max<<endl;
}


int main(){


return 1;
}















