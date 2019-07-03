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
	const std::string schema_generated_files2_Tags_namespace = "urn:Print3D";
	struct Tags;
	struct Tag;
	struct Tag {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string name;
		std::string description;
		Tag() {}
		~Tag() {}
	};
	struct Tags {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::Tag> Tag;
		Tags() {}
		~Tags() {}
	};
}
void Materialise::Tags::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < Tag.size();i++)
	{
		Tag[i].Write(s, "Tag"); 
	}
}
bool Materialise::Tags::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Tag __t;
		if (__t.Read(s, "Tag") == false)
			break;
		Tag.push_back(__t);
	}
	return true;
}
void Materialise::Tag::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("name", name.c_str());
	s.WriteAttr("description", description.c_str());
}
bool Materialise::Tag::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("name", name);
	s.ReadAttrStr("description", description);
	return true;
}
