#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+6;
int n, ma, mb;
int ans1 = 0, ans2 = 0;

struct node {
	int s, e;
}a[N], b[N];

bool check2(int mid) {
	int q[100010];
	int l, r;
	l = r = 1;q[l] = 0;
	int cnt1 = 0, cnt2 = 0;
	for(int i = 1;i <= ma;i ++) {
		int t = q[l]; 
		while(a[t].e <= a[i].s && r >= l) t = q[++l];
		if(r - l + 1 < mid) q[++r] = i, cnt1 ++;
	}
	l = r = 1;
	for(int i = 1;i <= mb;i ++) {
		int t = q[l]; 
		while(b[t].e <= b[i].s && r >= l) t = q[++l];
		if(r - l + 1 < n - mid) q[++r] = i, cnt2 ++;
	}
	if(ans2 <= cnt1 + cnt2 || ans2 == 0) {
//		cout << cnt1 << " " << cnt2 << " " << mid << " " << 2 <<endl;
		ans2 = cnt1 + cnt2;
		return true; 
	}
//	cout << cnt1 << " " << cnt2 << " " << mid << " " << 2 <<endl;
	return false;
}

bool check1(int mid) {
	int q[100010];
	int l, r;
	l = r = 1;q[l] = 0;
	int cnt1 = 0, cnt2 = 0;
	for(int i = 1;i <= ma;i ++) {
		int t = q[l]; 
		while(a[t].e <= a[i].s && r >= l) t = q[++l];
		if(r - l + 1 < mid) q[++r] = i, cnt1 ++;
	}
	l = r = 1;
	for(int i = 1;i <= mb;i ++) {
		int t = q[l]; 
		while(b[t].e <= b[i].s && r >= l) t = q[++l];
		if(r - l + 1 < n - mid) q[++r] = i, cnt2 ++;
	}
	if(ans1 > cnt1 + cnt2 || ans1 == 0) {
//		cout << cnt1 << " " << cnt2 << " " << mid << " " << 1<<endl;
		if(ans1 == 0) {
			ans1 = cnt1 + cnt2;
		}
		return false; 
	}
//	cout << cnt1 << " " << cnt2 << " " << mid << " " << 1<< endl; 
	ans1 = cnt1 + cnt2;
	return true;
}

bool cmp(node a, node b) {
	return a.s < b.s;
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0), cout.tie(0);
	cin >> n >> ma >> mb;
	for(int i = 1;i <= ma;i ++) {
		cin >> a[i].s >> a[i].e;
	}
	for(int i = 1;i <= mb;i ++) {
		cin >> b[i].s >> b[i].e;
	}
	if(ma > mb) {
		swap(ma, mb), swap(a, b);
	}
	
	sort(a+1, a+1+ma, cmp);
	sort(b+1, b+1+mb, cmp);
	
	int l = 0, r = min(n, ma);
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check1(mid)) l = mid + 1;
		else r = mid - 1;
	}
	l = 0, r = min(n, ma);
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check2(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << max(ans1, ans2) ;
	return 0;
}
