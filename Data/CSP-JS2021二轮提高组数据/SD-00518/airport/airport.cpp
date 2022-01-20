#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
const int N=100010;
int n,m,k,bs[N],ma;

struct node{
	int in,ou;
}te[N],ut[N];

bool com(node a,node b){
	return a.in <b.in ;
}

bool pe(int a,int b){
	return a>b;
} 


int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&te[i].in,&te[i].ou);
	for(int i=1;i<=k;i++)
		scanf("%d%d",&ut[i].in,&ut[i].ou);
	sort(te+1,te+m+1,com);
	sort(ut+1,ut+k+1,com);
	for(int i=0;i<=n;i++){
		int hea=0,tnt=0,ans=0;
		for(int j=1;j<=m;j++){
			if(i==0)break;
			if (tnt<i){
				ans++;
				bs[++tnt]=te[j].ou;
			}
			else{
				sort(bs+1,bs+tnt+1,pe);
				if(te[j].in >bs[tnt]){
				ans++;
				bs[tnt]=te[j].ou ;
				}
			} 
		}
		hea=0,tnt=0;
		for(int j=1;j<=k;j++){
			if(n-i==0)break;
			if(tnt<n-i){
				ans++;
				bs[++tnt]=ut[j].ou ;
			}
			
			else{
				sort(bs+1,bs+1+tnt,pe);
				if(ut[j].in >bs[tnt]){
				ans++;
				bs[tnt]=te[j].ou ;
				}
			} 
		}
		ma=max(ma,ans);
	}
	printf("%d",ma);
	return 0;
}  
