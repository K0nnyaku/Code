#include <bits/stdc++.h>
using namespace std;
int n,m1,m2;
int a1[200005],a2[200005],b1[200005],b2[200005];
int f[100005]={0};
void dfs1(int x, int y){
	int l = x,r = y;
	int mid = (x+y)/2;
	while(a1[x]<a1[mid]) x++;
	while(a1[y]>a1[mid]) y--;
	if(x>=y){
		int p = a1[x];
		a1[x] = a1[y];
		a1[y] = p;
		int m=b1[x];
		b1[x] = b1[y];
		b1[y] = p;
		x++;
		y--;
	}
	if(x<r) dfs1(x,r);
	if(y>l) dfs1(l,y);
	return;
}
void dfs2(int x, int y){
	int l = x,r = y;
	int mid = (x+y)/2;
	while(a2[x]<a2[mid]) x++;
	while(a2[y]>a2[mid]) y--;
	if(x>=y){
		int p = a2[x];
		a2[x] = a2[y];
		a2[y] = p;
		int m=b2[x];
		b2[x] = b2[y];
		b2[y] = p;
		x++;
		y--;
	}
	if(x<r) dfs2(x,r);
	if(y>l) dfs2(l,y);
	return;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.in","w",stdout);
	cin >> n >> m1 >> m2;
	for(int i=0;i<m1;i++){
		cin >> a1[i] >> b1[i];
	}
	for(int i=0;i<m2;i++){
		cin >> a2[i] >> b2[i];
	}
	dfs1(0,m1-1);
	dfs2(0,m2-1);
	int maxx=0;
	for(int i=0;i<=n;i++){
		int sum1=0,sp1=i,sp2=n-sp1,sum2=0;
		int g[100005] = {0};
		int p1 = 0,p2 = 0;
		for(int j=0;j<m1;j++){
			int u=0;
			for(int l=1;l<=i;l++){
				if(g[l]<b1[j]){
					sum1++;
					g[l] = b1[j];
					u=1;
				}
			}
			if(u==1) continue;
			if(sp1-p1>0){
				p1++;
				g[p1] = b1[j];
				sum1++;
			}
			
		}
		
		for(int j=0;j<m2;j++){
			int u=0;
			for(int l=1;l<=i;l++){
				if(g[l]<b2[j]){
					sum2++;
					g[l] = b2[j];
					u=1;
				}
			}
			if(u==1) continue;
			if(sp2-p2>0){
				p2++;
				g[p2] = b2[j];
				sum2++;
			}
		}
		int sum = sum1+sum2;
		if(sum>maxx) maxx = sum;
	}
	cout << maxx << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
