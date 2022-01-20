#include<bits/stdc++.h>

using namespace std;

template<typename _T>
inline void read(_T &x)
{
	x = 0;int f = 1;char s = getchar();
	while(s < '0'||s > '9'){f=1;if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<3)+(x<<1)+s-'0';s = getchar();}
	x *= f;
}

const int np = 2e5 + 5;
int b[np],num;

struct Air{
	int l,r;
	friend bool operator<(Air a,Air b)
	{
		return a.l < b.l;
	}
}gn[np],gj[np]; 
int n,m1,m2;
set<int> s;

inline int judging(int x)
{
	int lq1 = x,lq2 = n-x;
	s.clear();
	int l=0;
	int ans(0);
	for(int i=1;i <= num;i ++)
	{
		while(s.size() && (*s.begin()) <= i) s.erase(s.begin());
		while(l + 1 <= m1 && gn[l + 1].l <= i) {
			l++;
			if((int)s.size() < lq1) s.insert(gn[l].r),ans ++;
		}
	}
//	int Cans = ans;
	s.clear();
	l = 0;
	for(int i=1;i <= num;i ++)
	{
		while(s.size() && (*s.begin()) <= i) s.erase(s.begin());
		while(l + 1 <= m2 && gj[l + 1].l <= i) {
			l ++;
			if((int)s.size() < lq2) s.insert(gj[l].r),ans ++;
		}
	}
	s.clear();
//	return Cans;
	return ans;//-Cans - Cans;
}

signed main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n);
	read(m1);
	read(m2);
	num = 0;
//	printf("%d %d\n",m1,m2);
	for(int i=1;i <= m1;i ++) read(gn[i].l),read(gn[i].r),b[++num] = gn[i].r,b[++num] = gn[i].l;
	for(int i=1;i <= m2;i ++) read(gj[i].l),read(gj[i].r),b[++num] = gj[i].r,b[++num] = gj[i].l;
	
	sort(b + 1,b + 1 + num);
	int *be = b + 1;
	int *en = unique(b + 1,b + 1 + num);
	num = en-b-1;
	for(int i=1;i <= m1;i ++)
	{
		gn[i].l = lower_bound(be,en,gn[i].l) - b;
		gn[i].r = lower_bound(be,en,gn[i].r) - b;
	}
	for(int i=1;i <= m2;i ++)
	{
		gj[i].l =  lower_bound(be,en,gj[i].l) - b;
		gj[i].r =  lower_bound(be,en,gj[i].r) - b;
	}
	
	sort(gn + 1,gn + 1 + m1);
	sort(gj + 1,gj + 1 + m2);
	
	int l = 0,r = n;
	int maxn=0;
//	while(r-l+1 >= 10)
//	{
//		int len = (r-l+1)/3;
//		int lmid = l + len;
//		int rmid = r - len;
//		int ansl = judging(lmid),ansr = judging(rmid);
////		printf("%d %d\n",ansl,ansr);
//		maxn = max(maxn,ansl);
//		maxn = max(maxn,ansr);
//		if(ansl < ansr){
//			l = lmid + 1;
//		}
//		else{
//			r = rmid - 1;
//		}
//	}

	for(int i=l;i <= r;i ++)
	{
		int op = judging(i);
		maxn = max(maxn,op);
//		printf("%d ",op);
	}
	printf("%d\n",maxn);
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

2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10


*/

