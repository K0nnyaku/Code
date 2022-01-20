#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include<ctime>
using namespace std;



int main()
{
	fstream file_in;
	fstream file_out;
	file_in.open("palin.in");
	file_out.open("palin.out");
	
	
	
	file_out.close();
	file_in.close();
	return 0;
}
