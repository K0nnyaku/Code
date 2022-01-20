#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

const int MAXN = 500002;

int n;
int a[MAXN];

inline int oi_max(int a,int b){
	return a>b?a:b;
} 
inline void pl(){
	printf("L");
}
inline void pr(){
	printf("R");
}
bool chec1(int s,int t){
	int i = s;
	int j = t;
	while(i < j){
		if(a[i] != a[j]) return false;
		i++;
		j--;
	}
	return true;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout); 
	
	int T; 
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		n = 2*n;
		for(int i = 1; i <= n ; i++){
			scanf("%d",&a[i]);
		}
		
		
		//bool lorr = 0;//0 means l,1 means r
		if(a[1] == a[n]){
			if(chec1(1,n)){
				for(int i = 1; i <= n; i++){
					pl();
				}
				printf("\n");
			}
			else{
				printf("-1\n");
			}
		}
		else if(n == 2){
			printf("-1\n");
		}
		//printf("?");
		else if(a[1] == a[2]){
			if(chec1(3,n)){
				pl();
				for(int i = 1; i <= n-1; i++){
					pr();
				
				}
				printf("\n");	
			}
			else{
				printf("-1\n");
			}
		}
		else if(a[n-1] == a[n]){
			if(chec1(1,n-2)){
				pr();
				for(int i = 1; i <= n-1; i++){
					pl();
					
				}
			printf("\n");	
			}
			else{
				printf("-1\n");
			}
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
} 
