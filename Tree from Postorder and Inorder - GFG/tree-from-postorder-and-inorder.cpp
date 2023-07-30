//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node *constructTree(int post[], int pStart, int pEnd, int in[], int iStart, int iEnd,int n)
{
    if(pStart>pEnd || iStart>iEnd)
        return NULL;
    
    Node *root = new Node(post[pEnd]);
    int inRoot=0;
    for(int i=0;i<n;i++)
    {
        if(in[i]==post[pEnd])
        {
            inRoot=i;
            in[i]=-1;
            break;
        }
    }
    int numsLeft=inRoot-iStart;
    
    root->left = constructTree(post, pStart, pStart+numsLeft-1, in, iStart, inRoot - 1,n);
    root->right = constructTree(post, pStart + numsLeft, pEnd-1, in, inRoot + 1, iEnd,n);
    
    return root;
}
Node *buildTree(int in[], int post[], int n)
{
    return constructTree(post,0,n-1,in,0,n-1,n);
}
