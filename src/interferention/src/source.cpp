#include<iostream>
#include<SFML/Graphics.hpp>
#include<chrono>
#include<vector>
#include<cmath>
#include<sstream>
#include<memory>
#define _USE_MATH_DEFINES
double C = 299792458;
class Oscilator
{
	private:
		sf::Vector3f m_Pos;
		double m_Lambda;
		double m_Ez;
		std::chrono::system_clock::time_point m_startT;

	public:
	Oscilator(sf::Vector3f Pos = sf::Vector3f(0, 0, 0), double Lambda = 630 ) : m_Pos{Pos}
	{
		m_startT = std::chrono::system_clock::now();
	}
	double setValue(double r, double t)
	{
		return m_Ez*cos(2*M_PI*t*C/m_Lambda-2*M_PI*r/m_Lambda);
	}
	

};
class Screen
{
	private:
		double m_X;
		double m_Y;
		double m_PS;
		sf::Vector3f m_PSx;
		sf::Vector3f m_PSy;
		sf::Vector3f m_Pos;
		std::vector<Oscilator*> m_Oscilator;
	public:
		Screen(double X = 1920, double Y = 1080):m_X{X}, m_Y{Y}
		{

		}
		void addOsc(Oscilator osc)
		{
			m_Oscilator.push_back(&osc);
		}
		void setColors()
		{

		}
		void countDistances()
		{

		}
		void setValues()
		{
			for(int i = 0; i < m_X; ++i)
			{
				for(int j = 0; j < m_Y; ++j)
				{

				}
			}
		}
		void setColor(std::vector<std::vector<sf::RectangleShape>>&pix)                      
                {       
                        double R, G, B;
                        G = 0;
			for(int i = 0; i < m_X; ++i)
                        {       
                        	R = 255/m_X*i;
                        	for(int j = 0; j < m_Y; ++j)
                                {       
                                        B = 255/m_Y*j;
					pix[i][j].setFillColor(sf::Color(R, G, B));
                                }       
			}       
                }
		void render()
		{
			std::stringstream ss;
			std::string s;
			ss<<this;
			ss>>s;
			std::vector<std::vector<sf::RectangleShape>>pixel(m_X, std::vector<sf::RectangleShape>(m_Y));
			sf::RenderWindow win(sf::VideoMode(m_X, m_Y), s);
			sf::RectangleShape ex(sf::Vector2f(1 ,1 ));
			for(int i = 0; i < m_X; ++i)
			{
				for(int j = 0; j < m_Y; ++j)
				{
					pixel[i][j] = ex;
					pixel[i][j].move(i, j);
				}
			}
			while(win.isOpen())
			{
				sf::Event ev;
				while(win.pollEvent(ev))
				{
					if(ev.type == sf::Event::Closed)
						win.close();
				}
				this->setColor(pixel);
				for(int i = 0; i < m_X; ++i)
				{
					for(int j = 0; j < m_Y; ++j)
					{
						win.draw(pixel[i][j]);
					}
				}
				win.display();
				win.clear();
			}
		}
};
int main()
{
	double timeK = 1.0;
	std::chrono::system_clock::time_point GNS = std::chrono::system_clock::now();
	Screen src;
	src.render();
	return 0;
}

