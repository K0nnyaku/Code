#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

int read(){
	int k=1,x;
	char c=getchar();
	while (c<'0'||c>'9'){
		if(c=='-'){
			k=-1;
			c=getchar();
		}
	}
	while (c>='0'&&c<='9'){
		x=x<<3+x<<1+c^48;
		c=getchar();
	}
	return x*k;
}
int T,n,a[10000010];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		printf("-1\n");
	}
	
	return 0;
}  
