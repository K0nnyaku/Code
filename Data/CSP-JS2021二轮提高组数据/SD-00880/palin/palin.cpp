#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+7;

int t,n,m,bj,ii;
int a[maxn],b[maxn],cz[maxn],ans[maxn];

void pd() {
	int cnt=0,l=1,r=m,sum=0;
	for(int i=1;i<=m;i++) {
		if(cz[i]==1) {
			b[++cnt]=a[l];l++;
		}
		else{
			b[++cnt]=a[r];r--;
		}
	}
	int bjbj=0;
	for(int i=1,j=m;i<=n&&j>=n+1;i++,j--) {
		if(b[i]!=b[j]){
			bjbj=1;
			break;
		}
	}
	if(bjbj==0) {
		bj=1;
		ii++;
		if(ii==1) {
			for(int i=1;i<=m;i++){
				ans[i]=cz[i];
			}
			return;
		}
		int bzz=0;
		long long x=0,y=0;
		for(int i=1;i<=m;i++){
			x=x*10+ans[i];
			y=y*10+cz[i];
		}
		if(x>y) {
			for(int i=1;i<=m;i++) {
				ans[i]=cz[i];
			}
		}
	}
}

void dfs(int bz,int num) {
	if(num==m+1) {
		pd();
		return;
	}
	if(bz==1){
		cz[num]=1;
		dfs(0,num+1);
		dfs(1,num+1);
	}
	else {
		cz[num]=2;
		dfs(1,num+1);
		dfs(2,num+1);
	}
}

int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		m=n*2;
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
		}
		bj=0;ii=0;
		dfs(1,1);
		dfs(2,1);
		if(bj==0){
			cout<<"-1"<<endl;
		}
		else {
			for(int i=1;i<=m;i++) {
				if(ans[i]==1) {
					cout<<"L";
				}else cout<<"R";
			}
			cout<<endl;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
/*

2 
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

*/
