#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<cstring>
#include<string>
#include<map>
using namespace std;
const int maxn=500005;
int T,n,a[maxn],t[maxn];
char path[maxn],ans[maxn];
int flag=0;
void dfs(int step,int l,int r){
	if(step==2*n){
		if(flag==0){
			for(int i=1;i<=2*n;i++){
				ans[i]=path[i];
			}
		}
		flag=1;
		return;
	}
	if(t[a[l+1]]==0||t[a[l+1]]!=0&&t[a[l+1]]+step==2*n){
		t[a[l+1]]=step+1;
		path[step+1]='L';
		dfs(step+1,l+1,r);
		t[a[l+1]]=0;
	}
	if(t[a[r-1]]==0||t[a[r-1]]!=0&&t[a[r-1]]+step==2*n){
		t[a[r-1]]=step+1;
		path[step+1]='R';
		dfs(step+1,l,r-1);
		t[a[r-1]]=0;
	}
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	if(T<100){
		while(T--){
			memset(a,0,sizeof(a));
			memset(t,0,sizeof(t));
			memset(path,0,sizeof(path));
			memset(ans,0,sizeof(ans));
			flag=0;
			scanf("%d",&n);
			for(int i=1;i<=2*n;i++){
				scanf("%d",&a[i]);
			} 
			t[a[1]]=1;
			path[1]='L';
			dfs(1,1,2*n+1);
			t[a[1]]=0;
			if(flag==0){
				t[a[2*n]]=1;
				path[1]='R';
				dfs(1,0,2*n);
				t[a[2*n]]=0;
			}
			if(flag==0){
				printf("-1\n");
			}else{
				for(int i=1;i<=2*n;i++){
					printf("%c",ans[i]);
				}
				printf("\n");
			}
		}
	}else{
		while(T--){
			cout<<-1<<endl;
		}
	}
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}

