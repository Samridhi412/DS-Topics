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
class tree{
public:
	int data;
	tree* left;
	tree* right;
	tree(int data){
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
// 1 2 4 10 11 -1 -1 12 -1 -1 -1 5 -1 -1 3 6 8 -1 -1 9 -1 -1 7 -1 -1
tree* input(){
	// cout<<"Enter the root of tree";
	int rootdata;
	cin>>rootdata;
	if(rootdata==-1){
		return NULL;
	}
		tree* root=new tree(rootdata);
	    tree* leftnode=input();
		tree* rightnode=input();
		root->left=leftnode;
		root->right=rightnode;
		return root;
}
// 1 2 3 4 5 6 7 10 -1 -1 -1 8 9 -1 -1 11 12 -1 -1 -1 -1 -1 -1 -1 -1

tree* input_levelwise(){
	int rootdata;
	cin>>rootdata;
	if(rootdata==-1){
		return NULL;
	}
	tree* root=new tree(rootdata);
	queue<tree*> q;
	q.push(root);
	while(!q.empty()){
		tree* front=q.front();
		q.pop();
		cout<<"Enter leftdata and rightdata of"<<front->data;
		int leftdata,rightdata;
		cin>>leftdata>>rightdata;
		if(leftdata!=-1){
			tree* leftnode=new tree(leftdata);
			front->left=leftnode;
			q.push(leftnode);
		}
		if(rightdata!=-1){
			tree* rightnode=new tree(rightdata);
			front->right=rightnode;
			q.push(rightnode);
		}
	}
	return root;
}
void print(tree* root){
	if(root==NULL){
		return;
	}
	cout<<root->data;
	if(root->left!=NULL){
		cout<<"L-->"<<root->left->data<<",";
	}
	if(root->right!=NULL){
		cout<<"R-->"<<root->right->data<<".";
	}
	cout<<endl;
	print(root->left);
	print(root->right);
}
void print_level(tree* root){
	if(root==NULL){
		return;
	}
	queue<tree*> q;
	q.push(root);
	while(!q.empty()){
		tree* front=q.front();
		q.pop();
		cout<<front->data<<":";
		if(front->left!=NULL){
			cout<<"L-->"<<front->left->data<<",";
			q.push(front->left);
		}
		if(front->right){
			cout<<"R-->"<<front->right->data<<".";
			q.push(front->right);
		}
		cout<<endl;
		
	}
}
int findlevel(tree* root,int k,int dist){
	if(root==NULL){
		return -1;
	}
	if(root->data==k){
		return dist;
	}
	int left=findlevel(root->left,k,dist+1);
	if(left!=-1){
		return left;
	}
	return findlevel(root->right,k,dist+1);
}
tree* finddistutil(tree* root,int& d1,int& d2,int x,int y,int& dist,int lvl){
	if(root==NULL){
		return NULL;
	}
	if(root->data==x){
		d1=lvl;
		return root;
	}
	if(root->data==y){
		d2=lvl;
		return root;
	}
	tree* left=finddistutil(root->left,d1,d2,x,y,dist,lvl+1);
	tree* right=finddistutil(root->right,d1,d2,x,y,dist,lvl+1);
	if(left&&right){
		dist=d1+d2-2*lvl;
		return root;
	}
	else if(!left){
		return right;
	}
	return left;
}

int find_dist(tree* root,int x,int y){
	if(root==NULL){
		return -1;
	}
	int d1=-1,d2=-1,dist;
	tree* lca=finddistutil(root,d1,d2,x,y,dist,1);
	//both nodes present and none is ancestor
	if(d1!=-1&&d2!=-1){
		return dist;
	}
	// n1 is the ancestor
	if(d1!=-1){
		return findlevel(lca,y,0);
	}
	if(d2!=-1){
		return findlevel(lca,x,0);
	}
	return -1;
}
void solve(){
	// tree* root1=input();
	tree* root2=input_levelwise();
	// print(root1);
	print_level(root2);
	int x,y;
	cin>>x>>y;
	cout<<find_dist(root2,x,y);
	// tree* ancestor=lca(root2,x,y);
	// if(ancestor!=NULL){
	// 	cout<<ancestor->data<<endl;
	// }
	// int d1=find_dist(ancestor,x,0);
	// int d2=find_dist(ancestor,y,0);
	// cout<< d1+d2;
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}