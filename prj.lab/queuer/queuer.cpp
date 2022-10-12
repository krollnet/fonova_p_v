#include <queuer/queuer.h>
#include <iostream>

QueueR::QueueR() {
    begin = nullptr;
}

QueueR::~QueueR() {
    Node* current = begin;
    while (current != nullptr) {
        Node* next_node = current->nxt;
        delete current;
        current = next_node;
    }
}

int QueueR::top() {
    return begin->val;
}

void QueueR::pop() {
    if (!isEmpty()) {
        Node* newBegin = begin->nxt;
        delete begin;
        begin = newBegin;
    }
}

void QueueR::push(int value) {
    Node* current = begin;
    Node** refCurrent = &begin;
    while (current != nullptr && value >= current->val) {
        refCurrent = &(current->nxt);
        current = current->nxt;
    }
    Node* newNode = new Node(value, current);
    *refCurrent = newNode;
}

bool QueueR::isEmpty() {
    return begin == nullptr;
}