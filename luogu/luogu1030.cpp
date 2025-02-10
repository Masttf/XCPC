//根据中序和后序遍历结果构建二叉树
#include<iostream>
#include<unordered_map>
using namespace std;
string perorder;
unordered_map<char,int>map;
string bulid(string inorder,int instart,int inend,string enorder,int endstart,int endend);
int main(){
	string inorder,endorder;
	cin>>inorder>>endorder;
	for(int i=0;i<inorder.size();i++){
		map[inorder[i]]=i;
	}
	cout<<bulid(inorder,0,inorder.size()-1,endorder,0,endorder.size()-1)<<'\n';
	return 0;
}
//定义给出中序遍历结果和后续遍历结果返回前序遍历结果
string bulid(string inorder,int instart,int inend,string enorder,int endstart,int endend){
	if(instart>inend){
		return "";
	}
	string perorder;
	perorder+=enorder[endend];
	int index=map[enorder[endend]];
	int len=index-instart;
	perorder+=bulid(inorder,instart,index-1,enorder,endstart,endstart+len-1);
	perorder+=bulid(inorder,index+1,inend,enorder,endstart+len,endend-1);
	return perorder;
	
}
