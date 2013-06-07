#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
#include<fstream>
#include<vector>
using namespace std;

static int low_bound = 2;
static int up_bound = 100;

bool isPower(int number, int *power){
    int numberOfbase = 0;
    for (int i = low_bound; i <= ceil(sqrt(up_bound)); i++) {
        int powerNumber = number;
        int count = 0;
//        cout<<"powerNumber "<<powerNumber<<endl;
        while (powerNumber > 1) {
            if (powerNumber%i == 0) {
                powerNumber = powerNumber/i;
            }
            else{
                break;
            }
            count++;
        }
        if (powerNumber == 1 && count > 1) {
            power[0] = i;
            numberOfbase = count;
            break;
        }
    }
    power[1] = numberOfbase;
    if (power[0] != 0) {
        return true;
    }
    else{
        return false;
    }
    
}

int main(){
    clock_t begin = clock();

//    //brute force - not correct
//    int a = 2;
//    int b = 2;
//    vector<int> DistinctTerms;
//    while (a <= 100)
//    {
//        while (b <= 100)
//        {
//            bool flag = false;
//            for (int i = 0; i < DistinctTerms.size(); i++) {
//                if (DistinctTerms[i] == pow(a,b)) {
//                    flag = true;
//                    break;
//                }
//            }
//            
//            if (!flag)
//            {
//                DistinctTerms.push_back(pow(a, b));
//            }
//            b++;
//        }
//        b = 2;
//        a++;
//    }
//    
//    cout<<DistinctTerms.size()<<endl;
//    
//    
//    //smarter way
    
    int count = 0;

    for (int i = low_bound; i <= up_bound; i++) {
        bool flag = false;
        int powerBase[2] = {0, 0};
        if (isPower(i, powerBase)) { //is square root
            cout<<i<<" is pow("<<powerBase[0]<<","<<powerBase[1]<<")"<<endl;
            flag = true;
        }
        for (int j = low_bound; j <= up_bound; j++) {
            count++;
            if (flag) {
                if (j*powerBase[1] <= up_bound && powerBase[0] >= low_bound) {
                    count--;
                    cout<<"pow("<<i<<" , "<<j<<") is a duplicate"<<endl;
                }
            }
        }
    }
    
//    for (int i = low_bound; i <= up_bound; i++) {
//        bool flag = false;
//        if (ceil(sqrt(i)) - sqrt(i)  < 0.0000001) { //is square root
//            flag = true;
//            cout<<i<<" is square root!"<<endl;
//        }
//        for (int j = low_bound; j <= up_bound; j++) {
//            count++;
//            if (flag) {
//                if (j*2 <= up_bound && sqrt(i) >= low_bound) {
//                    count--;
//                    cout<<"pow("<<i<<" , "<<j<<") is a duplicate"<<endl;
//                }
//            }
//        }
//    }
    
    cout<<"Final count: "<<count<<endl;
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"Time elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}


