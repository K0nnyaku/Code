#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct node{ll r,l;}a[N],b[N]; //������뿪ʱ�� a���� b���� 
ll n,m1,m2,ans;
bool cmp(node x,node y){return x.l<y.l;}
inline ll Read()
{
	ll s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return f*s;
}
priority_queue<ll,vector<ll>,greater<ll> >q;
ll guonei(ll num) //������ڷ�num��������ͣ���ķɻ����� 
{
	while(!q.empty()) q.pop();
	ll tot=0;
	for(int i=1;i<=m1;i++) //ö�ٵڼ��ܷɻ�
	{
		ll temp=0;
		while(!q.empty()&&temp<=q.size()) 
		{
			if(a[i].l>q.top())	q.pop();
			temp++;
		}
		if(q.size()<num) 
		{
			if(i==1||q.size()<num) q.push(a[i].r),tot++;
			else if(q.size()==num-1)
			{
				if(a[i].l>q.top()) q.push(a[i].r),tot++; //>=����>
			}
		}
	} 
	return tot;
}
ll guoji(int num) 
{
	while(!q.empty()) q.pop();
	ll tot=0;
	for(int i=1;i<=m2;i++) //ö�ٵڼ��ܷɻ�
	{
		ll temp=0;
		while(!q.empty()&&temp<=q.size()) 
		{
			if(b[i].l>q.top())	q.pop();
			temp++;
		}
		if(q.size()<num) 
		{
			if(i==1||q.size()<num) q.push(b[i].r),tot++;
			else if(q.size()==num-1)
			{
				if(b[i].l>q.top()) q.push(b[i].r),tot++;
			}
		}
	} 
	return tot;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=Read(),m1=Read(),m2=Read(); //���ȸ��������ں�����������⺽�����
	for(int i=1;i<=m1;i++)
		a[i].l=Read(),a[i].r=Read();
	for(int i=1;i<=m2;i++)
		b[i].l=Read(),b[i].r=Read();
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(int i=0;i<=n;i++) //��n�����ȷ�Ϊ2�ݣ��ֱ�����ں͹��� 
	{ 
		ll ans1=0,ans2=0;
		if(i!=0) ans1=guonei(i); //�����ڷ�i��������ͣ���ķɻ����� 
		if(n-i!=0) ans2=guoji(n-i); //�����ʷ�n-i��������ͣ���ķɻ�����
		ans=max(ans,ans1+ans2);
	}
	cout<<ans<<endl;
	return 0;
}
