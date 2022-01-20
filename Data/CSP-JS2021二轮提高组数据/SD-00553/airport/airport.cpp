#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>
//#include <cmath>
//#include <cassert> // TODO: delete.
#include <set>

using namespace std;

const int _ = 200000 + 100;

int n, m1, m2;
struct flight_t{ int L, R, pri; } d1[_], d2[_];

struct event{ int type, fid, Ti; }T[_]; int tt = 0;

bool CMP0(const event & x, const event & y) { return x.Ti < y.Ti; }

bool CMP1(const flight_t & x, const flight_t & y) { return x.pri < y.pri; }

int main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &m1, &m2);
	for(int i = 1; i <= m1; i++) scanf("%d%d", &d1[i].L, &d1[i].R);
	for(int i = 1; i <= m2; i++) scanf("%d%d", &d2[i].L, &d2[i].R);
	
	set<int> Mex; 
	Mex.clear(); for(int i = 1; i <= n; i++) Mex.insert(i);
	tt = 0; for(int i = 1; i <= m1; i++) {
		++tt, T[tt].type = 1, T[tt].Ti = d1[i].L, T[tt].fid = i;
		++tt, T[tt].type = -1,T[tt].Ti = d1[i].R, T[tt].fid = i;
	}
	sort(T + 1, T + 1 + tt, CMP0);
	for(int i = 1; i <= tt; i++) {
		event &now = T[i];
		if(now.type == 1) {
			d1[now.fid].pri = (Mex.empty() ? (1e9) : (*Mex.begin()));
			if(!Mex.empty()) Mex.erase(d1[now.fid].pri);
		} else {
		//	if(Mex.find(d1[now.fid].pri) == Mex.end()); else cerr << "ERR " << d1[now.fid].pri << endl; 
			Mex.insert(d1[now.fid].pri);
		}
	}
	
//	for(int i = 1; i <= m1; i++) 
//		cerr << "(" << d1[i].L << ", " << d1[i].R << ") pri = " 
//			<< d1[i].pri << endl; 
//	
	Mex.clear(); for(int i = 1; i <= n; i++) Mex.insert(i);
	tt = 0; for(int i = 1; i <= m2; i++) {
		++tt, T[tt].type = 1, T[tt].Ti = d2[i].L, T[tt].fid = i;
		++tt, T[tt].type = -1,T[tt].Ti = d2[i].R, T[tt].fid = i;
	}
	sort(T + 1, T + 1 + tt, CMP0);
	for(int i = 1, exist = 0; i <= tt; i++) {
		event &now = T[i];
		if(now.type == 1) {
			d2[now.fid].pri = (Mex.empty() ? (1e9) : (*Mex.begin()));
			if(!Mex.empty()) Mex.erase(d2[now.fid].pri);
		} else {
			//if(Mex.find(d2[now.fid].pri) == Mex.end()); else cerr << "ERR " << d2[now.fid].pri << endl; 
			Mex.insert(d2[now.fid].pri);
		}
	}
//	cerr << "escape" << endl;
//	for(int i = 1; i <= m2; i++) 
//		cerr << "(" << d2[i].L << ", " << d2[i].R << ") pri = " 
//			<< d2[i].pri << endl;
//	
//	cerr << "done" << endl;
	sort(d1 + 1, d1 + 1 + m1, CMP1); 
	sort(d2 + 1, d2 + m2 + 1, CMP1);
	

//	cerr << "done" << endl;
	d1[m1 + 1].pri = 1e9;
	int p1 = m1 + 1, p2 = 0;
	int ans = 0;
	for(int N = n; N >= 0; N--) {
		int cnt1 = N, cnt2 = n - N;
		while(p1 - 1 >= 0 && d1[p1].pri > cnt1) p1--;
		while(p2 + 1 <= m2 && d2[p2 + 1].pri <= cnt2) p2++;
//		cerr << "N = " << N << " ans = " << p1 << " " << p2 << endl;
		ans = max(ans, p1 + p2);
	}
	printf("%d\n", ans);
	
	fclose(stdin); fclose(stdout);
	return 0;
}

