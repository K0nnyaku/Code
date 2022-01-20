#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <deque>
#include <string>
#include <cstring> 
#include <map>
using namespace std;
const int size = 500005;
int sum = size;
deque<int> a,b;
string str;
char L = 'L';
char R = 'R';
int n;
queue<pair< string,pair<deque<int>,deque<int> > > > m;
void Rm(deque<int> a,deque<int> b)
{
	if(a.empty())
		return;
	int pos = a.back();
	a.pop_back();
	b.push_back(pos);
}
void Lm(deque<int> a,deque<int> b)
{
	if(a.empty())
		return;
	int pos = a.front();
	a.pop_front();
	b.push_back(pos);
}
bool cheak(deque<int> bte)
{
	int lenth = bte.size();
	if(lenth % 2 != 0)
		return 1;
	lenth /= 2;
	for(int i = 0;i < lenth;i++)
	{
		if(bte[i] != bte[(2 * lenth) - 1 - i])
			return 1;
	}
	return 0;
}
void start()
{
	deque<int> pa = a;
	deque<int> pb;
	int pos = pa.back();
	pb.push_back(pos);
	pa.pop_back();
	m.push({"R",{pa,pb}});
	pa = a;
	pb.clear();
	pos = pa.front();
	pb.push_back(pos);
	pa.pop_front(); 
	m.push({"L",{pa,pb}});
}
int main()
{
	freopen("palin.out","w",stdout);
	freopen("palin1.in","r",stdin);
	int T;
	cin >> T;
	for(int t = 1;t <= T;t++)
	{
		cin >> n;
		a.clear();
		b.clear();
		int p;
		for(int i = 1;i <= (2 * n);i++)
		{
			cin >> p;
			a.push_back(p);
		}
		start();
		int k = 0;
		while(!m.empty())
		{
			str = m.front().first;
			deque<int> ate = m.front().second.first;
			deque<int> bte = m.front().second.second;
			m.pop();
			if(!cheak(bte))
			{
				cout << str << endl;
				k = 1;
				break;
			}
			string temp = str;
			int atp = ate.front();
			Lm(ate,bte);
			str += L;
			m.push({str,{ate,bte}});
			
			ate.push_front(atp);
			bte.pop_back();
			str = temp;
			atp = ate.back();
			Rm(ate,bte);
			str += R;
			m.push({str,{ate,bte}});
		}
		if(!k)
			cout << "-1" << endl;
	}
	return 0;
}
