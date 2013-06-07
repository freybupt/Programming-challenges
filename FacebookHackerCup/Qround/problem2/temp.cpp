#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
#include<fstream>
#include<vector>
#include <algorithm>

using namespace std;

int main(){
    clock_t begin = clock();
    
    vector<string>allLines;
    string line;
    ifstream myfile ("/Users/liangshi/Dropbox/_workspace/FacebookHackerCup/balanced_smileystxt.txt");
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
            int matchCount = 0;
            int matchCount2 = 0;
            int smileCount = 0;
            int crycount = 0;
            char lastChar;
            
            for (int j = 0; j < oneString.length(); j++) {
//                if (lastChar == ':') {
//                    if (oneString[j] == '(') {
//                        crycount++;
//                    }
//                    if (oneString[j] == ')') {
//                        smileCount++;
//                    }
//                }
                if (lastChar != ':') {
                    if (oneString[j] == '(') {
                        matchCount++;
                    }
                    else if (oneString[j] == ')') {
                        if (matchCount > 0) {
                            matchCount--;
                        }
                    }
                }

                lastChar = oneString[j];
            }

            lastChar = ' ';
            for (int j = 0; j < oneString.length(); j++) {
                
                if (oneString[j] == '(') {
                    matchCount2++;
                }
                else if (oneString[j] == ')') {
                    if (matchCount2 > 0) {
                        matchCount2--;
                    }
                }
                
                lastChar = oneString[j];
            }
           
            string output = "";
            if (matchCount > 0 && matchCount2 > 0) {
                output = "NO";
            }
            else{
                output = "YES";
            }
            
            cout<<"Case #"<<i+1<<": "<<output<<endl;
        }
        myfile.close();
    }
    
    else cout << "Unable to open file";
    
    
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"\nTime elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}




