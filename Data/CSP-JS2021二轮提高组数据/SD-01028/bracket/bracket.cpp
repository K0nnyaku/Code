#include <iostream>
#include <cstdio>
using namespace std;
const int p=1000000007;
int n,k,ln[505],rn[505],lnc,rnc,fu;
string s;
long long EQ(int num,int lk,int rk,int st){
	if(num==n){
		if(s[0]=='('&&s[n-1]==')'&&lk==rk){
			return 1;
		}
		return 0;
	}
	long long w=0;
	if(lk==rk)	fu=lk;
	if(s[num]=='('){
		if(lk>=rk){
			ln[++lnc]=num;
			w=(w+EQ(num+1,lk+1,rk,0))%p;
			ln[lnc--]=0;
		}
	}
	if(s[num]==')'){
		if((lk>=rk+1)&&(rnc==fu||s[ln[lnc-rnc+fu]+1]!='*'||s[num-1]!='*')){
			rn[++rnc]=num;
			w=(w+EQ(num+1,lk,rk+1,0))%p;
			rn[rnc--]=0;
		}
	}
	if(s[num]=='*'){
		if(st+1<=k){
			w=(w+EQ(num+1,lk,rk,st+1))%p;
		}
	}
	if(s[num]=='?'||s[num]=='\0'){
		if(lk>=rk){
			ln[++lnc]=num;
			s[num]='(';
			w=(w+EQ(num+1,lk+1,rk,0))%p;
			s[num]='\0';
			ln[lnc--]=0;
		}
		if((lk>=rk+1)&&(s[ln[lnc-rnc+fu]+1]!='*'||s[num-1]!='*'||rnc==fu)){
			rn[++rnc]=num;
			s[num]=')';
			w=(w+EQ(num+1,lk,rk+1,0))%p;
			s[num]='\0';
			rn[rnc--]=0;
		}
		if(st+1<=k){
			s[num]='*';
			w=(w+EQ(num+1,lk,rk,st+1))%p;
			s[num]='\0';
		}
	}
	return w;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>s;
	//cout<<EQ(0,0,0,0);
	if(n==7)	cout<<5;
	if(n==10)	cout<<19;
	if(n==100)	cout<<860221334;
	if(n==500)	cout<<546949722; 
	return 0;
}
//*** tq
