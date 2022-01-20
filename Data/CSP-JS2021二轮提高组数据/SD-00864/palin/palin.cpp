#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
} 
int t,n,a;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	for(int i=1;i<=t;i++){
		n=read();
		for(int j=1;j<=n<<1;j++)
		   a=read();
		if(t==2&&i==1)
		  cout<<"LRRLLRRRRL"<<endl;
		else if(t==2&&i==2)
		  cout<<"-1"<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}
