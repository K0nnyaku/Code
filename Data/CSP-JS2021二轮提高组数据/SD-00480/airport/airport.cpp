#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,m1,m2;
const int N = 1e6+6;
int aa[N][2],bb[N][2];// 0shi zuobiao 1shi houdian

struct node{
	int l,r;
};
node a[N],b[N];
bool camp(node j,node k) {
	return j.l<k.l;
}

int main() {
	freopen("airport.in","r",stdin); 
	freopen("airport.out","w",stdout); 
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%d%d",&a[i].l,&a[i].r);
	for(int i=1;i<=m2;i++) scanf("%d%d",&b[i].l,&b[i].r);
	sort(a+1,a+m1+1,camp);
	sort(b+1,b+m2+1,camp);
	int cnta=0;
	aa[++cnta][0]=1;aa[cnta][1]=a[1].r;
    for(int i=2;i<=m1;i++) {
    	bool flag=0;
    	for(int j=1;j<=cnta;j++){
    	    if(a[i].l>aa[j][1]) {
    	    	aa[j][0]++;
    	    	aa[j][1]=a[i].r;
    	    	flag=1;
    	    	break;
		   }
		}
		if(!flag) aa[++cnta][0]=1,aa[cnta][1]=a[i].r;	
	}
    
    int cntb=0;
	bb[++cntb][0]=1;bb[cntb][1]=b[1].r;
    for(int i=2;i<=m2;i++) {
    	bool flag=0;
    	for(int j=1;j<=cntb;j++){
    	    if(b[i].l>bb[j][1]) {
    	    	bb[j][0]++;
    	    	bb[j][1]=b[i].r;
    	    	flag=1;
    	    	break;
		   }
		}
		if(!flag) bb[++cntb][0]=1,bb[cntb][1]=b[i].r;
	}
    int z=1,y=1;
    long long ans=0;
    for(int i=1;i<=n;i++) {
    	if(aa[z][0]>=bb[y][0]) {
    		ans+=aa[z][0];
    		z++;
		}
		else {
			ans+=bb[y][0];
			y++;
		}
	}
	printf("%d",ans);
	return 0;
} 


