#include<iostream>
#include<cstdio>
#include<queue>
#include<set>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x*f;
}

const int mod=1e9+7;
int n,k,tot,ans,totvis,minn=1000;
int pos[505],ceng[505],posl[505],posr[505];
bool vis[505];
char a[505],fh[3]={'(','*',')'};

void modivis(int l,int r)
{
	for(int i=l;i<=r;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			totvis++;
		}
	}
}

void init()
{
	memset(ceng,0,sizeof ceng);
	memset(posl,0,sizeof posl);
	memset(posr,0,sizeof posr);
	memset(vis,0,sizeof vis);
	totvis=0;
	minn=1000;
}

bool check()
{
	if(a[1]=='*'||a[n]=='*') {return false;}
	int temp=1;
	int tl=0,tr=0,lps=0,rps=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i-1]&&a[i]=='*') temp++;
		else temp=1;
		if(temp>k) {return false;}
		if(a[i]=='(') posl[++tl]=i;
		if(a[n-i+1]==')') posr[++tr]=n-i+1;
	}
	if(tl!=tr){return false;}//左右括号数量不同;
	int c=0;
	for(int i=1;i<=n;i++)
	{
		minn=min(minn,c);
		if(a[i]=='(')
		{
			ceng[i]=++c;
		}
		else if(a[i]=='*') ceng[i]=c;
		else ceng[i]=c--;
	}
	int l=posl[tl],r=posr[tl];//此时tl=tr;
	for(int i=1;i<=n;i++) if(a[i]=='*'&&ceng[i]==minn) vis[i]=1,totvis++;
	while(l>=1&&r<=n)
	{
		if(l>r) {return false;}
		if(a[l-1]=='*'&&a[r+1]=='*')
		{
			return false;
		}
		if(ceng[l-1]==ceng[l]&&a[l-1]!=')') l--;
		if(ceng[r+1]==ceng[r]&&a[r+1]!='(') r++;
		if(a[l]=='('&&a[r]==')')
		{
			modivis(l,r);
			l=posl[--tl];r=posr[tl];
		}
		if(tl==0)
		{
			if(totvis<n)
			{
				return false;
			}
			else {return true;}
		}
		
	}
	return true;
}

void work(int cur,int sum)//当前操作'?'的pos下标,已操作'?'的总数;
{
	if(sum==tot)
	{
		init();
		if (check())
		{
			ans++;
		}
		return;
	}
	a[pos[cur]]=fh[0];
	work(cur+1,sum+1);
	a[pos[cur]]=fh[1];
	work(cur+1,sum+1);
	a[pos[cur]]=fh[2];
	work(cur+1,sum+1);
	
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();k=read();
	cin>>a+1;
	for(int i=1;i<=n;i++)
		if(a[i]=='?') pos[++tot]=i;
	work(1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
7 3 (*??*??
*/

/*
10 2 ???(*??(?)

*/

/*
可以考虑如果一组同层括号两旁有同层星号则这种方案不可以 
*/
