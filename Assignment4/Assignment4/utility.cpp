//
//  utility.cpp
//  Assignment4
//
//  Created by Reza Asad on 7/5/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include "utility.hpp"

void PrintList(Cell * list) {
    while(list != NULL) {
        cout << list->value << endl;
        list = list -> next;
    }
}

Cell * ConvertToList(vector<int> & cells) {
    Cell * list = NULL;
    for (int i = 0; i < cells.size(); ++i) {
        Cell * newCell = new Cell;
        newCell -> value = cells[i];
        newCell -> next = list;
        list = newCell;
    }
    return list;
}

Cell * ConvertToList2(vector<int> & cells) {
    if (cells.size() == 0 ) {
        Cell * list = new Cell;
        list = NULL;
        return list;
    }
    Cell * list = new Cell;
    list -> value = cells[0];
    vector<int> subCells(cells.begin()+1, cells.end());
    list -> next = ConvertToList2(subCells);
    return list;
}

int SumList(Cell *list) {
    if (list == NULL) return 0;
    return list->value + SumList(list->next);
}

void Append(Cell * & first, Cell * & second) {
    if (first == NULL) {
        first = second;
        return;
    }
    if (first -> next == NULL) {
        first -> next = second;
        return;
    }
    Append(first -> next, second);
}




