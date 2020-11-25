
#ifndef LABORATORIES_3_MAIN_H
#define LABORATORIES_3_MAIN_H

#include "string"

using namespace std;


class BookHero {
public:
    string heroName;
    int status{};
    BookHero *next{};
};


//List Of Heroes
struct listForHeroes {
    BookHero head;
    listForHeroes *next{};
};
class ListOfHeroes {
    listForHeroes *Head;
public:
    ListOfHeroes() { Head = nullptr; }
    void Add(BookHero *el);

};
void ListOfHeroes::Add(BookHero *el) {
    auto *temp = new listForHeroes;
    temp->head = *el;
    temp->next = Head;
    Head = temp;
}
class Book {

public:
    string bookName, author, releaseDate, annotation, mainHero;
    int numOfPage{};
    Book *next{};
    ListOfHeroes *Hero{};

    static void mainFunc();

};

//List Of Books
struct listForBooks {
    Book head;
    listForBooks *next{};
};
class ListOfBooks {
    static listForBooks *Head;
public:
    ListOfBooks() { Head = nullptr; }
    static void sortBySeries( BookHero *first, BookHero *fifth,  BookHero *eighth);
    static void Add(Book *el);
    void sortByData( );
};
void ListOfBooks::Add(Book *el) {
    auto *temp = new listForBooks;
    temp->head = *el;
    temp->next = Head;
    Head = temp;
}
//List Of Lists
struct ListForLists {
    BookHero hero;
    ListOfBooks *head{};
    ListForLists *next{};

};
class ListOfLists {
    ListForLists *Head;
public:
    ListOfLists() { Head = nullptr; }
    void Add(ListOfBooks *el, BookHero *hero);
};
void ListOfLists::Add(ListOfBooks *el, BookHero *hero) {
    auto *temp = new ListForLists;
    temp->hero = *hero;
    temp->head = el;
    temp->next = Head;
    Head = temp;
}



#endif //LAB1_LISTFUNCTIONS_H
