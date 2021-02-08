#ifndef BST_H
#define BST_H

#include <iostream>

template <typename keyT, typename valT>
struct TreeNode {
    keyT key;
    valT val;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;

    TreeNode(keyT _key = keyT(), valT _val = valT(), TreeNode* _parent = nullptr) {
        key = _key;
        val = _val;
        parent = _parent;
        left = nullptr;
        right = nullptr;
    }
};

template <typename keyT, typename valT>
class BinarySearchTree {
    TreeNode<keyT, valT>* root;

    // You may add private helper functions if you need them

public:
    BinarySearchTree() {
        root = nullptr;

    }

    ~BinarySearchTree() {
        clear();
        // Destructor
    }

    TreeNode<keyT, valT>* insert(keyT key, valT val) {
        // Insert a new node to tree and return its pointer
        TreeNode<keyT, valT>* Node = new TreeNode<keyT, valT>(key, val);

        if(this->root == nullptr){
            //todo std::cout<<"root ";
            root = Node;
            return Node;
            //cur Node 대입과 차이점
        }
        else{
            TreeNode<keyT, valT>* Temp = root;
            while(Temp != nullptr){
                if(Node->key < Temp->key){
                    if(Temp->left == nullptr){
                        Temp->left = Node;
                        Node->parent = Temp;
                        return Node;
                    }
                    else{
                        Temp = Temp->left;
                    }
                }
                else if(Node->key > Temp->key){
                    if(Temp->right == nullptr){
                        Temp->right = Node;
                        Node->parent = Temp;
                        return Node;
                    }
                    else{
                        Temp = Temp->right;
                    }
                }
                else{// Node->key == Temp->key
                    //todo std::cout<<"same key ";
                    return nullptr;
                }
            }

        }
    }

    bool remove(TreeNode<keyT, valT>* node) {
        if(node == nullptr){
            return false;
        }

        TreeNode<keyT, valT>* Temp = this->root;
        TreeNode<keyT, valT>* Par = Temp->parent;

        while(Temp != nullptr){
            if(Temp == node){ // found
                if(Temp->left == nullptr && Temp->right == nullptr){ //external node
                    if(Par == nullptr){
                        this->root = nullptr; 
                        delete Temp;
                        return true;
                    }
                    else if(Par->left == node){ //left external node
                        Par->left = nullptr;
                        delete Temp;
                        return true;
                    }
                    else{ //right external node
                        Par->right = nullptr;
                        delete Temp;
                        return true;
                    }
                }
                else if (Temp->left != nullptr && Temp->right == nullptr){ //left one child
                    if(Par == nullptr){
                        this->root = Temp->left;
                        this->root->parent = nullptr;
                        delete Temp;
                        return true;
                    }
                    else if (Par->left == Temp){
                        Par->left = Temp->left;
                        Par->left->parent = Par;
                        delete Temp;
                        return true;
                    }
                    else{
                        Par->right = Temp->left;
                        Par->right->parent = Par;
                        delete Temp;
                        return true;
                    }
                }
                else if (Temp->left == nullptr && Temp->right != nullptr){ //right one child
                    if(Par == nullptr){
                        this->root = Temp ->right;
                        this->root->parent = nullptr;
                        delete Temp;
                        return true;
                    }
                    else if (Par->left == Temp){
                        Par->left = Temp->right;
                        Par->left->parent = Par;
                        delete Temp;
                        return true;
                    }
                    else{
                        Par->right = Temp->right;
                        Par->right->parent = Par;
                        delete Temp;
                        return true;
                    }
                }
                else{ // two child
                    TreeNode<keyT, valT>* Suc = Temp->right;

                    while(Suc->left != nullptr){
                        Suc = Suc->left;
                    }
                    keyT Suc_k = Suc->key;
                    remove(Suc);
                    Temp->key = Suc_k; //todo 이부분 개념도 그렇고 코드도 그렇고 애매하다. val은 어찌되는건지, 포인터는 그대로 값만 바꾸면 되는건지

                    return true;
                }

            }
            else if(node->key < Temp->key){
                Par = Temp;
                Temp = Temp->left;
            }
            else{
                Par = Temp;
                Temp = Temp->right;
            }
        }

        // Remove 'node' and return true on success, false on fail
        // For example, if node is nullptr, do nothing and return false
    }

    TreeNode<keyT, valT>* search(keyT key) const {
        TreeNode<keyT, valT>* Temp = this->root;

        while(Temp != nullptr){
            if(Temp->key == key){
                return Temp;
            }
            else if(Temp->key > key){
                Temp = Temp->left;
            }
            else{
                Temp = Temp->right;
            }
        }

        return nullptr;

        // Find the node that has key 'key'
        // If not found, return nullptr
    }

    void clear() {
        deleteallnode(this->root);
        // Remove all nodes in the tree
    }

    void deleteallnode(TreeNode<keyT, valT>* node){
        if(node == nullptr){
            return;
        }
        deleteallnode(node->left);
        deleteallnode(node->right);

        remove(node);
    }

    void print_in(TreeNode<keyT, valT>* current) const {
        if (current != nullptr) {
            print_in(current->left);
            std::cout << current->key << ' ' << std::flush;
            print_in(current->right);
        }
    }

    void print_pre(TreeNode<keyT, valT>* current) const {
        if (current != nullptr) {
            std::cout << current->key << ' ';
            print_pre(current->left);
            print_pre(current->right);
        }
    }

    void print_post(TreeNode<keyT, valT>* current) const {
        if (current != nullptr) {
            print_post(current->left);
            print_post(current->right);
            std::cout << current->key << ' ';
        }
    }

    void print() const {
        // It prints all node info in two ways
        // to make sure all nodes are in the right place
        print_in(this->root);
        std::cout << std::endl;

        print_pre(this->root);
        std::cout << std::endl;

        print_post(this->root);
        std::cout << std::endl;
    }

    void printroot() {
        std::cout<< this->root <<std::endl;
    }
};

#endif
