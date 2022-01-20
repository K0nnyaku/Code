#include<cstdio>
#include<cstring>
using namespace std;
const int N=5e5+5;
int a[N<<1],n,aaa[N<<1];
char ans[N<<1],chf[N<<1];
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
bool chk(int c[])
{
	int i;
	for(i=1;i<=n;i++)
	if(c[i]!=c[n*2-i+1])
	return 0;
	return 1;
}
bool comparec(char s[],char t[])
{
	int i;
	for(i=1;i<=n*2;i++)
	if(s[i]!=t[i])
	{
		if(s[i]=='L'&&t[i]>='R')
		return 1;
		if(s[i]=='R'&&t[i]=='L')
		return 0;
	}
	return 0;
}
void dfs(int l,int r,int cnt,int aa[],char ch[])
{
	int i;
	if(cnt==2*n)
	{
		if(chk(aa))
		{
			if(comparec(ch,ans))
			for(i=1;i<=2*n;i++)
			ans[i]=ch[i];
		}
		return;
	}
	ch[++cnt]='L';aa[cnt]=a[l];
	dfs(l+1,r,cnt,aa,ch);
	ch[cnt]='R';aa[cnt]=a[r];
	dfs(l,r-1,cnt,aa,ch);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T,i;
	T=read();
	while(T--)
	{
		for(i=1;i<=2*N;i++)
		ans[i]='R'+1;
		n=read();
		for(i=1;i<=n*2;i++)
		a[i]=read();
		dfs(1,2*n,0,aaa,chf);
		if(ans[1]!='S')
		for(i=1;i<=2*n;i++)
		printf("%c",ans[i]);
		else
		printf("-1");
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
