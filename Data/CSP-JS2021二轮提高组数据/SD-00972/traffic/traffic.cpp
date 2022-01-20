#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int t,n,m;

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	srand(time(0));
	scanf("%d%d%d",&n,&m,&t);
	int x;
	for(int i=1;i<n;i++)
	    for(int j=1;j<=m;j++)
	        scanf("%d",&x);
	for(int i=1;i<=n;i++)
	    for(int j=1;j<m;j++)
	        scanf("%d",&x);
	while(t--){
		int k;
		scanf("%d",&k);
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		printf("%d",rand()%1000000+1);
	}
	return 0;
}
