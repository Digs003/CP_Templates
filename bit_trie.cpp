class trieNode{
public:
	int freq;
	trieNode* left;
	trieNode* right;
	trieNode(){
		freq=0;
		left=NULL;
		right=NULL;
	}
};

void insert(int n,trieNode* head){
	trieNode* curr=head;
	for(int i=31;i>=0;i--){
		if(n&(1<<i)){
			if(!curr->right){
				curr->right=new trieNode();
			}
			curr=curr->right;
			curr->freq++;
		}else{
			if(!curr->left){
				curr->left=new trieNode();
			}
			curr=curr->left;
			curr->freq++;
		}
	}
}

void erase(int n,trieNode* head){
	trieNode* curr=head;
	for(int i=31;i>=0;i--){
		if(n&(1<<i)){
			curr->right->freq--;
			if(curr->right->freq==0){
				delete curr->right;
				curr->right=NULL;
				return;
			}
			curr=curr->right;
		}else{
			curr->left->freq--;
			if(curr->left->freq==0){
				delete curr->left;
				curr->left=NULL;
				return;
			}
			curr=curr->left;
		}
	}
}