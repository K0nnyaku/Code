#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int qread(){
	char c=getchar(),o=' ';int x=0;
	while(c>'9'||c<'0')o=c,c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+c-48,c=getchar();
	if(o=='-')return -x;return x;
}
priority_queue<int>q;
signed main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n=qread(),m=qread(),t=qread();
	while(t--){
		cout<<n*m*2<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
