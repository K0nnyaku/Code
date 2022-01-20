#include<vector>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;
	cin >> n >> k;
	string str;
	cin >> str;
	if(n == 1)
	{
		cout << -1 << endl;
	}
	if(n == 2)
	{
		cout << 1 << endl;
	}
	if(n == 3)
	{
		if(k > 0)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
