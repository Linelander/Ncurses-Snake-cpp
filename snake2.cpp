#include <stdio.h>
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


// Classes
class Coord {
    public:
        int x;
        int y;
    public:
    Coord(int nx, int ny)
    {
        x = nx;
        y = ny;
    }
};

class Segment {
    public:
        Coord coord;
        char look = 'o';
        Segment *next;
        Segment *previous;
    public:
        void snakePrint(Segment *n) {
            if (next == NULL)
            {
                return;
            }
            mvprintw(coord.x, coord.y, &look)
            snakePrint(next)
        }
};

class Head : public Segment {
    public:
        char look = 'Y';
};

class Snake {
    private:
        Head head;
        Segment tail;
        Coord direction;
    public:
        void getDirection(void)
        {
            // stub
        }

        void drawSnake(void)
        {
            head.snakePrint();
        }

        bool collisionCheck(void)
        {
            Segment curr = head;
            while (curr != NULL)
            {
                if (curr.coord.x == head.coord.x && curr.coord.y == head.coord.y)
                {
                    return false;
                }
                curr = curr.next;
            }
            return true;
        }

        setDirection()
        {
            
        }
};

class Fruit {
    private:
        Coord location = Coord(-1, -1);
        char look = 'q';
    public:
        void placeFruit(void)
        {
            // randomize x and y and print there
        }
};

class Board{
    private:
        int score = 0;
        int grow_factor = 5;
        int size = 32;
        int speed = 50;    
    
        Snake snake;
        WINDOW window;
        int size;
        int win_height = size;
        int win_width = size * 2;
        Coord start = Coord(1, 1);
        Fruit fruit;
    public:
        void clear(void) {
            for (int i = 1; i < win_height-1; i++)
            {
                for (int j = 1; j < win_width-1; j++)
                {
                    mvprintw(i, j, " ");
                }
            }
        }

        void start(void) {
            // stub
        }

        bool checkFailure()
        {
            return snake.collisionCheck();
        }

        void checkEat(void)
        {
            if (snake.loc() == fruit.loc())
            {
                // grow
            }
        }
};

// Initial settings
void init(void)
{    
    initscr();
    noecho();
    cbreak(); 
    curs_set(0);
    timeout(SPEED);
    refresh();
}




// Gameplay loop
int main(int argc, char **argv)
{

    Board board;

    init();

    WINDOW *snakewin = newwin(board.size, board.size*2, 0, 0);
    box(snakewin, 0, 0);
    nodelay(snakewin, TRUE);




    return 0;
}