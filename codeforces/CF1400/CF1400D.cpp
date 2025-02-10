#include<iostream>
#include<vector>
using namespace std;
void backtrack(vector<int>&choice,vector<int>&track,int start,int &count){
	if(track.size()==4){
		count++;
	}
	for(int i=start;i<choice.size();i++){
		if(!track.empty()&&track.size()>=2){
			if(track.size()==2&&choice[i]!=track[0]||track.size()==3&&choice[i]!=track[1])
				continue;
		}
		track.push_back(choice[i]);
		backtrack(choice,track,i+1,count);
		track.pop_back();
	}
}
int main(){
	int t;cin>>t;
	vector<int>track;
	vector<int>choice;
	while(t--){
		int n,count=0;
		int x;
		cin>>n;
		while(n--){
			cin>>x;
			choice.push_back(x);
		}
		backtrack(choice,track,0,count);
		cout<<count<<'\n';
		choice.clear();
		track.clear();	
	}
	return 0;
}
