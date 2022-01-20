#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
int n,m1,m2;
int time1[100010][5],time2[100010][5];
int time[100010],maxx=0;
	int time11[100010][5],time22[100010][5];

int dp(int bridge,int country){
	bool stl[bridge+5][m1+10];
	memset(stl,true,sizeof(stl));
	if(bridge>=m1) return m1;
	if(bridge==0) return 0;
	int s=0;
	int st_top[m1+10];
	for(int i=0;i<=m1+1;i++){
		st_top[i]=1;
	}
	int st[bridge+5][m1+10];//bridge+2:max
	memset(st,0,sizeof(st));
	for(int j=1;j<=m1;j++){
		for(int i=1;i<=bridge+1;i++){
			for(int k=1;k<=st_top[j];k++) st[k][j]=st[bridge+1][j-1];
			if(i>st_top[j]+1) {
				for(int k=st_top[j]+2;k<=bridge+1;k++) st[k][j]=st[st_top[j]+1][j];
				break;
			}
			if(i==st_top[j]+1){
				st[i][j]=st[bridge+1][j-1]+1;
				int p=j+1;
				for(;;){
					if(time1[p][1]>=time1[j][2]) break;
					st_top[p]++;
					p++;
				}
			}
		}
	}
	return st[bridge+1][m1];
}

int dp2(int bridge,int country){
	bool stl[bridge+5][m2+10];
	memset(stl,true,sizeof(stl));
	if(bridge>=m2) return m2;
	if(bridge==0) return 0;
	int s=0;
	int st_top[m2+10];
	for(int i=0;i<=m2+1;i++){
		st_top[i]=1;
	}
	int st[bridge+5][m2+10];//bridge+2:max
	memset(st,0,sizeof(st));
	for(int j=1;j<=m2;j++){
		for(int i=1;i<=bridge+1;i++){
			for(int k=1;k<=st_top[j];k++) st[k][j]=st[bridge+1][j-1];
			if(i>st_top[j]+1) {
				for(int k=st_top[j]+2;k<=bridge+1;k++) st[k][j]=st[st_top[j]+1][j];
				break;
			}
			if(i==st_top[j]+1){
				st[i][j]=st[bridge+1][j-1]+1;
				int p=j+1;
				for(;;){
					if(time2[p][1]>=time2[j][2]) break;
					st_top[p]++;
					p++;
				}
			}
		}
	}
	return st[bridge+1][m2];
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	int timex,timey;
	memset(time1,1e8,sizeof(time1));
	memset(time2,1e8,sizeof(time2));
	int top1=0;
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&timex,&timey);
		if(top1==0){
			top1++;
			time1[top1][1]=timex;
			time1[top1][2]=timey;
			continue;
		}
		if(time1[top1][1]<timex){
			top1++;
			time1[top1][1]=timex;
			time1[top1][2]=timey;
			continue;
		}
		for(int j=1;j<=top1;j++){
			if(time1[j][1]>timex){
				top1++;
				for(int k=top1;k>=j;k--){
					time1[k][1]=time1[k-1][1];
					time1[k][2]=time1[k-1][2];
				}
				time1[j][1]=timex;
				time1[j][2]=timey;
				break;
			}
		}
		
	}
	
	int top2=0;
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&timex,&timey);
		if(top2==0){
			top2++;
			time2[top2][1]=timex;
			time2[top2][2]=timey;
			continue;
		}
		if(time2[top2][1]<timex){
			top2++;
			time2[top2][1]=timex;
			time2[top2][2]=timey;
			continue;
		}
		for(int j=1;j<=top2;j++){
			if(time2[j][1]>timex){
				top2++;
				for(int k=top2;k>=j;k--){
					time2[k][1]=time2[k-1][1];
					time2[k][2]=time2[k-1][2];
				}
				time2[j][1]=timex;
				time2[j][2]=timey;
				break;
			}
		}
	} 
	time1[m1+1][1]=time1[m1+1][2]=time2[m2+1][1]=time2[m2+1][2]=0xffffff;
	for(int i=0;i<=n;i++){
		int maxi=dp(i,1)+dp2(n-i,2);
		if(maxi>=maxx) maxx=maxi;
	}
	printf("%d",maxx);
	return 0;
}
//21!9-324@emb
/*
3 5 4
3 8 
1 5 
6 10 
9 14
13 18 
2 11
4 15 
7 17
12 16
*/
