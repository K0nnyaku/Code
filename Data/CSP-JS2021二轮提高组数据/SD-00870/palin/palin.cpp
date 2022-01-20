#include<iostream>
#include<cstdio>
using namespace std;
int a[101],b[101],n;
char c[101],d[101];
bool f=0;
int sea(int s,int l,int e) {
	if(f==1) return 0;
	if(s==(n*2)+1) {
		bool f1=0;
		for(int i=1; i<=n; i++) {
			if(b[i]!=b[(n*2)+1-i]) {
				f1=1;
				break;
			}
		}
		if(f1==1) return 0;
		if(f!=1) {
			f=1;
			for(int i=0; i<=(n*2)-1; i++) cout<<d[i];
			cout<<endl;
		}
		return 0;
	}
	b[s]=a[l],d[s-1]='L',sea(s+1,l+1,e);
	if(f==1) return 0;
	b[s]=a[(n*2)-e],d[s-1]='R',sea(s+1,l,e+1);
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	for(int i=0; i<=100; i++) c[i]='z';
	int t;
	cin>>t;
	while(t>0) {
		t--;
		scanf("%d",&n);
		for(int i=1; i<=n*2; i++) {
			scanf("%d",&a[i]);
		}
		sea(1,1,0);
		if(f==0) printf("-1\n");
		f=0;
	}
	return 0;
}
