#ifndef QUEUER_H_
#define QUEUER_H_


class QueueR {
public:
    QueueR();
    void push(int value);       // Добавление элемента в очередь
    int top();                 // Вернуть элемент с наивысшим приоритетом (минимальное значение в нашем случае)
    void pop();                 // Удалить элемент с наивысшим приоритетом (минимальное значение в нашем случае)
    bool isEmpty();             // Проверка очереди на пустоту
    ~QueueR();
private:
    struct Node {
        Node(int value) : Node(value, nullptr) {}
        Node(int value, Node* next) : val(value), nxt(next) {}

        int val;
        Node* nxt;
    };

    Node* begin;                // Указатель на начало очереди
};





#endif