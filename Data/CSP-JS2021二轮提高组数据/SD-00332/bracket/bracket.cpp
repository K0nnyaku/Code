#include<bits/stdc++.h>
using namespace std;
int n,k,f[501][501][501],ans;
char s[501];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&k,s+1);
	f[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			for(int l=0;l<=min(i,k);l++){
				if(s[i+1]=='?'){
					f[i+1][j][l+1]+=f[i][j][l];
					f[i+1][j+1][0]+=f[i][j][l];
					if(j>0)f[i+1][j-1][0]+=f[i][j][l];
				}
				if(s[i+1]=='*'){
					f[i+1][j][l+1]+=f[i][j][l];
				}
				if(s[i+1]=='('){
				    f[i+1][j+1][0]+=f[i][j][l];
				}
				if(s[i+1]==')'){
					if(j>0)f[i+1][j-1][0]+=f[i][j][l];
			    }
			}
		}
	}
	for(int i=0;i<=k;i++)ans+=f[n][0][i];
	cout<<ans;
	return 0;
}
