#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
struct guonei{
	int daoda,likai;
}much1[100010];
struct guowai{
	int daoda,likai;
}much2[100010];
bool cmp1(const guonei x,const guonei y){
	return x.daoda<y.daoda;
}
bool cmp2(const guowai x,const guowai y){
	return x.daoda<y.daoda;
}
int use1[100010],use2[100010];
using namespace std;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,endans=0,c;
	scanf("%d%d%d",&n,&m1,&m2);
	//cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++){
		cin>>much1[i].daoda>>much1[i].likai;
	}
	for(int i=0;i<m2;i++){
		cin>>much2[i].daoda>>much2[i].likai;
	}
	sort(much2,much2+m2,cmp2);
	sort(much1,much1+m1,cmp1);
	for(int i=0;i<=n;i++){
		int lqnei=i,lqwai=n-i;
		int ans=0;
		for(int j=0;j<m1;j++){//国内飞机 
			for(int k=0;k<lqnei;k++){
				if(use1[k]<=much1[j].daoda){
					use1[k]=much1[j].likai;
					ans++;
					break;
				}
			}
		}
		for(int j=0;j<m2;j++){//国外飞机 
		    for(int k=0;k<lqwai;k++){
		    	if(use2[k]<=much2[j].daoda){
		    		use2[k]=much2[j].likai;
		    		ans++;
		    		break;
				}
			}
	    }
		if(ans>endans){
			endans=ans;
		}
		memset(use1,0,sizeof(use1));
		memset(use2,0,sizeof(use2));
	}
	cout<<endans;
	return 0;
}
