struct node{
    int cnt;
    node* child[26];
    multiset<string>wend;
    node(){
        wend.clear();
        cnt=0;
        for(int i=0;i<26;i++){
            child[i]= NULL;
        }
    }
};

void insert(node* head,string s){
    node* curr=head;
    for(auto c:s){
        if(curr->child[c-'a']==NULL){
            curr->child[c-'a']=new node;
        }
        curr=curr->child[c-'a'];
        curr->cnt++;
        curr->wend.insert(s);
    }
}
