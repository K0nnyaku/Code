#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#define ri register int
#define ll long long

using namespace std;

template <class T> void read(T&x){
	x = 0;
	int w = 0;
	char g = getchar();
	while(!isdigit(g)){
		w = (g == '-');
		g = getchar(); 
	}
	while(isdigit(g)){
		x = (x << 3) + (x << 1) + (g xor 48);
		g = getchar();
	}
	x = w?-x:x;
	return;
}

int n,m1,m2,ans;
struct air{
	int a,b;
}p[100005],q[100005];

bool cmp(air x,air y){
	return x.a < y.a;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout); 
	read(n),read(m1),read(m2);
	for(ri i = 1; i <= m1; i++)
		read(p[i].a),read(p[i].b);
	for(ri i = 1; i <= m2; i++)
		read(q[i].a),read(q[i].b);
	sort(p+1,p+1+m1,cmp);
	sort(q+1,q+1+m1,cmp); 
	for(ri i = 0; i <= n; i++){
		int j = n-i, sum = 0,mid = 0;
		priority_queue<int,vector<int>,greater<int> >pq;
		for(ri k = 1; k <= m1; k++){
//			cout << "0\n";
			while(!pq.empty()&& pq.top() < p[k].a ){
				pq.pop();
				mid--;
			}
			if(mid < i){
				sum++;
				mid++;
				pq.push(p[k].b);
			}
		}
		mid = 0;
		while(!pq.empty()) pq.pop();
		for(ri k = 1; k <= m2; k++){
			while(!pq.empty() && pq.top() < q[k].a){
				pq.pop();
				mid--;
			}
			if(mid < j){
				sum++;
				mid++;
				pq.push(q[k].b);
			}
		}
		ans = max(ans,sum);
	}
	cout << ans;
	return 0;
} 
