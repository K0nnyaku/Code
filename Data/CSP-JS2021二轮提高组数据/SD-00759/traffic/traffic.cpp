#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,y=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')
			y=-1;
			c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0'),c=getchar();
	}
	return x*y;
}
void write(int x){
	if(x<0){
		putchar('-');
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	return 0;
} 
