#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int n,m,o;
int a[100100],b[100100],c[100100],d[100100],e,noo[100100],nw[100100],minn=0x3f,minnn=0x3f;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m>>o;
	int maxx=-1;
		for(int i=0;i<m;i++){
			cin>>a[i];
			cin>>b[a[i]];}
		for(int i=0;i<o;i++){
			cin>>c[i];
			cin>>d[c[i]];}
		sort(a,a+m);
		sort(c,c+o);
		for(int i=0;i<m;i++)
			noo[i]==b[a[i]];
		for(int i=0;i<o;i++)
			nw[i]==a[c[i]];
		for(int i=0;i<n;i++){
			int numm=0,numn=0;
			for(int j=0;j<m;j++){
				for(int k=i;k>=1;k--){
					if(a[j]>noo[k]){
						numm++;
						noo[k]==b[a[j]];
						break; 
					}
				}	
			} 
			for(int j=0;j<o;j++){
				for(int k=n-i;k>=1;k--){
					if(c[j]>nw[k]){
						numn++;
						nw[k]==d[c[j]];
						break; 
					}
				}	
			} 
			maxx=max(numm+numn,maxx);
		}
		cout<<maxx;		
	return 0;
	}
