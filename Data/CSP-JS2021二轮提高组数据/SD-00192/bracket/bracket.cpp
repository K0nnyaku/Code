#include<bits/stdc++.h>
using namespace std;
int zz=0,starr=0,asbb=0,ass=0,ans=0,n,k,cici[501],kiki[501];
int star(string);
int asb(string);
int as(string);
int search(string,int);
int cs(string);
int main()
{
//	freopen("bracket.in","r",stdin);
//freopen("bracket.out","w",stdout);
	string ss;
	cin>>n>>k;
	getline(cin,ss);
	search(ss,0);
	cout<<ans;
//	fclose(stdin);fclose(stdout);
	return 0;
}
int search(string ss,int aop)
{
	for(int i=aop;i<n;i++)
	if(ss[i]=='?')
	{//int tr=i-aop;
	//aop=aop+tr;
	for(int j=1;j<=3;j++)
		{
			if(j==1)ss[i]=='*';
			if(j==2)ss[i]=='(';
			if(j==3)ss[i]==')';
			if(i==n-1)cs(ss);
			else search(ss,i+1);
			ss[i]='?';
		}
	}
}
int cs(string ss)
{
	star(ss);
	asb(ss);
	as(ss);
	if(starr==0&&asbb==0&&ass==0)ans++;
}
int star(string ss)
{
	for(int i=0;i<n;i++)
	if(ss[i]=='('||ss[i]==')')
	for(int j=i;j<n;j++)
	{if(ss[i]=='*')zz++;
	else {if(zz>k)starr++;zz=0;break;}
	}
}
int asb(string ss)
{
	int count=0;
	for(int i=0;i<n;i++)
	if(ss[i]=='('||ss[i]==')')
	count++;
	if(count%2!=0)asbb++;
	count=0;
}
int as(string ss)
{
	int kl=-1,lk=-1;
	for(int i=0;i<n;i++)
	if(ss[i]=='(')
	{
	cici[kl++]=i;
		}
	for(int i=n-1;i>=0;i--)
	if(ss[i]==')')
	{
	cici[lk++]=i;
		}
	for(int i=0;i<n;i++)
	{
		if(cici[i]-cici[i+1]==1&&kiki[i]-kiki[i+1]==1)ass++;
	}
}
