#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    public: // constructor
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int>& arr)
{
    Node* head = new Node(arr[0]); // head is beginning of LL
    Node* mover = head; // mover is used to traverse LL
    for(int i=1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i]); // temp is used to create new nodes
        mover->next = temp; // connects the new node to the end of LL
        mover = mover->next; // moves the mover to the end of LL
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " " << '\n';
        head = head->next;
    }
}

Node* reverseListBruteWithStack(Node* head) {
    Node* temp = head; // copy of head
    stack<int> st;
    while(temp != NULL){
        st.push(temp->data); // push all elements to stack which is LIFO.
        temp =  temp->next; // traverse to end of LL
    }
    temp = head;
    while(temp != NULL){
        temp->data = st.top(); // change value of each node with that of the top of the stack
        st.pop(); // pops top most element of stack
        temp =  temp->next; // traverse to end of LL
    }
    return head;
}

Node* reverseListIterative(Node* head) {
    Node* temp = head; // copy of head
    Node* prev = NULL;
    while(temp != NULL){
        Node* front = temp->next; // front of LL stored
        temp->next = prev; // make it link backwards breaking the link with front
        prev = temp; // make prev jump to temp
        temp = front; // temp jumps 1 forward
    }
    return prev;
}

Node* reverseListRecursive(Node* head) {
    if(head == NULL || head->next == NULL) return head; // for 1 node
    Node* newHead = reverseListRecursive(head->next); // keep making new head next element till new head becomes last element
    Node* front =  head->next; // front is next of head
    front->next = head; // make front's next = head
    head->next = NULL; // head's next = NULL
    return newHead;
}

int main()
{
    vector<int> arr{ 23, 2, 3, 4, 5 };
    Node* head = convertArr2LL(arr);
    //reverseListRecursive(head); changes the value of LL itself that's why object doesn't need to be created
    Node* reverse = reverseListRecursive(head);

    print(reverse); // prints the LL after removing the first node
    return 0;
}