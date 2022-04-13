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
		int m_ID;
		std::chrono::system_clock::time_point m_startT;

	public:
	Oscilator(sf::Vector3f Pos = sf::Vector3f(0, 0, 0), double Lambda = 630 ) : m_Pos{Pos}
	{
		m_startT = std::chrono::system_clock::now();
	}
	double setValue(double r, double t)
	{
		return (pow(m_Ez*cos(2*M_PI / m_Lambda*(t*C - r)), 2));
	}
	sf::Vector3f getPos()
	{
		return m_Pos;
	}
	

};
class Screen
{
	private:
		double m_X;
		double m_Y;
		double m_PS;
		double m_Max;
		double m_Min;
		sf::Vector3f m_PSx;
		sf::Vector3f m_PSy;
		sf::Vector3f m_Pos;
		std::vector<Oscilator*> m_Oscilator;//public static
		std::vector<std::vector<std::vector<double>>> m_Distance;
		std::vector<std::vector<double>> m_Values;
	public:
		Screen(double X = 1920, double Y = 1080):m_X{X}, m_Y{Y}
		{
//			std::vector<std::vector<std::vector<double>>> dist(sizeof(m_Oscilator)/sizeof(m_Oscilator[0][0]), std::vector<std::vector<double>>(m_X, std::vector<double>(m_Y)));
			std::vector<std::vector<double>> values(m_X, std::vector<double>(m_Y)); 
			m_Values = values;
			m_Pos = sf::Vector3f(1, 0, 0);
			m_PSx = sf::Vector3f(0, 1, 0);
			m_PSy = sf::Vector3f(0, 0, -1);
			m_PS = 1.79e-4;

		}
		std::vector<std::vector<double>> countDistances(Oscilator& osc)
		{
			std::vector<std::vector<double>>dist(m_X, std::vector<double>(m_Y));
			for(int i = 0; i < m_X; ++i)
			{
				for(int j = 0; j < m_Y; ++j)
				{
					sf::Vector3f L = m_Pos - osc.getPos() + static_cast<float>(i) * m_PSx + static_cast<float>(j) * m_PSy;
					dist[i][j] = sqrt(pow(L.x, 2)+pow(L.y, 2)+pow(L.z, 2));

				}
			}
			return dist;
		}
		void addOsc(Oscilator& osc)
                {
                        m_Oscilator.push_back(&osc);
//			this->countDistances(osc);
			m_Distance.push_back(this->countDistances(osc));
                        
                }

		void setValues(double t)
		{
			for(int i = 0; i < m_X; ++i)
			{
				for(int j = 0; j < m_Y; ++j)
				{
					for(int k = 0; k < sizeof(m_Oscilator)/sizeof(m_Oscilator[0][0]); ++k)
					{
						m_Values[i][j] += m_Oscilator[k]->setValue(m_Distance[k][i][j], t);
						if(m_Values[i][j] > m_Max)
							m_Max = m_Values[i][j];
						else if(m_Values[i][j] < m_Min)
							m_Min = m_Values[i][j];
					}
				}
			}
		}
//		void setColor(std::vector<std::vector<sf::RectangleShape>>&pix)
		void setColor(sf::RectangleShape pix, int i, int j)		
                {       
                        double R, G, B;
                        G = 0;
			R = 0;
//			for(int i = 0; i < m_X; ++i)
//                      {       
//                        	R = 255 - 255/sqrt(pow(m_Y,2)+pow(m_X, 2))*sqrt(pow(i, 2)+pow(j, 2)) ;
//                        	for(int j = 0; j < m_Y; ++j)
//                              {       
//                                      B = 255/sqrt(pow(m_Y,2)+pow(m_X, 2))*sqrt(pow(i, 2)+pow(j, 2));
//					R = 255 - 255/sqrt(pow(m_Y,2)+pow(m_X, 2))*sqrt(pow(i, 2)+pow(j, 2)) ;
					B = 255 * (m_Values[i][j] - m_Min) /(m_Max - m_Min);	
					pix.setFillColor(sf::Color(R, G, B));
//                                }       
//			}       
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
			std::chrono::system_clock::time_point T;
			std::chrono::system_clock::time_point GNS = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> t;
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
//				T = std::chrono::system_clock::now();
//				t = T - GNS;
				sf::Event ev;
				while(win.pollEvent(ev))
				{
					if(ev.type == sf::Event::Closed)
						win.close();
				}
				
//				this->setColor(pixel);
				T = std::chrono::system_clock::now();      
                                t = T - GNS;

				this->setValues(t.count()/1000);
				for(int i = 0; i < m_X; ++i)
				{
					for(int j = 0; j < m_Y; ++j)
					{
						this->setColor(pixel[i][j], i, j);
						win.draw(pixel[i][j]);
					}
				}
				win.display();
				win.clear();
			}
			std::cout<<"You are fucking cunt, suck my dick"<<std::endl;
		}
//		void Prfmnc(double t)
//		{       
//        		this->countDistancies();
//			this->setValues(t);
//			this->setColor();
//			this->render();
//			}
};
int main()
{
	double timeK = 1.0;
	std::chrono::system_clock::time_point GNS = std::chrono::system_clock::now();
	Screen src;
	Oscilator osc;
	src.addOsc(osc);
	src.render();
	return 0;
}

