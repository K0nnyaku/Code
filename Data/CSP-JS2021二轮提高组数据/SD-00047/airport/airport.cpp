#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio> 
#include<string>
#include<queue>

using namespace std;

const int N = 100010;
int n, m1, m2;
int a1[N], b1[N], a2[N], b2[N], mx1 = -1, mx2 = -1;
int ans, ANS = -1;
int t1[N];
struct node{
	int a, b;
} aa1[N], aa2[N];
bool cmp(node x, node y){
	return x.a < y.a;
}
int lowbit(int x){
	return x & (-x);
}

void add1(int x, int y){
	for(int i = x; i <= mx1 + 2; i += lowbit(i)){
		t1[i] += y;
	}
}
void add2(int x, int y){
	for(int i = x; i <= mx2 + 2; i += lowbit(i)){
		t1[i] += y;
	}
}
int getsum(int x){
	int sum = 0;
	for(int i = x; i > 0; i -= lowbit(i)){
		sum += t1[i];
	}
	return sum;
}
void work1(int x){
	for(int i = 1; i <= m1; i++){
		if(getsum(aa1[i].a) + 1 <= x){
			ans++;
			add1(aa1[i].a, 1);
			add1(aa1[i].b, -1);
		}
	}
}
void work2(int x){
	for(int i = 1; i <= m2; i++){
		if(getsum(aa2[i].a) + 1 <= x){
			ans++;
			add2(aa2[i].a, 1);
			add2(aa2[i].b, -1);
		}
	}
}
int work3(){
	int cur = 0;
	for(int i = 1; i <= m1; i++){
		for(int j = aa1[i].a; j <= mx1 + 2; j+=lowbit(j)) t1[j]++;
		for(int j = aa1[i].b; j <= mx1 + 2; j+=lowbit(j)) t1[j]--;
		int cur1 = 0;
		for(int j = aa1[i].a; j > 0; j -= lowbit(j)) cur1+=t1[j];
		cur = max(cur, cur1);
	}
	return cur;
}
int work4(){
	int cur = 0;
	for(int i = 1; i <= m2; i++){
		for(int j = aa2[i].a; j <= mx2 + 2; j+=lowbit(j)) t1[j]++;
		for(int j = aa2[i].b; j <= mx2 + 2; j+=lowbit(j)) t1[j]--;
		int cur1 = 0;
		for(int j = aa2[i].a; j > 0; j -= lowbit(j)) cur1+=t1[j];
		cur = max(cur, cur1);
	}
	return cur;
}
int main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	cin >> n >> m1 >> m2;
	for(int i = 1; i <= m1; i++){
		cin >> aa1[i].a >> aa1[i].b;
		mx1 = max(mx1, aa1[i].b);
	}
	for(int i = 1; i <= m2; i++){
		cin >> aa2[i].a >> aa2[i].b;
		mx2 = max(mx2, aa2[i].b);
	}
	sort(aa1 + 1, aa1 + m1 + 1, cmp);
	sort(aa2 + 1, aa2 + m2 + 1, cmp);
	memset(t1, 0, sizeof(t1));
	int xx1 = work3();
	memset(t1, 0, sizeof(t1));
	int xx2 = work4();
	if(xx1 >= xx2){
		for(int i = 0; i <= min(n, xx2); i++){
			ans = 0;
			memset(t1, 0, sizeof(t1));
			work1(n - i);
			memset(t1, 0, sizeof(t1));
			work2(i);
			ANS = max(ANS, ans);
		}
	}else{
		for(int i = 0; i <= min(n, xx1); i++){
			ans = 0;
			memset(t1, 0, sizeof(t1));
			work1(i);
			memset(t1, 0, sizeof(t1));
			work2(n - i);
			ANS = max(ANS, ans);
		}
	}
	cout << ANS;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
