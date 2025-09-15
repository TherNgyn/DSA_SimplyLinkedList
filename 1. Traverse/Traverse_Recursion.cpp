#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    // Constructor 
    Node(int new_data) { // Hàm khởi tạo node 
        this->data = new_data;
        this->next = nullptr;
    }
};

// Hàm đệ quy để duyệt và in danh sách liên kết
void traverseList(Node* head) {
    if (head == nullptr) { // Điều kiện dừng: nếu head là nullptr, danh sách rỗng
        cout << endl;
        return;
    }
    cout << head->data; // In dữ liệu của node hiện tại
    if (head->next != nullptr) {
        cout << " -> ";
    }
    traverseList(head->next); // Gọi đệ quy cho node kế tiếp
}
void traverse(Node* head) {
    while(head != nullptr) {
        cout << head->data;
        if(head->next != nullptr) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Khởi tạo danh sách liên kết rỗng
    Node* head = nullptr;
    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // Duyệt và in danh sách liên kết
    traverse(head);
    return 0;
}