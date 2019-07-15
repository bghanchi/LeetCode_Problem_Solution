#include<bits/stdc++.h>
#include<string.h>
#include<tuple>
#define all(c) c.begin(),c.end()
#define tr(i,n)  for(int i=0;i<n;i++)
#define pb push_back
#define em emplace_back
#define ll long long int
#define mp make_pair
#define mt make_tuple
#define debug(c) cout<<c<<endl;
#define find(x,v)  find(all(v),c)!=v.end()

using namespace std;
typedef vector<int>vi;
typedef vector<vi>vii;
typedef pair<int,int>pi;
typedef tuple<int,int,int>ti;

vector<vector<int>>v;

struct node{
   int num;
   node *left, *right;
}*root=NULL;

node* create_BST(node *root,int num){
    if(root==NULL){
        root=new node();
        root->num=num;
        root->left=NULL;
        root->right=NULL;
    }
    else{
        if(root->num > num){
            root->left=create_BST(root->left,num);
        }
        else{
          root->right=create_BST(root->right,num);
        }
    }
}


void preorder(queue<node*>q){
    if(!q.empty()){
        queue<node*>q1;
        vector<int>arr;
        while (!q.empty()){
            node *t=q.front();
            arr.pb(t->num);
            if(t->right!=NULL){q1.push(t->right);}
            if(t->left!=NULL){q1.push(t->left);}
            q.pop();
        }
        v.pb(arr);
        preorder(q1);

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n>0 and n-- ){
        int a;
        cin>>a;
        root=create_BST(root,a);
    }
    
    if(root!=NULL){
        queue<node*>q;
        q.push(root);
        preorder(q);

        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    else{
        cout<<"Hello  Bharat Kumar"<<endl;
    }

}

