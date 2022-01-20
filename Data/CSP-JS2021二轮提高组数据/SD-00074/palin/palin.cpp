#include <bits/stdc++.h>
#define LL long long
#define PII pair<int,int>

using namespace std;
const int M = 100010;
int qmi(int m,int k,int p){
	int res=1%p,t=m;
	while(k){
		if(k&1) res=res*t%p;
		t=t*t%p;
		k>>=1;
	}
	return k;
}
PII st,et;
void dikstra(){
	memset(dist,0x3f,sizeof dist);
	dist[st.first][st.second]=0;
	priority_queue<PII,vector<PII>,greater<PII> > heap;
	heap.push({0,1});
	while(q.size()){
		PII t=heap.top();
		heap.pop();
		int ver=t.second,distance=t.first;
		if(st[ver]) continue;
		st[ver]=true;
		for(int i=h[ver];i!=-1;i=ne[i]){
			
		}
	}
}

int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	
	
	
	return 0;
} 
