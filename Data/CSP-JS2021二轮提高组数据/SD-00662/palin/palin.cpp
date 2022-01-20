#include<cstdio>
#include<list>
#include<string>

using namespace std;
#define ll long long
#define re register
#define endl() puts("")
template <typename T>
inline void reads(T &x){
	x=0;
	T f=1;
	char s=getchar();
	while(s<'0'||s>'9'){
		if(s=='-')f=-1;
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		x=x*10+s-48;
		s=getchar();
	}
	x=x*f;
}
template <typename T>
inline void writes(T x){
	if(x<0)x=-x,putchar('-');
	if(x<10){
		putchar(x+48);
		return ;
	}
	writes(x/10);
	putchar(x%10 +48);
}
int b[500006],n,jie=0;
inline void dfs(const int&cur,list<int>&f,string &s){
	if(jie)return;
	if(cur==n){
		jie=1;
		printf("%s\n",s.c_str() );
		return;
	}
	if(cur<n/2||f.front()==b[n-cur-1]){
		b[cur]=f.front();
		f.pop_front();
		
		s=s+"L";
		dfs(cur+1,f,s);
		f.push_front(b[cur]);
		s.pop_back(); 
	}
	
	if(cur<n/2||f.back() ==b[n-cur-1]) {
		b[cur]=f.back();
		f.pop_back();
		
		s=s+"R";
		dfs(cur+1,f,s);
		f.push_back(b[cur]);
		s.pop_back();
		
	} 
}
int main(){
	freopen("palin.in","r",stdin);
	freopen  ("palin.out","w",stdout);
	int t;
	reads(t);
	while(t--){
		string s="";
		reads(n);
		jie=0;
		n=2*n;
		list<int >f;
		
		for(re int i=1;i<=n;++i){
			int lin;
			reads(lin);
			f.push_back(lin); 
			
		}
		
		dfs(0,f,s);
		if(!jie)
		printf("-1\n");
	}
	


	fclose(stdin);
	fclose(stdout);

	return 0;
}

