#include<iostream>
#include<cstdio>
#define mL 505
#define modN 1000000007
using namespace std;
int n,k,m,q[mL],ans;
char ch[mL],ava[3]={'(',')','*'};
inline int rf()
{
	int rx=0,rfh=1,rch=0;
	while(rch<'0'||rch>'9') {rch=getchar();if(rch=='-')  rfh=-1;}
	while(rch>='0'&&rch<='9') {(rx*=10)+=(rch^48);rch=getchar();}
	return rx*rfh;
}
inline bool judge(int l,int r)
{
	if(r-l==1&&ch[l]=='('&&ch[r]==')')	return true;
	if(ch[l]!='('||ch[r]!=')')	return false;
	
	int i=l+1,dep=0,b=0,c=0;
	bool flag=1;
	
	for(;i<r;i++)
	{
		if(ch[i]=='*')	{c++;if(c>k)	return false;}
		else	{c=0;flag=0;}
	}
	if((!flag)&&ch[l+1]=='*'&&ch[r-1]=='*')	return false;
	
	i=l+1;
	while(i<r)
	{
		if(ch[i]=='(')	{dep++;if(b==0)	b=i;}
		if(ch[i]==')')	
		{
			dep--;
			if(dep<0) return false;
			if(dep==0)	{if(!judge(b,i)) return false;b=0;}
		}
		i++;
	}
	if(dep>0)	return false;
	return true;
}
inline void dfs(int d)
{
	for(int i=0;i<3;i++)
	{
		ch[q[d]]=ava[i];
		if(d==m)
		{
			if(judge(0,n)&&ch[1]=='('&&ch[n-1]==')')	ans++;
			if(ans==modN)	ans=0;
		}
		else
			dfs(d+1);
	}
	return;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=rf();k=rf();m=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%c",ch+i);
		if(ch[i]=='?')	q[++m]=i;
	}
	ch[0]='(';ch[++n]=')';
	if(m<=15)	
	{
		dfs(1);
		printf("%d",ans);
		return 0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

