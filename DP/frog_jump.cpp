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
int frog_jump(int n,vector<int>& heights){
	if(n==0)return 0;
	if(n<0)return INT_MAX;
	return min(frog_jump(n-1,heights)+abs(heights[n]-heights[n-1]),frog_jump(n-2,heights)+abs(heights[n]-heights[n-2]));
}
void solve(){
	ll n;
	cin>>n;
	vector<int> heights(n);
	for(int i=0;i<n;i++){{
		cin>>heights[i];
	}}
	// cout<<frog_jump(n-1,heights);
	int prev1=0;
	int prev2=0;
	for(int i=1;i<n;i++){
		int op1=prev2+abs(heights[i]-heights[i-1]);
		int op2=INT_MAX;
		if(i>1){
			op2=prev1+abs(heights[i]-heights[i-2]);
		}
		int curr=min(op1,op2);
		prev1=prev2;
		prev2=curr;
	}
	cout<<prev2;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
		solve();
	return 0;
}