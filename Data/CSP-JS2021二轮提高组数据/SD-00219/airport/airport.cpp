#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
struct A{
	int s,e;
};
A gn[100090],gw[100090];
bool cmp(A f,A g){
	return f.s<g.s;
}
int zhao(int x,int l[],int g){
	int le=1,r=2*g;
	while(le!=r){
		//cout<<le;
		int mid=(le+r)/2;
		if(l[mid]==x){
			return mid;
		}
		else if(l[mid]<x){
			le=mid+1;
		} 
		else{
			r=mid-1;
		}
	}
	return le;
}
int zhao1(int x,A l[],int g){
	int le=1,r=2*g;
	while(le!=r){
		//cout<<le;
		int mid=(le+r)/2;
		//cout<<mid;
		if(l[mid].s==x){
			return mid;
		}
		else if(l[mid].s<x){
			le=mid+1;
		} 
		else{
			r=mid-1;
		}
	}
	return le;
}
int n,m,k,f[100090],f1[100090],l[100090],l1[100090],qw[100090],p[100090],zx[100090];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>gn[i].s>>gn[i].e;
		l[i*2-1]=gn[i].s;
		l[i*2]=gn[i].e;
	}
	for(int i=1;i<=k;++i){
		cin>>gw[i].s>>gw[i].e;
		l1[i*2-1]=gw[i].s;
		l1[i*2]=gw[i].e;
	}
	sort(gn+1,gn+m+1,cmp);
	sort(gw+1,gw+k+1,cmp);
	sort(l+1,l+2*m+1);
	sort(l1+1,l1+2*k+1);
	for(int i=1;i<=m;++i){
		gn[i].s=zhao(gn[i].s,l,m);
		p[gn[i].s]++;
		gn[i].e=zhao(gn[i].e,l,m);
		p[gn[i].e]--;
		//cout<<gn[i].s<<" "<<gn[i].e<<endl;
	}
	int sum=0;
	for(int i=1;i<=2*m;++i){
		 sum+=p[i];
		 qw[i]=sum;
	}
	f[0]=0;
	for(int i=1;i<=2*m;++i){
		sum=0;
		memset(zx,0,sizeof(zx));
		for(int j=1;j<=2*m;++j){
			if(qw[j]-zx[j]<=i){
				continue;
			}
			++sum;
			int u=zhao1(j,gn,m);
			for(int k=gn[u].s;k<=gn[u].e;++k){
				zx[k]++;
			}
		}
		f[i]=m-sum;
	}
	memset(p,0,sizeof(p));
	for(int i=1;i<=k;++i){
		gw[i].s=zhao(gw[i].s,l1,k);
		p[gw[i].s]++;
		gw[i].e=zhao(gw[i].e,l1,k);
		p[gw[i].e]--;
		//cout<<gw[i].s<<" "<<gw[i].e<<endl;
	}
	for(int i=1;i<=2*k;++i){
		 sum+=p[i];
		 qw[i]=sum;
	}
	f1[0]=0;
	for(int i=1;i<=min(k,n);++i){
		sum=0;
		memset(zx,0,sizeof(zx));
		for(int j=1;j<=2*k;++j){
			if(qw[j]-zx[j]<=i){
				continue;
			}
			++sum;
			int u=zhao1(j,gw,k);
			for(int k=gw[u].s;k<=gw[u].e;++k){
				zx[k]++;
			}
		}
		f1[i]=k-sum;
	}
	int mAxx=0;
	for(int i=0;i<=n;++i){
		//cout<<f[i]<<" "<<f1[n-i]<<endl;
		if(f[i]+f1[n-i]>mAxx){
			mAxx=f[i]+f1[n-i];
		}
	}
	cout<<mAxx;
	return 0;
}
