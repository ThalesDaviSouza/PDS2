#include "list.hpp"

#include <iostream>

void List::insertNode(int data) {
    Node* aux = new Node;
    aux->data = data;
    aux->next = nullptr;
    if (head == nullptr) {
        head = aux;
        tail = aux;
    } else {
        tail->next = aux;
        tail = aux;
    }
}

void List::display() {
    Node* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

// Você deverá implementar apenas esse método
void List::inverte() {
    Node* actual = this->head;
    Node* next = nullptr;
    Node* prev = nullptr;
    
    if(this->head != nullptr){
        next = this->head->next;
    }
    
    while(actual != nullptr){
        actual->next = prev;

        prev = actual;
        actual = next;
        if(next != nullptr){
            next = next->next;
        }
    }

    Node* oldHead = this->head;
    this->head = this->tail;
    this->tail = oldHead;
}
