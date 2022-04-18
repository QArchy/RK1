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
    // указатель на следыющий элемент tail указывает на новый узел
    tail->setPnext(new Node());
    // указатель на предшествующий узел нового узла указывает на tail
    tail->getPnext()->setPprev(tail);
    // указатель на следующий узел нового узла указывает на 0
    tail->getPnext()->setPnext(nullptr);
    // двигаем tail вперед (на новый узел)
    tail = tail->getPnext();
    size++;
}

Data List::pop_front()
{
    if (!empty()) {
        // двигаем голову вперед
        head = head->getPnext();
        // запоминаем данные из бывшей головы
        Data tmp = *head->getPprev()->getData();
        delete head->getPprev();
        head->setPprev(nullptr);
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
        // возвращаем копию данных
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
            // добавляем в конец строки данные (цифру) и пробел
            str.append(QString::number(tmp->getData()->getNumber()) + ' ');
            // двигаем указатель вперед
            tmp = tmp->getPnext();
        }
        file.write(str.toLatin1());
        file.close();
        return;
    }
    // создаем указатель на элемент, предшествующий tail
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
    // находим нужный элемент
    while (pos != 0) {
        tmp = tmp->getPnext();
        pos--;
    }

    if (tmp == head) {
        push_front(data);
        return;
    }
    if (tmp == tail->getPprev()) {
        return;
        push_back(data);
    }

    // создаем новый узел с данными
    Node* new_node = new Node(data.getNumber());
    // указатель на следующий указывает на предыдущий найденного
    new_node->setPprev(tmp->getPprev());
    // указатель на следующий указывает на найденный
    new_node->setPnext(tmp);
    // берем указатель на элемент предшествующий найденному и ставим его на новосозданный узел
    tmp->getPprev()->setPnext(new_node);
    // ставим указатель на следующий элемент найденного на новосозданный
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
