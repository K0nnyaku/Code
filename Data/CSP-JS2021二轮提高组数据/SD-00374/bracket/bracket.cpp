#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cmath>
using namespace std;
inline int read() {
	int f=0,res=0; char ch;
	while(ch<'0'||ch>'9') {if(ch=='-')f=1; ch=getchar();}
	while(ch>='0'&&ch<='9'){res=(res<<1)+(res<<3)+(ch^48);ch=getchar();}
	return f?-res:res; 
}
const int maxn=520;
int n,k,ans,sk[maxn];
char s[maxn],c[maxn];
inline bool check() {
	int tot=0;
	for(int i=1;i<=n;i++) {
		if(c[i]=='(') sk[++tot]=i;
		if(c[i]==')') {
			if(tot==0) return false;
			int u=sk[tot]-sk[tot-1];
			if((u>=1&&c[i+1]!='*')||(c[i+1]=='*'&&u==1)||(c[i+1]!='*'&&i==n)) --tot;
			else return false;
		}
	} if(tot!=0) return false;
	//for(int i=1;i<=n;i++) cout<<c[i]; cout<<endl;
	return true;
}
inline void dfs(int x,int y) {
	if(x==n) {
		if(check()) ans++;
		return;
	} if(s[x]!='?') {
		if(s[x]=='*') {
			if(y<k)	dfs(x+1,y+1);
			else return;
		} else dfs(x+1,0);
	} else {
		if(y<k) {c[x]='*';dfs(x+1,y+1);}
		c[x]='('; dfs(x+1,0);
		c[x]=')'; dfs(x+1,0);
	} return;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(); k=read(); scanf("%s",s+1);
	if(s[1]!='?'&&s[1]!='(') {cout<<0<<endl; return 0;}
	s[n]=')'; s[1]='(';
	for(int i=1;i<=n;i++) c[i]=s[i];
	dfs(1,0); cout<<ans<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
