#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
struct str{
	int	da;
	int zou;
};
str a[5010],b[5010];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,ma,mb,zong=0,zongz=0;
	cin>>n>>ma>>mb;
	for(int i=1;i<=ma;i++){
		cin>>a[i].da>>a[i].zou;
	}
	for(int i=1;i<=mb;i++){
		cin>>b[i].da>>b[i].zou;
	}
	for(int i=0;i<=n;i++){
		int p=i,pp=1,ppp=2,zong=0,t=0;
		while(ma>1){
			if(p>0||a[ma].zou>=a[ma-1].da) {
				p--;
				zong++;
			}
			ma--;
		}
		p=n-i;
		pp=1;
		ppp=2;
		while(mb>1){
			if(p>0&&b[mb].zou>=b[mb-1].da) {
				p--;
				zong++;
			}
			mb--;
		}
		if(zong>=zongz) zongz=zong;
	}
	cout<<zongz;
	return 0;
} 
