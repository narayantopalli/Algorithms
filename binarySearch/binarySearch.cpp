#include "binarySearch.hpp"

int main() {
    auto bst = BinarySearchTree();
    bst.addNode(20);
    bst.addNode(30);
    bst.addNode(10);
    bst.addNode(40);
    bst.addNode(35);
    bst.addNode(45);
    bst.printTree();
    std::cout << bst.find(40) << '\n';
    std::cout << bst.getSize() << '\n';
    std::cout << '\n';
    bst.removeNode(40);
    bst.printTree();
    std:: cout << bst.find(40) << '\n';
    std::cout << bst.getSize() << '\n';
    return 0;
}
