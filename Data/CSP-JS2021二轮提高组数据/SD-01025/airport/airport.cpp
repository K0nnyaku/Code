#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;

const int maxn = 100010;
const int inf = 0x3f3f3f3f;

inline int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w = -1;
		ch = getchar();
	}
	while(ch>='0'&&ch<='9'){
		s = (s<<1) + (s<<3) + (ch^48);
		ch = getchar(); 
	}
	return s * w;
}

inline void write(int x){
	char f[200];int cnt = 0;
	if(x<0){
		putchar('-');
		x = -x;
	}
	while(x){
		f[++cnt] = x % 10 + '0';
		x /= 10; 
	}
	while(cnt){
		putchar(f[cnt]);
		cnt--;
	}
	return;
}

struct inport{
	int s;
	int t;
}in[maxn];

struct outport{
	int s;
	int t;
}out[maxn];

bool cmp1(inport a,inport b){
	return a.s < b.s;
}

bool cmp2(outport a,outport b){
	return a.s < b.s;
}

int n,m1,m2; 
int sol;

priority_queue<int> q;

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	n = read(),m1 = read(),m2 = read();
	
	for(int i=1;i<=m1;++i){
		in[i].s = read(),in[i].t = read();
	}
	
	for(int i=1;i<=m2;++i){
		out[i].s = read(),out[i].t = read();
	}
	
	sort(in+1,in+m1+1,cmp1);
	sort(out+1,out+m2+1,cmp2);
	
	for(int mid = 0;mid<=n;++mid){
		
		int ans = 0;
		int cnt1 = 0,cnt2 = 0;
		
		for(int i=1;i<=m1;++i)
		{	
			bool flag = 0;
			if(mid == 0) break; 
			if(cnt1==mid){
				if(in[i].s > -q.top()){
					cnt1--;
					q.pop();
				}
				else{
//					cout<<mid<<endl;
//					cout<<in[i].s<<" "<<in[i].t<<" !!!!"<<endl;  
					ans--;
					cnt1--;
					flag = 1;
				}
			}
			cnt1++;
			ans++;
			if(flag){
				continue;
			}
			q.push(-in[i].t);
		}
		
	//	cout<<ans<<"*"<<endl;
		
		while(!q.empty()){
			q.pop(); 
		}
		
		for(int i=1;i<=m2;++i)
		{	
			bool flag = 0;
			if(mid == n) break;
			if(cnt2 == n - mid){
				if(out[i].s > -q.top()){
					cnt2--;
					q.pop();
				}
				else{
//					cout<<mid<<endl;
//					cout<<out[i].s<<" "<<out[i].t<<" !!!!"<<endl; 	
					cnt2--;
					ans--; 
					flag = 1;
				}
			}
			cnt2++;
			ans++;
			if(flag){
				continue;
			}
			q.push(-out[i].t);
		}
		
		while(!q.empty()){
			q.pop(); 
		}
		
		sol = max(sol,ans);
		
	}
	
	write(sol); 
	
	return 0;
}
