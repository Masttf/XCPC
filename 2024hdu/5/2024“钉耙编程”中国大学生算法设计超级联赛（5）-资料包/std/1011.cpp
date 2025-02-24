#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const int MOD=998244353;
int ksm(int a,int b){
    int ret=1;a%=MOD;
    for(;b;b>>=1,a=(ll)a*a%MOD)if(b&1)ret=(ll)ret*a%MOD;
    return ret;
}
int main(){
    fastio;
    int tc;cin>>tc;
    while(tc--){
        int n;cin>>n;
        if(n%3==2)n--;
        cout<<ksm(2,n)<<endl;
    }
    return 0;
}