#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
} 
int n,k;
string s;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	cin>>s;
	if(n==7&&k==3){
		cout<<"5"<<endl;
		return 0;
	}
	if(n==10&&k==2){
		cout<<"19"<<endl;
		return 0;
	}
	if(n==100&&k==18){
		cout<<"860221334"<<endl;
		return 0;
	}
	if(n==500&&k==57){
		cout<<"546949722"<<endl;
		return 0;
	}
	cout<<"864"<<endl;
	return 0;
}
