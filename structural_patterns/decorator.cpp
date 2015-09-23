// ---------------------------------------------------------------------------
// This software is in the public domain, furnished "as is", without technical
// support, and with no warranty, express or implied, as to its usefulness for
// any purpose.
//
// decorator.cpp
// Decorator structural pattern
//
// Author: lucas <lucas@mroveq.com>
// ---------------------------------------------------------------------------

#include <string>
#include <iostream>

using namespace std;

class Weapon
{
protected:
	std::string m_str;
public:
	Weapon() : m_str("Unknown car") {}
	virtual std::string getDescription() { return m_str; }
	virtual double getCost() = 0;
	virtual ~Weapon() { std::cout << "~Weapon()" << std::endl; }
};

class WeaponAddition : public Weapon
{
public:
	virtual std::string getDescription() = 0;
	virtual ~WeaponAddition() { std::cout << "~WeaponAddition()" << std::endl; }
};

class HK : public Weapon
{
public:
	HK() { this->m_str = "HK()"; }
	virtual double getCost() { return 200.0; }
	virtual ~HK() { std::cout << "~HK()" << std::endl; }
};

class Scope : public WeaponAddition
{
	Weapon * m_w;
public:
	Scope(Weapon *w) { m_w = w; }
	std::string getDescription() { return m_w->getDescription() + ", Scope"; }
	double getCost() { return m_w->getCost() + 30.0; }
	~Scope() { std::cout << "~Scope()" << std::endl; }
};

class WeaponDecoratorExample {
public:
	~WeaponDecoratorExample() { delete m_s; delete m_w; }
	void execute() {
		m_w = new HK();

		std::cout << "Base model of " << m_w->getDescription() <<
			" cost: " << m_w->getCost() << std::endl;

		m_s = new Scope(m_w);
		std::cout << m_s->getDescription() << " cost: " << m_s->getCost() <<
			std::endl;
	}
private:
	Weapon *m_w;
	Weapon *m_s;
};

int main(void)
{
	WeaponDecoratorExample e;
	e.execute();
	return 0;
}
