#include <cstdio>
#include <deque>
using namespace std;
int s[500005];
int t,n;
deque<int>dq1,dq2;
bool go(bool f){
	if(dq1.empty()&&dq2.empty())return true;
	if(dq1.empty()){
		deque<int>dq3;
		while(!dq3.empty()){
			if(dq3.front()!=dq3.back())return false;
			dq3.pop_front();
			dq3.pop_back();
		}
		if(f){
			while(!dq2.empty()){
				printf("R");
				dq2.pop_back();
			}
		}
		return true;
	}else if(dq2.empty()){
		deque<int>dq3;
		while(!dq3.empty()){
			if(dq3.front()!=dq3.back())return false;
			dq3.pop_front();
			dq3.pop_back();
		}
		if(f){
			while(!dq1.empty()){
				printf("L");
				dq1.pop_front();
			}
		}
		return true;
	}
	if(dq1.size()==1&&dq2.size()==1){
		return dq1.back()==dq2.back();
	}
	if(!dq1.empty()){
		int v1=dq1.front();
	dq1.pop_front();
	if(!dq1.empty()&&dq1.back()==v1){
		dq1.pop_back();
		if(go(false)){
			if(f){
				printf("L");
				go(true);
				printf("L");
			}
		}
		dq1.push_back(v1);
	}else if(!dq2.empty()){
		dq2.pop_front();
		if(go(false)){
			if(f){
				printf("L");
				go(true);
				printf("R");
			}
		}
		dq2.push_front(v1);
	}
	dq1.push_front(v1);
	}
	if(!dq2.empty()){
	int v2=dq2.back();
	dq2.pop_back();
	if(!dq1.empty()&&dq1.back()==v1){
		dq1.pop_back();
		if(go(false)){
			if(f){
				printf("R");
				go(true);
				printf("L");
			}
		}
		dq1.push_back(v2);
	}else if(!dq2.empty()){
		dq2.pop_front();
		if(go(false)){
			if(f){
				printf("R");
				go(true);
				printf("R");
			}
		}
		dq2.push_front(v2);
	}
	dq1.push_front(v2);		
}
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=2*n;++i){
		scanf("%d",s+i);
	}
	bool flag=false;
	for(int i=2;i<=2*n;++i){
		if(s[i]==s[1]){
			flag=true;
		}else if(flag){
			dq2.push_back(s[i]);
		}else{
			dq1.push_back(s[i]);
		}
	}
	if(go(true))return;
	flag=false;
	for(int i=1;i<2*n;++i){
		if(s[i]==s[2*n]){
			flag=true;
		}else if(flag){
			dq2.push_back(s[i]);
		}else{
			dq1.push_back(s[i]);
		}
	}
	if(go(true))return;
	printf("-1\n");
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}

