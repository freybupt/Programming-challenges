#include<iostream>
#include<cmath>
using namespace std;

int myPow(int x, int p) {
  if (p == 0) return 1;
  if (p == 1) return x;
  return x * myPow(x, p-1);
}

//bad code
bool isPalindrome(int input){
    if (input < 0) {
        return false;
    }
	bool isPalindromeInteger = true;
	//compare the first and last digit
	while(input > 9){ //two digits
		int lastDigit = input%10;
		input = input/10;
		int firstDigit = input;
		int level = 0;
		while(firstDigit > 9){
			firstDigit = firstDigit/10;
			level++;
		}

        input = input - firstDigit*myPow(10, level);
		if(firstDigit != lastDigit){
			isPalindromeInteger = false;
			break;
		}
	}
	
	return isPalindromeInteger;
}

//good code
bool isPalindrome2(int x) {
    if (x < 0) return false;
    int div = 1;
    while (x / div >= 10) {
        div *= 10;
    }
    while (x != 0) {
        int l = x / div;
        int r = x % 10;
        if (l != r) return false;
        x = (x % div) / 10;
        div /= 100;
    }
    return true;
}

int main(){
	int inputInteger;
	cin>>inputInteger;

	cout<<"the number "<<inputInteger<<" is palindrome is "<<isPalindrome(inputInteger)<<endl;
	return 1;
}