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
	node.List = "List 2 here";
	node.PropertyNode.push_back(node);
	node.Name = "Name 1 here";
	node.PropertyNode.push_back(node);
	node.Name = "Name 4 here";
	tree.PropertyNode.push_back(node);
	bt.Defaults = tree;

	bt.Write(s, "BuildTicket");

	s.SetSchemaTargetNamespace(Materialise::schema_generated_files3_MtlsBuildTicket_2017_namespace);
	s.SaveToFile("simple_xml.xml");
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
	Materialise::Log log;
	Materialise::Entries entries;
	entries.count = 11;
	Materialise::LogEntry le;
	le.source = "AAAAA";
	le.type = Materialise::LogEntryType::Information;
	entries.Entry.push_back(le);
	le.type = Materialise::LogEntryType::Warning;
	entries.Entry.push_back(le);
	Materialise::MeterValues mv;
	mv.count = 1111111;
	Materialise::_Value v;
	v.meter = "MMM";
	mv.Value.push_back(v);
	v.meter = "MMMeee";
	mv.Value.push_back(v);
	le.Meters = mv;
	entries.Entry.push_back(le);
	log.Entries = entries;
	ds.Log = log;
	Materialise::DeviceStatus dstat;
	dstat.description = "AA";
	dstat.value = Materialise::DeviceStatusValue::ReadyToPrint;
	ds.Status = dstat;


	ds.Write(s, "DeviceState");

	s.SetSchemaTargetNamespace(Materialise::schema_generated_files3_DeviceState_namespace);
	s.SaveToFile("simple_xml.xml");
}

void read2() {
	PugiXmlSerializerReader s;
	s.Load("simple_xml.xml");
	Materialise::DeviceState bt;
	bt.Read(s, "DeviceState");
	auto jj = bt.Log.value().get().Entries;
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
