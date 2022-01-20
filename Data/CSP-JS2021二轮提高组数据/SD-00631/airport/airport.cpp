#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n , m1 , m2;
struct node{
	int l , r;
}a[N] ,b[N];
bool operator < (node x , node y) {
	return x.l < y.l;
} 
int e[N] ,  col[N];
int work(int k) {
	memset(col , 0 , sizeof(col));
	int ans = 0;
	for(int i = 1; i <= m1; i++) {
		if(col[a[i].l] < k) {
			ans++;
			for(int j = a[i].l; j <= a[i].r; j++) {
				col[j]++;
				
			}
		}
	}
	return ans;
}

int work2(int k) {
	memset(col , 0 , sizeof(col));
	int ans = 0;
	for(int i = 1; i <= m2; i++) {
		if(col[b[i].l] < k) {
		ans++;
			for(int j = b[i].l; j <= b[i].r; j++) {
				col[j]++;
				
			}
		}
	}
	return ans;
}
int main() {
	freopen("airport.in" , "r" , stdin);
	freopen("airport.out", "w" , stdout);
	double eee = time(0);
	scanf("%d%d%d" , &n , &m1 , &m2);
	
	for(int i = 1; i <= m1; i++) {
		scanf("%d%d" , &a[i].l , &a[i].r);
	}
	for(int i = 1; i <= m2; i++) {
		scanf("%d%d" , &b[i].l , &b[i].r);
	}
	
	
	sort(a + 1, a + m1 + 1);
	sort(b + 1 , b + m2 + 1);
	int cnt = 0;
	for(int i = 1; i <= m1; i++)
		e[++cnt] = a[i].l , e[++cnt] = a[i].r;
	sort(e + 1 , e + cnt + 1);
	for(int i = 1; i <= m1; i++) {
		a[i].l = lower_bound(e , e + cnt + 1, a[i].l) - e;
		a[i].r = lower_bound(e , e + cnt + 1, a[i].r) - e;
	}
	
	cnt = 0;
	for(int i = 1; i <= m2; i++)
		e[++cnt] = b[i].l , e[++cnt] = b[i].r;
		sort(e + 1 , e + cnt + 1);
	for(int i = 1; i <= m2; i++) {
		b[i].l = lower_bound(e , e + cnt + 1, b[i].l) - e;
		b[i].r = lower_bound(e , e + cnt + 1, b[i].r) - e;
	}
	
	int sum = 0;
	if(n <= 5000) {
		for(int k = 0; k <= n; k++) {
			int j = n - k;
			sum = max(sum , work(k) + work2(j));
		}		
	}
	else {
		int mid = n / 2;
		sum = work(mid) + work2(n - mid);
		for(int ud = 1; ud <= 200; ud++) {
			for(int i = max(0 , mid - 5); i <= min(n , mid + 5); i++) {
				int qe = work(i) + work2(n - i);
				if(qe > sum)mid = i , sum = qe;

			}
		}
		
	}
	printf("%d\n" , sum);
	return 0;
} 
