#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#define long long
#define dd double
#define ld long double
#define ull unsigned long long
#define N 1000100
#define M number
using namespace std;

template<typename T> inline void read(T &x){
	x=0;int flag=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') flag*=-1;
	for(;isdigit(c);c=getchar()){x*=10;x+=c-'0';}
	x*=flag;
}

int t,n,a[N],b[N];

inline void Init(){
	read(n);
	for(int i=1;i<=2*n;i++) read(a[i]);
}

inline bool Check(int x){
	int tail=0,l=1,r=2*n;
	for(int k=n-1;k>=0;k--){
		if((x>>k)&1) b[++tail]=a[r--];
		else b[++tail]=a[l++];
	}
	while(l<=r&&tail>0){
		if(a[l]==b[tail]){
			l++;tail--;
		}
		else if(a[r]==b[tail]){
			r--;tail--;
		}
		else return 0;
	}
	return 1;
}

inline void Print(int x){
	int tail=0,l=1,r=2*n;
	for(int k=n-1;k>=0;k--){
		if((x>>k)&1){
			b[++tail]=a[r--];
			putchar('R');
		}
		else{
			b[++tail]=a[l++];
			putchar('L');
		}
	}
	while(l<=r&&tail>0){
		if(a[l]==b[tail]){
			l++;tail--;
			putchar('L');
		}
		else if(a[r]==b[tail]){
			r--;tail--;
			putchar('R');
		}
	}
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	read(t);
	while(t--){
		Init();
		if(n<=20){
			bool op=0;
			int i;
			for(i=0;i<=(1<<n)-1;i++){
//				printf("%d\n",i);
				if(Check(i)){op=1;break;}
			}
			if(op) Print(i);
			else printf("-1");
			puts("");
		}
	}
}


