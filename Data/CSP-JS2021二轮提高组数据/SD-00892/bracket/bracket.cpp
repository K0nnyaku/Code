#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

const int N=510;
char p[N];
char h[N],t[N];
int hh,tt;
int n,k;

bool is(char a[])
{
	if(hh!=tt)return false;
	
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)
	{
	cin>>p[i];	
	}    
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		
		if(p[i]=='(')h[hh++]='(';
		if(p[i]==')')t[tt++]=')';
		
		if(p[i]==p[i+1])cnt++;
		if(p[i]!=p[i+1])cnt=0;
		if(cnt==k-1)
		{
			cout<<0<<endl;
			break;
		}
				
		if(p[0]=='?')p[n]='(';
		if(p[n]=='?')p[n]=')';
		
		if(p[0]!='('||p[n]!=')')
		{
			cout<<0<<endl;
			break;
		}
		cout<<67;
	}
	return 0;
 } 
