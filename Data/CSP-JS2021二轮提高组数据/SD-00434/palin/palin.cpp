#include<iostream>
#include<cstdio>
#include<deque>
using namespace std;
int T,a[1000010],n;
deque<int> q,TMP_;
int tmp[1000010];
char ans[1000010];
bool Flag=0;
bool check(){
	TMP_=q; 
	int cnt=0;
	while(!q.empty()) tmp[++cnt]=q.front(),q.pop_front();
	for(int i=1,j=2*n;i<=j;i++,j--){
		if(tmp[i]!=tmp[j]){
			q=TMP_;
			return false;
		}
	}
	q=TMP_;
	return true;
} 
void dfs(int l,int r,int dep){
	if(l>r){
		if(check()){
			puts(ans);
			Flag=1;return;
		}
		return ;
	}
	q.push_back(a[l]);
	ans[dep]='L';
	dfs(l+1,r,dep+1);
	q.pop_back();
	if(Flag) return;
	q.push_back(a[r]);
	ans[dep]='R';
	dfs(l,r-1,dep+1);
	q.pop_back();
	if(Flag) return;
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		Flag=0;q.clear();
		for(int i=1;i<=n*2;i++) scanf("%d",&a[i]);
		dfs(1,n*2,0);
		if(Flag);
		else printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

