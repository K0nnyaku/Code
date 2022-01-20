#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 1e5 + 10;
int n,m1,m2;
struct Air_ {
	int l,r;
}a[MAXN],b[MAXN]; 
int top = 0,Sum = 0;
priority_queue <int> qp;
int read()
{
	int s = 0,f = 0;char ch = getchar();
	while(!isdigit(ch)) f |= ch == '-',ch = getchar();
	while(isdigit(ch)) s = (s << 3) + (s << 1) + (ch ^ 48),ch = getchar();
	return f ? -s : s;
}
bool CMP(Air_ x,Air_ y) {
	return x.l < y.l;
}
void Solve1()
{
	int Ans = 0;
	sort(a + 1,a + m1 + 1,CMP);
	sort(b + 1,b + m2 + 1,CMP);
	for(int i = 0;i <= n;i ++) {
		int A = i,B = n - i;
		int res = 0,ret = 0;
		for(int j = 1;j <= m1;j ++) {
			if(A == 0) break;
			if(qp.size() != A) {
				qp.push(-a[j].r);
				res ++;
			}
			else {
				if(a[j].l > -qp.top()) {
					qp.pop();
					qp.push(-a[j].r);
					res ++;
				}
			}
		}
		while(!qp.empty()) qp.pop();
		for(int j = 1;j <= m2;j ++) {
			if(B == 0) break;
			if(qp.size() != B) {
				qp.push(-b[j].r);
				ret ++;
			}
			else {
				if(b[j].l > -qp.top()) {
					qp.pop();
					qp.push(-b[j].r);
					ret ++;
				}
			}
		} 
//		cout << res << " " << ret << endl;
		Ans = max(Ans,res + ret);
		while(!qp.empty()) qp.pop();
	}
	printf("%d\n",Ans);
	return;
}
int Calc(int A,int B)
{
	int res = 0,ret = 0,Ans = 0;
	for(int j = 1;j <= m1;j ++) {
		if(A == 0) break;
		if(qp.size() != A) {
			qp.push(-a[j].r);
			res ++;
		}
		else {
			if(a[j].l > -qp.top()) {
				qp.pop();
				qp.push(-a[j].r);
				res ++;
			}
		}
	}
	while(!qp.empty()) qp.pop();
	for(int j = 1;j <= m2;j ++) {
		if(B == 0) break;
		if(qp.size() != B) {
			qp.push(-b[j].r);
			ret ++;
		}
		else {
			if(b[j].l > -qp.top()) {
				qp.pop();
				qp.push(-b[j].r);
				ret ++;
			}
		}
	} 
	Ans = max(Ans,res + ret);
	while(!qp.empty()) qp.pop();
	return Ans;
}
bool check(int Num)
{
	bool f = false;
	int ans1 = Calc(Num,n - Num);
	int ans2 = Calc(n - Num,Num);
	if(ans1 > Sum || ans2 > Sum) f = true;
	Sum = max(Sum,max(ans2,ans1));
	if(f) return true;
	else return false;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n = read(),m1 = read(),m2 = read();
	for(int i = 1;i <= m1;i ++) {
		a[i].l = read(),a[i].r = read();
	}
	for(int i = 1;i <= m2;i ++) {
		b[i].l = read(),b[i].r = read();
	}
	if(n <= 5000 && m1 + m2 <= 5000) {
		Solve1();
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	sort(a + 1,a + m1 + 1,CMP);
	sort(b + 1,b + m2 + 1,CMP);
	int L = 0,R = n;
	while(L <= R) {
		int mid = (L + R) >> 1;
		if(check(mid)) L = mid + 1;
		else R = mid - 1; 
	}
	printf("%d\n",Sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 5 4 
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
