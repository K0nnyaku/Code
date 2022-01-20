#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,k;
string a;
char g[505];
bool check(string a)
{
	int cc=0,t=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]=='(')cc++;
		else if(a[i]==')')cc--;
		if(cc<0)return false;
		if(a[i]=='*')
		{
			if(cc==0)return false;
			t++;
		}
		else
		t=0;
		if(t>k)return false;
	}
	if(cc!=0)return false;
	return true;
}
//  (*()*)??? 
int c=0;
char tr[4]={0,'(',')','*'};
void chao(int t,string ss)
{
	if(t==n)
	{
		if(check(ss))c++;
		return;
	}
	for(int i=1;i<=3;i++)
	{
		chao(t+1,ss+tr[i]);
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	cin>>a;
	chao(1,"(");
	cout<<c;
	return 0;
}
