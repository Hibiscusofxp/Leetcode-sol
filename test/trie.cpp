#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

string words[6] = {"class", "cl", "la", "lbb", "labcd", "c"};

struct TrieNode
{
    unordered_map <char, TrieNode*> hashChilds;
    char ch;
    int count;
    string word;
    TrieNode (char cha): count(0), ch(cha) {}
};

void addTrie(TrieNode* root, const string& str)
{
    if (str == "")
        return;
    TrieNode* now = root;
    for (int i = 0; i < str.size(); i++) {
        if (now->hashChilds.find(str[i]) == now->hashChilds.end() ) {
            now->hashChilds[str[i]] = new TrieNode(str[i]);;
        }
        now = now->hashChilds[str[i]];
    }
    now->count ++;
    now->word = str;
}

void getPrefixWords(TrieNode *root, vector<string> &res)
{
    if (root == nullptr)
        return;
    if (root->count > 0 && (!root->hashChilds.empty()) ) {
        res.push_back(root->word);
    }
    for (auto p = root->hashChilds.begin(); p != root->hashChilds.end(); p++) {
        getPrefixWords(p->second, res);
    }
}

int main()
{
    vector <string> res;
    TrieNode *root = new TrieNode('#');
    for (int i = 0;i < 6; i++)
        addTrie(root, words[i]);
    getPrefixWords(root, res);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}