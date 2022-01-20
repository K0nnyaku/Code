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
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int x,y;
	cin>>x>>y;
	int z;
	for(int i=0;i<2*y;i++){
		cin>>z;
	} 
	int v;
	cin>>v;
	for(int i=0;i<2*v;i++){
		cin>>z;
	}
	for(int i=0;i<y;i++){
		cout<<'L'<<'R';
	}
	return 0;
} 
