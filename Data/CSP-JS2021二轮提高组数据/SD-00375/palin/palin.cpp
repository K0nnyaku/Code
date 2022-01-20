#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;
list< char > a;
vector< char > b;
vector< char > temp;
vector< vector<char> > ans;
int T, n;

void dfs(  int max, int x  );
bool test( void );
string turn( void );

int main()
{
	ios::sync_with_stdio( false );
	ifstream in;
	in.open( "palin.in" );
	ofstream out;
	out.open( "palin.out" );
	
	in >> T;
	for ( int i = 1; i <= T; i++ )
	{
		while ( a.size() ) a.pop_back();
		while ( b.size() ) b.pop_back();
		while ( ans.size() ) ans.pop_back();
		in >> n;
		int m;
		char ch;
		for ( int j = 1; j <= 2 * n; j++ )
		{
			in >> m;
			ch =  m + '0' ;
			a.push_back( ch );
		}
		dfs( 2 * n, 1 );
		if ( ans.size() == 0 )	out << -1 <<endl;
		else	out << turn() << endl;
	}
	
	in.close();
	out.close();
	return 0;
	
}
void dfs( int max, int x )
{
	if ( x > max )
	{
		if( test() )
			ans.push_back(temp);
		return ;
	}
			
	b.push_back( a.front() );
	a.pop_front();
	temp.push_back( 'L' );
	dfs(  max, x + 1 );
	a.push_front( b.back() );
	b.pop_back();
	temp.pop_back();
	
	b.push_back( a.back() );
	a.pop_back();
	temp.push_back( 'R' );
	dfs(  max, x + 1 );
	a.push_back( b.back() );
	b.pop_back();
	temp.pop_back();
	
	return ;		
}

bool test( void )
{
	for ( int i = 0; i < b.size()/2; i++ )
		if( b[i] != b[b.size()-i-1] )
			return false;
	return true;
}

string turn( void )
{
	string str[ans.size()];
	for ( int i = 0; i < ans.size(); i++ )
		for ( int j = 0; j < ans[i].size(); j++ )
			str[i] += ans[i][j];
	string m = str[0];
	for ( int i = 1; i < ans.size(); i++ )
		m = m < str[i] ? m : str[i];
	return m;	
}

