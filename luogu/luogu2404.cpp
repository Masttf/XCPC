#include<bits/stdc++.h>
using namespace std;
vector<int>track;
//利用start来维持有序
void dfs(int x,int start){
	if(x<0)return ;
	if(x==0){
		if(track.size()==1)return ;
		for(int i=0;i<track.size();i++){
			cout<<track[i];
			if(i!=track.size()-1)cout<<'+';
		}
		cout<<'\n';
		return ;
	}
	for(int i=start;i<=x;i++){
		track.push_back(i);
		dfs(x-i,i);
		track.pop_back();
	}
}
int main(){
	int n;cin>>n;
	dfs(n,1);
	return 0;
}
