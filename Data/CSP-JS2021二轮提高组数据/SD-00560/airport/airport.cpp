#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxN=100000+10;
int n,mx1,mx2;
int nmax,gn,gj,c,ans;
struct node{
	int dd,lk;
};
node hb1[maxN],hb2[maxN];
int cnt1[maxN],cnt2[maxN];


int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>mx1>>mx2;
	int max1=-1,max2=-1;
	int numb=1;
	for(int i=1;i<=mx1;i++){
		int x,y;
		cin>>x>>y;
		max1=max(max1,y);
		hb1[x].dd=numb;
		hb1[y].lk=numb;
		numb+=1;
	}
	numb=1;
	for(int i=1;i<=mx2;i++){
		int x,y;
		cin>>x>>y;
		max2=max(max2,y);
		hb2[x].dd=numb;
		hb2[y].lk=numb;
		numb+=1; 
	}
	
	nmax=0;
	c=n;
	int k;
	for(int i=0;i<=n;i++){
		gn=i,gj=c;
		ans=0;
		k=1;
		for(int j=1;j<=max1;j++){
			if(hb1[j].lk>=1&&cnt1[hb1[j].lk]==hb1[j].lk){
				gn+=1;
			}
			if(hb1[j].dd>=1&&gn>0){
				gn-=1;
				ans+=1;
				cnt1[k]=hb1[j].dd;
				k+=1;
			}
		}
		k=1;
		for(int j=1;j<=max2;j++){
			if(hb2[j].lk>=1&&cnt2[hb2[j].lk]==hb2[j].lk){
				gj+=1;
			}
			if(hb2[j].dd>=1&&gj>0){
				gj-=1;
				ans+=1;
				cnt2[k]=hb2[j].dd;
				k+=1;
			}
		}
		
		c-=1;
		nmax=max(nmax,ans);
	}
	
	cout<<nmax<<endl;
	
	return 0;
}

