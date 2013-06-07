#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
#include<fstream>
using namespace std;


unsigned long fibonacci(unsigned long index, unsigned long *hash){
    if (index == 0) {
        return 0;
    }
    else if(index == 2 || index == 1){
        return 1;
    }
    else{
        if (hash[index -1] != 0 && hash[index -2] != 0) {
            return hash[index - 1] + hash[index - 2];
        }
        else if(hash[index -1] != 0){
            return hash[index - 1] + fibonacci(index -2, hash);
        }
        else if(hash[index -2] != 0){
            return fibonacci(index - 1, hash) + hash[index - 2];
        }
        else{
            return fibonacci(index - 1, hash) + fibonacci(index -2, hash);
        }
        
    }
}
int main(){
    clock_t begin = clock();
    unsigned long count = 0;
    unsigned long index = 0;
    unsigned long hash[200000] = {0};
    while(count < 1000){
        unsigned long number;
        if (hash[index] != 0) {
            number = hash[index];
        }
        else{
            number = fibonacci(index, hash);
            hash[index] = number;
        }
        cout<<number<<endl;
        stringstream ss;//create a stringstream
        ss << number;//add number to the stream
        count = ss.str().size();
        cout<<"Count: "<<count<<" at index "<<index<<endl;
        index++;
    }
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"Time elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}


