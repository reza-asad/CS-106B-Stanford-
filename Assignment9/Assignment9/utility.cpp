//
//  utility.cpp
//  Assignment9
//
//  Created by Reza Asad on 7/27/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include "utility.hpp"

bool depthFirstSearch(nodeT * node, set<nodeT*> & visitedNodes) {
    for (set<arcT*>::iterator it = node->arcs.begin(); it != node->arcs.end(); ++it) {
        if (visitedNodes.find((*it)->end) != visitedNodes.end()) return true;
        visitedNodes.insert((*it)->end);
        depthFirstSearch((*it)->end, visitedNodes);
    }
    return false;
}

bool IsCyclicGraph(graphT & graph) {
    for (set<nodeT*>::iterator it = graph.nodes.begin(); it != graph.nodes.end(); ++it) {
        set<nodeT*> visitedNodes = {};
        visitedNodes.insert(*it);
        if (depthFirstSearch((*it), visitedNodes)) return true;
    }
    return false;
}
