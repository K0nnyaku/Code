#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
using namespace std;
const int maxn = 100010;
int k, n1, n2;
pair<int, int> a[maxn], b[maxn];//first:in second:out
int worka(int n, int k) {
	if(k == 0) {
		return 0;
	}
	set<pair<int, int> > Q;//front:small back:big
						   //first:out second:in
	Q.clear();
	int ret = 0;
	for(int i = 1; i <= n; ++i) {
		while(!Q.empty()) {
			if((*Q.begin()).first < (a[i]).first) {//ouy<in
//				cout << (*Q.begin()).first  << '-' << (*Q.begin()).second << endl;
				Q.erase(Q.begin());
			} else {
				break;
			}
		}
		if(Q.size() < k) {
			Q.insert(make_pair((a[i]).second, (a[i]).first));
			++ret;
			continue; 
		}
	}
	return ret;
}

int workb(int n, int k) {
	if(k == 0) {
		return 0;
	}
	set<pair<int, int> > Q;//front:small back:big
						   //first:out second:in
	Q.clear();
	int ret = 0;
	for(int i = 1; i <= n; ++i) {
		while(!Q.empty()) {
			if((*Q.begin()).first < (b[i]).first) {//ouy<in
//				cout << (*Q.begin()).first  << '-' << (*Q.begin()).second << endl;
				Q.erase(Q.begin());
			} else {
				break;
			}
		}
		if(Q.size() < k) {
			Q.insert(make_pair((b[i]).second, (b[i]).first));
			++ret;
			continue; 
		}
	}
	return ret;
}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	cin >> k >> n1 >> n2;
	for(int i = 1; i <= n1; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	for(int i = 1; i <= n2; ++i) {
		cin >> b[i].first >> b[i].second;
	}
	sort(a + 1, a + 1 + n1);
	sort(b + 1, b + 1 + n2);
	
	if(k <= 5000) 
	{
		int ans = 0;
		for(int i = 0; i <= k; ++i) {
			ans = max(worka(n1, i) + workb(n2, k - i), ans);
		}
		cout << ans << endl;
	} else {
		int l = 0, r = k, ret = -1;
		while(l < r) {
			int thir = (r - l) / 3;
//			cout << l << '-' << r << '-' << thir<< endl;
			int ansl = worka(n1, l + thir) + workb(n2, k - l - thir);
			int ansr = worka(n1, r - thir) + workb(n2, k - r + thir);
			ret = max(ret, max(ansl, ansr));
			if(worka < workb) {
				if(l == l + thir) {
					++l;
				}
				l = l + thir;
			} else {
				if(r == r - thir) {
					--l;
				}
				r = r - thir;
			}
		}
		cout << ret << endl;
	}
//	cout << workb(n2, 0) ;
//	cout << ' ' << workb(n2, 1) << ' ';
//	cout << workb(n2, 2) << ' '
//<< workb(n2, 3) << ' ' << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}










