#include<bits/stdc++.h>
using namespace std;
vector<int>track;
int cot[1000005];
void dfs(int n,int s){
	if(s>n||track.size()>n)return ;
	if(track.size()==n&&s==n){
		int flag=1;
		int len=track.size();
		for(int i=0;i<len;i++){
			if(track[i]!=cot[i]){
				flag=0;
			}
		}
		if(flag){
			for(int i=0;i<len;i++){
				cout<<track[i]<<' ';
			}
			cout<<'\n';
		}
	}
	for(int i=0;i<n;i++){
		track.push_back(i);
		cot[i]++;
		dfs(n,s+i);
		track.pop_back();
		cot[i]--;
	}
}
int main(){
	int n;cin>>n;
//	if(n==4)cout<<"1 2 1 0";
//	else if(n==5)cout<<"2 1 2 0 0";
//	else cout<<-1;
	dfs(n,0);
	return 0;
}
