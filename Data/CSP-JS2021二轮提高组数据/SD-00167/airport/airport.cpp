#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 100000 + 110;

priority_queue<int,vector<int>,greater<int> >dui,q;

int n,m,w;

struct shuu{
	int start,end;
}tm[N],tw[N];

bool cmp(shuu x,shuu y){
	return x.start < y.start;
}

int main(){
	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&w);
	for(int i = 1;i <= m;i ++){
		scanf("%d%d",&tm[i].start,&tm[i].end);
	}
	for(int i = 1;i <= w;i ++){
		scanf("%d%d",&tw[i].start,&tw[i].end);
	}
	sort(tm + 1,tm + m + 1,cmp);
	sort(tw + 1,tw + w + 1,cmp);
	
	
	
	int ans = 0;
	for(int k = 0;k <= n;k ++){
		int sum = 0;
		
		int pan = 0;
		while(!dui.empty()){
			
			dui.pop();
		}
		for(int i = 1;i <= m;i ++){
			while(!dui.empty() && dui.top() < tm[i].start){
				dui.pop();
				pan--;
			}
			if(pan < k){
				sum++;
				pan++;
				dui.push(tm[i].end);
			}
		}
		
		pan = 0;
		while(!q.empty()){
			q.pop();
		}
		for(int i = 1;i <= w;i ++){
			while(!q.empty() && q.top() < tw[i].start){
				q.pop();
				pan--;
			}
			if(pan < n - k){
				sum++;
				pan++;
				q.push(tw[i].end);
				
			}
		}
		ans = max(ans,sum);
		
	}
	
	cout << ans ;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}






