#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

    public: // constructor
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* prev = head; // copy of head
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev); // create new node temp
        prev -> next = temp; // connect prev node to new temp node
        prev = temp; // move prev to temp node
    } // keep iterating through loop till all nodes linked
    return head;
}

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){ // if empty list or single element list
        return NULL;
    }
    Node* prev = head; // copy of head
    head = head->next; // move head to next node
    head->back = nullptr; // set back of new head to null
    prev->next = nullptr; // break the link of prev pointing to head node so all links are broken and node can be deleted
    delete prev; // delete prev node
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL){ // if empty list or single element list
        return NULL;
    }
    Node* tail = head; // copy of head
    while(tail->next != NULL){
        tail = tail->next; // move tail to next node till it reaches last
    }
    Node* newTail = tail->back; // make new tail the one behind tail
    newTail->next = NULL; // break the link of new tail pointing to head node so all links are broken and node can be deleted
    tail->back = nullptr; // node can be deleted
    delete tail; // delete prev node
    return head;
}

Node* deleteKthNode(Node* head, int k){
    int cnt = 0;
    Node* temp = head; // copy of head
    while(temp != NULL)
    {
        cnt++;
        if(cnt == k) break;
        temp = temp->next; // traverse the list till we reach k
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    /*EDGE CASES*/
    if(prev == NULL && front == NULL) // single element
    {
        delete temp;
        return NULL;
    }
    else if(prev == NULL){
        deleteHead(head);
        return head;
    }
    else if(front == NULL){
        deleteTail(head);
        return head; 
    }
    prev->next = front;
    front->back = prev;

    delete temp; // delete temp
    return head;
}

void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp-> next;
    if(temp->next == NULL) {
        prev->next = nullptr;
        delete temp;
    }
    prev->next = front;
    front->back = prev;
    temp->back = nullptr;
    temp->next = nullptr;
    delete temp; // delete temp
}

Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;
    return newHead;
}

Node* insertBeforeTail(Node* head, int val){
    if(head->next == NULL) {
        return insertBeforeHead(head, val);
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

Node* insertBeforeKthElement(Node* head, int k, int val){
    if(k == 1) {
        return insertBeforeHead(head, val);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp->next != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

void insertBeforeNode(Node* node, int val){
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}


void print(Node* head){
    while(head != NULL){
        cout << head->data << " " << '\n';
        head = head->next;
    }
}

int main(){
    vector<int> arr{ 23, 12, 37, 89, 46, 95 };
    Node* head = convertArr2DLL(arr);
    head = deleteHead(head);
    head = deleteKthNode(head, 3);
    deleteNode(head->next->next);
    head = insertBeforeHead(head, 100);
    head = insertBeforeTail(head, 200);
    head = insertBeforeKthElement(head, 3, 500);
    insertBeforeNode(head->next->next, 5000);
    print(head);
    return 0;
}
