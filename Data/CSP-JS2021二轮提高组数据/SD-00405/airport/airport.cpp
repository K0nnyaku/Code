#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,m1,m2,ans1,ans2,ans,dd,s;
struct sh{
	int ks,js;
}a[100005],b[100005];int c[100005],d[100005];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++) {cin>>a[i].ks>>a[i].js;c[i]=a[i].ks;}
	for(int i=1;i<=m2;i++) {cin>>b[i].ks>>b[i].js;d[i]=b[i].ks;}
	for(int i=0;i<=n;i++){
		s=i;
		while(s!=0){
			dd=0;
			for(int j=1;j<=m1;j++){
				if(a[j].ks>dd){
					ans1++;
					dd=a[j].js;
					
					a[j].ks=0;
				}
			}
			s--;	
		}
		for(int p=1;p<=m1;p++) a[p].ks=c[p];
		s=i;
		dd=0;
		while(s!=n){
			dd=0;
			for(int k=1;k<=m2;k++){
				if(b[k].ks>dd){
					ans2++;
					dd=b[k].js;
					
					b[k].ks=0;
				}
			}
			s++;
		}
		for(int q=1;q<=m2;q++) b[q].ks=d[q];
		ans=max(ans1+ans2,ans);
		ans1=0;ans2=0;
		}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
