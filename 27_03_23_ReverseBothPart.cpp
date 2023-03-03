/*
Input: 1 -> 2 -> 3 -> 4 -> 5
k = 2
Output: 2 -> 1 -> 5 -> 4 -> 3
Explanation: As k = 2 , so the first part 2
nodes: 1 -> 2 and the second part with 3 nodes:
3 -> 4 -> 5. Now after reversing the first part:
2 -> 1 and the second part: 5 -> 4 -> 3.
So the output is: 2 -> 1 -> 5 -> 4 -> 3
*/
// c++ solution:
class Solution
{
public:
    Node *reverse(Node *head, int k)
    {
        // code here

        Node *x = head;
        Node *curr = head;
        Node *prev = NULL;
        while (k--)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        Node *res = prev;
        prev = NULL;
        while (curr)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        x->next = prev;
        return res;
    }
};