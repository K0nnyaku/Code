#include<iostream>
#include<cstdio>
using namespace std;
int main()
{freopen("airport.in","r",stdin);
freopen("airport.out","w",stdout);
int n;
cin>>n;
int m1;
int m2;
cin>>m1;
cin>>m2;
cout<<"";
int inarrive[m1]; 
int inleave[m1]; 
int outarrive[m2]; 
int outleave[m2]; 
for(int j=0;j<m1;j++){
cin>>inarrive[j]>>inleave[j];
cout<<"";
}
for(int k=0;k<m2;k++){
	cin>>outarrive[k]>>outleave[k];
	cout<<"";
}
int num[n+1];
int x=0;
int y=n-x;
if(x=0)
{
	if(m2<=n)
	{
		num[0]=m2;}
	else{
	    for(int w=0;w<m2-n;w++)
			{
				if(outleave[w]<outarrive[n])
				num[1]=num[0]+1;
				w++;
				n++;
				
			}
	    }
		
}
if(y=0)
{
	if(m1<=n)
	{
		num[0]=m1;}
	else{
	    for(int w=0;w<m1-n;w++)
			{
				if(outleave[w]<outarrive[n]||outleave[w+1]||outleave[w++])
				num[1]=num[0]+1;
				w++;
				n++;
				
			}
	    }
		
}
int max=0;
for (int v=0;v<n+1;v++)
if(num[v]>max)
num[v]=max;
cout<<n+m2;
return 0;
}
