#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
using namespace std;


int main(){
    for (int i = 1; i < 500; i++) {
        for (int j = 1; j < 500; j++) {
            if (i+j < 500) {
                continue;
            }
            int sum = i*i + j*j;
            if (ceil(sqrt(sum)) == floor(sqrt(sum))) {
                cout <<i<<"\t"<<j<<"\t"<<sqrt(sum)<<endl;
                if (i+j+ceil(sqrt(sum)) == 1000) {
                    return 1;
                }
            }
        }
    }
    
    return 1;
}


