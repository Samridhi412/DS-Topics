// #include<bits/stdc++.h>
// using namespace std;
// typedef unsigned long long ull;
// typedef long long ll;
// typedef long double ld;
// const ll mod=1e9+7;
// const ld eps=1e-9;
// const ll maxn=1e5+1;
// const ll inf=5e18;
// const ll minf=-inf;
// #define mp make_pair
// #define pb push_back
// #define endl "\n"
// bool** dp;
 
// void display(vector<int>& v)
// {
// 	cout<<v.size()<<endl;
//     for (int i = 0; i < v.size(); ++i)
//         cout<<v[i]<<" ";
//     cout<<endl;
// }
// bool printSubsetsRec(vector<int>& arr, int i, int sum, vector<int>& p)
// {
//     if (i == 0 && sum > 0)
//     {
//         if(arr[i]==sum){
//         p.push_back(arr[i]);
//         // cout<<"1"<<endl;
//         display(p);
//         return true;
//     }
//     return false;
//     }
//     if (i == 0 && sum == 0)
//     {
//         // cout<<"2"<<endl;
//         display(p);
//         return true;
//     }
//     bool left=false,right=false;
//     if (dp[i-1][sum])
//     {
//         // vector<int> b = p;
//         left=printSubsetsRec(arr, i-1, sum, p);
//     }
//     if (!left&&sum >= arr[i] && dp[i-1][sum-arr[i]])
//     {
//         p.push_back(arr[i]);
//         right=printSubsetsRec(arr, i-1, sum-arr[i], p);
//     }
//     return left||right;
// }
// void printAllSubsets(vector<int>& arr, int n, ll sum)
// {
//     if (n == 0 || sum < 0)
//        return;
//     dp = new bool*[n];
//     for (int i=0; i<n; ++i)
//     {
//         dp[i] = new bool[sum + 1];
//         dp[i][0] = true;
//     }
//     if (arr[0] <= sum)
//        dp[0][arr[0]] = true;
//     for (int i = 1; i < n; ++i)
//         for (int j = 0; j < sum + 1; ++j)
//             dp[i][j] = (arr[i] <= j) ? dp[i-1][j] ||
//                                        dp[i-1][j-arr[i]]
//                                      : dp[i - 1][j];
//     if (dp[n-1][sum] == false)
//     {
//         cout<<"IMPOSIIBLE"<<endl;
//         return;
//     }
//     cout<<"POSSIBLE"<<endl;
//     vector<int> p;
//     printSubsetsRec(arr, n-1, sum, p);
// }
 
// void solve(){
// 	ll n,x,y;
// 	cin>>n>>x>>y;
// 	ll tot_sum=(n*(n+1))/2;
// 	ll new_sum=x+y;
// 	float val=(float)tot_sum/new_sum;
// 	if(floor(val)!=ceil(val)){
// 		cout<<"IMPOSSIBLE"<<endl;
// 		return;
// 	}
// 	ll find_sum=x*(int)val;
// 	vector<int> arr(n);
// 	for(int i=0;i<n;i++){
// 		arr[i]=i+1;
// 	}
//     // cout<<"*****"<<find_sum<<"*****"<<endl;
// 	printAllSubsets(arr,n,find_sum);
// }
// int main(){
// 	ios_base :: sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	ll t;
// 	cin>>t;
// 	for(int i=1;i<=t;i++){
// 		cout<<"Case #"<<i<<": ";
// 		solve();
// 	}
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;
struct node{
    string str;
    int num;
    double doub;
    char x;
    node(string str,int num,double doub,char x){
        this->str=str;
        this->num=num;
        this->doub=doub;
        this->x=x;
    }
};
array<int, 3> arr1;
namespace abcd{
    int val=50;
    int getval(){
        return 10*val;
    }
}
int main(){
    double val=10.0;
    cout<<val<<" "<<abcd::getval()<<endl;
    node nn("abcd",19,34.65,' ');
    node* nn1=new node("acde",199,345.899,'&');
    cout<<endl;
    cout<<"hello: "<<nn1->str<<" "<<nn1->num<<" "<<nn1->doub<<" "<<nn1->x<<endl;
    array<int, 3> arr2;
    cout<<arr1[0]<<" "<<arr1[1]<<" "<<arr1[2]<<endl;
    cout<<arr2[0]<<" "<<arr2[1]<<" "<<arr2[2]<<endl;
    array<int,5> arr={12,15,89,0,11};
    for(auto it=arr.begin();it!=arr.end();it++){
        cout<<*it<<" ";
    }
    cout<<"******"<<endl;
    for(auto it=arr.rbegin();it!=arr.rend();it++){
        cout<<*it<<" ";
    }
    cout<<"******"<<endl;
    for(auto it=arr.begin();it<arr.end();it++){
        cout<<*it<<" ";
    }
    cout<<"******"<<endl;
    for(auto it=arr.rbegin();it<arr.rend();it++){
        cout<<*it<<" ";
    }
    string str="abcdefgh";
    for(auto c:str){
        cout<<c<<" ";
    }
    cout<<endl<<"///////////////"<<endl;
    cout<<arr.front()<<"  "<<arr.back()<<endl;
    multiset<int> ms;
    ms.insert(2);
    ms.insert(2);
     ms.insert(2);
     ms.insert(2);
    ms.insert(2);
        ms.insert(2);
    ms.insert(1);
    ms.insert(1);
    ms.insert(3);
    // ms.erase(ms.find(1));
    ms.erase(ms.find(2),ms.find(2)+2);
    for(auto it:ms){
        cout<<it<<" ";
    }
    cout<<endl;
}