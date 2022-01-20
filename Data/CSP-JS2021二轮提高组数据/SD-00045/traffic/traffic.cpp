#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int M=100005;
int n,m,t,a,minn;
int val[M],num[M];
bool col[M];
bool flag;
int main(){
	freopen("traffc.in","r",stdin);
	freopen("traffc.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=n-1;i++)for(int j=1;j<=m;j++)cin>>a;
	for(int i=1;i<=n;i++)for(int j=1;j<=m-1;j++)cin>>a;
	for(int i=1;i<=t;i++){
		cin>>a;
		for(int j=1;j<=a;j++){
			cin>>val[j]>>num[j]>>col[j];
			if(j>=2)if(col[j]==col[j-1])flag=1;
			minn=min(minn,val[j]);
		}
	}
	if(flag)cout<<0<<endl;
	else cout<<minn<<endl;
	return 0;
}

