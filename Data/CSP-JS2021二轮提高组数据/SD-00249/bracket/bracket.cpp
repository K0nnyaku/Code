#include <bits/stdc++.h>
#define lint long long
#define rint register int
using namespace std;
inline int read(){
	char c;int res=0,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-f;
	while(isdigit(c))res=res*10+c-'0',c=getchar();
	return res*f;
}
const int N=5e2+5;
const lint p=1e9+7;
int n,m;
lint f[N][N][5],ans;
char s[N];
inline bool ck(int x,char c)
	{return s[x]==c||s[x]=='?';}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();m=read();
	scanf("%s",s+1);
	for(rint len=1;len<=n;++len){
		for(rint i=1;i<=n-len+1;++i){
			int j=i+len-1;
			//处理整段s的情况
			if(len<=m&&len==1&&ck(i,'*'))f[i][j][0]=1;
			if(len<=m&&len>1&&ck(i,'*')&&f[i+1][j][0])f[i][j][0]=1; 
			if(ck(i,'(')&&ck(j,')')){
				if(len==2)f[i][j][1]=1;
				else{
					for(rint k=0;k<=2;++k)
						f[i][j][1]+=f[i+1][j-1][k];	
					f[i][j][1]%=p;
					for(rint k=i+1;k<=j-2;++k){
						f[i][j][1]+=(f[i+1][k][1]+f[i+1][k][2])*f[k+1][j-1][0]%p;
						f[i][j][1]+=f[i+1][k][0]*(f[k+1][j-1][1]+f[k+1][j-1][2])%p;	 
					}
					f[i][j][1]%=p;
				}
			}
			//需要划分点的情况 
			for(rint k=i;k<=j-1;++k){
				//A+B
				f[i][j][2]+=f[i][k][1]*f[k+1][j][2]%p;
				f[i][j][2]+=f[i][k][1]*f[k+1][j][1]%p;
				//AS+B
				f[i][j][2]+=f[i][k][3]*(f[k+1][j][1]+f[k+1][j][2])%p;
				//A+S
				f[i][j][3]+=f[i][k][1]*f[k+1][j][0]%p;	
			}
			f[i][j][2]%=p;f[i][j][3]%=p;
		}
	}
	for(rint i=0;i<=2;++i)
		ans=(ans+f[1][n][i])%p;
	cout<<ans;
	return 0;
}
/*
0为S串
1为简单串，即不可分割串 包括左右为()的串即两个简单串和一个S拼成的ASB
2为复杂串 可以分割的各种串
3为AS 保证A为简单串
4为 
*/
