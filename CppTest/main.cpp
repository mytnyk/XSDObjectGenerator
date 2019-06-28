// CppTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <pugixml.hpp>
#include "Serializers.hpp"
#include "MtlsBuildTicket_2017.hpp"
#include "DeviceState.hpp"


//------------------- Generated code begin--------------//

//------------------- Generated code end--------------//

int main()
{
	PugiXmlSerializerWriter s;
	Materialise::BuildTicket bt;
	Materialise::CT_PropertyTemplateTree tree;
	Materialise::CT_PropertyTemplateNode node;
	node.Default = "Default string here";
	node.DisplayName = "Display name here";
	node.DisplayNameContainer = "Display name container here";
	node.List = "List here";
	node.Name = "Name here";
	node.ProfileList = "Profile list here";
	tree.PropertyNode.push_back(node);
	tree.PropertyNode.push_back(node);
	bt.Defaults = tree;

	bt.Write(s, "BuildTicket");

	s.SaveToFile("simple_xml.xml");
	
	//Test::shiporder c;
	//c.Read(s);
	//int a;
	//std::cin >> a;
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
