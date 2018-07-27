//
//  utility.hpp
//  Assignment9
//
//  Created by Reza Asad on 7/27/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#ifndef utility_hpp
#define utility_hpp

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct arcT;
struct nodeT {
    string name;
    set<arcT*> arcs;
};
struct arcT {
    nodeT * start;
    nodeT * end;
};
struct graphT {
    set<nodeT *> nodes;
};

bool IsCyclicGraph(graphT & graph);

#endif /* utility_hpp */
