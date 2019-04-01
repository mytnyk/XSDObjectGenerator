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
		std::optional<std::string> note{ "" };
		std::string quantity;
		std::optional<int> price{ 0 };
		item() {}
		~item() {}
	};
	struct shipto {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string name;
		std::string address;
		std::string city;
		std::optional<std::string> country{ "" };
		shipto() {}
		~shipto() {}
	};
	struct shiporder {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::string> orderid{ "" };
		std::string orderperson;
		std::optional<std::reference_wrapper<Test::shipto>> shipto;
		std::vector<Test::item> item;
		shiporder() {}
		~shiporder() {}
	};
}
void Test::shiporder::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "shiporder");
	s.WriteAttr("orderid", orderid.value().c_str());
	s.Write("orderperson", orderperson.c_str());
	shipto.value().get().Write(s);
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
	Test::shipto* __shipto = new Test::shipto();
	__shipto->Read(s);
	shipto = std::optional<std::reference_wrapper<Test::shipto>>{ *__shipto };
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
	s.Write("country", country.value().c_str());
}
bool Test::shipto::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "shipto");
	if (scope.exist() == false)
		return false;
	s.ReadStr("name", name);
	s.ReadStr("address", address);
	s.ReadStr("city", city);
	s.ReadStr("country", country.value());
	return true;
}
void Test::item::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "item");
	s.Write("title", title.c_str());
	s.Write("note", note.value().c_str());
	s.Write("quantity", quantity.c_str());
	s.Write("price", price.value());
}
bool Test::item::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "item");
	if (scope.exist() == false)
		return false;
	s.ReadStr("title", title);
	s.ReadStr("note", note.value());
	s.ReadStr("quantity", quantity);
	s.ReadInt("price", price.value());
	return true;
}
