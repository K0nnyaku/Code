#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

inline int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

const int maxn = 100000;
int t,n,a[maxn],b[maxn],l1,r1,tot;
int an[maxn];
bool fl = 0;
void print(){
	for(int i = 1;i <= 2 * n; ++i) cout<<b[i]<<" ";cout<<endl;
}
void dfs(int x){
//	print();
	if(x == n * 2 + 1){
		bool bl = 1;
		for(int i = 1;i <= n; ++i) if(b[i] != b[2 * n - i + 1]) bl = 0;
		if(!bl) return ;
		
		fl = 1;
		for(int j = 1;j <= 2 * n; ++j){
			if(an[j] == 1) printf("L");
			else printf("R");
		}
		printf("\n");
		return ;
    }
	b[++tot] = a[l1++];
	an[x] = 1;
	dfs(x + 1);
	if(fl) return ;
	an[x] = 0;
	tot--,l1--;
	
	b[++tot] = a[r1--];
	an[x] = 2;
	dfs(x + 1);
	if(fl) return ;
	an[x] = 0;
	tot--,r1++;
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		l1 = 1,r1 = 2 * n,tot = 0,fl = 0;
		for(int i = 1;i <= 2 * n; ++i) scanf("%d",&a[i]);
		dfs(1); 
		if(!fl) cout<<"-1"<<endl;
		memset(an,0,sizeof an);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
	}
	return 0;
}
