ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> mpp;
        ListNode* temp = head;
        while(temp != NULL)
        {
            if(mpp.find(temp) != mpp.end()) return temp;
            mpp[temp] = 1;
            temp = temp->next;
        }
        return NULL;
    }

    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycleOptimalTortoiseHare(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) // for even and odd linear LLs
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)
            {
                slow = head;
                while(slow != fast)
                {
                    slow = slow -> next;
                    fast = fast -> next;
                    
                }
                if(slow == fast)
                    return slow;
            }
        }
        return NULL;
    }
};