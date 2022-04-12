#include "list.h"

int main() {
    List<int> *list = new List<int>(10);
    list->Insert(0, 15);
    list->Insert(0, 8);
    list->Insert(0, 6);
    list->Insert(0, 4);
    list->Delete(0);
    list->Delete(2);
    list->Insert(2, 14);
    list->Insert(3, 17);

    list->Display();

    List<int> listA = List<int>(10);
    listA.Insert(0, 12);
    listA.Insert(0, 10);
    listA.Insert(0, 9);
    listA.Insert(0, 8);
    listA.Insert(0, 7);
    listA.Insert(0, 6);

    listA.Display();

    List<int> unionList = list->Union(&listA);
    listA.Display();
    unionList.Display();

    List<int> differenceList = list->Difference(&listA);
    differenceList.Display();
    
    List<int> intersectionList = list->Intersection(&listA);
    intersectionList.Display();
    listA.Display();

    return 0;
}