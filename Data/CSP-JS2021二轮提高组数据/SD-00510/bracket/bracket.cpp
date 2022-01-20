#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	int n,k;
	cin >> n >> k;
	string str;
	cin >> str;
	int cnt=0;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='?')
		{
			cnt++;
		}
	}
	cout << cnt*(cnt-3)+1 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
