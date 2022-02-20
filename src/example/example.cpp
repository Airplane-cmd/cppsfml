#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <chrono>
#include <stdlib.h>
#include <ctime>
int main()
{
	//chrono::system_clock::time_point frameTime1 = chrono::system_clock::now();
	srand(time(0));
        rand();
        int xPole = 1000;
        int yPole = 1000;
        int rad = rand()%500;
        sf::RenderWindow window(sf::VideoMode(xPole, yPole), "std::string *Freudistic_name");
        sf::CircleShape shape(rad);
        shape.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255));
        int sx = 0;    
        int sy = 0;
        int x = rand()%5; 
        int y = rand()%5;
        int setX = rand()%(xPole - rad * 2);
        int setY = rand()%(yPole - rad * 2);
        std::cout<<rad<<"  "<< setX <<" "<< setY<<std::endl;
        shape.move(setX, setY);
	std::chrono::system_clock::time_point frameTime1 = std::chrono::system_clock::now();
	double latency = 0.016667;
	
        while (window.isOpen())
        {
		std::chrono::duration<double> frameTime;
                sf::Event event;
                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                window.close();
                }
                window.clear();
                if((sy > (yPole - rad * 2)-setY)||(sy < -setY))
                        y = -y;
                if((sx > (xPole - rad * 2)-setX)||(sx < -setX))
                        x = -x;

                shape.move(x, y);
                sx+=x;
                sy+=y;
                //std::cout << sx <<" " << sy<<std::endl;
		//while(frameTime < static_cast<std::chrono::duration<double>>(latency))
		//{
		//	std::chrono::system_clock::time_point frameTime2 = std::chrono::system_clock::now(); 
		//
		//	frameTime = frameTime2 - frameTime1;
		//}
		window.draw(shape);
                window.display();
		frameTime1 = std::chrono::system_clock::now();
        }
        return 0;
}

