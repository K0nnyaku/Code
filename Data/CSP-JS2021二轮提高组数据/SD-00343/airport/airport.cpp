#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<iostream>
#include<queue>
#define mp make_pair
using namespace std;
struct node{
	int a, b;
	bool operator < (const node &x)const{
		return a < x.a;
	}
}e1[100010], e2[100010];
int n, m1, m2, cnt, tot;
int a[500010];
map<int,int>p;
void lsh(int x){
	p[x] = ++tot;
}
int ji1[100010], ji2[100010];
int ct1[100010], ct2[100010];
int id1[400010], id2[400010];
int co1[400010], co2[400010];
int maxx, maxy, ans, qz1, qz2;
priority_queue<pair<int, int> >q1, q2;
signed main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d",&n, &m1, &m2);
	ans = m1 + m2 + 5;
	for(int i = 1; i <= m1; i++)
		scanf("%d%d", &e1[i].a, &e1[i].b), a[++cnt] = e1[i].a, a[++cnt] = e1[i].b;
	for(int i = 1; i <= m2; i++)
		scanf("%d%d", &e2[i].a, &e2[i].b), a[++cnt] = e2[i].a, a[++cnt] = e2[i].b;
	sort(a + 1, a + 1 + cnt);
	a[0] = -1;
	maxx = a[cnt]; 
	for(int i = 1; i <= cnt; i++){
		if(a[i] != a[i - 1])
			lsh(a[i]);
	}
	for(int i = 1; i <= m1; i++)
		e1[i].a = p[e1[i].a], e1[i].b = p[e1[i].b];
	for(int i = 1; i <= m2; i++)
		e2[i].a = p[e2[i].a], e2[i].b = p[e2[i].b];
	for(int i = 1; i <= m1; i++)
		ji1[e1[i].a] = 1, ji1[e1[i].b] = -1, id1[e1[i].a] = id1[e1[i].b] = i;
	for(int i = 1; i <= m2; i++)
		ji2[e2[i].a] = 1, ji2[e2[i].b] = -1, id2[e2[i].a] = id2[e2[i].b] = i;
	for(int i = 1; i <= maxx; i++){
		if(ji1[i] == 1){
			if(!q1.empty()){
				int la1 = q1.top().second;
				co1[id1[i]] = co1[la1];
				q1.pop();
				ct1[co1[id1[i]]]++;
			}
			else{
				co1[id1[i]] = qz1 + 1;
				ct1[co1[id1[i]]]++;
			}
		}
		if(ji1[i] == -1)
			q1.push(mp(-co1[id1[i]], id1[i]));
		qz1 += ji1[i];
		if(ji2[i] == 1){
			if(!q2.empty()){
				int la2 = q2.top().second;
				co2[id2[i]] = co2[la2];
				q2.pop();
				ct2[co2[id2[i]]]++;
			}
			else{
				co2[id2[i]] = qz2 + 1;
				ct2[co2[id2[i]]]++;
			}
		}
		if(ji2[i] == -1)
			q2.push(mp(-co2[id2[i]], id2[i]));
		qz2 += ji2[i];
	}
	for(int i = m1; i >= 0; i--)
		ct1[i] += ct1[i + 1];
	for(int i = m2; i >= 0; i--)
		ct2[i] += ct2[i + 1];
	for(int i = 0; i <= n; i++){
		ans = min(ans, ct1[i + 1] + ct2[n - i + 1]);
//		cout << ct1[i + 1]<<" "<<ct2[n - i + 1]<<"\n";
	}
	printf("%d\n", m1 + m2 - ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
