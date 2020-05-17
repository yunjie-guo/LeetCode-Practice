class Trie {
public:
    struct node {
        int is_leaf;
        struct node* arr[26];
    };
    
    struct node* tree_root;
    
    struct node* get_node() {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->is_leaf = 0;
        for(int i=0;i<26;i++)
            temp->arr[i] = NULL;
        return temp;
    }
    
    /** Initialize your data structure here. */
    Trie() {
        tree_root = get_node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        struct node* temp = tree_root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->arr[word[i]-'a']==NULL)
                temp->arr[word[i]-'a'] = get_node();
            temp = temp->arr[word[i]-'a'];
        }
        temp->is_leaf = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        struct node* temp = tree_root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->arr[word[i]-'a']==NULL)
                return false;
            temp = temp->arr[word[i]-'a'];
        }
        if(temp->is_leaf!=1)
            return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        struct node* temp = tree_root;
        for(int i=0;i<prefix.size();i++)
        {
            if(temp->arr[prefix[i]-'a']==NULL)
                return false;
            temp = temp->arr[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */