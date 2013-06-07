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

struct Point{
    int x;
    int y;
};

int main() {
  int N; cin >> N;
  for(int t = 0; t < N; t++) {
    int W, H, P, Q, N, X, Y, a, b, c, d; 
    cin>>W>>H>>P>>Q>>N>>X>>Y>>a>>b>>c>>d;
      int number = 0;
      //build the map
      vector<Point>deadPix;
      for (int i = 0; i < N; i++) {
          struct Point onePoint;
          onePoint.x = 0;
          onePoint.y = 0;
          deadPix.push_back(onePoint);
      }
      
      deadPix[0].x = X;
      deadPix[0].y = Y;
      for (int i = 1; i < N; i++) {
          deadPix[i].x = (deadPix[i-1].x*a + deadPix[i-1].y*b + 1)%W;
          deadPix[i].y = (deadPix[i-1].x*c + deadPix[i-1].y*d + 1)%H;
      }
      
      //print
      cout<<"N = "<<N<<endl;
      for (int i = 0; i < N; i++) {
          cout<<"Index: "<<i<<" x = "<<deadPix[i].x<<" y = "<<deadPix[i].y<<endl;
      }

    cout<< "Case #" << (t + 1) << ": "<<number<<endl;
    
  }
  return 0;
}