#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
using namespace std;

void print(int input[][15]){
    cout<<"Triangle is "<<endl;
    for (int i = 0; i<15; i++) {
        for (int j = 0; j < 15; j++) {
            cout<<input[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main(){
    clock_t begin = clock();
    
    int input[15][15] =
        {{75},
        {95,64},
        {17,47,82},
        {18,35,87,10},
        {20,4,82,47,65},
        {19,1,23,75,3,34},
        {88,2,77,73,7,63,67},
        {99,65,4,28,6,16,70,92},
        {41,41,26,56,83,40,80,70,33},
        {41,48,72,33,47,32,37,16,94,29},
        {53,71,44,65,25,43,91,52,97,51,14},
        {70,11,33,28,77,73,17,78,39,68,17,57},
        {91,71,52,38,17,14,91,43,58,50,27,29,48},
        {63,66,4,68,89,53,67,30,73,16,69,87,40,31},
        {4,62,98,27,23,9,70,98,73,93,38,53,60,4,23}};
     
    print(input);
    
    //replace each row with optimal option
    for (int i = 13; i>=0; i--) {//row index
        for (int j = 0; j <= i; j++) {
            int sum1 = input[i][j] + input[i+1][j];
            int sum2 = input[i][j] + input[i+1][j+1];
            if (sum1 >= sum2) {
                input[i][j] = sum1;
            }
            else{
                input[i][j] = sum2;
            }
        }
        print(input);
    }

    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"Time elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}


