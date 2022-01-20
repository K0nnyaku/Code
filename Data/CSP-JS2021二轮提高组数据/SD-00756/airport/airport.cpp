#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m1,m2;
struct ss{
	int r,l;
}a[300010];
int kr[1000100],kl[1000100];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	memset(kr,0,sizeof(kr));
	memset(kl,0,sizeof(kl));
	scanf("%d%d%d",&n,&m1,&m2);
	a[0].r=0;
	a[0].l=0;
	a[m1+1].l=0;
	a[m1+1].r=0;
	for(int i=1;i<=m1;i++) {
		scanf("%d%d",&a[i].r,&a[i].l);
	}
	for(int i=m1+2;i<=m2+m1+1;i++) {
		scanf("%d%d",&a[i].r,&a[i].l);
	}
	for(int i=1;i<=m1;i++) {
		for(int j=i;j>0;j--) {
			if(a[j].r<a[j-1].r) swap(a[j],a[j-1]);
		}
	}
	for(int i=m1+2;i<=m1+m2+1;i++) {
		for(int j=i;j>m1+1;j--) {
			if(a[j].r<a[j-1].r) swap(a[j],a[j-1]);
		}
	}
	int nei=0,wai=n,ans=0;
	while(nei<=n)
	{
		int ansa=0,ansb=0;
		if(nei!=0) {
			for(int i=1;i<=m1;i++) {
				for(int j=1;j<=nei;j++) {
					if(kr[j]==0&&kl[j]==0) {
						kr[j]=a[i].r;
						kl[j]=a[i].l;
						ansa++;
						break;
					}
					if(a[i].r>kl[j]) {
						kr[j]=a[i].r;
						kl[j]=a[i].l;
						ansa++;
						break;
					}
				}
			}
		}
		memset(kr,0,sizeof(kr));
		memset(kl,0,sizeof(kl));
		if(wai!=0) {
			for(int i=m1+2;i<=m1+m2+1;i++) {
				for(int j=1;j<=wai;j++) {
					if(kr[j]==0&&kl[j]==0) {
						kr[j]=a[i].r;
						kl[j]=a[i].l;
						ansb++;
						break;
					}
					if(a[i].r>kl[j]) {
						kr[j]=a[i].r;
						kl[j]=a[i].l;
						ansb++;
						break;
					}
				}
			}
		}
		memset(kr,0,sizeof(kr));
		memset(kl,0,sizeof(kl));
		if(ans<ansa+ansb) ans=ansa+ansb;
		nei++;
		wai--;
	}
	cout<<ans<<endl;
	return 0;
}
