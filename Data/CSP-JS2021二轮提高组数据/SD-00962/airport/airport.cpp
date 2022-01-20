#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#include<cmath>
using namespace std;
const int maxn=100005;
int n,m1,m2,a1[100005],a2[100005];
struct node1{
	int u,v;
}e1[maxn]; 
struct node2{
	int u,v;
}e2[maxn];
int ans,sum1,sum2;
bool cmp1(node1 x,node1 y){
	return x.u<y.u;
}
bool cmp2(node2 x,node2 y){
	return x.u<y.u;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>e1[i].u>>e1[i].v;
	}
	for(int i=1;i<=m2;i++){
		cin>>e2[i].u>>e2[i].v;
	}
	sort(e1+1,e1+1+m1,cmp1);
	sort(e2+1,e2+1+m2,cmp2);
	for(int i=0,j=n-i;i<=n;i++,j=n-i){
		int cnt1=i; 
		int cnt2=j; 
		if(i!=0){
			int bj=1e8+5;
			for(int k=1;k<=m1;k++){
			if(cnt1!=0){
				sum1++;
				bj=min(e1[k].v,bj);
			    cnt1--;
			}
			if(cnt1==0&&e1[k].u>bj){	
				sum1++;
				bj=min(e1[k].v,bj);
			}
		  } 
		}
		else{
			sum1=0;
		}
		if(j!=0){
			int bj=1e8+5;
		    for(int k=1;k<=m2;k++){
			if(cnt2!=0){
				sum2++;
				cnt2--;
				bj=min(e2[k].v,bj);
			
			}
			if(cnt2==0&&e2[k].u>bj){	
				sum2++;
				bj=min(e2[k].v,bj);
			}
		  } 	
		}
		else{
			sum2=0;
		}
		ans=max(ans,sum1+sum2);
		sum1=0;
		sum2=0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}



