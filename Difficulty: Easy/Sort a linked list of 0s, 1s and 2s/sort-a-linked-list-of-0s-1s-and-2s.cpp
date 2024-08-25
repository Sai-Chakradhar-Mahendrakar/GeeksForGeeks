//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        // Add code here
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* zeroHead = new Node(0); 
        Node* oneHead = new Node(0);  
        Node* twoHead = new Node(0);  
    
        Node* zeroTail = zeroHead; 
        Node* oneTail = oneHead;   
        Node* twoTail = twoHead;   
    
        Node* temp = head;
        
        while(temp!=NULL){
            if(temp->data==0){
                zeroTail->next=temp;
                zeroTail=zeroTail->next;
            }
            else if(temp->data==1){
                oneTail->next=temp;
                oneTail=oneTail->next;
            }
            else{
                twoTail->next=temp;
                twoTail=twoTail->next;
            }
            temp=temp->next;
        }
        
        zeroTail->next=oneHead->next!=NULL?oneHead->next:twoHead->next;
        oneTail->next=twoHead->next;
        twoTail->next=NULL;
        
        head=zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return head;
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends