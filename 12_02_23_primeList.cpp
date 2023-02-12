/*
  You are given the head of a linked list. You have to replace all the values of the nodes with the nearest prime number. If more than one prime number exists at an equal distance, choose the smallest one.

  Input:
1 → 15 → 20
Output:
2 → 13 → 19
*/
// c++ code:
class Solution
{
public:
    bool check(int n)
    {
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;

        return n >= 2;
    }
    int getVal(int n)
    {
        if (check(n))
            return n;
        int x = n;
        while (x >= 2 && !check(x))
        {
            x--;
        }
        int y = n;
        while (!check(y))
        {
            y++;
        }
        return x > 1 ? n - x <= y - n ? x : y : y;
    }
    Node *primeList(Node *head)
    {
        Node *curr = head;
        while (curr)
        {
            curr->val = getVal(curr->val);
            curr = curr->next;
        }
        return head;
    }
};