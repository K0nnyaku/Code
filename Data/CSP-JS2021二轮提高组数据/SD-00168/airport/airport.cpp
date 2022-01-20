#include <bits/stdc++.h>
using namespace std;
int n,m1,m2,ans,b[2][100005],l[2];
struct Plane{
	int dao;
	int li;
	int nat;
}p1[100005];
bool cmp(Plane x,Plane y){
	if(x.dao>y.dao){
		return false;
	}
} 
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=0;i<m1;i++){
		cin>>p1[i].dao>>p1[i].li;
		p1[i].nat=0;
	}
	for(int i=m1;i<m1+m2;i++){
		cin>>p1[i].dao>>p1[i].li;
		p1[i].nat=1;
	}
	sort(p1,p1+m1+m2,cmp);
	for(int i=0;i<=m1&&n-i>=0;i++){
		int ans1=0;
		memset(l,0,sizeof(l));
		memset(b,0,sizeof(b));
		for(int j=0;j<m1+m2;j++){
			if(p1[j].nat==0){
				if(l[0]<i){
					b[0][l[0]]=p1[j].li;
					ans1++;
					l[0]++;
				}else{
					for(int k=0;k<l[0];k++){
						if(b[0][k]<p1[j].dao){
							b[0][k]=p1[j].li;
							ans1++;
							break;
						}
					}
				}
			}else{
				if(l[1]<n-i){
					b[1][l[1]]=p1[j].li;
					ans1++;
					l[1]++;
				}else{
					for(int k=0;k<l[1];k++){
						if(b[1][k]<p1[j].dao){
							b[1][k]=p1[j].li;
							ans1++;
							break;
						}
					}
				}
			}
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
} 
