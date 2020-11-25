#include "iostream"
#include "MatrixFunctions.h"
#include "fstream"

using namespace std;
//Список 1. Задание 4

void List::Add(int x, int y, int z) {
    Node *temp = new Node;
    temp->next = nullptr;
    temp->value = x;
    temp->indexX = y;
    temp->indexY = z;

    if (head != nullptr) {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    } else {
        temp->prev = nullptr;
        head = tail = temp;
    }

}

void List::readFile(List firstList, List secondList) {
    ifstream f("List.txt");
    if (!f.is_open())
        perror("error while opening file");

    if (f.bad())
        perror("error while reading file");
    while (!f.eof()) {
        string s;
        getline(f, s);
        int pos, length, x, y, z;
        pos = s.find(' ');
        x = stoi(s.substr(0, pos));
        length = s.length() - pos;
        s = s.substr(pos + 1, length);
        pos = s.find(' ');
        y = stoi(s.substr(0, pos));
        s = s.substr(pos + 1, length);
        pos = s.find(' ');
        z = stoi(s.substr(0, pos));
        firstList.Add(x, y, z);
    }
    f.close();
    ifstream file("List2.txt");
    if (!file.is_open())
        perror("error while opening file");

    if (file.bad())
        perror("error while reading file");
    while (!file.eof()) {
        string s;
        getline(f, s);
        int pos, length, x, y, z;
        pos = s.find(' ');
        x = stoi(s.substr(0, pos));
        length = s.length() - pos;
        s = s.substr(pos + 1, length);
        pos = s.find(' ');
        y = stoi(s.substr(0, pos));
        s = s.substr(pos + 1, length);
        pos = s.find(' ');
        z = stoi(s.substr(0, pos));
        secondList.Add(x, y, z);
    }
    file.close();
}

void List::findByFirstIndex(int num) {
    while (head->next != nullptr && num < head->indexX) {
        if (num != head->indexX) {
            head = head->next;
        }
    }

}

void List::findBySecondIndex(int num) {
    while (head->next != nullptr && num < head->indexY) {
        if (num != head->indexY) {
            head = head->next;
        }
    }

}

void List::findByValue(int num) {
    while (head->next != nullptr) {
        if (num != head->value) {
            head = head->next;
        }
    }
}

void List::sumOfMAtrix(Node *firstList, Node *secondList) {
    List newList;
    if (firstList->indexX < secondList->indexX || firstList->indexY < secondList->indexY) {
        newList.Add(firstList->indexX, firstList->indexY, firstList->value);
        firstList = firstList->next;
    } else if (firstList->indexX > secondList->indexX || firstList->indexY > secondList->indexY) {
        newList.Add(secondList->indexX, secondList->indexY, secondList->value);
        secondList = secondList->next;
    } else {
        newList.Add(secondList->indexX, secondList->indexY, secondList->value + firstList->value);
        firstList = firstList->next;
        secondList = secondList->next;
    }

}

void List::multiOfMAtrix(Node *firstList, Node *secondList) {
    List newList;
    if (firstList->indexX < secondList->indexX || firstList->indexY < secondList->indexY) {
        newList.Add(firstList->indexX, firstList->indexY, firstList->value);
        firstList = firstList->next;
    } else if (firstList->indexX > secondList->indexX || firstList->indexY > secondList->indexY) {
        newList.Add(secondList->indexX, secondList->indexY, secondList->value);
        secondList = secondList->next;
    } else {
        newList.Add(secondList->indexX, secondList->indexY, secondList->value * firstList->value);
        firstList = firstList->next;
        secondList = secondList->next;
    }
}

void multiMAtrixOnVector(Node *List, int arr[]) {
    int j = 0, c = 0;
    for (int i = 0; i < 5; i++) {
        Node *temp = List;
        if (temp->indexX == i) {
            c += arr[temp->indexY] * temp->value;
            temp = temp->next;
        } else {
            temp = temp->next;
        }
    }
}


//Список 2. Задание 10



