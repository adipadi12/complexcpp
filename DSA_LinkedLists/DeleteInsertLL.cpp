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

Node* removeHead(Node* head){
    if(head == NULL) return head;
    // remove the first node and return the new head
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL; //for empty or single element list
    
    Node* temp = head;
    while(temp->next->next != NULL){ // checks for 2nd last element
        temp = temp->next;
    }
    free(temp->next); // can also use delete(temp->next) to delete the last node
    temp->next = nullptr; // removes the last node
    return head;
}

Node* removeKthElement(Node* head, int k){
    if(head == NULL) return head; // for empty list
    if(k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int cnt = 0; Node* temp = head; Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next; // removes the kth element
            free(temp);
            break;
        }
        prev = temp; // store previous to be temp
        temp = temp->next; // temp to next to be temp till it becomes NULL
    }
    return head;
}

Node* removeElement(Node* head, int el){
    if(head == NULL) return head; // for empty list
    if(head->data == el){ // if first element is the one we want to remove
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    // cnt not needed here since we already have data
    Node* temp = head; Node* prev = NULL;
    while(temp != NULL){
        if(temp->data == el){ // if we find the element to be removed
            prev->next = prev->next->next; // removes the element
            free(temp);
            break;
        }
        prev = temp; // store previous to be temp
        temp = temp->next; // temp to next to be temp till it becomes NULL
    }
    return head;
}

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head); //temp becomes new head
    return temp; // returns new head which is temp 
}

Node* insertTail(Node* head, int val){
    if(head == NULL)
        return new Node(val, NULL); // if list is empty return a new node with val and NULL next

    Node* temp = head; 
    while(temp->next != NULL){ // traverse till last element
        temp = temp->next;
    }
    Node* newNode = new Node(val, NULL); // new node with val pointing to null
    //temp->next = new Node(val, NULL); // create a
    temp->next = newNode; // temp at last position now points to new node at the end of the list
    return head;
}

Node* insertAtKthElement(Node* head, int val, int k){
    if(head == NULL){
        if(k == 1) return new Node(val, NULL); // if list is empty and k is 1 then return a new node with val and NULL next
        else return NULL; // if list is empty and k is not 1 then return null
    }
     
    if(k == 1){
        Node* temp = new Node(val, head);
        return temp;
    }
    int cnt = 0; Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k-1){
            Node* x = new Node(val, temp->next); // create a new node with val and NULL next
            x->next = temp->next; // new node points to next of temp
            temp->next = x;
            break;
        }
        temp = temp->next; // temp to next to be temp till it becomes NULL
    }
    return head;
}

Node* insertbefooreValue(Node* head, int el, int val){
    if(head == NULL){
        return NULL;
    }
     
    if(head->data == val){
        Node* temp = new Node(el, head);
        return temp;
    }

    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->data == val){
            Node* x = new Node(el, temp->next); // create a new node with val and NULL next
            temp->next = x;
            break;
        }
        temp = temp->next; // temp to next to be temp till it becomes NULL
    }
    return head;
}

int main()
{
    vector<int> arr{ 23, 2, 3, 4, 5 };
    Node* head = convertArr2LL(arr);
    
    head = insertHead(head, 69); // k element does not work like array index
    head = new Node(12, head); // can do this way as well

    head = insertTail(head, 78);
    head = insertAtKthElement(head, 47, 4);
    head = insertbefooreValue(head, 19, 23);

    print(head); // prints the LL after removing the first node
    return 0;
}