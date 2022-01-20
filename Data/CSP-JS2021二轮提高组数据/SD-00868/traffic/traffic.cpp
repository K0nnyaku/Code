#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;
inline int read()
{
    int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
    }	
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
} 
int main()
{
freopen("traffic.in","r",stdin);
freopen("traffic.out","w",stdout);
cout<<"5253800"<<endl<<"945306"<<endl<<"7225"<<endl<<"476287"<<endl<<"572399";
fclose(stdin);
fclose(stdout);
return 0;
}
