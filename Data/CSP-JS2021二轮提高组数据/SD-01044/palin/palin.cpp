#include<iostream>
using namespace std;
void l(int a[2n])
{
   int b[2n],n;
   a[0]=b[0];
   a[2n]==a[2n]-a[0];
} 
void r(int a[2n])
{
   int b[2n],n;
   a[2n-1]=b[2n-1];
   a[2n]==a[2n]-a[2n-1];
} 
int main()
{
	int T,n,a[2n],2n;
	cin>>n;
	cin>>a[2n];
	int b[2n]; 
	while(a[0]==a[2n]&&a[1]==a[2n-1]&&a[2n]!=a[2n-2])
	{
		l(a[2n]);cout<<"R";
		r(r[2n]);cout<<"L";
	}
	return 0;
}
