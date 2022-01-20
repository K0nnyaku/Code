#include <bits/stdc++.h>
using namespace std;
long long n,m1,m2,lb,rb,md1,md2,g[100010],as1,as2;
struct pl{
	long long at;
	long long bt;
	long long id;
}a1[100010],a2[100010],b1[100010],b2[100010];
int cmp1(pl u,pl v){
	return u.at<v.at?1:0;
}
int cmp2(pl u,pl v){
	return u.bt<v.bt?1:0;
}
long long clc(long long k){
	for(int i=1;i<=m1+m2;i++){
		g[i]=0;
	}
	long long ans=0,nd=-1,ni=0,nk=0,lq=k;
	for(int i=1;i<=m1;i++){
		while(lq<k&&b1[nd].bt<=a1[i].at){
			lq++;
			if(lq<k){
				ni=nd+1;
				while(g[b1[ni].id]==0){
					ni++;
				}
				nd=ni;
			}else{
				nd=-1;
			}
		}
		if(lq){
			lq--;
			ans++;
			g[i]=1;
			for(int j=1;j<=m1;j++){
				if(b1[j].id==i){
					nk=j;
					break;
				}
			}
			if(nd<0||b1[nd].bt>b1[nk].bt){
				nd=nk;
			}
		}
	}
	nd=-1,ni=0,lq=n-k;
	for(int i=1;i<=m2;i++){
		while(lq<n-k&&b2[nd].bt<=a2[i].at){
			lq++;
			if(lq<n-k){
				ni=nd+1;
				while(g[m1+b2[ni].id]==0){
					ni++;
				}
				nd=ni;
			}else{
				nd=-1;
			}
		}
		if(lq){
			lq--;
			ans++;
			g[m1+i]=1;
			for(int j=1;j<=m2;j++){
				if(b2[j].id==i){
					nk=j;
					break;
				}
			}
			if(nd<0||b2[nd].bt>b2[nk].bt){
				nd=nk;
			}
		}
	}
	return ans;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a1[i].at>>a1[i].bt;
		b1[i].at=a1[i].at;
		b1[i].bt=a1[i].bt;
	}
	for(int i=1;i<=m2;i++){
		cin>>a2[i].at>>a2[i].bt;
		b2[i].at=a2[i].at;
		b2[i].bt=a2[i].bt;
	}
	sort(a1+1,a1+m1+1,cmp1);
	sort(a2+1,a2+m2+1,cmp1);
	for(int i=1;i<=m1;i++){
		b1[i].at=a1[i].at;
		b1[i].bt=a1[i].bt;
		a1[i].id=i;
		b1[i].id=i;
	}
	for(int i=1;i<=m2;i++){
		b2[i].at=a2[i].at;
		b2[i].bt=a2[i].bt;
		a2[i].id=i;
		b2[i].id=i;
	}
	sort(b1+1,b1+m1+1,cmp2);
	sort(b2+1,b2+m2+1,cmp2);
	if(n==0){
		cout<<0;
		return 0;
	}
	if(n==1){
		cout<<max(clc(0),clc(1));
		return 0;
	}
	lb=0;rb=n;
	while(lb+2<rb){
		md1=lb+(rb-lb)/3;
		md2=lb+(rb-lb)*2/3;
		as1=clc(md1);
		as2=clc(md2);
		if(as1<as2){
			lb=md1;
		}else{
			rb=md2;
		}
	}
	cout<<max(max(clc(lb),clc(lb+1)),clc(rb));
	return 0;
}
