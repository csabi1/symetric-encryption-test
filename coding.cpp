#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


using namespace std;

string kapottSzoveg;
string abc = "abcdefghijklmnopqrstuvwxyz_";

class titkosit{
	int v[27][27];
	int kodSzamlalo=0;
	
	public:void abcAtrendezes(string b){
		
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
	
	public:void alakit (string a){
		for (int i=0; i < a.length(); i++) 
			{
				for (int j=0; j < 27; j++)
				{
					
					if (a[kodSzamlalo] == abc[j] ){ v[i][j] = 0; }
					else { v[i][j] =1; }
						
					
					
			    } kodSzamlalo++;	
			}
		
		
	}
	public:void kiir(string a)
	{
		int sz=0;
			for (int i=0; i < a.length(); i++) 
			{	cout<<setw(3)<<sz<<". ";
				for (int j=0; j < 27; j++)
				{
				
					if (v[i][j] == 0 ) { cout<<" "; }
				    if (v[i][j] == 1 ) { cout<<"█"; }
						
				
					
			    } 	sz++; cout<<endl;
			}
	}
	
	public:void outFileba(string a)
	{
		ofstream myfile("codesrc.txt");
		
		
			for (int i=0; i < a.length(); i++) 
			{	
				for (int j=0; j < 27; j++)
				{
				
					if (v[i][j] == 0 ) { myfile<<' '; }
				    if (v[i][j] == 1 ) { myfile<<'-'; }
						
				
					
			    } 	 myfile<<endl;
			}
			myfile.close();
	}
};
int main(){
	string kulcs;
	cout<<"Várok egy szöveget: "<<endl;
	cin >> kapottSzoveg;
	
	cout<<"Kulcs ami szerint kódoljak: "<<endl;
	cin >> kulcs;
	cout<<"A kódolt szöveg a következö: "<<endl;
	titkosit secret;
	secret.abcAtrendezes(kulcs);
	secret.alakit(kapottSzoveg);
	secret.kiir(kapottSzoveg);
	secret.outFileba(kapottSzoveg);
	 
}
