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
	const std::string schema_CppTest_PlatformCreationParameters_namespace = "http://www.materialise.com/BuildProcessor/2014";
	struct PlatformCreationParameters;
	struct ParameterValue;
	struct ParameterValue {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		ParameterValue(const ParameterValue&) = delete;
		ParameterValue& operator=(ParameterValue&&) = delete;
		ParameterValue& operator=(ParameterValue&) = delete;
		ParameterValue(ParameterValue&&) noexcept;
		ParameterValue() = default;
		~ParameterValue() = default;
		std::string id;
	};
	struct PlatformCreationParameters {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		PlatformCreationParameters(const PlatformCreationParameters&) = delete;
		PlatformCreationParameters& operator=(PlatformCreationParameters&&) = delete;
		PlatformCreationParameters& operator=(PlatformCreationParameters&) = delete;
		PlatformCreationParameters(PlatformCreationParameters&&) noexcept;
		PlatformCreationParameters() = default;
		~PlatformCreationParameters() = default;
		std::vector<ParameterValue> ParameterValue;
	};
}
Materialise::PlatformCreationParameters::PlatformCreationParameters(Materialise::PlatformCreationParameters &&___PlatformCreationParameters) noexcept
	: ParameterValue(std::move(___PlatformCreationParameters.ParameterValue))
{ }
void Materialise::PlatformCreationParameters::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : ParameterValue)
	{
		element.Write(s, "ParameterValue"); 
	}
}
bool Materialise::PlatformCreationParameters::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::ParameterValue __t;
		if (!__t.Read(s, "ParameterValue"))
			break;
		ParameterValue.push_back(std::move(__t));
	}
	return true;
}
Materialise::ParameterValue::ParameterValue(Materialise::ParameterValue &&___ParameterValue) noexcept
	: id(std::move(___ParameterValue.id))
{ }
void Materialise::ParameterValue::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id.c_str());
}
bool Materialise::ParameterValue::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("id", id);
	return true;
}
