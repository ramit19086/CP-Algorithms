#include <bits/stdc++.h>
using namespace std;

class Trie
{
private:
    class Node
    {
    public:
        Node *child[2];
        int cnt;
        Node()
        {
            child[0] = NULL;
            child[1] = NULL;
            cnt = 0;
        }
        ~Node()
        {
            delete child[0], delete child[1];
            child[0] = NULL, child[1] = NULL;
        }
    };
    int bits = 31;    //handle accrodingly and remember to 1LL << i when increasing the bits;

public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(int val)
    {
        Node *curr = root;
        for (int i = bits; i >= 0; i--)
        {
            bool b = (val >> i) & 1;
            if (curr->child[b] == NULL)
                curr->child[b] = new Node();
            curr->child[b]->cnt += 1;
            curr = curr->child[b];
        }
    }
    
    void remove(int val)
    {
        Node *curr = root;
        for(int i = bits; i >= 0; i--)
        {
            bool b = (val >> i) & 1;
            curr->child[b]->cnt -= 1;
            curr = curr->child[b];  
        }
    }
    
    int Max_XOR(int val) {
        Node* curr = root;
        int ans = 0;
        for (int i = bits; i >= 0; i--)
        {
            bool b = (val >> i) & 1;
            if (curr->child[1 - b] != NULL and curr->child[1 - b]->cnt > 0)
                ans |= 1LL << i, curr = curr->child[1 - b];
            else
                curr = curr->child[b];
        }
        return ans;
    }
    
    int count_xor_greaterthan(int val,int k) 
    {
        Node* curr = root;
        int ans = 0;
        for(int i = 31;i>=0;i--)
        {
            bool b1 = (val >> i) & 1;
            bool b2 = (k >> i) & 1;
            if(b2)
            {
                if(curr->child[1-b1] == NULL||curr->child[1-b1] == 0)
                    return ans;
                curr = curr->child[1-b1];
            }
            else
            {
                if(curr->child[1-b1] != NULL)
                    ans += curr->child[1-b1]->cnt;
                if(curr->child[b1] != NULL)
                    curr = curr->child[b1];
                else
                    return ans;
            }
        }
       return ans + curr->cnt;
    }

    // MAKE YOUR QUERY FUNCTION HERE
    
    void Query() {}

    ~Trie()
    {
        delete root;
        root = NULL;
    }
};
