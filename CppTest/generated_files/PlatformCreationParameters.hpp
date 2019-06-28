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
	struct PlatformCreationParameters;
	struct ParameterValue;
	struct ParameterValue {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string id;
		ParameterValue() {}
		~ParameterValue() {}
	};
	struct PlatformCreationParameters {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::ParameterValue> ParameterValue;
		PlatformCreationParameters() {}
		~PlatformCreationParameters() {}
	};
}
void Materialise::PlatformCreationParameters::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "PlatformCreationParameters");
	for(int i = 0;i < ParameterValue.size();i++)
	{
		ParameterValue[i].Write(s); 
	}
}
bool Materialise::PlatformCreationParameters::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "PlatformCreationParameters");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::ParameterValue __t;
		if (__t.Read(s) == false)
			break;
		ParameterValue.push_back(__t);
	}
	return true;
}
void Materialise::ParameterValue::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "ParameterValue");
	s.WriteAttr("id", id.c_str());
}
bool Materialise::ParameterValue::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "ParameterValue");
	if (scope.exist() == false)
		return false;
	id = s.ReadAttrStr("id");
	return true;
}
