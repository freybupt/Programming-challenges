#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

/* 1<=s<=10
 base of the numbers digits: s = 1
--- --- --- --- --- --- --- --- --- ---
     -   -       -   -   -   -   -   -
  |   |   | | | |   |     | | | | | | |
     -   -   -   -   -       -   -
  | |     |   |   | | |   | | |   | | |
     -   -       -   -       -   -   -
 */

using namespace std;


int main() {
    int s, n;
    cin>>s>>n;
    while (s > 0) {
        int width = s+2;
        int height = 2*s+3;
        stringstream ss;
        ss << n;
        string input(ss.str());
        vector<int>digits;
        for (int i = 0; i < input.size(); i++) {
            digits.push_back(input[i]-'0');
        }
        
//        for (int i = 0; i < input.size(); i++) {
//            cout<<digits[i]<<'\t';
//        }
//        cout<<endl;
        
        
        for (int i = 0; i < height; i++) { //number of rows
                for (int m = 0; m < digits.size(); m++) { //for each digit
                    if (i == 0) { // the first line
                        switch (digits[m]) {
                            case 1:
                            case 4:
                                //first line
                                for (int p = 0; p < width; p++) {
                                    cout<<' ';
                                }
                                break;
                            case 0:
                            case 2:
                            case 3:
                            case 5:
                            case 6:
                            case 7:
                            case 8:
                            case 9:
                                cout<<' ';
                                for (int p = 0; p < s; p++) {
                                    cout<<'-';
                                }
                                cout<<' ';
                                break;
                            default:
                                break;
                        }
                    }
                    else if(i == height -1) { // last line
                        switch (digits[m]) {
                            case 1:
                            case 4:
                            case 7:
                                //first line
                                for (int p = 0; p < width; p++) {
                                    cout<<' ';
                                }
                                break;
                            case 0:
                            case 2:
                            case 3:
                            case 5:
                            case 6:
                            case 8:
                            case 9:
                                cout<<' ';
                                for (int p = 0; p < s; p++) {
                                    cout<<'-';
                                }
                                cout<<' ';
                                break;
                            default:
                                break;
                        }
                    }
                    else if(i == (height -1)/2){ // mid line
                        switch (digits[m]) {
                            case 0:
                            case 1:
                            case 7:
                                //first line
                                for (int p = 0; p < width; p++) {
                                    cout<<' ';
                                }
                                break;
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                            case 8:
                            case 9:
                                cout<<' ';
                                for (int p = 0; p < s; p++) {
                                    cout<<'-';
                                }
                                cout<<' ';
                                break;
                            default:
                                break;
                        }

                    }
                    else if(i > 0 && i < (height -1)/2){ //above mid line
                        switch (digits[m]) {
                            case 1:
                            case 2:
                            case 3:
                            case 7:
                                for (int p = 0; p < width-1; p++) {
                                    cout<<' ';
                                }
                                cout<<'|';
                                break;
                            case 4:
                            case 8:
                            case 9:
                            case 0:
                                cout<<'|';
                                for (int p = 1; p < width-1; p++) {
                                    cout<<' ';
                                }
                                cout<<'|';
                                break;
                            case 5:
                            case 6:
                                cout<<'|';
                                for (int p = 1; p < width; p++) {
                                    cout<<' ';
                                }
                                break;
                            default:
                                break;
                        }

                    }
                    else if(i > (height -1)/2 && i < height -1){ //below mid line
                        switch (digits[m]) {
                            case 2:
                                cout<<'|';
                                for (int p = 1; p < width; p++) {
                                    cout<<' ';
                                }
                                break;
                            case 1:
                            case 3:
                            case 4:
                            case 5:
                            case 7:
                            case 9:
                                for (int p = 0; p < width-1; p++) {
                                    cout<<' ';
                                }
                                cout<<'|';
                                break;
                            case 6:
                            case 8:
                            case 0:
                                cout<<'|';
                                for (int p = 1; p < width-1; p++) {
                                    cout<<' ';
                                }
                                cout<<'|';
                                break;
                            default:
                                break;
                        }

                    }
                    if (m != digits.size()-1 ) {
                        cout<<' ';
                    }
                    
            }
            cout<<endl; //end of line
        }

        cin>>s>>n;
        cout<<endl;

        
    }
    
    return 0;
}