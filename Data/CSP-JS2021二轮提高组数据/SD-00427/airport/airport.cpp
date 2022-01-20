#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<cstdio>
#include<windows.h>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e5+10;
int n,m1,m2;
int air1[N]; 
int air2[N];
pair<int,int> a1[N];
pair<int,int> a2[N];
int color1[N];
int color2[N];
bool cmp(pair<int,int>a,pair<int,int>b){
	return a.first<b.first;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d",&n);
	scanf("%d%d",&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a1[i].first,&a1[i].second);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&a2[i].first,&a2[i].second);
	}
	if(n>=m1+m2){
		cout<<m1+m2<<'\n';
		return 0;
	} 
	sort(a1+1,a1+m1+1,cmp);
	sort(a2+1,a2+m2+1,cmp);
//	for(int i=1;i<=m1;i++){
//		cout<<a1[i].first<<" "<<a1[i].second<<" ";
//	}
	int count=0; 
	for(int i=1;i<=m1;i++){
		if(color1[i]==0){
			count++;
			color1[i]=count;
			int num=1;
			int k=a1[i].second;
			for(int j=i+1;j<=m1;j++){
				if(k<a1[j].first){
					if(!color1[j]){
						color1[j]=count;
						num++;		
						k=a1[j].second;				
					}
				}
			}
			air1[count]=num+air1[count-1];
		}
	} 
	for(int i=count;i<=m1;i++){
		air1[i]=air1[count];
	}
//	for(int i=1;i<=m1;i++){
//		cout<<color1[i]<<" ";
//	}
//	cout<<endl;
	count =0;
	for(int i=1;i<=m2;i++){
		if(color2[i]==0){
			count++;
			color2[i]=count;
			int num=1;
			int k=a2[i].second;
			for(int j=i+1;j<=m2;j++){
				if(k<a2[j].first){
					if(!color2[j]){
						color2[j]=count;
						num++;		
						k=a2[j].second;				
					}
				}
			}
			air2[count]=num+air2[count-1];
		}
	} 
	for(int i=count;i<=m2;i++){
		air2[i]=air2[count];
	}
//	for(int i=1;i<=m2;i++){
//		cout<<color2[i]<<" ";
//	}
	int ans=0; 
	for(int i=0;i<=n;i++){
		ans=max(air1[i]+air2[n-i],ans);
	}
	cout<<ans;
	return 0;
}
/*1.算出有多少航班冲突
 2.二分搜索
 */
 /*
 3 5 4
 1 5 3 8 6 10 9 14
 13 18 2 11 4 15 7 17 12 16 
 
 2 4 6
 20 30
 40 50 21 22
 41 42
 1 19
 2 18
 3 4 5 6 7 8 9 10
 */
 //(m1+m2) log (m1+m2)=10^9;
