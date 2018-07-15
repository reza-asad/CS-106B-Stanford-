//
//  utility.cpp
//  Assignmet6
//
//  Created by Reza Asad on 7/15/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include "utility.hpp"

bool IsBadMovie(Movie & m) {
    return (m.genre == "Drama" and m.rating < 7);
}
