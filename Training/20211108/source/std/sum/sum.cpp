#include<cstdio>
const int K=30,P=1000000007;
int n,i,j,k,x,y,cnt[K][K][2][2],p[K*2],ans;
int main(){
  freopen("sum.in","r",stdin);freopen("sum.out","w",stdout);
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&x);
    for(j=0;j<K;j++)for(k=0;k<K;k++)cnt[j][k][x>>j&1][x>>k&1]++;
  }
  for(p[0]=i=1;i<K*2;i++)p[i]=2LL*p[i-1]%P;
  for(i=0;i<K;i++)for(j=0;j<K;j++)
    for(x=0;x<2;x++)for(y=0;y<2;y++)
      ans=(1LL*cnt[i][j][x][y]*cnt[i][j][x^1][y^1]%P*p[i+j]+ans)%P;
  printf("%d",ans);
  fclose(stdin);fclose(stdout);
  return 0;
}