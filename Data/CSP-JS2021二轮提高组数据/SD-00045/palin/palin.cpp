#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=5e5+5;
int n,m,t,brk;
int sz[N<<1],ans[N<<1];
bool chos[N<<1];
struct stk{
	int tp=0;
	int z[N];
	void clear(){
		tp=0;
	}
	void pop(){
		tp--;
	}
	int top(){
		return z[tp];
	}
	void push(int x){
		z[++tp]=x;
	} 
	bool empty(){
		return tp<=0;
	}
}s1,s2;
bool check(){
	//cout<<"ced";
	for(int i=2*n;i>=1;i--){
		ans[i]=s1.top();
		s1.pop();
	}
	for(int i=1;i<=n;i++){
		if(ans[i]!=ans[2*n-i+1])return 0;
	}
	return 1;
}
void chp(){
	int now=1;
	while(chos[now]){
		chos[now]=0;
		now++;
	}
	chos[now]++;
}
void chc(){
	for(int i=1;i<=2*n;i++)chos[i]=0;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=2*n;j++)cin>>sz[j];
		chc();
		for(int j=1;j<=pow(2,2*n);j++){
			int head=1,tail=2*n;
			for(int q=2*n;q>=1;q--){
				if(!chos[q]){
					s1.push(sz[head]);
//					cout<<sz[head]<<" ";
					s2.push(0);//0ȡͷ 
					head++;
				}
				else{
					s1.push(sz[tail]);
//					cout<<sz[tail]<<" ";
					s2.push(1);
					tail--;
				}
			}
//			cout<<endl;
			if(check())break;
			s1.clear();
			s2.clear();
			chp();
		}
		if(s2.empty())cout<<-1<<endl;
		else{
			for(int i=1;i<=s2.tp;i++){
				if(s2.z[i])cout<<"R";
				else cout<<"L";
			}
			cout<<endl;
		}
	}
	return 0;
}

