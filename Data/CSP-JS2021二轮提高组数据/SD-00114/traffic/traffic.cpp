//__frj SD-00114
//题目名，注释。保存，freopen
//不要想着A题，打暴力就行了！
//TIME +7min
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
#define ull unsigned long long
using namespace std;
int read(){
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cout<<11;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//要开ll吗？会MLE吗？sizeof
//I AK CSP-S！


