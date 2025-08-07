/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        
        Node* levelStart = root;
        
        while (levelStart != nullptr) {
            Node* curr = levelStart;
            
            while (curr != nullptr) {
                if (curr->left != nullptr) {
                    if (curr->right != nullptr) {
                        curr->left->next = curr->right;
                    } else {
                        curr->left->next = getNextRight(curr);
                    }
                }
                
                if (curr->right != nullptr) {
                    curr->right->next = getNextRight(curr);
                }
                
                curr = curr->next;
            }
            
            levelStart = getNextLevelStart(levelStart);
        }
        
        return root;
    }
    
    Node* getNextRight(Node* node) {
        Node* curr = node->next;
        while (curr != nullptr) {
            if (curr->left != nullptr) return curr->left;
            if (curr->right != nullptr) return curr->right;
            curr = curr->next;
        }
        return nullptr;
    }
    
    Node* getNextLevelStart(Node* node) {
        while (node != nullptr) {
            if (node->left != nullptr) return node->left;
            if (node->right != nullptr) return node->right;
            node = node->next;
        }
        return nullptr;
    }
};