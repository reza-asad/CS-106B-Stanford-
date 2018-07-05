//
//  utility.cpp
//  Assignment4
//
//  Created by Reza Asad on 7/5/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include "utility.hpp"

Cell * ConvertToList(vector<int> & cells) {
    Cell * list = NULL;
    for (int i = 0; i < cells.size(); ++i) {
        Cell * newCell = NULL;
        newCell -> value = cells[i];
        newCell -> next = list;
        list = newCell;
    }
    return list;
}
