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

void write1() {
	PugiXmlSerializerWriter s;
	/*Materialise::BuildTicket bt;
	Materialise::CT_PropertyTemplateTree tree;
	Materialise::CT_PropertyTemplateNode node;
	node.Default = "Default string here";
	node.DisplayName = "Display name here";
	node.DisplayNameContainer = "Display name container here";
	node.List = "List here";
	node.Name = "Name here";
	node.ProfileList = "Profile list here";
	tree.PropertyNode.push_back(node);
	node.List = "List 2 here";
	node.PropertyNode.push_back(node);
	node.Name = "Name 1 here";
	node.PropertyNode.push_back(node);
	node.Name = "Name 4 here";
	tree.PropertyNode.push_back(node);
	bt.Defaults = tree;

	bt.Write(s, "BuildTicket");

	s.SetSchemaTargetNamespace(Materialise::schema_generated_files_test2_MtlsBuildTicket_2017_namespace);
	s.SaveToFile("simple_xml.xml");*/
}

void read1() {
	PugiXmlSerializerReader s;
	s.Load("simple_xml.xml");
	Materialise::BuildTicket bt;
	bt.Read(s, "BuildTicket");
	std::string ns = s.getSchemaTargetNamespace();
	return;
}

void write2() {
	PugiXmlSerializerWriter s;
	Materialise::DeviceState ds;

	ds.Log = std::make_unique<Materialise::Log>();// new Materialise::Log());
	ds.Log.value()->Entries = std::make_unique<Materialise::Entries>();//(entries);
	ds.Log.value()->Entries.value()->count = 23786238;

	Materialise::LogEntry le;
	le.source = "AAAAA";
	le.type = Materialise::LogEntryType::Information;
	ds.Log.value()->Entries.value()->Entry.push_back(std::move(le));


	Materialise::LogEntry le2;
	le2.source = "BB";
	le2.message = "Hi";
	le2.type = Materialise::LogEntryType::Warning;
	ds.Log.value()->Entries.value()->Entry.push_back(std::move(le2));

	Materialise::LogEntry le3;
	le3.source = "AAAAA";
	le3.message = "Hi2";
	le3.type = Materialise::LogEntryType::Error;
	ds.Log.value()->Entries.value()->Entry.push_back(std::move(le3));

	ds.Status.description = "AA";
	ds.Status.value = Materialise::DeviceStatusValue::ReadyToPrint;

	ds.Write(s, "DeviceState");

	s.SetSchemaTargetNamespace(Materialise::schema_generated_files_test2_DeviceState_namespace);
	s.SaveToFile("simple_xml.xml");
}

void read2() {
	PugiXmlSerializerReader s;
	s.Load("simple_xml.xml");
	Materialise::DeviceState bt;
	bt.Read(s, "DeviceState");
	auto g = bt.Log.value().get();
	auto jj = bt.Log.value()->Entries.value().get();
	std::string ns = s.getSchemaTargetNamespace();
	return;
}

int main()
{
	write2();
	read2();
	
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
