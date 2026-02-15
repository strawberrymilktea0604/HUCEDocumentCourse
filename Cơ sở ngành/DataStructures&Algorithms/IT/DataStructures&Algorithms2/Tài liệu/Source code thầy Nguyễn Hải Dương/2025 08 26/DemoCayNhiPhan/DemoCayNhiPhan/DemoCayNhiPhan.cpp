// DemoCayNhiPhan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <queue>

using namespace std;


//định nghĩa node
struct Node
{
	int Val;
	Node* ChildLeft;
	Node* ChildRight;
};

//định nghĩa cây tìm kiếm nhị phân - Binary Search Tree (BST)
struct BST
{
	Node* root;
};



//Hàm để khởi tạo 1 Node
Node* CreateNode(int val)
{
	Node* newNode = (Node*)calloc(1, sizeof(Node));
	newNode->Val = val;
	newNode->ChildLeft = NULL;
	newNode->ChildRight = NULL;
	return newNode;
}

BST CreateBST()
{
	BST t;
	t.root = NULL;
	return t;
}


Node* insert_Node(int val, Node* root)
{
	Node* newNode = CreateNode(val);
	if (root == NULL)
	{
		//Chưa có Node nào trên cây
		//=> Node mới sẽ chính là gốc của cây T
		root = newNode;
	}
	else
	{
		//đã có Node trên cây
		if (root->Val == val)
		{
			cout << "Da ton tai node co gia tri la " << val << " tren cay nhi phan tim kiem";
		}
		else
		{
			if (val < root->Val)
			{
				root->ChildLeft = insert_Node(val, root->ChildLeft);
			}
			else
			{
				root->ChildRight = insert_Node(val, root->ChildRight);
			}
		}
	}
	return root;
}


//hàm tính chiều cao của cây
int countHeight(Node* root)
{
	//trường hợp root bằng NULL thì return 0
	if (root == NULL)
	{
		return 0;
	}
	//Nếu root khác NULL thì tính chiều cao của cây con trái và cây con phải sau đó lấy max.
	//Hàm sẽ đệ quy đến từng node lá và trả ra độ sâu của Node lá sâu nhất. -> Chính là chiều cao của cây
	int left = countHeight(root->ChildLeft);
	int right = countHeight(root->ChildRight);
	return 1 + max(left, right);
}

queue<string> q; //Tạo 1 hàng đợi để lưu các Node của cây.

//Hàm để lấy ra các Node tại từng tầng của Cây, node nào Null thì sẽ trả về ký tự "#"
void getNode_1Level(Node* root, int level)
{
	if (root == NULL)
	{
		q.push("#");
		return;
	}
	//Nếu level ==1 thì tức là đúng node của tầng cần lấy giá trị rồi => lấy giá trị của Node đẩy và q
	if (level == 1)
	{
		q.push(to_string(root->Val));
		//cout << root->Val << "  ";
	}
	else
	{
		//Nếu level khác 1 thì đệ quy giảm dần level để tìm đến tầng cần lấy giá trị.
		getNode_1Level(root->ChildLeft, level - 1);
		getNode_1Level(root->ChildRight, level - 1);
	}
}

void printTree(Node* root)
{
	//clear q để chuẩn bị cho lần in mới
	while (!q.empty())
	{
		q.pop();
	}

	//lấy về chiều cao của cây để biết phải lặp mấy lần
	int h = countHeight(root);

	//tạo vòng lặp có số lần lặp bằng đúng chiều cao của cây để lấy node của từng tầng từ trên xuống dưới
	for (int i = 0; i < h; i++)
	{
		getNode_1Level(root, i + 1);
	}

	//sau khi lấy hết các node của từng tầng trong cây thì ta có q là hàng đợi chứa tất cả các node của cây. 
	//Bây giờ cần in cây theo quy cách
	//tạo 1 chỉ số chạy theo q
	// Tầng 1 có start_index=2^0-1=0 và có 2^0=1 phần tử.
	// Tầng 2 có start_index=2^1-1=1 và có 2^1=2 phần tử.
	// Tầng 3 có start_index=2^2-1=3 và có 2^2=4 phần tử...
	
	int i = 0; //chỉ số chạy theo số node trong q

	int width = pow(2, h + 1); //số lượng ký tự/1 dòng
	int tangcu = 0; //biến lưu thứ tự của tầng cũ trước khi sang tầng mới.

	//lấy dần các node trong q ra và tính vị trí của nó trên dòng cần in ra
	while (!q.empty())
	{
		int tangthu = (int)log2(i); //tính node hiện tại thuộc tầng thứ bao nhiêu
		//kiểm tra xem tầng của node hiện tại có phải là tầng mới hay không
		if (tangthu>tangcu)
		{
			//nếu đã sang tầng mới thì in ra 1 dấu xuống dòng và cập nhật lại tầng cũ về tầng hiện tại để chuẩn bị cho lần kiểm tra sau
			cout << endl;
			tangcu++;
		}

		int khoangcachgiuacacnode = width / pow(2,tangthu+1); //khoảng cách giữa các node trong tầng hiện tại
		
		//in node hiện tại ra vị trí giữa của khoangcachgiuacacnode
		for (int j = 0; j < khoangcachgiuacacnode; j++)
		{
			//nếu không phải là vị trí giữa thì in ra dấu " "
			if (j != khoangcachgiuacacnode / 2) {
				cout << " ";
			}
			else
			{
				//nếu là vị trí giữa thì in ra giá trị của node đang xét
				cout << q.front();
				//sau khi lấy node đang xét để in ra thì loại nó ra khỏi q
				q.pop();
			}
		}
		i++;//tăng i lên để biết chỉ số của node tiếp theo trong q
	}
}

int main()
{
	BST t = CreateBST();
	t.root = insert_Node(10, t.root);
	t.root = insert_Node(5, t.root);
	t.root = insert_Node(14, t.root);
	t.root = insert_Node(4, t.root);
	t.root = insert_Node(7, t.root);
	t.root = insert_Node(20, t.root);


	cout << "Chieu cao cua cay: " << countHeight(t.root) << endl;

	printTree(t.root);

}