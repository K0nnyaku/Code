#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define ll long long
const int MOD=1e9+7;
int str[505],now[505],x[505],y[505],vis[505],cnt,n,k,ans;
stack <int> st;

int cl(int l,int r){
	/*printf("%d %d\n",l,r);
	for(int i=l;i<=r;i++){
			if(now[i]==1) printf("(");
			if(now[i]==2) printf(")");
			if(now[i]==3) printf("*");
		}
		printf("\n");*/
	if(l+1==r&&now[l]==1&&now[r]==2)
		return 1;
	if((l==1&&r==n)&&(now[r]==3||now[l]==3)) return 0;
	int _sum=0;
	for(int i=l;i<=r;i++){
		if(now[i]!=3) _sum=0;
		else _sum++;
		if(_sum>k) return 0;
		if(now[i]==1) st.push(i);
		if(now[i]==2){
			if(st.empty()) return 0;
			else{
				int le=st.top();
				if(le<l) return 0;
				if(!cl(le+1,i-1)) return 0;
				st.pop();
			}
		}
	//	printf("333\n");
	}
	if(!st.empty()&&l==1&&r==n) return 0;
	/*if(l==1&&r==n){
		for(int i=1;i<=n;i++){
			if(now[i]==1) printf("(");
			if(now[i]==2) printf(")");
			if(now[i]==3) printf("*");
		}
		printf("\n");
	}*/
	return 1;
}

void DFS(int dep){
	if(dep>n){
		while(!st.empty()){
			st.pop();
		}
		ans+=cl(1,n);
		return;
	}
	if(str[dep]!=0){
		now[dep]=str[dep];
		DFS(dep+1);
	}
	else{
		for(int i=1;i<=3;i++){
			now[dep]=i;
			DFS(dep+1);
		}
	}
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		char c;
		scanf(" %c",&c);
		if(c=='(') str[i]=1;
		if(c==')') str[i]=2;
		if(c=='*') str[i]=3;
		now[i]=str[i];
	}
	DFS(1);
	/*int now=str[1],l=1;
	for(int i=2;i<=n;i++){
		if(now&&!str[i]){
			x[++cnt]=l;
			y[cnt]=i-1;
			l=i;
			now=str[i];
		}
		if(!now&&str[i]){
			x[++cnt]=l;
			y[cnt]=i-1;
			l=i;
			now=str[i];
			vis[cnt]=1;
		}
	}
	x[++cnt]=l;
	y[++cnt]=n;
	if(!now) vis[cnt]=1;*/
	printf("%d\n",ans%MOD);
	return 0;
} 
