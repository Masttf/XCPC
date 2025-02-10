#include <bits/stdc++.h>

#define Max 100005

using namespace std;

const int mod=1e9+7;

struct Tree{
    int lazy,num,p;
}st[2][Max*4];

int T,n,m,ans,cnt,inv;
set<int>S;

inline int qpow(int x,int y){
    int ans=1;
    while(y){
        if(y&1)ans=1ll*ans*x%mod;
        x=1ll*x*x%mod;
        y>>=1;
    }
    return ans;
}

inline Tree up(Tree L,Tree R,int q){
    Tree now;
    now.lazy=0;
    if(L.p==-1&&R.p==-1){
        now.p=-1;
        return now;
    }
    if(L.p==-1){
        now.p=R.p;
        now.num=R.num;
        return now;
    }
    if(R.p==-1){
        now.p=L.p;
        now.num=L.num;
        return now;
    }
    if(q==0){
        if(L.num<=R.num){
            now.p=L.p;
            now.num=L.num;
        }else{
            now.p=R.p;
            now.num=R.num;
        }
    }else{
        if(L.num>=R.num){
            now.p=L.p;
            now.num=L.num;
        }else{
            now.p=R.p;
            now.num=R.num;
        }
    }
    return now;
}

inline void down(int node,int q){
    if(!st[q][node].lazy)return;
    st[q][node<<1].lazy+=st[q][node].lazy;
    st[q][node<<1|1].lazy+=st[q][node].lazy;
    st[q][node<<1].num+=st[q][node].lazy;
    st[q][node<<1|1].num+=st[q][node].lazy;
    st[q][node].lazy=0;
    return;
}

inline void build(int node,int L,int R,int q){
    if(L==R){
        st[q][node].p=-1;
        return;
    }
    st[q][node].lazy=0;
    int mid=(L+R)>>1;
    build(node<<1,L,mid,q);
    build(node<<1|1,mid+1,R,q);
    st[q][node]=up(st[q][node<<1],st[q][node<<1|1],q);
}

inline void change(int node,int l,int r,int L,int R,int q,int k){
    if(l>r)return;
    if(L>=l&&R<=r){
        st[q][node].lazy+=k;
        st[q][node].num+=k;
        return;
    }
    down(node,q);
    int mid=(L+R)>>1;
    if(l<=mid)change(node<<1,l,r,L,mid,q,k);
    if(r>mid)change(node<<1|1,l,r,mid+1,R,q,k);
    st[q][node]=up(st[q][node<<1],st[q][node<<1|1],q);
    return;
}

inline void change2(int node,int id,int L,int R,int q,int k){
    if(L==R){
        if(k==-1){
            st[q][node].p=-1;
        }else{
            st[q][node].p=L;
            if(q==0){
                st[q][node].num=1;
            }else{
                st[q][node].num=-1;
            }
        }
        return;
    }
    down(node,q);
    int mid=(L+R)>>1;
    if(id<=mid)change2(node<<1,id,L,mid,q,k);
    else change2(node<<1|1,id,mid+1,R,q,k);
    st[q][node]=up(st[q][node<<1],st[q][node<<1|1],q);
    return;
}

inline Tree query(int node,int l,int r,int L,int R,int q){
    if(l>r)return (Tree){0,0,-1};
    if(L>=l&&R<=r)return st[q][node];
    down(node,q);
    int mid=(L+R)>>1;
    if(r<=mid)return query(node<<1,l,r,L,mid,q);
    if(l>mid)return query(node<<1|1,l,r,mid+1,R,q);
    return up(query(node<<1,l,r,L,mid,q),query(node<<1|1,l,r,mid+1,R,q),q);
}

int main(){
    freopen("1.in","r",stdin);
    freopen("3.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    inv=qpow(2,mod-2);
    while(T--){
        cin>>n>>m;
        build(1,1,n,0);
        build(1,1,n,1);
        S.clear();
        for(int i=1;i<=n;i++)S.insert(i);
        ans=cnt=0;
		for(int i=1;i<=m;i++){
			int l,r;
			cin>>l>>r;
			l++;
			int p,q;
            auto it=S.lower_bound(l);
            if(it!=S.end())p=*it;else p=-1;
            Tree now=query(1,l,n,1,n,1);
            if(now.p!=-1&&now.num==-1)q=now.p;else q=-1;
//			cout<<p<<"!"<<q<<endl;
			bool flag=1;
			if(p==q&&p==-1){
                change(1,l,r,1,n,0,1);
                change(1,l,r,1,n,1,1);
				flag=0;
			}else if(p!=-1&&(q==-1||p<q)){
				ans=(ans+n-p)%mod;
				cnt++;
                change(1,l,p,1,n,0,1);
                change(1,l,p,1,n,1,1);
                S.erase(p);
                change2(1,p,1,n,0,1);
			}else{
				ans=(ans+n-q+1)%mod;
				cnt--;
                change(1,l,q,1,n,0,1);
                change(1,l,q,1,n,1,1);
                change2(1,q,1,n,1,-1);
                S.insert(q);
			}
//			cout<<ans<<" "<<cnt<<" "<<flag<<endl;
			if(flag){
                now=query(1,r+1,n,1,n,0);
                if(now.p!=-1&&now.num==1)p=now.p;else p=-1;
                it=S.lower_bound(r+1);
                if(it!=S.end())q=*it;else q=-1;
				if(p==q&&p==-1){
                    change(1,r+1,n,1,n,0,-1);
                    change(1,r+1,n,1,n,1,-1);
				}else if(p!=-1&&(q==-1||p<q)){
					ans=(ans-(n-p)+mod)%mod;
					cnt--;
                    change(1,r+1,p,1,n,0,-1);
                    change(1,r+1,p,1,n,1,-1);
                    change2(1,p,1,n,0,-1);
                    S.insert(p);
				}else{
					ans=(ans-(n-q+1)+mod)%mod;
					cnt++;
                    change(1,r+1,q,1,n,0,-1);
                    change(1,r+1,q,1,n,1,-1);
                    S.erase(q);
                    change2(1,q,1,n,1,1);
				}
			}
//			cout<<ans<<" "<<cnt<<endl;
			cout<<(ans+1ll*cnt*inv%mod)%mod<<'\n';
		}
    }
    return 0;
}
