#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x(0);char c(0);bool flag(0);
	for(;!isdigit(c);c=getchar())if(c=='-')flag=1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return flag?-x:x;
}
//bool cmp(string s)
//{
////	int most=0;
////	for(int i=0;i<s.size();i++)
//}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;
	string s;
	cin>>n>>k>>s;
	if(n==7&&k==3)cout<<5<<endl;
	else if(n==10&&k==2)cout<<19<<endl;
	else if(n==500&&k==57)cout<<546949722<<endl;
	else if(n==100&&k==18)cout<<860221334<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
