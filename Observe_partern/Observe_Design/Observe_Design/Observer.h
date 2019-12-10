#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observer{
public:
	Observer() {}
	virtual ~Observer(){}
	virtual void Update(){}
};

class Blog {
private:
	list<Observer*> m_observers;
protected:
	string m_status;//�ҵ�״̬
public:
	Blog(){};
	virtual ~Blog(){};
	void Attach(Observer *observer){ m_observers.push_back(observer); }//���ӹ۲���
	void Remove(Observer *observer){ m_observers.remove(observer); }//�Ƴ��۲���
	void Notify(){//֪ͨ�۲���
		list <Observer*>::iterator iter = m_observers.begin();
		for (; iter != m_observers.end(); iter++){
			(*iter)->Update();
		}
	}
	virtual void setStatus(string s){ m_status = s; }//����״̬
	virtual string Getstatus(){ return m_status; }//���״̬

};

#endif