#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#define ll long long

using namespace std;

const int N=550;
const int K=550;
const ll mode=1e9+7;

void setting(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
}

ll f[N][N],g[N][N];
int n,k;
char c[N];
bool chk[N][N];
int main(){
    setting();
    scanf("%d %d",&n,&k);
    scanf("%s",c+1);
    
    for(int i=1;i<n;++i)
       if( (c[i]=='('||c[i]=='?') && (c[i+1]==')'||c[i+1]=='?') ) f[i][i+1]=g[i][i+1]=1;
	
	for(int i=1;i<=n;++i){
		chk[i][i-1]=1;
        if(c[i]!='*'&&c[i]!='?') continue;
	    for(int j=i;j<=n;++j){
	    	if(c[j]!='*'&&c[j]!='?') break;
	    	chk[i][j]=1;
		} 
	}
    
    for(int i=3;i<=n;++i){
   	    for(int j=1;j+i-1<=n;++j){
			int r=j+i-1;
			if(c[j]==')'||c[j]=='*') continue;
			if(c[r]=='('||c[r]=='*') continue;
			
			if(i-2<=k&&chk[j+1][r-1]) f[j][r]=1;
			
			for(int l=j+1;l<=min(r,j+k+1);++l){
				if(c[l]==')') break;
				if(c[l]=='*') continue;
				f[j][r]=(f[j][r]+g[l][r-1])%mode;
				if(c[l]=='(') break;
			}
			
			for(int l=r-2;l>=max(j,r-k-1);--l){
				if(c[l]=='(') break;
				if(c[l]=='*') continue;
				f[j][r]=(f[j][r]+g[j+1][l])%mode;
				if(c[l]==')') break;
			}
			
			g[j][r]=f[j][r];
			ll val=0;
			
			for(int l=j+1;l<r;++l){//ÓÒ
				if(c[l]=='*'||c[l]=='(') continue;
				
				
				for(int t=r-1;t>l;--t){//×ó 
					if(c[t]=='*'||c[t]==')') continue;
			       
							
					for(int a=l+1;a<t;++a){
						if(chk[l+1][a-1]==0) continue;
			            
					    for(int b=t-1;b>a;--b){
					        if(chk[b+1][t-1]==0) continue;
					        val=g[a][b];			
						} 
					   
					}
					val=(val*f[t][r])%mode;	
				}		
			    val=(val*f[j][l])%mode;
			    g[j][r]=(g[j][r]+val)%mode;
			     
			}
			
			
		}
   }
    
    printf("%lld",g[1][n]);
          	
   fclose(stdin);
   fclose(stdout);
   return 0;
}

