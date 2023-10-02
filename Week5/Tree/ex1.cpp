// 1. Given a tree, your task is to write a program with following functions
// ● Calculate the height of the tree.
// ● Write out the order of nodes following the preorder traversal.
// ● Write out the order of nodes following the postorder traversal.
// ● Check if the given tree is a binary tree? If yes, write out the order of nodes in inorder
// traversal.

// 5 4
// 1 2
// 1 3
// 2 4
// 2 5

// 2
// 1 2 4 5 3
// 4 5 2 3 1
// 4 2 5 1 3

// c2 
/**
 struct Node{
    int data;
    vector<Node*> child;
 };
*/

#include <bits/stdc++.h>
using namespace std;
int N , M;
int height =0;
bool visited[1001];

bool wasPrint[1001];

int parent[1001];

vector<vector<int>> tree(1001);

// luu thu tu cac nut duoc them vao tree as type preorder traversal
vector<int> orderOfNodesPre(N);

vector<int> orderOfNodesPos(N);

void dfs(int u , int he){
    orderOfNodesPre.push_back(u);
    visited[u] = true;
    for (auto x : tree[u]){
        if (!visited[x]){
            ++he;
            height = max(height , he);
            dfs(x , he);
            --he;
        }
    }
}

void posTraversal(int u){
    visited[u] = true;
    for ( auto x : tree[u]){
        if (!visited[x]){
            posTraversal(x);
        }
    }
    orderOfNodesPos.push_back(u);
}

void binaryTree(int u){
    visited[u] = true;
    for ( auto x : tree[u]){
        if (!visited[x]){
            binaryTree(x);
        }
    }
    if (!wasPrint[u]){
        cout << u << " ";
        wasPrint[u] = true;
    }
    if (wasPrint[parent[u]] == false){
        cout << parent[u] <<" ";
        wasPrint[parent[u]] = true;
    }
}

int main(){
    cin >> N >> M;
    int head;
    int checkFrequence[N];
    memset(visited , false , sizeof(visited));
    memset(checkFrequence , 0 , sizeof(checkFrequence));
    wasPrint[0] = true;
    for (int i = 1 ; i <= M ; i++){
        int x , y;
        cin >> x >> y;
        parent[y] = x;
        checkFrequence[x]++;
        checkFrequence[y]++;
        if ( i == 1){
            head = x;
        }
        tree[x].push_back(y);
    }
    dfs(head , 0);
    memset(visited , false , sizeof(visited));
    posTraversal(head);
    cout << height << endl;
    for ( auto x : orderOfNodesPre){
        cout << x << " ";
    }
    cout << endl;
    for ( auto x : orderOfNodesPos){
        cout << x << " ";
    }
    cout << endl;
    
    memset(visited , false , sizeof(visited));
    bool isBinaryTree = true;
    for (auto x : checkFrequence){
        if ( x > 3){
            isBinaryTree = false;
        }
    }
    if (!isBinaryTree){
        cout << "NOT BINARY TREE";
    }else{
        binaryTree(head);
    }
    return 0;
}
