#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,top,fro=1,lst;
int tot=0,a[2500],b[2500];
string s[5000];
char pre[2500];
int read()
{
	int f=1,s=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();} 
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
void ne()
{
	tot++;
	for(int i=1;i<=2*n;i++)
		s[tot][i]=pre[i];
}
void jud()
{
	for(int i=1;i<=n;i++)
		if(b[i]!=b[2*n+1-i]) return;
	ne();
}
void solve(int lev)
{
	if(lev==2*n+1) 
	{
		jud();
		return; 
	}
	b[lev]=a[fro++];
	pre[lev]='L';
	solve(lev+1);
	fro--;
	pre[lev]='R';
	b[lev]=a[lst--];
	solve(lev+1);
}
void out_answer()
{
	solve(1);
	if(!tot) printf("-1\n") ;
	sort(s+1,s+tot+1);
	for(int i=1;i<=2*n;i++) cout<<s[1][i];
}
void get_data()
{
	int t=read();
	for(int i=1;i<=t;i++)
	{
		fro=1;tot=top=0;
		memset(pre,0,sizeof(pre));
		memset(s,0,sizeof(s));
		n=read();
		for(int j=1;j<=2*n;j++)
			a[j]=read();
		lst=2*n;
		out_answer();
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	get_data();
	return 0;
}
/*2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3*/
