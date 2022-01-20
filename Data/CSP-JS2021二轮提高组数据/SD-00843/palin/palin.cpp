#include<cstdio>
#include<algorithm>
#include<cstring>
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
const int N=500005;
int t,n,a[N<<1],p[N<<1],vis[N<<1],l,r,ans[N<<1];
int yyy[N<<1];
bool flag;
void print(){
	l=1;
	r=n;
	n=n>>1;
	memset(yyy,0,sizeof(yyy));
	for(int i=1;i<=n;++i){
		if(ans[i]) yyy[i]=a[r],--r,printf("R");
		else yyy[i]=a[l],++l,printf("L");
	}
	for(int i=n;i>=1;--i){
		if(yyy[i]==a[l]) ++l,printf("L");
		else --r,printf("R");
	}
	putchar('\n');
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--){
		memset(vis,0,sizeof(vis));
		memset(ans,0,sizeof(ans));
		memset(p,0,sizeof(p));
		n=read()<<1;
		for(int i=1;i<=n;++i){
			a[i]=read();
			if(vis[a[i]]){
				p[i]=vis[a[i]];
				p[vis[a[i]]]=i;
			}
			else vis[a[i]]=i;
		}
//--------------------left-------------------
		memset(vis,0,sizeof(vis));
		vis[p[1]]=1;
		l=2;
		r=n;
		ans[1]=0;
		flag=1;
		for(int i=2;i<=(n>>1);++i){
			if((!vis[l])&&(vis[p[l]+1]||vis[p[l]-1])){
				vis[p[l]]=1;
				ans[i]=0;
				++l;
			}
			else if((!vis[r])&&(vis[p[r]+1]||vis[p[r]-1])){
				vis[p[r]]=1;
				ans[i]=1;
				--r;
			}
			else{
				flag=0;
				break;
			}
		}
		if(flag){
			print();
			continue;
		}
//---------------------right------------------------
		memset(vis,0,sizeof(vis));
		vis[p[n]]=1;
		l=1;
		r=n-1;
		ans[1]=1;
		flag=1;
		for(int i=2;i<=(n>>1);++i){
			if((!vis[l])&&(vis[p[l]+1]||vis[p[l]-1])){
				vis[p[l]]=1;
				ans[i]=0;
				++l;
			}
			else if((!vis[r])&&(vis[p[r]+1]||vis[p[r]-1])){
				vis[p[r]]=1;
				ans[i]=1;
				--r;
			}
			else{
				flag=0;
				break;
			}
		}
		if(flag){
			print();
			continue;
		}
		printf("-1\n");
	}
	return 0;
}
