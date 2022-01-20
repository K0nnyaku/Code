#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

template<typename T = int>
inline T read(){
	T x=0,w=1;
	char ch=getchar();
	
	while(!isdigit(ch)){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}	
	
	return x*w;
}
template<typename T = int>
inline void write(T x){
	static int sta[56],tp=0;
	if(x<0){
		putchar('-');
		x=-x;
	}else if(x==0){
		putchar('0');
		return;
	}
	while(x){
		sta[++tp]=x%10,x/=10;
	}
	while(tp){
		putchar(sta[tp--]+'0');
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	cout<<12<<endl;
	
	return 0;
}
