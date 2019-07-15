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
	const std::string schema_generated_files_PlatformInformation_namespace = "http://www.materialise.com/BuildProcessor/2014";
	struct PlatformInformation;
	struct Materials;
	struct Material;
	struct Parameters;
	struct Choice;
	struct Item;
	struct Choice2;
	struct Choice2Item;
	struct Choice2Item {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Choice2Item(const Choice2Item&) = delete;
		Choice2Item& operator=(Choice2Item&&) = delete;
		Choice2Item& operator=(Choice2Item&) = delete;
		Choice2Item(Choice2Item&&) noexcept;
		Choice2Item() = default;
		~Choice2Item() = default;
		std::string id;
		std::string name;
		std::optional<bool> isDefault;
	};
	struct Choice2 {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Choice2(const Choice2&) = delete;
		Choice2& operator=(Choice2&&) = delete;
		Choice2& operator=(Choice2&) = delete;
		Choice2(Choice2&&) noexcept;
		Choice2() = default;
		~Choice2() = default;
		std::string id;
		std::string name;
		std::optional<bool> isRequired;
		std::vector<Choice2Item> Item;
	};
	struct Item {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Item(const Item&) = delete;
		Item& operator=(Item&&) = delete;
		Item& operator=(Item&) = delete;
		Item(Item&&) noexcept;
		Item() = default;
		~Item() = default;
		std::string id;
		std::string name;
		std::optional<bool> isDefault;
	};
	struct Choice {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Choice(const Choice&) = delete;
		Choice& operator=(Choice&&) = delete;
		Choice& operator=(Choice&) = delete;
		Choice(Choice&&) noexcept;
		Choice() = default;
		~Choice() = default;
		std::string id;
		std::string name;
		std::optional<bool> isRequired;
		std::vector<Item> Item;
	};
	struct Parameters {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Parameters(const Parameters&) = delete;
		Parameters& operator=(Parameters&&) = delete;
		Parameters& operator=(Parameters&) = delete;
		Parameters(Parameters&&) noexcept;
		Parameters() = default;
		~Parameters() = default;
		std::vector<Choice> Choice;
		std::vector<Choice2> Choice2;
	};
	struct Material {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Material(const Material&) = delete;
		Material& operator=(Material&&) = delete;
		Material& operator=(Material&) = delete;
		Material(Material&&) noexcept;
		Material() = default;
		~Material() = default;
		std::string name;
	};
	struct Materials {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Materials(const Materials&) = delete;
		Materials& operator=(Materials&&) = delete;
		Materials& operator=(Materials&) = delete;
		Materials(Materials&&) noexcept;
		Materials() = default;
		~Materials() = default;
		std::vector<Material> Material;
	};
	struct PlatformInformation {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		PlatformInformation(const PlatformInformation&) = delete;
		PlatformInformation& operator=(PlatformInformation&&) = delete;
		PlatformInformation& operator=(PlatformInformation&) = delete;
		PlatformInformation(PlatformInformation&&) noexcept;
		PlatformInformation() = default;
		~PlatformInformation() = default;
		std::string Name;
		std::optional<std::string> Comment;
		std::optional<std::unique_ptr<Materials>> Materials;
		std::optional<std::unique_ptr<Parameters>> Parameters;
	};
}
Materialise::PlatformInformation::PlatformInformation(Materialise::PlatformInformation &&___PlatformInformation) noexcept
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
	std::string __Comment;
	if (s.ReadStr("Comment", __Comment))
		Comment = std::make_optional(std::move(__Comment));
	std::unique_ptr<Materialise::Materials> __Materials = std::make_unique<Materialise::Materials>();
	if (__Materials->Read(s, "Materials"))
		Materials = std::make_optional(std::move(__Materials));
	std::unique_ptr<Materialise::Parameters> __Parameters = std::make_unique<Materialise::Parameters>();
	if (__Parameters->Read(s, "Parameters"))
		Parameters = std::make_optional(std::move(__Parameters));
	return true;
}
Materialise::Materials::Materials(Materialise::Materials &&___Materials) noexcept
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
Materialise::Material::Material(Materialise::Material &&___Material) noexcept
	: name(___Material.name)
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
Materialise::Parameters::Parameters(Materialise::Parameters &&___Parameters) noexcept
	: Choice(std::move(___Parameters.Choice))
	, Choice2(std::move(___Parameters.Choice2))
{ }
void Materialise::Parameters::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Choice)
	{
		element.Write(s, "Choice"); 
	}
	for(auto&& element : Choice2)
	{
		element.Write(s, "Choice2"); 
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
	while (true) { 
		Materialise::Choice2 __t;
		if (!__t.Read(s, "Choice2"))
			break;
		Choice2.push_back(std::move(__t));
	}
	return true;
}
Materialise::Choice::Choice(Materialise::Choice &&___Choice) noexcept
	: id(___Choice.id)
	, name(___Choice.name)
	, isRequired(___Choice.isRequired)
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
Materialise::Item::Item(Materialise::Item &&___Item) noexcept
	: id(___Item.id)
	, name(___Item.name)
	, isDefault(___Item.isDefault)
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
Materialise::Choice2::Choice2(Materialise::Choice2 &&___Choice2) noexcept
	: id(___Choice2.id)
	, name(___Choice2.name)
	, isRequired(___Choice2.isRequired)
	, Item(std::move(___Choice2.Item))
{ }
void Materialise::Choice2::Write(IXmlSerializerWriter& s, const std::string& __name__) {
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
bool Materialise::Choice2::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("id", id);
	s.ReadAttrStr("name", name);
	bool __isRequired;
	if (s.ReadAttrBool("isRequired", __isRequired))
		isRequired = std::optional<bool> { __isRequired };
	while (true) { 
		Materialise::Choice2Item __t;
		if (!__t.Read(s, "Item"))
			break;
		Item.push_back(std::move(__t));
	}
	return true;
}
Materialise::Choice2Item::Choice2Item(Materialise::Choice2Item &&___Choice2Item) noexcept
	: id(___Choice2Item.id)
	, name(___Choice2Item.name)
	, isDefault(___Choice2Item.isDefault)
{ }
void Materialise::Choice2Item::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id.c_str());
	s.WriteAttr("name", name.c_str());
	if (isDefault.has_value())
		s.WriteAttr("isDefault", isDefault.value());
}
bool Materialise::Choice2Item::Read(IXmlSerializerReader& s, const std::string& __name__) {
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
