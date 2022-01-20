#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;
int n,m,t;
//最小生成树???
//我不会 
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
} 

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(),m=read(),t=read();
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
