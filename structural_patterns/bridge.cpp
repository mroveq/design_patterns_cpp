// ---------------------------------------------------------------------------
// This software is in the public domain, furnished "as is", without technical
// support, and with no warranty, express or implied, as to its usefulness for
// any purpose.
//
// bridge.cpp
// Bridge structural pattern
//
// Author: lucas <lucas@mroveq.com>
// ---------------------------------------------------------------------------

#include <iostream>
#pragma GCC diagnostic ignored "-Wwrite-strings" 

class HardwareInterface {
public:
	virtual void sendData(char *data, int size) = 0;
	virtual ~HardwareInterface() {}
};

class Uart : public HardwareInterface {
public:
	virtual void sendData(char *data, int size)
	{
		std::cout << "Send data through uart: " << size << std::endl;
	}
};

class I2C : public HardwareInterface {
public:
	virtual void sendData(char *data, int size)
	{
		std::cout << "Send data through i2c: " << size << std::endl;
	}
};

class Processor {
public:
	virtual ~Processor() {}
	virtual void send(char *in_data, int size) = 0;
};

class AtmelCPU : public Processor {
public:
	AtmelCPU(HardwareInterface* interface) : m_interface(interface) {}
	void send(char *in_data, int size)
	{
		m_interface->sendData(in_data, size);
	}
private:
	HardwareInterface* m_interface;
};

int main()
{
	char *in = "Hello string";
	AtmelCPU cpu_1(new Uart);
	AtmelCPU cpu_2(new I2C);

	cpu_1.send(in , 2);
	cpu_2.send(in, 10);
	return 0;
}
