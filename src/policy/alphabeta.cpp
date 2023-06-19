#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <queue>

#include "../state/state.hpp"
#include "./alphabeta.hpp"


/**
 * @brief get a legal action by alphabeta
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */

int visited[BOARD_H][BOARD_W] = {0};
int val = 0;
int pick = 0;
int final_pick = 0;
int max_pick = 0;
int min_pick = 0;
int pick_array[10000];

int Alphabeta::alphabeta_cnt(State *state, int depth, int alpha, int beta, bool minimaxingplayer)
{

    if(depth == 0)
        return state->evaluate();

    if(minimaxingplayer)
    {
        val = -INT16_MAX;
        for(auto &p: state->legal_actions)
        {
            val = std::max(val, alphabeta_cnt(state->next_state(p), depth-1, alpha, beta, !minimaxingplayer));
            alpha = std::max(alpha, val);
            if(alpha >= beta) 
                break;
        }
    } 
    else
    {
        for(auto &p: state->legal_actions)
        {
            val = std::min(val, alphabeta_cnt(state->next_state(p), depth-1, alpha, beta, !minimaxingplayer));
            beta = std::min(beta, val);
            if(alpha >= beta) 
                break;
        }

    }

    if(depth == 3)
    {
        pick_array[pick] = val;
        pick++;
    }
    return val;
}

/**
 * @brief get a legal action by alphabeta
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */

Move Alphabeta::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();

  int m = alphabeta_cnt(state, 4, -INT16_MAX, INT16_MAX, 1);

  for(int k=0; k<pick ; k++)
  {
    if(pick_array[k] <= max_pick) 
    {
        max_pick = pick_array[k];
        final_pick = k;
    }
  }
  auto actions = state->legal_actions;
  return actions[final_pick];
}