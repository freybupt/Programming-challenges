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
    if (number == 1) {
        flag = false;
    }
	if(number%2 == 0 && number != 2)
        flag=false;
    else{
        for(unsigned long i = 2; i < number ; i++){
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
    
    unsigned long int finalSum = 0;
    int count = 0;
    for (int i = 11; i < 10000000; i = i+2) {
        bool flag;
        ostringstream ss;
        ss << i;
        string numberString = ss.str();
//        cout<<"Test Number: "<<numberString<<endl;
        int size = numberString.size();
        if (size == 1) {
            flag = isPrime(i);
        }
        else{
            for (int j = 1; j < size; j++) {
                flag = true;
                if (numberString[j] == '1' || numberString[j] == '3' || numberString[j] == '7' || numberString[j] == '9' ) {
                    //check circular
                    string temp = numberString.substr(0,j);
                    string temp2 = numberString.substr(size-j, size);
//                    cout<<"string1: "<<temp<<" string2: "<<temp2<<endl;
                    int tempInt;
                    stringstream(temp) >> tempInt;
                    if (isPrime(tempInt)) {
//                        cout<<tempInt<<" is prime"<<endl;
                    }
                    else{
//                        cout<<tempInt<<" is not prime"<<endl;
                        flag = false;
                        break;
                    }
                    stringstream(temp2) >> tempInt;
                    if (isPrime(tempInt)) {
//                        cout<<tempInt<<" is prime"<<endl;
                    }
                    else{
//                        cout<<tempInt<<" is not prime"<<endl;
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
        
        if (flag && isPrime(i)) {
            cout<<i<<" is a awesome prime!"<<"\n\n"<<endl;
            count++;
            finalSum += i;
        }
    }
    
    cout<<"Final count "<<count<<endl;
    cout<<"Final sum "<<finalSum<<endl;
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"Time elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}


