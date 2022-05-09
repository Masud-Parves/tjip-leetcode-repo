class MyHashMap {
public:

    struct TreeNode
    {
        int key,value;
        TreeNode *left,*right;
        TreeNode(int k,int val): key(k), value(val),left(NULL),right(NULL) {}
        ~TreeNode(){}
    };
    TreeNode* root;
    MyHashMap() {
        root = NULL;
    }
    
    TreeNode* addNodeBST(TreeNode* root, int key, int value){
        if(root == NULL) {
            root = new TreeNode(key, value);
            return root;
        }  
        
        if(root->key == key)
            root->value = value;
        else if(root->key > key)
            root->left = addNodeBST(root->left, key, value);
        else
            root->right = addNodeBST(root->right, key, value);
        return root; 
    }
    
    TreeNode* deleteNodeBST(TreeNode* root, int key){
        if(root == NULL) return NULL;
        
        if(root->key == key){
            return helper(root);
        }
        
        TreeNode* dummy = root;
        while(root!=NULL){
            if(root->key > key){
                // on the left sub tree
                if(root->left != NULL && root->left->key == key){
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if(root->right != NULL && root->right->key == key){
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
    
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL) {
            return root->right;
        }
        if(root->right == NULL){
            return root->left;
        }
        
        TreeNode* rightChild = root->right;
        TreeNode* leftMostNode = getLeftMostNode(root->left);
        leftMostNode->right = rightChild;
        return root->left;
    }
    
    TreeNode* getLeftMostNode(TreeNode* node){
        while(node->right != NULL){
            node = node->right;
        }
        return node;
    }
    
    int searchNodeBST(TreeNode* root, int key){
        if(root == NULL) return -1;
        
        if(root->key == key) return root->value;
        if(root->key > key){
            return searchNodeBST(root->left, key);
        } else if(root->key < key){
            return searchNodeBST(root->right, key);
        }
        
        return -1;
    }
    
    
    void put(int key, int value) {
        root = addNodeBST(root, key, value);
    }
    
    
    int get(int key) {
        return searchNodeBST(root, key);
    }
    
   
    
    void remove(int key) {
        root = deleteNodeBST(root, key);
    }
};