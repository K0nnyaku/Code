#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
inline int read()
{
	int x=0,y=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') y=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*y;
}

int t,n,top;
int a[1000005],s[1000005];
bool vis[1000005];
int ans[1000005],res[1000005];

bool dfs(int step,int l,int r){
	if(step==n+1){
		int k=n,top=n;
		while(top){
			if(a[l]==s[top]){
				ans[++k]=0;
				top--; 
				l++;
			}else if(a[r]==s[top]){
				ans[++k]=1;
				top--;
				r--;
			}else{
				return 0;
			}
		}
		bool flag=0;
		for(int i=1;i<=2*n;i++){
			if(ans[i]==res[i]) continue;
			else if(ans[i]<res[i]){
				flag=1;
				break;
			}else{
				break;
			}
		}
		if(flag==1){
			for(int i=1;i<=2*n;i++){
				res[i]=ans[i];
			}
		}
		return 1;
	}
	if(!vis[a[l]]){
		vis[a[l]]=1;
		ans[step]=0;
		s[step]=a[l];
		dfs(step+1,l+1,r);
		vis[a[l]]=0;
		top--;
	}
	if(!vis[a[r]]){
		vis[a[r]]=1;
		ans[step]=1;
		s[step]=a[r];
		dfs(step+1,l,r-1);
		vis[a[r]]=0;
		top--;
	}else{
		return 0;
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=2*n;i++) a[i]=read(),res[i]=1;
		memset(vis,0,sizeof(vis));
		dfs(1,1,2*n);
		bool flag=1;
		for(int i=1;i<=2*n;i++){
			if(!res[i]){
				flag=0;break;
			}
		}
		if(!flag){
			for(int i=1;i<=2*n;i++){
				if(res[i]) printf("R");
				else printf("L");
			}
			printf("\n");
		}else{
			printf("-1\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

