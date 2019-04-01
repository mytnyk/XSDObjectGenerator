#pragma once
// Copyright 2008, Microsoft Corporation and 2019 Alex Mytnyk
// Sample Code - Use restricted to terms of use defined in the accompanying license agreement (EULA.doc)
//--------------------------------------------------------------
#include <iostream>
#include <string>
#include <ctime>
#include "Serializers.hpp"
#include <optional>
#pragma once
// Copyright 2008, Microsoft Corporation and 2019 Alex Mytnyk
// Sample Code - Use restricted to terms of use defined in the accompanying license agreement (EULA.doc)
//--------------------------------------------------------------
#include <iostream>
#include <string>
#include <ctime>
namespace Test {
	struct shiporder;
	struct shipto;
	struct item;
	struct item {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string title;
		std::string note;
		std::string quantity;
		int price;
		item() {
			price = 0;
		}
		~item() {}
	};
	struct shipto {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string name;
		std::string address;
		std::string city;
		std::string country;
		shipto() {
		}
		~shipto() {}
	};
	struct shiporder {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string orderid;
		std::string orderperson;
		Test::shipto shipto;
		std::vector<Test::item> item;
		shiporder() {
		}
		~shiporder() {}
	};
}
void Test::shiporder::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "shiporder");
	s.WriteAttr("orderid", orderid.c_str());
	s.Write("orderperson", orderperson.c_str());
	shipto.Write(s);
	for (int i = 0; i < item.size(); i++)
	{
		item[i].Write(s);
	}
}
bool Test::shiporder::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "shiporder");
	if (scope.exist() == false)
		return false;
	orderid = s.ReadAttrStr("orderid");
	s.ReadStr("orderperson", orderperson);
	shipto.Read(s);
	while (true) {
		Test::item __t;
		if (__t.Read(s) == false)
			break;
		item.push_back(__t);
	}
	return true;
}
void Test::shipto::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "shipto");
	s.Write("name", name.c_str());
	s.Write("address", address.c_str());
	s.Write("city", city.c_str());
	s.Write("country", country.c_str());
}
bool Test::shipto::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "shipto");
	if (scope.exist() == false)
		return false;
	s.ReadStr("name", name);
	s.ReadStr("address", address);
	s.ReadStr("city", city);
	s.ReadStr("country", country);
	return true;
}
void Test::item::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "item");
	s.Write("title", title.c_str());
	s.Write("note", note.c_str());
	s.Write("quantity", quantity.c_str());
	s.Write("price", price);
}
bool Test::item::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "item");
	if (scope.exist() == false)
		return false;
	s.ReadStr("title", title);
	s.ReadStr("note", note);
	s.ReadStr("quantity", quantity);
	s.ReadInt("price", price);
	return true;
}
