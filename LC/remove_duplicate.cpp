#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
#include<fstream>
#include<vector>

using namespace std;


void removeDuplicate(char *str){
    int length = strlen((char*)str);
    cout<<"length is: "<<length<<endl;
    for (int i = 0; i <= length; i++) {
        int isEaqual = 0;
        for (int j = i+1; j <= length+1; j++) {
            if (isEaqual == 0 && str[i]== str[j]) {
                cout<<"str[i] "<<str[i]<<" str[j] "<<str[j]<<endl;
                isEaqual = 1;
            }
            if (isEaqual == 1) {
                str[j] = str[j+1];
                str[j+1] = '\0';
                cout<<str[j]<<endl;
            }
        }
        if (isEaqual == 1) {
            --i;
            length--;
        }
    }
    
}

int main(){
    clock_t begin = clock();
    
    char input[] = "aaaabbb";
    
    removeDuplicate(input);
    
    int length = strlen((char*)input);
    for (int i = 0; i < length; i++) {
        cout<<input[i]<<'\t';
    }
    
    cout<<"with length: "<<length<<endl;
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"\nTime elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}


