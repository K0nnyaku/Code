#include <iostream>
#include <queue>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=100010;
int n,m1,m2,zq[MAXN][3];
unsigned int tim[100000001][3];
struct node{
	int xh;
	int jz;
	int cz;
}pl[MAXN];
bool cmp(node a,node b){if(a.jz>b.jz)return 0;}
inline int add(int st,int en,int sc){
	//Ç°×ººÍ(need)
	int ansa;
	for(int i=st;i<=en;i++){
		ansa+=tim[i][sc];
	} 
	return ansa;
}
int ans;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	if(n==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=m1;i++)
	{
		cin>>pl[i].jz>>pl[i].cz;
		pl[i].xh=1;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>pl[m1+i].jz>>pl[m1+i].cz;
		pl[m1+i].xh=2;
	}
	sort(pl+1,pl+1+m1+m2,cmp);
	int xc;
	pl[0].jz=0;
	int nans=0;
	for(int k=0;k<=n;k++) {
		ans=max(ans,nans);
		nans=0;
		int g[3]={0,k,n-k};
		for(int i=1;i<=m1+m2;i++){
			if(pl[i].xh==1){
				g[1]+=add(pl[i-1].jz+1,pl[i].jz,1);
				xc=pl[i].xh;
				if(g[xc]>0){
					g[xc]--;
					nans++;
					tim[pl[i].cz][xc]++;
				}
			}else{
				g[2]+=add(pl[i-1].jz+1,pl[i].jz,2);
				xc=pl[i].xh;
				if(g[xc]>0){
					g[xc]--;
					nans++;
					tim[pl[i].cz][xc]++;
				}
			}
		}
	}
	cout<<max(ans,nans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

