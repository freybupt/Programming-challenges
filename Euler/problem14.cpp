#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include<vector>
using namespace std;

int main(){
    int max = 0;
    long maxStartNumber = 0;
    
    for (long startNumber = 1; startNumber < 1000000; startNumber++) {
        int count = 0;
        long startNumberTemp = startNumber;
        cout<<"Start number: "<<startNumber<<"->";
        while (startNumberTemp > 1) {
            if (startNumberTemp%2 == 0) {
                startNumberTemp = startNumberTemp/2;
            }
            else{
                startNumberTemp = 3*startNumberTemp+1;
            }
            cout<<startNumberTemp<<"->";
            count++;
        }
        if(startNumberTemp < 0){
        	cout<<"Error!"<<endl;
        	break;
        }
        cout<<endl;
        if (count > max) {
            max = count;
            maxStartNumber = startNumber;
        }
    }
    cout<<"max number "<<maxStartNumber<<" with chain "<<max<<endl;
    return 1;
}
