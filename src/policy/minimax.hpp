#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class Minimax : State{
public:
    static int minimax_cnt(State *state, int depyh, bool minimaxingplayer);
    static Move get_move(State *state, int depth);
};