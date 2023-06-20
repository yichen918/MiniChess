#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for alphabeta, 
 * your policy class should have get_move method
 */
class Alphabeta :State{
public:
    static int alphabeta_cnt(State *state, int depth, int alpha, int beta, bool minimaxingplayer);
    static Move get_move(State *state, int depth);
};