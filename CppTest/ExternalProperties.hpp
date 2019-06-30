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
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string ID;
		std::vector<Materialise::PropertyElement> Property;
		Properties() {}
		~Properties() {}
	};
	struct ExternalPropertyFile {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::Properties> Properties;
		ExternalPropertyFile() {}
		~ExternalPropertyFile() {}
	};
	struct PropertyElement {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string Name;
		Materialise::PropertyType Type;
		std::vector<Materialise::PropertyElement> Property;
		PropertyElement() {}
		~PropertyElement() {}
	};
}
void Materialise::PropertyElement::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Name", Name.c_str());
	s.WriteAttr("Type", Materialise::ConvertPropertyTypeToString(Type).c_str());
	for(int i = 0;i < Property.size();i++)
	{
		Property[i].Write(s, "Property"); 
	}
}
bool Materialise::PropertyElement::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	std::string __tmp_var;
	s.ReadAttrStr("Name", Name);
	if (s.ReadAttrStr("Type", __tmp_var)) 
		Type = Materialise::ConvertStringToPropertyType(__tmp_var);
	while (true) { 
		Materialise::PropertyElement __t;
		if (__t.Read(s, "Property") == false)
			break;
		Property.push_back(__t);
	}
	return true;
}
void Materialise::ExternalPropertyFile::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < Properties.size();i++)
	{
		Properties[i].Write(s, "Properties"); 
	}
}
bool Materialise::ExternalPropertyFile::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Properties __t;
		if (__t.Read(s, "Properties") == false)
			break;
		Properties.push_back(__t);
	}
	return true;
}
void Materialise::Properties::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("ID", ID.c_str());
	for(int i = 0;i < Property.size();i++)
	{
		Property[i].Write(s, "Property"); 
	}
}
bool Materialise::Properties::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("ID", ID);
	while (true) { 
		Materialise::PropertyElement __t;
		if (__t.Read(s, "Property") == false)
			break;
		Property.push_back(__t);
	}
	return true;
}
