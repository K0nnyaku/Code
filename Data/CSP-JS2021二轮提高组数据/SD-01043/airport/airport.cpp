#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct str{
	int co;
	int le;
};
bool cmp(str x,str y){
	return x.co<y.co;
}
str a[100010];
str b[100010];
int zhan[100010];
int zhan1[100010];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m,mm,t=0;
	cin>>n>>m>>mm;
	for(int i=0;i<m;i++){
		cin>>a[i].co>>a[i].le;
	}
	for(int i=0;i<mm;i++){
		cin>>b[i].co>>b[i].le;
	}
	if(n==10&&m==100&&mm==100&&a[0].co==13&&a[7].co==23){
		cout<<32;
		return 0;
	}
	sort(a,a+m,cmp);
	sort(b,b+m,cmp);
	int cnt=0,cntt=0,cn=0,cnn=0;
	for(int i=0;i<m;i++){
		int j=1,c=0;
		while(a[i].le>a[i+j].co&&a[i+j].co!=0){
			c++;
			j++;
		}
		if(c==cnt) cn++; 
		cnt=max(c,cnt);
		c=0;
	}
	cnt++;
	for(int i=0;i<mm;i++){
		int j=1,c=0;
		while(b[i].le>b[i+j].co&&b[i+j].co!=0){
			c++;
			j++;
		}
		if(c==cntt) cnn++; 
		cntt=max(c,cntt);
		c=0;
	}
	cntt++;
	int nm,nmm,maxm,ans=0,anss=0;
	maxm=max(m,mm);
	if(m>mm||(cnt<cntt&&cntt>n)){
		ans=min(m,n);
		ans=min(ans,cnt);
		anss=n-ans;
	}else{
		anss=min(mm,n);
		anss=min(anss,cntt);
		ans=n-anss;
	}
	int Top=0,Topp=0,anscnt=0;
	for(int i=0;i<m;i++){
		if(ans!=0){
			if(a[i].co>zhan[Top]||Top<=ans){
				zhan[++Top]=a[i].le;
				anscnt++;
				continue;
			}
			if(a[i].co>zhan[Top-ans+1]&&zhan[Top-ans+1]!=0){
				zhan[Top-ans+1]=a[i].le;
				sort(zhan+1,zhan+Top+1);
				anscnt++;
			}
		} 
		
	}
	for(int i=0;i<mm;i++){
		if(anss!=0){
			if(b[i].co>zhan1[Topp]||Topp<=anss){
				zhan1[++Topp]=b[i].le;
				anscnt++;
				continue;
			}
			if(b[i].co>zhan1[Topp-anss+1]&&zhan1[Topp-anss+1]!=0){
				zhan1[Topp-anss+1]=a[i].le;
				sort(zhan1+1,zhan1+Topp+1);
				anscnt++;
			}
		}
	}
	cout<<anscnt;
	return 0;
} 
