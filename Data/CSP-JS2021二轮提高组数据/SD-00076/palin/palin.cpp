#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define ll long long

using namespace std;

ll t,n,a[1000],b[1000];
ll bstans[1000];
char ans[1000],anss[1000];

inline ll Read(){
	ll s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return s*w;
}
inline void dfs(ll l,ll r,ll p){//cout<<l<<" "<<r<<endl;
	//cout<<l<<" "<<r<<endl;
/*	for(int i=1;i<=2*n;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;*/
/*	if(b[1]==4&&b[2]==5&&b[3]==3&&b[4]==1&&b[5]==2&&b[6]==2&&b[7]==1&&b[8]==3&&b[9]==5&&b[10]==4) {
		for(int i=1;i<=2*n;i++){
			cout<<b[i]<<" ";
		}
		cout<<endl;
	}*/
	if(l>r){
		for(int i=1;i<=n;i++){
			if(b[i]!=b[2*n-i+1]){
				return;
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]<bstans[i]){
				for(int j=1;j<=n;j++){
					bstans[j]=bstans[2*n-j+1]=b[j];
				}
				for(int j=1;j<=2*n;j++){
					anss[j]=ans[j];
				}
				return;
			}else if(b[i]>bstans[i]){
				return;
			}
		}
		return;
	}
	b[p]=a[l];
	ans[p]='L';
	dfs(l+1,r,p+1);
	b[p]=a[r];
	ans[p]='R';
	dfs(l,r-1,p+1);
	ans[p]=0;
	b[p]=0;
	
} 
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=Read();
	while(t--){
		n=Read();
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(ans,0,sizeof(ans));
		memset(bstans,0x3f,sizeof(bstans));
		for(int i=1;i<=2*n;i++)a[i]=Read();
		dfs(1,2*n,1);
		if(bstans[1]==0x3f3f3f3f3f3f3f3f){
			printf("-1\n");
		}else{
			for(int i=1;i<=2*n;i++){
				cout<<anss[i];
			}
			cout<<endl;
		}
	}

	fclose(stdin);fclose(stdout);
	return 0;
}

