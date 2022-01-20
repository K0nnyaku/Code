#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
using namespace std;
int n,m1,m2;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	int  jinnei[100005],jinwai[100005],chunei[100005],chuwai[100005],shu[100005];
	for(int i=1;i<=m1;i++){
		cin>>jinnei[i]>>chunei[i];
	}
	for(int i=1;i<=m2;i++){
		cin>>jinwai[i]>>chuwai[i]; 
	}
	int mmax=0;
	for(int q=0;q<n;q++){
		int max1=0;
		int max2=0;
		for(int i=1;i<=m1;i++){
			for(int j=jinnei[i];j<=chunei[i];j++){
				shu[j]++;
			}
			if(shu[i]>max1){
				max1=shu[i];
			}
			shu[i]=0;
		}
		for(int i=1;i<=m2;i++){
			for(int j=jinwai[i];j<=chuwai[i];j++){
				shu[j]++;
			}
			if(shu[i]>max2){
				max2=shu[i];
			}
			shu[i]=0;
		}
		if(mmax<max1+max2){
			mmax=max1+max2+1;
		}
	}
	cout<<mmax;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
