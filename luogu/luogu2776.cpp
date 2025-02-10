#include<bits/stdc++.h>
using namespace std;
const int t=305,N=100005;
queue<int>q[305];//记录每个组
int f[N];//先用f来记录每个点的值属于那个组
int main(){
	int n,m;cin>>n>>m;
	int x;
	for(int i=0;i<=m;i++){
		q[i]=queue<int>();
	}
	for(int i=0;i<n;i++){
		cin>>x;
		f[i]=x+1;
	}
	int T;cin>>T;
	string a="";
	while(T--){
		cin>>a;
		if(a=="push"){
			cin>>x;
			if(q[f[x]].empty()){//如果是空说明这个组的其他人都没来过
				q[f[x]].push(x);
				q[0].push(f[x]);//总队列加入该小组
			}else{
				q[f[x]].push(x);
			}
		}else{
			cout<<q[q[0].front()].front()<<'\n';
			q[q[0].front()].pop();//如果这个小组人都走完了
			if(q[q[0].front()].empty()){
				q[0].pop();
			}
		}
	}
	return 0;
}
