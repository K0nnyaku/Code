#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int n,a[N],b[N];
int vis[N],visi[N];
int mp[N],mmp[N];
deque<int> Q;
inline int read(){
	int f=1,q=0;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=0;ch=getchar();}
	while(isdigit(ch))q=(q<<3)+(q<<1)+(ch^48),ch=getchar(); 
	return f?q:-q;
}
inline void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+48);
}
signed main(){
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int t=read();
	while(t--){
		n=read();int p=n,q=n+1,pp=n,qq=n+1,nn=(n<<1);int hh=1,tt=nn;memset(vis,0,sizeof(vis));memset(visi,0,sizeof(visi));Q.clear();
		for(register int i=1;i<=nn;++i)a[i]=read();
		//------------------18-20----------------------//
		bool flag=true;
		for(register int i=1;i<=n;++i)if(a[i]^a[nn-i+1]){flag=false;break;}
		if(flag){
			for(register int i=1;i<=nn;++i)putchar('L');
			putchar('\n');
			continue;
		}
		//------------------18-20----------------------//
		//-----------------------正反双找判断无解-------------------////错了
		for(register int i=1;i<=n;++i){
			if(!vis[a[i]])vis[a[i]]=1;
			else{p=i-1;break;}
		}
	//		for(register int i=1;i<=n;++i)cout<<vis[i]<<" ";
	//		cout<<endl; 
		for(register int i=nn;i>n;--i){
			if(!vis[a[i]])vis[a[i]]=2;
			else{q=nn-i;break;}
		}
		for(register int i=nn;i>n;--i){
			if(!visi[a[i]])visi[a[i]]=1;
			else{qq=nn-i;break;}
		}
		for(register int i=1;i<=n;++i){
			if(!visi[a[i]])visi[a[i]]=2;
			else{pp=i-1;break;}
		}
		if(((p+q)^n)&&((pp+qq)^n)){
			printf("-1\n");
			continue;
		}
		//-----------------------正反双找判断无解-------------------//
		if((p+q)^n){
			for(register int i=pp+1;i<=n-qq;++i){
				if(visi[a[i]]&1)putchar('R');
				else putchar('L');
			}
			for(register int i=1;i<n;++i)putchar('L');putchar('R');
			putchar('\n');
		}
		else{
			for(register int i=p+1;i<=nn-q;++i){
				if(vis[a[i]]&1)putchar('L');
				else putchar('R');
			}
			for(register int i=1;i<n;++i)putchar('R');putchar('L');
			putchar('\n');
		}
		
//		for(register int i=1;i<=nn;++i)Q.push_back(a[i]);
//		for(register int i=1;i<=nn;++i){
//			if(!mp[a[i]])mp[a[i]]=i;
//			else mmp[a[i]]=i;
//		}
//		for(register int i=1;i<=n;++i){
//			if(!vis[a[i]])vis[a[i]]=1;
//			else{p=i-1;break;}
//		}
//		for(register int i=nn;i>n;--i){
//			if(!vis[a[i]])vis[a[i]]=2;
//			else{q=nn-i;break;}
//		}
//		for(register int i=nn;i>n;--i){
//			if(!visi[a[i]])visi[a[i]]=1;
//			else{qq=nn-i;break;}
//		}
//		for(register int i=1;i<=n;++i){
//			if(!visi[a[i]])visi[a[i]]=2;
//			else{pp=i-1;break;}
//		}
//		if(((p+q)^n)&&((pp+qq)^n)){
//			printf("-1\n");
//			continue;
//		}
//		while(!Q.empty()){
//			int x=Q.front(),y=Q.back();
//			if(mp[x]==hh){
//				putchar('L');
//				Q.pop_front();
//			}
//			else if(mp[y]==hh){
//				putchar('R');
//				Q.pop_back();
//			}
//			else if(mmp[y]==tt){
//				putchar('R');
//				Q.pop_back();
//			}
//			else if(mmp[x]==tt){
//				putchar('L');
//				Q.pop_front();
//			}
//			else{
//				printf("-1\n");
//				break;
//			}
//		}
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

大样例第19个： 
20
13 18 2 3 19 7 8 15 4 12 13 18 20 17 2 1 5 6 10 14 11 9 16-3 19 16 9 7 11 14 10 6 5 1 17 8 15 20 12 4
13 18 2 3 19                                                    16 9 7 11 14 10 6 5 1 17 8 15 20 12 4
RRLLRRRRLRRRRRRRRRLLRRRRLRRRRRRRRLLRRRRL
12345678901234567890
qq=17,pp=3
正反双找 
*/
