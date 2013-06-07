#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include<vector>
using namespace std;

static int scale = 21;
unsigned long hash[441]= {0};
unsigned long stepsToGet(int index_i, int index_j){
    if (index_i + index_j == 0) {
        hash[index_i*scale+index_j] = 0;
        return 0;
    }
    else if(index_i == 0 || index_j == 0){
        hash[index_i*scale+index_j] = 1;
        return 1;
    }
    else if(index_i + index_j ==1){
        hash[index_i*scale+index_j] = 1;
        return 1;
    }
    else{
        cout<<"point i: "<<index_i<<"  j: "<<index_j<<endl;
        int result1 = 0;
        int result2 = 0;
        if(hash[index_i*scale+index_j] == 0){
            hash[index_i*scale+index_j] = stepsToGet(index_i -1, index_j) + stepsToGet(index_i, index_j -1);
            return stepsToGet(index_i -1, index_j) + stepsToGet(index_i, index_j -1);
        }
        else if(hash[(index_i-1)*scale+index_j] == 0){
            hash[index_i*scale+index_j] = stepsToGet(index_i -1, index_j) + hash[index_i*scale+(index_j-1)];
            return stepsToGet(index_i -1, index_j) + hash[index_i*scale+(index_j-1)];
        }
        else if(hash[index_i*scale+(index_j-1)] == 0){
            hash[index_i*scale+index_j] = hash[(index_i-1)*scale+index_j]  + stepsToGet(index_i, index_j -1);
            return hash[(index_i-1)*scale+index_j]  + stepsToGet(index_i, index_j -1);
        }
        else{
            return hash[index_i*scale+index_j];
        }
    }
}

void printHash(unsigned long *hash){
    for(int i = 0; i < scale; i++){
        for (int j = 0; j < scale; j++) {
            cout<<hash[i*scale+j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<endl;
}

int main(){
     
    printHash(hash);
    cout<<stepsToGet(scale, scale)<<endl;
    printHash(hash);
    return 1;
}
