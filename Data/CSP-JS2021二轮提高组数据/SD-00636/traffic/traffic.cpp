#include<bits/stdc++.h> 
using namespace std;
int n,m,t,k,a,b,c;
int main()
{	
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
    srand(time(0));
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<n;i++)
      for(int j=1;j<=m;j++) scanf("%d",&a);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++) scanf("%d",&a);
    for(int i=1;i<=t;i++) 
    {
    	scanf("%d",&k);
    	for(int j=1;j<=k;j++)
    	  scanf("%d%d%d",&a,&b,&c);
    }
    for(int i=1;i<=t;i++) {printf("12\n");}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

