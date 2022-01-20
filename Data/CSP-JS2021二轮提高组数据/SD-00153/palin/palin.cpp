#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#define max(a,b) (a > b ? a : b) 
#define min(a,b) (a < b ? a : b) 

using namespace std;

const int N = 1e6 + 10;
const int n1 = (N >> 1) + 10;
int a[N],L[n1],R[n1],d[n1];
bool b[N],flag;
char c[N];
int n;
void csh(){
	flag = false;
	memset(a,0,sizeof(a));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	memset(L,0,sizeof(L));
	memset(R,0,sizeof(R));
	memset(b,false,sizeof(b));
}
void init(){
	scanf("%d",&n);
	n = n << 1;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d",&a[i]);
		(L[a[i]] != 0) ? (R[a[i]] = i) :(L[a[i]] = i);
	}
} 

void dfs(int l,int r,int tot){
	if(flag || l > r)
		return ;
	if((tot << 1) == n){
		int i = tot;
		while(l <= r){
			flag = false;
			while(l <= r && d[i] == a[l]){
				++l,--i,flag = true;
				c[++tot] = 'L';
			}
			while(l < r && d[i] == a[r]){
				--r,--i,flag = true;
				c[++tot] = 'R';
			}
			if(!flag)
				return ;
		}
		for(int i = 1 ; i <= tot ; ++i)
			printf("%c",c[i]);
		printf("\n");
		flag = true;
		return ;
	}
	int nl = R[a[l]];
	int nr = L[a[r]];
	if(l == 1 && b[2]){
		--nl;
		++nl;
	}
	else if((b[max(nl - 1,1)] || b[min(n,nl + 1)] || (tot == 0))){
		b[nl] = b[l] = true;
		c[++tot] = 'L';
		d[tot] = a[l];
		dfs(l + 1,r,tot);
		if(flag)
			return ;
		b[nl] = b[l] = false;
		c[tot] = 0,d[tot] = 0;
		--tot;
	}
	if(r == n && b[n - 1]){
		--nl;
		++nl;
	}
	else if((b[max(nr - 1,1)] || b[min(n,nr + 1)] || (tot == 0))){
		b[nr] = b[r] = true;
		c[++tot] = 'R';
		d[tot] = a[r];
		dfs(l,r - 1,tot);
		if(flag)
			return ;
		b[nr] = b[r] = false;
		c[tot] = 0,d[tot] = 0;
		--tot;
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T --> 0){
		csh();
		init();
		dfs(1,n,0);
		if(!flag)
			printf("-1\n");
	}
	return 0;
}
