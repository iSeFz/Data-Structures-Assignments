#ifndef _AVL_HPP
#define _AVL_HPP

#include <iostream>
#include <map>
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
    map<string , int> deptCount;
public:
    // Constructor
    AVL() : root(nullptr) {}
    // Function to get height of node
    int height(AVLNode<T>* node){
        if(node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
    // Function to check whether tree is empty or not
    bool isEmpty(){
        return root == nullptr;
    }
    
    // Function to get Balance factor of node
    int bFactor(AVLNode<T>* node){
        // calculate height from left
        int lHeight = height(node->left);
        // calculate height from right
        int rHeight = height(node->right);
        // calculate balance factor
        int bFactor = lHeight - rHeight;
        return bFactor;
    }

    // Function to handle ll case
    AVLNode<T>* llRotation(AVLNode<T>* node){
        // get left child of node
        AVLNode<T>* temp = node->left;
        // make left subtree of node is right subtree of temp
        node->left = temp->right;
        // make temp right subtree is node after node take its right subtree
        temp->right = node;
        return temp;
    }

    // Function to handle rr case
    AVLNode<T>* rrRotation(AVLNode<T>* node){
        // get right child of node
        AVLNode<T>* temp = node->right;
        // make right subtree of node is left subtree of temp
        node->right = temp->left;
        // make temp left subtree is node after node take its left subtree
        temp->left = node;
        return temp;
    }

    // Function to handle lr case
    AVLNode<T>* lrRotation(AVLNode<T>* node){
        // get left child of node
        AVLNode<T>* temp = node->left;
        // make left subtree link to correct node of right subtree and this lead to ll case
        node->left = rrRotation(temp);
        // fix ll case
        return llRotation(node);
    }

    // Function to handle rl case
    AVLNode<T>* rlRotation(AVLNode<T>* node){
        // get right child of node
        AVLNode<T>* temp = node->right;
        // make right subtree link to correct node of left subtree and this lead to rr case
        node->right = llRotation(temp);
        // fix rr case
        return rrRotation(node);
    }

    // Function to handle balance violations
    AVLNode<T>* balance(AVLNode<T>* node){
        int bf = bFactor(node);
        AVLNode<T>* temp = node;
        // ll or lr cases
        if(bf > 1){
            // fix ll case
            if(bFactor(node->left) > 0){
                temp = llRotation(node);
            }
            // fix lr case
            else{
                temp = lrRotation(node);
            }
        }
        // rr or rl cases
        else if (bf < -1){
            // fix rr case
            if(bFactor(node->right) < 0){
                temp = rrRotation(node);
            }
            // fix rl case
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

    // Function to search node and return parent and child
    pair<AVLNode<T>*,AVLNode<T>*> search(T val){
        // AVL tree is empty
        if(root == nullptr) return {nullptr, nullptr};
        AVLNode<T>* focus = root, *parent = root;
        while (focus != nullptr){
            // node found return this node and its parent
            if(focus->value == val)
                return {parent,focus};
            else if(focus->value > val){
                parent = focus;
                focus = focus->left;
            }
            else{
                parent = focus;
                focus = focus->right;
            }
        }
        // not found
        return {nullptr, nullptr};
    }

    // Function to insert node in tree
    bool insert(T el){
        AVLNode<T>* temp = search(el).second;
        // element exist before don't insert it
        if(temp != nullptr) return false;
        // create new node
        AVLNode<T>* newNode = new AVLNode<T>(el);
        deptCount[el.getDept()]++;
        // AVL tree is empty
        if(isEmpty()){
            root = newNode;
            root->left = root->right = nullptr;
        }
        else{
            AVLNode<T>* focus = root, *parent = nullptr;
            while (true){
                parent = focus;
                if(el > focus->value){
                    // go right until reach leaf
                    focus = focus->right;
                    if(focus == nullptr){
                        parent->right = newNode;
                        break;
                    }
                }
                else{
                    // go left until reach leaf
                    focus = focus->left;
                    if(focus == nullptr){
                        parent->left = newNode;
                        break;
                    }
                }
            }
        }
        // balance tree after insertion
        root = balanceTree(root);
        return true;
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
    bool remove(T el){
        // search for element you want to remove
        auto res = search(el);
        AVLNode<T>* focus = res.second, *temp, *parent = res.first;
        // node not found
        if (parent == nullptr) return false;
        // element has no children
        if(focus->left == nullptr && focus->right == nullptr){
            temp = focus;
            // deleted node is left child
            if(parent->left == focus){
                parent->left = nullptr;

            }
            // deleted node is right child
            else{
                parent->right = nullptr;
            }
        }
            // element has only one child at the right
        else if(focus->left == nullptr){
            temp = focus;
            // deleted node  is left child
            if (parent->left == focus)
                parent->left = focus->right;
            // deleted node  is right child
            else{
                parent->right = focus->right;
            }
            
        }
            // element has only one child at the left
        else if(focus->right == nullptr){
            temp = focus;
            // deleted node  is left child
            if (parent->left == focus)
                parent->left = focus->left;
            // deleted node  is right child
            else{
                parent->right = focus->left;
            }
            
        }
        // element has two children
        else{
            // get predecessor
            AVLNode<T>* predecessor = getPredecessor(focus);
            // get parent of predecessor
            auto childAndParent = search(predecessor->value);
            // swap element with predecessor
            focus->value = predecessor->value;
            parent = childAndParent.first;
            focus = childAndParent.second;
            // element is right child
            if(parent->right == focus)
                parent->right = nullptr;
            // element is left child
            else
                parent->left = nullptr;
            temp = focus;
        }
        delete temp;
        // balance tree after removal
        root = balanceTree(root);
        return true;
    }

    // Function to print AVL tree ordered
    void print(AVLNode<T>* avlRoot){
        if(avlRoot == nullptr) return;
        print(avlRoot->left);
        cout << avlRoot->value;
        print(avlRoot->right);
    }

    // Function to print Student per Department
    void deptPrint(){
        cout << "Student per Departments:\n";
        for (auto pair: deptCount) {
            cout << pair.first << " " <<pair.second << " Students\n";
        }
    }

    // AVL Tree User Menu
    void menu(){
        short choice;
        while(true){
            cout << "\n\tAVL Tree Menu\n"
            << "1. Add new student\n"
            << "2. Remove student by ID\n"
            << "3. Search student by ID\n"
            << "4. Print All Students\n"
            << "5. Return to main menu\n"
            << "Choose one of the above options (1-5) >> ";
            choice = 0;
            cin >> choice;
            // Get student data from the user
            if(choice == 1){
                T stud;
                cin >> stud;
                if(insert(stud))
                    cout << "\n\tStudent Added Successfully!\n";
                else
                    cout << "\n\tThis ID is already used by ==> " << search(stud).second->value;
            }
            // Remove certain student using ID
            else if(choice == 2){
                string id;
                cout << "Enter ID to remove >> ";
                cin >> id;
                AVLNode<T>* res = search(T(id)).second;
                if(res != nullptr){
                    cout << "Removing Student...\n";
                    cout << res->value;
                    remove(res->value);
                    cout << "\n\tStudent Deleted Successfully!\n";
                }
                else
                    cerr << "\n\tStudent NOT Found!\n";
            }
            // Search for certain student using ID
            else if(choice == 3){
                string id;
                cout << "Enter ID to search for >> ";
                cin >> id;
                AVLNode<T>* res = search(T(id)).second;
                if(res != nullptr){
                    cout << "Student is found!\n";
                    cout << res->value;
                }
                else
                    cerr << "\n\tStudent NOT Found!\n";
            }
            // Output all current students sorted by ID
            else if(choice == 4) {
                this->print(this->root);
                this->deptPrint();
            }
            else if(choice == 5) break;
            else
                cerr << "\n\tINVALID INPUT!! Enter ONLY numbers from 1 to 5\n";
        }
    }

};

#endif