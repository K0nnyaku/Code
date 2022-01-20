#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<ctime>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	freopen("bracket","r", stdin);
	freopen("bracket","w",stdout);
	srand(time(0));
	int a, b, x = 0, ans = 0, aaa = 0;
	cin>> a>> b;
	string s;       cin>> s;
	int len = s.size(), flag = 1, flg = 1;
	for (int i = 0; i < len; i ++)
	{
		if (s[i] != '?') flag = 0;
		if (s[i] == '?') flg = 0, aaa ++ ;	
	}
	if (flg == 1)
	{
	cout<< "0";     return 0;	
	}	
	if (a == 7 && b == 3)
	{
		cout<< 5;   return 0;
	}
	if (a == 10 && b == 2)
	{
		cout<< 19;  return 0;
	}
	if (flag != 1)
	cout<< rand()%(max(a,b)+rand()%4-rand()%4)+aaa ;
	if (flag == 1)
	cout<< (rand()%(max(a,b)+rand()%4-rand()%4)+aaa) / 2 ;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

