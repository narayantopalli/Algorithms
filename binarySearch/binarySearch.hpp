#include <iostream>
#include <string>

struct BinaryNode
{
    public:
    BinaryNode() : value(0), left(nullptr), right(nullptr) {}
    BinaryNode(int value) : value(value), left(nullptr), right(nullptr) {}

    void setValue(int value) {this->value = value;}
    int getValue() {return this->value;}

    void setRight(BinaryNode* right) {this->right = right;}
    BinaryNode* getRight() {return this->right;}

    void setLeft(BinaryNode* left) {this->left = left;}
    BinaryNode* getLeft() {return this->left;}

    private:
    int value;
    BinaryNode* left;
    BinaryNode* right;
};

struct BinarySearchTree
{
    public:
    BinarySearchTree() : root(nullptr), size(0) {}
    ~BinarySearchTree() {
        if (this->root != nullptr) _freeTree(this->root);
    }

    // add node call function
    void addNode(int value) {
        if (this->root == nullptr) {
            this->root = new BinaryNode(value);
            ++this->size;
        }
        else {
            _addNode(value, this->root);
        }
    }

    // search tree call function
    bool find(int value) const {
        if (this->root == nullptr) {
            return false;
        }
        return _find(value, this->root);
    }

    // print tree call function
    void printTree() const {
        if (this->root == nullptr) {
            std::cout << "Tree is Empty\n";
        }
        else {
            _printTree(this->root);
        }
    }

    // remove node call function
    void removeNode(int value) {
        this->root = _removeNode(value, this->root);
    }

    // get size of tree
    size_t getSize() const {return this->size;}

    private:
    // recursive add node function
    void _addNode(int value, BinaryNode* node) {
        if (value == node->getValue()) return;
        else if (value > node->getValue()) {
            if (node->getRight() == nullptr) {
                node->setRight(new BinaryNode(value));
                ++this->size;
            }
            else _addNode(value, node->getRight());
        }
        else {
            if (node->getLeft() == nullptr) {
                node->setLeft(new BinaryNode(value));
                ++this->size;
            }
            else _addNode(value, node->getLeft());
        }
    }

    // recursive print tree function
    void _printTree(BinaryNode* node) const {
        std::string rightval = (node->getRight() != nullptr) ? std::to_string(node->getRight()->getValue()) : "null";
        std::string leftval = (node->getLeft() != nullptr) ? std::to_string(node->getLeft()->getValue()) : "null";
        std::cout << "Node: " << node->getValue() << ", left: " << leftval << ", right: " << rightval << '\n';
        if (node->getRight() != nullptr) _printTree(node->getRight());
        if (node->getLeft() != nullptr) _printTree(node->getLeft());
    }

    // recursive search tree function
    bool _find(int value, BinaryNode* node) const {
        if (value > node->getValue()) {
            return (node->getRight() != nullptr) ? _find(value, node->getRight()): false;
        }
        else if (value < node->getValue()) {
            return (node->getLeft() != nullptr) ? _find(value, node->getLeft()): false;
        }
        else return true;
    }

    // finds successor in right sub-branch
    BinaryNode* _findLeftmost(BinaryNode* node) const {
        if (node->getLeft() != nullptr) return _findLeftmost(node->getLeft());
        return node;
    }

    // recursive remove node function
    BinaryNode* _removeNode(int value, BinaryNode* node) {
        if (node == nullptr) {
            return nullptr;
        }
        else if (value < node->getValue()) {
            node->setLeft(_removeNode(value, node->getLeft()));
            return node;
        }
        else if (value > node->getValue()) {
            node->setRight(_removeNode(value, node->getRight()));
            return node;
        }
        else {
            if (node->getLeft() == nullptr && node->getRight() == nullptr) {
                delete node;
                --this->size;
                return nullptr;
            }
            else if (node->getLeft() == nullptr) {
                auto new_node = node->getRight();
                delete node;
                --this->size;
                return new_node;
            }
            else if (node->getRight() == nullptr) {
                auto new_node = node->getLeft();
                delete node;
                --this->size;
                return new_node;
            }
            else {
                // swapping node with leftmost in right subtree keeps all other node positions not needing to be changed
                auto leftmost = _findLeftmost(node->getRight());
                int new_val = leftmost->getValue();
                leftmost->setValue(value);
                node->setValue(new_val);
                node->setRight(_removeNode(value, node->getRight()));
                return node;
            }
        }
    }

    // free heap allocated nodes
    void _freeTree(BinaryNode* node) {
        if (node->getRight() != nullptr) _freeTree(node->getRight());
        if (node->getLeft() != nullptr) _freeTree(node->getLeft());
        delete node;
    }

    BinaryNode* root;
    size_t size;
};
