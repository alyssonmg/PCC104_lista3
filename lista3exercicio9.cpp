//Binary search tree
#pragma once

#include <iostream>
#include <concepts>
#include <memory>

enum class InsertionInfo { Inserted, AlreadyIn };
enum class SearchInfo { Found, NotFound };

int main()
{
    BinarySearchTree<int> bt;

    std::cout << (bt.insert(9)  == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
    std::cout << (bt.insert(10) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
    std::cout << (bt.insert(8)  == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
    std::cout << (bt.insert(3)  == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
    std::cout << (bt.insert(2)  == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
    std::cout << (bt.insert(4)  == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
    std::cout << (bt.insert(2)  == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
    std::cout << (bt.insert(11) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;

    bt.print();

    std::cout << << std::endl;

    std::cout << (bt.search(7) == SearchInfo::Found ? "Found" : "Not found") << std::endl;
    std::cout << (bt.search(8) == SearchInfo::Found ? "Found" : "Not found") << std::endl;

}

template <std::totally_ordered T>
class BinarySearchTree {
    class BSTNode{
        public:
        T value;
        std::unique_ptr<BSTNode> left;
        std::unique_ptr<BSTNode> right;

        BSTNode(T v) { value = v; }
    };

public:

    BinarySearchTree() {}

    InsertInfo insert(T v){
        return insert(v, root);
    }

    SearchInfo search (t v){
        return search(v, root);
    }

    void print(){
            print(root);
    }

private:
    std::unique_ptr<BSTNode> root;
    InsertInfo insert(T v, std::unique_ptr<BSTNode>& node){
        if (!node){
            node = std::unique_ptr<BTSNode>(new BSTNode(v));
            return InsertionInfo::Inserted;
        }
        if (v == node->value){
            return InsertionInfo::AlreadyIn;
        }
        return (v < node->value) ? insert(v, node->left) : insert(v, node->right);
    }
    SearchInfo search(T v, std::unique_ptr<BSTNode>& node){
        if (!node){
            return SearchInfo::NotFound;
        }
        if (v == node->value){
            return SearchInfo::Found;
        }
        return (v < node->value) ? search(v, node->left) : search(v, node->right);
    }

    void print(std::unique_ptr<BTSNode>& node)  {
        if (!node){
            return;
        }
        else{
            print(note->left);
            std::cout << node->value << "\t";
            print(node->right);
        }
    }  
};
