#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
#include<fstream>
#include<vector>

using namespace std;

void quickSort(vector<int> &num, int left, int right){
    if (left >= right) {
        return;
    }
    int leftTemp = left;
    int rightTemp = right;
    int pivot = num[(left+right)/2];
    cout<<"left: "<<left<<"right: "<<right<<endl;
    //set pivot and use recursion
    while(leftTemp < rightTemp){
        while (num[leftTemp] < pivot) {
            leftTemp++;
        }
        while (num[rightTemp] > pivot) {
            rightTemp--;
        }
        if(leftTemp <= rightTemp){
            //swap element
            int temp = num[leftTemp];
            num[leftTemp] = num[rightTemp];
            num[rightTemp] = temp;
            leftTemp++;
            rightTemp--;
        }
    }
    //recursivly solve left and right part
    if (left < rightTemp) {
        quickSort(num, left, rightTemp);
    }
    if (leftTemp < right) {
        quickSort(num, leftTemp, right);
    }
}

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
    }
    
    
};



int main(){
    clock_t begin = clock();
    int myints[] = {-1, 0, 1, 2, -1, -4};
    vector<int> input(myints, myints + sizeof(myints)/sizeof(int));
    
    //step 1: sorting
    quickSort(input, 0, input.size()-1);
    
    //step 2: remove duplicates
//    for (int i=0; i < input.size()-1; i++){
//        if (input[i] == input[i+1]) {
//            input.erase(input.begin()+i);
//            continue;
//        }
//        cout << " " << input[i];
//    }
//    cout<<endl;
    
    for (int i=0; i < input.size(); i++){
        cout << " " << input[i];
    }

    
    //step 3: find triples
    for (int i = 0; i < input.size() && input[i] < 0; i++) {
        for (int j = i + 1; j < input.size(); j++) {
            int sum = input[i]+input[j];
            for(int m = input.size(); m > i && m > j; m--){
                if (input[m] + sum == 0 && input[m] > input[j]) {
                    //found triples
                    cout<<"\ntriples: "<<input[i]<<"\t"<<input[j]<<"\t"<<input[m]<<"\t"<<endl;
                }
            }
        }
    }
    
    
    
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"\nTime elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}


