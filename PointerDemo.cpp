#include <iostream>

struct Node {
    int value;
    Node* next;
};

class PointerDemo {
private:
    Node* head;

public:
    PointerDemo() {
        head = nullptr;
    }

    ~PointerDemo() {
        Node* tmp;
        while (head != nullptr) {
            tmp = head;
            head = head->next;
            delete tmp;     // zwalnianie pamięci
        }
    }

    void create(int v) {
        head = new Node();
        head->value = v;
        head->next = nullptr;
        std::cout << "Utworzono pierwszy node o wartosci " << v << "\n";
    }

    void addNext(int v) {
        if (head == nullptr) {
            std::cout << "Najpierw utwórz head!\n";
            return;
        }
        head->next = new Node();
        head->next->value = v;
        head->next->next = nullptr;
        std::cout << "Dodano next o wartosci " << v << "\n";
    }

    void print() {
        Node* ptr = head;
        while (ptr != nullptr) {
            std::cout << "Node: " << ptr->value << "\n";
            ptr = ptr->next;    // przejście wskaźnikiem
        }
    }

    void menu() {
        while (true) {
            std::cout << "\n--- MENU ---\n"
                      << "1. Ustaw head\n"
                      << "2. Dodaj next do head\n"
                      << "3. Wyswietl\n"
                      << "4. Wyjscie\n"
                      << "Wybor: ";

            int ch;
            std::cin >> ch;

            if (ch == 1) {
                int v;
                std::cout << "Wartosc: ";
                std::cin >> v;
                create(v);
            }
            else if (ch == 2) {
                int v;
                std::cout << "Wartosc: ";
                std::cin >> v;
                addNext(v);
            }
            else if (ch == 3) print();
            else if (ch == 4) break;
            else std::cout << "Zly wybor.\n";
        }
    }
};

int main() {
    PointerDemo d;
    d.menu();
    return 0;
}
