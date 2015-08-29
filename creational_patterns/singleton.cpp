#include <iostream>
#include <string>

using namespace std;

class SingletonObject
{
private:
	const SingletonObject &operator=(const SingletonObject &object);
	SingletonObject(const SingletonObject &object);

	string m_name;
	int m_id;
public:
	void setName(const string &ref) { m_name = ref; }
	string getName() { return m_name; }
	void setId(const int id) { m_id = id; }
	int getId() { return m_id; }

	static SingletonObject& instance()
	{
		static SingletonObject *obj = new SingletonObject;
		return *obj;
	}
	SingletonObject() {}
};

//SingletonObject obj;

int main()
{
	const string str("project name");

	SingletonObject::instance().setName(str);
	SingletonObject::instance().setId(20);
	std::cout << SingletonObject::instance().getName() << std::endl;
	std::cout << SingletonObject::instance().getId() << std::endl;

	return 0;
}

