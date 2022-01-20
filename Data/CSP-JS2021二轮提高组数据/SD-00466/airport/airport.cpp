#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
unsigned long long int port[100001];
int n,m1,m2,ans,tot;
struct pla{
	unsigned long long int a;
	unsigned long long int b;
}pla1[100001],pla2[100001];

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)cin>>pla1[i].a>>pla1[i].b;
	for(int i=1;i<=m2;i++)cin>>pla2[i].a>>pla2[i].b;
	//paixu

	for(int i=1;i<=m1;i++)
	for(int j=i;j<=m1-1;j++)
		if(pla1[j].a>pla1[j+1].a)
			swap(pla1[j],pla1[j+1]);
						
	for(int i=1;i<=m2;i++)
	for(int j=i;j<=m2-1;j++)
		if(pla2[j].a>pla2[j+1].a)
			swap(pla2[j],pla2[j+1]);
	//hexin
	
	for(int i=0;i<=n;i++){
		tot=0;
		for(int i=0;i<=n;i++)port[i]=0;
		
		for(int j=1;j<=m1;j++)
			for(int k=1;k<=i;k++){
					if(pla1[j].a>port[k]){	
						port[k]=pla1[j].b;tot++;
						break;
					}
			}
		
		for(int j=1;j<=m2;j++)
			for(int k=i+1;k<=n;k++){

					if(pla2[j].a>port[k]){
					port[k]=pla2[j].b;tot++;
					break;
					}
			}
		ans=max(ans,tot);
	}
	cout<<ans;
	return 0;
}
