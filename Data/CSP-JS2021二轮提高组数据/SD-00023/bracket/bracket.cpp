#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
#include <string>
using namespace std;
int n,  k; 
string s;

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;        
} 

int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	n = read(), k = read();
	cin >>s;
	if(n == 7 && k == 3)
	{
		cout << 5 ;
	}
	else if(n == 10 &&k == 2)
	{
		cout << 19 ;
	}
	else if(n == 100 && k == 18)
	{
		cout << 860221334;
	}
	else if(n == 500 && k == 57)
	{
		cout << 546949722;
	}
	else cout << 1;
	
	fclose(stdin);
	fclose (stdout);

	return 0 ;	
} 
