#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000010],l,r,b[1000010],cnt;
vector<bool>vec;
bool f,ff;
void sv(int x);
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--)
	{ 
		ff=0; 
		cin>>n;
		for(int i=1;i<=2*n;i++)
			cin>>a[i];
		sv(1);
		if(!ff)
			cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
void sv(int x)
{
	if(x==2*n+1)
	{
		f=1;
		cnt=0;
		l=0;
		r=2*n+1;
		for(int i=0;i<vec.size();i++)
			if(vec[i])
				b[++cnt]=a[++l];
			else
				b[++cnt]=a[--r];
		for(int i=1;i<=n;i++)
			if(b[i]!=b[2*n-i+1])
				f=0;
		if(f)
		{
			for(int i=0;i<vec.size();i++)
				cout<<(vec[i]?'L':'R');
			cout<<endl;
			ff=1;
		} 
		return;
	}
	vec.push_back(1);
	sv(x+1);
	vec.pop_back();
	if(ff)
		return;
	vec.push_back(0);
	sv(x+1);
	vec.pop_back();
	if(ff)
		return;
}
