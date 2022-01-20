#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int ans1=0,ans2=0;
struct node {
	int ar;
	int la;
};
struct node1 {
	bool f=0;
	int be;
	int ov;
};
node a[100001];
node b[100001];
node1 vis1[10001];
node1 vis2[10001];
int zans1=-1,zans2=-1;
int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	while(q--){
		int opt;
		for(int i=1;i<=m;++i)cin>>opt;
		cout<<opt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
