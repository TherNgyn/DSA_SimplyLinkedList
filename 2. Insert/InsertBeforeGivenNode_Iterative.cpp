#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* insertBeforeKey(Node* head, int key, int newData) {
    if (head == nullptr) return nullptr; // Nếu danh sách rỗng


    // Nếu node đầu có giá trị bằng key
    if (head->data == key) {
        Node* new_node = new Node(newData);
        new_node->next = head;
        return new_node; // Trả về node mới làm head
    }
    Node* curr = head;
    while (curr->next != nullptr && curr->next->data != key) {
        curr = curr->next;
    }
    // Nếu không tìm thấy key trong danh sách
    if (curr->next == nullptr) {
        cout << "Không tìm thấy node có giá trị " << key << endl;
        return head; // Trả về head của danh sách gốc
    }
    // Chèn node mới trước node có giá trị key
    Node* new_node = new Node(newData);
    new_node->next = curr->next;
    curr->next = new_node;
    return head; // Trả về head của danh sách đã chỉnh sửa
}

// Hàm in danh sách liên kết
void printList(Node* node) {
    Node* curr = node;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);                           // Tạo danh sách: 1 -> 2 -> 3 -> 4 -> 5
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int newData = 6, key = 2;                           // Chèn 6 trước node có giá trị 2
    head = insertBeforeKey(head, key, newData);

    printList(head);                                    // In danh sách sau khi chèn
    return 0;
}
