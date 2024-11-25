#include <iostream>
using namespace std;

struct LinkedList {
    LinkedList *next;
    LinkedList *prev;
    int data;
};

LinkedList *head = nullptr;

void display(LinkedList *head) {
    LinkedList *current = head;
    if (current != nullptr) {
        cout << "[ ";
        do {
            cout << current->data << " <-> ";
            current = current->next;
        } while (current != head);
        cout << "]" << endl;
    } else {
        cout << "[]" << endl;
    }
}

void insertFirst(LinkedList *&head, int val) {
    LinkedList *newNode = new LinkedList();
    newNode->data = val;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head; // Circular references
    } else {
        LinkedList *current = head;
        while (current->next != head) {
            current = current->next;
        }
        newNode->next = head;
        newNode->prev = current;
        current->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

void insertLast(LinkedList *&head, int val) {
    LinkedList *newNode = new LinkedList();
    newNode->data = val;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head; // Circular references
    } else {
        LinkedList *current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        newNode->next = head;
        head->prev = newNode;
    }
}

void insertAtAny(LinkedList *&head, int position, int val) {
    LinkedList *newNode = new LinkedList();
    newNode->data = val;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head; // Circular references
    } else if (position == 1) {
        insertFirst(head, val);
    } else {
        LinkedList *current = head;
        int pos = 1;

        while (pos < position - 1 && current->next != head) {
            current = current->next;
            pos++;
        }

        if (pos < position - 1) {
            cout << "Position is out of bounds." << endl;
            delete newNode;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

void deleteFirst(LinkedList *&head) {
    if (head == nullptr) {
        cout << "The list is empty" << endl;
        return;
    }

    LinkedList *temp = head;

    if (head->next == head) {
        head = nullptr;
    } else {
        LinkedList *current = head;
        while (current->next != head) {
            current = current->next;
        }
        head = head->next;
        current->next = head;
        head->prev = current;
    }

    delete temp;
}

void deleteLast(LinkedList *&head) {
    if (head == nullptr) {
        cout << "The list is empty" << endl;
        return;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        LinkedList *current = head;
        while (current->next->next != head) {
            current = current->next;
        }
        LinkedList *temp = current->next;
        current->next = head;
        head->prev = current;
        delete temp;
    }
}

void deleteAtAny(LinkedList *&head, int position) {
    if (head == nullptr) {
        cout << "The list is empty" << endl;
        return;
    }

    if (position == 1) {
        deleteFirst(head);
    } else {
        LinkedList *current = head;
        int pos = 1;

        while (pos < position - 1 && current->next != head) {
            current = current->next;
            pos++;
        }

        if (current->next == head) {
            cout << "Position is out of bounds." << endl;
            return;
        }

        LinkedList *temp = current->next;
        current->next = temp->next;
        temp->next->prev = current;
        delete temp;
    }
}

void reverse(LinkedList *&head) {
    if (head == nullptr) {
        cout << "The list is empty" << endl;
        return;
    }

    LinkedList *prev = nullptr;
    LinkedList *current = head;
    LinkedList *next = nullptr;
    LinkedList *start = head;

    do {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    } while (current != start);

    head->next = prev;
    head->prev = prev->next;
    head = prev;
}

void menu(LinkedList *&head);

void deletionMenu(LinkedList *&head) {
    int choice, sub;
    cout << "*********Deletion Menu*******\n\n";
    cout << "1. Delete At Beginning\n\n2. Delete At Last \n\n3. Delete At Any Position\n\n0. Back to Menu\n";
    cin >> choice;
    
    switch (choice) {
        case 1:
            system("CLS");
            deleteFirst(head);
            display(head);
            cout << "\n\n";
            cout << "Enter\n\n1. Back to Menu  0. Exit\n\n";
            cin >> sub;
            if (sub == 1) {
                system("CLS");
                deletionMenu(head);
            } else {
                return;
            }
            break;
        case 2:
            system("CLS");
            deleteLast(head);
            display(head);
            cout << "\n\n";
            cout << "Enter\n\n1. Back to Menu  0. Exit\n\n";
            cin >> sub;
            if (sub == 1) {
                system("CLS");
                deletionMenu(head);
            } else {
                return;
            }
            break;
        case 3:
            system("CLS");
            cout << "Enter position\n\n";
            int pos;
            cin >> pos;
            deleteAtAny(head, pos);
            display(head);
            cout << "\n\n";
            cout << "Enter\n\n1. Back to Menu  0. Exit\n\n";
            cin >> sub;
            if (sub == 1) {
                system("CLS");
                deletionMenu(head);
            } else {
                return;
            }
            break;
        case 0:
            system("CLS");
            menu(head);
            break;
    }
}

void insertionMenu(LinkedList *&head) {
    int choice, sub;
    int pos, val;
    cout << "\n\n*********Insertion Menu*******\n\n";
    cout << "1. Insertion At Beginning\n\n2. Insertion At Last\n\n3. Insertion At Any Position\n\n0. Return to Menu\n\n";
    cin >> choice;
    switch (choice) {
        case 1:
            system("CLS");
            cout << "Enter value\n\n";
            cin >> val;
            insertFirst(head, val);
            display(head);
            cout << "Enter\n\n1. Back to Menu  0. Exit\n\n";
            cin >> sub;
            if (sub == 1) {
                insertionMenu(head);
            } else {
                return;
            }
            break;
        case 2:
            system("CLS");
            cout << "Enter value\n\n";
            cin >> val;
            insertLast(head, val);
            system("CLS");
            display(head);
            cout << "Enter\n\n1. Back to Menu  0. Exit\n\n";
            cin >> sub;
            if (sub == 1) {
                system("CLS");
                insertionMenu(head);
            } else {
                return;
            }
            break;
        case 3:
            system("CLS");
            cout << "Enter position\n\n";
            cin >> pos;
            cout << "Enter value\n\n";
            cin >> val;
            insertAtAny(head, pos, val);
            display(head);
            cout << "Enter\n\n1. Back to Menu  0. Exit\n\n";
            cin >> sub;
            if (sub == 1) {
                system("CLS");
                insertionMenu(head);
            } else {
                return;
            }
            break;
        case 0:
            system("CLS");
            menu(head);
            break;
        default:
            cout << "Invalid choice\n\n";
            menu(head);
            break;
    }
}

void menu(LinkedList *&head) {
    cout << "\n\n*********Circular Doubly LinkedList*******\n\n";
    cout << "1. Insertion\n\n2. Deletion\n\n3. Reverse\n\n0. Exit\n\n";
    int option;
    cin >> option;
    switch (option) {
        case 1:
            system("CLS");
            insertionMenu(head);
            break;
        case 2:
        system("CLS");
        deletionMenu(head);
        break;
        case 3:
        system("CLS");
        reverse(head);
        break;  

            }
            }

    int main()
    {
        LinkedList *head = NULL;
        menu(head);
    }