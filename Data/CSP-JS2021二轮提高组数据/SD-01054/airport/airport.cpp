#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<string>
#include<queue>
#include<cmath>
#include<cctype>
#include<utility>
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
struct node{
	int a1,b1;
};
bool cmp1(node k1,node k2){
	return k1.a1<k2.a1;
}

struct mote{
	int a2,b2;
}qq[100009];
int n,m1,m2,t[100009],maxl,dp1[100009],dp2[100009];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	node p[100009],q[100009];
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&p[i].a1,&p[i].b1);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&q[i].a1,&q[i].b1);
	}
	sort(p+1,p+m1+1,cmp1);
	sort(q+1,q+m2+1,cmp1);
	t[0]=0x3f3f3f3f;
	for(int i=0;i<=n;i++){
		for(int j=1;j<=i;j++){
			t[j]=0;
		}
		for(int j=1;j<=m1;j++){
			if(p[j].a1>t[1]){
				t[1]=p[j].b1;
				
				sort(t+1,t+i+1,cmp);
				dp1[i]++;
			}
		}
		
		for(int j=1;j<=i;j++){
			t[j]=0;
		}
		for(int j=1;j<=m2;j++){
			if(q[j].a1>t[1]){
				t[1]=q[j].b1;
				sort(t+1,t+i+1,cmp);
				dp2[i]++;
			}
		}
	}
	
	for(int i=0;i<=n;i++){
		maxl=max(maxl,dp1[i]+dp2[n-i]);
	}
	
	cout<<maxl;
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

