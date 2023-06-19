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
int i = 0;
int pick = 0;
int final_pick = 0;
int max_pick = 0;
int pick_array[10000];

int Minimax::minimax_cnt(State *state, int depth, bool minimaxingplayer)
{

    if(depth == 0)
        return state->evaluate();

    if(minimaxingplayer)
    {
        val = -INT16_MAX;
        for(auto &p: state->legal_actions)
            val = std::max(val, minimax_cnt(state->next_state(p), depth-1, !minimaxingplayer));
    } 
    else
    {
        val = INT16_MAX;
        for(auto &p: state->legal_actions)
            val = std::min(val, minimax_cnt(state->next_state(p), depth-1, !minimaxingplayer));
    }

    if(depth == 1)
    {
        i = val;
        pick_array[pick] = i;
        pick++;
    }

    return val;
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

  int m = minimax_cnt(state, 2, 1);

  for(int k = 0; k < pick; k++)
  {
    if(pick_array[k] >= max_pick) 
    {
        max_pick = pick_array[k];
        final_pick = k;
    }
  }
  auto actions = state->legal_actions;
  return actions[final_pick];
}