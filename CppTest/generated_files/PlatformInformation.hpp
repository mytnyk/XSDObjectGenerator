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
	struct PlatformInformation;
	struct Materials;
	struct Material;
	struct Parameters;
	struct Choice;
	struct Item;
	struct Item {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string id;
		std::string name;
		std::optional<bool> isDefault;
		Item() {}
		~Item() {}
	};
	struct Choice {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string id;
		std::string name;
		std::optional<bool> isRequired;
		std::vector<Materialise::Item> Item;
		Choice() {}
		~Choice() {}
	};
	struct Parameters {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::Choice> Choice;
		Parameters() {}
		~Parameters() {}
	};
	struct Material {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string name;
		Material() {}
		~Material() {}
	};
	struct Materials {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::Material> Material;
		Materials() {}
		~Materials() {}
	};
	struct PlatformInformation {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Name;
		std::optional<std::string> Comment {""};
		std::optional<std::reference_wrapper<Materialise::Materials>> Materials;
		std::optional<std::reference_wrapper<Materialise::Parameters>> Parameters;
		PlatformInformation() {}
		~PlatformInformation() {}
	};
}
void Materialise::PlatformInformation::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "PlatformInformation");
	s.Write("Name", Name.c_str());
	s.Write("Comment", Comment.value().c_str());
	Materials.value().get().Write(s);
	Parameters.value().get().Write(s);
}
bool Materialise::PlatformInformation::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "PlatformInformation");
	if (scope.exist() == false)
		return false;
	s.ReadStr("Name", Name);
	s.ReadStr("Comment", Comment.value());
	Materialise::Materials* __Materials = new Materialise::Materials();
	__Materials->Read(s);
	Materials = std::optional<std::reference_wrapper<Materialise::Materials>> { *__Materials };
	Materialise::Parameters* __Parameters = new Materialise::Parameters();
	__Parameters->Read(s);
	Parameters = std::optional<std::reference_wrapper<Materialise::Parameters>> { *__Parameters };
	return true;
}
void Materialise::Materials::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Materials");
	for(int i = 0;i < Material.size();i++)
	{
		Material[i].Write(s); 
	}
}
bool Materialise::Materials::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Materials");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Material __t;
		if (__t.Read(s) == false)
			break;
		Material.push_back(__t);
	}
	return true;
}
void Materialise::Material::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Material");
	s.WriteAttr("name", name.c_str());
}
bool Materialise::Material::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Material");
	if (scope.exist() == false)
		return false;
	name = s.ReadAttrStr("name");
	return true;
}
void Materialise::Parameters::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Parameters");
	for(int i = 0;i < Choice.size();i++)
	{
		Choice[i].Write(s); 
	}
}
bool Materialise::Parameters::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Parameters");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Choice __t;
		if (__t.Read(s) == false)
			break;
		Choice.push_back(__t);
	}
	return true;
}
void Materialise::Choice::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Choice");
	s.WriteAttr("id", id.c_str());
	s.WriteAttr("name", name.c_str());
	s.WriteAttr("isRequired", isRequired.value());
	for(int i = 0;i < Item.size();i++)
	{
		Item[i].Write(s); 
	}
}
bool Materialise::Choice::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Choice");
	if (scope.exist() == false)
		return false;
	id = s.ReadAttrStr("id");
	name = s.ReadAttrStr("name");
	isRequired = s.ReadAttrBool("isRequired");
	while (true) { 
		Materialise::Item __t;
		if (__t.Read(s) == false)
			break;
		Item.push_back(__t);
	}
	return true;
}
void Materialise::Item::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Item");
	s.WriteAttr("id", id.c_str());
	s.WriteAttr("name", name.c_str());
	s.WriteAttr("isDefault", isDefault.value());
}
bool Materialise::Item::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Item");
	if (scope.exist() == false)
		return false;
	id = s.ReadAttrStr("id");
	name = s.ReadAttrStr("name");
	isDefault = s.ReadAttrBool("isDefault");
	return true;
}
