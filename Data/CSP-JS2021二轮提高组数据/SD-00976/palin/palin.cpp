#include<cstdio>
#include<iostream>
inline int rd(){
	int res=0,flag=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')flag=-1;
	for(;isdigit(c);c=getchar())res=(res<<1)+(res<<3)+(c-'0');
	return res*flag;
}
const int N=1e6+13;
int n,a[N],tong[N>>1],ms[N],Fa[N],ans[N];
bool vis[N],out[N];
int Find(int x){return Fa[x]==x?x:Fa[x]=Find(Fa[x]);}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
int T=rd();while(T--){
	n=rd();
	for(int i=1;i<=n;++i) tong[i]=vis[i]=0;
	for(int i=1;i<=(n<<1);++i){
		a[i]=rd();int x=a[i];
		if(tong[x]) ms[i]=tong[x],ms[tong[x]]=i;
		else tong[x]=i;
	}
	for(int i=1;i<=(n<<1)+1;++i) Fa[i]=i;
	int tmp=ms[1],l=2,r=(n<<1),cnt=1;ans[1]=a[1],out[1]=1;
	while(cnt<n){
		if(!vis[a[l]]&&(Find(ms[l]-1)==tmp||Find(ms[l]+1)==tmp)){
			ans[++cnt]=a[l];out[cnt]=1;
			Fa[ms[l]]=tmp;vis[a[l]]=1;
			++l;
			continue;
		}
		if(!vis[a[r]]&&(Find(ms[r]-1)==tmp||Find(ms[r]+1)==tmp)){
			ans[++cnt]=a[r];out[cnt]=0;
			Fa[ms[r]]=tmp;vis[a[r]]=1;
			--r;
			continue;
		}
		break;
	}
	if(cnt==n){
		while(vis[a[l]]) ++l;
		while(vis[a[r]]) --r;
		for(int i=1;i<=n;++i) putchar(out[i]?'L':'R');
		for(int i=1;i<=n;++i){
			if(ans[i]==a[l]) putchar('L'),++l;
			else putchar('R'),--r;
		}
		putchar('\n');
		continue;
	}
	for(int i=1;i<=(n<<1)+1;++i) Fa[i]=i;
	tmp=ms[n<<1],l=1,r=(n<<1)-1,cnt=1;ans[1]=a[n<<1],out[1]=0;
	while(cnt<n){
		if(!vis[a[l]]&&(Find(ms[l]-1)==tmp||Find(ms[l]+1)==tmp)){
			ans[++cnt]=a[l];out[cnt]=1;
			Fa[ms[l]]=tmp;vis[a[l]]=1;
			++l;
			continue;
		}
		if(!vis[a[r]]&&(Find(ms[r]-1)==tmp||Find(ms[r]+1)==tmp)){
			ans[++cnt]=a[r];out[cnt]=0;
			Fa[ms[r]]=tmp;vis[a[r]]=1;
			--r;
			continue;
		}
		break;
	}
	if(cnt==n){
		while(vis[a[l]]) ++l;
		while(vis[a[r]]) --r;
		for(int i=1;i<=n;++i) putchar(out[i]?'L':'R');
		for(int i=1;i<=n;++i){
			if(ans[i]==a[l]) putchar('L'),++l;
			else putchar('R'),--r;
		}
		putchar('\n');
		continue;
	}
	puts("-1");
}
	return 0;
}
