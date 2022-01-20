#include<cstdio>
#include<algorithm>
using namespace std;
#define C getchar()
typedef long long ll;
ll read(){
	ll f=1,x=0;
	char ch=C;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=C;}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=C;
	return x*=f;
}
const int N=505,mod=1e9+7;
int n,k;
ll ans,sum[N];
char s[N],p[N];

//int work(int l,int r){
//	if(s[l]==')'||s[r]=='('||s[l]=='*'||s[r]=='*') return 0;
//	if(r-l==1) return 1;
//	ll res=0;
//	if(r-l-1<=k) ++res;
//	for(int i=l+1;i+2<=n;++i)
//		res=(work(l,i)*work(i+1,r)%mod+res)%mod;
//	for(int i=l+1;i<=l+k;++i)
//		if(s[i]=='*'||s[i]=='?') res=(work(i+1,r-1)+res)%mod;
//		else break;
//	for(int i=r-1;i>=r-1;--i)
//		if(s[i]=='*'||s[i]=='?') res=(work(l+1,i-1)+res)%mod;
//		else break;
//	if(s[l+1]!=')'&&s[l+1]!='*'&&s[r-1]!='('&&s[r-1]!='*') res=(work(l+1,r-1)+res)%mod;
//	return res;
//}

void dfs(int x,int cnt,int len){
	if(x>n){
		if(cnt==0&&len<=k){
			ans=(ans+1)%mod;
		}
		return;
	}
	if(sum[x+1]>=cnt+1&&(s[x]=='('||s[x]=='?')){
		p[x]='(';
		dfs(x+1,cnt+1,0);
	}
	if(cnt>=1&&(s[x]==')'||s[x]=='?')){
		p[x]=')';
		dfs(x+1,cnt-1,0);
	}
	if(x!=1&&x!=n&&len<k&&(s[x]=='*'||s[x]=='?')){
		p[x]='*';
		dfs(x+1,cnt,len+1);
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();
	k=read();
	scanf("%s",s+1);
	for(int i=n;i>=1;--i)
		if(s[i]=='(') sum[i]=sum[i+1]-1;
		else if(s[i]==')'||s[i]=='?')sum[i]=sum[i+1]+1;
		else sum[i]=sum[i+1];
	dfs(1,0,0);
	printf("%lld\n",ans);
	return 0;
}
