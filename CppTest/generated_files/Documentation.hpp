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
	struct Links;
	struct Link;
	struct Documentation;
	struct Documentation {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::reference_wrapper<Materialise::Links>> Links;
		Documentation() {}
		~Documentation() {}
	};
	struct Link {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Name;
		std::string Description;
		std::string LinkToFile;
		Link() {}
		~Link() {}
	};
	struct Links {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::Link> Link;
		Links() {}
		~Links() {}
	};
}
void Materialise::Links::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Links");
	for(int i = 0;i < Link.size();i++)
	{
		Link[i].Write(s); 
	}
}
bool Materialise::Links::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Links");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Link __t;
		if (__t.Read(s) == false)
			break;
		Link.push_back(__t);
	}
	return true;
}
void Materialise::Link::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Link");
	s.Write("Name", Name.c_str());
	s.Write("Description", Description.c_str());
	s.Write("LinkToFile", LinkToFile.c_str());
}
bool Materialise::Link::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Link");
	if (scope.exist() == false)
		return false;
	s.ReadStr("Name", Name);
	s.ReadStr("Description", Description);
	s.ReadStr("LinkToFile", LinkToFile);
	return true;
}
void Materialise::Documentation::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Documentation");
	Links.value().get().Write(s);
}
bool Materialise::Documentation::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Documentation");
	if (scope.exist() == false)
		return false;
	Materialise::Links* __Links = new Materialise::Links();
	__Links->Read(s);
	Links = std::optional<std::reference_wrapper<Materialise::Links>> { *__Links };
	return true;
}
