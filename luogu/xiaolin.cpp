#include<bits/stdc++.h>
//#define int long long
using namespace std;
struct node{
    int l,r,val,sz;
};
void solve(){
    int n,m;cin>>n>>m;
    vector<int>root(m+1);
    int tot=0;
    int last=0;
    vector<node>tr(n*80);
    auto bulid = [&](auto self,int &u,int l,int r)->void{
        u=++tot;
        if(l==r){
            tr[u].val=l;
            tr[u].sz=1;
            return ;
        }
        int mid=(l+r)>>1;
        self(self,tr[u].l,l,mid);
        self(self,tr[u].r,mid+1,r);
    };

    auto query = [&](auto self,int u,int l,int r,int x)->int{
        if(l==r)return u;
        int mid=(l+r)>>1;
        if(x<=mid)return self(self,tr[u].l,l,mid,x);
        else return self(self,tr[u].r,mid+1,r,x);
    };

    auto find = [&](int x,int rt)->int{
        int f=query(query,root[rt],1,n,x);
        while(tr[f].val!=x){
            x=tr[f].val;
            f=query(query,root[rt],1,n,x);
        }
        return f;
    };
    auto updata1 = [&](auto self,int &u,int v,int l,int r,int x,int fa)->void{
        u=++tot;
        tr[u]=tr[v];
        if(l==r){
            tr[u].val=fa;
            return ;
        }
        int mid=(l+r)>>1;
        if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x,fa);
        else self(self,tr[u].r,tr[v].r,mid+1,r,x,fa);
    };

    auto updata2 = [&](auto self,int &u,int v,int l,int r,int x,int val)->void{
        if(u<=last){
            u=++tot;
            tr[u]=tr[v];
        }
        if(l==r){
            tr[u].sz+=val;
            return ;
        }
        int mid=(l+r)>>1;
        if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x,val);
        else self(self,tr[u].r,tr[v].r,mid+1,r,x,val);
    };

    auto merge = [&](int a,int b,int rt)->void{
        a=find(a,rt-1);
        b=find(b,rt-1);
        int fa=tr[a].val;
        int sza=tr[a].sz;
        int fb=tr[b].val;
        int szb=tr[b].sz;
        if(fa==fb){
            root[rt]=root[rt-1];
            return ;
        }
        if(sza>szb){
            swap(fa,fb);
            swap(sza,szb);
        }
        updata1(updata1,root[rt],root[rt-1],1,n,fa,fb);
        updata2(updata2,root[rt],root[rt-1],1,n,fb,sza);
        return ;
    };
    bulid(bulid,root[0],1,n);
    for(int i=1;i<=m;i++){
        last=tot;
        int t;cin>>t;
        if(t==1){
            int a,b;cin>>a>>b;
            merge(a,b,i);
        }else if(t==2){
            int k;cin>>k;
            root[i]=root[k];
        }else{
            root[i]=root[i-1];
            int a,b;cin>>a>>b;
            int fa=tr[find(a,i-1)].val;
            int fb=tr[find(b,i-1)].val;
            if(fa==fb)cout<<1<<'\n';
            else cout<<0<<'\n';
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