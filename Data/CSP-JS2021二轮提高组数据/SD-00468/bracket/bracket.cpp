#include<bits/stdc++.h>
#define LL long long
#define rep(i,l,r) for(int i = l;i<=r;++i)
#define reg register
#define IT iterator
#define pb(x) push_back(x)
using namespace std;
const int N = 1e5+10,p = 1;
const bool is_file = 1;
const string Name = "bracket";
int n,k;
char a[N];
int stk[N],stk_cnt;
int cnt_A,cnt_S;
int op[N],op_cnt;

bool check(){
	stk_cnt = 0;
	int cntt = 0,Cntt = 0;
	rep(i,1,n){
		if(a[i]=='(')++cntt,Cntt = 0;
		if(a[i]==')')--cntt,Cntt = 0;
		if(a[i]=='*')++Cntt;
		if(cntt<0){
			return false;	
		}
		if(Cntt>k){
			return false;
		}
	}
	rep(i,1,n){
		if(a[i]=='(')stk[++stk_cnt]='(';
		if(a[i]=='*'){
			int CCnt = 0;
			while(a[i+1]=='*')++i,++CCnt;
			stk[++stk_cnt]='S';
		}
		if(a[i]==')'){
//			if(stk[stk_cnt]=='(')stk[stk_cnt]='A';
			int j = stk_cnt;int cnt_x = 0;
			while(stk[j]!='('){
				if(stk[j]=='S')++cnt_x;
				--j;
			}
			if(cnt_x<=1)stk_cnt=j,stk[stk_cnt]='A';
		}
		if(stk[stk_cnt]=='A'){
			while(stk[stk_cnt-1]=='A'||stk[stk_cnt-2]=='A'){
				while(stk[stk_cnt-2]=='A')stk_cnt-=2;
				while(stk[stk_cnt-1]=='A')stk_cnt-=1;
			}
		}
	}
	if(stk[stk_cnt]=='A'){
		while(stk[stk_cnt-2]=='A')stk_cnt-=2;
	}
	if(stk_cnt==1)return true;
	else return false;
}
int LL res;
void dfs(int k){
		int cntt = 0,Cntt = 0;
		rep(i,1,k){
			if(a[i]=='(')++cntt,Cntt = 0;
			if(a[i]==')')--cntt,Cntt = 0;
			if(a[i]=='*')++Cntt;
			if(cntt<0){
				return ;	
			}
			if(Cntt>k){
				return ;
			}
		}
	if(k==op_cnt+1)res+=check();
	else{
		a[op[k]]='(';dfs(k+1);
		a[op[k]]='*';dfs(k+1);
		a[op[k]]=')';dfs(k+1);
	}
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>a+1;
	if(n>100)cout<<check();
	else{
		rep(i,1,n)if(a[i]=='?')op[++op_cnt]=i;
		dfs(1);
		cout<<res;
	}

	return 0;
}

