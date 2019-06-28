#pragma once
// Copyright 2008, Microsoft Corporation and 2019 Alex Mytnyk
// Sample Code - Use restricted to terms of use defined in the accompanying license agreement (EULA.doc)
//--------------------------------------------------------------
#include <iostream>
#include <string>
#include <ctime>
#include "Serializers.hpp"
#include <optional>
namespace Materialise {
	struct Tags;
	struct Tag;
	struct Tag {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string name;
		std::string description;
		Tag() {}
		~Tag() {}
	};
	struct Tags {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::Tag> Tag;
		Tags() {}
		~Tags() {}
	};
}
void Materialise::Tags::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Tags");
	for(int i = 0;i < Tag.size();i++)
	{
		Tag[i].Write(s); 
	}
}
bool Materialise::Tags::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Tags");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Tag __t;
		if (__t.Read(s) == false)
			break;
		Tag.push_back(__t);
	}
	return true;
}
void Materialise::Tag::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Tag");
	s.WriteAttr("name", name.c_str());
	s.WriteAttr("description", description.c_str());
}
bool Materialise::Tag::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Tag");
	if (scope.exist() == false)
		return false;
	name = s.ReadAttrStr("name");
	description = s.ReadAttrStr("description");
	return true;
}
