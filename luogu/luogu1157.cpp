#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
vector<int> choice;
vector<vector<int>>res;
void backtrack(int n,int r,int start,vector<int>&track);
int main(){
	int n,r;
	cin>>n>>r;
	vector<int>track;
	backtrack(n,r,1,track);
	for(int i=0;i<res.size();i++){
		for(int h=0;h<res[i].size();h++){
			cout<<setw(3) << res[i][h];
			if(h==res[i].size()-1)
				cout<<'\n';
		}
	}
	return 0;
}
void backtrack(int n,int r,int start,vector<int>&track){
	if(track.size()==r)
	{	
		res.push_back(track);
		return;
	}
	for(int i=start;i<=n;i++){
		track.push_back(i);
		backtrack(n,r,i+1,track);
		track.pop_back();
	}
}
//#include<bits/stdc++.h>
//using namespace std;
//vector<int>chose;
//void backtrack(int x,int n,int m){
//	if(chose.size()>m||chose.size()+n-x+1<m){
//		return ;
//	}
//	//base case
//	if(x==n+1){
//		for(int i=0;i<chose.size();i++){
//			cout << setw(3) << chose[i];
//		}
//		cout<<'\n';
//		return ;
//	}
//	chose.push_back(x);
//	backtrack(x+1,n,m);
//	chose.pop_back();
//	backtrack(x+1,n,m);
//}
//int main(){
//	int n,m;cin>>n>>m;
//	backtrack(1,n,m);
//	return 0;
//}
