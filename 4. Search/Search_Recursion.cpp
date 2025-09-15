#include <iostream>
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


int searchKey(Node* head, int key, int pos = 1) {
    // Trường hợp danh sách rỗng
    if (head == nullptr)
        return -1;

    // Nếu tìm thấy tại node hiện tại
    if (head->data == key)
        return pos;

    // Nếu chưa thấy → gọi đệ quy cho node tiếp theo
    return searchKey(head->next, key, pos + 1);
}

int main() {
    // Tạo danh sách: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int key = 5;

    int pos = searchKey(head, key);
    if (pos != -1)
        cout << "Tim thay " << key << " tại vi tri " << pos;
    else
        cout << "Khong tim thay!!!";

    return 0;
}
