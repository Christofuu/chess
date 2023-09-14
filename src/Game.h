//
// Created by Chris on 9/5/2023.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "Board.h"


class Game {
public:
    Game();
    // Methods for game management
    bool isCheckmate();
    bool isCheck();
};


#endif //CHESS_GAME_H
