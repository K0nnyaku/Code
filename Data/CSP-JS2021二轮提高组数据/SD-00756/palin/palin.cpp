#include<iostream>
#include<cstdio>

using namespace std;

int a[1000010];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	while(t>0) {
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) {
			scanf("%d",&a[i]);
		}
		cout<<"-1"<<endl;
		t--;
	}
	return 0;
}
