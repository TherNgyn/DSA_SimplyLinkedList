#include <bits/stdc++.h>
using namespace std;

// Định nghĩa một node trong danh sách liên kết
struct Node {
    int data;
    Node* next;

    // Hàm khởi tạo node
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
}; 

// Hàm chèn một node mới sau node có giá trị key
Node* insertAfter(Node* head, int key, int newData) {
    Node* curr = head;

    // Duyệt danh sách để tìm node có giá trị bằng key
    while (curr != nullptr) {
        if (curr->data == key)
            break;
        curr = curr->next;
    }

    // Nếu curr = nullptr nghĩa là không tìm thấy key trong danh sách
    if (curr == nullptr) {
        cout << "Không tìm thấy node có giá trị " << key << endl;
        // Trả về head của danh sách gốc
        return head;
    }

    // Cấp phát node mới và gán dữ liệu
    Node* newNode = new Node(newData);

    // Liên kết node mới với node kế tiếp của curr
    newNode->next = curr->next;

    // Đổi liên kết của curr sang node mới
    curr->next = newNode;

    // Trả về head của danh sách đã chỉnh sửa
    return head;
}

// Hàm in danh sách liên kết
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Hàm main (chạy thử)
int main() {
    // Tạo danh sách liên kết cứng: 2 -> 3 -> 5 -> 6
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(6);

    cout << "Danh sách ban đầu: ";
    printList(head);

    // Key: chèn node sau node có giá trị key
    int key = 3, newData = 4;

    // Thêm node có dữ liệu 4 sau node có dữ liệu 3
    head = insertAfter(head, key, newData);

    cout << "Danh sách sau khi chèn: ";
    printList(head);

    return 0;
}
