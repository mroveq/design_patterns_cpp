// ---------------------------------------------------------------------------
// This software is in the public domain, furnished "as is", without technical
// support, and with no warranty, express or implied, as to its usefulness for
// any purpose.
//
// prototype.cpp
// Prototype creational pattern
//
// Author: lucas <lucas@mroveq.com>
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <map>

using namespace std;

enum Record_enum {
	SKATEBOARD,
	ROLLERS
};

class Record {
public:
	Record() { std::cout << "Record constructor" << std::endl; }
	virtual ~Record() { std::cout << "Record destructor" << std::endl; }
	virtual Record* clone() = 0;
	virtual void print() = 0;
};

class SkateboardRecord: public Record {
private:
	string m_name;
	int m_id;
public:
	SkateboardRecord(string name, int id) :
		Record(),
		m_name(name),
		m_id(id)
	{
		std::cout << "Skateboard constructor" << std::endl; 
	}

	SkateboardRecord(const SkateboardRecord &record) : Record(record)
	{
		m_name = record.m_name;
		m_id = record.m_id;
	}

	~SkateboardRecord() { std::cout << "Skateboard destructor" << std::endl; }

	Record* clone()
	{
		return new SkateboardRecord(*this);
	}

	void print ()
	{
		std::cout << "SkateBoard: " << m_name << " name: " << m_id << std::endl;
	}
};

class RollerRecord: public Record {
private:
	string m_type;
	int m_wheels;
public:
	RollerRecord(string type, int wheels) :
		Record(),
		m_type(type),
		m_wheels(wheels)
	{ }

	RollerRecord(const RollerRecord &record) : Record(record)
	{
		m_type = record.m_type;
		m_wheels = record.m_wheels;
	}

	~RollerRecord() {}

	Record* clone()
	{
		return new RollerRecord(*this);
	}

	void print ()
	{
		std::cout << "Rollers: " << m_type<< " wheels count: " << m_wheels << std::endl;
	}
};

class RecordFactory
{
private:
	map<Record_enum, Record *> m_RecordReference;
public:
	RecordFactory()
	{
		m_RecordReference[SKATEBOARD] = new SkateboardRecord("yellow thunder", 12);
		m_RecordReference[ROLLERS] = new RollerRecord("sport rollers", 5);
	}
	~RecordFactory()
	{
		delete m_RecordReference[SKATEBOARD];
		delete m_RecordReference[ROLLERS];
	}

	Record *createRecord(Record_enum num)
	{
		return m_RecordReference[num]->clone();
	}
};

int main()
{
	RecordFactory* factory = new RecordFactory();
	Record *rec = factory->createRecord(SKATEBOARD);
	rec->print();
	delete rec;

	Record *rec_2 = factory->createRecord(ROLLERS);
	rec->print();
	delete rec_2;
}
