#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <queue>

#include "../state/state.hpp"
#include "./minimax.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */

int visited[BOARD_H][BOARD_W] = {0};
int val = 0;

int Minimax::minimax_cnt(State *state, int depth, bool minimaxingplayer)
{

    if(depth == 0)
        return val;

    if(minimaxingplayer)
    {
        val = -INT16_MAX;
        for(auto &p: state->legal_actions)
                val = std::max(val, minimax_cnt(state->next_state(p), depth-1, false));
        return val;
    } 
    else
    {
        val = INT16_MAX;
        for(auto &p: state->legal_actions)
            val = std::min(val, minimax_cnt(state->next_state(p), depth-1, true));
        return val;
    }
}

/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */

Move Minimax::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  
  auto actions = state->legal_actions;
  return actions[(minimax_cnt(state, 2, true))%actions.size()];
}