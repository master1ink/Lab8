#include <iostream>
#include "function.h"

using namespace std;
int main() {
    int choice = 0;
    int quantity = 0;
    List::Node* myList = nullptr;
    List::Node* splitedList = nullptr;
    List lst;
    lst.menu();
    bool loop = true;
    while (loop){
        cout << "\n Enter: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                myList = lst.memoryAllocation(myList, quantity);
                break;
            case 2:
                lst.keyboardInput(myList, quantity);
                break;
            case 3:
                lst.searchItem(myList);
                break;
            case 4:
                lst.sorting(myList);
                break;
            case 5:
                lst.itemEditing(myList);
                break;
            case 6:
                lst.addingItemEnd(myList);
                break;
            case 7:
                myList = lst.removingItem(myList);
                break;
            case 8:
                myList = lst.AddItem(myList);
                break;
            case 9:
                lst.writeFile(myList);
                break;
            case 10:
                myList = lst.readFile(myList);
                break;
            case 11:
                if (splitedList != nullptr)
                {
                    cout << "First List: " << endl;
                    lst.outputDisplay(myList);
                    cout << "Second List: " << endl;
                    lst.outputDisplay(splitedList);
                }
                else
                {
                    lst.outputDisplay(myList);
                }
                break;
            case 12:
                myList = lst.deleteMemory(myList);
                splitedList = lst.deleteMemory(splitedList);
                cout << "Free mem. " << endl;
                break;

            case 13:
                lst.listLength(myList);
                break;

            case 14:
                myList = lst.mergingLists(myList, splitedList);
                break;

            case 15:
                lst.splittingList(myList, splitedList);
                break;

            case 16:
                myList = lst.deleteMemory(splitedList);
                myList = lst.deleteMemory(myList);
                loop = false;
                break;
            case 17:
                lst.menu();
                break;
        }
    }
    return 0;
}