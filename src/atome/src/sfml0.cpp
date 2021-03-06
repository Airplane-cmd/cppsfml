#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <chrono>
#include <stdlib.h>
#include <ctime>
#include <vector>

	int xPole = 1920;
	int yPole = 1080;
	double timeK = 0.001;
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
		Vector(float x, float y)
		{
			m_x = x;
			m_y = y;
		}
                //Vector(double x, double y) 
                friend Vector operator+(const Vector &v1, const Vector &v2);
                friend Vector operator-(const Vector &v1, const Vector &v2);
		friend double operator*(const Vector &v1, const Vector &v2);
		friend Vector operator*(const double &v1, const Vector &v2);
		friend Vector operator*(const Vector &v1, const double &v2);
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
		/*float getX()
		{
			return m_x;
		}
		float getY()
		{
			return m_y;
		}*/
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
double operator*(const Vector &v1, const Vector &v2)
{
        return(v1.m_x * v2.m_x + v1.m_y * v2.m_y);
}
Vector operator*(const double &v1, const Vector &v2)
{
        return Vector(v1 * v2.m_x, v1 * v2.m_y);
}
Vector operator*(const Vector &v1, const double &v2)
{
        return Vector(v2 * v1.m_x, v2 * v1.m_y);             
}

class Atome
{
        private:
		static int id;
		int m_id;
                double m_charge;
                int m_rad;
                double m_mass;
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
                Atome(Vector vec = setVector(0, 0), Vector vec1 = setVector(0, 0), Vector vec2 = setVector(0, 0), double charge = 1, int rad = 50, double mass = 1, bool staticP = 0) : m_charge{charge}, m_rad{rad}, m_mass{mass}, m_static{staticP}, m_pos{vec}, m_velosity{vec1}, m_accel{vec2}
		{
			m_id = ++id;
			sf::CircleShape fuck(m_rad);
                        shape = fuck;
                        sf::Color m_color(255, 0, 255);
                        shape.setFillColor(m_color);
                        shape.move(m_pos.getX(), m_pos.getY());
//			std::cout<<"ID: "<<m_id<<std::endl;

		}
		void setVelosity(Vector vel)
		{
			m_velosity = vel;
		}
		void setAccel(Vector accel)
		{
			m_accel = accel;
		}
		void movef(double x = 1, double y = 1)
		{
			window.draw(shape);
                        shape.move(x, y);
		}

		void mooving(Vector s)
		{
			window.draw(shape);
			shape.move(s.getX(), s.getY());
//			shape.move(1, 1);
			//window.draw(shape);
//			std::cout<<"sX: "<<s.getX()<<" sY: "<<s.getY()<<std::endl;
		}
		/*sf::CircleShape getAtome()
		{
			return shape;
		}*/
		Vector getVelosity()
		{
			return m_velosity;
		}
		Vector getAccel()
		{
			return m_accel;
		}
		int getID()
		{
			return m_id;
		}
		Vector getPosition()
		{
			return m_pos;
		}
		Vector c_dS(double t)
		{
//			t = 1.0/60.0; 
			 
			double x = m_velosity.getX()*t+m_accel.getX()*t*t/2;
			double y = m_velosity.getY()*t+m_accel.getY()*t*t/2;;

			dS = setVector(x, y);
			m_velosity = m_velosity + m_accel*t;
			//std::cout<<"ds: "<<dS.getY()<<"  VelY: "<<m_velosity.getY()*t<<"  t: "<<t<<std::endl;
			m_pos = m_pos + dS;
			return dS;
		}
                void displayAtome();
		sf::Color setColor(Extremum);
                
    
};
int Atome::id = 0;
/*sf::Color setColor(Atome at, Extremum extr)
{
	int col = 255 *(extr.getMax() - extr.getMin())/(at.getVelosity().getVectorValue() - extr.getMin());
        return sf::Color(col, 0, 255 - col);    
}*/
sf::Color Atome::setColor(Extremum extr)
{
        int col = 255*(m_velosity.getVectorValue()-extr.getMin())/(extr.getMax()-extr.getMin());
	//std::cout<<m_id<<"   "<<col<<" = "<< "255 * ("<<m_velosity.getVectorValue()<<" - "<<extr.getMin()<<")/("<<extr.getMax()<<" - "<<extr.getMin()<<")"<<std::endl;
        return sf::Color(col, 0, 255 - col);    
}

class Continuum
{
	private:
		Vector max;
		Vector min;
		double m_latency;
		double m_TimeShift = timeK;
		int m_atomes = 0;
		std::vector<Atome*> m_atomesA;
		
//		double* m_acceles = new double[m_atomes];
		double* m_velocities = new double[m_atomes];
//		
		
	public:
		Continuum()
		{
			max = setVector(0, 0);       
                        min = setVector(0, 0);  
			m_latency = 1.0/60.0;

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
		void addAtomes(Atome *atome)
                {
                        ++m_atomes;
//			if(atome.getID() == m_atomes)
			m_atomesA.push_back(atome);//fix
                        //m_atomesA[m_atomes] = &atome;

                }
		int getAtomes()
		{
			return m_atomes;
		}
		Extremum getParam()
		{
//			max = setVector(0, 0);
			min = m_atomesA[0]->m_velosity;
				
			for(int i = 0; i < m_atomes; ++i)
			{	
				
				if (m_atomesA[i]->m_velosity.getVectorValue()>max.getVectorValue())
					max = m_atomesA[i]->m_velosity;
				if(m_atomesA[i]->m_velosity.getVectorValue()<min.getVectorValue())
					min = m_atomesA[i]->m_velosity;
//				std::cout<<m_atomesA[i]->m_id<<"c: "<<m_atomesA[i]->m_velosity.getVectorValue()<<std::endl;
			}

//			std::cout<<"max: " <<max.getVectorValue()<<"   min: "<<min.getVectorValue()<<"   Atomes:   "<<m_atomes<<std::endl;
			return Extremum(max.getVectorValue(),min.getVectorValue());


		}
		Vector getAccel(Atome *atome)
		{
//			std::vector<Vector> distancies;
//			std::vector<Vector> forces;
			Vector force = setVector(0, 0);
			Vector distance = setVector(0, 0);
			for(int j = 0; j < m_atomes; ++j)
			{
//				distancies.push_back(m_atomesA[j]->m_pos - atome->m_pos);
//				std::cout<<atome->getID()<<"pref: "<<force.getVectorValue()<<std::endl;
				distance = (m_atomesA[j]->m_pos * 1.79e-4)-(atome->m_pos * 1.79e-4);
									
//				std::cout<<atome->getID()<<distance.getVectorValue()<<std::endl;
				if((m_atomes != 1)&&(distance.getVectorValue() != 0))
				{
					force = force - (9e15 * atome->m_charge * m_atomesA[j]->m_charge)*(1/(pow(distance.getVectorValue(), 3)) * distance);
//					std::cout<<distance.getVectorValue()<<std::endl;
				}
				
//				std::cout<<atome->getID()<<": "<<atome->m_velosity.getVectorValue()<<std::endl;
//				std::cout<<atome->getID()<<": "<<(9e9 * atome->m_mass * m_atomesA[j]->m_mass * (1/(pow(distance.getVectorValue(), 3)))*distance).getVectorValue()<<std::endl;
//				std::cout<<atome->getID()<<": "<<(9e9 * atome->m_mass * m_atomesA[j]->m_mass * (1/(pow(distance.getVectorValue(), 3))))<<std::endl;
				
			}
//			std::cout<<force.getVectorValue()<<std::endl;
			std::cout<<atome->getID()<<": a: "<<atome->m_accel.getVectorValue()<<"  v: "<<atome->m_velosity.getVectorValue()<<std::endl;
			return force * (1/atome->m_mass);
			
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
//			std::cout<<frameTime.count()<<std::endl;
        		frameTime -= frameTime;
		}

};

Continuum con;


void Atome::displayAtome()//(Atome a)//, Continuum c)
{
	if((con.getAtomes())<(this->getID()))
                con.addAtomes(this);
	this->setAccel(con.getAccel(this));
	shape.setFillColor(this->setColor(con.getParam()));
	shape.move(static_cast<float>((this)->c_dS(con.getTime()).getX()), static_cast<float>((this)->c_dS(con.getTime()).getY()));
	window.draw(shape);


//	std::cout<<this->getID()<<"f: x: "<<this->getAccel().getX()<<"  Y: "<<this->getAccel().getY()<<std::endl;

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
			std::cout<<rad<<": "<< setX <<": "<< setY<<std::endl;
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
//	Continuum con;
	srand(time(0));
	rand();
	int frame = 0;
//	example ex;
//	example ex1;
//	Example ex2;
//	Example ex3;
//	double vel = 100;
//	Atome hydrogen(setVector(0, 0), setVector(0, 0), setVector(0, 0), -1.6e-19, 50, 1.7e-27, 0);
	Atome hydrogen1(setVector(50, 50), setVector(0, 0), setVector(0, 0), -1.6e-19, 50, 1.7e-27, 0);
	Atome hydrogen2(setVector(400, 400), setVector(0, 0), setVector(0, 0), -1.e-19, 50, 1.7e-27, 0);
//	Atome hydrogen3(setVector(0, 400), setVector(0, 0), setVector(0, 0), 1, 50, 1, 0);
//	Atome hydrogen4(setVector(500, 500), setVector(-11, -11), setVector(0, 0), 1, 50, 1.7e-27, 0);
//	con.addAtomes(*hydrogen);
//	con.addAtomes(*hydrogen1);
//	con.addAtomes(*hydrogen2);



	while (window.isOpen())
	{
//		vel+=10;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
//		std::cout<<con.getAtomes()<<std::endl;
//		con.getParam();
		window.clear();
//		hydrogen.displayAtome();
		hydrogen1.displayAtome();
		hydrogen2.displayAtome();
//		hydrogen3.displayAtome();
//		hydrogen4.displayAtome();
//		std::cout<<"VF: "<<hydrogen1.getVelosity().getVectorValue()<<std::endl;
		//displayAtome(hydrogen1);//, con);
//		ex.displayEx();
//		ex1.displayEx();
//		ex2.displayEx();
//		ex3.displayEx();
		window.display();
		con.wait60();
	}
	return 0;
}
	


