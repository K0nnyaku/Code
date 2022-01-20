#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct hhh{
	int st,ed;
	const bool operator < (hhh w)const{
		return ed>w.ed;
	}
};
bool cmp(hhh aaa,hhh bbb)
{
	return aaa.st<bbb.st;
}
hhh a[100005],b[100005];
priority_queue<hhh> _1,_2;
int maxn=-3;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	if(n>=m1+m2)
	{
		cout<<m1+m2;
		return 0;
	}
	for(int i=1;i<=m1;++i)
		scanf("%d%d",&a[i].st,&a[i].ed);
	sort(a+1,a+1+m1,cmp);
	for(int i=1;i<=m2;++i)
		scanf("%d%d",&b[i].st,&b[i].ed);
	sort(b+1,b+1+m2,cmp);
//	cout<<1<<endl;
	for(int i=0;i<=n;++i)
	{
		if(n-i>m2||i>m1)
			continue; 
//		cout<<endl<<i<<endl<<"in"<<endl;
		int cnt=0;
		for(int j=1;j<=m1;++j)
		{
			while(!_1.empty())
				if(_1.top().ed<a[j].st)
//					cout<<_1.front()<<" pop"<<endl,
					_1.pop();
				else
					break;
//			cout<<j<<endl;
			if(_1.size()<i)
			{
				_1.push({a[j].st,a[j].ed}),cnt++;
//				cout<<j<<"push_in__1"<<endl;
			}
		}
//		cout<<endl;
		while(!_1.empty())
			_1.pop();
//		cout<<"out"<<endl;
		for(int j=1;j<=m2;++j)
		{
			while(!_2.empty())
				if(_2.top().ed<b[j].st)
//					cout<<_2.front()<<" pop"<<endl,
					_2.pop();
				else
					break;
//			cout<<j<<endl;
			if(_2.size()<n-i)
			{
				_2.push({b[j].st,b[j].ed}),cnt++;
//				cout<<j<<"push_in__2"<<endl;
			}
		}
		while(!_2.empty())
			_2.pop();
		maxn=max(maxn,cnt);
//		printf("%d %d\n",i,cnt);
	}
	printf("%d\n",maxn);
	return 0;
}
