#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }
    void put(char ch,Node *node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch)
    {
        return links[ch - 'a'];
    }
    bool setEnd(){
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};
class trie
{
private:
    Node *root;

public:
    trie()
    {
    }
    // O(word.size())
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            // move to new reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }


    bool search(string word)
    {
        Node* node = root;
        for(int i = 0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }


    bool startsWith(string prefix)
    {
        Node* node = root;
        for(int i = 0;i<prefix.length();i++)
        {
            if(!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
int main()
{
    return 0;
}