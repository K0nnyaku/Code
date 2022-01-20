#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m1,m2;
int a1[100001],b1[100001],a2[100001],b2[100001],d1[100001],d2[100001];
int k1[100001],k2[100001],s[100001];

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a1[i],&b1[i]);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&a2[i],&b2[i]);
	}
	for(int n1=0;n1<=n;n1++){
		k1[n1]=0; int n2=n-n1;k2[n2]=0;
			for(int i=1;i<=n1;i++){
				d1[i]=b1[i]; k1[n1]++;
			} 
			for(int j=n1;j<=m1;j++){
				for(int i=1;i<=n1;i++){
					if(a1[j]>=d1[i]) {k1[n1]++; d1[i]=b1[j];break;}
				}
			}
		for(int i=1;i<=n2;i++){
				d2[i]=b2[i]; k2[n2]++;
			} 
			for(int j=n2;j<=m2;j++){
				for(int i=1;i<=n2;i++){
					if(d2[i]<=a2[j]) {k2[n2]++; d2[i]=b2[j];break;}
				}
			}	
		}
	for(int i=1;i<=n;i++){
		s[i]=k1[i]+k2[i];
		if(s[i]<s[i-1]) s[i]=s[i-1];
	}
	printf("%d",s[n]-1);
	return 0;
} 
