#ifndef LABORATORIES_3_MATRIXFUNCTION_H
#define LABORATORIES_3_MATRIXFUNCTION_H



#include "cstring"

using namespace std;
struct Node {
    int value, indexX, indexY;
    Node *next, *prev;
};

class List {
    Node *head, *tail;
public:
    List() : head(nullptr), tail(nullptr) {};

    void Add(int x, int y, int z);

    void findBySecondIndex(int num);

    void findByFirstIndex(int num);

    void findByValue(int num);

    static void multiOfMAtrix(Node *firstList, Node *secondList);

    static void sumOfMAtrix(Node *firstList, Node *secondList);

    static void readFile(List firstList, List secondList);


};


#endif //LABORATORIES_3_MATRIXFUNCTION_H
