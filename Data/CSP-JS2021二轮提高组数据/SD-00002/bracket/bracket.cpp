#include<bits/stdc++.h>
#define LL long long
#define il inline
#define us unsigned
#define INF 0x3f3f3f3f
#define pub push_back
#define pii pair<int,int>
#define mkp make_pair
#define x first
#define y second
#define ls (k<<1)
#define rs (k<<1|1)
#define nmid ((l+r)>>1)
#define tmid ((tr[k].l+tr[k].r)>>1)
#define KafuuChino return
#define HotoKokoa 0;
using namespace std;
il void Read(int &x){
  int f=1;x=0;char c=getchar();
  while(c<'0'||c>'9'){
    if(c=='-')f=-1;c=getchar();
  }
  while(c>='0'&&c<='9'){
    x=x*10+c-'0',c=getchar();
  }
  x*=f;
}
const int N=510;
int n,k;char a[N];int ans;
stack<int> s;
void DFS(int now){
  if(now>n){
    if(a[1]=='*'||a[n]=='*')return;
    for(int i=1,cnt=0;i<=n;i++){
      if(a[i]=='('){
        if(cnt){
          s.push(cnt);
          cnt=0;
        }
        s.push(0);
      }else if(a[i]==')'){
        if(cnt){
          if(s.empty()||!s.top())s.push(cnt);
          else return;
          cnt=0;
        }
        if(s.empty())return;
        while(s.top()){
          s.pop();if(s.empty())return;
        }
        s.pop();
      }else {
        if(cnt==k)return;cnt++;
      }
    }
    if(s.size()){
      while(!s.empty()){
        if(!s.top()){
          while(!s.empty())s.pop();return;
        }
        s.pop();
      }
    }
    return (void)(ans++);
  }
  if(a[now]!='?')DFS(now+1);
  else {
    a[now]='(',DFS(now+1);
    a[now]=')',DFS(now+1);
    a[now]='*',DFS(now+1),a[now]='?';
  }
}
int main(){
  freopen("bracket.in","r",stdin);
  freopen("bracket.out","w",stdout);
  Read(n),Read(k),scanf("%s",a+1);
  DFS(1);
  printf("%d\n",ans);
  KafuuChino HotoKokoa
}
