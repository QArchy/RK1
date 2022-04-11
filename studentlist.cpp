#include "studentlist.h"

void StudentList::add_student(QString fio) {
    lst[fio];
}
void StudentList::add_subject(QString subj_name) {
    for (auto i = lst.begin(); i != lst.end(); i++)
        i.value()[subj_name];
}
void StudentList::add_grade(QString fio, QString subj_name, uint grade) {
    lst[fio][subj_name].append(grade);
}
double StudentList::get_mean(QString fio, QString subj_name) {
    double sum = 0;
    for (uint i = 0; i < lst[fio][subj_name].size(); i++)
        sum += lst[fio][subj_name][i];
    return sum / lst[fio][subj_name].size();
}
void StudentList::show_student_info(QString fio) {
    std::cout << fio.toStdString() << std::endl;
    std::cout << '\t' << "Оценки по предметам : " << std::endl;
    for (auto i = lst[fio].begin(); i != lst[fio].end(); i++) {
        std::cout << "\t\t" << i.key().toStdString() << " : ";
        for (uint j = 0; j < i.value().size(); j++)
            std::cout << i.value()[j] << ' ';
        std::cout << std::endl;
        std::cout << "\t\t\t" << "Среднее : " << get_mean(fio, i.key());
        std::cout << std::endl;
    }
}
void StudentList::show_all() {
    for (auto i = lst.begin(); i != lst.end(); i++)
        show_student_info(i.key());
}
