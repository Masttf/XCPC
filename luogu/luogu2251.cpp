#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int res[maxn];
deque<int>q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>res[i];
	}
	for(int i=1;i<=n;i++){
		while(!q.empty()&&res[i]<q.back()){
			q.pop_back();
		}
		q.push_back(res[i]);	
		if(i==m)cout<<q.front()<<'\n';
		else if(i>m){
			if(res[i-m]==q.front()){
				q.pop_front();
			}
			cout<<q.front()<<'\n';
		}
	}
	return 0;
}
//st解法
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=100005;
//int res[maxn];
//int dp[maxn][20];
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
//	int n,m;cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>res[i];
//		dp[i][0]=res[i];
//	}
//	for(int k=1;(1<<k)<=n;k++){
//		for(int s=1;s+(1<<k)<=n+1;s++){
//			dp[s][k]=min(dp[s][k-1],dp[s+(1<<(k-1))][k-1]);
//		}
//	}
//	for(int i=m;i<=n;i++){
//		int k=log2(m);
//		cout<<min(dp[i-m+1][k],dp[i-(1<<k)+1][k])<<'\n';
//	}
//	return 0;
//}
