// ---------------------------------------------------------------------------
// This software is in the public domain, furnished "as is", without technical
// support, and with no warranty, express or implied, as to its usefulness for
// any purpose.
//
// builder.cpp
// Builder creational pattern
//
// Author: lucas <lucas@mroveq.com>
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

class Flower {
public:
	void set_color(const string &color) { m_color = color; }
	void set_leaf(const string &leaf) { m_leaf = leaf; }
	void open() { std::cout << "(Flower color): " << m_color <<
		" (leaf shape): " << m_leaf << std::endl; }
private:
	string m_color;
	string m_leaf;
};

class FlowerBuilder {
public:
	virtual ~FlowerBuilder() {};
	Flower* getFlower() { return m_flower; }
	void createNewFlower() { m_flower = new Flower; }

	virtual void build_color() = 0;
	virtual void build_leaf() = 0;
protected:
	Flower *m_flower;
};

class flow_1 : public FlowerBuilder
{
public:
	virtual ~flow_1() {};
	virtual void build_color() { m_flower->set_color("white"); }
	virtual void build_leaf() { m_flower->set_leaf("acicular"); }
};

class Gardener
{
public:
	void setFlowerBuilder (FlowerBuilder *fb) { m_flowerBuilder = fb; }
	Flower* getFlower() { return m_flowerBuilder->getFlower(); }
	void constructFlower() {
		m_flowerBuilder->createNewFlower();
		m_flowerBuilder->build_color();
		m_flowerBuilder->build_leaf();
	}
private:
	FlowerBuilder* m_flowerBuilder;
};

int main()
{
	Gardener grd;

	FlowerBuilder *fl_1 = new flow_1;
	grd.setFlowerBuilder(fl_1);
	grd.constructFlower();
	grd.getFlower()->open();

	delete fl_1;
}
