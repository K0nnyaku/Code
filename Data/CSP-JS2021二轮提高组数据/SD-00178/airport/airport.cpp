#include <iostream>
#include <cstdio>
#include <vector>
using namespace std ;
const int maxn = 100009 ;
int n , m1 , m2 ; 
int tot1[maxn] , tot2[maxn] ; 
struct pla{
	int fr ;
	int to ;
}a[maxn] , b[maxn] ;
int anss = -1 ;
vector <int> t1[100009] , t2[100009] ;
int main(){
	freopen("airport.in","r",stdin) ;
	freopen("airport.ans","w",stdout) ;
	scanf("%d%d%d" , &n , &m1 , &m2 ) ;
	for(int i = 1 ; i <= m1 ; i ++ ) {
		scanf("%d%d" , &a[i].fr , &a[i].to ) ;
		for(int j = a[i].fr ; j <= a[i].to ; j ++)
			t1[j].push_back(i) ; 
	}
	for(int i = 1 ; i <= m2 ; i ++ ) {
		scanf("%d%d" , &b[i].fr , &b[i].to ) ;
		for(int j = b[i].fr ; j <= b[i].to ; j ++)
			t2[j].push_back(i) ;
	}

	
	for(int i = 0 ; i < a[m1].to ; i ++){
		if	   (t1[i].size() < t1[i+1].size())	tot1[t1[i+1].size()] ++ ;
		else if(t1[i] != t1[i + 1] && t1[i].size() == t1[i+1].size())   tot1[t1[i+1].size()] ++ , tot1[t1[i].size()-1] ++ ;
	}
	for(int i = 0 ; i < b[m2].to ; i ++){
		if	   (t2[i].size() < t2[i+1].size())	tot2[t2[i+1].size()] ++ ;
		else if(t2[i] != t2[i + 1] && t2[i].size() == t2[i+1].size())   tot2[t2[i+1].size()] ++ , tot2[t2[i].size()-1] ++ ;
	}
	for(int i = 0 ; i <= n ; i ++ )		anss = max(anss , tot1[i] + tot2[n - i] ) ;
	printf("%d" , anss ) ;
	return 0 ;	
	fclose(stdin) ;
	fclose(stdout);
}
