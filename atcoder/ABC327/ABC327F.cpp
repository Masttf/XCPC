#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)
 
void err() {
	std::cout << std::endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts &... args) {
	std::cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
struct node{
    int l,r,val;
    int tag;
};
void solve(){
    int n,d,w;cin>>n>>d>>w;
    vector<pair<int,int>>a(n+1);
    vector<int>b(n+1);
    for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second,b[i]=a[i].second;
    sort(a.begin()+1,a.end());
    sort(b.begin()+1,b.end());
    vector<node>t(n*4+1);
    auto up =[&](int l,int r,int p)->void{
        t[p].val=max(t[l].val,t[r].val);
        return ;
    };
    auto down=[&](int l,int r,int p)->void{
        t[l].val+=t[p].tag;
        t[l].tag+=t[p].tag;
        t[r].val+=t[p].tag;
        t[r].tag+=t[p].tag;
        t[p].tag=0;
        up(p<<1,p<<1|1,p);
        return ;
    };
    auto bulid =[&](auto self,int l,int r,int p)->void{
        t[p].l=l,t[p].r=r;
        if(l==r){
            return ;
        }
        int mid=(l+r)>>1;
        self(self,l,mid,p<<1);
        self(self,mid+1,r,p<<1|1);
        up(p<<1,p<<1|1,p);
    };
    bulid(bulid,1,n,1);

    auto update =[&](auto self,int l,int r,int p,int val)->void{
        if(l<=t[p].l&&t[p].r<=r){
            t[p].val+=val;
            t[p].tag+=val;
            return ;
        }
        down(p<<1,p<<1|1,p);
        int mid=(t[p].l+t[p].r)>>1;
        if(l<=mid)self(self,l,r,p<<1,val);
        if(r>mid)self(self,l,r,p<<1|1,val);
        up(p<<1,p<<1|1,p);
        return ;
    };
    int r=1;
    int ans=0;
    for(int i=1;i<=n;i++){
    	while(r<=n&&a[r].first-a[i].first<d){
    		int ll=a[r].second-w+1;
    		int p1=lower_bound(b.begin()+1,b.end(),ll)-b.begin();
    		int p2=upper_bound(b.begin()+1,b.end(),a[r].second)-b.begin()-1;
    		update(update,p1,p2,1,1);
    		r++;
    		
    	}
    	ans=max(ans,t[1].val);
    	int ll=a[i].second-w+1;
    	int p1=lower_bound(b.begin()+1,b.end(),ll)-b.begin();
    	int p2=upper_bound(b.begin()+1,b.end(),a[i].second)-b.begin()-1;
    	update(update,p1,p2,1,-1);
    }
    cout<<ans<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--)solve();
    return 0;
}
