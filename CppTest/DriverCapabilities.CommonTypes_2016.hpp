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
	const std::string schema_generated_files_test2_DriverCapabilities.CommonTypes_2016_namespace = "http://schemas.materialise.com/BuildProcessor/2016";
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
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Capability(Capability&&);
	Capability(){ }
		std::string Id;
		std::optional<std::string> Value;
	};
	struct Capabilities {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Capabilities(Capabilities&&);
	Capabilities(){ }
		std::string Id;
		std::vector<Capability> Capability;
		std::vector<Capabilities> __Capabilities;
	};
	struct DriverIssue {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		DriverIssue(DriverIssue&&);
	DriverIssue(){ }
		Materialise::DriverIssueId Id;
		std::string Title;
		std::optional<std::string> Description;
		Materialise::DriverIssueSeverity Severity;
	};
	struct DriverIssues {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		DriverIssues(DriverIssues&&);
	DriverIssues(){ }
		std::vector<DriverIssue> DriverIssue;
	};
}
Materialise::DriverIssue::DriverIssue(Materialise::DriverIssue &&___DriverIssue)
	: Id(std::move(___DriverIssue.Id))
	, Title(std::move(___DriverIssue.Title))
	, Description(std::move(___DriverIssue.Description))
	, Severity(std::move(___DriverIssue.Severity))
{ }
void Materialise::DriverIssue::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Id", Materialise::ConvertDriverIssueIdToString(Id).c_str());
	s.WriteAttr("Title", Title.c_str());
	if (Description.has_value())
		s.WriteAttr("Description", Description.value().c_str());
	s.WriteAttr("Severity", Materialise::ConvertDriverIssueSeverityToString(Severity).c_str());
}
bool Materialise::DriverIssue::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	if (s.ReadAttrStr("Id", __tmp_var)) 
		Id = Materialise::ConvertStringToDriverIssueId(__tmp_var);
	s.ReadAttrStr("Title", Title);
	std::string __Description;
	if (s.ReadAttrStr("Description", __Description))
		Description = std::optional<std::string> { __Description };
	if (s.ReadAttrStr("Severity", __tmp_var)) 
		Severity = Materialise::ConvertStringToDriverIssueSeverity(__tmp_var);
	return true;
}
Materialise::DriverIssues::DriverIssues(Materialise::DriverIssues &&___DriverIssues)
	: DriverIssue(std::move(___DriverIssues.DriverIssue))
{ }
void Materialise::DriverIssues::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : DriverIssue)
	{
		element.Write(s, "DriverIssue"); 
	}
}
bool Materialise::DriverIssues::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::DriverIssue __t;
		if (!__t.Read(s, "DriverIssue"))
			break;
		DriverIssue.push_back(std::move(__t));
	}
	return true;
}
Materialise::Capability::Capability(Materialise::Capability &&___Capability)
	: Id(std::move(___Capability.Id))
	, Value(std::move(___Capability.Value))
{ }
void Materialise::Capability::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Id", Id.c_str());
	if (Value.has_value())
		s.WriteAttr("Value", Value.value().c_str());
}
bool Materialise::Capability::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("Id", Id);
	std::string __Value;
	if (s.ReadAttrStr("Value", __Value))
		Value = std::optional<std::string> { __Value };
	return true;
}
Materialise::Capabilities::Capabilities(Materialise::Capabilities &&___Capabilities)
	: Id(std::move(___Capabilities.Id))
	, Capability(std::move(___Capabilities.Capability))
	, __Capabilities(std::move(___Capabilities.__Capabilities))
{ }
void Materialise::Capabilities::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Id", Id.c_str());
	for(auto&& element : Capability)
	{
		element.Write(s, "Capability"); 
	}
	for(auto&& element : __Capabilities)
	{
		element.Write(s, "Capabilities"); 
	}
}
bool Materialise::Capabilities::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("Id", Id);
	while (true) { 
		Materialise::Capability __t;
		if (!__t.Read(s, "Capability"))
			break;
		Capability.push_back(std::move(__t));
	}
	while (true) { 
		Materialise::Capabilities __t;
		if (!__t.Read(s, "Capabilities"))
			break;
		__Capabilities.push_back(std::move(__t));
	}
	return true;
}
