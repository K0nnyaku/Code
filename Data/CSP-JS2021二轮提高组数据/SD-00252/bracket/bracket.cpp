#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int mod=1e9+7;
int n,k,ans=1;
bool b[501];
char s[501];
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	cin.getline(s,n);
	if(n==1){
		printf("0\n");
		fclose(stdin);
	    fclose(stdout);
	    return 0;
	}
	if(n==2){
		printf("%d\n",ans);
	}
	else {
		for(int i=1;i<=n-3;i++){
			ans*=2;
			ans%=mod;
		}
		for(int i=1,j=1;i<n-k-1;i<<=1,j<<=1){
			ans=(ans-j)%mod;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
