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
	const std::string schema_generated_files3_Documentation_namespace = "";
	struct Links;
	struct Link;
	struct Documentation;
	struct Documentation {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<std::reference_wrapper<Materialise::Links>> Links;
		Documentation() {}
		~Documentation() {}
	};
	struct Link {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string Name;
		std::string Description;
		std::string LinkToFile;
		Link() {}
		~Link() {}
	};
	struct Links {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::Link> Link;
		Links() {}
		~Links() {}
	};
}
void Materialise::Links::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < Link.size();i++)
	{
		Link[i].Write(s, "Link"); 
	}
}
bool Materialise::Links::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Link __t;
		if (__t.Read(s, "Link") == false)
			break;
		Link.push_back(__t);
	}
	return true;
}
void Materialise::Link::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.Write("Name", Name.c_str());
	s.Write("Description", Description.c_str());
	s.Write("LinkToFile", LinkToFile.c_str());
}
bool Materialise::Link::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadStr("Name", Name);
	s.ReadStr("Description", Description);
	s.ReadStr("LinkToFile", LinkToFile);
	return true;
}
void Materialise::Documentation::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (Links.has_value())
		Links.value().get().Write(s, "Links");
}
bool Materialise::Documentation::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	Materialise::Links* __Links = new Materialise::Links();
	__Links->Read(s, "Links");
	Links = std::optional<std::reference_wrapper<Materialise::Links>> { *__Links };
	return true;
}
