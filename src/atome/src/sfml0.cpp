#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <chrono>
#include <stdlib.h>
#include <ctime>

	int xPole = 1920;
	int yPole = 1080;
	sf::RenderWindow window(sf::VideoMode(xPole, yPole), "std::string *Freudistic_name");

//class Atome;
class Extremum
{
	private:
		double m_max;
		double m_min;
	public:
		Extremum(double max, double min) : m_max{max}, m_min{min}{};
		double getMax()
		{
			return m_max;
		}
		double getMin()
		{
			return m_min;
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
                friend Vector operator-(const Vector &v1, const Vector &v2);

                void operator=(const Vector &v1)
                {
                        m_x = v1.m_x;
                        m_y = v1.m_y;
                }
                double getVectorValue()
                {        
                        return sqrt(m_x*m_x+m_y*m_y);
                }
		double getX()
		{
			return m_x;
		}
		double getY()
                {       
                        return m_y;
                }
                void set(double x, double y)
                {
                        m_x = x;
                        m_y = y;
                }
                
};
Vector operator+(const Vector &v1, const Vector &v2)
{
        return Vector(v1.m_x + v2.m_x, v1.m_y + v2.m_y);
}
Vector operator-(const Vector &v1, const Vector &v2)
{
        return Vector(v1.m_x - v2.m_x, v1.m_y - v2.m_y);
}

Vector setVector(int xa, int ya)
{
        return Vector(xa, ya);
}

class Atome
{
        private:
                double m_charge;
                int m_rad;
                int m_mass;
                bool m_static;
                Vector m_pos;
                Vector m_velosity;
                Vector m_accel;
                //Vector m_sumForce;
                Vector dS;
                sf::Color color;
		sf::CircleShape shape;

        public:
		friend class Continuum;
		friend class Vector;
                Atome(Vector vec = setVector(0, 0), double charge = 1, int rad = 50, int mass = 1, bool staticP = 0) : m_charge{charge}, m_rad{rad}, m_mass{mass}, m_static{staticP}, m_pos{vec}
		{
			sf::CircleShape fuck(m_rad);
                        shape = fuck;
                        sf::Color m_color(0, 0, 255);
                        shape.setFillColor(m_color);
                        shape.move(m_pos.getX(), m_pos.getY());

		}
		void mooving(Vector v)
		{
			shape.move(v.getX(), v.getY());
		}
		Vector getVelosity()
		{
			return m_velosity;
		}
		void setFillC(sf::Color c)
		{
			shape.setFillColor(c);
		}
/*		sf::Color setColor(Extremum extr)
		{
			int col = 255 *(extr.getMax() - extr.getMin())/( m_velosity.getVectorValue() - extr.getMin());
			return sf::Color(col, 0, 255 - col);	

		}*/
		Vector c_dS(double t)
		{
			double x = m_velosity.getX()*t+m_accel.getX()*t*t/2;
			double y = m_velosity.getY()*t+m_accel.getY()*t*t/2;;

			dS = setVector(x, y);

			return dS;
		}
                void displayAtome();
                
    
};
sf::Color setColor(Atome at, Extremum extr)
{
	int col = 255 *(extr.getMax() - extr.getMin())/(at.getVelosity().getVectorValue() - extr.getMin());
        return sf::Color(col, 0, 255 - col);    
}

class Continuum
{
	private:
		double m_latency;
		double m_TimeShift = 1;
		int m_atomes = 0;
		Atome* m_atomesA = new Atome[m_atomes];
		double* m_acceles = new double[m_atomes];
		double* m_velocities = new double[m_atomes];
		double** m_S = new double*[m_atomes];
		
	public:
		Continuum()
		{
			m_latency = 1/60;
			for(int i = 0; i < m_atomes; ++i)
                        	m_S[m_atomes] = new double[m_atomes];

		}
		double getTime()
		{
			return m_TimeShift * m_latency;
		}

		friend class Atome;
		/*void discon()//every iterative functuon of comtinuum
		{
			selectColour();	
		}*/
		void addAtoms(Atome atome)
                {
                        ++m_atomes;
                        //m_atomesA[m_atomes] = &atome;

                }
		Extremum getParam()
		{
			Vector max = setVector(0, 0);
			Vector min = setVector(0, 0);
			for(int i = 0; i < m_atomes; ++i)
			{
				if (m_atomesA[i].m_velosity.getVectorValue()>max.getVectorValue())
					max = m_atomesA[i].m_velosity;
				else if(m_atomesA[i].m_velosity.getVectorValue()<min.getVectorValue())
					min = m_atomesA[i].m_velosity;
			}
			return Extremum(max.getVectorValue(),min.getVectorValue());


		}
		void wait60()
		{
        		
        		std::chrono::duration<double> frameTime;
        		std::chrono::system_clock::time_point frameTime3 = std::chrono::system_clock::now();         
        		while(frameTime < static_cast<std::chrono::duration<double>>(m_latency))
        		{
               			std::chrono::system_clock::time_point frameTime2 = std::chrono::system_clock::now();
                		frameTime = frameTime2 - frameTime3; 
                		//std::cout<<frameTime.count()<<std::endl;
        		}
        		//std::cout<<frameTime.count()<<std::endl;
        		frameTime -= frameTime;
		}

};
void displayAtome(Atome a, Continuum c)
{
	a.setFillC(setColor(a, c.getParam()));
	a.mooving(a.c_dS(c.getTime()));//a.moving(Vector vec)
}
class Example
{
	private:
		int rad = rand()%500;
	//	float radf;
		//sf::CircleShape shape();
		sf::Color m_color();
		int sx = 0;    
        	int sy = 0;
	        int x = rand()%30; 
        	int y = rand()%30;
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
			std::cout<<rad<<" :sex: "<< setX <<" :sex: "<< setY<<std::endl;
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
	Example ex3;




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
		ex3.displayEx();
		window.display();
		con.wait60();
	}
	return 0;
}
	


