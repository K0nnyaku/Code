#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define N 1000010
using namespace std;

ll t,n,a[N],zhi=0,b[N],h1,t1,h2,t2,flag;


int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(ll i=1;i<=(n<<1);i++)scanf("%lld",&a[i]);
		
		
		b[1]=1;b[n<<1]=1;
		zhi=2;
		while(a[zhi]!=a[1])zhi++;
		h1=2;t1=zhi-1;t2=zhi+1;h2=(n<<1);
		flag=0;
		for(ll i=2;i<=n;i++){
			if(h1>t1){
				if(a[t2]!=a[h2]){flag=1;break;}
				b[i]=b[(n<<1)-i+1]=2;
				h2--;t2++;
			}
			else if(h2<t2){
				if(a[t1]!=a[h1]){flag=1;break;}
				b[i]=b[(n<<1)-i+1]=1;
				h1++;t1--;
			}
			else {
				if(a[h1]==a[t1]&&h1!=t1){
					b[i]=b[(n<<1)-i+1]=1;
					h1++;t1--;
				}
				else if(a[h1]==a[t2]){
					b[i]=1;b[(n<<1)-i+1]=2;
					h1++;t2++;
				}
				else if(a[h2]==a[t1]){
					b[i]=2;b[(n<<1)-i+1]=1;
					h2--;t1--;
				}
				else if(a[h2]==a[t2]&&h2!=t2){
					b[i]=2;b[(n<<1)-i+1]=2;
					h2--;t2++;
				}
				else {flag=1;break;}
			}
		}
		if(!flag){
			for(ll i=1;i<=(n<<1);i++)b[i]==1?putchar('L'):putchar('R');
			cout<<endl;
			continue;
		}
		
		
		b[1]=2;b[n<<1]=1;
		zhi=(n<<1)-1;
		while(a[zhi]!=a[n<<1])zhi--;
		h1=1;t1=zhi-1;t2=zhi+1;h2=(n<<1)-1;
		flag=0;
		for(ll i=2;i<=n;i++){
			if(h1>t1){
				if(a[t2]!=a[h2]){flag=1;break;}
				b[i]=b[(n<<1)-i+1]=2;
				h2--;t2++;
			}
			else if(h2<t2){
				if(a[t1]!=a[h1]){flag=1;break;}
				b[i]=b[(n<<1)-i+1]=1;
				h1++;t1--;
			}
			else {
				if(a[h1]==a[t1]&&h1!=t1){
					b[i]=b[(n<<1)-i+1]=1;
					h1++;t1--;
				}
				else if(a[h1]==a[t2]){
					b[i]=1;b[(n<<1)-i+1]=2;
					h1++;t2++;
				}
				else if(a[h2]==a[t1]){
					b[i]=2;b[(n<<1)-i+1]=1;
					h2--;t1--;
				}
				else if(a[h2]==a[t2]&&h2!=t2){
					b[i]=2;b[(n<<1)-i+1]=2;
					h2--;t2++;
				}
				else {flag=1;break;}
			}
		}
		if(!flag){
			for(ll i=1;i<=(n<<1);i++)b[i]==1?putchar('L'):putchar('R');
			cout<<endl;
			continue;
		}
		printf("-1\n");
		
		
	}
	return 0;
}
/*

1
20
15 12 4 16 9 2 8 17 6 1 14 20 11 13 10 7 19 18 3 3 18 19 7 10 13 11 20 14 1 6 17 8 2 9 16 4 12 5 15 5


*/
