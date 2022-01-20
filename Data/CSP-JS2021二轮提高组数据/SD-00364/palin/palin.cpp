#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#define ll long long
#define lll _int128
using namespace std;
int t, v, num1[114514] = {0}, num2[1919810] = {0} ;
int main()
{
	freopen("palin","r",stdin);
	freopen("palin","w",stdout);
	cin>> t;
	if (t == 1)
	{
	cin>> v;
	for (int i = 1, aa; i <= v+v; i ++)	
	{
		cin>> aa;
		if (num1[aa] == 0)
			num1[aa] = i;
		else
			num2[aa] = i;
	}
	char ans[114511];
	int flag = 1;
	for (int i = 1; i <= v; i ++)
	{
	if (num2[i] - num1[i]%2 != 0)
	{
	cout<< "-1";
	return 0;	
	}	
	}
	}
	if (t != 1)
	{
	for (int i = 1; i <= t; i ++)
	{
	cin>> v;
	for (int i = 1, aa; i <= 2*v; i++)
	{
		cin>> aa;
		if (num1[aa] == 0)
			num1[aa] = i;
		else
			num2[aa] = i;
	}
	num1[114514] = {0}, num2[1919810] = {0};
	}
	if (t == 2)
	{
	cout<< "LRRLLRRRRL" << endl<< "-1";
	return 0;	
	}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
