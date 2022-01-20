#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m1,m2,ai1[100005],cnt1,ai2[100005],cnt2,ans;
struct node {
	int a,b;
}air1[100005],air2[100005];
int cmp (node x,node y){
	return x.a<y.a;
}
int cmp2 (int x,int y){
	return x<y;
}
int main (){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	if (n>=m1+m2){
		cout<<m1+m2;
		return 0;
	}
	for (int i=1;i<=m1;i++){
		scanf("%d%d",&air1[i].a,&air1[i].b);
		ai1[++cnt1]=air1[i].a,ai1[++cnt1]=air1[i].b; 
	}
	for (int i=1;i<=m2;i++){
		scanf("%d%d",&air2[i].a,&air2[i].b);
		ai2[++cnt2]=air2[i].a,ai2[++cnt2]=air2[i].b;
	}
	sort(ai1+1,ai1+cnt1+1,cmp2);
	for (int i=1;i<=m1;i++){
		air1[i].a=lower_bound(ai1+1,ai1+cnt1+1,air1[i].a)-ai1;
		air1[i].b=lower_bound(ai1+1,ai1+cnt1+1,air1[i].b)-ai1;
	}
	sort(ai2+1,ai2+cnt2+1,cmp2);
	for (int i=1;i<=m2;i++){
		air2[i].a=lower_bound(ai2+1,ai2+cnt2+1,air2[i].a)-ai2;
		air2[i].b=lower_bound(ai2+1,ai2+cnt2+1,air2[i].b)-ai2;
	}
	sort(air1+1,air1+1+m1,cmp);
	sort(air2+1,air2+1+m2,cmp);
	cout<<"\n";
	for (int i=0;i<=n;i++){
		int l=i,r=n-i,ans1=0,ans2=0,ano1=0,ano2=0;
		queue <int> q1,q2;
		q1.push(air1[1].b);
		for (int j=1;j<=m1;j++){
			while (air1[j].a>=q1.front()&&q1.size()){
				q1.pop();
			}
			if (j!=1) q1.push(air1[j].b);
			if (q1.size()-ano1<=l) ans1++;
			else if (j!=1&&ans1) ano1++;
		}
		q2.push(air2[1].b);
		for (int j=1;j<=m2;j++){
			while (air2[j].a>=q2.front()&&q2.size()){
				q2.pop();
			}
			if (j!=1) q2.push(air2[j].b);
			if (q2.size()-ano2<=r) ans2++;
			else if (j!=1&&ans2) ano2++;
		}
		ans=max(ans,ans1+ans2);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
