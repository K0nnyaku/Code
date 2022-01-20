#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
ll re(){
	ll x=0;int f=1;char t=getchar();
	while(t<'0'||t>'9'){if(t=='-')f=-1;t=getchar();}
	while(t>='0'&&t<='9')x=x*10+t-'0',t=getchar();
	return x*f;
}
const int N=100010;
int n,m1,m2;
int l[N];
struct data{
	int l,r;
};
data a1[N],a2[N];
int pd2[N];
bool pd1(data a,data b){
	return a.l<b.l;
}
int la1;
bool pd3(int x,int la,int zd){
	if(pd2[la]){
		if(a1[x].l>=a1[la].l&&a1[x].l<=a1[la].r){
			if(l[la]<zd){l[x]=l[la]+1;return true;}
			else return false;
		}
		else if(l[la]<zd){
			l[x]=l[la]+1;
			return true;
		}
		else return false;
	}
	else if(l[la]<zd){
		l[x]=l[la]+1;
		return true;
	}
	else return false;
}
bool pd4(int x,int la,int zd){
	if(pd2[la]){
		if(a2[x].l>=a2[la].l&&a2[x].l<=a2[la].r){
			if(l[la]<zd){l[x]=l[la]+1;return true;}
			else return false;
		}
		else if(l[la]<zd){
			l[x]=l[la]+1;
			return true;
		}
		else return false;
	}
	else if(l[la]<zd){
		l[x]=l[la]+1;
		return true;
	}
	else return false;
}
int js(int x1){
	memset(pd2,0,sizeof(pd2));
	memset(l,0,sizeof(l));
	ll x2=n-x1,ls=0,sum=0;la1=0;
	for(int i=1;x1&&i<=m1;i++){
		while(la1&&a1[la1].r<a1[i].l&&la1<=m1){
			la1++;
			while(!pd2[la1]&&la1<=m1)la1++;
			l[ls]--;
		}
		if(pd3(i,ls,x1))pd2[i]=1,ls=i,sum++,la1=la1?la1:i;
	}
	la1=0,ls=0;
	memset(pd2,0,sizeof(pd2));
	memset(l,0,sizeof(l));
	for(int i=1;x2&&i<=m2;i++){
		while(la1&&a2[la1].r<a2[i].l&&la1<=m2){
			la1++;
			while(!pd2[la1]&&la1<=m2)la1++;
			l[ls]--;
		}
		if(pd4(i,ls,x2))pd2[i]=1,ls=i,sum++,la1=la1?la1:i;
	}
	return sum;
}
ll ans=0;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int x1,x2;
	n=re(),m1=re(),m2=re();
	for(int i=1;i<=m1;i++){
		a1[i].l=re(),a1[i].r=re();
	}
	sort(a1+1,a1+m1+1,pd1);
	for(int i=1;i<=m2;i++){
		a2[i].l=re(),a2[i].r=re();
	}
	sort(a2+1,a2+m2+1,pd1);
	for(int i=0;i<=n;i++){
		int ls=js(i);
		if(ls>ans)ans=ls;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

