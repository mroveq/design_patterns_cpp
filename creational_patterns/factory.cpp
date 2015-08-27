#include <iostream>
#include <string>

using namespace std;

class Pet {
public:
	virtual int getPrice() const = 0;
	virtual ~Pet() {};
};

class Mouse : public Pet {
public:
	virtual int getPrice() const { return 20; }
	virtual ~Mouse() {};
};

class Cat : public Pet {
public:
	virtual int getPrice() const { return 28; }
	virtual ~Cat() {};
};

class Fish : public Pet {
public:
	virtual int getPrice() const { return 10; }
	virtual ~Fish() {};
};

class PetFactory {
public:
	enum PetType {
		MouseType,
		CatType,
		FishType
	};

	static Pet* createPet(PetType type) {
		switch(type) {
		case MouseType:
			return new Mouse();
		case CatType:
			return new Cat();
		case FishType:
			return new Fish();
		}
		throw "invalid pizza type";
	}
};

void petInfo(PetFactory::PetType typ)
{
	Pet *p = PetFactory::createPet(typ);
	std::cout << "Pet price: " << p->getPrice() << std::endl;
	delete p;
}
int main()
{
	petInfo(PetFactory::MouseType);
	petInfo(PetFactory::CatType);
}
