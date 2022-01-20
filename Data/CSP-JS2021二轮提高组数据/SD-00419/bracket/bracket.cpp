#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
int n,k;
int x[600],lenx=0,oi=0;
unsigned long long ans=0;
int klen=0,kong[600];
deque<int> suid,suchang,d,e;
char c;
int pan(){
	suid.clear();
	suchang.clear();
	int p=0;
	for(int i=0;i<n;i++){
		if(x[i]==1) p++;
		else if(x[i]==2) p--;
		if(p<0) return 0;
	}
	if(p!=0) return 0;
	
	for(int i=0;i<n;i++){
		if(x[i]==1){
			p=0;
			for(int j=1;j<=k;j++){
				if(x[j+i]!=3&&x[j+i]!=2) break;
				if(x[j+i]==2){
					if(i==0&&j+i==n-1) return 1;
					suid.push_back(i);
					suchang.push_back(j+1);
					break;
				}
			}
		}
	}
	for(int i=0;i<suid.size();i++){
		oi=0;
		int a=suid.front();
		suid.pop_front();
		int b=suchang.front();
		suchang.pop_front();
		for(int j=0;j<=k;j++){
			if(x[a+b+j]!=suid.front()&&x[a+b+j]!=3) break;
			if(a+b+j==suid.front()){
				oi=1;
				if(a==0&&b+suchang.front()==n-1) return 1;
				suid.push_front(a);
				suchang.push_front(b+suchang.front()+j);
				break;
			}
		}
		while(!suid.empty()){
			oi=0;
			a=suid.front();
			suid.pop_front();
			b=suchang.front();
			suchang.pop_front();
			if(x[a-1]==1&&x[a+b]==2){
				oi=1;
				if(a-1==0&&a+b==n-1) return 1;
				suid.push_front(a-1);
				suchang.push_front(b+1);
			}
			else{
				if(x[a+b]==2){
					for(int i=1;i<=k+1;i++){
						if(x[a-i]!=3&&x[a-i]!=1)break;
						if(x[a-i]==1){
							oi=1;
							if(a-i==0&&a+b==n-1) return 1;
							suid.push_front(a-i);
							suchang.push_front(b+i);
							break;
						}
					}
				}
				if(oi==0){
					if(x[a-1]==1){
						for(int i=0;i<k+1;i++){
							if(x[a+b+i]!=3&&x[a+b+i]!=2) break;
							if(x[a+b+i]==2){
								oi=1;
								if(a-1==0&&a+b+i==n-1) return 1;
								suid.push_front(a-1);
								suchang.push_front(b+1+i);
								break;
							}
						}
					}
				}
			}
			if(oi==0){
				d.push_back(a);
				e.push_back(b);
			}
		}
		while(!d.empty()){
			a=d.front();
			b=e.front();
			suid.push_back(a);
			suchang.push_back(b);
		}
	}
	return 1;
}
void dfs(int step){
	//printf("%d\n",step);
	if(step==klen){
		if(pan()){
			ans++;
			ans%=1000000007;
		}
		return ;
	}
	else{
		for(int i=1;i<=3;i++){
			x[kong[step]]=i;
		}
		dfs(step+1);
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	while((c=getchar())!=EOF){
		if(c=='('){
			x[lenx++]=1;
		}
		else if(c==')'){
			x[lenx++]=2;
		}
		else if(c=='*'){
			x[lenx++]=3;
		}
		else if(c=='?'){
			kong[klen++]=lenx;
			x[lenx++]=4;
		}
	}
	//printf("haha\n");
	ans=0;
	dfs(0);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
