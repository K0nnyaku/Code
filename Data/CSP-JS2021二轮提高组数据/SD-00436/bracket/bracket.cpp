#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<vector>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#define ll long long
using namespace std;
int n,k,arr[505],num,quiz[505];
int ans,dec;
void input()
{
	cin >> n >> k;
	for(int i=0;i<=n;i++)
	{
		char c;
		scanf("%c",&c);
		if(c=='(')
			arr[i]=1;
		if(c==')')
			arr[i]=2;
		if(c=='*')
			arr[i]=3;
		if(c=='?')
		{
			num++;
			quiz[num]=i;
		}
	}
}
bool check(int* arr)
{
	int cnt=0,mcnt=0,st=0,flag=0;
	for(int i=1;i<=n;i++)
	{
		if(arr[i]==1)
		{
			cnt=0;
			st++;
		}
		if(arr[i]==2)
		{
			cnt=0;
			if(st>=0)
				st--;
			else
				return false;
		}
		if(arr[i]==3)
		{
			cnt++;
			if(cnt>k)
				return false;
		}
	}
	if(flag)
		return false;
	if(st!=0)
		return false;
	if(mcnt>k)
		return false;
	if(cnt!=0)
		return false;
	return true;
}
void calc(int dep)
{
	if(dep>num)
	{
		ans+=check(arr);
		return;
	}
	else
	{
		for(int i=1;i<=3;i++)
		{
			arr[quiz[dep]]=i;
			calc(dep+1);
			arr[quiz[dep]]=0;
		}
	}
}
void output()
{
	cout << ans << endl;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	input();
	calc(1);
	output();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

