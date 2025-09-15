#include <iostream>
using namespace std;

// Lớp Node biểu diễn một nút trong danh sách liên kết
class Node {
public:
    int data;
    Node* next;
    Node(int x) { // Hàm khởi tạo
        data = x;
        next = nullptr;
    }
};

// Hàm chèn node có giá trị x vào cuối danh sách, trả về head
Node* insertAtEnd(Node* head, int x) {
    Node* newNode = new Node(x);          // Tạo node mới
    if (head == nullptr) return newNode;  // Nếu danh sách rỗng, node mới là head

    Node* last = head;                    // Con trỏ tạm để duyệt
    while (last->next != nullptr) last = last->next; // Duyệt đến node cuối
    last->next = newNode;                 // Gán node cuối trỏ tới node mới
    return head;                          // Trả về head của danh sách
}

// Hàm in danh sách liên kết từ head
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data;
        if (node->next != nullptr) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);             // Tạo danh sách: 1 -> 2 -> 3 -> 4 -> 5
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = insertAtEnd(head, 6);          // Chèn 6 vào cuối danh sách

    printList(head);                      // In: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    return 0;
}
