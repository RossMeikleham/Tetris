
#include "board.h"
#include <stdio.h>

using namespace std;


Board::Board(int w, int h, QObject *parent) : 
   QObject(parent),
   m_width(w),
   m_height(h) {
 
   state.resize(w, vector<bool>(h, false)); 
}


// Insert a single block in the specified position 
void Board::insert(int w, int h) {
    state[h][w] = true;    
}


bool Board::isFilled(int w, int h) {
    return this->state[h][w];
}


int Board::clearRows() {

   int count = 0;

   for (int i = 0; i < m_height; i++) {
        
      bool has_gaps = false;

      for (int j = 0; j < m_width; j++) {
        // Gap found in row, check the next
        if (this->state[i][j] == false) {
            has_gaps = true;
            break;
        } 
      }     
      
      if (!has_gaps) {

        // Row is filled, move all rows down
        for (int k = i; k > 0; k--) {
            swap(this->state[k-1], this->state[k]);
        }

        // Clear the top row
        for (int l = 0; l < m_width; l++) {
            this->state[0][l] = false;
        }

        count++;
      }
   }
   
   return count; 
}


/* Prints out current state of the board, 1 represents the space
   being occupied, 0 otherwise */
void Board::print_board() {
    for (int i = 0; i < m_height; i++) {
        for (int j = 0; j < m_width; j++) {
            printf("%d ", this->state[i][j] == true ? 1 : 0);
        }
        printf("\n");
    }
    printf("\n");
}

void Board::fill_row(int row) {
    for (int i = 0; i < m_width; i++) {
        this->state[row][i] = true;
    }

}


int Board::height() {
    return m_height;
}

int Board::width() {
    return m_width;
}

