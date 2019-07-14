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
	const std::string schema_generated_files_test2_ExternalProperties_namespace = "";
	enum class PropertyType {
		_bool,
		integer,
		_unsigned,
		_double,
		_float,
		_string,
		_long,
		Properties,
		PositionMatrix,
		ExternalProperties,
		SubProperties,
		FileContent,
	};

	PropertyType ConvertStringToPropertyType(std::string str) {
		if (str == "bool") return PropertyType::_bool;
		if (str == "integer") return PropertyType::integer;
		if (str == "unsigned") return PropertyType::_unsigned;
		if (str == "double") return PropertyType::_double;
		if (str == "float") return PropertyType::_float;
		if (str == "string") return PropertyType::_string;
		if (str == "long") return PropertyType::_long;
		if (str == "Properties") return PropertyType::Properties;
		if (str == "PositionMatrix") return PropertyType::PositionMatrix;
		if (str == "ExternalProperties") return PropertyType::ExternalProperties;
		if (str == "SubProperties") return PropertyType::SubProperties;
		if (str == "FileContent") return PropertyType::FileContent;
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertPropertyTypeToString(PropertyType e) {
		if (e == PropertyType::_bool) return "bool";
		if (e == PropertyType::integer) return "integer";
		if (e == PropertyType::_unsigned) return "unsigned";
		if (e == PropertyType::_double) return "double";
		if (e == PropertyType::_float) return "float";
		if (e == PropertyType::_string) return "string";
		if (e == PropertyType::_long) return "long";
		if (e == PropertyType::Properties) return "Properties";
		if (e == PropertyType::PositionMatrix) return "PositionMatrix";
		if (e == PropertyType::ExternalProperties) return "ExternalProperties";
		if (e == PropertyType::SubProperties) return "SubProperties";
		if (e == PropertyType::FileContent) return "FileContent";
		throw std::exception("Can't convert enum value to string");
	}

	struct PropertyElement;
	struct ExternalPropertyFile;
	struct Properties;
	struct Properties {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Properties(Properties&&);
	Properties(){ }
		std::string ID;
		std::vector<PropertyElement> Property;
	};
	struct ExternalPropertyFile {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		ExternalPropertyFile(ExternalPropertyFile&&);
	ExternalPropertyFile(){ }
		std::vector<Properties> Properties;
	};
	struct PropertyElement {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		PropertyElement(PropertyElement&&);
	PropertyElement(){ }
		std::string Name;
		Materialise::PropertyType Type;
		std::vector<PropertyElement> Property;
	};
}
Materialise::PropertyElement::PropertyElement(Materialise::PropertyElement &&___PropertyElement)
	: Name(std::move(___PropertyElement.Name))
	, Type(std::move(___PropertyElement.Type))
	, Property(std::move(___PropertyElement.Property))
{ }
void Materialise::PropertyElement::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Name", Name.c_str());
	s.WriteAttr("Type", Materialise::ConvertPropertyTypeToString(Type).c_str());
	for(auto&& element : Property)
	{
		element.Write(s, "Property"); 
	}
}
bool Materialise::PropertyElement::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	s.ReadAttrStr("Name", Name);
	if (s.ReadAttrStr("Type", __tmp_var)) 
		Type = Materialise::ConvertStringToPropertyType(__tmp_var);
	while (true) { 
		Materialise::PropertyElement __t;
		if (!__t.Read(s, "Property"))
			break;
		Property.push_back(std::move(__t));
	}
	return true;
}
Materialise::ExternalPropertyFile::ExternalPropertyFile(Materialise::ExternalPropertyFile &&___ExternalPropertyFile)
	: Properties(std::move(___ExternalPropertyFile.Properties))
{ }
void Materialise::ExternalPropertyFile::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Properties)
	{
		element.Write(s, "Properties"); 
	}
}
bool Materialise::ExternalPropertyFile::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::Properties __t;
		if (!__t.Read(s, "Properties"))
			break;
		Properties.push_back(std::move(__t));
	}
	return true;
}
Materialise::Properties::Properties(Materialise::Properties &&___Properties)
	: ID(std::move(___Properties.ID))
	, Property(std::move(___Properties.Property))
{ }
void Materialise::Properties::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("ID", ID.c_str());
	for(auto&& element : Property)
	{
		element.Write(s, "Property"); 
	}
}
bool Materialise::Properties::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("ID", ID);
	while (true) { 
		Materialise::PropertyElement __t;
		if (!__t.Read(s, "Property"))
			break;
		Property.push_back(std::move(__t));
	}
	return true;
}
