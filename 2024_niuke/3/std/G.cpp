#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
ll s,t;
vi ans,a;
void d4(ll x){
    assert(x%16==0);
    a.pb(x/16*12); 
    a.pb(x/16*5); 
    a.pb(x/16*4);
}
void d2(ll x){
    assert(x%8==0);
    a.pb(x/8*15);
    a.pb(x/8*12);
    a.pb(x/8*5);
    a.pb(x/8*4);
}
void solve(ll x){
    ll co=1,p=x,q=1; a.clear();
    while (p%2==0) co<<=1,p>>=1;
    while (p>1){
        while (co>=16) d4(co*p*q),co>>=2;
        ll np=(p+q)/2,nq=(p-q)/2;
        co<<=1; p=np; q=nq;
        while (p%2==0) co<<=1,p>>=1;
        while (q%2==0) co<<=1,q>>=1;
        if (p<q) swap(p,q);
        assert(__gcd(p,q)==1);
        a.pb(co*p*q); 
    }
    while (co>=16) d4(co),co>>=2;
    if (co>=8) d2(co),co>>=1;
}
int main(){
    cin >> s >> t;
    if (s<=2||t<=2){
        cout << "impossible" << endl;
        return 0;
    }
    if (s==3&&t==5){
        cout << 1 << endl << 5 << endl;
        return 0;
    } else if (s==4&&t==12){
        cout << 2 << endl << 5 << endl << 12 << endl;
        return 0;
    }
    solve(s);
    for (auto x:a) ans.pb(x);
    solve(t);
    if (t!=4) a.pop_back();
    reverse(a.begin(),a.end());
    for (auto x:a) ans.pb(x);
    if (t!=4) ans.pb(t);
    assert(ans.size()<=2000);
    cout << ans.size() << endl;
    for (auto x:ans) cout << x << endl;
}