#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>

using namespace std;

string searchForSubstring(string s1, string s2){
    string resultString = "";
    for (int i = 0; i < s1.size()-s2.size(); i++) {
        string substring = s1.substr(i,s2.size());
        //compare substring and s2
        bool isEqual = true;
        for (int j = 0; j < s2.size(); j++) {
            if (substring[j] != s2[j] && (substring[j] != '?' && s2[j] != '?')) {
                isEqual = false;
                break;
            }
            else if(substring[j] != '?' && s2[j] == '?'){
                s2[j] = substring[j];
            }
            else if(substring[j] == '?' && s2[j] != '?'){
                substring[j] = s2[j];
            }
        }
        if (isEqual) {
//            cout<<"offset: "<<i;
//            cout<<" substring: "<<substring<<endl;
            //add it to s1
            for (int j = 0; j < s2.size(); j++) {
                if (s1[j] == '?') {
                    if (s2[j] != '?') {
                        s1[j] = s2[j];
                    }
                    else{
                        s1[j] = 'a';
                    }
                }
            }
            resultString = s1.substr(0, s2.size());
            break;
        }
    }
    return resultString;
}

int main() {
  int N; cin >> N;
  for(int t = 0; t < N; t++) {
    int m;
    cin >> m;
    string k1, k2;
    cin>>k1>>k2;
      
      //check k1 and k2 has equal length
      if (k1.size() != k2.size()) {
          cout<< "Case #" << (t + 1) << ": "<<"IMPOSSIBLE"<<endl;
      }
      else{
         //check if k2 is permutation of a1
          string newK1 = k1+k1;

          string result = searchForSubstring(newK1, k2);
          if(result.size() > 0){
              cout << "Case #" << (t + 1) << ": "<<result<<endl;
          }
          else{
              cout<< "Case #" << (t + 1) << ": "<<"IMPOSSIBLE"<<endl;
          }
      }


    
    
  }
  return 0;
}