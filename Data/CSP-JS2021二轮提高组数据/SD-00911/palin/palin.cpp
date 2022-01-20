#include<iostream>
#include<cstdio>
#include<cstring>
#include<string> 
#define ll long long
using namespace std;

inline ll read(){
	register ll x=0,f=1;
	register char ch=getchar();
	while(ch<'0'|| ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

ll a[1010],b[1010],lst[1010];


int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	ll t=read();
	while(t--){
		ll n=read();
		for(ll i=1ll;i<=2ll*n;i++)
			a[i]=read();
		//0表示左拿，1表示右拿 
		ll len=(1ll<<(2ll*n)),ans=-1;
		bool vlst=0;
		for(ll i=0;i<len;i++){
			memset(b,0,sizeof(b));
			ll hd=1,tl=2*n;
			bool flg=1;
			for(ll j=2*n;j>=1;j--){
				if(i&(1ll<<(j-1)))b[j]=a[tl--];
				else b[j]=a[hd++];
			}
			for(ll j=1;j<=n;j++)
				if(b[j]!=b[2*n-j+1]) flg=0;
			if(flg){
				ans=i;break;
			} 
		}
		if(ans==-1){
			puts("-1");
			continue;
		}
		else{
			for(ll i=2*n;i>=1;i--){
				if(ans & (1ll<<(i-1))) putchar('R');
				else putchar('L');
			}
			puts(" ");
		}
	}
	return 0;
	fclose(stdin),fclose(stdout);
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
