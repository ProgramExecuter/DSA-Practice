<h1><b>Problem</b> - <a href="https://leetcode.com/problems/reverse-linked-list/">
Reverse A Linked List</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. Traverse the linked list <br/>
&emsp; 2. Then put each node into the stack <br/>
&emsp; 3. Then pop the nodes from stack and make them point to next popping node <br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(N)</b> <br/>

```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> st;

        ListNode* tmp = head;

        while(tmp) {                        // Put all nodes into the stack
            st.push(tmp);
            tmp = tmp->next;
        }

        ListNode* dummy = new ListNode(0);  // Dummy node for making easier

        tmp = dummy;
        while(!st.empty()) {
            tmp->next = st.top();           // Point to popped node, and pop it from stack
            st.pop();
            tmp = tmp->next;                // Move to next node
        }
        tmp->next = NULL;                   // Make last node's next = NULL

        return dummy->next;                 // Dummy's next always contains the HEAD
    }

};
```

<br/><br/>

<h3><b><u>Approach 2</u></b></h3>

&emsp; 1. `prev = NULL`, previous node is <u>NULL</u> at start<br/>
&emsp; 2. Traverse the linked list <br/>
&emsp; 3. Reverse the links, i.e. make previous node as current node's <i>next</i><br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

```
class Solution {
public:
ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head;
        while(curr) {
            ListNode* nxt = curr->next;     // Save next NODE
            curr->next = prev;              // Reverse Links
            prev = curr;                    // Save PREV for next node
            curr = nxt;                     // Move ahead
        }
        head = prev;

        return head;
    }
};
```
