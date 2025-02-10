#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int INF=0x3f3f3f3f;
const int N=105;
int n,a[N];
int main(){
    fastio;
    int tc;cin>>tc;
    while(tc--){
        cin>>n;
        assert(1<=n&&n<=100);
        rep(i,1,n)cin>>a[i],assert(1<=a[i]&&a[i]<=1000000);
        sort(a+1,a+n+1);
        int ans=n+1,d=a[1];
        rep(i,1,n)d=__gcd(d,a[i]);
        if(a[1]==d)ans=n-1;

        //case 1
        rep(i,1,n)rep(j,i+1,n){
            int d=a[j]%a[i];
            if(!d)continue;
            //case 1-1 
            int cnt=0;
            rep(k,1,n)if(k!=j){
                if(a[k]%d&&a[k]%a[j])cnt++;
            }
            if(!cnt)ans=min(ans,n);
        }

        //case 2
        //case 2-1
        d=0;
        rep(i,2,n)if(a[i]%a[1])d=__gcd(d,a[i]);
        if(d==0||d>=a[1])ans=min(ans,n);

        //case 2-2
        rep(i,1,n){
            int mi=INF;
            d=0;
            rep(j,1,n)if(j!=i){
                if(a[j]%a[i]){
                    d=__gcd(d,a[j]);
                    mi=min(mi,a[j]);
                }
            }
            if(d==0||mi==d)ans=min(ans,n);
        }
        cout<<ans<<endl;
    }
    return 0;
}