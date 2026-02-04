class node {
public:
    unordered_map<char, node*> children;
    bool isend;

    node() {
        isend = false;
    }
};



class Trie {
    node* root;
public:
    Trie() {
    
        root = new node();
    }

    void insert(string key) {
        node* temp = root;
        for (char c : key) {
            if (temp->children.count(c) == 0) {
                temp->children[c] = new node();
            }
            temp = temp->children[c];
        }
        temp->isend = true;
    }  
    
    
  
    
    bool search(string word) {
        node* temp = root;
        for (char c : word) {
            if (temp->children.count(c)==0){
                return false;
           
                
            }
            
             temp = temp->children[c];
               
        }
        return temp->isend;
    }
    
    bool startsWith(string prefix) {
             node* temp = root;
        for (char c : prefix) {
            if (temp->children.count(c) == 0)
                return false;
            temp = temp->children[c];
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
