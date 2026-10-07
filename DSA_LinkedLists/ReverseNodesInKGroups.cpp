ListNode* getKthNode(ListNode* temp, int k){
        k -= 1;
        while(temp != NULL && k > 0){
            k--;
            temp = temp -> next;
        }
        return temp;
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head; // for 1 node
        ListNode* newHead = reverseList(head->next); // keep making new head next element till new head becomes last element
        ListNode* front =  head->next; // front is next of head
        front->next = head; // make front's next = head
        head->next = NULL; // head's next = NULL
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL)
        {
            ListNode* KNode = getKthNode(temp, k);
            if(KNode == NULL){
                if(prev) prev->next = temp; // link remaining tail as is
                break;
            }

            ListNode* nextNode = KNode -> next; // save new node
            KNode -> next = NULL; // point k nodes next to null to cut group off
            reverseList(temp); // reverse current group
            if(temp == head) // 
            {
                head = KNode; // update overall head
            }
            else{
                prev->next = KNode; // this group onto previous group
            }
            prev = temp; // temp now tail of group
            temp = nextNode; // move to next group
        }
        return head;
    }