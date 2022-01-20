#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include<ctime>
using namespace std;
char a[550];
char try_a[550];
long n,k,num=0,num_uk=0;

void chack()
{
	if(try_a[0]=='*'||try_a[n-1]=='*')return;
	char zan[550];
	int tzan=0;
//	cout<<try_a<<endl;
	for(int i=0;i<n;i++)
	{
//		cout<<i<<" ";
		if(try_a[i]!=')')
		{
			zan[tzan]=try_a[i];
			tzan++;
		}
		else
		{
			int num_str=0;
			tzan--;
			while(zan[tzan]!='(')
			{
				num_str++;
				tzan--;
				if(num_str>k)
				{
					return;
				}
			}
			if(zan[tzan-1]=='*'&&try_a[i+1]=='*')
			{
				while(try_a[i+1]=='*')
				{
					i++;
				}
				if(try_a[i]==')')
				{
					return;
				}
			}
		}
	}
	if(tzan!=0)
	{
		while(zan[tzan-1]=='*')
		{
			tzan--;
		}
	}
	if(tzan==0)
	{
		num++;
	}
}

void find_a(int i)
{
	if(i==n)
	{
		chack();
		return;
	}
	if(a[i]!='?')
	{
		try_a[i]=a[i];
		find_a(i+1);
	}
	else
	{
		try_a[i]=')';
		find_a(i+1);
		try_a[i]='*';
		find_a(i+1);
		try_a[i]='(';
		find_a(i+1);
		
	}
	
}

int main()
{
	//预处理 
	ifstream file_in;
	ofstream file_out;
	file_in.open("bracket.in");
	file_out.open("bracket.out");
	//输入
	file_in>>n>>k;
	file_in>>a;
	find_a(0);
	file_out<<num;
	//结束 
	file_out.close();
	file_in.close();
	return 0;
}
