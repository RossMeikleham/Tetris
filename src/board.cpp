
#include "board.h"

Board::Board(int w, int h) {
   width = w;
   height = h; 
   state = new vector<bool>[height];
   for (int i = 0; i < height; i++) {
        state[i].reserve(width);
   }
   
}


#include <stdio.h>

int Board::eliminateRows() {

   int count = 0;

   for (int i = 0; i < height; i++) {
        
      bool has_gaps = false;

      for (int j = 0; j < width; j++) {
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
        for (int l = 0; l < width; l++) {
            this->state[0][l] = false;
        }

        count++;
      }
   }
   
   return count; 
}



void Board::print_board() {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            printf("%d ", this->state[i][j] == true ? 1 : 0);
        }
        printf("\n");
    }
    printf("\n");
}

void Board::fill_row(int row) {
    for (int i = 0; i < width; i++) {
        this->state[row][i] = true;
    }

}

