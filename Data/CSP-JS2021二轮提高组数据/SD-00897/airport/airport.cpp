#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 100010
using namespace std;

int n,m1,m2;
int tmp1,tmp2;

struct zhs{
	int st;
	int en;
}e[3][N];

bool cmp(zhs x,zhs y){
	return x.st < y.st;
}

void work(){
	tmp1 = 1;
	int minn1 = e[1][1].en;
	for(int i=2;i<=m1;i++){
		if(e[1][i].st>minn1){
			minn1 = min(minn1,e[1][i].en);
		}
		else{
			tmp1++;
			minn1 = min(minn1,e[1][i].en);
		}
	}
	tmp2 = 1;
	int minn2 = e[2][1].en;
	for(int i=2;i<=m2;i++){
		if(e[2][i].st>minn2){
			minn2 = min(minn2,e[2][i].en);
		}
		else{
			tmp2++;
			minn2 = min(minn2,e[2][i].en);
		}
	}
}

int work1(int k){
	if(k == 0) return 0;
	int tmp = 1,minn_=e[1][1].en;
	int x = 1;
	for(int i=2;i<=m1;i++){
		if(e[1][i].st>minn_){
			minn_ = min(minn_,e[1][i].en);
			x++;
		}
		else{
			if(tmp != k){
				tmp++;
				minn_ = min(minn_,e[1][i].en);
				x++;
			}
		}
	}
	return x;
}

int work2(int k){
	if(k == 0) return 0;
	int tmp = 1,minn_=e[2][1].en;
	int x = 1;
	for(int i=2;i<=m2;i++){
		if(e[2][i].st>minn_){
			minn_ = min(minn_,e[2][i].en);
			x++;
		}
		else{
			if(tmp != k){
				tmp++;
				minn_ = min(minn_,e[2][i].en);
				x++;
			}
		}
	}
	return x;
}

void baoli(){
	int ans = 0;
	for(int l=0;l<=n;l++){
		int r = n - l;
		ans = max(work1(l)+work2(r),ans);
	}
	printf("%d",ans);
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&e[1][i].st,&e[1][i].en);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&e[2][i].st,&e[2][i].en);
	}
	sort(e[1]+1,e[1]+m1+1,cmp);
	sort(e[2]+1,e[2]+m2+1,cmp);
	work();
	if(n>=tmp1+tmp2){
		printf("%d\n",m1+m2);
	}
	if(n<tmp1 && n<tmp2){
		baoli();
	}
	if(n>=tmp1 && n<tmp2){
		printf("%d\n",m1+work2(n - tmp1));
	}
	if(n<tmp1 && n>=tmp2){
		printf("%d\n",m2+work1(n - tmp2));
	}
	if(n>=tmp1 && n>=tmp2 && n<tmp1+tmp2){
		printf("%d\n",max(m1+work2(n - tmp1),m2+work1(n - tmp2)));
	}
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
*/
/*
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
