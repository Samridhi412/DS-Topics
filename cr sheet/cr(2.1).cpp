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
	vector<string> vect(n);
	for(int i=0;i<n;i++){
		cin>>vect[i];
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int j=x1-1;j<x2;j++){
			for(int k=y1-1;k<y2;k++){
				vect[j][k]=vect[j][k]^1;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<vect[i]<<endl;
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}