#include <list>
#include <iostream>
#include <string>
using namespace std;
#include "Observer.h"
class BlogCSDN :public Blog{
private:
	string m_name;
public:
	BlogCSDN(string name) :m_name(name){}
	~BlogCSDN(){}
	void setStatus(string s){
		m_status = "CSDN 通知" + m_name + s;
	}
/*	string GetStatus(){
		return m_status;
	}
	*/
};

class ObserverBlog : public Observer
{
private:
	string m_name;
	Blog *m_blog;
public:
	ObserverBlog(string name, Blog *blog) :m_name(name), m_blog(blog){}
	~ObserverBlog(){}
	void Update(){
		string status = m_blog->Getstatus();
		cout << m_name << "-----------------" << status << endl;
	}
};

int main(){
	Blog *blog = new BlogCSDN("Hello world");
	Observer *observer1 = new ObserverBlog("NO_1", blog);
	Observer *observer2 = new ObserverBlog("NO_2", blog);

	blog->Attach(observer1);
	blog->Attach(observer2);
	blog->setStatus("观察模式");
	blog->Notify();

	blog->setStatus("moshi");
	blog->Getstatus();
	blog->Notify();
	delete blog;
	delete observer1;
	
	system("pause");
	return 0;
}