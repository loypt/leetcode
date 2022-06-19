class Trie
{
public:
    bool isWord;
    int weight;
    unordered_map<char, Trie*> child;

    Trie ()
    {
        this->isWord = false;
        this->weight = -1;
    }

    void insert(string word)
    {
        Trie * rt = this;
        for (char c: word)
        {
            if (rt->child.count(c) == 0)
                rt->child[c] = new Trie();
            rt = rt->child[c];
        }
        rt->isWord = true;
    }

    bool search(string word)
    {
        Trie* rt = this;
        for (char c: word)
        {
            if (rt->child.count(c) == 0)
                return false;
            rt = rt->child[c];
        }
        return rt->isWord == true;
    }

    bool startsWith(string word)
    {
        Trie* rt = this;
        for (char c: word)
        {
            if (rt->child.count(c) == 0)
                return false;
            rt = rt->child[c];
        }
        return true;
    }
};


class WordFilter 
{
public:
    Trie * root;

    WordFilter(vector<string>& words) 
    {
        root = new Trie();
        for (int weight = 0; weight < words.size(); weight ++)
        {
            string word = words[weight];                //apple
            string tmp = word + '#' + word;             //apple#apple
            for (int i = 0; i < word.size() + 1; i ++)
            {
                Trie* cur = root;
                for (int j = i; j < tmp.size(); j ++)   //如ple#apple
                {
                    if (cur->child.count(tmp[j]) == 0)
                        cur->child[tmp[j]] = new Trie();
                    cur = cur->child[tmp[j]];
                    cur->weight = weight;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) 
    {
        Trie* rt = root;
        string tmp = suffix + '#' + prefix;
        for (char c: tmp)
        {
            if (rt->child.count(c) == 0)
                return -1;
            rt = rt->child[c];
        }
        return rt->weight;
    }
};
