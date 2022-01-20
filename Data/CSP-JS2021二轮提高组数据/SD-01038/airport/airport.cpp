#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<algorithm>
using namespace std;
const int Maxn=100005;
void read(int &x)
{
	char ch=getchar();x=0;int f=1;
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	x*=f;
}
struct plane_s{
	int Time_in,Time_out; 
}C[Maxn],F[Maxn];
struct time_table{
	int Timez,plnez;
}TCin[Maxn],TCout[Maxn],TFin[Maxn],TFout[Maxn];
bool cmp1(plane_s a,plane_s b)
{
	return a.Time_in<b.Time_in;
}
bool cmp2(plane_s a,plane_s b)
{
	return a.Time_out<b.Time_out;
}
int n,mC,mF,num,MaxtimeC,MaxtimeF,numCin=1,numCout=1,numFin=1,numFout=1,anss,nwplC,nwplF,num_timeC[Maxn],num_timeF[Maxn];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n),read(mC),read(mF);
	for(int i=1;i<=mC;++i) read(C[i].Time_in),read(C[i].Time_out),MaxtimeC=max(MaxtimeC,C[i].Time_out);
	for(int i=1;i<=mF;++i) read(F[i].Time_in),read(F[i].Time_out),MaxtimeF=max(MaxtimeF,F[i].Time_out);
	sort(C+1,C+1+mC,cmp1);sort(F+1,F+1+mF,cmp1);
	for(int i=1;i<=mC;++i)
	{
		TCin[i].plnez=i;
		TCin[i].Timez=C[i].Time_in;
	}
	num=0;
	for(int i=1;i<=mF;++i)
	{
		TFin[i].plnez=i;
		TFin[i].Timez=F[i].Time_in;
	}
	num=0;
	sort(C+1,C+1+mC,cmp2);sort(F+1,F+1+mF,cmp2);
	for(int i=1;i<=mC;++i)
	{
		TCout[i].plnez=i;
		TCout[i].Timez=C[i].Time_out;
	}
	num=0;
	for(int i=1;i<=mF;++i)
	{
		TFout[i].plnez=i;
		TFout[i].Timez=F[i].Time_out;
	}
	num=0;
	for(int j=0;j<=n;++j)
	{
		int ans=0;int ansa=0,ansb=0;
		for(int i=1;i<=MaxtimeC;++i)
		{
			if(i==TCout[numCout].Timez)
			{
				++numCout;--nwplC;
			}
			if(i==TCin[numCin].Timez)
			{
				++numCin;++nwplC;
				if(nwplC<=j) ansa++;
			}
		}
		for(int i=1;i<=MaxtimeF;++i)
		{
			if(i==TFout[numFout].Timez)
			{
				++numFout;--nwplF;
			}
			if(i==TFin[numFin].Timez)
			{
				++numFin;++nwplF;
				if(nwplF<=n-j) ansb++;
			}
		}
		ans=ansa+ansb;
		anss=max(ans,anss);
	}
	cout<<anss;
	return 0;
}
//3 5 4
//1 5 3 8 6 10 9 14 13 18 2 11 4 15 7 17 12 16
