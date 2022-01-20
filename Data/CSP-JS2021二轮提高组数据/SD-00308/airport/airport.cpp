#include<bits/stdc++.h>
using namespace std;
struct p{
	int a;
	int b;
}pla[10005];
int n,m1,m2,n1,num=0,sum=0;
int tjp[10005];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1+m2;i++){
		scanf("%d%d",&pla[i].a,&pla[i].b);
	}
	for(int i=0;i<=n;i++){
		n1=n-i;
		memset(tjp,0,sizeof(tjp));
		if(i!=0&&m1!=0)
			for(int j=1;j<=m1;j++){
				for(int k=1;k<=i;k++)
				{
					if(tjp[k]>pla[j].a)continue;
					tjp[k]=pla[j].b;
					num++;
					break;
				}
			}
		memset(tjp,0,sizeof(tjp));
		if(n1!=0&&m2!=0)
			for(int j=m1+1;j<=m1+m2;j++){
				for(int k=1;k<=n1;k++)
				{
					if(tjp[k]>pla[j].a)continue;
					tjp[k]=pla[j].b;
					num++;
					break;
				}
			}
		if(num>sum)sum=num;
		num=0;
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
