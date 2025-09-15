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

// Hàm đệ quy để chèn node có giá trị newData trước node có giá trị key
Node* insertBeforeKey(Node* head, int key, int newData) {
    if (head == nullptr) return nullptr;                 // Nếu danh sách rỗng
    if (head->data == key) {                             // Nếu node đầu có giá trị bằng key
        Node* new_node = new Node(newData);
        new_node->next = head;
        return new_node;                                 // Trả về node mới làm head
    }
    head->next = insertBeforeKey(head->next, key, newData); // Gọi đệ quy cho node tiếp theo
    return head;
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
