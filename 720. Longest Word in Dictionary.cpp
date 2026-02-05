class trinode{
public:
    bool isend;
    string word;
    vector<trinode*> child;

    trinode(){
        isend=false;
        word="";
        child.resize(26, NULL);
    }
};

class Solution {
public:

    void insert(trinode* root, string str){
        trinode* cur=root;
        for(char c: str){
            int ind=c-'a';
            if(cur->child[ind]==NULL){
                cur->child[ind]= new trinode();
            }
            cur=cur->child[ind];
        }
        cur->isend=true;
        cur->word=str;
    }

    void search(trinode* root, string &ans){
        for(int i=0;i<26;i++){
            if(root->child[i]!=NULL && root->child[i]->isend){
                string w = root->child[i]->word;

                if(w.size() > ans.size() ||
                  (w.size()==ans.size() && w < ans)){
                    ans = w;
                }
                search(root->child[i], ans);
            }
        }
    }

    string longestWord(vector<string>& words) {
        trinode* root=new trinode();

        for(string &w: words){
            insert(root, w);
        }

        string ans="";
        search(root, ans);
        return ans;
    }
};
