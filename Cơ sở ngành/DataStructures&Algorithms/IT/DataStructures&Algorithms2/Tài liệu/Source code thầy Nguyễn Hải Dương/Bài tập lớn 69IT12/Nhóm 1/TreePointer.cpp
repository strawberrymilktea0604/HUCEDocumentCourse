#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

template<typename T>
struct Node {
    T value;
    Node<T>* leftBranch;
    Node<T>* rightBranch;
    Node(T val) : value(val), leftBranch(nullptr), rightBranch(nullptr) {}
};

template<typename T>
class BinaryTree {
    Node<T>* root;
public:
    BinaryTree() {
	    root = nullptr;
    }
    BinaryTree(T value) {
        root = new Node(value);
    }
    void insert(T value) {
        if(!root) {
            root = new Node(value);

	    return;
        }

        Node<T>* cur = root;
        while(cur) {
            if(value < cur->value) {
                if(!cur->leftBranch) {
                    cur->leftBranch = new Node<T>(value);
                    return;
                }

                cur = cur->leftBranch;
            } else {
               if(!cur->rightBranch) {
                    cur->rightBranch = new Node<T>(value);
                    return;
                }

                cur = cur->rightBranch; 
            }
        }
    }

    bool contains(T value) {
        Node<T>* cur = root;
        while(cur) {
            if(value == cur->value) return true;
            
            cur = value < cur -> value ? cur->leftBranch : cur->rightBranch;
        }

        return false;
    }
    
	bool remove(T value) {
    	if (!root) return false;
        Node<T>* current = root;
        Node<T>* parent = nullptr;
        while (current && current->value != value) {
            parent = current;
            current = (value < current->value) ? current->leftBranch : current->rightBranch;
        }
        if (!current) return false;

        if (!current->leftBranch && !current->rightBranch) {
            if (current == root) {
                root = nullptr;
            } else if (parent->leftBranch == current) {
                parent->leftBranch = nullptr;
            } else {
                parent->rightBranch = nullptr;
            }
            delete current;
        }
        else if (!current->leftBranch || !current->rightBranch) {
            Node<T>* child = current->leftBranch ? current->leftBranch : current->rightBranch;
            
            if (current == root) {
                root = child;
            } else if (parent->leftBranch == current) {
                parent->leftBranch = child;
            } else {
                parent->rightBranch = child;
            }
            delete current;
        }
        else {
            Node<T>* successor = current->rightBranch;
            Node<T>* successorParent = current;
            
            while (successor->leftBranch) {
                successorParent = successor;
                successor = successor->leftBranch;
            }
            current->value = successor->value;
            if (successorParent->leftBranch == successor) successorParent->leftBranch = successor->rightBranch;
            else successorParent->rightBranch = successor->rightBranch;
            delete successor;
        }
        return true;
    }
    
    vector<T> preOrderTraversal() {
    		vector<T> result;
        if(!root) return result;
        
        stack<Node<T>*> s;
        s.push(root);
        
        while(!s.empty()) {
            Node<T>* current = s.top();
            s.pop();
            result.push_back(current->value);
            
            if(current->rightBranch) s.push(current->rightBranch);
            if(current->leftBranch) s.push(current->leftBranch);
        }
        return result;
    }
    
    vector<T> inOrderTraversal() {
    		vector<T> result;
        stack<Node<T>*> s;
        Node<T>* current = root;
        
        while(current || !s.empty()) {
            while(current) {
                s.push(current);
                current = current->leftBranch;
            }
            
            current = s.top();
            s.pop();
            result.push_back(current->value);
            
            current = current->rightBranch;
        }
        return result;
    }
    
    vector<T> postOrderTraversal() {
    	vector<T> result;
        if(!root) return result;
        
        stack<Node<T>*> s1, s2;
        s1.push(root);
        
        while(!s1.empty()) {
            Node<T>* current = s1.top();
            s1.pop();
            s2.push(current);
            
            if(current->leftBranch) s1.push(current->leftBranch);
            if(current->rightBranch) s1.push(current->rightBranch);
        }
        
        while(!s2.empty()) {
            result.push_back(s2.top()->value);
            s2.pop();
        }
        return result;
    }
    
    vector<T> breadthTraversal() {
    		vector<T> result;
        if(!root) return result;
        
        queue<Node<T>*> q;
        q.push(root);
        
        while(!q.empty()) {
            Node<T>* current = q.front();
            q.pop();
            result.push_back(current->value);
            
            if(current->leftBranch) q.push(current->leftBranch);
            if(current->rightBranch) q.push(current->rightBranch);
        }
        return result;
    }
    
};

template<typename T>
void printVector(const vector<T>& v) {
    for(auto x : v) cout << x << " ";
}
int main() {
    BinaryTree<int> tree;
    string mn = "====================\n0. Exit\n1. insert\n2. contains\n3. delete\n4. preOrderTraversal\n5. inOrderTraversal\n6. postOrderTraversal\n7. breadthTraversal\n";
    int choice = -1;
    int val;
    while(choice != 0) {
        cout << mn << "nhap lua chon: ";
        cin >> choice;
        switch(choice) {
      	    case 1:
        	    cout << "nhap gia tri cho node: ";
                cin >> val;
                tree.insert(val);
        	    break;
            case 2:
        	    cout << "nhap gia tri can kiem tra: ";
                cin >> val;
        	    cout << (tree.contains(val) ? " True\n" : " False\n");
        	    break;
            case 3:
                cout << "nhap  gia tri can xoa: ";
                cin >> val;
        	    if(!tree.contains(val)) {
          	        cout << "   gia tri can xoa khong co\n";
                }
                else {
          	        tree.remove(val);
                    cout << "   da xoa " << val;
                    cout << endl;
                }          	
        	    break;
            case 4:
                cout << "Pre-order Traversal: ";
                printVector(tree.preOrderTraversal());
                cout << endl;
                break;
            case 5:
                cout << "in-order Traversal: ";
                printVector(tree.inOrderTraversal());
                cout << endl;
                break;
            case 6:
                cout << "Post-order Traversal: ";
                printVector(tree.postOrderTraversal());
                cout << endl;
                break;
            case 7:
                cout << "Breadth Traversal: ";
                printVector(tree.breadthTraversal());
                cout << endl;
                break;
            default:break;
      }
    }
}
