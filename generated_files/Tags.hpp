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
	const std::string schema_generated_files_Tags_namespace = "urn:Print3D";
	struct Tags;
	struct Tag;
	struct Tag {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Tag(const Tag&) = delete;
		Tag& operator=(Tag&&) = delete;
		Tag& operator=(Tag&) = delete;
		Tag(Tag&&) noexcept;
		Tag() = default;
		~Tag() = default;
		std::string name;
		std::string description;
	};
	struct Tags {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Tags(const Tags&) = delete;
		Tags& operator=(Tags&&) = delete;
		Tags& operator=(Tags&) = delete;
		Tags(Tags&&) noexcept;
		Tags() = default;
		~Tags() = default;
		std::vector<Tag> Tag;
	};
}
Materialise::Tags::Tags(Materialise::Tags &&___Tags) noexcept
	: Tag(std::move(___Tags.Tag))
{ }
void Materialise::Tags::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Tag)
	{
		element.Write(s, "Tag"); 
	}
}
bool Materialise::Tags::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::Tag __t;
		if (!__t.Read(s, "Tag"))
			break;
		Tag.push_back(std::move(__t));
	}
	return true;
}
Materialise::Tag::Tag(Materialise::Tag &&___Tag) noexcept
	: name(___Tag.name)
	, description(___Tag.description)
{ }
void Materialise::Tag::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("name", name.c_str());
	s.WriteAttr("description", description.c_str());
}
bool Materialise::Tag::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("name", name);
	s.ReadAttrStr("description", description);
	return true;
}
