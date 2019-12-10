#include <iostream>
#include <list>
using namespace std;
class Observe{
    public:
        virtual void Update(int)=0;
};

class Subject{
    public:
    virtual void Attach(Observe *)=0;
    virtual void Detach(Observe*)=0;
    virtual void Notify()=0;
};

class ConcreteObserve :public Observe
{
private:
    /* data */
    Subject *m_project;
public:
    ConcreteObserve(Subject *pSubject):m_pSubject(pSubject){}
    void Update(int value){
        cout<<"ConcreteObserver get the update.Now State:"<<value<<endl;
    }
    //~ConcreteObserve :public Observe();
};

class ConcreteSubject :public Subject{
    private:
        std::list<Observe*> m_ObserverList;
        int m_State;
    public:
        void Attach(Observe * pObserver);
        void Detach(Observe * pObserver);
        void Notify();
        void setState(int state){
            m_iState=state;
        }

};

void ConcreteSubject::Attach(Observe * pObserver){
    m_ObserverList.pop_back(pObserver);
}

void ConcreteSubject::Detach(Observe * pObserver){
    m_ObserverList.remove(Observe *pObserver);
}

void ConcreteSubject::Notify(){
    std::list<Observe*>::iterator it=m_ObserverList.begin();
    while(it!=m_ObserverList.end()){
        (*it)->Update(m_State);
        ++it;
    }
}

int main(){
    //创建subject
    ConcreteSubject *pSubject=new ConcreteSubject(pSubject);
    //创建observe
    Observe *pObserve= new Observe(pObserve);
    Observe *pObserve2= new Observe(pObserve2);

    //设置状态
    pSubject->setState(2);

    //增加订阅者
    pSubject->Attach(pObserve);
    pSubject->Attach(pObserve2);

    //进行广播
    pSubject->Notify();
    
    //删除订阅者
    pSubject->Detach(pObserve);
    
    //增加订阅者
    pSubject->setState(3);
    pSubject->Notify();

    delete pObserve;
    delete pObserve2;
    delete pSubject;


    system("pause");
    return 0;
}