#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct pl{
	int d,q;
}a1[100005],a2[100005];
bool cmp(pl e,pl f){
	return e.d<f.d;
}
int n,m1,m2,a,b,h1=1,h2=1,ans=0;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%d%d",&a1[i].d,&a1[i].q);
	for(int i=1;i<=m2;i++) scanf("%d%d",&a2[i].d,&a2[i].q);
	sort(a1+1,a1+m1+1,cmp);
	sort(a2+1,a2+m2+1,cmp);
	for(int i=1;i<=m1;i++){
		a=a1[i].d;b=a1[i].q;a1[i].d=0;a1[i].q=0;
		for(int j=1;j<=i;j++){
			if(a1[j].q<a){
				a1[j].q=b;a1[j].d++;break;
			}
		}
	}
	for(int i=1;i<=m2;i++){
		a=a2[i].d;b=a2[i].q;a2[i].d=0;a2[i].q=0;
		for(int j=1;j<=i;j++){
			if(a2[j].q<a){
				a2[j].q=b;a2[j].d++;break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a1[h1].d<a2[h2].d){
			ans+=a2[h2].d;h2++;
		}else{
			ans+=a1[h1].d;h1++;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
