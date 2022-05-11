<table>
  <tr>
      <th>Problem</th>
      <th>Tags</th>
  </tr>
  <tr>
      <td><a href="#1">Swap Nodes In Pairs</a></td>
      <td>Recursion</td>
  </tr>
  <tr>
      <td><a href="#2">Copy List With Random Pointer</a></td>
      <td>Hash-Table</td>
  </tr>
</table>

<br/><br/><br/><br/><br/>

<div id="1">

<h1><b>Problem</b> - <a href="https://leetcode.com/problems/swap-nodes-in-pairs/">Swap Nodes In Pairs</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. Save 2nd nodes in current pair, then point 1st node's `next` to head of remaining swapped list. <br/>
&emsp; 2. Point 2nd node's `next` to 1st node. <br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next)                // If 0 or 1 Nodes
            return head;

        ListNode *temp = head->next;            // Save 2nd node of current group of 2
        head->next = swapPairs(temp->next);     // Point HEAD's next to next group's head
        temp->next = head;                      // Point 2nd node of current group's 'next' to 'head'(1st node of curr. group)

        return temp;
    }
};
```

</div>

<br/><br/><br/><br/><br/>

<div id="2">

<h1><b>Problem</b> - <a href="https://leetcode.com/problems/copy-list-with-random-pointer/">Copy List With Random Pointer</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. In 1st pass, make `new` node for each `original` node, and make its their pair entry in a map. <br/>
&emsp; 2. In 2nd pass, assign `next` and `random` pointers to each new node. <br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(N)</b> <br/>

```
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)                                                           // No node, RETURN
            return NULL;

        map<Node*, Node*> mp;

        Node *curr = head, *newHead = NULL;

        while(curr) {
            Node* tmp = new Node(curr->val);                                // Make 'new' list's nodes
            mp[curr] = tmp;                                                 // Map 'old' nodes to 'new' nodes

            curr = curr->next;
        }

        newHead = mp[head];                                                 // Get new 'head'

        curr = head;
        while(curr) {
            mp[curr]->next   = curr->next   ? mp[curr->next]   : NULL;      // Point 'new' node's 'next' and 'random' correctly
            mp[curr]->random = curr->random ? mp[curr->random] : NULL;

            curr = curr->next;
        }

        return newHead;
    }
};
```

<br/><br/>

<h3><b><u>Approach 2</u></b></h3>

&emsp; 1. In 1st pass, make new `nodes`, and put them just after the 'original' `nodes`. <br/>
&emsp; 2. In 2nd pass, make `random` of new nodes point to original node's `next`, because that's where its equivalent new node is present.<br/>
&emsp; 3. In 3rd pass, separate the `new` and `original` lists. <br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

```
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)                                       // No node, RETURN
            return NULL;

        Node *tmp = head;

                while(tmp) {                            // Insert new(temporary) Nodes in between
            Node *newNode, *nxt = tmp->next;

                    newNode = new Node(tmp->val);       // Create New Node

                    newNode->next = tmp->next;          // Insert the New Node after original Node
            tmp->next = newNode;

                    tmp = nxt;                          // Move ahead
        }

        tmp = head;

        while(tmp) {                                    // Make 'random' pointers for new Nodes, by copying the previous node's 'random'

            if(tmp->random == NULL)                     // Make pointer to correct 'random'
                tmp->next->random = NULL;
            else
                tmp->next->random = tmp->random->next;

            tmp = tmp->next->next;                      // Move to next 'original' node
        }

        tmp = head;
        Node *newHead = head->next;

        while(tmp) {                                    // Get the original and new list
            Node *nxt = tmp->next->next;

            if(nxt)                                     // Make 'next's of New Nodes
                tmp->next->next = nxt->next;
            else
                tmp->next->next = NULL;

            tmp->next = nxt;                            // Make the original list
            tmp = nxt;
        }

        return newHead;
    }
};
```

</div>