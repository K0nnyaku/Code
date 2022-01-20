#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

const long long N=5e5+1;
long long t,n,a[N+10],f[N+10][2],ok;
stack <long long> s1,s2;

void init(){
	ok=0;
	while(!s1.empty()) s1.pop();
	while(!s2.empty()) s2.pop();
}
void dfs(long long l,long long r,long long x,long long y){
	if(ok) return;
	if(x<l || y>r || l>r) return;
	if(l==x && r==y && a[l]==a[r]){
		ok=1;
		return;
	}
	if(a[l]==a[x] && l<x && x>1){
		dfs(l+1,r,x-1,y);
		if(ok){
			s1.push(0);
			s2.push(0);
			return;
		}
	}
	if(a[l]==a[y] && y<r && y<2*n){
		dfs(l+1,r,x,y+1);
		if(ok){
			s1.push(0);
			s2.push(1);
			return;
		}
	}
	if(a[r]==a[x] && l<x && x>1){
		dfs(l,r-1,x-1,y);
		if(ok){
			s1.push(1);
			s2.push(0);
			return;
		}
	}
	if(a[r]==a[y] && y<r && y<2*n){
		dfs(l,r-1,x,y+1);
		if(ok){
			s1.push(1);
			s2.push(1);
			return;
		}
	}
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	long long i,j,u,v;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		init();
		for(i=1;i<=2*n;i++){
			scanf("%lld",&a[i]);
			if(!f[a[i]][0]) f[a[i]][0]=i;
			else f[a[i]][1]=i;
		}
		dfs(2,2*n,f[a[1]][1]-1,f[a[1]][1]+1);
		if(ok){
			putchar('L');
			while(!s1.empty()){
				u=s1.top();s1.pop();
				if(u==0) putchar('L');
				else putchar('R');
			}
			putchar('L'),putchar('R');
			while(!s2.empty()){
				u=s2.top();s2.pop();
				if(u==0) putchar('L');
				else putchar('R');
			}
			putchar('L');
			putchar('\n');
			continue;
		}
		dfs(1,2*n-1,f[a[2*n]][0]-1,f[a[2*n]][0]+1);
		if(ok){
			putchar('R');
			while(!s1.empty()){
				u=s1.top();s1.pop();
				if(u==0) putchar('L');
				else putchar('R');
			}
			putchar('L'),putchar('R');
			while(!s2.empty()){
				u=s2.top();s2.pop();
				if(u==0) putchar('L');
				else putchar('R');
			}
			putchar('L');
			putchar('\n');
			continue;
		}
		printf("-1\n");
	}
	return 0;
}
