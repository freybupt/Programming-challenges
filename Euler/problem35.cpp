#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
#include<fstream>
#include<vector>


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
//    if (flag) {
//        cout<<number<<" is prime!"<<endl;
//    }
//    else{
//        cout<<number<<" is not prime!"<<endl;
//    }
	return flag;
}

int main(){
    clock_t begin = clock();
    
    int count = 0;
    for (int i = 2; i < 2000; i = i+2) {
        bool flag;
        ostringstream ss;
        ss << i;
        string numberString = ss.str();
        cout<<"Test Number: "<<numberString<<endl;
        int size = numberString.size();
        if (size == 1) {
            flag = isPrime(i);
        }
        else{
            for (int j = 0; j < size; j++) {
                flag = true;
                if (numberString[j] == '1' || numberString[j] == '3' || numberString[j] == '7' || numberString[j] == '9' ) {
                    //check circular
                    string temp = numberString.substr(j,size)+numberString.substr(0,j);
                    cout<<"string rotation: "<<temp;
                    int tempInt;
                    stringstream(temp) >> tempInt;
                    if (isPrime(tempInt)) {
                        cout<<" is prime"<<endl;
                    }
                    else{
                        cout<<" is not prime"<<endl;
                        flag = false;
                        break;
                    }
                }
                else{
                    flag = false;
                    break;
                }
            }
        }
        
        if (flag) {
            cout<<i<<" is a circular prime!"<<"\n\n"<<endl;
            count++;
        }
    }
    
    cout<<"Final count "<<count<<endl;
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"Time elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}


