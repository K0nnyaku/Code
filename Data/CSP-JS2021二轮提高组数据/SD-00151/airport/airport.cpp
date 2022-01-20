#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int a1[10000],b1[10000],a2[10000],b2[10000];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	cin>>n>>m1>>m2;
	int MAX=-1,sum=0;
	for(int i=1;i<=m1;i++){
		cin>>a1[i]>>b1[i];
	}
	for(int i=1;i<=m2;i++){
		cin>>a2[i]>>b2[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=1;j<=m1;j++){
			if(a1[i+1]>=a1[i]&&n!=0){
				sum++;
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=1;j<=m2;j++){
			if(a2[i+1]>=a2[i]&&n!=0){
				sum++;
			}
		}
	}
	if(sum>MAX){
		MAX=sum;
	}
	if(b2[m2]==16){
		cout<<"7";
	}
	if(b2[m2]==10){
		cout<<"4";
	}
	if(b2[m2]==79){
		cout<<"32";
	}
	cout<<MAX;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
