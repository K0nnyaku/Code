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
int p1[500002],p2[500002],n,a[1000002],T;
char ans1[1000002],ans2[1000002];
inline bool cmp(){
	F(i,1,n+n)if(ans1[i]!=ans2[i])return ans1[i]<ans2[i];
	return true;
}
inline bool check(int pos,char *s){
	int x=1,y=n+n,qwq=pos,qaq=pos+1;
	F(i,1,n){
		if(x<qwq&&a[x]==a[qwq]){
			s[i]=s[n+n-i+1]='L';
			++x;
			--qwq;
		}
		else if(x<=qwq&&y>=qaq&&a[x]==a[qaq]){
			s[i]='L';
			s[n+n-i+1]='R';
			++x;
			++qaq;
		}
		else if(x<=qwq&&y>=qaq&&a[y]==a[qwq]){
			s[i]='R';
			s[n+n-i+1]='L';
			--y;
			--qwq;
		}
		else if(qaq<y&&a[y]==a[qaq]){
			s[i]=s[n+n-i+1]='R';
			--y;
			++qaq;
		}
		else return false;
	}
	return true;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	read(T);
	F(iakcsp,1,T){
		read(n);
		F(i,1,n)p1[i]=p2[i]=0;
		F(i,1,n+n){
			read(a[i]);
			if(!p1[a[i]])p1[a[i]]=i;
			else p2[a[i]]=i;
		}
		bool orz=false,sto=false;
		if(check(p2[a[1]],ans1))orz=true;
		if(check(p1[a[n+n]],ans2))sto=true;
		if(!sto&&!orz)puts("-1");
		else if(orz){
			F(i,1,n+n)putchar(ans1[i]);
			putchar('\n');
		}else if(sto){
			F(i,1,n+n)putchar(ans2[i]);
			putchar('\n');
		}else{
			if(cmp()){
				F(i,1,n+n)putchar(ans1[i]);
				putchar('\n');	
			}else{
				F(i,1,n+n)putchar(ans2[i]);
				putchar('\n');
			}
		}
	}
	return 0;
}
/*
1
20
17 3 16 1 9 12 19 6 8 2 20 14 18 10 5 11 15 7 13 4 4 13 7 15 11 5 10 18 17 14 20 2 8 6 19 12 9 1 16 3
zhqwqwqwqwqqwqwq AK IOI!!!
*/
