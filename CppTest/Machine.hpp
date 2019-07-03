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
	const std::string schema_generated_files2_Machine_namespace = "";
	struct MachineCustomProperty;
	struct Machine;
	struct CustomProperties;
	struct MachineCustomProperty {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string VariableName;
		std::string VariableType;
		MachineCustomProperty() {}
		~MachineCustomProperty() {}
	};
	struct CustomProperties {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::MachineCustomProperty> Property;
		CustomProperties() {}
		~CustomProperties() {}
	};
	struct Machine {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string Name;
		std::string Manufacturer;
		std::string RequiredLicenseName;
		std::optional<std::reference_wrapper<Materialise::CustomProperties>> CustomProperties;
		Machine() {}
		~Machine() {}
	};
}
void Materialise::MachineCustomProperty::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("VariableName", VariableName.c_str());
	s.WriteAttr("VariableType", VariableType.c_str());
}
bool Materialise::MachineCustomProperty::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("VariableName", VariableName);
	s.ReadAttrStr("VariableType", VariableType);
	return true;
}
void Materialise::Machine::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.Write("Name", Name.c_str());
	s.Write("Manufacturer", Manufacturer.c_str());
	s.Write("RequiredLicenseName", RequiredLicenseName.c_str());
	if (CustomProperties.has_value())
		CustomProperties.value().get().Write(s, "CustomProperties");
}
bool Materialise::Machine::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadStr("Name", Name);
	s.ReadStr("Manufacturer", Manufacturer);
	s.ReadStr("RequiredLicenseName", RequiredLicenseName);
	Materialise::CustomProperties* __CustomProperties = new Materialise::CustomProperties();
	__CustomProperties->Read(s, "CustomProperties");
	CustomProperties = std::optional<std::reference_wrapper<Materialise::CustomProperties>> { *__CustomProperties };
	return true;
}
void Materialise::CustomProperties::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < Property.size();i++)
	{
		Property[i].Write(s, "Property"); 
	}
}
bool Materialise::CustomProperties::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::MachineCustomProperty __t;
		if (__t.Read(s, "Property") == false)
			break;
		Property.push_back(__t);
	}
	return true;
}
