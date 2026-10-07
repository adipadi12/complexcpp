bool hasCycleBrute(ListNode *head) {
        unordered_map<ListNode*, int> mpp;
        ListNode* temp = head;
        while(temp != NULL)
        {
            if(mpp.find(temp) != mpp.end()) return true;
            mpp[temp] = 1;
            temp = temp->next;
        }
        return false;
    }
bool hasCycleBetter(ListNode *head) {
        // unordered_map<ListNode*, int> mpp;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) // for even and odd linear LLs
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) return true;
        }
        return false;
    }