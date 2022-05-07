<h1><b>Problem</b> - <a href="https://leetcode.com/problems/middle-of-the-linked-list/">Middle Of Linked List</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. Take two pointer `fast` and `slow` <br/>
&emsp; 2. `fast` moves 2X as fast as `slow`<br/>
&emsp; 3. So when `fast` reaches end, `slow` reaches middle<br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

```
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
};
```