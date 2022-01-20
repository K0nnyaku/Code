#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
priority_queue<int,vector<int>,greater<int> > q;//ok
int t,n;
int a[500001];
int ne[500001][4];
int st[500001];
int ans[500001];
int res[500001];

bool flag=1;

bool check() {
	for(int i=1; i<=n/2; i++) {
		if(res[i]!=res[n-i+1]) return false;
	}
	return true;
}


void py() {
	for(int i=1; i<=n; i++) {
		ans[i]=st[i];
		//	cout << ans[i] << " ";
	}
	//cout << endl;
}

void work() {
	if(flag==1) {
		for(int i=1; i<=n; i++) {
			ans[i]=st[i];
		}
		flag=0;
	} else {
		for(int i=1; i<=n; i++) {
			if(st[i]<ans[i]) {
				py();
				break;
			}
			if(st[i]>ans[i]) {
				break;
			}
		}
		//	cout << endl;
	}
}


void search(int sp,int l,int r,bool flag) {
	if(flag==0) {
		st[sp]=flag;
		res[sp]=a[l];
		if(sp==n) {
			if(check())work();
		} else {
			search(sp+1,l+1,r,false);
			search(sp+1,l+1,r,true);
		}

	} else {
		st[sp]=flag;
		res[sp]=a[r];
		if(sp==n) {
			if(check()) {
				work();
			}
		} else {
			search(sp+1,l,r-1,false);
			search(sp+1,l,r-1,true);
		}

	}
}

int main() {
//	srand((int)time(NULL));
//	for(int i=1; i<=1000; i++) {
//		cout << rand() << endl;
//	}
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin >> t;
	while(t--) {
		flag=1;
		cin >> n;
		n=2*n;
		for(int i=1; i<=n; i++) {
			cin >> a[i];
		}
		//int l=1,r=n;
		//cout << 1 << endl;
		search(1,1,n,false);
		search(1,1,n,true);
		if(flag==1) {
			cout << "-1" << endl;
			continue;
		}
		for(int i=1; i<=n; i++) {
			if(ans[i]==0) cout << 'L';
			else cout << 'R';
		}
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);


	return 0;
}
/*
21!9-324@emb




*/
