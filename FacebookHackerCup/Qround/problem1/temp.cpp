#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
#include<fstream>
#include<vector>
#include <algorithm>


using namespace std;

void quickSort(int *num, int left, int right){
    if (left >= right) {
        return;
    }
    int leftTemp = left;
    int rightTemp = right;
    int pivot = num[(left+right)/2];
//    cout<<"left: "<<left<<"right: "<<right<<endl;
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
    
    vector<string>allLines;
    string line;
    ifstream myfile ("/Users/liangshi/Dropbox/_workspace/FacebookHackerCup/beautiful_stringstxt.txt");
    if (myfile.is_open())
    {
        int numberOfLines = 0;
        getline (myfile,line);
        stringstream(line) >> numberOfLines;
        cout<<"number of lines "<<numberOfLines<<endl;
        while ( myfile.good() )
        {
            getline (myfile,line);
            transform(line.begin(), line.end(), line.begin(), ::tolower);
            cout << line << endl;
            allLines.push_back(line);
        }
        
        for(int i = 0; i < allLines.size(); i++){
            string oneString =  allLines[i];
            //get the max possbile beauty of each string
            int beautyScore = 0;
//            vector<int> letters;
            int letters[26] = {0};
            //collect all letters
            for (int j = 0; j<oneString.length(); j++) {
                int index = oneString[j]-'a';
                if (index >= 0 && index < 27) {
                    letters[index]++;
                }
                
            }
            
            quickSort(letters, 0, 25);
            //print it
//            cout<<"Print letters count"<<endl;
            for (int j = 0; j<26; j++) {
//                cout<<letters[j]<<endl;;
            }
            
            int score = 26;
            for (int j = 25; j>= 0; j--) {
                beautyScore = beautyScore + letters[j]*score;
                score--;
            }
            
            cout<<"Case #"<<i+1<<": "<<beautyScore<<endl;
        }
        myfile.close();
    }
    
    else cout << "Unable to open file";
    
    
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"\nTime elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}




