#include <bits/stdc++.h>
#define F(i,a,b) for(ll i=a;i<=b;i++)
#define UF(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pii pair<int,int>
#define int long long
#define foredge(i) int i=head[u],v=edges[i].to;i;i=edges[i].nxt,v=edges[i].to

using namespace std;
const ll N=100005,M=400005;
ll read(){
	ll x=0,i=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')i=0;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return i!=0?x:-x;
}

void write(ll x){
	if(x<0){
		putchar('-');
		write(-x);
		return;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

void write(ll x,char c){
	if(x<0)putchar('-'),write(-x);
	else write(x);
	putchar(c);
}
int t,n,a[N];
bool trig;
int pos[N>>1][2];
int lst[N];
void query(int l,int r,int ml,int mr,int cnt){
	if(ml<l||mr>r) return;
	if(cnt==n){
		trig=1;
		int nl=1,nr=n<<1;
//		F(i,1,n) write(lst[i],' ');
//		cout<<endl;
		F(i,1,n){
			//cout<<lst[i]<<' ';
			if(a[nl]==lst[i]&&(a[nl+1]==lst[i+1]||i==n||a[nr]==lst[i+1])) putchar('L'),nl++;
			else putchar('R'),nr--;
		}
		//cout<<endl;
		UF(i,n,1){
			if(a[nl]==lst[i]&&(a[nl+1]==lst[i-1]||i==1||a[nr]==lst[i-1])) putchar('L'),nl++;
			else putchar('R'),nr--;
		}
		putchar('\n');
		return;
	}
	if(a[l+1]==a[mr+1]&&!trig){
		lst[cnt+1]=a[l+1];
		query(l+1,r,ml,mr+1,cnt+1);
	}
	if(a[l+1]==a[ml-1]&&!trig){
		lst[cnt+1]=a[l+1];
		query(l+1,r,ml-1,mr,cnt+1);
	}
	if(a[r-1]==a[mr+1]&&!trig){
		lst[cnt+1]=a[r-1];
		query(l,r-1,ml,mr+1,cnt+1);
	}
	if(a[r-1]==a[ml-1]&&!trig){
		lst[cnt+1]=a[r-1];
		query(l,r-1,ml-1,mr,cnt+1);
	}
}
int opt[N];
signed main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	F(i,1,t){
		trig=0;
		n=read();
		F(i,1,n<<1){
			a[i]=read();
		}
		int tr=1;
		F(i,0,pow(2,n*2)-1){
			//cout<<i<<endl;
			int pos=0;
			ll k=i;
			while(k){
				if(k&1) opt[pos]=1;
				else opt[pos]=0;
				k>>=1;
				pos++;
			}
//				UF(i,n*2-1,0){
//					if(!opt[i]) putchar('L');
//					else p-utchar('R');
//				}
//				putchar('\n');
			int l=1,r=n<<1,trig=1;
			UF(i,n*2-1,0){
				if(!opt[i]) lst[i+1] =a[l++];
				else lst[i+1]=a[r--];
			}
			F(i,1,n*2){
				//write(lst[i],' ');
				if(lst[i]!=lst[n*2-i+1])
				{
					trig=0;
					break;
				}
			}
			//cout<<endl;
			if(trig){
				tr=0;
				UF(i,n*2-1,0){
					if(!opt[i]) putchar('L');
					else putchar('R');
				}
				putchar('\n');
				break;
			}
		}
		if(tr){
			write(-1,'\n');
		}
	}
	return 0;
}
