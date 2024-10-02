#include <iostream>

/*
    Программа, которая определяет, равны ли два 
    односвязных кольцевых списка без учета 
    положения начального узла.
*/

struct Node {
    int data;
    Node* next;
};

// Сама функция
bool areEqual(Node* head1, Node* head2) {
    if (!head1 || !head2) return head1 == head2;

    Node* current1 = head1;
    Node* current2 = head2;
    int length1 = 0, length2 = 0;

    // Вычисление длины 1 списка
    do {
        length1++;
        current1 = current1->next;
    } while (current1 != head1);

    // Вычисление длины второго списка
    do {
        length2++;
        current2 = current2->next;
    } while (current2 != head2);

    // Если длинны списков не равны, то списки не равны, логично
    if (length1 != length2) return false;

    // Сравнение списков
    for (int i = 0; i < length1; ++i) {
        current1 = head1;
        for (int j = 0; j < i; ++j) {
            current1 = current1->next;
        }

        bool match = true;
        current2 = head2;
        for (int j = 0; j < length1; ++j) {
            if (current1->data != current2->data) {
                match = false;
                break;
            }
            current1 = current1->next;
            current2 = current2->next;
        }

        if (match) return true;
    }

    return false;
}

// Её тест
int main() {
    Node* head1 = new Node{3, nullptr};
    Node* second1 = new Node{1, nullptr};
    Node* third1 = new Node{2, nullptr};
    head1->next = second1;
    second1->next = third1;
    third1->next = head1;

    Node* head2 = new Node{2, nullptr};
    Node* second2 = new Node{3, nullptr};
    Node* third2 = new Node{1, nullptr};
    head2->next = second2;
    second2->next = third2;
    third2->next = head2;

    if (areEqual(head1, head2)) {
        std::cout << "Списки одинаковые." << std::endl;
    } else {
        std::cout << "Списски НЕ одинаковые." << std::endl;
    }

    // Очистка памяти
    delete head1;
    delete second1;
    delete third1;
    delete head2;
    delete second2;
    delete third2;

    return 0;
}
