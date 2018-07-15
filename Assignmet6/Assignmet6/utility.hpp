//
//  utility.hpp
//  Assignmet6
//
//  Created by Reza Asad on 7/15/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#ifndef utility_hpp
#define utility_hpp

#include <iostream>
#include <queue>

using namespace std;

template <typename Type>
void FilterQueue(queue<Type> & q, bool (IsBad)(Type) ) {
    int current = 0;
    while (current < q.size()) {
        Type elem = q.front();
        q.pop();
        if (!IsBad(elem)) q.push(elem);
        current++;
    }
}
#endif /* utility_hpp */
