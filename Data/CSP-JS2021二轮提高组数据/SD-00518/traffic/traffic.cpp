#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <ctime>

using namespace std;

int read(){
	int k=1,x;
	char c=getchar();
	while (c<'0'||c>'9'){
		if(c=='-'){
			k=-1;
			c=getchar();
		}
	}
	while (c>='0'&&c<='9'){
		x=x<<3+x<<1+c^48;
		c=getchar();
	}
	return x*k;
}

int n,m,T,a,b;

int main(){
	freopen("traffc.in","r",stdin);
	freopen("traffc.out","w",stdout);
	int c;
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<n;i++)
	for(int j=1;j<=m;j++) 
	cin>>a;
	for(int i=1;i<=n;i++)
	for(int j=1;j<m;j++)
	cin>>a;
	while(T--)
	cin>>a>>b;
	cout<<c;
	return 0;
}  
