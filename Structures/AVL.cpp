#include <iostream>
using namespace std;
template <class T>
class AVL {
private:
    template<class Type = T>
    struct AVLNode {
        Type value;
        AVLNode<T>* left;
        AVLNode<T>* right;
        AVLNode() : left(nullptr), right(nullptr), value(0) {}
        AVLNode(T el): value(el), right(nullptr), left(nullptr) {}
    };
    AVLNode<T>* root;
public:
    // Constructor
    AVL() : root(nullptr) {}
    // Function to get height of node
    int height(AVLNode<T>* node){
        if(node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
    // Function to get Balance factor of node
    int bFactor(AVLNode<T>* node){
        int lHeight = height(node->left);
        int rHeight = height(node->right);
        int bFactor = lHeight - rHeight;
        return bFactor;
    }

    // Function to handle ll case
    AVLNode<T>* llRotation(AVLNode<T>* node){
        AVLNode<T>* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        return temp;
    }

    // Function to handle rr case
    AVLNode<T>* rrRotation(AVLNode<T>* node){
        AVLNode<T>* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        return temp;
    }

    // Function to handle lr case
    AVLNode<T>* lrRotation(AVLNode<T>* node){
        AVLNode<T>* temp = node->left;
        node->left = rrRotation(temp);
        return llRotation(node);
    }

    // Function to handle rl case
    AVLNode<T>* rlRotation(AVLNode<T>* node){
        AVLNode<T>* temp = node->right;
        node->right = llRotation(temp);
        return rrRotation(node);
    }

    // Function to handle balance violations
    AVLNode<T>* balance(AVLNode<T>* node){
        int bf = bFactor(node);
        AVLNode<T>* temp;
        if(bf > 1){
            if(bFactor(node->left) > 0){
                temp = llRotation(node);
            }
            else{
                temp = lrRotation(node);
            }
        }
        else if (bf < -1){
            if(bFactor(node->right) < 0){
                temp = rrRotation(node);
            }
            else{
                temp = rlRotation(node);
            }
        }
        return temp;
    }

    // Function to balance tree
    AVLNode<T>* balanceTree(AVLNode<T>* node){
        if (node == nullptr) return nullptr;
        node->left = balanceTree(node->left);
        node->right = balanceTree(node->right);
        node = balance(node);
        return node;
    }

    // Function to search element and return parent
    AVLNode<T>* search(T val){
        if(root == nullptr) return nullptr;
        AVLNode<T>* focus = root, *parent = root;
        while (focus != nullptr){
            if(focus->value == val)
                return parent;
            else if(focus->val > val){
                parent = focus;
                focus = focus->left;
            }
            else{
                parent = focus;
                focus = focus->right;
            }
        }
        return nullptr;
    }

    // Function to insert node in tree
    void insert(T el){
        AVLNode<T>* newNode = new AVLNode<T>(el);
//        AVLNode<T>* temp = search(el);
//        if(temp != nullptr) return;
        if(root == nullptr){
            root = newNode;
            root->left = root->right = nullptr;
        }
        else{
            AVLNode<T>* focus = root, *parent = nullptr;
            while (true){
                parent = focus;
                if(el > focus->value){
                    focus = focus->right;
                    if(focus == nullptr){
                        parent->right = newNode;
                        break;
                    }
                }
                else{
                    focus = focus->left;
                    if(focus == nullptr){
                        parent->left = newNode;
                        break;
                    }
                }
            }
        }
        root = balanceTree(root);
    }

    // Function to get predecessor of specific node
    AVLNode<T>* getPredecessor(AVLNode<T>* node){
        // get first node in left subtree
        AVLNode<T>* temp = node->left;
        // go to rightmost node until reach leaf
        while (temp->right != nullptr){
            temp = temp->right;
        }
        return temp;
    }

    // Function to remove node from AVL
    AVLNode<T>* remove(T el){
        AVLNode<T>* focus, *temp, *parent = search(el);
        // node not found
        if (parent == nullptr) return nullptr;
        else{
            if(parent->right->val == el)
                focus = parent->right;
            else if(parent->left->val == el) {
                focus = parent->left;
            }
            // element is the root
            else{
                focus = parent;
                parent = nullptr;
            }
        }
        AVLNode<T>* removedNode = focus;
        // element has no children
        if(focus->left == nullptr && focus->right == nullptr){
            temp = focus;
            if(parent->left == focus){
                parent->left = nullptr;
            }
            else{
                parent->right = nullptr;
            }
            delete temp;
        }
            // element has only one child at the right
        else if(focus->left == nullptr){
            temp = focus;
            // element is left child
            if (parent->left == focus)
                parent->left = focus->right;
                // element is right child
            else{
                parent->right = focus->right;
            }
            delete temp;
        }
            // element has only one child at the left
        else if(focus->right == nullptr){
            temp = focus;
            // element is left child
            if (parent->left == focus)
                parent->left = focus->left;
                // element is right child
            else{
                parent->right = focus->left;
            }
            delete temp;
        }
            // element has two children
        else{
            // get predecessor
            AVLNode<T>* predecessor = getPredecessor(focus);
            // swap element with predecessor
            focus->val = predecessor->val;
            parent = focus;
            focus = focus->left;
            // go to rightmost node until reach predecessor position
            while (focus->right != nullptr){
                parent = focus;
                focus = focus->right;
            }
            // element is right child
            if(parent->right == focus)
                parent->right = nullptr;
                // element is left child
            else
                parent->left = nullptr;
            temp = focus;
            delete temp;
        }
        // balance tree after removal
        root = balanceTree(root);
        return removedNode;
    }

    // Function to print AVL tree
    void print(AVLNode<T>* root){
        if(root == nullptr) return;
        print(root->left);
        cout << root->value;
        print(root->right);
    }
    
    // AVL menu
    void menu(int choice){
        cout << "Choose one of the following options\n\t"
        << "1. Add student\n\t2. Remove student\n\t3. Search student\n\t4. Print All\n\t5. Return to main menu\n";
        switch (choice) {
            case 1:
                T el;
                cin >> el;
                insert(el);
                cout << "The student is added\n";
                break;
            case 2:
                int id;
                cin >> id;
                remove(id);
                break;
            default:
                break;
        }
    }

};
