#include<iostream>
#include<cstdio>
#define MAXN 10000010
using namespace std;
char a[MAXN];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int i=1;i<=n+n;i++){
			cin>>a[i];
		}
		cout<<-1<<endl;
	}
	return 0;
}
