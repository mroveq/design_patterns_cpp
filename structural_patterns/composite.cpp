// ---------------------------------------------------------------------------
// This software is in the public domain, furnished "as is", without technical
// support, and with no warranty, express or implied, as to its usefulness for
// any purpose.
//
// composite.cpp
// Composite structural pattern
//
// Author: lucas <lucas@mroveq.com>
// ---------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>

using namespace std;

class Fruit {
public:
	virtual void show() const = 0;
};

class Apple : public Fruit {
public:
	virtual void show() const {
		std::cout << "This is Apple!" << std::endl;
	}
};

class CompositeFruits {
public:
	void showAll() {
		std::for_each(m_fruitList.begin(), m_fruitList.end(), mem_fun(&Fruit::show));
	}
	void add(Fruit *fr) {
		m_fruitList.push_back(fr);
	}
private:
	std::vector<Fruit *> m_fruitList;
};


int main()
{
	const auto_ptr<Apple> apple_1(new Apple);
	const auto_ptr<Apple> apple_2(new Apple);
	const auto_ptr<Apple> apple_3(new Apple);

	const auto_ptr<CompositeFruits> comp(new CompositeFruits());
	comp->add(apple_1.get());
	comp->add(apple_2.get());
	comp->add(apple_3.get());

	comp->showAll();
	return 0;
}

