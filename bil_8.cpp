#include <iostream>

/*
    Программа, которая перед каждым участком 
    из одинаковых элементов в двухсвязном линейном 
    списке вставляет новый узел с длиной этого участка.
*/

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Сама функция
void insertLengthNodes(Node*& head) {
    if (!head) return;

    Node* current = head;

    while (current) {
        int count = 1;
        Node* runner = current->next;

        while (runner && runner->data == current->data) {
            count++;
            runner = runner->next;
        }

        if (count > 1) {
            Node* lengthNode = new Node{count, current, current->prev};
            if (current->prev) {
                current->prev->next = lengthNode;
            } else {
                head = lengthNode;
            }
            current->prev = lengthNode;
        }

        current = runner;
    }
}

// Вспомогательная функция для теста
void printList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Тест функции
int main() {
    Node* head = new Node{1, nullptr, nullptr};
    Node* second = new Node{2, nullptr, head};
    Node* third = new Node{3, nullptr, second};
    Node* fourth = new Node{2, nullptr, third};
    Node* fifth = new Node{2, nullptr, fourth};
    Node* sixth = new Node{2, nullptr, fifth};
    Node* seventh = new Node{4, nullptr, sixth};
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    std::cout << "Изначальный список: ";
    printList(head);

    insertLengthNodes(head);

    std::cout << "Модифицированный список: ";
    printList(head);

    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
