#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii; 

const int maxn=1e5+10;

int x[maxn],y[maxn];

int n,m,mm;

struct plane{
	int s,t,id;
}a[maxn],b[maxn];

bool cmp(plane a,plane b){
	return a.s<b.s;
}

int check(int l,int r){
	int xx=0,yy=0,numx=0,numy=0;
	for(int i=1;i<=m;i++){
		if(!xx&&xx<l){
				xx++;
				x[++numx]=a[i].t;
		}
		else{
			bool flag=false;
			for(int j=1;j<=numx;j++){
				if(x[j]<=a[i].s){
					x[j]=a[i].t;
					flag=true;
					break;
				}
			}
			if(flag) xx++;
			else if(numx<l){
				x[++numx]=a[i].t;
				xx++;
			}
		}
	}
	for(int i=1;i<=mm;i++){
		if(!yy&&yy<r){
				yy++;
				y[++numy]=b[i].t;
		}
		else{
			bool flag=false;
			for(int j=1;j<=numy;j++){
				if(y[j]<=b[i].s){
					y[j]=b[i].t;
					flag=true;
					break;
				}
			}
			if(flag) yy++;
			else if(numy<r){
				y[++numy]=b[i].t;
				yy++;
			}
		}
	}
	return xx+yy;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int ans=0;
	scanf("%d%d%d",&n,&m,&mm);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a[i].s,&a[i].t);
		a[i].id=1;
	}
	for(int i=1;i<=mm;i++){
		scanf("%d%d",&b[i].s,&b[i].t);
		b[i].id=2;
	}
	sort(a+1,a+m+1,cmp);
	sort(b+1,b+mm+1,cmp);
	int l=0,r=n;
	while(l<=n){
		int t=check(l,r);
		ans=max(ans,t);
	    l++;r--;
	}
	printf("%d\n",ans);
	return 0;
}
