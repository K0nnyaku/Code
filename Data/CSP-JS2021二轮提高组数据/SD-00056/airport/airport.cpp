#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 9;
int n, m1, m2;
struct plane{
	int l, r;
}a[N], b[N];
bool cmp(plane x, plane y){
	if(x.l == y.l) return x.r < y.r;
	return x.l < y.l;
}
int t1[N], t2[N], ans;

int f(int d){
	int num1 = d, num2 = n - d;
	int tmp = 0, cnt1 = 0, cnt2 = 0;
	for(int i = 1; i <= m1; i++){
		bool flag = 1;
		for(int j = 1; j <= cnt1; j++){
			if(t1[j] < a[i].l){
				t1[j] = a[i].r;
				flag = 0;
				tmp++;
				break;
			}
		}
		if(cnt1 < num1 && flag){
			t1[++cnt1] = a[i].r;
			tmp++;
		}
	}
	for(int i = 1; i <= m2; i++){
		bool flag = 1;
		for(int j = 1; j <= cnt2; j++){
			if(t2[j] < b[i].l){
				t2[j] = b[i].r;
				flag = 0;
				tmp++;
				break;
			}
		}
		if(cnt2 < num2 && flag){
			t2[++cnt2] = b[i].r;
			tmp++;
		}
	}
	return tmp;
//	res = max(res, tmp);
}
bool check(int d){
	int res = -0x3f3f3f3f;
	int num1l = 0, num1r = n, mid1, mid2, num2;
	while(num1l <= num1r){
		mid1 = num1l + (num1r - num1l) / 3;
		mid2 = num1l + 2 * (num1r - num1l) / 3;
		int y1 = f(mid1);
		int y2 = f(mid2);
		if(y1 <= y2){
			num1l = mid1 + 1;
		}
		else{
			num1r = mid2;
		}
		res = max(y1, y2);
		if(num1l == num1r) break;
	}
	res = max(f(num1l), res);
	if(res > d){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &m1, &m2);
	for(int i = 1; i <= m1; i++){
		scanf("%d%d", &a[i].l, &a[i].r); 
	}
	for(int i = 1; i <= m2; i++){
		scanf("%d%d", &b[i].l, &b[i].r);
	}
	sort(a + 1, a + m1 + 1, cmp);
	sort(b + 1, b + m2 + 1, cmp);
	int l = 0, r = m1 + m2, mid;
	while(l < r){
		mid = (r - l) / 2 + l;
		if(check(mid)){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	printf("%d", l);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
