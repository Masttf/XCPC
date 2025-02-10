#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 5e2 + 2;
int n,m,a,b,c,nx,ny;
vector<array<int,4>>ans;
int mp[N][N],mp1[N][N],mp2[N][N],dx[]={0,-1,0,0},dy[]={-1,0,0,0};
int check(int x,int y){
    return 0<=x&&x<=n&&0<=y&&y<=m;
}
int check2(int x,int y){
    return 0<=x&&x<n&&0<=y&&y<=m;
}
int check1(int x,int y){
    return 0<=x&&x<=n&&0<=y&&y<m;
}
void solve() {
    cin>>n>>m>>a>>b>>c;
    int cnt=(n+1)*((m+1)/2);
    for(int i=1;i<=c&&i<=cnt;i++){
        ans.push_back({nx,ny,nx+1,ny+1001});
        mp[nx/1000][ny/1000]=mp[nx/1000][ny/1000+1]=1;
        mp1[nx/1000][ny/1000]=1;
        nx+=1000;
        if(nx>1000*n+1){
            nx=0,ny+=2000;
        }
    }
    for(int i=cnt+1;i<=c;i++){
        ans.push_back({nx,ny,nx+1001,ny+1});
        mp[nx/1000][ny/1000]=mp[nx/1000+1][ny/1000]=1;
        mp2[nx/1000][ny/1000]=1;
        nx+=2000;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(mp[i][j]==0){
                for(int k=0;k<4;k++){//awds
                    int ni=i+dx[k],nj=j+dy[k];
                    if(k%2==0){
                        if(check1(ni,nj)==0)continue;
                        if(mp1[ni][nj]==0){
                            if(k==0){
                                ans.push_back({ni*1000,nj*1000+1,ni*1000+1,nj*1000+1001});
                            }
                            if(k==2){
                                ans.push_back({ni*1000,nj*1000,ni*1000+1,nj*1000+1000});
                            }//
                            mp1[ni][nj]=1;
                            break;
                        }
                    }else{
                        if(check2(ni,nj)==0)continue;
                        if(mp2[ni][nj]==0){
                            if(k==1){
                                ans.push_back({ni*1000+1,nj*1000,ni*1000+1001,nj*1000+1});
                            }
                            if(k==3){
                                ans.push_back({ni*1000,nj*1000,ni*1000+1000,nj*1000+1});
                            }
                            mp2[ni][nj]=1;
                            break;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            if(mp2[i][j]==0){
                ans.push_back({i*1000+1,j*1000,i*1000+1000,j*1000+1});
                mp2[i][j]=1;
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<m;j++){
            if(mp1[i][j]==0){
                ans.push_back({i*1000,j*1000+1,i*1000+1,j*1000+1000});
                mp1[i][j]=1;
            }
        }
    }
    assert(a+b+c==ans.size());
    for(auto x:ans){
        cout<<x[0]<<' '<<x[1]<<' '<<x[2]<<' '<<x[3]<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
//    cin >> tc;
    while (tc--) solve();
    return 0;
}
