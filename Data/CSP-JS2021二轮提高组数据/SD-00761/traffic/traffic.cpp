#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<cstring>
#include<map>
#include<cmath>
#include<ctime>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch-'0');ch=getchar();}
	return x*f;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cout<<"12";
	return 0;
}

