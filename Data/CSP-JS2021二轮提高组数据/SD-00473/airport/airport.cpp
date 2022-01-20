#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<bits/stdc++.h> 
using namespace std;
int aa[111111],sa,sb,n,m1,m2,sum1,sum2,bb[111111],maxn=-111;
struct node{
	int dao,li;
}a[111111],b[111111];
void dfs(int sum1,int ss){
	if(sum1==n+1){
		return ;
	}
	if(sum1!=0){
		for(int i=1;i<=m1;i++){
		for(int j=1;j<=sum1;j++){
			if(a[i].dao>aa[j]){
				sa++;
				aa[j]=a[i].li;
				break;
			}
		}
    }
	}
	if(n-sum1!=0){
		for(int i=1;i<=m2;i++){
		for(int j=1;j<=n-sum1;j++){
			if(b[i].dao>bb[j]){
				sb++;
				bb[j]=b[i].li;
				break;
			}
		}
	}
	}
	ss=sa+sb;
	if(ss==m1+m2){
		maxn=ss;
		return ;
	}
	maxn=max(ss,maxn);	
	sa=0;sb=0;
	memset(aa,0,sizeof(aa));
	memset(bb,0,sizeof(bb));
	dfs(sum1+1,ss); 
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a[i].dao>>a[i].li;
	}
	for(int i=1;i<=m2;i++){
		cin>>b[i].dao>>b[i].li;
	}
	dfs(0,0);
	cout<<maxn;
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
12 16*/
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

