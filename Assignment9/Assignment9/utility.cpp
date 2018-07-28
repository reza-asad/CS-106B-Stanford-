//
//  utility.cpp
//  Assignment9
//
//  Created by Reza Asad on 7/27/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include "utility.hpp"

bool isCyclic(nodeT * node, set<nodeT*> & visitedNodes, nodeT * curr) {
    for (set<arcT*>::iterator it = node->arcs.begin(); it != node->arcs.end(); ++it) {
        if (visitedNodes.find((*it)->end) == visitedNodes.end()) {
            visitedNodes.insert((*it)->end);
            isCyclic((*it)->end, visitedNodes, curr);
        }
    }
    if (visitedNodes.find(curr) != visitedNodes.end()) return true;
    return false;
}

bool IsCyclicGraph(graphT & graph) {
    for (set<nodeT*>::iterator it = graph.nodes.begin(); it != graph.nodes.end(); ++it) {
        set<nodeT*> visitedNodes = {};
        nodeT * curr = (*it);
        if (!isCyclic(curr, visitedNodes, curr)) return false;
    }
    return true;
}
