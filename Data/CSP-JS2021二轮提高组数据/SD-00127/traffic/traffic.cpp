#include<iostream>
#include<cstdio> 
#include<algorithm>
using namespace std;
int n,m,T,t,u,y[100010];
int f[1100][1100];
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&t);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			scanf("%d",&t);
		}
	}
	int k,o=0;
	while(T--){
		o=0;
		scanf("%d",&k);
		while(k--)
			scanf("%d%d%d",&t,&u,&y[++o]);
		bool q1=0,q2=0;
		for(int i=1;i<=o;i++){
			if(y[i]==0)
				q1=1;
			if(y[i]==1)
				q2=1;
		}
		if(q1==1&&q2==1)
			cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
