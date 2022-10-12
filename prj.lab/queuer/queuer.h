#ifndef QUEUER_H_
#define QUEUER_H_


class QueueR {
public:
    QueueR();
    void push(int value);       // ���������� �������� � �������
    int top();                 // ������� ������� � ��������� ����������� (����������� �������� � ����� ������)
    void pop();                 // ������� ������� � ��������� ����������� (����������� �������� � ����� ������)
    bool isEmpty();             // �������� ������� �� �������
    ~QueueR();
private:
    struct Node {
        Node(int value) : Node(value, nullptr) {}
        Node(int value, Node* next) : val(value), nxt(next) {}

        int val;
        Node* nxt;
    };

    Node* begin;                // ��������� �� ������ �������
};





#endif