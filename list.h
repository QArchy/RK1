#ifndef LIST_H
#define LIST_H

typedef unsigned int uint;
#include <QDir>
#include <QString>
#include <QFile>
#include <iostream>

class Data {
private:
    int number;
public:
    Data(){};
    Data(int number) { this->number = number; }
    int getNumber() const { return number; }
    void setNumber(int newNumber) { this->number = newNumber; }
    void operator=(const Data& other) {
        this->number = other.number;
    }
};

class Node {
private:
    Node* pprev = nullptr;
    Node* pnext = nullptr;
    Data* data = nullptr;
public:
    Node() { data = new Data(); }
    Node(int number) { this->data = new Data(number); }
    Node *getPprev() const { return pprev; }
    void setPprev(Node *newPprev) { pprev = newPprev; }
    Node *getPnext() const { return pnext; }
    void setPnext(Node *newPnext) { pnext = newPnext; }
    Data *getData() const { return data; }
    void setData(Data *newData) { *data = *newData; }
    ~Node() { delete data; }
};

class List {
private:
    uint size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    void push_front(Data& data);
    void push_back(Data& data);
    Data pop_front();
    Data pop_back();
    void print(bool reverse);
    void print_to_file(QDir file_path, bool reverse);
    void insert(Data& data, uint pos); // вставка со сдвигом вправо
    void clear();
    bool empty() { return size == 0; }
    uint get_size() { return size; }
    ~List();
};

#endif // LIST_H
