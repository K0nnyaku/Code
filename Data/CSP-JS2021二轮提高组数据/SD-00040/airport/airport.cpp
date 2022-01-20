#include<bits/stdc++.h>
using namespace std;
struct gnf{
	int a,b;
}fj1[100005];
struct gwf{
	int a,b;
}fj2[100005];
bool cmp1(gnf x,gnf y){
	return x.a<y.a;
}
bool cmp2(gwf x,gwf y){
	return x.a<y.a;
}
int maxn(int a,int b){
	if(a>=b) return a;
	else return b;
}
int n,m,o;
int sum1,sum2;
int ans,zans;
bool ok1[100005],ok2[100005];
bool nj[100005],wj[100005];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m,&o);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&fj1[i].a,&fj1[i].b);
	for(int i=1;i<=o;i++)
		scanf("%d%d",&fj2[i].a,&fj2[i].b);
	sort(fj1+1,fj1+m+1,cmp1);
//	cout<<"\n";
	//for(int i=1;i<=m;i++)	cout<<fj1[i].a<<" "<<fj1[i].b<<endl;
//	cout<<"\n";
	sort(fj2+1,fj2+o+1,cmp2);
	for(int i=0;i<=n;i++){
		sum1=i,sum2=n-i;ans=0;
		memset(nj,0,sizeof(nj));memset(ok1,0,sizeof(ok1));
		memset(wj,0,sizeof(wj));memset(ok2,0,sizeof(ok2));
		for(int j=1;j<=m;j++){
			if(sum1>0){
				//cout<<j<<" ";
				sum1--;
				ans++;
				ok1[j]=1;
			}
			else{
				//cout<<j<<" ";
				int minn=1e9,mini=0;
				for(int k=1;k<j;k++)
					if(fj1[k].b<fj1[j].a&&fj1[k].b<minn&&nj[k]==0&&ok1[k]==1){
						//cout<<k<<" ";
						minn=fj1[k].b,mini=k;
					}
				if(mini>0){
					ans++;
					ok1[j]=1;
					nj[mini]=1;
				}
			}
		}
		//printf("%d   ",ans);
		for(int j=1;j<=o;j++){
			if(sum2>0){
				//cout<<j<<" ";
				sum2--;
				ans++;
				ok2[j]=1;
			}
			else{
				//cout<<j<<" ";
				int minn=1e9,mini=0;
				for(int k=1;k<j;k++)
					if(fj2[k].b<fj2[j].a&&fj2[k].b<minn&&wj[k]==0&&ok2[k]==1){
						//cout<<k<<" ";
						minn=fj2[k].b,mini=k;
					}
				if(mini>0){
					ans++;
					ok2[j]=1;
					wj[mini]=1;
				}
			}
		}
		//printf("%d\n",ans);
		zans=maxn(zans,ans);
	}
	printf("%d\n",zans);
	return 0;
}
