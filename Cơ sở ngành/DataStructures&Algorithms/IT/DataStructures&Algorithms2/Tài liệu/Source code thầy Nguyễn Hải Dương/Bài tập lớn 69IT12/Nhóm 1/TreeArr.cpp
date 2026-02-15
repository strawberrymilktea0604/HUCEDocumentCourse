#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template<typename T>
class BinaryTree {
	T* tree;
    unsigned int size;
    
public:
    BinaryTree() {
	this->tree = new T[100]();
	this->size = 100;
    }
	
    BinaryTree(T value) {
    	this->tree = new T[100]();
        this->tree[0] = value;
        this->size = 100;
    }
    
    ~BinaryTree() {
    		delete[] tree;
    }
    
    void insert(T value) {
        /**
        * Nếu cây rỗng (nghĩa là tree[0] chưa có gì), thì gán luôn value vào gốc rồi thoát.
        * Như vậy node đầu tiên chèn vào luôn là root.
         */
    	if(!tree[0]) {
		    tree[0] = value;
		    return;
		}
        
        int index = 0;
        while(true) {
            /**
            * Nếu tree[index] trống → dừng vòng lặp → chèn value vào chỗ đó.
            * Ngược lại, nếu có giá trị rồi thì phải tìm nút con phù hợp để đi tiếp.
             */
        	if(!tree[index]) break;
          
            /**
            * xác định sang nhánh trái hay nhánh phải
            * trái: 2*i + 1
            * phải : 2*i + 2
            */
        	index = (value < tree[index] ? 1 : 2) + 2*index;
            
            //điểu kiện mở rộng mảng
            if(index > size) {
          	    unsigned int oldSize = size;    //lưu lại kích thước cũ
          	    size = size + size >> 1;    //nếu index cần có vượt quá mảng thì tăng lên 1.5 lần
                T* newTree = new T[size](); //cấp phát mảng mới với kích thước lớn hơn, 
                                            //sao chép dữ liệu mảng cũ sang mảng mới
                for(int i = 0; i < oldSize; i++) {
            		newTree[i] = tree[i];
                }
                tree = newTree;
          }
        }
        //Sau khi tìm được một chỗ trống (tree[index] rỗng), gán giá trị mới vào.
        tree[index] = value;
    }
    
    bool contains(T value) {
    	auto index = 0;
        
        while(true) {
            //kiểm tra node có rỗng không
        	if(!tree[index]) break;

            //kiểm tra node có giá trị và = value
            if(tree[index] == value) return true;
            
            /**
            * xác định sang nhánh trái hay nhánh phải
            * trái: 2*i + 1
            * phải : 2*i + 2
            */
            index = (value < tree[index] ? 1 : 2) + 2*index;
            
            //dừng khi vượt ngoài mảng
            if(index >= size) break;
        }
        
        return false;
    }
    
    bool remove(T value) {
    	int current = 0;
    	int parent = -1;
    	bool isLeftChild = false;

    	while (current < size && tree[current] && tree[current] != value) {
        	parent = current;
        	if (value < tree[current]) {
            		current = 2 * current + 1;
            		isLeftChild = true;
        	} else {
     			current = 2 * current + 2;
            		isLeftChild = false;
        	}
    	}

    	if (current >= size || !tree[current]) return false;

    	int leftChild = 2 * current + 1;
    	int rightChild = 2 * current + 2;

    	if ((leftChild >= size || !tree[leftChild]) && 
        	(rightChild >= size || !tree[rightChild])) {
        	tree[current] = T();
        
        	if (parent != -1) {
            		if (isLeftChild) {
                		tree[2 * parent + 1] = T();
            		} else {
                		tree[2 * parent + 2] = T();
            		}
        	}
    	}
    	else if (leftChild >= size || !tree[leftChild]) {
        	tree[current] = tree[rightChild];
        	tree[rightChild] = T();
    	}
    	else if (rightChild >= size || !tree[rightChild]) {
        	tree[current] = tree[leftChild];
        	tree[leftChild] = T();
    	}
    	else {
        	int successor = rightChild;
        	int successorParent = current;
        
        	while ((2 * successor + 1) < size && tree[2 * successor + 1]) {
            	successorParent = successor;
            	successor = 2 * successor + 1;
        	}

        	tree[current] = tree[successor];
        
        	int successorRightChild = 2 * successor + 2;
        	if (successorRightChild < size && tree[successorRightChild]) {
            		tree[successor] = tree[successorRightChild];
            		tree[successorRightChild] = T();
        	} else {
            		tree[successor] = T();
            
            		if (successorParent != current) {
                		tree[2 * successorParent + 1] = T();
            		} else {
                		tree[2 * successorParent + 2] = T();
            		}
        	}
    	}
    
    	return true;
	}
    
	vector<T> preOrderTraversal() {
    		vector<T> result;
    		stack<int> indices;
    		if (size > 0 && tree[0]) indices.push(0);// Nếu có phần tử gốc thì push vào stack
    
    		while (!indices.empty()) {
        		int current = indices.top();
        		indices.pop();
        		result.push_back(tree[current]);// xử lý node hiện tại 

                // Push con phải trước để con trái được xử lý trước (do stack LIFO)
        		int right = 2 * current + 2;
        		if (right < size && tree[right]) indices.push(right);
        
        		int left = 2 * current + 1;
        		if (left < size && tree[left]) indices.push(left);
    		}
    	return result;
	}
    
    vector<T> inOrderTraversal() {
        vector<T> result;
        stack<int> indices;
        int current = 0;
    
        while (current < size && tree[current] || !indices.empty()) {
            //Đi hết nhánh trái, đẩy các node vào stack.
            while (current < size && tree[current]) {
                indices.push(current);
                current = 2 * current + 1;
            }
            //Lấy node trên đỉnh stack ra → duyệt node hiện tại.
            if (!indices.empty()) {
                current = indices.top();
                indices.pop();
                result.push_back(tree[current]);
            
                current = 2 * current + 2;
            }
        }
        return result;
    }
    
    vector<T> postOrderTraversal() {
        vector<T> result;
        stack<int> indices;
        int current = 0;
        int lastVisited = -1;
    
        while (current < size && tree[current] || !indices.empty()) {
            //Đi hết nhánh trái, đẩy các node vào stack
            while (current < size && tree[current]) {
                indices.push(current);
                current = 2 * current + 1;
            }
            //kiểm tra stack rỗng không
            int peek = indices.empty() ? -1 : indices.top();
            
            //Nếu node có con phải và con phải chưa được duyệt (lastVisited chưa trùng) → chuyển sang duyệt nhánh phải
            if (peek != -1 && 2 * peek + 2 < size && tree[2 * peek + 2] && 
                (2 * peek + 2 != lastVisited)) {
                current = 2 * peek + 2;
            } else {
                //Chỉ khi cả trái và phải đã xử lý xong, ta mới thăm node.
                if (peek != -1) {
                    result.push_back(tree[peek]);
                    lastVisited = peek;
                    indices.pop();
            }
        }
    }
    return result;
    }
    
    vector<T> breadthTraversal() {
        vector<T> result;
        for(int i = 0; i < size; i++) {
            if(tree[i]) result.push_back(tree[i]);
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
