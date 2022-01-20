#include<cstdio>
#include<iostream>
using namespace std;

int n,a[55],b[55],c[55];bool flag;

void dfs(int x) {
	if(x == 2*n + 1){
		int l = 1,r = 2*n;
		for(int i = 1;i <= 2*n;i += 1){
			if(!c[i])b[i] = a[l++];
			else b[i] = a[r--];
		}
		bool opt = 1;
		for(int i = 1;i <= n;i += 1)
			if(b[i] != b[2*n-i+1])opt = 0;
		if(opt){
			flag = 1;
			for(int i = 1;i <= 2*n;i += 1)
				if(!c[i])printf("L");
				else printf("R");
			printf("\n");
		}
		return;
	}
	c[x] = 0;dfs(x+1);if(flag)return;
	c[x] = 1;dfs(x+1);if(flag)return;
}

int main()
{
	freopen("palin.in","r",stdin);freopen("palin.out","w",stdout); 
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);flag = 0;
		for(int i = 1;i <= 2*n;i += 1)scanf("%d",&a[i]);
		dfs(1);if(!flag)printf("-1\n");
	}
	return 0;
}

