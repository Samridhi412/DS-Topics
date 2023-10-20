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
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<char>> arr(n+1,vector<char>(m+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
		}
	}
	int q;
	cin>>q;
	vector<vector<int>> sums(n+2,vector<int>(m+2,0));
	for(int i=0;i<q;i++){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		sums[x1][y1]++;
		sums[x1][y2+1]--;
		sums[x2+1][y1]--;
		sums[x2+1][y2+1]++;
	}
	//compute prefix sum
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sums[i][j]+=sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1];
			if(sums[i][j]&1){
				arr[i][j]^=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<arr[i][j];
		}
		cout<<endl;
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}