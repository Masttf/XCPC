#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int res[maxn];
int n,m;
deque<int>q;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>res[i];
	}
	cout<<0<<'\n';
	for(int i=1;i<=n;i++){
		while(!q.empty()&&res[i]<q.back()){
			q.pop_back();
		}
		q.push_back(res[i]);
		if(i>m){
			if(q.front()==res[i-m])q.pop_front();
		}
		cout<<q.front()<<'\n';
	}
	return 0;
}
