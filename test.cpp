#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;
int main()
{
	string s;
	ifstream myFile("codesrc.txt");
	int v[30][30];
	int sizeOfCode=0;    	   
	while (!myFile.eof()){
	   getline(myFile,s);
	   for (int i=0; i < s.size(); i++)
        {
		  
		  if (s[i]=='-')
		   { v[sz][i] = 1;} else {
			   v[sz][i] = 0;
		   }
	    }sz++;
	}

    
    
 
    
    
    
   
}
