#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,flag;
int a[2001],b[2001];
char op[2001];
inline int qread(){
	char c=getchar(),o=' ';int x=0;
	while(c>'9'||c<'0')o=c,c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+c-48,c=getchar();
	if(o=='-')return -x;return x;
}
void dfs(int p,int l,int r){
//	if(p==2*n+1){
//		cout<<"-------\n";
//		cout<<p<<' '<<l<<' '<<r<<'\n';
//		for(int i=1;i<=n*2;++i)cout<<op[i];
//		cout<<'\n';
//		for(int i=1;i<=n*2;++i)cout<<b[i];
//		cout<<"\n";
//	}
	if(p>n){
		for(int i=n+1;i<=p-1;++i){
			if(b[i]!=b[n*2-i+1])return;
		}
	}
	if(p==2*n+1){
		flag=1;
		for(int i=1;i<=n*2;++i)cout<<op[i];
		cout<<'\n';
	}
	if(flag)return;
	b[p+1]=a[l];op[p+1]='L';
	dfs(p+1,l+1,r);
	if(flag)return;
	b[p+1]=a[r];op[p+1]='R';
	dfs(p+1,l,r-1);
}
signed main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=qread();
	while(t--){
		n=qread();flag=0;
		for(int i=1;i<=n*2;++i)a[i]=qread();
		if(n>20){
			int flag1=1;
			for(int i=n+1;i<=n*2-i+1;++i){
				if(a[i]!=a[n*2-i+1]){
					flag1=0;break;
				}
			}
			if(flag1){
				for(int i=1;i<=n;++i){
					cout<<"L";
				}
				cout<<'\n';
				continue;
			}
			else{
				cout<<"-1\n";
				continue;
			}
		}
		dfs(0,1,n*2);
		if(!flag)cout<<"-1\n";
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
