#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=1e6+3;
typedef pair<int,int>pi;
int n;
map<int,int> cnt;
priority_queue<pi> q;
vector<pi> a,ans;
int ff(int ban){
    if (q.empty()) return -1;
    pi t1=q.top(); q.pop();
    if (t1.S!=ban){
        if (t1.F>1) q.push((pi){t1.F-1,t1.S});
        return t1.S;
    }
    if (q.empty()){
        q.push(t1);
        return -1;
    }
    pi t2=q.top(); q.pop(); 
    q.push(t1);
    if (t2.F>1) q.push((pi){t2.F-1,t2.S});
    return t2.S;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++){
        int x,y; cin >> x >> y;
        if (x==y){
            cnt[x]++;
        } else {
            a.pb((pi){x,y});
        }
    }
    for (auto nd:cnt) q.push((pi){nd.S,nd.F});
    int last=-1;
    while (!q.empty()){
        int u=ff(last); 
        assert(u!=last);
        if (u==-1) break;
        ans.pb((pi){u,u});
        last=u;
    }
    if (!q.empty()){
        pi t1=q.top(); q.pop();
        int u=t1.S,cc=t1.F;
        vector<pi> b;
        for (auto t2:a){
            if (cc>0&&t2.F!=t2.S&&t2.F!=u&&t2.S!=u){
                ans.pb(t2);
                ans.pb((pi){u,u});
                cc--;
            } else {
                b.pb(t2);
            }
        }
        if (cc>0){
            cout << "No" << endl;
            exit(0);
        }
        a=b;
    } 
    for (auto t1:a){
        if (t1.F==last){
            ans.pb((pi){t1.S,t1.F});
        } else {
            ans.pb(t1);
            last=t1.S;
        }
    }
    cout << "Yes" << endl;
    for (auto t1:ans) cout << t1.F << ' ' << t1.S << endl;
    //cout << endl;
}
