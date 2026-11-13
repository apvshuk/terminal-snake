#include <stdio.h>
#include <ncurses.h>
#include <time.h>

void draw_snake(int *snake_x, int *snake_y, int size, int index_);

int snake_x[100] = {10, 10, 10, 10, 10, 10, 10, 10};
int snake_y[100] = {10, 11, 12, 13, 14, 15, 16, 17};
int max_index = 7;          	// max index of snake_y or snake_x

int index_ = 0;

int main(void) {
	initscr();              // starts ncurses, enters alternate screen, inializes stdscr
	cbreak();               // keypresses reach program instantly, no ENTER needed
	noecho();               // keys you press don't print on screen
	curs_set(0);            // hides the blinking cursor
	nodelay(stdscr, TRUE);  // non-blocking input, meaning, it returns ERR instead of blocking
		   	        // the screen


	struct timespec last, now;
	while (1) {
	        clear();            // wipes the entire screen
		int ch = getch();   // reads a keypress; returns ERR if none (because of nodelay above)

	    if (ch == 'q') break;
    

		clock_gettime(CLOCK_MONOTONIC, &now);
		double elapsed = (now.tv_sec - last.tv_sec) * 1000.0 + (now.tv_nsec - last.tv_nsec) / 1e6;
		if (elapsed >= 70) {
			// fps code here

			// draw snake
			draw_snake(snake_x, snake_y, max_index, index_);

			last = now;
		}


		refresh();          // actually pushes everything to the terminal
	}



	endwin(); 		    // exits alternate screen, restores terminal to original state
	return 0;
}

void draw_snake(int *snake_x, int *snake_y, int size, int index_) {
	if (index_ > size) {
		index_ = 0;
		return;
	}
	mvprintw(snake_y[index_], snake_x[index_], "0");
	index_ += 1;
	draw_snake(snake_x, snake_y, size, index_);
}

void move_snake() {
	
}