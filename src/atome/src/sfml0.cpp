#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <chrono>
#include <stdlib.h>
#include <ctime>
class Continuum
{
	private:
		int m_atoms = 0;
		int* m_velosities = new int[m_atoms];
		int* m_acceles = new int[m_atoms];
	public:
		Continuum()
		{

		}
		void addAtoms()
		{
			++m_atoms;
		}
};
class Vector
{
	private:
		int m_x;
		int m_y;
	public:
		Vector(int x, int y)
		{
			m_x = x;
			m_y = y;
		};
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
		void move(Vector vec)
		{
		//	move(vec.m_x, vec.m_y);
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
		int m_radious;
		int m_mass;
		bool m_static;
		Vector m_pos();
		Vector m_velosity();
		Vector m_accel();
		Vector m_sumForce();
		Vector m_elS();
		sf::Color color;
	public:
		Atom(int charge = 1, int radious = 50, int mass = 1, bool staticP = 0, Vector vec = setVector(1920/2, 1080/2)) : m_charge{charge}, m_radious{radious}, m_mass{mass}, m_static{staticP}{};
//		{
			//m_pos = setVector(960, 540);
			//m_pos = Vector::Vector(1920/2, 1080/2);
//		}
		void chooseColour(double par)
		{

		}
		void displayAtom(Atom ex)
		{

			sf::CircleShape atom(m_radious);
		}
		

		

	
};
int main()
{
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
        int x = rand()%10; 
	int y = rand()%10;
	int setX = rand()%(xPole - rad * 2);
	int setY = rand()%(yPole - rad * 2);
	std::cout<<rad<<"  "<< setX <<" "<< setY<<std::endl;
	shape.move(setX, setY);
	while (window.isOpen())
	{
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
		window.draw(shape);
		window.display();
	}
	return 0;
}
	


