#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

const int MAXN = 100002;

struct PL{
	int s,t;
};

bool cmp(PL a,PL b){
	return a.s < b.s;
}

bool cmp2(PL a,PL b,bool x){
	return a.s < b.s;
}

int n,m1,m2;
PL I[MAXN];
PL O[MAXN];



int calci(int mx){
	if(mx == 0) return 0;
	int num = 0;
	int ans = 0;
	std::priority_queue<int , std::vector<int> ,std::greater<int> >q; 
	for(int tot = 1; tot <= m1; tot++){
		while(!q.empty() && q.top() < I[tot].s){
			q.pop();
			num--;
		}
		
		if(num < mx){
			num++;
			ans++;
			q.push(I[tot].t);
		}
		
		
	}
	return ans;
}

int calco(int mx){
	if(mx == 0) return 0;
	int num = 0;
	int ans = 0;
	std::priority_queue<int , std::vector<int> ,std::greater<int> >q; 
	for(int tot = 1; tot <= m2; tot++){
		while(!q.empty() && q.top() < O[tot].s){
			q.pop();
			num--;
		}
		
		if(num < mx){
			num++;
			ans++;
			q.push(O[tot].t);
		}
		
		
	}
	return ans;
}

int solve(int mx){
	int ans = calci(mx)+calco(n-mx);
	return ans;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout); 
	
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i = 1; i <= m1;i++){
		scanf("%d%d",&I[i].s,&I[i].t);
	}
	for(int i = 1; i <= m2;i++){
		scanf("%d%d",&O[i].s,&O[i].t);
	}
	std::sort(I+1,I+m1+1,cmp);
	std::sort(O+1,O+m2+1,cmp);
	
    
	int maxx = 0;
	for(int i = 0; i <= n ; i ++){
		int s = solve(i);
		maxx = (maxx < s) ?s : maxx;
	}
	printf("%d\n",maxx);
	
	return 0;
} 
