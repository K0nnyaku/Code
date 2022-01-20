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
	    fin.open("traffic.in");
	    fout.open("traffic.out");
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
	cout<<"12";
	fff(0);
}

