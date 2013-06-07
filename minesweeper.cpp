#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;
int n, m;
vector<vector <int> >lines;
void addMine(int i, int j){
    if (i >= 0 && j >= 0 && i < n && j < m && lines[i][j] != -1) {
        lines[i][j]++;
    }
}

int main() {
    
    int count = 1;
    cin>>n>>m;
    while (n > 0 && m > 0) {
            cout<<"Field #"<<count<<":"<<endl;
            lines.clear();
            //read lines
            for (int i = 0; i < n; i++) {
                string line;
                cin>>line;
                vector<int>oneLine;
                for (int j = 0; j < m; j++) {
                    if (line[j] == '*') {
                        oneLine.push_back(-1);
                    }
                    else{
                        oneLine.push_back(0);
                    }
                }
                lines.push_back(oneLine);
            }
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m ; j++) {
                    if(lines[i][j] == -1){ //mine
                        addMine(i-1,j-1);
                        addMine(i-1,j);
                        addMine(i,j-1);
                        addMine(i+1,j);
                        addMine(i,j+1);
                        addMine(i+1,j+1);
                        addMine(i-1,j+1);
                        addMine(i+1,j-1);
                    }
                }
            }
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m ; j++) {
                    if(lines[i][j] == -1){
                        cout<<"*";
                    }
                    else{
                        cout<<lines[i][j];
                    }
                }
                cout<<endl;
            }
            cin>>n>>m;
        if (n > 0 && m > 0) {
            count++;
            cout<<endl;
        }
    }
  return 0;
}