#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N=1e6+5;
int T,n,a[N],b[N],flag;
char ans[N];
void dfs(int l,int r){
	if(flag) return;
	if(r-l+1==n){
		for(int i=n;i>=1;--i){
			if(b[i]==a[l]) ++l,ans[2*n-i+1]='L';
			else if(b[i]==a[r]) --r,ans[2*n-i+1]='R';
			else return;
		}
		flag=1;
		return;
	}
	ans[2*n-(r-l)]='L';
	b[2*n-(r-l)]=a[l];
	dfs(l+1,r);
	if(flag) return;
	ans[2*n-(r-l)]='R';
	b[2*n-(r-l)]=a[r];
	dfs(l,r-1);
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;++i) scanf("%d",&a[i]);
		if(n>=30){
			int x=0,op=1,y=0;
			for(int i=1;i<=2*n;++i)
				if(a[i]==a[i-1]){
					x=i-1;
					break;
				}
			for(int i=1;i<=x;++i)
				if(a[i]!=a[2*x+1-i])
					op=0;
			if(!op){
				printf("-1\n");
				continue;
			} 
			if(x==n){
				for(int i=1;i<=2*n;++i) putchar('L');
				putchar('\n');
				continue;
			}
			for(int i=2*x+1;i<=2*n;++i)
				if(a[i]==a[i-1]) y=i-1;
			op=1;
			for(int i=2*x+1;i<=2*y-2*x;++i)
				if(a[i]!=a[2*y+1-i])
					op=0;
			if((!op)||y-x!=n){
				printf("-1\n");
				continue;
			}
			for(int i=1;i<=x;++i) putchar('L');
			for(int i=1;i<=y-2*x;++i) putchar('R');
			for(int i=1;i<=y-2*x;++i) putchar('R');
			for(int i=1;i<=x;++i) putchar('L');
			putchar('\n');
		}
		else{
			flag=0;
			dfs(1,2*n);
			if(!flag) printf("-1\n");
			else{
				for(int i=1;i<=2*n;++i) putchar(ans[i]);
				putchar('\n');
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
