<h1><b>Problem</b> - <a href="https://leetcode.com/problems/linked-list-cycle/">Linked List Cycle</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. Traverse each node, and put it into a `set`<br/>
&emsp; 2. If we find a node that is already present in the set, then this linked list has a cycle <br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(N)</b> <br/>

```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> st;

        ListNode* tmp = head;

        while(tmp) {
            if(st.find(tmp) != st.end())        // This node is already been visited so there's a cycle
                return true;

            st.insert(tmp);                     // Insert this node to 'set', then move ahead
            tmp = tmp->next;
        }

        return false;
    }
};
```

<br/><br/>

<h3><b><u>Approach 2</u></b></h3>

&emsp; 1. Take two pointer `fast` and `slow`.<br/>
&emsp; 2. `fast` moves 2X faster than `slow`<br/>
&emsp; 3. So, if these two meet, then linked list has cycle<br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL  ||  head->next == NULL)        // If the list has 0 or 1 node only
            return false;

        ListNode *slow = head, *fast = head;

        while(fast  &&  fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)                            // If these pointers meet then there's a cycle
                return true;
        }

        return false;
    }
};
```
