#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
using namespace std;
int T,n,head,flag = 0;
int a[500100];
int b[500100];
char solve[500100];
bool check(){
	int l=1,r=n*2;
	while(l<=r){
		//cout<<b[l]<<" "<<b[r]<<endl;
		if(b[l] != b[r]) return 0;
		l++;r--;
	}
	return 1; 
}
void dfs(int tot,int le,int ri){
	//if(le > ri) return;
	if(flag == 1) return;
	if(tot >= n*2 + 1 ){
		if(check() == 1){
			for(int i=1;i<=n*2;i++){
				printf("%c",solve[i]);
			}
			flag = 1;
		}
		return;
	}
	b[n*2 - tot + 1] = a[le];
	solve[tot] = 'L';
	dfs(tot+1,le+1,ri);
	b[n*2 - tot + 1] = -1;
	solve[tot] = '0';
	
	b[n*2 - tot + 1] = a[ri];
	solve[tot] = 'R';
	dfs(tot+1,le,ri-1);
	b[n*2 - tot + 1] = -1;
	solve[tot] = '0';
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		scanf("%d",&n);
		flag = 0;
		head = 1;
		for(int i=1;i<=n*2;i++) scanf("%d",&a[i]);
		dfs(1,1,n*2);
		if(flag == 0) printf("-1\n");
		else printf("\n");
	}
} 
