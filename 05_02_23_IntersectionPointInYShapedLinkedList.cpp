/*
Intersection Point in Y Shaped Linked Lists

Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

Input:
Linked List 1 = 4->1->common
Linked List 2 = 5->6->1->common
common = 8->4->5->NULL
Output: 8
Explanation:

4              5
|              |
1              6
 \            /
  8  -----  1
   |
   4
   |
  5
  |
  NULL




Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)

*/
// c++ solution:
class Solution
{
public:
    int intersectPoint(Node *head1, Node *head2)
    {
        // Your Code Here
        int l1 = 0, l2 = 0;
        Node *root1 = head1, *root2 = head2;
        while (root1)
        {
            l1++;
            root1 = root1->next;
        }
        while (root2)
        {
            l2++;
            root2 = root2->next;
        }
        int x = abs(l2 - l1);
        if (l1 < l2)
        {
            while (x--)
                head2 = head2->next;
        }
        else if (l1 > l2)
        {
            while (x--)
                head1 = head1->next;
        }

        while (head1 and head1)
        {
            if (head1 == head2)
                return head2->data;
            head1 = head1->next;
            head2 = head2->next;
        }
        return -1;
    }
};