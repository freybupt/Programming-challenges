#include<iostream>
#include<set>
#include<String>
/* input a string, output the power set of the set of all characters 
   e.g input: "abac"
*/

set<string> getPowersertFromString(String *inputString){
//get all unique char from string
set<char> uniqueSet;
for(int i=0; i<inputString.size(); i++){
    if(uniqueSet.count(inputString[i]) == 0){
        uniqueSet.insert(inputString[i]);
    }
}
//form the power set from all unique chars
    return getPowerSet(uniqueSet); //uniqueSet: {a,b,c}
}


set<string> getPowerSet(set<char> inputSet){
//use dynamic programming
    if(inputSet.empty()){
        char emptyChar = '%';
        set<char> resultSet;
        resultSet.insert(emptyChar);
        return resultSet;
    }
    else{
        //remove the last element from the set
        set<int>::iterator it = inputSet.end();
        char lastChar =  *it;
        set<char> smallSet = inputSet;
        //remove the last char
        smallSet.erase(it);
        set<string> smallSetResult = getPowerSet(smallSet);
        set<string> bigSetResult = smallSetResult;
        for...
        bigSetResult.insert(lastChar); //for each of them
        set<string> resultSet;
        resultSet.insert(smallSetResult);
        resultSet.insert(bigSetResult);
        return resultSet;
    }
}


int main(){
	return 1;
}