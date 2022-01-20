#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
long long n,m1,m2,zl[100010],c,f,ans,mx,x=0,k,hehe,ansk;
bool flag=0;
struct aip{
	long long a,b;
};
struct aip p1[100010];
struct aip p2[100010];
bool px(struct aip x,struct aip y){
	return x.a<y.a;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m1,&m2);
	for(long long i=1;i<=m1;i++){
		scanf("%lld %lld",&p1[i].a,&p1[i].b);
	}
	for(long long i=1;i<=m2;i++){
		scanf("%lld %lld",&p2[i].a,&p2[i].b);
	}
	sort(p1+1,p1+1+m1,px);
	sort(p2+1,p2+1+m2,px);
	for(long long t=0;t<=n;t++){
//		cout<<"hehe"<<endl;
		c=t,f=n-t,ans=0,x=0,flag=0,k=x,ansk=0;
		for(long long i=1;i<=m1;i++){
			flag=0;
			k=x,ansk=0;
			while(k>0){
				if(p1[zl[k]].b<=p1[i].a){
					hehe=k;
					zl[k]=0;
					ansk++;
					flag=1;
				}
				k--;
			}
			if(flag==1){
				zl[hehe]=i;
				x-=(ansk-1);
				ans++;
			}else if(zl[x+1]==0&&x+1<=c){
				x++;
				zl[x]=i;
				ans++;
			}
		}
//		cout<<ans<<" ";
		for(long long i=1;i<=ans;i++){
			zl[i]=0;
		}
		x=0,ansk=0;
		for(long long i=1;i<=m2;i++){
			flag=0;
			k=x,ansk=0;
			while(k>0){
				if(p2[zl[k]].b<=p2[i].a){
					hehe=k;
					zl[k]=0;
					ansk++;
					flag=1;
				}
				k--;
			}
			if(flag==1){
//				cout<<i<<endl;
				zl[hehe]=i;
				x-=(ansk-1);
//				cout<<x<<endl;
				ans++;
			}else if(zl[x+1]==0&&x+1<=f){
				x++;
				zl[x]=i;
				ans++;
//				cout<<i<<" ";
			}
//			cout<<x<<endl;
		}
//		cout<<ans<<endl;
		for(long long i=1;i<=ans;i++){
			zl[i]=0;
		}
		mx=max(mx,ans);
//		cout<<mx<<endl;
	}
	printf("%lld\n",mx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
