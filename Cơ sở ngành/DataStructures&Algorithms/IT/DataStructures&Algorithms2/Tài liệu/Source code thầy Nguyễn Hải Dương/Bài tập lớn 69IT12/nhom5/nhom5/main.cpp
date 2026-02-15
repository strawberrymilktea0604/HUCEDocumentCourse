#include <iostream>
#include <string>
using namespace std;

// ================== CẤU TRÚC NODE ==================
// Mỗi Node trong cây Huffman sẽ lưu:
// - Ký tự (ch) nếu là lá
// - Tần suất xuất hiện (freq)
// - Con trái và con phải
struct Node {
    char ch;
    int freq;
    Node *left;
    Node *right;
};

// ================== HÀM TẠO NODE ==================
Node* createNode(char c, int f, Node* l = NULL, Node* r = NULL) {
    Node* node = new Node;
    node->ch = c;
    node->freq = f;
    node->left = l;
    node->right = r;
    return node;
}

// ================== HÀM TÌM 2 NODE NHỎ NHẤT ==================
// Trong mảng node[], tìm ra 2 node có tần suất nhỏ nhất
void findTwoMin(Node* arr[], int n, int &i1, int &i2) {
    i1 = i2 = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == NULL) continue;

        if (i1 == -1 || arr[i]->freq < arr[i1]->freq) {
            i2 = i1; // node nhỏ nhất cũ thành node nhỏ thứ hai
            i1 = i;  // cập nhật node nhỏ nhất
        }
        else if (i2 == -1 || arr[i]->freq < arr[i2]->freq) {
            i2 = i;  // cập nhật node nhỏ thứ hai
        }
    }
}

// ================== HÀM SINH MÃ HUFFMAN ==================
// Duyệt cây theo để quy ước sinh mã cho từng ký tự
// - Đi trái thêm '0'
// - Đi phải thêm '1'
void buildCodes(Node* root, string code, string codes[256]) {
    if (root == NULL) return;

    // Nếu là node lá (không có con)
    if (root->left == NULL && root->right == NULL) {
        if (code == "") code = "0"; // Trường hợp đặc biệt: chỉ có 1 ký tự duy nhất
        codes[(unsigned char)root->ch] = code;
        return;
    }

    // Đệ quy sang trái và phải
    buildCodes(root->left, code + "0", codes);
    buildCodes(root->right, code + "1", codes);
}

// ================== HÀM GIẢI MÃ ==================
// Duyệt cây theo chuỗi nhị phân để lấy lại ký tự gốc
string decode(Node* root, string &encoded) {
    string result = "";
    Node* curr = root;

    // Duyệt từng bit trong chuỗi đã mã hóa
    for (int i = 0; i < (int)encoded.size(); i++) {
        char bit = encoded[i];
        if (bit == '0')
            curr = curr->left;
        else
            curr = curr->right;

        // Nếu gặp node lá thì lấy ký tự
        if (curr->left == NULL && curr->right == NULL) {
            result += curr->ch;
            curr = root; // quay lại gốc để giải mã ký tự tiếp theo
        }
    }

    return result;
}

// ================== HÀM GIẢI PHÓNG BỘ NHỚ ==================
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// ================== HÀM MÃ HÓA HUFFMAN ==================
void huffmanEncoding(string text) {
    // 1. Đếm tần suất hiện của từng ký tự
    int freq[256] = {0}; // mảng 256 phần tử bao toàn bộ mã ASCII
    for (int i = 0; i < text.size(); i++) {
        char c = text[i];
        freq[(unsigned char)c]++;
    }

    // 2. Tạo mảng các node lá
    Node* nodes[512]; // tối đa 256 lá + 256 node trung gian
    int n = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            nodes[n++] = createNode((char)i, freq[i]);
        }
    }

    // 3. Xây cây Huffman
    while (true) {
        int i1, i2;
        findTwoMin(nodes, n, i1, i2);
        if (i2 == -1) break; // chỉ còn 1 node => đó là gốc

        // Ghép 2 node nhỏ nhất thành 1 node cha
        Node* parent = createNode(0, nodes[i1]->freq + nodes[i2]->freq);
        parent->left = nodes[i1];
        parent->right = nodes[i2];
        nodes[i1] = parent;
        nodes[i2] = NULL;
    }

    // 4. Lấy gốc cây
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            root = nodes[i];
            break;
        }
    }

    // 5. Sinh mã Huffman
    string codes[256];
    buildCodes(root, "", codes);

    // 6. In bảng mã Huffman
    cout << "===== BẢNG MÃ HUFFMAN =====\n";
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            if (isprint(i)) // nếu là ký tự in được (chữ, số, dấu)
                cout << (char)i << " (" << freq[i] << "): " << codes[i] << "\n";
            else
                cout << "\\x" << hex << i << dec << " : " << codes[i] << "\n";
        }
    }

    // 7. Mã hóa chuỗi gốc
    string encoded = "";
    for (int i = 0; i < text.size(); i++) {
        encoded += codes[(unsigned char)text[i]];
    }
    cout << "\nChuoi sau khi ma hoa: " << encoded << "\n";

    // 8. Giải mã để kiểm tra
    string decoded = decode(root, encoded);
    cout << "Chuoi sau khi giai ma: " << decoded << "\n";

    // 9. Giải phóng bộ nhớ
    freeTree(root);
}

// ================== HÀM MAIN ==================
int main() {
    string input;
    cout << "Nhap chuoi: ";
    getline(cin, input);

    huffmanEncoding(input);
    return 0;
}
