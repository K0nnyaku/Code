#include <iostream>
#include <cstdio>

using namespace std;

void read(int &x)
{
	int f= 1;
	x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch= getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + ch^48;
		ch = getchar();
	}
	x *= f;
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;
	read(n);read(k);
	string s;
	cin >> s;
	return 0;
}

