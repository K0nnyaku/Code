#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<vector>

using namespace std;

const int N =5e5 +100;

int a[N*2],vis[N];
int n;
int flag=0;
vector<pair<int,int> > v,ans; // 1 is l,2 is r

void dfs(int x,int y){
	if(flag) return ;
	if(y-x+1 <= n){
		ans=v;
		int len = v.size();
		int l=x,r=y;
		for(int i=len-1;i>=0;i--){
			int pos=v[i].first;
			if(a[l]==a[pos]){
				ans.push_back({l,1});
				l++;
			}
			else if(a[r]==a[pos]){
				ans.push_back({r,2});
				r--;
			}
			else return ;
		}
		flag=1;
		return ;
	}
	if(flag) return ;
	if(!vis[a[x]]){
		vis[a[x]]=1;
		v.push_back({x,1});
		dfs(x+1,y);
		v.pop_back();
		vis[a[x]]=0;
	}
	if(flag) return ;
	if(!vis[a[y]]){
		vis[a[y]]=1;
		v.push_back({y,2});
		dfs(x,y-1);
		v.pop_back();
		vis[a[y]]=0;
	}
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",a+i);
		}
		memset(vis,0,sizeof vis);
		flag=0;
		dfs(1,2*n);
		if(flag==0) printf("-1\n");
		else{
			for(int i=0;i<2*n;i++){
				if(ans[i].second==1){
					printf("L");
				}
				else printf("R");
			}
			puts("");
		}
	}
	return 0;
}

