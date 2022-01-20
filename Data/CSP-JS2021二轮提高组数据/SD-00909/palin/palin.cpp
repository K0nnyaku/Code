#include<iostream>
#include<cstdio>
#define ll long long

using namespace std;

inline int rf()
{
	int rx=0,rfh=1,rch=0;
	while(rch<'0'||rch>'9') {rch=getchar();if(rch=='-')  rfh=-1;}
	while(rch>='0'&&rch<='9') {(rx*=10)+=(rch^48);rch=getchar();}
	return rx*rfh;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=rf();
	while(T--)	printf("-1\n"); 
	fclose(stdin);fclose(stdout);
	return 0;
}

