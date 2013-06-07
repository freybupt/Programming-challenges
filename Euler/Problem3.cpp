#include<iostream>
#include <ctime>
using namespace std;

//bool isPrimePreCheck(int number){
//    ostringstream buffer;
//    buffer<< number;
//    string r = buffer.str();
//    int index = r.size();
//    char letter = r[index-1];
//    if (letter == '1' ||letter == '3' ||letter == '7' ||letter == '9') {
//        return true;
//    }
//    else
//        return false;
//}

int main(){
    clock_t begin = clock();
    long number = 600851475143;
	int primeFactor = 1;
    unsigned long j = 2;
    while(j <= number){
        if (number%j == 0) {
            number = number/j;
            cout<<"factor: "<<j<<"  Number left: "<<number<<endl;
            if (number == 1) {
                primeFactor = j;
                break;
            }
        }
        else
            j += 1;
    }
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"The biggest prime factor is:"<<primeFactor<<" in "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}


//old slow method
//	for(long j = 3; j *2 < number; j += 2){
//        cout<<j<<endl;
//		if(number%j == 0 && isPrime(j)){
//
//            primeFactor = j;
//		}
//	}
//8462696833 is not prime!
//716151937 is not prime!
//408464633 is not prime!
//87625999 is not prime!
//10086647 is not prime!
//5753023 is not prime!
//1234169 is not prime!
//486847 is not prime!
//104441 is not prime!
//59569 is not prime!
//6857 is prime!
//6857
//1471 is prime!
//1471
//839 is prime!
//839
//71 is prime!
//71
//The biggest primefactor is:71





