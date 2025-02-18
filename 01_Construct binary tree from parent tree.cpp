#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector<int>& v) {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root) {
    vector<int> v;
    queue<Node*> q;

    q.push(root);

    Node* next_row = NULL;

    while (!q.empty()) {
        Node* n = q.front();
        q.pop();

        if (n == next_row) {
            sort_and_print(v);
            next_row = NULL;
        }

        v.push_back(n->data);

        if (n->left) {
            q.push(n->left);
            if (next_row == NULL)
                next_row = n->left;
        }

        if (n->right) {
            q.push(n->right);
            if (next_row == NULL)
                next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node* createTree(int parent[], int n);

class Solution {
  public:
    Node *createTree(vector<int> parent) {
        int n=parent.size();
        unordered_map<int,Node*> mp;
        for(int i=0;i<n;i++)
        {
            int par=parent[i];
            int child=i;
            if(mp.find(par)==mp.end()){
                mp[par]=new Node(par);
            }
            if(mp.find(child)==mp.end()){
                mp[child]=new Node(child);
            }
            if(mp[par]->left==NULL&&mp[par]->right==NULL){
                mp[par]->left=mp[child];
            }
            else if(mp[par]->left==NULL){
                mp[par]->left=mp[child];
            }
            else{
                mp[par]->right=mp[child];
            }
        }
        return mp[-1]->left;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }

        Solution ob;

        Node* res = ob.createTree(a);

        printLevelOrder(res);
        cout << endl;
    }

    return 0;
}

