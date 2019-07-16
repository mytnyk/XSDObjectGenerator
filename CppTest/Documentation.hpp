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
	const std::string schema_CppTest_Documentation_namespace = "";
	struct Links;
	struct Link;
	struct Documentation;
	struct Documentation {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Documentation(const Documentation&) = delete;
		Documentation& operator=(Documentation&&) = delete;
		Documentation& operator=(Documentation&) = delete;
		Documentation(Documentation&&) noexcept;
		Documentation() = default;
		~Documentation() = default;
		std::optional<std::unique_ptr<Links>> Links;
	};
	struct Link {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Link(const Link&) = delete;
		Link& operator=(Link&&) = delete;
		Link& operator=(Link&) = delete;
		Link(Link&&) noexcept;
		Link() = default;
		~Link() = default;
		std::string Name;
		std::string Description;
		std::string LinkToFile;
	};
	struct Links {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Links(const Links&) = delete;
		Links& operator=(Links&&) = delete;
		Links& operator=(Links&) = delete;
		Links(Links&&) noexcept;
		Links() = default;
		~Links() = default;
		std::vector<Link> Link;
	};
}
Materialise::Links::Links(Materialise::Links &&___Links) noexcept
	: Link(std::move(___Links.Link))
{ }
void Materialise::Links::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Link)
	{
		element.Write(s, "Link"); 
	}
}
bool Materialise::Links::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::Link __t;
		if (!__t.Read(s, "Link"))
			break;
		Link.push_back(std::move(__t));
	}
	return true;
}
Materialise::Link::Link(Materialise::Link &&___Link) noexcept
	: Name(std::move(___Link.Name))
	, Description(std::move(___Link.Description))
	, LinkToFile(std::move(___Link.LinkToFile))
{ }
void Materialise::Link::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.Write("Name", Name.c_str());
	s.Write("Description", Description.c_str());
	s.Write("LinkToFile", LinkToFile.c_str());
}
bool Materialise::Link::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadStr("Name", Name);
	s.ReadStr("Description", Description);
	s.ReadStr("LinkToFile", LinkToFile);
	return true;
}
Materialise::Documentation::Documentation(Materialise::Documentation &&___Documentation) noexcept
	: Links(std::move(___Documentation.Links))
{ }
void Materialise::Documentation::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (Links.has_value())
		Links.value().get()->Write(s, "Links");
}
bool Materialise::Documentation::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	Materialise::Links* __Links = new Materialise::Links();
	if (__Links->Read(s, "Links"))
		Links = std::optional<std::unique_ptr<Materialise::Links>> { __Links };
	return true;
}
