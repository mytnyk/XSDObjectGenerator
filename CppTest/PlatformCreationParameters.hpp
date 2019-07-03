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
	const std::string schema_generated_files2_PlatformCreationParameters_namespace = "http://www.materialise.com/BuildProcessor/2014";
	struct PlatformCreationParameters;
	struct ParameterValue;
	struct ParameterValue {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string id;
		ParameterValue() {}
		~ParameterValue() {}
	};
	struct PlatformCreationParameters {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::ParameterValue> ParameterValue;
		PlatformCreationParameters() {}
		~PlatformCreationParameters() {}
	};
}
void Materialise::PlatformCreationParameters::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < ParameterValue.size();i++)
	{
		ParameterValue[i].Write(s, "ParameterValue"); 
	}
}
bool Materialise::PlatformCreationParameters::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::ParameterValue __t;
		if (__t.Read(s, "ParameterValue") == false)
			break;
		ParameterValue.push_back(__t);
	}
	return true;
}
void Materialise::ParameterValue::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id.c_str());
}
bool Materialise::ParameterValue::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("id", id);
	return true;
}
