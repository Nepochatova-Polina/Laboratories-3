#include "listFunctions.h"
#include "iostream"
#include "fstream"

void Book::mainFunc() {
    BookHero first = {"Harry Potter", 1};
    BookHero second = {"Hermione Granger", 2};
    BookHero third = {"Ron Weasley", 2};
    BookHero fourth = {"Luna Lovegood", 3};
    ListOfHeroes One;
    One.Add(&first);
    One.Add(&second);
    One.Add(&third);
    One.Add(&fourth);

    BookHero fifth = {"Bilbo Baggins", 1};
    BookHero sixth = {"Frodo Baggins", 2};
    BookHero seventh = {"Gollum", 3};
    ListOfHeroes Two;
    Two.Add(&fifth);
    Two.Add(&sixth);
    Two.Add(&seventh);
    BookHero eighth = {"Mila Rudik", 1};
    BookHero ninth = {"Roman Lapshin", 2};
    BookHero tenth = {"Belyana Veksha", 2};
    ListOfHeroes Three;
    Three.Add(&eighth);
    Three.Add(&ninth);
    Three.Add(&tenth);


    Book one = {"Harry Potter and Stone", "J.K.Rowling",
                "12.02.2001", "Young boy and evil lord", first.heroName, 345};
    one.Hero = &One;
    Book two = {"Harry Potter and Goblet of Fire", "J.K.Rowling",
                "12.12.2007", "Evil lord's servant finds Harry", first.heroName, 452};
    two.Hero = &One;
    Book three = {"Lord of the Rings", "J.Tolkien",
                  "12.02.1954", "the hobbit starts to meet adventures", fifth.heroName, 455};
    three.Hero = &Two;
    Book four = {"Lord of the Rings 2", "J.Tolkien",
                 "12.02.1988", "the hobbit's nephew continues on his way", fifth.heroName, 412};
    four.Hero = &Two;
    Book five = {"Lord of the Rings 3", "J.Tolkien",
                 "12.02.2002", "the hobbit's nephew ends his way", fifth.heroName, 412};
    five.Hero = &Two;
    Book six = {"Mila Rudik and kristall of phobos", "Alec Volskikh",
                "20.05.2012", "Girl going to magic school", eighth.heroName, 212};
    six.Hero = &Three;
    Book seven = {"Mila Rudik and magic synod", "Alec Volskikh",
                  "20.05.2018", "Girl saves her enemy's life", eighth.heroName, 321};
    seven.Hero = &Three;

    ListOfBooks BigList;
    BigList.Add(&one);
    BigList.Add(&two);
    BigList.Add(&three);
    BigList.Add(&four);
    BigList.Add(&five);
    BigList.Add(&six);
    BigList.Add(&seven);

    ListOfBooks::sortBySeries(&first, &fifth, &eighth);
}


void ListOfBooks::sortBySeries(BookHero *first, BookHero *fifth, BookHero *eighth) {
    ListOfBooks one;
    ListOfBooks two;
    ListOfBooks three;
    while (Head != nullptr) {
        if (Head->head.mainHero == first->heroName) {
            one.Add(&Head->head);
            Head = Head->next;
        } else {
            if (Head->head.mainHero == fifth->heroName) {
                two.Add(&Head->head);
                Head = Head->next;
            } else {
                three.Add(&Head->head);
                Head = Head->next;
            }
        }
    }
    one.sortByData();
    two.sortByData();
    three.sortByData();
    ListOfLists BigList;
    BigList.Add(&one, first);
    BigList.Add(&two, fifth);
    BigList.Add(&three, eighth);
}

void ListOfBooks::sortByData() {
    listForBooks *left = Head;
    listForBooks *right = Head->next;
    auto *temp = new listForBooks;

    while (left->next){
        while (right){
            if ((left->head.releaseDate) < (right->head.releaseDate)){
                temp = left;
                left = right;
                right = temp;
            }
            right = right->next;
        }
        left = left->next;
        right = left->next;
    }

}
