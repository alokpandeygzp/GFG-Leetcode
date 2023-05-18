//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    Node *reverseSecondPart(Node *head)
    {
        Node *curr=head, *next=head, *prev=NULL;
        while(next!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node *findMiddleNode(Node *head)
    {
        Node *f=head, *s=head;
        while(f->next!=NULL && f->next->next!=NULL)
        {
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    bool isPalindrome(Node *head)
    {
        if(head==NULL || head->next==NULL)
            return true;
            
        Node *s=findMiddleNode(head);
        
        s->next=reverseSecondPart(s->next);
        s=s->next;
        
        Node *f=head;
        while(s!=NULL)
        {
            if(s->data!=f->data)
                return false;
            f=f->next;
            s=s->next;
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends