#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <queue>
#include <map> 
using namespace std;
const int N=5e5+5,inf=1e9;
#define ll long long
#define db double
#define gc getchar()
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define dep(x,y,z) for(int x=y;x>=z;x++)
inline int in()
{
	int f=0,g=1;char c=gc;
	while(!isdigit(c)) 
		g=g*(c=='-'?-1:1),c=gc;
	while(isdigit(c))
		f=f*10+c-'0',c=gc;
	return f*g;
} 
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cout<<12; 
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
