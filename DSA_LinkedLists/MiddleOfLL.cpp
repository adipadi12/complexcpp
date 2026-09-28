ListNode* middleNodeBrute(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        int midNode = count/2 + 1;
        
        ListNode* temp1 = head;
        while(temp1 != NULL){
            midNode--;
            if(midNode == 0) break;
            temp1 = temp1->next;
        }
        return temp1;

    }

ListNode* middleNodeTortoise&Hare(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast -> next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}