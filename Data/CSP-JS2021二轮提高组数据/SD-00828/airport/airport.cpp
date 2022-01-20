#include<iostream>
#include<cmath>
#include<cstdio>
#include<stack>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cstdlib>
using namespace std;
const int N=1e5+5;
int n,m1,m2,ans=-1;
int min1,min2; 
int ans1[N],ans2[N],sum1[N],sum2[N],ls1[N],ls2[N];
void file(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
}
struct node1{
	int l,r;
}a1[N];
struct node2{
	int l,r;
}a2[N];
bool cmp1(node1 x,node1 y){
	return x.l<y.l;
}
bool cmp2(node2 x,node2 y){
	return x.l<y.l;
}
int main(){
	file();
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a1[i].l>>a1[i].r;
	}
	for(int i=1;i<=m2;i++){
		cin>>a2[i].l>>a2[i].r;
	}
	if(n>=(m1+m2)){
		cout<<m1+m2<<endl;
		return 0;
	}
	sort(a1+1,a1+m1+1,cmp1);
	sort(a2+1,a2+m2+1,cmp2);
	memset(ans1,m1,sizeof(ans1));
	memset(ans2,m2,sizeof(ans2));
//	for(int i=1;i<=m1;i++){
//		cout<<a1[i].l<<" "<<a1[i].r<<endl;
//	}
//	for(int i=1;i<=m2;i++){
//		cout<<a2[i].l<<" "<<a2[i].r<<endl;
//	}
	int tot=1,flag=0;
	sum1[1]=1;
	ls1[1]=a1[1].r;
	for(int i=2;i<=m1;i++){
		flag=0;
		for(int j=1;j<=tot;j++){
			if(a1[i].l>ls1[j]){
				ls1[j]=a1[i].r;
				sum1[j]++;
				flag=1;
				break;
			}
		}
		if(flag==0){
			tot++;
			sum1[tot]++;
			ls1[tot]=a1[i].r;
		}
	}	
	for(int i=2;i<=tot;i++){
		sum1[i]+=sum1[i-1];
	}
	tot=1,flag=0;
	sum2[1]=1;
	ls2[1]=a2[1].r;
	for(int i=2;i<=m2;i++){
		flag=0;
		for(int j=1;j<=tot;j++){
			if(a2[i].l>ls2[j]){
				ls2[j]=a2[i].r;
				sum2[j]++;
				flag=1;
				break;
			}
		}
		if(flag==0){
			tot++;
			sum2[tot]++;
			ls2[tot]=a2[i].r;
		}
	}
	for(int i=2;i<=tot;i++){
		sum2[i]+=sum2[i-1];
	} 
	for(int i=0;i<=n;i++){
		ans=max(ans,sum1[i]+sum2[n-i]);
	}
	cout<<ans<<endl;
	return 0;
} 
