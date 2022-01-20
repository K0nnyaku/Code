#include<iostream>
#include<iomanip>
#include<cstdio>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<ctime>
#include<bitset>
#include<complex>
#define F(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
using namespace std;
namespace fastIO{
	inline int read(){
		int x=0;
		bool fu=false;
		char ch=0;
		while((ch=getchar())>'9'||ch<'0'){
			if(ch=='-')fu=true;
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+ch-'0';
			ch=getchar();
		}
		return fu?-x:x;
	}
	template<class T>
	inline void read(T &x){
		x=0;
		bool fu=false;
		char ch=0;
		while((ch=getchar())>'9'||ch<'0'){
			if(ch=='-')fu=true;
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+ch-'0';
			ch=getchar();
		}
		if(fu)x=-x;
	}
	char num_[50];
	int cnt_;
	template<class T>
	inline void write(T x){
		if(x==0){
			putchar('0');
			return;
		}
		if(x<0)putchar('-'),x=-x;
		while(x){
			num_[++cnt_]=x%10+'0';
			x/=10;
		}
		while(cnt_)putchar(num_[cnt_--]);
	}
	template<class T>
	inline void write(T x,char c){
		write(x);
		putchar(c);
	}
}
using namespace fastIO;
set<pii >A,B;
int n,m,k,t1,t2,ans,a[114514],b[114514];
inline int orz(){
	int cnt=0,now=0;
	while(true){
		set<pii >::iterator x=A.lower_bound(make_pair(now,0));
		if(x==A.end())break;
		++cnt;
		now=x->second;
		A.erase(x);
	}
	return cnt;
}
inline int sto(){
	int cnt=0,now=0;
	while(true){
		set<pii >::iterator x=B.lower_bound(make_pair(now,0));
		if(x==B.end())break;
		++cnt;
		now=x->second;
		B.erase(x);
	}
	return cnt;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>k>>n>>m;
	F(i,1,n){
		read(t1);
		read(t2);
		A.insert(make_pair(t1,t2));
	}
	F(i,1,m){
		read(t1);
		read(t2);
		B.insert(make_pair(t1,t2));
	}
	F(i,1,k){
		a[i]=a[i-1]+orz();
	}
	F(i,1,k){
		b[i]=b[i-1]+sto();
	}
	F(i,0,k){
		ans=max(ans,a[i]+b[k-i]);
	}
	cout<<ans;
	//cerr<<endl;F(i,1,k)cerr<<a[i]<<" ";
	//cerr<<endl;F(i,1,k)cerr<<b[i]<<" ";
	return 0;
}
