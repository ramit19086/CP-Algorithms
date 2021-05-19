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

public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(int val)
    {
        Node *curr = root;
        for (int i = 31; i >= 0; i--)
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
        for(int i=31;i>=0;i--)
        {
            bool b = (val>>i)&1;
            curr->child[b]->cnt -= 1;
            curr = curr->child[b];  
        }
    }

    // MAKE YOUR QUERY FUNCTION HERE
    
    void Query() {}

    ~Trie()
    {
        delete root;
        root = NULL;
    }
};
