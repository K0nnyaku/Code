#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cstring>

using namespace std;


long long n,m,T;
long long D[3][550][550];
long long A[550][550];
bool book[3][550][550];
long long biao[550][550];

 
long long shu=1;
long long heng=2;
long long k;
long long hei=2;
long long bai=1;
long long mmin=0x7fffffff;
void dfs(long long x,long long y,long long l){
	
	if(l>=mmin) return ;
	if(x==n+1){
		mmin=l;
		return ;
	}
	if(y>m){
		dfs(x+1,1,l);
		return ;
	}
	biao[x][y]=hei;
	long long t=0;
	if(biao[x-1][y]==bai){
		t+=D[shu][x-1][y];
	}
	if(biao[x][y-1]==bai){
		t+=D[heng][x][y-1];
	}
	
	if(x==n)if(biao[x+1][y]==bai) t+=D[shu][x][y];
	
	dfs(x,y+1,l+t);
	
	biao[x][y]=bai;
	t=0;
	if(biao[x-1][y]==hei){
		t+=D[shu][x-1][y];
	}
	if(biao[x][y-1]==hei){
		t+=D[heng][x][y-1];
	}	
	if(x==n)if(biao[x+1][y]==hei) t+=D[shu][x][y];
	dfs(x,y+1,l+t);
	
}

int main(){
	
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	cin>>n>>m>>T;
	
	for(long long i=1;i<n;i++){
		
		for(long long o=1;o<=m;o++){
			cin>>D[shu][i][o];
		}
		
	}
	for(long long i=1;i<=n;i++){
		for(long long o=1;o<m;o++){
			cin>>D[heng][i][o];
		}
	}
	
	for(long long p=1;p<=T;p++){
		
		cin>>k;
		memset(biao,0,sizeof(biao));
		mmin=0x7fffffff;
		for(long long i=1;i<=k;i++){
			long long a,b,c;
			cin>>a>>b>>c;
			c+=1;
			if(b<=m){
			
				D[shu][0][b]=a;
				biao[0][b]=c;
			}
			else if(b<=m+n){
		
				D[heng][b-m][m]=a;
				biao[b-m][m]=c;
			}
			else if(b<=2*m+n){
			
				D[shu][n][m-(b-m-n)+1]=a;
				biao[n][m-(b-m-n)+1]=c;
			}
			else if(b<=2*m+2*n){
	
				D[heng][n-(b-m-m-n)+1][0]=a;
				biao[n-(b-m-m-n)+1][0]=c;
			}
		}
		
		dfs(1,1,0);
		
		cout<<mmin<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);	
	
	return 0;
}
