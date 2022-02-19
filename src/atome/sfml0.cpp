#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <chrono>
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
		Vector m_pos;
		Vector m_velosity;
		Vector m_accel;
		Vector m_sumForce;
		Vector m_elS;
		sf::Color color;
	public:
		Atom(int charge = 1, int radious = 50, int mass = 1, bool staticP = 0, Vector vec = setVector(1920/2, 1080/2)) : m_charge{charge}, m_radious{radious}, m_mass{mass}, m_static{staticP}j{};
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
	int xPole = 1920;
	int yPole = 1080;
	sf::RenderWindow window(sf::VideoMode(xPole, yPole), "std::string *Freudistic_name");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Blue);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	
		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}
	


