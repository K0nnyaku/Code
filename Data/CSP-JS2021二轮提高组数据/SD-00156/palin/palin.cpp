#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 500010
#define int long long
using namespace std;
inline bool isdigit(char x){return x>='0'&&x<='9';}
inline int read(){
	char x=getchar();int fl=1,ans=0;
	while(!isdigit(x)){if(x=='-')fl=-1;x=getchar();}
	while(isdigit(x)){ans=(ans<<3)+(ans<<1)+(int)(x-'0');x=getchar();}
	return fl*ans;
}
char inf[]="palin.in",ouf[]="palin.out";
int a[N],buca[N],mina,maxa,n;
bool isSuccessful;
vector<int> b;
inline int gmin(int x,int y){return x<y?x:y;}
inline int gmax(int x,int y){return x>y?x:y;}
void dfs(int cur,int fir,int las,string answer){
	if(cur==n+1){cout<<answer<<endl;isSuccessful=true;return;}
	if((b[n-cur+1]!=a[fir]&&b[n-cur+1]!=a[las])||isSuccessful)return;
	if(b[n-cur+1]==a[fir]){
		string aanswer=answer;
		aanswer+='L';
		dfs(cur+1,fir+1,las,aanswer);
	}
	if(!isSuccessful&&b[n-cur+1]==a[las]){
		string aanswer=answer;
		aanswer+='R';
		dfs(cur+1,fir,las-1,aanswer);
	}
	return;
}
void summon(int cur,int lef,int rig,string answer){
	if(isSuccessful)return;
	if(cur==n+1){
		dfs(1,lef,rig,answer);
		return;
	}
	b.push_back(a[lef]);
	summon(cur+1,lef+1,rig,answer+'L');
	b.pop_back();
	b.push_back(a[rig]);
	summon(cur+1,lef,rig-1,answer+'R');
	b.pop_back();
	return;
}
signed main(){
	ios::sync_with_stdio(false);
	freopen(inf,"r",stdin);
	freopen(ouf,"w",stdout);
int T=read();
while(T--){
	n=read();
	isSuccessful=false;
	/*
	memset(buca,0,sizeof(a));
	memset(bucb,0,sizeof(b));
	bool isSucceed=true;
	for(int i=1;i<=2*n;i++){
		a[i]=read();
		buca[a[i]]++;
		mina=gmin(a[i],mina);
		maxa=gmax(a[i],maxa);
	}
	for(int i=mina;i<=maxa;i++){
		if(buca[i]&2){
			printf("-1\n");
			isSucceed=false;
			break;
		}
	}
	if(!isSucceed)
		continue;
	*/
	for(int i=1;i<=2*n;i++)a[i]=read();
	b.clear();b.push_back(0);
	summon(1,1,2*n,"");
	if(!isSuccessful)printf("-1\n");
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//Only Brute_Force Search :( 28pts
