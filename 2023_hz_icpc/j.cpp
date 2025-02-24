#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n;cin>>n;
	int cnt=0;
	pair<int,int>res;
	for(int i=1;i<=n/2;i++){
		cout<<"? "<<i*2-1<<' '<<i*2<<endl;
		int d;cin>>d;
		if(d==1){
			cnt++;
			res={i*2-1,i*2};
		}
	}
	if(cnt>=2){
		cout<<"! 1"<<endl;
	}else{
		if(n%2==0&&cnt==0){
			cout<<"! 1"<<endl;
		}else{
			if(cnt==1){
				vector<int>vis(n+1);
				auto [a,b]=res;
				vis[a]=1;
				vis[b]=1;
				int now=1;
				while(vis[now])now++;
				cout<<"? "<<a<<' '<<now<<endl;
				int d;cin>>d;
				if(d==1){
					now++;
					while(vis[now])now++;
					cout<<"? "<<a<<' '<<now<<endl;
					cin>>d;
					if(d==1){
						cout<<"! 2"<<endl;
						return ;
					}else{
						cout<<"! 1"<<endl;
						return ;
					}
				}else{
					cout<<"? "<<b<<' '<<now<<endl;
					cin>>d;
					if(d==1){
						now++;
						while(vis[now])now++;
						cout<<"? "<<b<<' '<<now<<endl;
						cin>>d;
						if(d==1){
							cout<<"! 2"<<endl;
							return ;
						}else{
							cout<<"! 1"<<endl;
							return ;
						}
					}else{
						cout<<"! 1"<<endl;
						return ;
					}
				}
			}else{
				if(n%2==0){
					cout<<"! 1"<<endl;
					return ;
				}
				int a=n;
				cnt=0;
				for(int i=1;i<=3;i++){
					cout<<"? "<<i<<' '<<a<<endl;
					int d;cin>>d;
					cnt+=d;
				}
				if(cnt<=2){
					cout<<"! 1"<<endl;
					return ;
				}else{
					cout<<"! 2"<<endl;
					return ;
				}
				
				
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}