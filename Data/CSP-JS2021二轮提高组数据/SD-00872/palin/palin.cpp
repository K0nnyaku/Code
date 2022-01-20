#include <cstdio>
#include <queue>
#include <vector>
#define ll long long
using namespace std;
ll T,n,a[500010],pr;
deque <int> dq,tem;
vector <int> ans,ans1,ans2,ans3;
void print(){
	for(int i=0;i<ans1.size();i++){
		if(ans1[i]==0){
			printf("L");
		}
		else{
			printf("R");
		}
	}
	for(int i=0;i<ans3.size();i++){
		if(ans3[i]==0){
			printf("L");
		}
		else{
			printf("R");
		}
	}
	printf("\n");
	pr=1;
}
void dfs(){
	if(ans.size()==n){
		ans2.clear();
		ans3.clear();
		tem=dq;
			for(int i=ans.size()-1;i>=0;i--){
				if(tem.front()==ans[i]){
					ans2.push_back(tem.front());
					tem.pop_front();
					ans3.push_back(0);
				}
				else{
					if(tem.back()==ans[i]){
						ans2.push_back(tem.back());
						tem.pop_back();
						ans3.push_back(1);
					}
					else{
						return;
					}
				}
			}
			print();
		return;
	}
	ans.push_back(dq.front());
	ans1.push_back(0);
	dq.pop_front();
	dfs();
	if(pr) return;
	dq.push_front(ans[ans.size()-1]);
	ans.pop_back();
	ans1.pop_back();
	ans.push_back(dq.back());
	ans1.push_back(1);
	dq.pop_back();
	dfs();
	if(pr) return;
	dq.push_back(ans[ans.size()-1]);
	ans.pop_back();
	ans1.pop_back();
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		pr=0;
		ans.clear();ans1.clear();
		scanf("%lld",&n);
		for(int i=1;i<=(n<<1);i++){
			scanf("%lld",&a[i]);
			dq.push_back(a[i]);
		}
		dfs();
		if(pr==0){
			printf("-1\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
