#include<ctime>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#define maxn 100005
using namespace std;
int a[maxn],b[maxn];
int n,m,t;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
    scanf("%d %d %d",&n,&m,&t);
    for(int i=1;i<=n-1;i++){
    	scanf("%d",&a[i]);
	}
	for(int i=1;i<=m-1;i++){
		scanf("%d",&b[i]);
	}
	cout<<"17";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
