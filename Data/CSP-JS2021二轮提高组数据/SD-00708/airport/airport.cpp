#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MaxN = 100005;
int n,m1,m2,ans=-1,in[MaxN];
struct Air{
	int s,e;
} q1[MaxN],q2[MaxN];
bool cmp(Air v1, Air v2) {
	return v1.s<v2.s;
}
int dp1[MaxN],dp2[MaxN];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) {
		int s,e;
		scanf("%d%d",&s,&e);
		q1[i].s = s;
		q1[i].e = e;
	}
	sort(q1+1,q1+m1+1,cmp);
	for(int j=0;j<=n;j++) {
		int len=0;
		for(int i=0;i<=m1;i++) {
			if(i*j==0) {
				dp1[j]=0;
				continue;
			}
			if(len<j) {
				in[len++]=q1[i].e;
				dp1[j]++;
			} else {
				bool flag=false;
				for(int k=0;k<len;k++){
					if(in[k] == 0) {
						continue;
					}
					if(in[k]<q1[i].s) {
						in[k]=q1[i].e;
						flag=true;
						break;
					}
				}
				if(flag) {
					dp1[j]++;
				}
			}
		}
	}
	for(int i=1;i<=m2;i++) {
		int s,e;
		scanf("%d%d",&s,&e);
		q2[i].s = s;
		q2[i].e = e;
	}
	sort(q2+1,q2+m2+1,cmp);
	for(int j=0;j<=n;j++) {
		int len=0;
		for(int i=0;i<=m2;i++) {
			if(i*j==0) {
				dp2[j]=0;
				continue;
			}
			if(len<j) {
				in[len++]=q2[i].e;
				dp2[j]++;
			} else {
				bool flag=false;
				for(int k=0;k<len;k++){
					if(in[k] == 0) {
						continue;
					}
					if(in[k]<q2[i].s) {
						in[k]=q2[i].e;
						flag=true;
						break;
					}
				}
				if(flag) {
					dp2[j]++;
				}
			}
		}
	}
	for(int i=0;i<=n;i++) {
		ans=max(ans,dp1[i]+dp2[n-i]);
	}
	printf("%d",ans);
	return 0;
}
