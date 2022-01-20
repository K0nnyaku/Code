#include<bits/stdc++.h>
using namespace std;
const int M=1000001;
int n,k,m,ans=0,h,bioji=0;
char sz[M];
bool a[M];
int pd(char ss[]) {
	int l=n;
	while(l!=0) {
		if((ss[l]-'0')!=(ss[h+1-l]-'0'))return 0;
		l--;
	}
	return 1;
}
char ppd[M];
string s;
string ls;
int jz=0;
void dfs(int x) {
	if(x==h+1) {
		if(jz==1)return ;
		if(a[1]==0)jz=1; 
		int e=1,o=h,tot=1;
		for(int i=1;i<=h;++i) {
			if(a[i]==0)ppd[tot++]=sz[e++],s+="L";
			else ppd[tot++]=sz[o--],s+="R";
		}
		if(pd(ppd)){
		bioji++;
			if(ls>s)ls=s;
		s.clear();
		}
		else s.clear();
		return ;
	}
	for(int i=0;i<=1;++i) {
		a[x]=i;
		dfs(x+1);
	}
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		h=n+n;
		for(int i=1;i<=h;++i)cin>>sz[i];
		for(int i=1;i<=h;++i)ls+="R";
		dfs(1);
		if(bioji>0){cout<<ls<<endl;
		ls.clear();}
		else {printf("-1\n");ls.clear();}
		bioji=0;
		jz=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


