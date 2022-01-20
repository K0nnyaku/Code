#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000010],b[1000010];
string ans,s,d;
string xx="-1";
char answer[1000010];
string xfind(int x,int y,int i)
{
	if(i==2*n)
	{
		int v=0;
		for(int j=0;j<n;j++)
		{
			if(b[j]==b[2*n-j-1])
				v++;
			else break;
		}
		if(v==n)
		return answer;
		return xx;
	}
	string st;
	b[i]=a[x];
	answer[i]='L';
	i++;
	st=xfind(x+1,y,i);
	i--;
	if(st!=xx) s=min(s,st);
	b[i]=a[y];
	answer[i]='R';
	i++;
	st=xfind(x,y-1,i++);
	i--;
	if(st!=xx) s=min(s,st);
	if(s!=d) return s;
	return xx;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>n;
		s.erase();
		for(int i=0;i<2*n;i++)
		    cin>>a[i];
		for(int i=0;i<2*n;i++)
		s+='R';
		d=s;
		ans=xfind(0,2*n-1,0);
		if(ans==xx)
			cout<<"-1";
		else 
		for(int i=0;i<2*n;i++)
			cout<<ans[i];
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
} 
