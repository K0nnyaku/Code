#include<iostream>
#include<cstdio>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
inline int qread(){
	int x=0;
	char c=getchar(),o=' ';
	while(c<'0'||c>'9') o=c,c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	if(o=='-') x=~x+1;
	return x;
}
int a[200010],b[200010],l[200010],r[200010],o[200010];
int n;
bool dfs(int pos,int ll,int rr){
//	cout<<pos<<'\n';
	if(pos>n&&b[pos]!=b[2*n+1-pos]) return false;
	if(pos>=n*2) return true;
	pos++;
	o[pos]=1;
	b[pos]=a[ll];
	if(dfs(pos,ll+1,rr))return true;
	o[pos]=2;
	b[pos]=a[rr];
	if(dfs(pos,ll,rr-1))return true;
	return false;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t=qread();
	while(t--){
		n=qread();
		for(int i=1;i<=2*n;++i){
			a[i]=qread();
			if(l[a[i]])r[a[i]]=i;
			else l[a[i]]=i;
		}
		if(!dfs(0,1,2*n)) cout<<-1<<'\n';
		else{
			for(int i=1;i<=2*n;++i){
				if(o[i]==1) cout<<"L";
				else cout<<"R";
			}
			puts("");
		}
	}
	return 0;
}
/*
1
5
4 1 2 4 5 3 1 2 3 5
*/
