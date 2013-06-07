// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector>
using namespace std;

int main () {
  string line;

  //for reading file
  ifstream inputFile ("A-large-practice.in");

  //for writing file
    ofstream resultfile;
    resultfile.open ("result.txt");

  if (inputFile.is_open())
  {
	  getline (inputFile,line);
	  stringstream ss(line);
	  int numberOfCases;
	  ss >> numberOfCases;
	  cout << numberOfCases << endl;
    for(int index = 0; index < numberOfCases; index++){

      getline (inputFile,line);//should do three times for this case
      stringstream ss1(line);
      int credit;
      ss1 >> credit;

      getline (inputFile,line);//should do three times for this case
      stringstream ss2(line);
      int numberofitems;
      ss2 >> numberofitems;


      getline (inputFile,line);//should do three times for this case
      string buf; // Have a buffer string
      stringstream ss(line); // Insert the string into a stream

      //get all elements in one case
      vector<string> tokens; // Create vector to hold our words
      while (ss >> buf)
          tokens.push_back(buf);

      int size = (int)tokens.size();
      int index1, index2;
      for(int j = 0; j < size; j++){
    	  int a = 0;
    	  stringstream ssa(tokens.at(j));
    	  ssa >> a;

    	  for(int m = j+1; m < size; m++){
    		  int b = 0;
    		  stringstream ssa(tokens.at(m));
    		  ssa >> b;
    		  if(a+b == credit && m != j){
    			  index1 = j;
    			  index2 = m;
    		  }
    	  }
      }

      resultfile << "Case #" <<index+1 <<": "<<index1+1 << " " <<index2+1<< endl;


    }
    inputFile.close();
    cout << numberOfCases << endl;

  }

  resultfile.close();

  cout << "end!" <<endl;

  return 0;
}
