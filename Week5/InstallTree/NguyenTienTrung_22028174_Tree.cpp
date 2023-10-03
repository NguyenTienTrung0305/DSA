#include <iostream>
using namespace std;

// Một Node trong cây
class Node {
public:
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;

    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    Node* firstChild;
    // firstChild trỏ đến sibling child
    Node* nextSibling;
    Node(int value) {
        data = value;
        fatherNode = nullptr;
        firstChild = nullptr;
        nextSibling = nullptr;
    }
    friend class Tree;
};

// Lớp Cây
class Tree {
private:
    bool wasCheckBinaryTree;
public:
    // Chứa một Node gốc
    Node* root;
    Tree() {
        root = nullptr;
    }

    Node* findNode(Node* node , int data){
        if (node == nullptr){
            return nullptr;
        }
        if (node->data == data){
            return node;
        }
        Node* result = nullptr;
        Node* sibling = node;
        while(sibling != nullptr){
            result = findNode(sibling->firstChild , data);
            if (result != nullptr){
                return result;
            }
            result = findNode(sibling->nextSibling , data);
            if (result != nullptr){
                return result;
            }
        }
        return result;
    };

    // Các hàm khởi tạo khác nếu cần thiết

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insert(int father, int data){
        if(root == nullptr){
            return false;
        }
        Node* fatherNode = findNode(root , father);
        // kiem tra neu node tra khong ton tai
        if (fatherNode == nullptr){
            return false;
        }
        Node* tmp = fatherNode->firstChild;
        while(tmp->nextSibling != nullptr){
            if (tmp->data == data){
                return false;
            }
            tmp = tmp->nextSibling;
        }
        Node* newNode = new Node(data);
        newNode->fatherNode = fatherNode;
        if (tmp == nullptr){
            fatherNode->firstChild = newNode;
        }else{
            tmp->nextSibling = newNode;
        }
        return true;
    }

    // number child of paren , end delete node
    int totalNodeWasDelete(Node* parent){
        if (parent == nullptr){
            return 0;
        }
        int result;
        result = 1 + totalNodeWasDelete(parent->firstChild);
        result = result + totalNodeWasDelete(parent->nextSibling);
        delete parent;
        return result;
    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    int remove(int data){
        Node* node = findNode(root , data);
        int result = totalNodeWasDelete(node->firstChild);
        node->fatherNode->firstChild = node->nextSibling;
        delete node;
        return result;
    };

    // Hàm in ra các Node theo thứ tự preorder
    // gốc sau đến con
    void preorder(Node* root){
        if (root == nullptr){
            return;
        }
        cout << root->data <<" ";
        Node* childNode = root->firstChild;
        while(childNode != nullptr){
            preorder(childNode);
            childNode = childNode->nextSibling;
        }
    };

    // Hàm in ra các Node theo thứ tự postorder
    // hết con mới đến gốc
    void postorder(Node* root){
        if (root == nullptr){
            return;
        }
        
        // duyet node theo thu tu tu trai sang phai
        Node* childNode = root->firstChild;
        while(childNode != nullptr){
            postorder(childNode);
            childNode = childNode->nextSibling;
        }
        cout << root->data << " ";
    };

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree(Node* root){
        if (root == nullptr){
            return true;
        }
        Node* child = root->firstChild;
        int totalSibling;
        while(child != nullptr){
            if(isBinaryTree(child)){
                ++totalSibling;
                if (totalSibling > 2){
                    return false;
                }
            }
            child = child->nextSibling;
        }
        return true;
    };

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree(Node* root){
        if (wasCheckBinaryTree == false){
            if(!isBinaryTree(root)){
                return false;
            }
            wasCheckBinaryTree = true;
        }
        bool result;
        // neu parent khong con con nua => luon dung
        if (root->firstChild == nullptr){
            return true;
        }
        // neu parent van con con
        while (root->firstChild != nullptr){
            // neu parent chi co 1 con => luon dung
            if (root->firstChild->nextSibling == nullptr){
                return true;
            // truong hop parent co 2 con , thi phai thoa man dong thoi 2 dieu kien
            }else{
                if (root->data > root->firstChild->data && root->data < root->firstChild->nextSibling->data){
                    result = isBinarySearchTree(root->firstChild);
                    if (result == false){
                        return false;
                    }
                    result = isBinarySearchTree(root->nextSibling);
                }else{
                    return false;
                }
            }
        }
        
        return result;
    }

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree(Node* root){
        if (wasCheckBinaryTree == false){
            if(!isBinaryTree(root)){
                return false;
            }
            wasCheckBinaryTree = true;
        }
        bool result;
        // if parent don't have any child
        if (root->firstChild == nullptr){
            return true;
        }
        // if parent still have child
        while(root->firstChild != nullptr){
            if (root->firstChild->nextSibling == nullptr){
                if (root->data > root->firstChild->data){
                    return true;
                }else{
                    return false;
                }
            }else{
                if (root->data > root->firstChild->data && root->data > root->firstChild->nextSibling->data){
                    result = isMaxHeapTree(root->firstChild);
                    if (result == false){
                        return false;
                    }
                    result = isMaxHeapTree(root->firstChild->nextSibling);
                }else{
                    return false;
                }
            }
        }
        return result;
    };

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    // trái - gốc - phải 
    void inorder(Node* root){
         if (wasCheckBinaryTree == false){
            if(!isBinaryTree(root)){
                return;
            }
            wasCheckBinaryTree = true;
        }
        if (root == nullptr){
            return;
        }
        inorder(root->firstChild);
        cout << root->data <<" ";
        inorder(root->nextSibling);
    };

    // Hàm trả về độ cao của cây
    int height(Node* root){
        if (root == nullptr){
            return 0;
        }
        // neu no khong co con va sibing tra ve 0
        if (root->firstChild == nullptr && root->nextSibling == nullptr){
            return 0;
        }
        int he;
        // neu no co con thi tang chieu cao len 1
        he = 1 + height(root->firstChild);
        // neu no co sibling thi height_current_node = max(height_current_node , height_current_sibling_node )
        he = max(he , height(root->nextSibling));
        return he;
    };

    // Hàm trả về độ sâu của một Node
    int depth(int data){
        Node* node = findNode(root , data);
        return height(node);
    };

    // Hàm đếm số lượng lá
    int numOfLeaves(Node* root){
        int leaf;
        if(root == nullptr){
            return 1;
        }
        leaf = leaf + numOfLeaves(root->firstChild);
        if (root->firstChild == nullptr){
            leaf = leaf + numOfLeaves(root->nextSibling);
        }
        return leaf;
    };

    // Hàm trả về Node có giá trị lớn nhất
    int findMax(Node* root , int maxEle){
        if (root == nullptr){
            return maxEle;
        }
        maxEle = max(maxEle ,root->data);
        maxEle = findMax(root->firstChild , maxEle);
        maxEle = findMax(root->nextSibling , maxEle);
        return maxEle;
    };

    // totalchild
    int totalChild(Node* currentNode){
        if (currentNode == nullptr){
            return 0;
        }
        return 1 + totalChild(currentNode->firstChild) + totalChild(currentNode->nextSibling);
    }

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild(){
        return totalChild(root->firstChild);
    };
};

int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    // Test thử các hàm của lớp cây

    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại
    
    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    Tree tree;
    Node* node1 = new Node(3);
    Node* node2 = new Node(6);
    Node* node3 = new Node(7);
    Node* node4 = new Node(5);
    Node* node5 = new Node(2);
    Node* node6 = new Node(10);
    Node* node7 = new Node(9);
    Node* node8 = new Node(1);

    node1->firstChild = node2;
    node2->fatherNode = node1;
    node2->nextSibling = node3;
    node3->nextSibling = node4;
    node3->fatherNode = node1;
    node4->fatherNode = node1;

    node2->firstChild = node5;
    node5->fatherNode = node2;
    node5->nextSibling = node6;
    node6->fatherNode = node2;

    node3->firstChild = node7;
    node7->fatherNode = node3;
    node7->nextSibling = node8;
    node8->fatherNode = node3;

    tree.root = node1;
    cout << tree.findMax(tree.root , 0);
    cout << endl;

    // tree.remove(10);
    tree.preorder(tree.root);
    cout << endl;
    cout << tree.findNode(tree.root , 6)->data;
    cout << endl;
    cout << tree.remove(6);
    cout << endl;
    tree.preorder(tree.root);
    cout << endl;

    cout << tree.findMaxChild();

    return 0;
}