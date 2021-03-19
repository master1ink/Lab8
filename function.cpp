#include <iostream>
#include <string>
#include "function.h"

using namespace std;
List::Node* List::deleteMemory(List::Node* myList){
    List::Node* temp;
    while (myList != nullptr){
        temp = myList;
        myList = myList->next;
        delete temp;
    }
    myList = nullptr;
    return myList;
}
List::Node* List::memoryAllocation(List::Node* myList, int n){
    int choice = 1;
    if (myList != nullptr){
        cout << "Recreate?" << endl;
        cout << "1. Yes " << endl;
        cout << "2. No" << endl;
        cin >> choice;
    }
    if (choice == 1){
        deleteMemory(myList);
        cout << "\nNumb items: ";
        cin >> n;
        List::Node* head = nullptr;
        List::Node* tail = nullptr;
        List::Node* current = nullptr;
        for (int i = 0; i < n; i++){
            current = new List::Node;
            if (head == nullptr){
                head = current;
            }
            else{
                tail->next = current;
            }
            tail = current;
        }
        tail->next = nullptr;
        return head;
    }
    else{
        return myList;
    }
}
List::Node* List::mergingLists(List::Node* myList, List::Node* &splitedList){
    if ( myList != nullptr ){
        List::Node* save = splitedList;
        List::Node* currentCell = myList;
        List::Node* head = currentCell;
        while (currentCell->next != nullptr){
            currentCell = currentCell->next;
        }
        currentCell->next = save;
        splitedList = nullptr;
        return head;
    }
    else if (splitedList != nullptr){
        return splitedList;
    }
    else{
        cout << "Not merging" << endl;
    }
    return splitedList;
}
void List::cellPath(List::Node* &currentCell, List::Node* &save, int number){
    if (currentCell != nullptr){
        while (number != 1){
            number--;
            save = currentCell;
            currentCell = currentCell->next;
        }
    }
}
List::Node* List::removingItem(List::Node* head){
    int number;
    cout << "Numb item:";
    cin >> number;
    List::Node* currentCell = head;
    List::Node* save = currentCell;
    if (number == 1){
        head = currentCell->next;
        delete save;
    }
    else{
        cellPath(currentCell, save, number);
        save->next = currentCell->next;
        delete currentCell;
    }
    return head;
}
List::Node* List::AddItem(List::Node* head){
    List::Node* currentCell = head;
    List::Node* save = currentCell;
    List::Node* newCell = new List::Node;
    int position;
    cout << "Numb items";
    cin >> position;
    cellPath(currentCell, save, position);
    string model,processor;
    int fast,memory,price;
    cout << "Model:";
    cin >> model;
    newCell->cell.model = model;
    cout << "Processor:";
    cin >> processor;
    newCell->cell.processor = processor;
    cout << "Fast (1-10):";
    cin >> fast;
    newCell->cell.fast = fast;
    cout << "Memory:";
    cin >> memory;
    newCell->cell.memory = memory;
    cout << "Price:";
    cin >> price;
    newCell->cell.price = price;
    if (position == 1){
        newCell->next = head;
        head = newCell;
    }
    else{
        newCell->next = currentCell;
        save->next = newCell;
    }
    return head;
}
List::Node* List::readFile(List::Node* myList){
    List::Node* head = nullptr;
    List::Node* tail = nullptr;
    List::Node* currentCell = nullptr;
    int choice = 1;
    if (myList != nullptr){
        cout << "Recreate?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> choice;
    }
    if (choice == 1){
        deleteMemory(myList);
        ifstream fin;
        fin.open("Data.txt");
        while (!fin.eof()){
            currentCell = new List::Node;
            fin >> currentCell->cell.model;
            fin >> currentCell->cell.processor;
            fin >> currentCell->cell.memory;
            fin >> currentCell->cell.fast;
            fin >> currentCell->cell.price;
            if (head == nullptr){
                head = currentCell;
            }
            else{
                tail->next = currentCell;
            }
            tail = currentCell;
        }
        tail->next = nullptr;
        fin.close();
        cout << "Success!";
    }
    else{
        head = myList;
    }
    return head;
}
void List::keyboardInput(List::Node *head, int n){
    string model,processor;
    int fast,memory,price;
    cout<<"Numb items:"<<endl;
    cin>>n;
    for (int i = 0; i < n; i++){
        cout<<"Model:"<<endl;
        cin >> model;
        head->cell.model = model;
        cout<<"Processor:"<<endl;
        cin >> processor;
        head->cell.processor = processor;
        cout<<"Memory:"<<endl;
        cin >> memory;
        head->cell.memory = memory;
        cout<<"Fast (1-10):"<<endl;
        cin >> fast;
        head->cell.fast = fast;
        cout<<"Price:"<<endl;
        cin >> price;
        head->cell.price = price;
        head = head->next;

    }
}
void List::searchItem(List::Node* head){
    string parameter;
    List::Node * target = new List::Node;
    int counter = 0;
    cout << "Input:";
    cin >> parameter;
    while (head->next != nullptr){
        if (head->next->cell.model == parameter){
            counter++;
            target = head->next;
        }
        head = head->next;
    }
    if (counter != 0){
        cout << "Model:" << target->cell.model << endl;
        cout << "Processor:" << target->cell.processor << endl;
        cout << "Memory:" << target->cell.memory << endl;
        cout << "Fast (1-10):" << target->cell.fast << endl;
        cout << "Price:" << target->cell.price << endl;
    }
    else{
        cout << "No item" << endl;
    }
}
void List::sorting(List::Node* head){
    List::Node* tmp = head->next;
    List::Node* tmp2 = head->next;
    while (tmp != nullptr) {
        tmp2 = head;
        while (tmp2->next != nullptr) {
            if (tmp2->cell.price > tmp2->next->cell.price) {
                int a = tmp2->next->cell.price;
                tmp2->next->cell.price = tmp2->cell.price;
                tmp2->cell.price = a;
            }
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
}
void List::itemEditing(List::Node* currentCell){
    List::Node* save;
    int number,fast,memory,price;
    string model,processor;
    cout << "Item numb:";
    cin >> number;
    cellPath(currentCell, save, number);
    cout << "Model:";
    cin >> model;
    currentCell->cell.model = model;
    cout << "Processor:";
    cin >> processor;
    currentCell->cell.processor = processor;
    cout << "Memory:";
    cin >> memory;
    currentCell->cell.memory = memory;
    cout << "Fast (1-10):";
    cin >> fast;
    currentCell->cell.fast = fast;
    cout << "Price:";
    cin >> price;
    currentCell->cell.price = price;
}
void List::addingItemEnd(List::Node* currentCell){
    while (currentCell->next != nullptr){
        currentCell = currentCell->next;
    }
    int fast,memory,price;
    string model,processor;
    List::Node* newCell = nullptr;
    newCell = new List::Node;
    cout << "Model:";
    cin >> model;
    newCell->cell.model = model;
    cout << "Processor:";
    cin >> processor;
    newCell->cell.processor = processor;
    cout << "Memory:";
    cin >> memory;
    newCell->cell.memory = memory;
    cout << "Fast (1-10):";
    cin >> fast;
    newCell->cell.fast = fast;
    cout << "Price:";
    cin >> price;
    newCell->cell.price = price;
    newCell->next = nullptr;
    currentCell->next = newCell;

}
void List::writeFile(List::Node* head){
    List::Node* currentCell = head;
    ofstream fout;
    fout.open("Data.txt");
    while (currentCell != nullptr)
    {
        fout << currentCell->cell.model << endl;
        fout << currentCell->cell.processor << endl;
        fout << currentCell->cell.memory << endl;
        fout << currentCell->cell.fast << endl;
        fout << currentCell->cell.price << endl;
        currentCell = currentCell->next;
    }
    cout << "Success!" << endl;
    fout.close();

}
void List::outputDisplay(List::Node* currentCell){
    if (currentCell != nullptr){
        int number = 1;
        cout << endl;
        List::Node* links = currentCell;
        while (currentCell != nullptr){
            cout << number << ".\n";
            cout << "Model " << currentCell->cell.model << endl;
            cout << "Processor " << currentCell->cell.processor << endl;
            cout << "Memory " << currentCell->cell.memory << endl;
            cout << "Computer power " << currentCell->cell.fast << endl;
            cout << "Price " << currentCell->cell.price << endl;
            currentCell = currentCell->next;
            links = links->next;
            number++;
        }
        cout << endl;
    }
    else{
        cout << "Mem not alloc." << endl;
    }
}
void List::listLength(List::Node* myList){
    int length = 0;
    List::Node* currentCell = myList;
    while (currentCell != nullptr){
        length++;
        currentCell = currentCell->next;
    }
    cout << "List length " << length << endl;

}
void List::splittingList(List::Node*& myList, List::Node* &splitedList){
    if (splitedList == nullptr){
        List::Node* currentCell = myList;
        List::Node* prevCell = currentCell;
        if (myList != nullptr)
        {
            int number = 0;
            cout << "Item numb: ";
            cin >> number;
            cellPath(currentCell, prevCell, number);
            prevCell->next = nullptr;
            splitedList = currentCell;
        }
    }
}
void List::menu(){
    cout << "1. Mem alloc." << endl;
    cout << "2. Input." << endl;
    cout << "3. Search." << endl;
    cout << "4. Sorting." << endl;
    cout << "5. Editing." << endl;
    cout << "6. Add item end." << endl;
    cout << "7. Remove." << endl;
    cout << "8. Add item." << endl;
    cout << "9. Write file." << endl;
    cout << "10. Read file." << endl;
    cout << "11. Output." << endl;
    cout << "12. Delete." << endl;
    cout << "13. Length." << endl;
    cout << "14. Merge." << endl;
    cout << "15. Split." << endl;
    cout << "16. Stop." << endl;
    cout << "17. Menu." << endl;
}