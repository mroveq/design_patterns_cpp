#include <iostream>

class Fruit {
public:
	virtual ~Fruit() = default;
	virtual void performCut() = 0;
};

class Banana : public Fruit {
	virtual void performCut() override { std::cout << "Banana cut" << std::endl; }
};

class Vegetable {
public:
	virtual ~Vegetable() = default;
	virtual void performCut() = 0;
};

class Carrot : public Vegetable {
	virtual void performCut() override { std::cout << "Carrot cut" << std::endl; }
};

class FruitKnife {
public:
	void performCut(Fruit *fr) {
		std::cout << "Perfom Fruit cut" << std::endl;
		fr->performCut();
	}
};

class FruitAdapter : public Fruit {
private:
	Vegetable* m_vegetable;
public:
	FruitAdapter (Vegetable *veg) { m_vegetable = veg; }
	virtual void performCut() override { m_vegetable->performCut(); }
};

int main()
{
	Banana* banana = new Banana;
	Carrot* carrot = new Carrot;
	FruitKnife fr_knife;
	FruitAdapter* adapter = new FruitAdapter(carrot);

	fr_knife.performCut(banana);
	fr_knife.performCut(adapter);
	delete banana;
	delete carrot;
	delete adapter;
	return 0;
}

