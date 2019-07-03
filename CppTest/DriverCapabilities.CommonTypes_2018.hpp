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
	const std::string schema_generated_files2_DriverCapabilities.CommonTypes_2018_namespace = "http://schemas.materialise.com/BuildProcessor/2018";
	enum class DriverIssueSeverity {
		Information,
		Warning,
		Critical,
	};

	enum class DriverIssueId {
		Licensing,
		Configuration,
		Other,
	};

	DriverIssueSeverity ConvertStringToDriverIssueSeverity(std::string str) {
		if (str == "Information") return DriverIssueSeverity::Information;
		if (str == "Warning") return DriverIssueSeverity::Warning;
		if (str == "Critical") return DriverIssueSeverity::Critical;
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertDriverIssueSeverityToString(DriverIssueSeverity e) {
		if (e == DriverIssueSeverity::Information) return "Information";
		if (e == DriverIssueSeverity::Warning) return "Warning";
		if (e == DriverIssueSeverity::Critical) return "Critical";
		throw std::exception("Can't convert enum value to string");
	}

	DriverIssueId ConvertStringToDriverIssueId(std::string str) {
		if (str == "Licensing") return DriverIssueId::Licensing;
		if (str == "Configuration") return DriverIssueId::Configuration;
		if (str == "Other") return DriverIssueId::Other;
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertDriverIssueIdToString(DriverIssueId e) {
		if (e == DriverIssueId::Licensing) return "Licensing";
		if (e == DriverIssueId::Configuration) return "Configuration";
		if (e == DriverIssueId::Other) return "Other";
		throw std::exception("Can't convert enum value to string");
	}

	struct DriverIssue;
	struct DriverIssues;
	struct Capability;
	struct Capabilities;
	struct Capability {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string Id;
		std::optional<std::string> Value;
		Capability() {}
		~Capability() {}
	};
	struct Capabilities {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string Id;
		std::vector<Materialise::Capability> Capability;
		std::vector<Materialise::Capabilities> __Capabilities;
		Capabilities() {}
		~Capabilities() {}
	};
	struct DriverIssue {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		Materialise::DriverIssueId Id;
		std::string Title;
		std::optional<std::string> Description;
		Materialise::DriverIssueSeverity Severity;
		DriverIssue() {}
		~DriverIssue() {}
	};
	struct DriverIssues {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::DriverIssue> DriverIssue;
		DriverIssues() {}
		~DriverIssues() {}
	};
}
void Materialise::DriverIssue::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Id", Materialise::ConvertDriverIssueIdToString(Id).c_str());
	s.WriteAttr("Title", Title.c_str());
	if (Description.has_value())
		s.WriteAttr("Description", Description.value().c_str());
	s.WriteAttr("Severity", Materialise::ConvertDriverIssueSeverityToString(Severity).c_str());
}
bool Materialise::DriverIssue::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	std::string __tmp_var;
	if (s.ReadAttrStr("Id", __tmp_var)) 
		Id = Materialise::ConvertStringToDriverIssueId(__tmp_var);
	s.ReadAttrStr("Title", Title);
	std::string* __Description = new std::string();
	if (s.ReadAttrStr("Description", *__Description))
		Description = std::optional<std::reference_wrapper<std::string>> { *__Description };
	if (s.ReadAttrStr("Severity", __tmp_var)) 
		Severity = Materialise::ConvertStringToDriverIssueSeverity(__tmp_var);
	return true;
}
void Materialise::DriverIssues::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < DriverIssue.size();i++)
	{
		DriverIssue[i].Write(s, "DriverIssue"); 
	}
}
bool Materialise::DriverIssues::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::DriverIssue __t;
		if (__t.Read(s, "DriverIssue") == false)
			break;
		DriverIssue.push_back(__t);
	}
	return true;
}
void Materialise::Capability::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Id", Id.c_str());
	if (Value.has_value())
		s.WriteAttr("Value", Value.value().c_str());
}
bool Materialise::Capability::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("Id", Id);
	std::string* __Value = new std::string();
	if (s.ReadAttrStr("Value", *__Value))
		Value = std::optional<std::reference_wrapper<std::string>> { *__Value };
	return true;
}
void Materialise::Capabilities::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Id", Id.c_str());
	for(int i = 0;i < Capability.size();i++)
	{
		Capability[i].Write(s, "Capability"); 
	}
	for(int i = 0;i < __Capabilities.size();i++)
	{
		__Capabilities[i].Write(s, "Capabilities"); 
	}
}
bool Materialise::Capabilities::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("Id", Id);
	while (true) { 
		Materialise::Capability __t;
		if (__t.Read(s, "Capability") == false)
			break;
		Capability.push_back(__t);
	}
	while (true) { 
		Materialise::Capabilities __t;
		if (__t.Read(s, "Capabilities") == false)
			break;
		__Capabilities.push_back(__t);
	}
	return true;
}
