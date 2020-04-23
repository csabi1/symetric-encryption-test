#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <string.h>
#include <thread>
#include <unistd.h>
using namespace std;
int v[50][50];
int sizeOfCode=0;
string abc = "abcdefghijklmnopqrstuvwxyz_";
char megfejtett[100];
class decode {
	string current;
	string ures;
	
	public:void olvas(string a)
    {
	    string s;
	    ifstream myFile(a);
	       	   
	   while (!myFile.eof()){
	   getline(myFile,s);
	   for (int i=0; i < s.size(); i++)
        {
		  
		  if (s[i]=='-')
		   { v[sizeOfCode][i] = 1;} else {
			   v[sizeOfCode][i] = 0;
		   }
	    }sizeOfCode++;
	}

    
	}
	
	
		
	public:void kiir(int a)
	{
		int sz=0;
			for (int i=0; i < a; i++) 
			{	
				for (int j=0; j < 27; j++)
				{
				
					if (v[i][j] == 0 ) { cout<<" "; }
				    if (v[i][j] == 1 ) { cout<<"█"; }
						
				
					
			    } 	sz++; cout<<endl;
			}
	}
		public:void abcdekodolas(string b){
		
		char tmp;
			for (int i=0; i < b.length(); i++) 
			{
				for (int j=0; j < 27; j++)
				{
					if (b[i] == abc[j] )
					{
						tmp = abc[j];
						if ( j < 20 ) { abc[j] = abc[j+5]; abc[j+5] = tmp; }
						if ( j > 20 ) { abc[j] = abc[j-6]; abc[j-6] = tmp; }
					}
					
			    } 
			}
		
	}
	void visszafejtes()
	{
		for (int i =0 ; i<sizeOfCode-1 ; i++){
		 for (int j =0 ; j<27;j++)
		 {
			if (v[i][j] == 0 ){megfejtett[i] = abc[j];}
		 }
	 }
    }
};

int main()
{
	string kulcs, filenev;
	
	
	decode uj;
	
	
	cout<<"Add meg a filenevét amiben a titkosítás található: "<<endl;
	cin>>filenev;
	uj.olvas(filenev);
	cout<<endl<<"A file-ból beolvasott minta a következö: "<<endl;
	uj.kiir(sizeOfCode);
	cout<<"Add meg a kulcsot amivel dekódoljam a file-t: "<<endl;
	cin>>kulcs;
	/*for (int i =0; i < 100 ;){
		i+= 20;
		cout<<"A kód megfejtése folyamatban...    "<<i<<"%"<<endl;
		usleep(1200);
		
		
	}*/
	uj.abcdekodolas(kulcs);
	uj.visszafejtes();
	
	cout<<"A kódolt szöveg: ";
	cout<<megfejtett<<endl;
}
