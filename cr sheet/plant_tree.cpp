#include<bits/stdc++.h>
using namespace std;
int dx[8]={-1,1,0,0,-1,1,1,-1};
int dy[8]={0,0,1,-1,-1,-1,1,1};
bool possible(int u,int v,vector<string>& arr,int n,int m,set<pair<int,int>> &s){
	if(u<0||u>=n||v<0||v>=m||arr[u][v]=='#'||s.find({u,v})!=s.end()){
		return false;
	}
	return true;
}
void helper(vector<string>& arr,int n,int m,int i,int j,set<pair<int,int>> &s){
	for(int k=0;k<8;k++){
		if(possible(i+dx[k],j+dy[k],arr,n,m,s)){
		s.insert({i+dx[k],j+dy[k]});	
		}
	}
	return;
}
int solution(vector<string> &arr){
	int n=arr.size();
	int m=arr[0].size();
	set<pair<int,int>> st;
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]=='#'){
				count++;
				helper(arr,n,m,i,j,st);
			}
		}
	}
	cout<<st.size();
	return n*m-st.size()-count;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<string> arr;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char ch;
			cin>>ch;
		}
	}
	cout<<solution(arr);
	return 0;
}