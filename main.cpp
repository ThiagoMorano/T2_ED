#include <SFML/Graphics.hpp>

struct pos
{
    int x;
    int y;
};

class cFruit
{
    private:
        int x;
        int y;

    public:
        cFruit()
        {
            x = sf::Randomizer::Random(0,19);
            y = sf::Randomizer::Random(0,19);
        }

        int xVal()
        {
            return x;
        }

        int yVal()
        {
            return y;
        }

        void draw(sf::RenderWindow & App)
        {
            App.Draw(sf::Shape::Circle(x*10+5,y*10+5,5.0,sf::Color(255,0,0)));
        }

        void generate()
        {
                x = sf::Randomizer::Random(0,19);
                y = sf::Randomizer::Random(0,19);
        }

        ~cFruit() {}
};

class cSnake
{
    private:
        pos body[400];
        int x;
        int y;
        int direction;
        int length;

    public:
        cSnake()
        {
            x = 10;
            y = 10;
            body[0].x = x;
            body[0].y = y;
            direction = sf::Randomizer::Random(1,4);
            length = 1;
        }

        void move()
        {
            for(int i=length-1;i != 0;i--)
            {
                    body[i].x = body[i-1].x;
                    body[i].y = body[i-1].y;
            }

            switch(direction)
            {
                case 1:
                y--;
                break;

                case 2:
                y++;
                break;

                case 3:
                x++;
                break;

                case 4:
                x--;
                break;
            }

            body[0].x = x;
            body[0].y = y;

        }

        void setDirection(int dir)
        {
                direction = dir;
        }

        void draw(sf::RenderWindow & App)
        {
            for(int i=0;i<length;i++)
                App.Draw(sf::Shape::Rectangle(body[i].x*10+1,body[i].y*10+1,body[i].x*10+9,body[i].y*10+9,sf::Color(0,255,0)));
        }

        void addBodyPiece()
        {
            length++;
            for(int i=length-1;i != 0;i--)
            {
                    body[i].x = body[i-1].x;
                    body[i].y = body[i-1].y;
            }

            body[0].x = x;
            body[0].y = y;
        }

        bool eatFruit(cFruit & fruit)
        {
            if(x == fruit.xVal() && y == fruit.yVal())
                return true;
            else
                return false;
        }

        bool wallHit()
        {
            if(y == -1 || y == 20 || x == -1 || x == 20)
                return true;
            else
                return false;
        }

        bool bodyHit()
        {
            for(int i=2;i<length;i++)
                if(body[i].x == x && body[i].y == y)
                    return true;

            return false;
        }

        bool fruitCollision(cFruit & fruit)
        {
            for(int i=0;i<length;i++)
                if(body[i].x == fruit.xVal() && body[i].y == fruit.yVal())
                    return true;

            return false;
        }

        ~cSnake() {}
};

int main()
{
    sf::RenderWindow App(sf::VideoMode(200,200),"Snake");

    cSnake snake;
    cFruit fruit;

    while(App.IsOpened())
    {
        sf::Event Event;
        while(App.GetEvent(Event))
        {
            if(Event.Type == sf::Event::Closed)
                App.Close();

            if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
                App.Close();

            if(App.GetInput().IsKeyDown(sf::Key::Up))
                snake.setDirection(1);

            if(App.GetInput().IsKeyDown(sf::Key::Down))
                snake.setDirection(2);

            if(App.GetInput().IsKeyDown(sf::Key::Right))
                snake.setDirection(3);

            if(App.GetInput().IsKeyDown(sf::Key::Left))
                snake.setDirection(4);
        }

        snake.move();

        if(snake.eatFruit(fruit))
        {
            fruit.generate();

            while(snake.fruitCollision(fruit))
            fruit.generate();

            snake.addBodyPiece();
        }

        if(snake.wallHit() || snake.bodyHit())
            snake = cSnake();

        App.Clear();
        snake.draw(App);
        fruit.draw(App);
        App.Display();

        sf::Sleep(0.1);
    }

    return 0;
}

/*MAIN OLD VERSION
#include <SFML/Graphics.hpp>
#include "game_state.h"
#include "main_game.h"

game_state coreState;
bool quitGame = false;

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake BCC Edition");

    //Preparing the core state
    coreState.SetWindow(&window);
    coreState.SetState(new main_game());

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Green);

        //Update the state
        coreState.Update();
        //Render the state
        coreState.Render();


        // end the current frame
        window.display();

        //Close the window in case the game ended
        if(quitGame) {
            window.close();
        }

    }

    return 0;
}
*/
