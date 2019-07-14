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
	const std::string schema_generated_files_test2_Machine_namespace = "";
	struct MachineCustomProperty;
	struct Machine;
	struct CustomProperties;
	struct MachineCustomProperty {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		MachineCustomProperty(MachineCustomProperty&&);
	MachineCustomProperty(){ }
		std::string VariableName;
		std::string VariableType;
	};
	struct CustomProperties {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CustomProperties(CustomProperties&&);
	CustomProperties(){ }
		std::vector<MachineCustomProperty> Property;
	};
	struct Machine {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Machine(Machine&&);
	Machine(){ }
		std::string Name;
		std::string Manufacturer;
		std::string RequiredLicenseName;
		std::optional<std::unique_ptr<CustomProperties>> CustomProperties;
	};
}
Materialise::MachineCustomProperty::MachineCustomProperty(Materialise::MachineCustomProperty &&___MachineCustomProperty)
	: VariableName(std::move(___MachineCustomProperty.VariableName))
	, VariableType(std::move(___MachineCustomProperty.VariableType))
{ }
void Materialise::MachineCustomProperty::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("VariableName", VariableName.c_str());
	s.WriteAttr("VariableType", VariableType.c_str());
}
bool Materialise::MachineCustomProperty::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("VariableName", VariableName);
	s.ReadAttrStr("VariableType", VariableType);
	return true;
}
Materialise::Machine::Machine(Materialise::Machine &&___Machine)
	: Name(std::move(___Machine.Name))
	, Manufacturer(std::move(___Machine.Manufacturer))
	, RequiredLicenseName(std::move(___Machine.RequiredLicenseName))
	, CustomProperties(std::move(___Machine.CustomProperties))
{ }
void Materialise::Machine::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.Write("Name", Name.c_str());
	s.Write("Manufacturer", Manufacturer.c_str());
	s.Write("RequiredLicenseName", RequiredLicenseName.c_str());
	if (CustomProperties.has_value())
		CustomProperties.value().get()->Write(s, "CustomProperties");
}
bool Materialise::Machine::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadStr("Name", Name);
	s.ReadStr("Manufacturer", Manufacturer);
	s.ReadStr("RequiredLicenseName", RequiredLicenseName);
	Materialise::CustomProperties* __CustomProperties = new Materialise::CustomProperties();
	if (__CustomProperties->Read(s, "CustomProperties"))
		CustomProperties = std::optional<std::unique_ptr<Materialise::CustomProperties>> { __CustomProperties };
	return true;
}
Materialise::CustomProperties::CustomProperties(Materialise::CustomProperties &&___CustomProperties)
	: Property(std::move(___CustomProperties.Property))
{ }
void Materialise::CustomProperties::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Property)
	{
		element.Write(s, "Property"); 
	}
}
bool Materialise::CustomProperties::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::MachineCustomProperty __t;
		if (!__t.Read(s, "Property"))
			break;
		Property.push_back(std::move(__t));
	}
	return true;
}
