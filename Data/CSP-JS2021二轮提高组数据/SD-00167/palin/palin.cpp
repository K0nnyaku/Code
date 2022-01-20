#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long

using namespace std;
const int N = 5e5 + 10;

ll t,n;
bool flag;
ll a[N];
ll vis[N];

char ch[N];


void dfs(ll wei,ll top,ll tail){
	if(wei > 2 * n){
		printf("%s\n",ch + 1);
		flag = false;
		return;
	}
	
	if(!vis[a[top]]){
		ch[wei] = 'L';
		vis[a[top]] = wei;
	 
		dfs(wei + 1,top + 1,tail);
		vis[a[top]] = 0;
		if(!flag) return;
	}
	if(vis[a[top]]){
		if(wei == 2 * n - vis[a[top]] + 1){
			ch[wei] = 'L';	 
			dfs(wei + 1,top + 1,tail);
			if(!flag) return;
		}
	}
	
	if(!vis[a[tail]]){
		ch[wei] = 'R';
		vis[a[tail]] = wei;
	 
		dfs(wei + 1,top,tail - 1);
		vis[a[tail]] = 0;
		if(!flag) return;
	}
	if(vis[a[tail]]){
		if(wei == 2 * n - vis[a[tail]] + 1){
		
			ch[wei] = 'R';
			dfs(wei + 1,top,tail - 1);
			if(!flag) return;
		}
	}
	
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	scanf("%lld",&t);
	while(t--){
		
		memset(vis,0,sizeof vis);
		
		flag = true;
		scanf("%lld",&n);
		
		for(int i = 1;i <= 2 * n;i ++){
			scanf("%lld",&a[i]);
		}
		
		dfs(1,1,2 * n);
		if(flag) printf("-1\n");
		
	}

	fclose(stdin);
	fclose(stdout);	
	return 0;
}
