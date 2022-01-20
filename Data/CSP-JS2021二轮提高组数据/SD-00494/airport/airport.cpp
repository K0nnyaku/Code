#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int n,m_1,m_2,a_1[100005],b_1[100005],a_2[100005],b_2[100005],gn[100005],gw[100005],gnn[100005],gww[100005];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m_1,&m_2);
	for(int i=1;i<=m_1;i++){
		scanf("%d %d",&a_1[i],&b_1[i]);
	}
	for(int i=1;i<=m_2;i++){
		scanf("%d %d",&a_2[i],&b_2[i]);
	}
	for(int i=1;i<=m_1;i++){
		for(int j=i+1;j<=m_1;j++){
			if(a_1[i]>a_1[j]){
				swap(a_1[i],a_1[j]);
				swap(b_1[i],b_1[j]);
			}
		}
	}
	for(int i=1;i<=m_2;i++){
		for(int j=i+1;j<=m_2;j++){
			if(a_2[i]>a_2[j]){
				swap(a_2[i],a_2[j]);
				swap(b_2[i],b_2[j]);
			}
		}
	}
	int anss=0;
	//int cntt=0,cnttt=0;
	for(int i=0;i<=n;i++){
		int ans=0;
		int x=0,y=0;
		memset(gn,0,sizeof(gn));
		memset(gw,0,sizeof(gw));
		int cnt1=0,cnt2=0;
		for(int j=1;j<=m_1;j++){
			if(x<i){
				gn[++cnt1]=b_1[j];
				x++;
				ans++;
				//gnn[++cntt]=j;
			}else{
				bool ff=0;
				for(int k=1;k<=cnt1;k++){
					if(gn[k]<=a_1[j]){
						if(ff==0)gn[k]=b_1[j]; 
						else{
							gn[k]=0;
							x--;
						}
						ff=1;
					}
				}
				if(ff==1){
					//gnn[++cntt]=j;
					ans++;
				}
			}
		}
		for(int j=1;j<=m_2;j++){
			if(y<n-i){
				gw[++cnt2]=b_2[j];
				y++;
				ans++;
				//gww[++cnttt]=j;
			}else{
				bool ff=0;
				for(int k=1;k<=cnt2;k++){
					if(gw[k]<=a_2[j]){
						if(ff==0)gw[k]=b_2[j]; 
						else{
							gw[k]=0;
							y--;
						}
						ff=1;
					}
				}
				if(ff==1){
					//gww[++cnttt]=j;
					ans++;
				}
			}
		}
		anss=max(anss,ans);
		//cout<<ans<<'\n';
	}
	cout<<anss;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16

2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
