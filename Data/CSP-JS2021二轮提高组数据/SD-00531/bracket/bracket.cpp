#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
ll n,k;
string in;
ll chcheck(string wnt){
	ll lef[555],cnt=0,rea=0;
	if(wnt[0]=='*'||wnt[n-1]=='*') return 0ll;
	for(ll i=0;i<n;++i){
		if(wnt[i]=='('){
			lef[++cnt]=i;
		}
		else if(wnt[i]==')'){
			if(!cnt) return 0ll;
			int j,k;
			for(j=lef[cnt]-1;j>=0;--j){
				if(wnt[j]=='('||wnt[j]==')') break;
			}
			for(k=i+1;k<n;++k){
				if(wnt[k]=='('||wnt[k]==')') break;
			}
			if(wnt[j]=='('&&wnt[k]==')'&&wnt[lef[cnt]-1]=='*'&&wnt[i+1]=='*') return 0ll;
			--cnt;
		}
		if(wnt[i]!='*'||i==n-1){
			if(rea>k) return 0ll;
			rea=0;
		}
		else if(wnt[i]=='*') rea++;
	}
	if(cnt) return 0ll;
	return 1ll;
}
ll DFS(ll now,ll nowp){
	if(nowp<0) return 0;
	ll fnd=1919810,res=0;
	for(ll i=now+1;i<n;++i){
		if(in[i]=='(') nowp++;
		else if(in[i]==')') nowp--;
		if(nowp<0) break;
		if(in[i]=='?'){
			fnd=i;
			break;
		}
	}
	if(fnd==1919810){
		in[now]='(';
		res+=chcheck(in);
		in[now]=')';
		res+=chcheck(in);
		in[now]='*';
		res+=chcheck(in);
	}
	else{
		in[now]='(';
		res+=DFS(fnd,nowp+1);
		in[now]=')';
		res+=DFS(fnd,nowp-1);
		in[now]='*';
		res+=DFS(fnd,nowp);
	}
	in[now]='?';
	return res;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k; 
	cin>>in;
	if(!n){
		printf("0\n");
		return 0;
	}
	ll fstbld=1919810,nana=0;
	for(ll i=0;i<n;++i){
		if(in[i]=='(') nana++;
		else if(in[i]==')') nana--;
		if(in[i]=='?'){fstbld=i;break;}
	}
	if(fstbld==1919810){
		printf("%lld\n",chcheck(in));
		return 0;
	}
	printf("%lld\n",DFS(fstbld,nana));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

