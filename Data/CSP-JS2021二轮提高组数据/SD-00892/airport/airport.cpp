#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int,int> PII;
const int N=1e5+10;

int n,m1,m2;
PII pc[N];
PII pf[N];

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++)
	{
		cin>>pc[i].first>>pc[i].second;
	}
	for(int i=0;i<m2;i++)
	{
		cin>>pf[i].first>>pf[i].second;
	}
	
	sort(pc,pc+m1);
	sort(pf,pf+m2);
	
	int ans=0;
	for(int i=n,j=0;j<n;j++,i--)
	{
		int cnt=0;
		priority_queue<int,vector<int>,greater<int> > h;
		priority_queue<int,vector<int>,greater<int> > t;//确保随时可以找到最先出队的元素 
		//国内 
		for(int k=0;k<i;k++)
		{
			h.push(pc[k].first);
			t.push(pc[k].second);
			cnt++;//先将前i个元素入队 
		for(int q=i;q<m1+1;q++)//判断后m-i个元素 
			{
			  if(t.top()<=pc[q].first)
			  {
			  	cnt++;
			  	t.pop();
			  	t.push(pc[q].second);
			  }  
			}		
		}
		
		//国际
	    priority_queue<int,vector<int>,greater<int> > h1;
		priority_queue<int,vector<int>,greater<int> > t1;
		 for(int k=0;k<j;k++)
		{
			h1.push(pf[k].first);
			t1.push(pf[k].second);
			cnt++;
			for(int q=j;q<m2+1;q++)
			{
			  if(t1.top()<=pf[q].first)
			  {
			  	cnt++;
			  	t1.pop();
			  	t1.push(pf[q].second);
			  }  
			}	
		}
		
		ans=max(ans,cnt);
     }
     cout<<ans<<endl;
    return 0;
 } 
