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
	string m_status;//我的状态
public:
	Blog(){};
	virtual ~Blog(){};
	void Attach(Observer *observer){ m_observers.push_back(observer); }//增加观察者
	void Remove(Observer *observer){ m_observers.remove(observer); }//移除观察者
	void Notify(){//通知观察者
		list <Observer*>::iterator iter = m_observers.begin();
		for (; iter != m_observers.end(); iter++){
			(*iter)->Update();
		}
	}
	virtual void setStatus(string s){ m_status = s; }//设置状态
	virtual string Getstatus(){ return m_status; }//获得状态

};

#endif