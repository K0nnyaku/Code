#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<deque>
#include<vector>
#include<map>
#define ri int
#define ll long long
using namespace std;
inline int read(){
	int rd=0,ch,flag=1;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') flag=-1;
	do rd=(rd<<1)+(rd<<3)+(ch^48);while((ch=getchar())>='0'&&ch<='9');
	return rd*flag;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cout<<"ZRZ AK IOI";
	return 0;
}

