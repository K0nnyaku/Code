#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#define MAXN 100010
using namespace std;
int m,m1,m2;
int a[3][MAXN]={0},b[3][MAXN]={0};
int t[MAXN],time[MAXN];
int mid=0;
int main(){
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	//int m,m1,m2;//分别表示廊桥的个数、国内航班飞机的数量、国际航班飞机的数量
	//int a[2][MAXN]={0},b[2][MAXN]={0};//表示一架国内航班飞机的抵达、离开时刻//表示一架国际航班飞机的抵达、离开时刻
	int g1,g2,q1,q2;q1=m1;q2=m2;
	int time[MAXN]={0};
	cin>>m>>m1>>m2;
	if(q1!=0&&q2!=0){
		for(int i=0;i<m1;i++){
			cin>>a[1][i]>>b[1][i]; 
			time[i]=b[1][i]-a[1][i];
			q1--;g1++;
		}
		for(int j=0;j<m2;j++){
			cin>>a[2][j]>>b[2][j];
			time[g1+j]=b[2][j]-a[2][j];
			q2--;g2++;
		}
	}
	int cs=(g1+g2)%2;
	if(m<g1+g2){
		int mid;
		if(cs==0){
			mid=(g1+g2)/2;
    	}else mid=((g1+g2)/2)>>1;
		
	}else cout<<g1+g2<<endl;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
