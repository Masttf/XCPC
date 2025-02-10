#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int res[maxn];
int p2[maxn];
deque<int>r,r2;
int main(){
	int n;cin>>n;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		res[i]=res[i-1]+x;
	}
	for(int i=1;i<=n;i++){
		p2[i]=res[i]+res[n];
	}
	for(int i=1;i<=n;i++){//拿到res的最小值
		while(!r.empty()&&res[i]<r.back()){
			r.pop_back();
		}
		r.push_back(res[i]);
	}
	int cnt=0;
	if(r.front()>=0)cnt++;
	for(int i=2;i<=n;i++){
		if(res[i-1]==r.front()){//除去i之前的res最小值
			r.pop_front();
		}
		while(!r2.empty()&&p2[i-1]<r2.back()){
			r2.pop_back();
		}
		r2.push_back(p2[i-1]);
		if(r.front()-res[i-1]>=0&&r2.front()-res[i-1]>=0)cnt++;
	}
	cout<<cnt;
	return 0;
}
