#include<bits/stdc++.h>
#define int long long
using namespace std;

#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)

void err() {
    cout <<endl<<endl;
}

template<class T, class... Ts>
void err(T arg, Ts &... args) {
    std::cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
const int maxn=5e5+5;
int a[maxn];
struct node{
    int l,r,lmax,rmax,tmax,sum;
}t[maxn<<2];
void solve(){
    int n,m;cin>>n>>m;
    //vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    
    //vector<node>t(n<<2+1);
    auto up =[&](node &rt,node &l,node &r)->void{
        rt.l=l.l;
        rt.r=r.r;
        rt.sum=l.sum+r.sum;
        rt.lmax=max(l.lmax,l.sum+r.lmax);
        rt.rmax=max(r.rmax,r.sum+l.rmax);
        rt.tmax=max({l.tmax,r.tmax,l.rmax+r.lmax});
        return ;
    };
    
    auto bulid = [&](auto self,int l,int r,int p)->void{
        t[p].l=l,t[p].r=r;
        if(l==r){
            t[p].sum=a[l];
            t[p].lmax=a[l];
            t[p].rmax=a[l];
            t[p].tmax=a[l];
            return ;
        }
        int mid=(l+r)>>1;
        self(self,l,mid,p<<1);
        self(self,mid+1,r,p<<1|1);
        up(t[p],t[p<<1],t[p<<1|1]);
    };
    bulid(bulid,1,n,1);
    
    auto updata = [&](auto self,int x,int p,int val)->void{
        if(t[p].l==x&&t[p].r==x){
            //dbg(t[p].l,t[p].r);
            t[p].sum=val;
            t[p].lmax=val;
            t[p].rmax=val;
            t[p].tmax=val;
            
            return ;
        }
        int mid=(t[p].l+t[p].r)>>1;
        if(x<=mid)self(self,x,p<<1,val);
        else self(self,x,p<<1|1,val);
        up(t[p],t[p<<1],t[p<<1|1]);
        
        return ;
    };
    
    auto query = [&](auto self,int l,int r,int p)->node{
        if(l<=t[p].l&&t[p].r<=r){
            return t[p];
        }
        int mid=(t[p].l+t[p].r)>>1;
        if(r<=mid)return self(self,l,r,p<<1);
        else if(l>mid)return self(self,l,r,p<<1|1);
        else{
            node res;
            node temp1=self(self,l,r,p<<1);
            node temp2=self(self,l,r,p<<1|1);
            up(res,temp1,temp2);
            return res;
        }
    };
    
    while(m--){
        int t,x,y;cin>>t>>x>>y;
        if(t==1){
            if(x>y)swap(x,y);
            cout<<query(query,x,y,1).tmax<<'\n';
        }else{
            updata(updata,x,1,y);
        }
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--)solve();
    return 0;
}