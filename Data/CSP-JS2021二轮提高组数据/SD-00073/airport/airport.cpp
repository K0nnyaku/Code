#include<iostream>
#include<cstdio>
#include<set>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define mkp make_pair
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
inline ll read(){
	ll x = 0, f = 1; char c = getchar();
	while(!isdigit(c)){if(c == '-') f = -1; c = getchar();}
	while(isdigit(c)){x = x * 10 + c - '0', c = getchar();}
	return x * f;
}
void SETTING(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
}
int n,mm1,mm2,ans,ans1[N],ans2[N];
set<pair<int,int> >ss1,ss2;
set<pair<int,int> > :: iterator it;
int main(){
	SETTING();
	n = read(), mm1 = read(), mm2 = read();
	for(int i = 1; i <= mm1; i ++){
		int l = read(), r = read();
		ss1.insert(mkp(l,r));
	}
	for(int i = 1; i <= mm2; i ++){
		int l = read(), r = read();
		ss2.insert(mkp(l,r));
	}
	for(int i = 1; i <= n; i ++){
		if(ss1.empty()){
			ans1[i] = ans1[i - 1];
			continue;
		}
		int tmp = 1;
		int now = (*(ss1.begin())).second;ss1.erase(ss1.begin());
		while((it = ss1.lower_bound(mkp(now + 1,0))) != ss1.end()){
			now = (*it).second;
			ss1.erase(it);
			tmp ++;	
			//printf("now : %d\n",now);
		}
		ans1[i] = ans1[i - 1] + tmp;
		//printf("%d\n",ans1[i]);
	}
	for(int i = 1; i <= n; i ++){
		if(ss2.empty()){
			ans2[i] = ans2[i - 1];
			continue;
		}
		int tmp = 1;
		int now = (*(ss2.begin())).second;ss2.erase(ss2.begin());
		while((it = ss2.lower_bound(mkp(now + 1,0))) != ss2.end()){
			now = (*it).second;
			ss2.erase(it);
			tmp ++;	
			//printf("now : %d\n",now);
		}
		ans2[i] = ans2[i - 1] + tmp;
		//printf("%d\n",ans2[i]);
	}
	for(int i = 0; i <= n; i ++){
		ans = max(ans, ans1[i] + ans2[n - i]);
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

