#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int p = 1e9+7; 
template<class T>
inline void read(T &x){
	x = 0;
	char c=getchar();
	bool t = false;
	while(c<'0'||c>'9'){if(c=='-')t=true;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	x = x*(t?-1:1);
}
char s[1010];
int n,k;
ll f[1010][1010];
ll g[1010][1010];
bool t[1010][1010]; 
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	read(n);read(k);
	cin>>s+1;
	int ls = strlen(s+1);
	for(int i=1;i<=ls;i++){
		f[i+1][i] = 1;
		if(s[i]=='*'||s[i]=='?'){
			g[i][i] = 1;
		}
	}
	for(int i=1;i<=ls;i++){
		for(int j=i;j<=i+k-1;j++){
			if(s[j]=='('||s[j]==')'){
				break;
			}
			t[i][j] = true;
		}	
	}
	for(int i=2;i<=ls;i++){ 
		for(int j=1;j<=ls-i+1;j++){
			int l = j ,r = j+i-1;
			for(int k=l;k<=r;k++){
				if(t[l][k]){
					g[l][r]+=f[k+1][r];
				}
				if(t[k+1][r]){
					g[l][r]+=f[l][k];
				}
			}		
			if(s[l]==')'||s[r]=='('||s[l]=='*'||s[r]=='*'){
				f[l][r] = 0;
				continue;
			}
			f[l][r] += f[l+1][r-1];
			f[l][r] = f[l][r]+g[l+1][r-1]; 
			for(int k=l+1;k<=r-1;k++){
				if(f[l+1][k]==0||f[k+1][r-1]==0)continue;
				f[l][r] = f[l][r]+f[l+1][k]+f[k+1][r-1];
			}
		}
	}		
	cout<<f[1][n];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
