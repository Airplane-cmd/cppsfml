#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <chrono>
#include <stdlib.h>
#include <ctime>

	int xPole = 1920;
	int yPole = 1080;
	sf::RenderWindow window(sf::VideoMode(xPole, yPole), "std::string *Freudistic_name");
class Continuum
{
	private:
		int m_atomes = 0;
		Atome* m_atomes = new Atomes[m_atomes];
		double* m_acceles = new double[m_atomes];
		double* m_velocities = new double[m_atomes];
		double** m_S = new double*[m_atomes];
		
	public:
		Continuum()
		{
			for(int i = 0; i < m_atomes; ++i)
                        	m_S[m_atomes] = new double[m_atomes];

		}
		void addAtoms()
		{
			++m_atomes;

		}
		void wait60()
		{
        		double latency = 0.016667;
        		std::chrono::duration<double> frameTime;
        		std::chrono::system_clock::time_point frameTime3 = std::chrono::system_clock::now();         
        		while(frameTime < static_cast<std::chrono::duration<double>>(latency))
        		{
               			std::chrono::system_clock::time_point frameTime2 = std::chrono::system_clock::now();
                		frameTime = frameTime2 - frameTime3; 
                		//std::cout<<frameTime.count()<<std::endl;
        		}
        		//std::cout<<frameTime.count()<<std::endl;
        		frameTime -= frameTime;
		}

};
class Vector
{
	private:
		double m_x;
		double m_y;
	public:
		Vector(double x = 0, double y = 0)
		{
			m_x = x;
			m_y = y;
		};
		Vector(int x, int y)
                {
                        m_x = x;
                        m_y = y;
                };

		//Vector(double x, double y) 
		friend Vector operator+(const Vector &v1, const Vector &v2);
		void operator=(const Vector &v1)
		{
			m_x = v1.m_x;
			m_y = v1.m_y;
		}
		double getVectorVelue()
                {        
                        return sqrt(m_x*m_x+m_y*m_y);
                }
		void setVector(double x, double y)
		{
			m_x = x;
			m_y = y;
		}
		
};
Vector operator+(const Vector &v1, const Vector &v2)
{
	return Vector(v1.m_x + v2.m_x, v1.m_y + v2.m_y);
}
Vector setVector(int xa, int ya)
{
        return Vector(xa, ya);
}

class Atom
{
	private:
		int m_charge;
		int m_rad;
		int m_mass;
		bool m_static;
		Vector m_pos;
		Vector m_velosity;
		Vector m_accel;
		Vector m_sumForce;
		Vector m_elS;
		sf::Color color;
	public:
		Atom(int charge = 1, int rad = 50, int mass = 1, bool staticP = 0, Vector vec = setVector(xPole/2 - rad, yPole/2 - rad)) : m_charge{charge}, m_rad{rad}, m_mass{mass}, m_static{staticP}, m_pos{vec}
		{
			//m_pos = setVector(960, 540);
			m_pos.setVector(xPole/2 - m_rad, yPole/2 - m_rad);
		}
		friend class Continuum;
		void chooseColour(double par)
		{

		}
		void displayAtom(Atom ex)
		{

			sf::CircleShape atom(m_rad);
		}
		

		

	
};
class Example
{
	private:
		int rad = rand()%500;
	//	float radf;
		//sf::CircleShape shape();
		sf::Color m_color();
		int sx = 0;    
        	int sy = 0;
	        int x = rand()%10; 
        	int y = rand()%10;
        	int setX = rand()%(xPole - rad * 2);
        	int setY = rand()%(yPole - rad * 2);
		sf::CircleShape shape;
		//sf::CircleShape shapei;
	public:
		Example()
		{
			
			//rad = rand()%500;
			//radf = rad;
			//shape(radf);
			//int rad = rand()%500;
        		//shape(rad);
			sf::CircleShape fuck(rad);
			shape = fuck;
			sf::Color m_color(rand()%255, 0, rand()%255);
			shape.setFillColor(m_color);
			std::cout<<rad<<"  "<< setX <<" "<< setY<<std::endl;
		        shape.move(setX, setY);
		}
		void displayEx()
		{
			if((sy > (yPole - rad * 2)-setY)||(sy < -setY))
                        	y = -y;
                	if((sx > (xPole - rad * 2)-setX)||(sx < -setX))
                        	x = -x;

                	shape.move(x, y);
                	sx+=x;
                	sy+=y;
        	        //std::cout << sx <<" " << sy<<std::endl;
	                window.draw(shape);
		}
};




int main()
{
	Continuum con;
	srand(time(0));
	rand();
	Example ex;
	Example ex1;
	Example ex2;


//	sf::RenderWindow window(sf::VideoMode(xPole, yPole), "std::string *Freudistic_name");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		ex.displayEx();
		ex1.displayEx();
		ex2.displayEx();
		window.display();
		con.wait60();
	}
	return 0;
}
	


