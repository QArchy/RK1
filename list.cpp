#include "list.h"

void List::push_front(Data &data)
{
    if (empty()) {
        head = new Node(data.getNumber());

        tail = new Node();
        tail->setPprev(head);
        tail->setPnext(nullptr);

        head->setPnext(tail);
        head->setPprev(nullptr);

        size++;
        return;
    }
    head->setPprev(new Node(data.getNumber()));
    head->getPprev()->setPnext(head);
    head->getPprev()->setPprev(nullptr);
    head = head->getPprev();
    size++;
}

void List::push_back(Data &data)
{
    if (empty()) {
        push_front(data);
        return;
    }
    tail->setData(&data);
    tail->setPnext(new Node());
    tail->getPnext()->setPprev(tail);
    tail->getPnext()->setPnext(nullptr);
    tail = tail->getPnext();
    size++;
}

Data List::pop_front()
{
    if (!empty()) {
        head = head->getPnext();
        Data tmp = *head->getPprev()->getData();
        delete head->getPprev();
        size--;
        return tmp;
    }
    throw("Empty list");
}

Data List::pop_back()
{
    if (!empty()) {
        tail = tail->getPprev();
        delete tail->getPnext();
        size--;
        return *tail->getData();
    }
    throw("Empty list");
}

void List::print(bool reverse)
{
    if (empty()) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    if (!reverse) {
        Node* tmp = head;
        while (tmp != tail) {
            std::cout << tmp->getData()->getNumber() << ' ';
            tmp = tmp->getPnext();
        }
        return;
    }
    Node* tmp = tail->getPprev();
    while (tmp != nullptr) {
        std::cout << tmp->getData()->getNumber() << ' ';
        tmp = tmp->getPprev();
    }
}

void List::print_to_file(QDir file_path, bool reverse)
{
    QFile file(file_path.absolutePath() + "/output_lst.txt");
    file.open(QFile::WriteOnly);

    QString str;

    if (!reverse) {
        Node* tmp = head;
        while (tmp != tail) {
            str.append(QString::number(tmp->getData()->getNumber()) + ' ');
            tmp = tmp->getPnext();
        }
        file.write(str.toLatin1());
        file.close();
        return;
    }
    Node* tmp = tail->getPprev();
    while (tmp != nullptr) {
        str.append(QString::number(tmp->getData()->getNumber()) + ' ');
        tmp = tmp->getPprev();
    }
    file.write(str.toLatin1());
    file.close();
}

void List::insert(Data &data, uint pos)
{
    if (pos > size - 1)
        throw("Invalid index");

    Node* tmp = head;
    while (pos != 0) {
        tmp = tmp->getPnext();
        pos--;
    }

    if (tmp == head)
        push_front(data);
    if (tmp == tail->getPprev())
        push_back(data);

    Node* new_node = new Node(data.getNumber());
    new_node->setPprev(tmp->getPprev());
    new_node->setPnext(tmp);

    tmp->getPprev()->setPnext(new_node);
    tmp->setPprev(new_node);
}

void List::clear()
{
    while (head != tail) {
        head = head->getPnext();
        delete head->getPprev();
    }
    delete tail;
    tail = nullptr;
    head = nullptr;
}

List::~List()
{
    while (head != tail) {
        head = head->getPnext();
        delete head->getPprev();
    }
    delete tail;
}
