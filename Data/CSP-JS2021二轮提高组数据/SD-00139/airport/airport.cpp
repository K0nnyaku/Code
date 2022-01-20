#include<iostream>
#include<cstdio>
using namespace std;
int n,m1,m2,a1[100001],b1[100001],maxx=0;
struct airport{
	int r,sum;
}a[100001],b[100001];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int top=1,l=0,r=0;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1,k=0;i<=m1;i++,k=0){
		scanf("%d%d",&l,&r);
		for(int j=1;j<=top;j++)
			if(a[j].r<=l){
				a[j].sum++,a[j].r=r;
				k=1;break;
			}
		if(k==0&&top<n)
			a[++top].r=r,a[top].sum++;
	}top=1;
	for(int i=1,k=0;i<=m2;i++,k=0){
		scanf("%d%d",&l,&r);
		for(int j=1;j<=top;j++)
			if(b[j].r<=l){
				b[j].sum++,b[j].r=r;
				k=1;break;
			}
		if(k==0&&top<n)
			b[++top].r=r,b[top].sum++;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			a1[i]+=a[j].sum,b1[i]+=b[j].sum;
	for(int i=0;i<=n;i++){
		int sum=a1[i]+b1[n-i];
		if(sum>=maxx)
			maxx=sum;
	}printf("%d",maxx);
	return 0;
}
