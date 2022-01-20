#include<bits/stdc++.h>//40pts~60pts
#include<cstdio>
using namespace std;
int n,m1,m2,ans=0;//21!9-324@emb
int biao1a[1000009],biao2a[1000009],biao1b[1000009],biao2b[1000009];
int f1[1000009],f2[1000009],cannot1[1000009],cannot2[1000009];
struct kkk{
	int shi;
	int lei;
	int lian;
};
bool cmp(kkk aa,kkk bb){return aa.shi<bb.shi;}
kkk shi1[1000009];
kkk shi2[1000009];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	for(int i=1;i<=1000004;i++)
		cannot1[i]=-114514,cannot2[i]=-114514;
	cin>>n>>m1>>m2;
	int k1=m1*2,k2=m2*2;
	for(int i=1;i<=m1;i++)
	{
		cin>>shi1[i*2-1].shi;
		cin>>shi1[i*2].shi;
		shi1[i*2-1].lei=1;
		shi1[i*2].lei=2;//1进入2出来 
		shi1[i*2-1].lian=i;
		shi1[i*2].lian=i;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>shi2[i*2-1].shi;
		cin>>shi2[i*2].shi;
		shi2[i*2-1].lei=1;
		shi2[i*2].lei=2;//1进入2出来 
		shi2[i*2-1].lian=i;
		shi2[i*2].lian=i;
	}
	sort(shi1+1,shi1+k1+1,cmp);
	sort(shi2+1,shi2+k2+1,cmp);
	for(int i=0;i<=min(n,5500);i++)
	{
		int size1=0,size2=0,an1=0,an2=0;
		for(int l=1;l<=k1;l++)
		{
			if(cannot1[shi1[l].lian]==i)
				continue;
			if(shi1[l].lei==1)
			{
				if(size1<i)
					size1++;
				else
					an1++,cannot1[shi1[l].lian]=i;
			}
			if(shi1[l].lei==2)
				size1--;
		}
		for(int l=1;l<=k2;l++)
		{
			if(cannot2[shi2[l].lian]==i)
				continue;
			if(shi2[l].lei==1)
			{
				if(size2<n-i)
					size2++;
				else
					an2++,cannot2[shi2[l].lian]=i;
			}
			if(shi2[l].lei==2)
				size2--;
		}
//		cout<<"国内"<<i<<"  国际"<<n-i<<" 时，答案: "<<m1+m2-an1-an2<<endl;
//		cout<<an1<<"   "<<an2<<endl;
		ans=max(ans,m1+m2-an1-an2);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
