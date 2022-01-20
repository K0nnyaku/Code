#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<set>
#include<map>
#include<bitset>
#include<vector>
#define mp make_pair
#define pb push_back
#define vi vector<int>
typedef long long ll;
using namespace std;
//#define int long long
int read() {
	char c=getchar();
	int s=0,x=1;
	while(c<'0' || c>'9') {
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9') {
		s=s*10+c-'0';
		c=getchar();
	}
	return s*x;
}
const int N=1e3+5;
int T,n,pos[N],a[N];
int cd[N],flag,st[N],sa[N],cz[N];
bool check() {
	int head=1,tail=2*n;
	int ta=0;
	for(int i=1; i<=n*2; i++)pos[a[i]]=0;
	for(int i=1; i<=n; i++) {
		if(cd[i]==0) {
			if(pos[a[head]])return 0;
			pos[a[head]]=i;
			sa[++ta]=a[head];
			head++;
		} else {
			if(pos[a[tail]])return 0;
			pos[a[tail]]=i;
			sa[++ta]=a[tail];
			tail--;
		}
		cz[i]=cd[i];
	}
	int top=0;
	for(int i=head; i<=tail; i++)st[++top]=a[i];
	int tt=n;
	head=1;
	for(int i=ta; i>=1; i--) {
		if(st[head]==sa[i]) {
			cz[++tt]=0;
			head++;
		} else if(st[top]==sa[i]) {
			cz[++tt]=1;
			top--;
		} else return 0;
	}
	return 1;
}
void dfs(int u) {
	if(u==n+1) {
		if(check()) {
			for(int i=1; i<=n*2; i++) {
				if(cz[i]==0)cout<<"L";
				else cout<<"R";
			}
			cout<<endl;
			flag=1;
		}
		return ;
	}
	cd[u]=0;
	dfs(u+1);
	if(flag)return ;
	cd[u]=1;
	dfs(u+1);
	if(flag)return ;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--) {
		n=read();
		for(int i=1; i<=2*n; i++)a[i]=read();
		flag=0;
		dfs(1);
		if(!flag)puts("-1");
	}
	return 0;
}
/*
4
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
