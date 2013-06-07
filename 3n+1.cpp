#include <iostream>

using namespace std;

int getLength(int n){
    int count = 1;
    while (n != 1) {
        if (n% 2 == 0)
            n /= 2;
        else
            n = n*3+1;
        count++;
    }
    return count;
}

int main(int argc, char *argv[]) {
    int a, b, low, high;
	while(cin>>a>>b) {
		if(a < b) {
			low = a;
			high = b;
		} else {
			low = b;
			high = a;
		}
        int maxLength = getLength(low);
        for (int i = low+1; i<=high; i++) {
            int result = getLength(i);
            if (result > maxLength) 
                maxLength = result;
        }
        cout<<a<<" "<<b<<" "<<maxLength<<endl;
    }  return 0;
}