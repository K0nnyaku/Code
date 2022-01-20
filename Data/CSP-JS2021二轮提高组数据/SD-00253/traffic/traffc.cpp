#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

int m,n,t;

typedef struct bian{
	int w;
	
	int p1;
	int p2;
	
	bool operator< (const bian& b) const {
		return w < b.w; 
	}
	
}bian;


struct {
	vector<bian> cu;
	
}points[250010];

vector<bian> all_bian;


struct{
	int dt[250010];
	void reset(int size){
		for(int i = 0; i < size;++i)
			dt[i] = i;
	}
	
	int ca(int x){
		return (dt[x] == x) ? x : dt[x] = ca(dt[x]);
	}
	
	void bing(int a,int b){
		dt[ca(a)] = ca(b);
	}
	
}bcj;


int main(){
	
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&t);
	for(int i = 1;i < n;++i){
		for(int j = 0;j < m;++j){
			int w;
			scanf("%d",&w);
			all_bian.push_back({w,i - 1 + j * n,i + j * m});
		}
	}
	for(int i = 0;i < n; ++i){
		for(int j = 1;j < m;++j){
			int w;
			scanf("%d",&w);
			all_bian.push_back({w,i + (j - 1) * n,i + j * n});
		}
	}
	while(t--){
		int adn;
		scanf("%d",&adn);
		bcj.reset(m * n + adn);
		for(int i = 0; i < adn; ++i){
			int w,p,c;
			int cp;
			scanf("%d%d%d",&w,&p,&c);
			--p;
			if(p < m)
				cp = p * n;
			else if(p < m + n)
				cp = (m - 1) * n + (p - m);
			else if(p < 2 * m + n)
				cp = (m - (p - m - n) - 1) + n - 1;
			else
				cp = n - (p - 2 * m - n) - 1;
			
			all_bian.push_back({w,all_bian.size(),cp});
			
			
			printf("%d",w ^ p ^ c % 250);
		}
	}
	
	fclose(stdout);
	fclose(stdin);
	
	return 0;
}
