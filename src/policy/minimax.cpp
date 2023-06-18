#include <cstdlib>
#include <iostream>
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
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int Minimax::minimax_cnt(State *state, int depth, bool minimaxingplayer)
{
    int val;

    auto board = this->board.board[this->player];
    priority_queue<State> pq;

    if(depth ==0 || this->evaluate() == 0)
        return this->evaluate();

    if()
    {
        val = -INT16_MAX;
        for(auto &p : )
            val = std::max(val, minimax_cnt(, depth-1, false));
        return val;
    } 
    else
    {
        val = INT16_MAX;
        for(auto &p: )
            val = std::min(val, minimax_cnt(, depth-1, true));
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
  return actions[(rand()+depth)%actions.size()];
}