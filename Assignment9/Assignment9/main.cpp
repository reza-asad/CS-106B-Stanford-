//
//  main.cpp
//  Assignment9
//
//  Created by Reza Asad on 7/27/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include <iostream>

#include "utility.hpp"

int main() {
    // creating a graph
    nodeT * node1 = new nodeT;
    nodeT * node2 = new nodeT;
    nodeT * node3 = new nodeT;
    nodeT * node4 = new nodeT;
    nodeT * node5 = new nodeT;
    nodeT * node6 = new nodeT;
    
    node1->name = "1";
    node2->name = "2";
    node3->name = "3";
    node4->name = "4";
    node5->name = "5";
    node6->name = "6";
    
    arcT * arc1 = new arcT;
    arcT * arc2 = new arcT;
    arcT * arc3 = new arcT;
    arcT * arc4 = new arcT;
    arcT * arc5 = new arcT;
    
    arc1->start = node1;
    arc1->end = node2;
    arc2->start = node2;
    arc2->end = node3;
    arc3->start = node3;
    arc3->end = node4;
    arc4->start = node4;
    arc4->end = node5;
    arc5->start = node5;
    arc5->end = node6;
    
    set<arcT*> arcs1 = {arc1};
    set<arcT*> arcs2 = {arc2};
    set<arcT*> arcs3 = {arc3};
    set<arcT*> arcs4 = {arc4};
    set<arcT*> arcs5 = {arc5};
    set<arcT*> arcs6 = {};

    node1->arcs = arcs1;
    node1->arcs = arcs2;
    node1->arcs = arcs3;
    node1->arcs = arcs4;
    node1->arcs = arcs5;
    node1->arcs = arcs6;
    
    set<nodeT*> nodes = {node1, node2, node3, node4, node5, node6};
    graphT * graph = new graphT;
    graph->nodes = nodes;
    
    
    return 0;
}
