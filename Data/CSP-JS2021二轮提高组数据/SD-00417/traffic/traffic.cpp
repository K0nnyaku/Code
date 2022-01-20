#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n,m,T,k;
int xia[505][505];
int you[505][505];
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>T;
	for(int o=1;o<=T;o++){
		for(int i=1;i<n;i++){
			for(int j=1;j<=m;j++){
				cin>>xia[i][j];
			}
		} 
		for(int i=1;i<=n;i++){
			for(int j=1;j<m;j++){
				cin>>you[i][j];
			}
		}
		cin>>k;
		int w,num,fl;
		for(int i=1;i<=k;i++){
			cin>>w>>num>>fl;
			
		}
		
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
