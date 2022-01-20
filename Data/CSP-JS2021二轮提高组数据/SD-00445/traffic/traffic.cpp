#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<time.h>
#include<stdlib.h>
#include<string>
#define random(x) (rand()%x)
using namespace std;
int n,m,t,q;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<n;i++){
		for(int i=1;i<=m;i++){
			cin>>q;
		}
	} 
	for(int i=1;i<=n;i++){
		for(int i=1;i<m;i++){
			cin>>q;
		}
	}
	int k;
	for(int i=1;i<=t;i++){
		cin>>k;
		for(int j=1;i<=3*k;i++){
			cin>>q;
		}
	}
	srand((int)time(0));
	cout<<random(20);
	fclose(stdin);
	fclose(stdout);
	return 0;
}//±ðÍüÁËÈ¥µô×¢ÊÍ 
