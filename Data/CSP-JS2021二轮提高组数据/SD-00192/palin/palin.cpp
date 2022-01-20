#include<bits/stdc++.h>
using namespace std;
int qq=0,n,nn,am[1000001],bm[1000001];
char ans[1000001],anss[1000001];
int search(int);
bool differ();
int main()
{
	freopen("palin.in","r",stdin);
freopen("palin.out","w",stdout);
	cin>>n;
	int m[n+1];
	for(int i=1;i<=n;i++)
	{cin>>m[i];
	nn=2*m[i];    
	for(int j=1;j<=nn;j++)
	cin>>am[j];
	for(int j=1;j<=nn;j++)
	bm[j]=0;
	search(1);
	if(qq!=0)
	{for(int k=1;k<nn;k++)
	cout<<anss[k];
	cout<<endl;
	}
	if(qq==0)
	cout<<"-1"<<endl;
	}
	cout<<"-1"<<endl;
	cout<<"-1";
//	fclose(stdin);fclose(stdout);
	return 0;
	
}
int search(int cc)
{
	for(int i=1;i<=2;i++)
	{if(i==1)
	 {int kk=am[1];
	 for(int j=1;j<nn;j++)
	 am[j]=am[j+1];
	 bm[cc]=kk;
	 ans[cc]='L';}
	 if(i==2)
	 {
	 	bm[cc]=am[nn-cc+1];
	 	am[nn-cc+1]=-1;
	 	ans[cc]='R';
	 }
	 if(cc=nn)differ();
	 else (cc+1);
	 if(i==1)
	 {int kk=bm[cc];
	 for(int j=nn;j>=2;j--)
	 am[j]=am[j-1];
	 am[1]=kk;
	 bm[cc]=0;}
	 if(i==2)
	 {
	 	am[nn-cc+1]=bm[cc];
	 	bm[cc]=0;
	 }
	 cc--;
	}
}
bool differ()
{
	
	int op=0;
	for(int i=1;i<=nn;i++)
	{
		if(bm[i]==bm[nn-i+1])
		op++;
	}
	if(op==n)
	{qq++;
	if(qq==1)
	for(int y=1;y<=nn;y++)
	anss[y]=ans[y];
	return 1;
	}
	else return 0;
}
