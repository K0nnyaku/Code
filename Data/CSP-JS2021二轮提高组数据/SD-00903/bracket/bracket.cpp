#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int panduan1(int b, int c, int d)
{
	if(b*2==(c+d))
		return 1;
	if((c < b) && (d==b) || (d < b) && (c==b))
		return 2;
	return 0;
}

int panduan2(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n, m, i, kd;   //kd:kuohaoduishu
	int s[5]={};   //1:?  2:(  3:) 4:*
	int c[4]={};	//panduanjieguo
	int op=0;		//caozuoshu
	char a;
	string ss="";
	bool man=false;
	cin >> n >> m;  //n:zongchang m:xingshu
	for(i=0;i<n;i++)
	{
		cin >> a;
		if(a=='?')	s[1]++;
		else if(a=='(')	s[2]++;
		else if(a==')')	s[3]++;
		else s[4]++;
		ss+=a;
	}
	if(panduan2(s[1])<=1)
	{
		cout << panduan2(s[1]);
		return 0;
	}
	if(s[3]==s[1] || s[2]==s[1] || s[4]==s[1])
	{
		cout << "1";
		return 0;
	}
	kd=(n-m)/2;
	c[1]=panduan1(kd,s[2],s[3]);
	if(ss[0]=='?')
	{
		ss='('+ss.substr(1,n);
		op=1;
	}
	if(ss[n-1]=='?')
	{
		ss=ss.substr(0,n-1)+')';
		op=1;
	}
	return 0;
}
