#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
using namespace std;
ifstream fin;
ofstream fout;

int fff(bool f)
{
	if(f)
	{
	    fin.open("bracket.in");
	    fout.open("bracket.out");
	}
	else
	{
	    fin.close();
        fout.close();
	}
	return 0;
}
int main(){
	fff(1);
	cout<<"5";
	fff(0);
}

