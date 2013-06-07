#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

unsigned long factorial(unsigned long n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

unsigned long getC(unsigned long n, unsigned long k){
  unsigned long result = 0;
    if ((factorial(k)*factorial(n-k)) > 0) {
        result = factorial(n)/(factorial(k)*factorial(n-k));
    }
    else{
        result = 0;
    }
//  cout<<"c"<<n<<","<<k<<" is "<<result<<endl;
  return result;
}

int main() {
  unsigned long N; cin >> N;
  for(unsigned long t = 0; t < N; t++) {
    unsigned long n, k; 
    cin >> n >> k;
//    cout<<"n = "<<n<<" k = "<<k<<endl;
    vector<unsigned long> a;
    unsigned long sum = 0;
    for(unsigned long i = 0; i < n; i++){
    	unsigned long number;
    	cin>>number;
    	a.push_back(number);
    }
    
    sort(a.rbegin(), a.rend(), greater<unsigned long>());
    
//    cout<<"after sorting"<<endl;
//    for(unsigned long i = 0; i < n; i++){
//    	cout<<a[i]<<"\t";
//    }
//    cout<<endl;
    
    for(unsigned long i = k-1; i < n; i++){
    	unsigned long value = 0;
    	if(i == k-1){
    	 value =  a[i];
    	}
    	else{
    	 value =  (getC(i+1,k) - getC(i,k))*a[i];
    	}
//    	cout<<"a["<<i<<"] is "<<value<<endl;
    	sum = sum + value;
    }

      sum = sum%1000000007;
    cout << "Case #" << (t + 1) << ": "<<sum<<endl;
    
  }
  return 0;
}