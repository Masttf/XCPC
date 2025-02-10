
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
#define endl '\n'
#define ls tr[u].lson
#define rs tr[u].rson
const int N=2e5+10;
struct node
{
    int lson,rson,num,sum;
}tr[N<<5];
int root,idx;
void pushup(int u)
{
    tr[u].num=tr[ls].num+tr[rs].num;
    tr[u].sum=tr[ls].sum+tr[rs].sum;
}
int modify(int u,int trl,int trr,int pos,int x)
{
    if(u==0)
    {
        u=++idx;
        ls=0;
        rs=0;
        tr[u].sum=0;
        tr[u].num=0;
    }
    if(trl==trr)
    {
        if(x==1)
        {
            tr[u].num+=1;
            tr[u].sum+=trl;
        }
        else
        {
            tr[u].num-=1;
            tr[u].sum-=trl;
        }
        return u;
    }
    else
    {
        int mid=trl+trr>>1;
        if(pos<=mid) ls=modify(ls,trl,mid,pos,x);
        else rs=modify(rs,mid+1,trr,pos,x);
        pushup(u);
        return u;
    }
}
int query(int u,int trl,int trr,int l,int r)
{
    if(u==0) return 0;
    if(l<=trl&&trr<=r)
    {
        return tr[u].sum;
    }
    else
    {
        int ans=0;
        int mid=trl+trr>>1;
        if(l<=mid) ans+=query(ls,trl,mid,l,r);
        if(r>mid) ans+=query(rs,mid+1,trr,l,r);
        return ans;
    }
}
int querynum(int u,int trl,int trr,int l,int r)
{
    if(u==0) return 0;
    if(l<=trl&&trr<=r)
    {
        return tr[u].num;
    }
    else
    {
        int ans=0;
        int mid=trl+trr>>1;
        if(l<=mid) ans+=querynum(ls,trl,mid,l,r);
        if(r>mid) ans+=querynum(rs,mid+1,trr,l,r);
        return ans;
    }
}
pair<int,int> find(int u,int trl,int trr,int l,int r,int x)
{
    if(u==0) return {-1,0};
   if(l<=trl&&trr<=r)
   {
        if(tr[u].sum<=x) return {-1,tr[u].sum};
        if(trl==trr) return {trl,tr[u].sum};
   }
   int mid=trl+trr>>1;
   pair<int,int> ans={-1,0};
   if(l<=mid)
   {
     ans=find(ls,trl,mid,l,r,x);
    if(ans.first!=-1) return ans;
   }
   if(r>mid) return find(rs,mid+1,trr,l,r,x-ans.second);
   return ans;
}

void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        root=modify(root,-1e9,1e9,a[i],1);
    }
    while(q--)
    {
        int pos,x;
        cin>>pos>>x;
       root=modify(root,-1e9,1e9,a[pos],-1);
       a[pos]=x;
       root=modify(root,-1e9,1e9,a[pos],1);
       int sum1=query(root,-1e9,1e9,-1e9,-1);
       int l=1,r=1e12;
        l=find(root,-1e9,1e9,1,1e9,-sum1).first;
       // cout<<sum1<<"aa";
        //cout<<l<<"aa"<<endl;
       //  l=1;
       // while(l<r)
       // {
       //      int mid=l+r>>1;
       //      if(query(root,-1e9-2,1e9+2,1,mid)>=-sum1) r=mid;
       //      else l=mid+1;
       // }
       // cout<<l<<"ee"<<endl;
        //dbg(l);
       if(l==-1){
            int num=querynum(root,-1e9,1e9,1,1e9);
            cout<<num+1<<endl;
       }else if(l!=1)
       {
            int t=query(root,-1e9,1e9,1,l-1);
            t=-sum1-t;
            int s=t/l;
            s+=querynum(root,-1e9,1e9,1,l-1);
            cout<<s+1<<endl;
       }else{
            int s=-sum1;
            cout<<s+1<<endl;
       }


    }

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T=1;
    while(T--) solve();
}
