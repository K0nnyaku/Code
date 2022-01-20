#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<vector>
#include<cstdlib>
using namespace std;
int read()
{
	int x=0;bool f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=0;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?x:(~x)+1;
}
int t;
int n;
string sz[1000006];
bool pd[1000006];
bool f=0;
int huiwen(string a)
{
	int len=a.size();
	for(int i=0,j=len-1;i<len/2,j>=0;i++,j--)
	if(a[i]!=a[j])
	return 0;
	return 1;
}
void print()
{
	for(int i=1;i<=2*n;i++)
	{
		if(pd[i]==0)
		printf("L");
		else 
		printf("R");
	}
	cout<<endl;
}
void dfs(int x,string b,int l,int r)
{
	if(f==1)
	return;
	if(x==2*n+1)
	{
		if(huiwen(b))
		{
			print();
			f=1;
		}return;
	}
	dfs(x+1,b+sz[l],l+1,r);
	pd[x]=1;
	dfs(x+1,b+sz[r],l,r-1);
	pd[x]=0;
}
int main()
{
	freopen("pailn.in","r",stdin);
	freopen("pailn.out","w",stdout);
	 t=read();
	 while(t--)
	 {
	 	memset(pd,0,sizeof(pd));
	 	string b;
	 	n=read();
	 	for(int i=1;i<=n*2;i++)
	 	cin>>sz[i];
	 	
	 	f=0;
	 	dfs(1,b,1,2*n);
	 	if(f==0)
		 cout<<-1<<endl; 
	 }
	fclose(stdin);
	fclose(stdout);
	 return 0;
}
