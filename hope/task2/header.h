#ifndef d
#define d
	class Block
	{
        	private:    
                	int m_lnght, m_ps, m_pst, m_id;
        	public:
                	void setLenght(int& vl)
                	{
                        	m_lnght = vl;
                	}
                	int getLenght()
                	{
                        	return m_lnght;
                	}
                	void setPos(int& vl)
                	{
                        	m_ps = vl;
                	}
                	int getPos()
                	{
                        	return m_ps;
                	}
                	void setPst(int& vl)
                	{
                        	m_pst = vl;
                	}
                	int getPst()
                	{
                        	return m_pst;
                	}
			void setId(int &vl)
			{
				m_id = vl;
			}
			int getId()
			{
				return m_id;
			}
	};
#endif

