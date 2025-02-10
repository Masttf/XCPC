#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)

void err() {
	cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
void solve(){
	int m;cin>>m;
	vector<int>cnt(35);
	for(int i=1;i<=m;i++){
		int t;cin>>t;
		if(t==1){
			int x;cin>>x;
			cnt[x]++;
		}else{
			vector<int>temp=cnt;
			for(int j=0;j<29;j++){
				temp[j+1]+=temp[j]/2;
				temp[j]%=2;
			}
			int x;cin>>x;
			int ok=1;
			for(int j=29;j>=0;j--){
				int f=0;
				if(x>>j&1){
					if(temp[j]<=0){
						ok=0;
						break;
					}
					else f=1;
				}
				int d=cnt[j];
				if(!d)d+=f;
				dbg(j,temp[j]);
				if(j!=0)temp[j-1]+=(temp[j]-d)*2;
				
			}
			if(ok)cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
/*
35
1 14
1 29
1 11
1 22
1 21
1 5
1 22
1 12
1 19
1 21
1 19
1 19
1 4
1 0
1 2
1 17
1 29
1 29
1 1
1 3
1 23
1 7
1 15
1 3
1 20
1 0
2 66
1 1
1 26
1 10
1 2
1 29
1 12
1 1
2 83
*/
 