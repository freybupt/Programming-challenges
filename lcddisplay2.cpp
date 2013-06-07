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
#include <stdlib.h>

using namespace std;
/* 1<=s<=10
 base of the numbers digits: s = 1
--- --- --- --- --- --- --- --- --- ---
     -   -       -   -   -   -   -   -
  |   |   | | | |   |     | | | | | | |
     -   -   -   -   -       -   -
  | |     |   |   | | |   | | |   | | |
     -   -       -   -       -   -   -
 */
   
string numbers[10] ={
    " - | |   | | - ",
    "     |     |   ",
    " -   | - |   - ",
    " -   | -   | - ",
    "   | | -   |   ",
    " - |   -   | - ",
    " - |   - | | - ",
    " -   |     |   ",
    " - | | - | | - ",
    " - | | -   | - "
};


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

        for (int i = 0; i < height; i++) { //number of rows
            for (int m = 0; m < digits.size(); m++) { //for each digit
                string number = numbers[digits[m]];
                string substring;
                if (i == 0 || i == (height-1)/2 || i == height-1) {
                    int line = floor(i - 2*i*(s-1)/(height-1));
                    substring = number.substr(line*3, 3);
                }
                else
                    substring = i < (height -1)/2? number.substr(1*3, 3):number.substr(3*3, 3);
                cout<<substring[0];
                for (int j = 0; j < s; j++)
                    cout<<substring[1];
                cout<<substring[2];
                
                if (m != digits.size()-1 ) {
                    cout<<' ';
                }
            }
            cout<<endl;
        }
        cin>>s>>n;
        cout<<endl;
    }
    
    return 0;
}