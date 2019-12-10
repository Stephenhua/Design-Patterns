#include <iostream>
#include <string>
#include <list>
using namespace std;
class Subject;
class Observe{
    public:
    Observe(string name ,Subject *sub){
        this->name=name;
        this->sub=sub;
    }
    virtual void update()=0;
};

class StackObserver:public Observe{
    public:
    StackObserver(string name ,Subject *sub):Observe(name,sub){}
    void update();
};

class NBAObserver:public Observe{
    NBAObserver(string name ,Subject *sub):Observe(name,sub){};
    void update();
};

class Subject{
    protected:
    list<Observe* >observes;
    public:
    string action;
    virtual void Attach(Observe*)=0;
    virtual void Detach(Observe*)=0;
    virtual void Notify()=0;
};

class Secretary:public Subject{
    public:
    void attch(Observe *observer){
        observes.push_back(observer);
    }

    void detach(Observe *observer){
        list<Observe*>::iterator iter= observes.begin();
        while(iter!=observes.end()){
            if((*iter)!=observes.end()){
                observes.erase(iter);
            }

            ++iter;
        }
    }

    void notify(){
        list<Observe*>::iterator iter=observes.begin();
        while((*iter)!=observes.end()){
            (*iter)->update();
            ++iter;
        }
    }
};

void StackObserver::update(){
    cout << name << " 收到消息：" << sub->action << endl;
    if (sub->action == "梁所长来了!")
    {
        cout << "我马上关闭股票，装做很认真工作的样子！" << endl;
    }
}

void NBAObserver::update(){
    cout << name << " 收到消息：" << sub->action << endl;
    if (sub->action == "梁所长来了!")
    {
        cout << "我马上关闭NBA，装做很认真工作的样子！" << endl;
    }
}

int main(){
    Subject *pSubject=new Secretary();
    Observe *xs= new NBAObserver("hua",pSubject);
    Observe *ys=new NBAObserver("zai",pSubject);
    Observe *lm= new StackObserver("limi",pSubject);

    pSubject->Attach(xs);
    pSubject->Attach(ys);
    pSubject->Attach(lm);

    pSubject->action("去吃饭了！");
    pSubject->Notify();

    cout<<endl;
    pSubject->action("人来了");
    pSubject->Notify();
    system("pause");
    return 0;    
}