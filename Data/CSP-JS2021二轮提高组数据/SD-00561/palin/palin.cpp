#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int t,n,a[1000100],b[1000100];
bool tag=0;
char s[1000100];
void dfs(int st,int en,int top){
	if(tag){
		return ;
	}
	if(top>2*n){
		int i=1,j=n+n;
		while(i<j){
			if(b[i]!=b[j]){
				return;
			}
			
			i++;j--;
		}
		for(int i=1;i<=2*n;i++){
			printf("%c",s[i]);
		}
		printf("\n");
		tag=1;
		return ;
	}
	b[top]=a[st];
	s[top]='L';
	dfs(st+1,en,top+1);
	b[top]=a[en];
	s[top]='R';
	dfs(st,en-1,top+1);
	return ; 
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		tag=0;
		scanf("%d",&n);
		for(int i=1;i<=n+n;i++){
			scanf("%d",&a[i]);
		}
		dfs(1,n+n,1);
		if(!tag)printf("-1\n");
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
