#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
int f[502][502];
int s[502][502];
int ss[502][502];
int fi[502][502];
int e[502][502];
int g[502];
int q[1002];
int mu=1e9+7;
string a;
int v[10002];
int main(){
	FILE *asdf,*asd;
	asd=freopen("bracket.in","r",stdin);
	asdf=freopen("bracket.out","w",stdout);
	int n,k;
	cin>>n>>k;
	cin>>a;
	for(int i=0;i<n;i++){
		if(a[i]=='*')v[i+1]=1;
		else if(a[i]=='(')v[i+1]=2;
		else if(a[i]==')')v[i+1]=4;
		else v[i+1]=7;
	}
	for(int i=1;i<=n;i++){
		int u=min(i+k-1,n);
		for(int j=i;j<=u;j++){
			if(v[j]&1)e[i][j]=1;
			else break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j;j--){
			if((v[j]&2)&&(v[i]&4)){
				if(i-j==1){
					f[j][i]=fi[j][i]=1;
				}else{
					f[j][i]=e[j+1][i-1]+f[j+1][i-1]+ss[j+1][i-1];
					while(f[j][i]>=mu)f[j][i]-=mu;
					if(f[j][i]>=mu)f[j][i]-=mu;
					f[j][i]+=s[j+1][i-1];
					if(f[j][i]>=mu)f[j][i]-=mu;
					fi[j][i]=f[j][i];
					for(int l=j+1;l<=i-2;l++){
						f[j][i]=(f[j][i]+(s[j][l]+f[j][l])*1LL*fi[l+1][i])%mu;
					}
				}int uu=min(i+k,n);
				for(int l=i+1;l<=uu;l++){
					if(!e[i+1][l])break;
					s[j][l]+=f[j][i];
					if(s[j][l]>=mu)s[j][l]-=mu;
				}
				uu=max(1,j-k);
				for(int l=j-1;l>=uu;l--){
					if(!e[l][j-1])break;
					ss[l][i]+=f[j][i];
					if(ss[l][i]>=mu)ss[l][i]-=mu;
				}
			}
		}
	}
	cout<<f[1][n];
	fclose(asdf);fclose(asd);
	return 0;
} 
