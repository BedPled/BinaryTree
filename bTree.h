//
// Created by pledushka on 14.04.2022.
//

#ifndef BINARYTREE_BTREE_H
#define BINARYTREE_BTREE_H
#include <iostream>

struct key {
    char s; // b/m/s
    int n; // 4 цифры

    key(char s, int n) : s(s), n(n) {}
    key() {
        this->s = 'b';
        this->n = 0000;
    }
};

bool operator < (key q, key w)
{
    if (q.s < w.s) {
        return true;
    } else if ((q.s == w.s) && (q.n < w.n)){
        return true;
    } else {
        return false;
    }
}

bool operator <= (key q, key w)
{
    if (q.s < w.s) {
        return true;
    } else if ((q.s == w.s) && (q.n < w.n)){
        return true;
    } else if ((q.s == w.s) && (q.n == w.n)) {
        return true;
    } else {
        return false;
    }
}

class bTree {

private:

    struct TreeNode{
        key key_;
        TreeNode *left_ = nullptr;
        TreeNode *right_ = nullptr;
        TreeNode *p_ = nullptr;
    };

    TreeNode *nil = new TreeNode;
    TreeNode *root;

    bool isNil(TreeNode *x) { // проверка на конец дерева
        if (x == nil) {
            return true;
        } else {
            return false;
        }
    }

    TreeNode *treeMinimum (TreeNode *y){ // указатель на минимальный элемент поддерева с корнем в y
        TreeNode *x = y; // МНЕ КАЖЕТСЯ ЧТО ДОЛЖНО БЫТЬ ТАК, ТК ИНАЧЕ МЕНЯЕТ ЗНАЧЕНИЕ УКАЗАТЕЛЯ
        while (!isNil(x->left_)) {
            x = x->left_;
        }
        return x;
    };

    TreeNode *treeMaximum (TreeNode *y){ // указатель на минимальный элемент поддерева с корнем в y
        TreeNode *x = y; // МНЕ КАЖЕТСЯ ЧТО ДОЛЖНО БЫТЬ ТАК, ТК ИНАЧЕ МЕНЯЕТ ЗНАЧЕНИЕ УКАЗАТЕЛЯ
        while (!isNil(x->right_)) {
            x = x->right_;
        }
        return x;
    };

    TreeNode *successor(TreeNode *z) {
        TreeNode *x = z; // МНЕ КАЖЕТСЯ ЧТО ДОЛЖНО БЫТЬ ТАК, ТК ИНАЧЕ МЕНЯЕТ ЗНАЧЕНИЕ УКАЗАТЕЛЯ
        if (!isNil(x->right_)) {
            return treeMinimum(x->right_);
        }
        TreeNode *y = x->p_;

        while (!isNil(y) && x == y->right_) {
            x = y;
            y = y->p_;
        }
        return y;
    }

    TreeNode *predecessor(TreeNode *z) {
        TreeNode *x = z; // МНЕ КАЖЕТСЯ ЧТО ДОЛЖНО БЫТЬ ТАК, ТК ИНАЧЕ МЕНЯЕТ ЗНАЧЕНИЕ УКАЗАТЕЛЯ
        if (!isNil(x->left_)) {
            return treeMaximum(x->left_);
        }
        TreeNode *y = x->p_;

        while (!isNil(y) && x == y->left_) {
            x = y;
            y = y->p_;
        }
        return y;
    }

    void insertTreeNode (TreeNode *z) { // вставка узла в дерево
        TreeNode *y = nil;
        TreeNode *x = root;

        while (!isNil(x)) {
            y = x;
            if (z->key_ <= x->key_) { // как сравнивать !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                x = x->left_;
            } else {
                x = x->right_;
            }
        }
        z->p_ = y;
        if (isNil(y)) {
            root = z;
        } else {
            if (z->key_ <= y->key_) {
                y->left_ = z;
            } else {
                y->right_ = z;
            }
        }

        z->left_ = nil; // nil
        z->right_ = nil; // nil

    }

    void deleteTreeNode (TreeNode *z) {
        TreeNode *y;
        TreeNode *x;
        if (isNil(z->left_) || isNil(z->right_)) {
            y = z;
        } else {
            y = predecessor(z);
        }

        if (!isNil(y->left_)) {
            x = y->left_;
        } else {
            x = y->right_;
        }

        x->p_ = y->p_;

        if (isNil(y->p_)) {
            root = x;
        } else if (y == y->p_->left_) {
            y->p_->left_ = x;
        } else {
            y->p_->right_ = x;
        }

        if (y != z) {
            z->key_ = y->key_;
            // копируем соответсвующие данные y в z
        }
    }


    void printTree(TreeNode *node, int level = 0) {
        if (isNil(node)) {
            if (level == 0) {
                std::cout << "Tree is empty";
            }
            return;
        }

        if (node) {
            printTree(node->right_, level + 1);

            for (int i = 0; i < level; i++) {
                std::cout << "       ";
            }

                std::cout << "\x1B[48;2;20;20;20m\x1B[1;38;2;255;255;255m " << node->key_.s << node->key_.n << ""
                          << " \033[0m" << std::endl;


            printTree(node->left_, level + 1);
        }
    }

    void inorderWalkL(TreeNode *node) {
        if (!isNil(node)) {
            inorderWalkL(node->left_);
            std::cout << "\x1B[48;2;20;20;20m\x1B[1;38;2;255;255;255m " << node->key_.s << node->key_.n << ""
                      << " \033[0m" << std::endl;
            inorderWalkL(node->right_);
        }
    }

    void inorderWalkR(TreeNode *node) {
        if (!isNil(node)) {
            inorderWalkR(node->right_);
            std::cout << "\x1B[48;2;20;20;20m\x1B[1;38;2;255;255;255m " << node->key_.s << node->key_.n << ""
                      << " \033[0m" << std::endl;
            inorderWalkR(node->left_);
        }
    }


    void preorderWalk(TreeNode *node)
    {
        if (!isNil(node)) {
            std::cout << "\x1B[48;2;20;20;20m\x1B[1;38;2;255;255;255m " << node->key_.s << node->key_.n << ""
                      << " \033[0m" << std::endl;
            preorderWalk(node->left_);
            preorderWalk(node->right_);
        }
    }

    void postorderWalk(TreeNode *node)
    {
        if (!isNil(node)) {
            postorderWalk(node->left_);
            postorderWalk(node->right_);
            std::cout << "\x1B[48;2;20;20;20m\x1B[1;38;2;255;255;255m " << node->key_.s << node->key_.n << ""
                      << " \033[0m" << std::endl;
        }
    }
public:

    bTree() { // Создать
        root = nil;
    }

    ~bTree() { // отчистить
        root = nil;
    }


    TreeNode *search (key k) {
        TreeNode *x = root;
        while (!isNil(x) && k.n != x->key_.n) {
            if (k < x->key_) {
                x = x->left_;
            } else {
                x = x->right_;
            }
        }
        return x;
    }

    void insert(key obj) {
        TreeNode *node = new TreeNode {
                obj,
                nullptr,
                nullptr,
                nullptr,
        };

        insertTreeNode(node);
    }

    void del(key obj) {
        TreeNode *x = search(obj);
        if (!isNil(x)) {
            deleteTreeNode(x);
        }
    }

    void print() {
        printTree(root, 0);
    }

    void inorderWalkL() {
        inorderWalkL(root);
    }

    void inorderWalkR() {
        inorderWalkR(root);
    }

    void preorderWalk() {
        preorderWalk(root);
    }

    void postorderWalk() {
        postorderWalk(root);
    }

};
#endif //BINARYTREE_BTREE_H