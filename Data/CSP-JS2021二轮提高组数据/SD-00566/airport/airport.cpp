#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m1,m2;
struct A{
	int l,r;
}num1[100005],num2[100005];
int ans1[100005],ans2[100005],ans[100005];
bool vis1[100005],vis2[100005];
bool cmp(A x,A y){
	if(x.l!=y.l)	return x.l<y.l;
	else return x.r<y.r;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&num1[i].l,&num1[i].r);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&num2[i].l,&num2[i].r);
	sort(num1+1,num1+1+m1,cmp);
	sort(num2+1,num2+1+m2,cmp);
	for(int i=1;i<=n;i++){
		int tot=0;
		bool check=false;
		for(int j=1;j<=m1;j++){
			if(vis1[j])	continue;
			check=true;
			if(num1[j].l<tot)	continue;
			vis1[j]=true;
			tot=num1[j].r;
			ans1[i]++;
		}
		if(!check)	break;
	}
	for(int i=1;i<=n;i++)
		ans1[i]+=ans1[i-1];
	for(int i=1;i<=n;i++){
		int tot=0;
		bool check=false;
		for(int j=1;j<=m2;j++){
			if(vis2[j])	continue;
			check=true;
			if(num2[j].l<tot)	continue;
			vis2[j]=true;
			tot=num2[j].r;
			ans2[i]++;
		}
		if(!check)	break;
	}
	for(int i=1;i<=n;i++)
		ans2[i]+=ans2[i-1];
	int sol=0;
	for(int i=0;i<=n;i++){
		ans[i]=ans1[i]+ans2[n-i];
		sol=max(ans[i],sol);
	}
	printf("%d",sol);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

