struct Node{
    int key;
    Node* left;
    Node* right;
    int depth;
    Node(int x){
        this->key = x;
        this->left = nullptr;
        this->right = nullptr;
        this->depth = 1;
    }
};

class AVL_Tree{
public:
    int depth(Node* v){
        if(v==nullptr)return 0;
        return v->depth;
    }

    Node* rightRotate(Node* par){
        Node* child = par->left;
        par->left = child->right;
        par->depth = 1 + max(depth(par->left),depth(par->right));
        child->right = par;
        child->depth = 1 + max(depth(child->left),depth(child->right));
        par = child;
        return par;
    }

    Node* leftRotate(Node* par){
        Node* child = par->right;
        par->right = child->left;
        par->depth = 1 + max(depth(par->left),depth(par->right));
        child->left = par;
        child->depth = 1 + max(depth(child->left),depth(child->right));
        par = child;
        return par;
    }

    Node* retrace(Node* node){
        if(node==nullptr){
            return node;
        }
        //Left heavy
        if((depth(node->left) - depth(node->right)) > 1){
            if(depth(node->left->left)<depth(node->left->right)){
                node->left = leftRotate(node->left);
            }
            node = rightRotate(node);
        }

        //Right heavy
        if((depth(node->right) - depth(node->left)) > 1){
            if(depth(node->right->right)<depth(node->right->left)){
                node->right = rightRotate(node->right);
            }
            node = leftRotate(node);
        }

        node->depth = 1 + max(depth(node->left),depth(node->right));
        return node;
    }

    Node* insert(Node* node,int key){
        if(node==nullptr){
            return new Node(key);
        }
        if(key<node->key){
            node->left = insert(node->left,key);
        }
        else if(key>node->key){
            node->right = insert(node->right,key);
        }
        node = retrace(node);
        return node;
    }

    Node* getMin(Node* node){
        if(node->left){
            return getMin(node->left);
        }else{
            return node;
        }
    }

    Node* delete_node(Node* node,int key){
        if(node==nullptr){
            return node;
        }
        if(key<node->key){
            node->left = delete_node(node->left,key);
        }
        else if(key>node->key){
            node->right = delete_node(node->right,key);
        }else{
            if(!node->left && !node->right){delete node; return nullptr;}
            else if(node->left && !node->right){
                Node* tmp=node->left;
                delete node;
                return tmp;
            }
            else if(!node->left && node->right){
                Node* tmp=node->right;
                delete node;
                return tmp;
            }
            else{
                Node* tmp = getMin(node->right);
                node->key = tmp->key;
                node->right = delete_node(node->right,tmp->key);
            }
        }
        node = retrace(node);
        return node;
    }
};