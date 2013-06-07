#include<iostream>
#include<cmath>
#include<sstream>
#include<String>
using namespace std;

string getlongestPalindrome(string inputString){
	string longestPallindrome = "";
	int N = inputString.size();
	//go through each gap (2N-1) and check forward and back
	for(int i = 1; i<2*N-1;i++){	 //i is the index of gap, not the element
		if(i%2 == 0){ //real number
			stringstream ss;
			string palindrome;
			ss << inputString[i/2];;
			ss >> palindrome;
			int step = 1;
			while(i/2>=step && i/2+step < N && inputString[i/2-step] == inputString[i/2+step]){
				palindrome.append(1, inputString[i/2-step]);
				string::iterator it;
				it = palindrome.insert(palindrome.begin(),inputString[i/2-step]);
				step++;
			}
			if(palindrome.size() > longestPallindrome.size()){
				longestPallindrome = palindrome;
			}
		}
		else{ //gap in between
			int index1 = (i-1)/2;
			int index2 = (i+1)/2;
			string palindrome = "";
			while(index1>=0 && index2 < N && inputString[index1] == inputString[index2]){
				palindrome.append(1,inputString[index1]);
				string::iterator it;
				it = palindrome.insert(palindrome.begin(),inputString[index2]);
				index1--;
				index2++;
			}
			if(palindrome.size() > longestPallindrome.size()){
				longestPallindrome = palindrome;
			}
		}
	}
	return longestPallindrome;
}

int main(){
	string input;
	input = "FourscoreandsevenyearsagoourfaathersbroughtforthonthiscontainentanewnationconceivedinzLibertyanddedicatedtothepropositionthatallmenarecreatedequalNowweareengagedinagreahtcivilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
	cout<<"The longest one is "<<getlongestPalindrome(input)<<endl;	
}

