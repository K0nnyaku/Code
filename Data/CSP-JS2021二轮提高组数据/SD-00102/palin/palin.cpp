#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=5e5+10;
int T,n,a[maxn],ans[maxn],L,R,q[maxn],l,r,cnt=0,flag;
void dfs(int num){
	if(num>2*n){
		bool b=1;r--;
		for(int i=1;i<=cnt;++i) if(q[i]!=q[cnt-i+1]) b=0;	
		if(b) flag=1;
		return;	
	}
	if(flag) return;
	q[++cnt]=a[L++];
	ans[num]=0;
	dfs(num+1);
	if(flag) return;
	--cnt,--L;	
	q[++cnt]=a[R--];
	ans[num]=1;
	dfs(num+1);
	if(flag) return;
	--cnt,++R;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		flag=0;
		cin>>n;
		for(int i=1;i<=2*n;++i) scanf("%d",&a[i]);
		if(n>10){
			bool bb=1;
			for(int i=1;i<=2*n;++i) if(a[i]!=a[2*n-i+1]) bb=0;
			if(bb){
				for(int i=1;i<=2*n;++i) cout<<'L';
				cout<<'\n';
				continue;
			}else{
				cout<<"-1\n";
				continue;
			}
		}
		L=1,R=2*n;
		l=1000,r=1000;
		dfs(1);
		if(flag){
			for(int i=1;i<=2*n;++i){
				if(ans[i]==0) cout<<'L';
				else cout<<'R';
			}
		}else{
			cout<<"-1";
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
