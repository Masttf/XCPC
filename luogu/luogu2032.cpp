#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int res[maxn];
deque<int>q;
int main(){
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>res[i];
	}
	for(int i=1;i<=n;i++){
		while(!q.empty()&&res[i]>q.back()){
			q.pop_back();
		}
		q.push_back(res[i]);
		if(i>k){
			if(res[i-k]==q.front()){
				q.pop_front();
			}
			cout<<q.front()<<'\n';
		}else if(i==k)cout<<q.front()<<'\n';
	}
	return 0;
}
