#include<bits/stdc++.h>
#include<queue>
#include<stack>
#include<set>
#define ll long long
using namespace std;
template <typename T>inline void read(T &x)
{
	x = 0 ; int w = 1 ; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') w = -1 ; ch = getchar();}
	while(ch >= '0' && ch <='9'){x = (x << 1) + (x << 3) + (ch ^ 48) ; ch = getchar();}
	x *= w;
}
template <typename T>inline void write(T x)
{
	if(x < 0)
		putchar('-') , x = -x;
	if(x == 0)
	{
		putchar('0');
		return ;
	}
	if(x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}
const int maxn = 1e6 + 1;
struct node
{
	int lai;
	int gun;
	int vis;
}a[maxn] , b[maxn];
int n , guo , wai;
int brin , brout;
int maxa = 0 , maxb = 0;
inline int calc()
{
//	cout << brin << " ";
	set < int > inc;
	set < int > outc;
	set < int > inlai;
	set < int > outlai;
	inc.clear() ; outc.clear() ;
	inlai.clear() ; outlai.clear() ;
	ll part1 = 0 , part2 = 0;
	for(int i = 1 ; i <= guo ; i ++)
	{
		if(inc.size())
		{
			while(a[i].lai > *inc.begin())
			{
				//cout << a[i].lai << "???" << *inc.begin() << endl;
				int fuckf = *inc.begin();
				//cout << fuckf<<" nmsl" << endl;
				brin ++ ;
				inc.erase(fuckf);
				if(inc.empty())
					break;
			}
		}
		if(brin == 0)
		{
			goto NMSL;
		}
		brin --;
		part1 ++ ;
		inlai.insert(a[i].lai);
		inc.insert(a[i].gun);
	//	cout << "当前来的最wan的" <<*inlai.rbegin()<< " 当前走的最zao的"<< *inc.begin()<< endl;  
		NMSL:;
//		if(inlai.size() && inc.size())
//		{
//			while(*inlai.rbegin() > *inc.begin())
//			{
//				int fuck = *inc.begin();
//				//cout << fuck << "???" << endl;
//				inc.erase(fuck);
//				brin ++ ;
//			}
//		}
	}
//	cout << part1 << " part2 ";
	for(int i = 1 ; i <= wai ; i ++)
	{
		if(outc.size())
		{
			while(b[i].lai > *outc.begin())
			{
				int fuckf = *outc.begin();
				brout ++ ;
				outc.erase(fuckf);
				if(outc.empty())
					break;
			}
		}
		if(brout == 0)
			goto NBSL;
		brout -- ;
		part2 ++ ;
		outlai.insert(b[i].lai);
		outc.insert(b[i].gun);
		NBSL:;
//		if(outlai.size() && outc.size())
//		{
//			while(*outlai.rbegin() > *outc.begin())
//			{
//				int fuck = *outc.begin();
//				outc.erase(fuck);
//				brout ++ ;
//			}
//		}
	}
//	cout << part2  <<endl;
	return part1 + part2;
}
int ans = 0;
bool cmp(const node &x , const node &y)
{
	return x.lai < y.lai;
}
signed main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n) ; read(guo) ; read(wai) ;
	for(int i = 1 ; i <= guo ; i ++)
		read(a[i].lai) , read(a[i].gun) , maxa = max(maxa , a[i].gun);
	for(int i = 1 ; i <= wai ; i ++)
		read(b[i].lai) , read(b[i].gun) , maxb = max(maxb , b[i].gun);
	sort(a + 1 , a + guo + 1 , cmp);
	sort(b + 1 , b + wai + 1 , cmp);
//	cout << maxa << " " << maxb << endl;
	for(int i = 0 ; i <= n ; i ++)
	{
		brin = i;
		brout = n - i;
		ll now_ans = calc();
	//	cout << now_ans << endl;
		if(now_ans > ans)
			ans = now_ans ;
	}
	write(ans);
	return 0;
}
/*
3 5 4 
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
