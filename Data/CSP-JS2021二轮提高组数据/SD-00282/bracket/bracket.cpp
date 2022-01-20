#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#define INF 0x3f3f3f3f
#define ll long long
#define maxn 505
#define mod 1000000007

using namespace std;

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int n,k;
string s;

ll f[maxn][maxn],fl[maxn][maxn],fr[maxn][maxn];

bool ok[maxn][maxn];

inline bool lk(char ch)
{
	return ch=='('||ch=='?';
}

inline bool rk(char ch)
{
	return ch==')'||ch=='?';
}

inline bool xk(char ch)
{
	return ch=='*'||ch=='?';
}

inline void print(int i,int j)
{
//	int l=j-i+1; 
//	for(int k=i;k<j;k++){
//		if(f[i][k]*f[k+1][j]) cout<<"1. "<<k<<" "<<f[i][k]<<" "<<f[k+1][j]<<endl; 
//	}
//	if(lk(s[i])&&rk(s[j])&&l>2) f[i][j]+=f[i+1][j-1]+fl[i+1][j-1]+fr[i+1][j-1];
//	for(int k=i;k<j;k++){
//		if(f[i][k]*fl[k+1][j]) cout<<"2. "<<k<<endl;
//	}
//	for(int k=i;k<j;k++){
//		if(ok[i][k]) fl[i][j]+=f[k+1][j];
//	}
//	for(int k=j;k>i;k--){
//		if(ok[k][j]) fr[i][j]+=f[i][k-1];
//	}
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=min(n,i+k-1);j++){
			if(!xk(s[j])) break;
			ok[i][j]=true;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++) cout<<ok[i][j]<<" ";
//		puts("");
	for(int i=2;i<=n;i++){
		if(lk(s[i-1])&&rk(s[i])) f[i-1][i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(ok[i+1][j-1]&&lk(s[i])&&rk(s[j])) f[i][j]=1;
		}
	}
	for(int l=2;l<=n;l++){
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			for(int k=i;k<j;k++){
				if(f[i][k]==1){
					f[i][j]=(f[i][j]+f[i][k]*f[k+1][j]%mod)%mod;
//					break;
				}
			}
//			for(int k=i;k<j;k++) f[i][j]=(f[i][j]+f[i][k]*f[k+1][j])%mod;
			if(lk(s[i])&&rk(s[j])&&l>2) f[i][j]=(f[i][j]+f[i+1][j-1]+fl[i+1][j-1]+fr[i+1][j-1])%mod;
			for(int k=i;k<j;k++) f[i][j]=(f[i][j]+f[i][k]*fl[k+1][j]%mod)%mod;
			for(int k=i;k<j;k++){
				if(ok[i][k]) fl[i][j]=(fl[i][j]+f[k+1][j])%mod;
			}
			for(int k=j;k>i;k--){
				if(ok[k][j]) fr[i][j]=(fr[i][j]+f[i][k-1])%mod;
			}
		}
	}
	cout<<f[1][n]<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			cout<<f[i][j]<<" ";
//		}
//		puts("");
//	}
//	print(1,n);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
/*
7 3
(*??*??

10 2
???(*??(?)


(()(*))
(**(*))
()((*))
(??(**)
(??(*?)

(?)

(*)(**)(*)
()((*))(*)
()*(**)(*)
((*(*))(*)
(??(*??(?)
(??(*??(?)
(??(*??(?)
(??(*??(?)
(??(*??(?)
(??(*??(?)
(??(*??(?)
(??(*??(?)
(??(*??(?)
(??(*??(?)
(??(*??(?)
(??(*??(?)
(??(*??(?)
*/
