#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
#include<vector>
#include <algorithm>

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

int main(){
    clock_t begin = clock();
    
    ifstream myfile ("/Users/freybupt/Dropbox/_workspace/FacebookHackerCup/example.txt");
    if (myfile.is_open())
    {
        string line;
        int numberOfCases = 0;
        getline (myfile,line);
        stringstream(line) >> numberOfCases;
        cout<<"number of cases "<<numberOfCases<<endl;
        int count = 0;
        while ( myfile.good() )
        {
            string line1;
            string line2;
        
            getline (myfile,line1);
            getline (myfile,line2);
            
            //parse line1
            long buf; // Have a buffer string
            stringstream ss(line1); // Insert the string into a stream
            vector<long> tokens; // Create vector to hold our words
            while (ss >> buf){
                tokens.push_back(buf);
            }
              long n = tokens[0];
              long k = tokens[1];
            
            vector<long>m(n);
            //parse line2
            stringstream ss2(line2); // Insert the string into a stream
            vector< long> tokens2; // Create vector to hold our words
            while (ss2 >> buf){
                tokens2.push_back(buf);
            }
             long a = tokens2[0];
             long b = tokens2[1];
             long c = tokens2[2];
             long r = tokens2[3];
            
            bool *numberContainer = new bool[r];
            for ( long i = 0; i < r; i++) {
                numberContainer[i] = 0;
            }
            //compute the numbers from 0 to k-1
            m[0] = a;
            cout<<m[0]<<" ";
            for ( long i = 1; i < k; i++) {
                m[i] = (b*m[i-1] + c)%r;
                cout<<m[i]<<" ";
                numberContainer[m[i]] = 1;
            }         
            cout<<endl;
            
            
            for ( long i = 0; i < r; i++) {
                cout<<numberContainer[i]<<" ";
            }
            
            //first solution
            for ( long i = k; i < n; i++) {
                for ( long p = 0; p < r; p++) {
                    bool hasThisNumber = false;
                    for ( long j = i-1; j >= i - k; j--) {
                        if (m[j] == p) {
                            hasThisNumber = true;
                            break;
                        }
                    }
                    if (!hasThisNumber) {
                        m[i] = p;
                        break;
                    }
                }
            }

            //second solution -  use bitset - doesn't work
//            for ( long i = k; i < n; i++) {
//                
//                for ( long j = 0; j < r; j++) {
//                    if (!numberContainer[j]) { //number does not exist
//                        m[i] = j;
//                        numberContainer[j] = 1;
//                        break;
//                    }
//                }
//                
//                numberContainer[m[i-k]] = 0;
//            }
            
            
            cout<<"\nafter k: "<<endl;
            for ( long i = k; i < n; i++) {
                cout<<m[i]<<" ";
            }
            cout<<endl;
            
            count++;
            cout<<"Case #"<<count<<": "<<m[n-1]<<endl;
            delete []numberContainer;
        }
        
        
        myfile.close();
    }
    
    else cout << "Unable to open file";
    
    
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"\nTime elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}




