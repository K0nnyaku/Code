#include<bits/stdc++.h>
using namespace std;
const 
int N=5e5+10;
int n,m,k;
int l[N];
int ans[N];
int shuchu[N];
int flag=0;
int aa=0;
int sum=0;
void DFS(int head,int tail,int x){
	if(x==n+1){
		sum++;
		int f=1;
//		for(int i=1;i<=n;i++){
//			cout<<ans[i]<<' ';
//		}
		for(int i=1;i<=m;i++){
			if(ans[i]!=ans[n-i+1]){
				f=0;
				break;
			}
		}
		if(f==1&&aa==0){
			flag=1;
			aa++;
			for(int i=1;i<=n;i++){
				if(shuchu[i]==1)cout<<'L';
				else cout<<'R';
			}
		}
		if(sum==n*n*n*n)flag=1;
		return;
	}else if(flag==0){
	for(int i=1;i<=2;i++){
		if(i==1){
			ans[x]=l[head];
			shuchu[x]=1;
			x++;
			head++;
			DFS(head,tail,x);
			head--;
			x--;
		}else{
			ans[x]=l[tail];
			shuchu[x]=2;
			x++;
			tail--;
			DFS(head,tail,x);
			x--;
			tail++;
		}
	}
	}
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>k;
	for(int j=1;j<=k;j++){
		memset(l,0,sizeof(l));
		memset(ans,0,sizeof(l));
		memset(shuchu,0,sizeof(l));
		sum=0;
		flag=0;
		aa=0;
		cin>>m;
		n=m*2;
		for(int i=1;i<=n;i++){
			cin>>l[i];
		}
		DFS(1,n,1);
		int aabb=-1;
		if(flag==0||sum==n*n*n*n)cout<<aabb;
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
} 
