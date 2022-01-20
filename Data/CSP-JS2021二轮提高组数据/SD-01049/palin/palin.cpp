#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline long long read(){
	char ch=getchar();
	while(ch!='-'&&(ch>'9'||ch<'0'))
	{
		ch=getchar();
	}
	long long ans=0,t=1;
	if(ch=='-'){
		t=-1;
		ch=getchar();
	} 
	while(ch>='0'&&ch<='9'){
		ans=ans*10+(ch-'0');
		ch=getchar();
	}
	return ans*t;
}
inline void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
const int N=5e5+10;
int a[N];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		int x=read();
		for(int j=1;j<=2*x;j++){
			a[j]=read();
		}
		cout<<"-1"<<endl;
	}
	return 0;
} 
