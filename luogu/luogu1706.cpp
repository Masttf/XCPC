#include<bits/stdc++.h>
using namespace std;
vector<int>track;
bool chose[15];
void backtarck(int n){
	if(track.size()==n){
		for(int i=0;i<n;i++){
			cout<<setw(5)<<track[i];
		}
		cout<<'\n';
	}
	for(int i=1;i<=n;i++){
		if(chose[i])continue;
		track.push_back(i);
		chose[i]=1;
		backtarck(n);
		track.pop_back();
		chose[i]=0;
	}
}
int main(){
	int n;cin>>n;
	backtarck(n);
	return 0;
}
