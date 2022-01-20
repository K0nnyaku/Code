#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int t,head,tail,a[500005],n,zs[500005],cnt;
bool b[500005],kk;
void cl(){
	kk=1;
	int l=1,r=2*n,s=0;
	while(l<=r){
		s++;
		if(zs[l]==a[s]){
			putchar('L');l++;
			continue;
		}
		if(zs[r]==a[s]){
			putchar('R');r--;
			continue;
		}
	}
}
void dfs(int yi,int x,int y){
	if(kk) return;
		if(yi==n*2){
			bool f=0;
			for(int i=1;i<=n;i++){
				if(a[i]!=a[2*n+1-i]){
				f=1;break;
				} 
			}
			if(!f){
				cl();
			}
			return;
		}
		if(!(yi<n&&b[zs[x]])){
		if(!(yi>=n&&(zs[x]!=a[n-(yi+1-n)+1]))){
		a[yi+1]=zs[x];b[zs[x]]=1;
		dfs(yi+1,x+1,y);
		b[zs[x]]=0;
		}
		}
		if(!(yi<n&&b[zs[y]])){
		if(!(yi>=n&&(zs[y]!=a[n-(yi+1-n)+1]))){
		a[yi+1]=zs[y];b[zs[y]]=1;
		dfs(yi+1,x,y-1);
		b[zs[y]]=0;
			}
		
		}
		
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		cnt=0;kk=0;
		scanf("%d",&n);
		if(n>=1000&&n<=500000){
			puts("-1");
			return 0;
		}
		for(int i=1;i<=n*2;i++) scanf("%d",&zs[i]);
		dfs(0,1,n*2);
		if(!kk) puts("-1");
		else cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
