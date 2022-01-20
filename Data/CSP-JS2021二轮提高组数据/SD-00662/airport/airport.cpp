#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<ctime>

using namespace std;
#define ll long long
#define re register
#define endl() puts("")
template <typename T>
inline void reads(T &x){
	x=0;
	T f=1;
	char s=getchar();
	while(s<'0'||s>'9'){
		if(s=='-')f=-1;
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		x=x*10+s-48;
		s=getchar();
	}
	x=x*f;
}
template <typename T>
inline void writes(T x){
	if(x<0)x=-x,putchar('-');
	if(x<10){
		putchar(x+48);
		return ;
	}
	writes(x/10);
	putchar(x%10 +48);
}
struct node{
	int in,out;
	node(int i=0,int o=0){
		in=i;
		out=o;
	}
	inline bool operator >(const node&x)const{
		return out>x.out;
	}
	
};
inline bool cmp(const node&x,const node&y){
	return x.in<y.in; 
}
node a[100006],b[100006];
int n,m1,m2;
int sums=0;
inline int nei(int xx){
	if(!xx)return 0;
	if(xx>=m1)return m1;
	int cnt=0;
	priority_queue<node,vector<node>,greater<node> > q; 
	for(re int i=1;i<=m1;++i){
		if(q.size()<xx){
			++sums;
			q.push(a[i]);
			++cnt;
			continue;
		} 
		while(!q.empty()){
			++sums;
			if(a[i].in >q.top().out ){
				q.pop();
				++cnt;
				q.push(a[i]);
				break;
			}else{
				break;
			}
		}
		
		
	}
	return cnt;
}
inline int wai(int xx){
	if(!xx)return 0;
	if(xx>=m2)return m2;
	int cnt=0;
	priority_queue<node,vector<node>,greater<node> > q; 
//	q.push({2,2});
//	q.push({1,1});
//	cout<<q.top().in;
	for(re int i=1;i<=m2;++i){
		if(q.size()<xx){
			++sums;
			q.push(b[i]);
			++cnt;
			continue;
		} 
		while(!q.empty()){
			++sums;
			if(b[i].in >q.top().out ){
				q.pop();
				++cnt;
				q.push(b[i]);
				break;
			}else{
				break;
			}
		}
		
		
	}
	return cnt;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen  ("airport.out","w",stdout);
	srand(time(0));
	reads(n),
	reads(m1),
	reads(m2);
	if(m1+m2==1){
		writes(1);
		endl();
		return 0;
	}
	for(re int i=1;i<=m1;++i){
		reads(a[i].in ),reads(a[i].out );
	}
	for(re int i=1;i<=m2;++i){
		reads(b[i].in ),reads(b[i].out );
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	int maxx=0;
	int lin=nei(0)+wai(n);
	if(lin>maxx)maxx=lin;
	lin=nei(n)+wai(0);
	if(lin>maxx)maxx=lin ;
	for(re int i=n/2;i<=n-1;++i){
		int lin=nei(i)+wai(n-i);
//		cout<<lin<<endl;
		if(lin>maxx)maxx=lin;
		if(sums>=0.5e8)break;
	}
	for(re int i=n/2-1;i>=1;--i){
		int lin=nei(i)+wai(n-i);
//		cout<<lin<<endl;
		if(lin>maxx)maxx=lin;
		if(sums>=0.5e8)break;
	}
		for(re int i=1;i<=400;++i){
		int lin2=rand()%(n+1) *(ll)rand()%(n+1);
		
		int lin=nei(lin2)+wai(n-lin2);
//		cout<<lin<<endl;
		if(lin>maxx)maxx=lin;
		
	}
	writes(maxx);
	endl();
	fclose(stdin);
	fclose(stdout);

	return 0;
}

