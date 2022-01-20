#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;
int n, m1, m2;
pair< int, int > p[100010];
pair< int, int > q[100010];
int ans[100010];
priority_queue< int > p1, p2;

int main()
{
	ifstream in;
	in.open( "airport.in" );
	ofstream out;
	out.open( "airport.out" );
	ios::sync_with_stdio( false );
	
	in >> n >> m1 >> m2;
	for ( int i = 1; i <= m1; i++ )
		in >> p[i].first >> p[i].second;
	for ( int i = 1; i <= m2; i++ )
		in >> q[i].first >> q[i].second;
	sort ( p + 1, p + m1 + 1 );
	sort ( q + 1, q + m2 + 1 );
	for ( int i = 0; i <= n; i++ )
	{
		while( p1.size() )	p1.pop();
		while( p2.size() )	p2.pop();
		int temp = 0;
		int t = 1;
		int x = 1, y = 1;
		while ( x <= m1 || y <= m2 )
		{
			while( p1.size() )
				if ( (-p1.top()) == t )	p1.pop();
				else break;
			while( p2.size() )
				if ( (-p2.top()) == t )	p2.pop();
				else break;
			while( p[x].first == t )
			{
				if ( p1.size() < i )
				{
					p1.push( -p[x].second );
					temp++;
				}
				x++;
			}
			while( q[y].first == t )
			{
				if ( p2.size() < (n - i) )
				{
					p2.push( -q[y].second );
					temp++;
				}
				y++;
			}
			t++;
		}
		ans[i] = temp;
	}
	int temp = 0;
	for ( int i = 1; i <= n; i++ )
		temp = max( temp, ans[i] );
	out << temp;
	
	in.close();
	out.close();
	return 0;
	
}
