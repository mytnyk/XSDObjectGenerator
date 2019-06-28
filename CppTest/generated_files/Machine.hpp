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
	struct MachineCustomProperty;
	struct Machine;
	struct CustomProperties;
	struct MachineCustomProperty {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string VariableName;
		std::string VariableType;
		MachineCustomProperty() {}
		~MachineCustomProperty() {}
	};
	struct CustomProperties {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::MachineCustomProperty> Property;
		CustomProperties() {}
		~CustomProperties() {}
	};
	struct Machine {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Name;
		std::string Manufacturer;
		std::string RequiredLicenseName;
		std::optional<std::reference_wrapper<Materialise::CustomProperties>> CustomProperties;
		Machine() {}
		~Machine() {}
	};
}
void Materialise::MachineCustomProperty::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "MachineCustomProperty");
	s.WriteAttr("VariableName", VariableName.c_str());
	s.WriteAttr("VariableType", VariableType.c_str());
}
bool Materialise::MachineCustomProperty::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "MachineCustomProperty");
	if (scope.exist() == false)
		return false;
	VariableName = s.ReadAttrStr("VariableName");
	VariableType = s.ReadAttrStr("VariableType");
	return true;
}
void Materialise::Machine::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Machine");
	s.Write("Name", Name.c_str());
	s.Write("Manufacturer", Manufacturer.c_str());
	s.Write("RequiredLicenseName", RequiredLicenseName.c_str());
	CustomProperties.value().get().Write(s);
}
bool Materialise::Machine::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Machine");
	if (scope.exist() == false)
		return false;
	s.ReadStr("Name", Name);
	s.ReadStr("Manufacturer", Manufacturer);
	s.ReadStr("RequiredLicenseName", RequiredLicenseName);
	Materialise::CustomProperties* __CustomProperties = new Materialise::CustomProperties();
	__CustomProperties->Read(s);
	CustomProperties = std::optional<std::reference_wrapper<Materialise::CustomProperties>> { *__CustomProperties };
	return true;
}
void Materialise::CustomProperties::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "CustomProperties");
	for(int i = 0;i < Property.size();i++)
	{
		Property[i].Write(s); 
	}
}
bool Materialise::CustomProperties::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "CustomProperties");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::MachineCustomProperty __t;
		if (__t.Read(s) == false)
			break;
		Property.push_back(__t);
	}
	return true;
}
