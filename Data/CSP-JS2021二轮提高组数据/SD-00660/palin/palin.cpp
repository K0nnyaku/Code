#include <cstdio>
#include <iostream>
#include <deque>
#include <queue>
using namespace std;

const int N = 1000010;
int T,n,ans;
int a[N];
void pri(queue<char>q)
{
	while(q.size())
	{
		cout<<(char)(q.front());
		q.pop();
	}
}
bool c(deque<int>dq)
{
//	if(dq.size() % 2)
//		return false;
	while(dq.size() >= 2)
	{
//			cout << *dq.begin() << " " << *dq.end()-1) << endl;
		if(*dq.begin() == *(dq.end()-1))
		{
//			cout << *dq.begin() << " " << *dq.end()-1) << endl;
			dq.pop_back(),dq.pop_front();
		}
		else
			return false;
	}
	return true;
}
void ch(deque<int>dq,queue<char>qu,int k,int l,int r)
{
	if(k == n*2)
		if(c(dq))
		{
			pri(qu);
			cout << endl;
			return ;
		}
	else
	{
		dq.push_front(a[l]);
		qu.push('L');
		ch(dq,qu,k + 1,l + 1,r);
		dq.pop_front();
		
		dq.push_back(a[r]);
		qu.push('R');
		ch(dq,qu,k + 1,l,r - 1);
		dq.pop_back();
	}
}
int chk()
{
	deque<int>dq;
	queue<char>qu;
	ch(dq,qu,0,1,n * 2);
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	cin >> T;
	
	while(T --)
	{
		ans = 0;
		
		cin >> n;
		for(int i = 1;i <= n * 2;i ++)
			cin >> a[i];
			
		cout << chk() << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
