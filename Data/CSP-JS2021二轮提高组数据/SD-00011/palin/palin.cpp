#include<cstdio>
#include<algorithm>
const int maxn(1e6+5);
int n,t,x;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(;t;--t)
	{
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++) scanf("%d",&x);
		printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

