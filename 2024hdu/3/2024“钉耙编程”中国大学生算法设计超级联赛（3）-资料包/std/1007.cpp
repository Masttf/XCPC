#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<int, 4> State;

const int MAXN = 200000+5;
int n, q;
ll a[MAXN], b[MAXN];
State tag[MAXN<<2];

State unite(State a, State b){
    State tmp;
    tmp[0] = a[0] & b[0];
    tmp[1] = a[1] & b[1];
    tmp[2] = a[2] & b[2];
    tmp[3] = (a[1] & b[2]) | (a[1] & b[3]) | (a[3] & b[2]);
    return tmp;
}

void push_up(int x){
    tag[x] = unite(tag[x<<1], tag[x<<1|1]);
}

void build(int x, int l, int r){
    if(l == r) {
        if (b[l] == 0) tag[x][0] = 1;
        else if (b[l] > 0) tag[x][1] = 1;
        else tag[x][2] = 1;
        return;
    }
    int mid = (l+r)/2;
    build(x<<1, l, mid);
    build(x<<1|1, mid+1, r);
    push_up(x);
}

void update(int x, int l, int r, int p, int v){
    if(l == r){
        b[l] += v;
        tag[x][0] = tag[x][1] = tag[x][2] = tag[x][3] = 0;
        if (b[l] == 0) tag[x][0] = 1;
        else if(b[l] > 0) tag[x][1] = 1;
        else tag[x][2] = 1;
        return;
    }
    int mid = (l+r)/2;
    if(p <= mid) update(x<<1, l, mid, p, v);
    else update(x<<1|1, mid+1, r, p, v);
    push_up(x);
}

State query(int x, int l, int r, int L, int R){
    if(L <= l && r <= R)
        return {tag[x][0], tag[x][1], tag[x][2], tag[x][3]};
    int mid = (l+r)/2;
    if(R <= mid) return query(x<<1, l, mid, L, R);
    else if(L > mid) return query(x<<1|1, mid+1, r, L, R);
    else{
        State left = query(x<<1, l, mid, L, R);
        State right = query(x<<1|1, mid+1, r, L, R);
        return unite(left, right);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i] - a[i-1];
    }
    build(1, 2, n);
    cin >> q;
    while(q--){
        int op, l, r, x;
        cin >> op >> l >> r;
        if(op == 1){
            cin >> x;
            if(l > 1) update(1, 2, n, l, x);
            if(r < n) update(1, 2, n, r+1, -x);
        } else if(op == 2){
            if(l == r){
                cout << "1\n";
                continue;
            }
            cout << query(1, 2, n, l+1, r)[0] << "\n";
        } else if(op == 3){
            if(l == r){
                cout << "1\n";
                continue;
            }
            cout << query(1, 2, n, l+1, r)[1] << "\n";
        } else if(op == 4){
            if(l == r){
                cout << "1\n";
                continue;
            }
            cout << query(1, 2, n, l+1, r)[2] << "\n";
        } else{
            cout << query(1, 2, n, l+1, r)[3] << "\n";
        }
    }
    return 0;
}