#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int pre[maxn];
deque<int>q;
signed main(){
	int n,m;cin>>n>>m;
	int x;
	for(int i=1;i<=n;i++)cin>>x,pre[i]=pre[i-1]+x;
	int ans=pre[1];
	for(int i=1;i<n;i++){
		while(!q.empty()&&pre[i]<q.back()){
			q.pop_back();
		}
		q.push_back(pre[i]);
		if(i>m){
			if(pre[i-m]==q.front()){
				q.pop_front();
			}
		}
		ans=max(ans,pre[i+1]-q.front());
	}
	cout<<ans;
	return 0;
}
