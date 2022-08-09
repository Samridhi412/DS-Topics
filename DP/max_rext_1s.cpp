#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
const ld eps=1e-9;
const ll maxn=1e5+1;
const ll inf=5e18;
const ll minf=-inf;
#define mp make_pair
#define pb push_back
#define endl "\n"
int lhr(vector<int>& hist,int m){
	stack<int> st;
	int maxi=-1e9;
	for(int i=0;i<=m;i++){
		while(!st.empty()&&(i==m||hist[st.top()]>hist[i])){
			
			int height=hist[st.top()];
			st.pop();
			int rightsmaller=i;
			int leftsmaller=st.empty()?-1:st.top();
			int width=leftsmaller==-1?rightsmaller:rightsmaller-leftsmaller-1;
			maxi=max(maxi,height*width);
		}
		st.push(i);
	}
	return maxi;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<vector<int>> rectangle(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>rectangle[i][j];
		}
	}
	 vector<int> histogram(m,0);
	 int maxi=-1e9;
	 for(int i=0;i<n;i++){
	 	for(int j=0;j<m;j++){
	 		if(rectangle[i][j]==1){
	 			histogram[j]+=1;
	 		}
	 		else{
	 			histogram[j]=0;
	 		}
	 		maxi=max(maxi,lhr(histogram,m));
	 	}
	 }
	 cout<<maxi;
	return 0;
}