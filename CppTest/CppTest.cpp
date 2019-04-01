// CppTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "test.h"



//------------------- Generated code begin--------------//

//------------------- Generated code end--------------//

int main()
{
	PugiXmlSerializerReader s;
	s.Load("text.xml");
	Test::shiporder c;
	c.Read(s);
	int a;
	std::cin >> a;
	/*Test::shiporder c;
	c.orderid = "falshjje";
	c.orderperson = "Alex";
	c.shipto.address = "asd";
	c.shipto.country = "Ukraine";
	c.shipto.name = "asdaaa";
	Test::item i;
	i.price = 200;
	i.note = "asd";
	c.item.push_back(i);
	c.Write(s);*/

	//s.SaveToFile("text.xml");

	return 0;
}
