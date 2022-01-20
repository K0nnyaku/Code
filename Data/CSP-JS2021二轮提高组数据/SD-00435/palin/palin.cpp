#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <map>
#include <vector>
#include <set>
using namespace std;
long long int a[1000005],b[1000005];
char s[1000005],cch[1000005];
int n;
int ff=0;
void dfs(int now,char ch,int l,int r) {
	s[now]=ch;
	if(ch=='R') {
		b[now]=a[r];
		r--;
	}
	if(ch=='L') {
		b[now]=a[l];
		l++;
	}
	if(now==n*2) {
		int f=1;
		for(int i=1; i<=n; i++) {
//			cout<<b[i]<<" ";
			if(b[i]!=b[2*n-i+1]) {
				f=0;
				break;
			}
		}
//		cout<<endl;
		if(f==1) {
			ff=1;
			for(int i=1;i<=n*2;i++) {
				cch[i]=s[i];
			}
//			cout<<endl;
		}
		return ;
	}
	dfs(now+1,'R',l,r);
	dfs(now+1,'L',l,r);
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n*2; i++) {
			cin>>a[i];
		}
		ff=0;
		dfs(0,'L',0,n*2);
		if(ff==1) {
			for(int i=1; i<=2*n; i++) {
				cout<<cch[i];
			}
			cout<<endl;
		} else {
			cout<<-1<<endl;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
