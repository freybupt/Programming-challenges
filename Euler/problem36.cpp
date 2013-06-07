#include<iostream>
#include<string>
#include<sstream>
#include<bitset>
#include<math.h>
#include <ctime>
#include<fstream>
#include<vector>

using namespace std;



bool isPalindromic(string testString){
    int size = testString.size();
//    cout<<"String "<<testString<<" with size "<<size<<endl;
    string substring1 = testString.substr(0, floor(size/2));
    string substring2 = testString.substr(ceil(size/2), size-1);
    bool flag = true;
    for (int m = 0; m <substring1.size(); m++) {
        if (substring1[m] != substring2[substring2.size()-m-1]) {
            flag = false;
            break;
        }
    }
    return flag;
}


int main(){
    clock_t begin = clock();
    
    unsigned long int sum = 0;
    for(int a = 1; a < 1000000; a++) {
        string mystring=bitset<20>( a ).to_string<char,char_traits<char>,allocator<char> >();
        //remove 0s
        for (int i = 0; i < mystring.size(); i++) {
            if (mystring[i] == '1') {
                mystring = mystring.substr(i, mystring.size());
                break;
            }
        }
//        cout<<a<<" = binary of "<<mystring<<endl;
        
        ostringstream ss;
        ss << a;
        if (isPalindromic(ss.str()) && isPalindromic(mystring)) {
            cout<<a<<" with binary "<<mystring<<" is Palindromic!"<<endl;
            sum += a;
        }
        else if(!isPalindromic(ss.str())){
            cout<<ss.str()<<" is not Palindromic!"<<endl;
        }
        else{
            cout<<a<<"'s binary "<<mystring<<" is not Palindromic!"<<endl;
        }
    }
    
    cout<<"Final sum: "<<sum<<endl;
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"Time elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}


