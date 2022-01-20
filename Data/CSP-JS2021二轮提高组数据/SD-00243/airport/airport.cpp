#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
int n,m,k;
std::priority_queue<int,std::vector<int>,std::greater<int> >q;
struct sjb {
    int a,b;
} t[100001],o[100001];
bool cmp(sjb c,sjb d)
{
    return c.a<d.a;
}
int jsansf(int lq)
{
    while(!q.empty()) q.pop();

    int res=0;
    int topp=0x7fffffff;
    for(int i=1; i<=m; i++)
    {
        while(t[i].a>=topp&&(!q.empty()))
        {
            lq+=1;
            q.pop();
            topp=q.top();
            //printf("114514");
        }
        if(lq>0)
        {
            lq-=1;
            res+=1;
            q.push(t[i].b);
            topp=q.top();
        }
    }
    return res;
}
int jsanss(int lq)
{
    while(!q.empty()) q.pop();
    int res=0;
    int topp=0x7fffffff;
    for(int i=1; i<=m; i++)
    {
        while(o[i].a>=topp&&(!q.empty()))
        {
            lq+=1;
            q.pop();
            topp=q.top();
        }
        if(lq>0)
        {
            lq-=1;
            res+=1;
            q.push(o[i].b);
            topp=q.top();
        }
    }
    return res;
}
int main()
{
    freopen("airport.in","r",stdin);
    freopen("airport.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1; i<=m; i++)
    {
        scanf("%d %d",&t[i].a,&t[i].b);
    }
    for(int i=1; i<=k; i++)
    {
        scanf("%d %d",&o[i].a,&o[i].b);
    }
    if(n>=m+k)
    {
        printf("%d",m+k);
        return 0;
    }
    std::sort(t+1,t+m+1,cmp);
    std::sort(o+1,o+1+k,cmp);
    if(n<=5000)
    {
        int ans=-0x7fffffff;
        for(int i=0; i<=n; i++)
        {
            ans=std::max(ans,jsansf(i)+jsanss(n-i));
        }
        printf("%d",ans);
    }
    else
    {
        int l=0,r=n,mid=(l+r)>>1,ans=-0x7fffffff,rans=0;;
        bool temp=0;
        if(jsansf(mid+1)+jsanss(n-mid-1)>jsansf(mid)+jsanss(n-mid))
        {
            temp=1;
        }
        while(l<=r)
        {
            mid=(l+r)>>1;
            rans=jsansf(mid)+jsanss(n-mid);
            if(temp==1)
            {
                if(rans>ans)
                {
                    ans=rans;
                    l=mid+1;
                }
                else r=mid-1;
            }
            else if(!temp)
            {
                if(rans>ans)
                {
                    ans=rans;
                    r=mid-1;
                }
                else l=mid+1;
            }
        }
        printf("%d",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

