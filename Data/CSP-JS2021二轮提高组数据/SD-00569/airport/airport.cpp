#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1e5 + 7;
inline int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int n;
typedef pair<int,int> poi;
//vector<poi> pp[2][maxn];
struct que{
	int m,an[maxn],s[maxn],tot = 0;
	poi wai[maxn];
	priority_queue <poi,vector<poi>,greater<poi> >st1,st2;
	//不可用的，可用的 
	void work(){
		sort(wai + 1,wai + m + 1);
		an[0] = 0;
		s[++tot] = 1;
		st1.push(make_pair(wai[1].second,1));
		
		for(int i = 2;i <= m; ++i){
			poi t;
			while(!st1.empty() && st1.top().first < wai[i].first){
				t = st1.top();
				st1.pop();
				st2.push(make_pair(t.second,t.first));
			}
			if(!st2.empty()) {
				poi now = st2.top();
				st2.pop();
				s[now.first]++;
				st1.push(make_pair(wai[i].second,now.first));
			}
			else if(tot < n){
				s[++tot] = 1;
				st1.push(make_pair(wai[i].second,tot));
			}
		}
		for(int i = 1;i <= n; ++i) an[i] = an[i - 1] + s[i];
		return ;
	}
}q[2];


void init(){
	n = read();
	q[0].m = read();q[1].m = read();
	for(int j = 0;j <= 1; ++j){
		for(int i = 1;i <= q[j].m; ++i){
			q[j].wai[i].first = read();
			q[j].wai[i].second = read();
		}
	}
	return ;
}

void print(){
	int ans = 0;
	for(int i = 0;i <= n; ++i){
	//	cout<<q[0].an[i]<<" "<<q[1].an[n - i]<<endl;
		ans = max(ans,q[0].an[i] + q[1].an[n - i]);
	}
	printf("%d\n",ans);
	return ;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	init();
	q[0].work();
	q[1].work();
	print();
	return 0;
}

