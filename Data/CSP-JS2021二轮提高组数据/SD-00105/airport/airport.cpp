#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
const int wc=100005;
int n,m1,m2;
struct air{
	int start,end;
}a[wc+5],b[wc+5];
int ans=0;
int cmp(air a,air b){
	return a.start<b.start;
}
int cheak1(int gn){
	int z=0,sum=1;
	if(gn==0){
		return 0;
	}
	int viss[gn+5],vise[gn+5];
	memset(viss,0,sizeof(viss));
	memset(vise,0,sizeof(vise));
	viss[1]=a[1].start;
	vise[1]=a[1].end;
	z=1;
	for(int i=2;i<=m1;i++){
		int f=0;
		if(z<gn){
			z++;
			sum++;
			viss[z]=a[i].start;
			vise[z]=a[i].end;
		}else{
			for(int j=1;j<=gn;j++){
				if(vise[j]<=a[i].start){
					viss[j]=a[i].start;
					vise[j]=a[i].end;
					f=1;
					break;
				}
			}
			if(f==1){
				sum++;
			}
		}
	}
	return sum;
}
int cheak2(int gw){
	int z=0,sum=1;
	if(gw==0){
		return 0;
	}
	int viss[gw+5],vise[gw+5];
	memset(viss,0,sizeof(viss));
	memset(vise,0,sizeof(vise));
	viss[1]=b[1].start;
	vise[1]=b[1].end;
	z=1;
	for(int i=2;i<=m2;i++){
		int f=0;
		if(z<gw){
			z++;
			sum++;
			viss[z]=b[i].start;
			vise[z]=b[i].end;
		}else{
			for(int j=1;j<=gw;j++){
				if(vise[j]<=b[i].start){
					viss[j]=b[i].start;
					vise[j]=b[i].end;
					f=1;
					break;
				}
			}
			if(f==1){
				sum++;
			}
		}
	}
	return sum;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a[i].start>>a[i].end;
	}		
	for(int i=1;i<=m2;i++){
		cin>>b[i].start>>b[i].end;
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
    for(int i=0;i<=n;i++){
    	ans=max(ans,cheak1(i)+cheak2(n-i));
	} 
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
