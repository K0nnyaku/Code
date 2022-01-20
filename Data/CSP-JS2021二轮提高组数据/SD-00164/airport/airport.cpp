#include<bits/stdc++.h>

namespace zhangtao{
	inline int read(int &x){
	  x=0;int f=1;
	  char ch=getchar();
	  while(!isdigit(ch)){
	    if(ch=='-') f=-1;
	    ch=getchar();
    }
    while(isdigit(ch)){
      x=x*10+(ch-'0');
      ch=getchar();
    }
    return x*=f;
  }
  inline void write(int x){
    if(x<0){
      putchar('-');
      x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
  }
}

using std::pair;
using std::make_pair;
using namespace zhangtao;
const int maxn=200005;

int n,m_1,m_2;
struct Airplane{
  int arrive,leave;
}Local[maxn],Abroad[maxn];
inline bool operator < (Airplane a,Airplane b){
  return a.arrive<b.arrive;
}
int A[maxn],it;

pair<int,int> timetable[2][maxn];
int qwq[maxn];

inline int work(int k,const int mode){
  int used,sum;
  used=sum=0;
  for(int i=1;i<=it;++i){
    if(timetable[mode][i].first==1 && used+1<=k){
      qwq[timetable[mode][i].second]=-1;
      used++,sum++;
      continue;
    }
    used+=qwq[i];
  } 
  memset(qwq,0,sizeof qwq);
  return sum;
}

int L[5005],R[5005];
int Ans[5005];
std::vector<int>from;

signed main(){
  freopen("airport.in","r",stdin);
  freopen("airport.out","w",stdout);
  read(n),read(m_1),read(m_2);
  for(int i=1;i<=m_1;++i){
    A[++it]=read(Local[i].arrive);
    A[++it]=read(Local[i].leave);
  }
  for(int i=1;i<=m_2;++i){
    A[++it]=read(Abroad[i].arrive);
    A[++it]=read(Abroad[i].leave);
  }
  std::sort(A+1,A+1+it);
  for(int i=1;i<=m_1;++i){
    Local[i].arrive=std::lower_bound(A+1,A+it+1,Local[i].arrive)-A;
    Local[i].leave=std::lower_bound(A+1,A+it+1,Local[i].leave)-A;
  }  
  for(int i=1;i<=m_2;++i){
    Abroad[i].arrive=std::lower_bound(A+1,A+it+1,Abroad[i].arrive)-A;
    Abroad[i].leave=std::lower_bound(A+1,A+it+1,Abroad[i].leave)-A; 
  }
  for(int i=1;i<=m_1;++i){
    int arrive=Local[i].arrive,leave=Local[i].leave;
    timetable[0][arrive]=make_pair(1,leave);
    timetable[0][leave]=make_pair(-1,leave);
  }
  for(int i=1;i<=m_2;++i){
    int arrive=Abroad[i].arrive,leave=Abroad[i].leave;
    timetable[1][arrive]=make_pair(1,leave);
    timetable[1][leave]=make_pair(-1,leave);
  }
  //make Airplane timetable
  std::sort(Local+1,Local+m_1+1);
  std::sort(Abroad+1,Abroad+m_2+1);
  //preworks
  int ans=0;
  if(n<=5000){
    for(int i=0;i<=n;++i)
    ans=std::max(ans,work(i,0)+work(n-i,1));
    write(ans),putchar('\n');
    return 0;
  }else{
    //surprising sqrt technology
    int len=sqrt(n),tot=n/len;
    for(int i=1;i<=tot;++i)
      L[i]=(i-1)*len+1,R[i]=i*len;
    if(R[tot]<n) tot++,L[tot]=R[tot-1]=1,R[tot]=n;
    for(int i=1;i<tot;++i)
      Ans[i]=work(R[i],0)+work(n-R[i],1);
    int M=-1; 
    for(int i=1;i<tot;++i)
      if(Ans[i]==M)
        from.push_back(i);
      else if(Ans[i]>M){
        from.clear();
        from.push_back(i);
        M=Ans[i];
      }
    for(unsigned int _=0;_<from.size();++_){
      for(int i=L[from[_]-1];i<=R[from[_]+1];++i)
        ans=std::max(ans,work(i,0)+work(n-i,1));
    }
    write(ans),putchar('\n');
    return 0;
  }
}
