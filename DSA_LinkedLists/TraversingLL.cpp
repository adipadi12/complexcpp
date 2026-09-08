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

int sizeOfLL(vector<int>& arr)
{
    int cnt = 0;
    Node* head = new Node(arr[0]); // head is beginning of LL
    Node* mover = head; // mover is used to traverse LL
    for(int i=1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i]); // temp is used to create new nodes
        mover->next = temp; // connects the new node to the end of LL
        mover = mover->next; // moves the mover to the end of LL
        cnt++;
    }
    return cnt + 1;
}

bool checkIfPresent(Node* head, int value){
    Node* mover = head;
    while(mover){
        if(mover->data == value) return true;
        mover = mover->next;
    }
    return false;
}

int main()
{
    vector<int> arr{ 23, 2, 3, 4, 5 };
    Node* head = convertArr2LL(arr);
    cout << head << endl; // gives address of head
    cout << head->data << endl; // gives you data of head
    cout << head->next <<endl; // gives address of next node
    cout << sizeOfLL(arr) << endl;
    cout << boolalpha << checkIfPresent(head, 23) << endl;
    return 0;
}