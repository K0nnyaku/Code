#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
const int mod=1e9+7;
long long n,k,id[505],cnt,l,sum,ans,num,ps;
char s[505];
bool vis[505];
long long nxt[505];
inline long long read(){
	long long s=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
void solve(int now){
	if(now>cnt){
		l=0;sum=0;num=0;ps=0;
		for(int i=1;i<=n;i++)vis[i]=nxt[i]=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='(')vis[l]=1,l++,nxt[l]=i,sum=0;
			if(s[i]=='*')sum++;
			if(s[i]==')'){
				if(vis[l]&&s[nxt[l]+1]=='*'&&s[i-1]=='*')return;
				vis[l]=0;
				nxt[l]=0;
				l--;sum=0;
			}
			if(sum>k||l<0)return;
		}
		if(l||s[n]=='*'||s[1]=='*')return;
		ans=(ans+1)%mod;
		return;
	}
	s[id[now]]='(',solve(now+1);
	s[id[now]]=')',solve(now+1);
	s[id[now]]='*',solve(now+1);
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();k=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)if(s[i]=='?')id[++cnt]=i;
	solve(1);
	printf("%lld",ans);
	return 0;
} 
