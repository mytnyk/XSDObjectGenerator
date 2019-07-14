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
	const std::string schema_generated_files_test2_PlatformInformation_namespace = "http://www.materialise.com/BuildProcessor/2014";
	struct PlatformInformation;
	struct Materials;
	struct Material;
	struct Parameters;
	struct Choice;
	struct Item;
	struct Item {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Item(Item&&);
	Item(){ }
		std::string id;
		std::string name;
		std::optional<bool> isDefault;
	};
	struct Choice {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Choice(Choice&&);
	Choice(){ }
		std::string id;
		std::string name;
		std::optional<bool> isRequired;
		std::vector<Item> Item;
	};
	struct Parameters {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Parameters(Parameters&&);
	Parameters(){ }
		std::vector<Choice> Choice;
	};
	struct Material {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Material(Material&&);
	Material(){ }
		std::string name;
	};
	struct Materials {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Materials(Materials&&);
	Materials(){ }
		std::vector<Material> Material;
	};
	struct PlatformInformation {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		PlatformInformation(PlatformInformation&&);
	PlatformInformation(){ }
		std::string Name;
		std::optional<std::string> Comment;
		std::optional<std::unique_ptr<Materials>> Materials;
		std::optional<std::unique_ptr<Parameters>> Parameters;
	};
}
Materialise::PlatformInformation::PlatformInformation(Materialise::PlatformInformation &&___PlatformInformation)
	: Name(std::move(___PlatformInformation.Name))
	, Comment(std::move(___PlatformInformation.Comment))
	, Materials(std::move(___PlatformInformation.Materials))
	, Parameters(std::move(___PlatformInformation.Parameters))
{ }
void Materialise::PlatformInformation::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.Write("Name", Name.c_str());
	if (Comment.has_value())
		s.Write("Comment", Comment.value().c_str());
	if (Materials.has_value())
		Materials.value().get()->Write(s, "Materials");
	if (Parameters.has_value())
		Parameters.value().get()->Write(s, "Parameters");
}
bool Materialise::PlatformInformation::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadStr("Name", Name);
	s.ReadStr("Comment", Comment.value());
	Materialise::Materials* __Materials = new Materialise::Materials();
	if (__Materials->Read(s, "Materials"))
		Materials = std::optional<std::unique_ptr<Materialise::Materials>> { __Materials };
	Materialise::Parameters* __Parameters = new Materialise::Parameters();
	if (__Parameters->Read(s, "Parameters"))
		Parameters = std::optional<std::unique_ptr<Materialise::Parameters>> { __Parameters };
	return true;
}
Materialise::Materials::Materials(Materialise::Materials &&___Materials)
	: Material(std::move(___Materials.Material))
{ }
void Materialise::Materials::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Material)
	{
		element.Write(s, "Material"); 
	}
}
bool Materialise::Materials::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::Material __t;
		if (!__t.Read(s, "Material"))
			break;
		Material.push_back(std::move(__t));
	}
	return true;
}
Materialise::Material::Material(Materialise::Material &&___Material)
	: name(std::move(___Material.name))
{ }
void Materialise::Material::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("name", name.c_str());
}
bool Materialise::Material::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("name", name);
	return true;
}
Materialise::Parameters::Parameters(Materialise::Parameters &&___Parameters)
	: Choice(std::move(___Parameters.Choice))
{ }
void Materialise::Parameters::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Choice)
	{
		element.Write(s, "Choice"); 
	}
}
bool Materialise::Parameters::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::Choice __t;
		if (!__t.Read(s, "Choice"))
			break;
		Choice.push_back(std::move(__t));
	}
	return true;
}
Materialise::Choice::Choice(Materialise::Choice &&___Choice)
	: id(std::move(___Choice.id))
	, name(std::move(___Choice.name))
	, isRequired(std::move(___Choice.isRequired))
	, Item(std::move(___Choice.Item))
{ }
void Materialise::Choice::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id.c_str());
	s.WriteAttr("name", name.c_str());
	if (isRequired.has_value())
		s.WriteAttr("isRequired", isRequired.value());
	for(auto&& element : Item)
	{
		element.Write(s, "Item"); 
	}
}
bool Materialise::Choice::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("id", id);
	s.ReadAttrStr("name", name);
	bool __isRequired;
	if (s.ReadAttrBool("isRequired", __isRequired))
		isRequired = std::optional<bool> { __isRequired };
	while (true) { 
		Materialise::Item __t;
		if (!__t.Read(s, "Item"))
			break;
		Item.push_back(std::move(__t));
	}
	return true;
}
Materialise::Item::Item(Materialise::Item &&___Item)
	: id(std::move(___Item.id))
	, name(std::move(___Item.name))
	, isDefault(std::move(___Item.isDefault))
{ }
void Materialise::Item::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id.c_str());
	s.WriteAttr("name", name.c_str());
	if (isDefault.has_value())
		s.WriteAttr("isDefault", isDefault.value());
}
bool Materialise::Item::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("id", id);
	s.ReadAttrStr("name", name);
	bool __isDefault;
	if (s.ReadAttrBool("isDefault", __isDefault))
		isDefault = std::optional<bool> { __isDefault };
	return true;
}
