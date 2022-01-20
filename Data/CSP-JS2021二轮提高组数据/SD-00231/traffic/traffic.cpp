#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>


using namespace std;

int read(){
	int x = 0,w = 1;char ch = 1;
	while(ch < '0' || ch > '9'){if(ch == '-') w = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + (ch - '0');ch = getchar();}
	return x * w;
}

int main(){
	freopen("tarffic.in","r",stdin);
	freopen("traffic.out","w",stdout);


	fclose(stdin);
	fclose(stdout);

	return 0;
}
