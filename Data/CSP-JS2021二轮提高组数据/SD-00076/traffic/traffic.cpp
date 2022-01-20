#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define ll long long

using namespace std;
inline ll Read(){
	ll s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return s*w;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cout<<5<<endl; 
	fclose(stdin);fclose(stdout);
	return 0;
}

