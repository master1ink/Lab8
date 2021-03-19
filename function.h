#include <fstream>
#pragma once
#include <iostream>
#include <string>
#ifndef header_h
#define header_h
using namespace std;
class List{
private:
    struct Computer{
        string model;
        string processor;
        int memory;
        int price;
        int fast;
    };

public:
    struct Node{
        Computer cell;
        Node *next{};
    };
    List()= default;;
    ~List()= default;;
    static Node* memoryAllocation(Node* head, int n);
    static Node* deleteMemory(Node* head);
    static Node* removingItem(Node* head);
    static Node* mergingLists(Node* myList, Node* &splitedList);
    Node* AddItem(Node* head);
    Node* readFile(Node* myList);
    static void cellPath(Node* &currentCell, Node* &save, int number);
    void keyboardInput(Node* head, int n);
    void searchItem(Node* head);
    void sorting(Node* head);
    void itemEditing(Node* head);
    static void addingItemEnd(Node* head);
    void writeFile(Node* head);
    static void outputDisplay(Node* currentCell);
    static void listLength(Node* myList);
    static void splittingList(Node*& myList, Node* &splitedList);
    static void menu();
};
#endif /* Header_h */