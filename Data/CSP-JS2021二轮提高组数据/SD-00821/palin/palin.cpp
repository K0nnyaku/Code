#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[500010],b[500010],sum[500010],T,czs[500010],ans[500010];
bool flt=false;
int cnt;
void dfs(int l,int r,int id) {
	if(id>2*n) {
//		cout<<++cnt<<endl;
		bool flag=true;
		for(int i=1; i<=n; ++i) {
			if(b[i]!=b[2*n+1-i]) {
				flag=false;
				break;
			}
		}
		if(flag) {
			flt=true;
//			bool ftp=false;
//			for(int i=1;i<=2*n;++i){
//				if(b[i]<sum[i]){
//					ftp=true;
//					break;
//				}
//				else if(b[i]>sum[i]){
//					break;
//				} 
//			}
//			if(ftp){
//				for(int i=1;i<=2*n;++i){
//					sum[i]=b[i];
//					ans[i]=czs[i];
//				}
//			}
		}
		return;
	}
	b[id]=a[l];
	czs[id]=0;
	if((id<=n)||(id>n&&b[id]==b[2*n-id+1]))
		dfs(l+1,r,id+1);
	if(flt) return;
	czs[id]=1;
	b[id]=a[r];
	if((id<=n)||(id>n&&b[id]==b[2*n-id+1]))
		dfs(l,r-1,id+1);
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		flt=false;
		memset(sum,0x3f3f3f3f,sizeof(sum));
		scanf("%d",&n);
		for(int i=1; i<=2*n; ++i) {
			scanf("%d",&a[i]);
		}
		if(n>=50){
			printf("-1\n");
			continue;
		}
		dfs(1,2*n,1);
		if(!flt){
			printf("-1\n");
		}
		else{
			for(int i=1;i<=2*n;++i){
				if(!czs[i]){
					printf("L");
				}
				else{
					printf("R");
				}
			}
			printf("\n");
		}
	}

	return 0;
}
