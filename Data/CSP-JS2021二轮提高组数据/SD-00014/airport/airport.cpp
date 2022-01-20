#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include<ctime>
using namespace std;

int n,m_1,m_2;
int main()
{
	//预处理 
	ifstream file_in;
	ofstream file_out;
	file_in.open("airport.in");
	file_out.open("airport.out");
	//输入 
	file_in>>n>>m_1>>m_2;
	
	if(m_1>m_2)
	{
		file_out<<m_1;
	}
	else
	{
		file_out<<m_2;
	}
	
	//结束 
	file_out.close();
	file_in.close();
	return 0;
}
