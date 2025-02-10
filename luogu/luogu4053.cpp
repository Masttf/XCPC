//要按终点排序如果能在这个时间内修好就修好不然的拿出中间最大的一段
//毕竟都是一换一我时间还短
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=150005;
struct node{
	int s,t;
	bool operator <(const node y)const{
		if(t!=y.t) return t<y.t;
		else return s<y.s;
	}
}res[maxn];
priority_queue<int>q;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>res[i].s>>res[i].t;
	sort(res+1,res+1+n);
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		sum+=res[i].s;
		cnt++;
		q.push(res[i].s);
		if(sum>res[i].t){
			sum-=q.top(),q.pop(),cnt--;
		}
	}
	cout<<cnt;
	return 0;
}
