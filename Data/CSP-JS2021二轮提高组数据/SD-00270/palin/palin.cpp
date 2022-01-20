#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn=1e6+6;
int n,t;//memset 
int a[maxn];


int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	int tepan=t;
	while (t--)	{
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	for (int i=1;i<=2*n;i++)
	scanf("%d",&a[i]);	
		
	if (tepan==1) {
		for (int i=1;i<=2*n;i++)
		cout<<"L";
		cout<<endl;		}
	else{
		cout<<"-1"<<endl;
	}	
	
		
}
	return 0;
}
