#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <queue>

#include "../state/state.hpp"
#include "./submission.hpp"


/**
 * @brief get a legal action by alphabeta
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */

int Alphabeta::alphabeta_cnt(State *state, int depth, int alpha, int beta, bool minimaxingplayer)
{
    int val = 0;
    
    if(!state->legal_actions.size())
      state->get_legal_actions();

    if(state->game_state == WIN)
    {
        if(minimaxingplayer == true) //the winner is me
            return 8000000;
        else
            return -8000000; //the winner is the opponent
    }

    else if(depth == 0)
        return state->evaluate(minimaxingplayer);

    else if(minimaxingplayer)
    {
        val = -80000000;
        for(auto &p: state->legal_actions)
        {
            val = std::max(val, alphabeta_cnt(state->next_state(p), depth-1, alpha, beta, false));
            alpha = std::max(alpha, val);
            if(alpha >= beta) 
                break;
        }
    } 
    
    else if(!minimaxingplayer)
    {
        val = 80000000;
        for(auto &p: state->legal_actions)
        {
            val = std::min(val, alphabeta_cnt(state->next_state(p), depth-1, alpha, beta, true));
            beta = std::min(beta, val);
            if(alpha >= beta) 
                break;
        }
    }

    /*if(depth == last_depth)
    {
        pick_array[pick] = val;
        pick++;
    }*/
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
  
  int i = 0;
  int pick_array[100000];
  for(auto &p : state->legal_actions)
  {
    pick_array[i] = alphabeta_cnt(state->next_state(p), depth-1, -80000000, 80000000, false);
    i++;
  }


  //int m = alphabeta_cnt(state, depth, -80000000, 80000000, state->player);
  int final_pick = 0;

  int max_pick = -8000000;
  for(int k=0; k < i ; k++)
  {
    if(pick_array[k] > max_pick) 
    {
        max_pick = pick_array[k];
        final_pick = k;
    }
  }
  auto actions = state->legal_actions;
  return actions[final_pick];
}