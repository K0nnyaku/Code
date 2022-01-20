#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=505;
const int mod=1e9+7;
int len,k,ans;
char s[N],td[N];
int read()
{
	int res,f=1;
	char ch;
	while((ch=getchar())<'0'||ch>'9')
	if(ch=='-')
	f=-1;
	res=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
	res=(res<<1)+(res<<3)+(ch^48);
	return res*f;
}
bool chk(int l,int r,char t[])
{
	if(t[l]=='*')
	return 0;
	int i,cl=0,cr=0,star=0,pl[N],pr[N];
	for(i=l;i<=r;i++)
	{
		if(t[i]=='*')
		{
			star++;
			if(star>k)
			return 0;
		}
		else
		{
			star=0;
			if(t[i]=='(')
			pl[++cl]=i;
			if(t[i]==')')
			pr[++cr]=i;
		}
	}
	if(cl!=cr)
	return 0;
	if(cl==1||!cl)
	for(i=1;i<=cl;i++)
	if(!chk(pl[i],pr[i],t))
	return 0;
	return 1;
}
int dfs(int id,int l,int r,int star,char t[])
{
	if(id==len)
	return chk(0,len-1,t);
	if(s[id]!='?')
	{
		if(s[id]=='(')
		l++;
		if(s[id]==')')
		r++;
		if(s[id]=='*')
		star++;
		if(star>k)
		return 0;
		t[id]=s[id];
		return dfs(id+1,l,r,star,t);
	}
	else
	{
		int ans=0;
		if(star<k)
		{
			t[id]='*';
			ans=(ans+dfs(id+1,l,r,star+1,t))%mod;
		}
		t[id]='(';
		ans=(ans+dfs(id+1,l+1,r,0,t))%mod;
		t[id]=')';
		ans=(ans+dfs(id+1,l,r+1,0,t))%mod;
		return ans;
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	len=read();k=read();
	scanf("%s",s);s[0]='(';s[len-1]=')';
	printf("%d",dfs(0,0,0,0,td));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
