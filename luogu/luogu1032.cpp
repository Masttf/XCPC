#include<bits/stdc++.h>
using namespace std;
vector<string> r1,r2;
int len;
string a,b;
queue<string>q;
int bfs(){
	int cnt=1;
	q.push(a);
	while(!q.empty()){
		if(cnt>10){
			return -1;
		}
		int sz=q.size();
		for(int j=1;j<=sz;j++){
			string temp=q.front();
			q.pop();
			for(int i=0;i<len;i++){
				if(temp.find(r1[i])!=temp.npos){
					int sub=-1;
					while((sub=temp.find(r1[i],sub+1))!=temp.npos){
						string a=temp;
						a.replace(sub,r1[i].size(),r2[i]);
						if(a==b)return cnt;
						q.push(a);
					}
					
				}
			}
		}
		cnt++;
	}
}
int main(){
	cin>>a>>b;
	string temp1,temp2;
	while(cin>>temp1>>temp2){
		r1.push_back(temp1);
		r2.push_back(temp2);
	}
	len=r1.size();
	int ans=bfs();
	ans==-1?cout<<"NO ANSWER!":cout<<ans;
	return 0;
}
