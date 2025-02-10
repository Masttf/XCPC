#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls tr1[u].lson
#define rs tr1[u].rson
#define endl '\n'
const int N=1e6+10;
struct node  //这个是求最长上升子序列的线段树
{
    int l,r;
    int maxx;
}tr[N<<2];
struct tree  //这个是统计答案的线段树
{
    int lson,rson,lazy;
    int sum=0;
}tr1[N<<5];
struct pii  
{
    int x,y;
    friend bool operator <(pii a,pii b)
    {
        if(a.x==b.x) return a.y>b.y;
        else return a.x<b.x;
    }
};
map<int,int> ma;
int idxx,idx;
int n;
int root;
void check(int x)  //离散化
{
    if(ma.count(x)==0) ma[x]=++idxx;
}
void pushup(int u)
{
    tr[u].maxx=max(tr[u<<1].maxx,tr[u<<1|1].maxx);
}
void build(int u,int l,int r)
{
    tr[u].l=l;
    tr[u].r=r;
    if(l==r)
    {
        tr[u].maxx=0;
    }
    else
    {
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
void modify(int u,int pos,int x)
{
    if(tr[u].l==tr[u].r)
    {
        tr[u].maxx=max(tr[u].maxx,x);
    }
    else
    {

        int mid=tr[u].l+tr[u].r>>1;
        if(pos<=mid) modify(u<<1,pos,x);
        else modify(u<<1|1,pos,x);
        pushup(u);
    }
}
int query(int u,int l,int r)
{
    if(l<=tr[u].l&&tr[u].r<=r)
    {
        return tr[u].maxx;
    }
    else
    {
        int mid=tr[u].l+tr[u].r>>1;
        int ans=0;
        if(l<=mid) ans=max(ans,query(u<<1,l,r));
        if(r>mid) ans=max(ans,query(u<<1|1,l,r));
        pushup(u);
        return ans;
    }
}
void pushup1(int u)
{
    tr1[u].sum=tr1[ls].sum+tr1[rs].sum;
}
void pushdown(int u,int trl,int trr)
{
    if(tr1[u].lazy==-1) return ;
    int mid=trl+trr>>1;
    if(ls==0)
    {
        ls=++idx;
        tr1[ls].lson=0;
        tr1[ls].rson=0;
        tr1[ls].sum=tr1[u].lazy*(mid-trl+1);
        tr1[ls].lazy=tr1[u].lazy;

    }
    else
    {
        tr1[ls].sum=tr1[u].lazy*(mid-trl+1);
        tr1[ls].lazy=tr1[u].lazy;
    }
    if(rs==0)
    {
        rs=++idx;
        tr1[rs].lson=0;
        tr1[rs].rson=0;
        tr1[rs].sum=tr1[u].lazy*(trr-(mid+1)+1);
        tr1[rs].lazy=tr1[u].lazy;

    }
    else
    {
        tr1[rs].sum=tr1[u].lazy*(trr-(mid+1)+1);
        tr1[rs].lazy=tr1[u].lazy;
    }
    tr1[u].lazy=-1;


}
int modify1(int u,int trl,int trr,int l,int r,int x)
{
    if(u==0)
    {
        u=++idx;
        tr1[u].sum=0;
        ls=0;
        rs=0;
        tr1[u].lazy=-1;
    }
    if(l<=trl&&trr<=r)
    {
        tr1[u].lazy=x;
        tr1[u].sum=(trr-trl+1)*x;
        return u;
    }
    else
    {
        pushdown(u,trl,trr);
        int mid=trl+trr>>1;
        if(l<=mid) ls=modify1(ls,trl,mid,l,r,x);
        if(r>mid) rs=modify1(rs,mid+1,trr,l,r,x);
        pushup1(u);
        return u;
    }
}
int query1(int u,int trl,int trr)
{
    return tr1[u].sum;
}
void init()
{
    root=0;  //初始化
    idx=0;
    ma.clear();
    idxx=0;
}
void solve()
{
   
    init();
    cin>>n;
    int p,q;
    cin>>p>>q;
    vector<pii> a;
    vector<int> b;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        x+=1;
        y+=1;
        if(x<=p&&y<=q) a.push_back({x,y});
        b.push_back(y);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<b.size();i++)
    {
        check(b[i]);
    }
    build(1,0,n);
    int ans=0;
    vector<int> dp(n+1,0);
    for(int i=0;i<a.size();i++)
    {
        int j=i;
        int prey=-1;
        while(j<a.size()&&a[j].x==a[i].x)
        {
            int value=ma[a[j].y];
            dp[j]=query(1,0,value-1)+1;
            modify(1,value,dp[j]);
            if(prey==-1)
            {
                root=modify1(root,0,1e9+10,a[j].y,q,dp[j]);
                prey=a[j].y;
            }
            else
            {
                root=modify1(root,0,1e9+10,a[j].y,prey-1,dp[j]);
                prey=a[j].y;
            }
            j++;

        }
        if(j==a.size())
        {
            ans+=query1(root,0,1e9+10)*(p-a[i].x+1);
        }
        else
        {
            ans+=query1(root,0,1e9+10)*(a[j].x-a[i].x);
        }
        i=j-1;

    }
    int cnt=(p + 1) * (1 + q) * q / 2 + (q + 1) * (1 + p) * p / 2;
    cout<<cnt-ans<<endl;
  
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}