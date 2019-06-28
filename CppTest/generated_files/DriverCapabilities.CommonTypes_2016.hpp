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
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Id;
		std::optional<std::string> Value {""};
		Capability() {}
		~Capability() {}
	};
	struct Capabilities {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Id;
		std::vector<Materialise::Capability> Capability;
		std::vector<Materialise::Capabilities> __Capabilities;
		Capabilities() {}
		~Capabilities() {}
	};
	struct DriverIssue {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		Materialise::DriverIssueId Id;
		std::string Title;
		std::optional<std::string> Description {""};
		Materialise::DriverIssueSeverity Severity;
		DriverIssue() {}
		~DriverIssue() {}
	};
	struct DriverIssues {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::DriverIssue> DriverIssue;
		DriverIssues() {}
		~DriverIssues() {}
	};
}
void Materialise::DriverIssue::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "DriverIssue");
	s.WriteAttr("Id", Materialise::ConvertDriverIssueIdToString(Id).c_str());
	s.WriteAttr("Title", Title.c_str());
	s.WriteAttr("Description", Description.value().c_str());
	s.WriteAttr("Severity", Materialise::ConvertDriverIssueSeverityToString(Severity).c_str());
}
bool Materialise::DriverIssue::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "DriverIssue");
	if (scope.exist() == false)
		return false;
	Id = Materialise::ConvertStringToDriverIssueId(s.ReadAttrStr("Id"));
	Title = s.ReadAttrStr("Title");
	Description = s.ReadAttrStr("Description");
	Severity = Materialise::ConvertStringToDriverIssueSeverity(s.ReadAttrStr("Severity"));
	return true;
}
void Materialise::DriverIssues::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "DriverIssues");
	for(int i = 0;i < DriverIssue.size();i++)
	{
		DriverIssue[i].Write(s); 
	}
}
bool Materialise::DriverIssues::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "DriverIssues");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::DriverIssue __t;
		if (__t.Read(s) == false)
			break;
		DriverIssue.push_back(__t);
	}
	return true;
}
void Materialise::Capability::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Capability");
	s.WriteAttr("Id", Id.c_str());
	s.WriteAttr("Value", Value.value().c_str());
}
bool Materialise::Capability::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Capability");
	if (scope.exist() == false)
		return false;
	Id = s.ReadAttrStr("Id");
	Value = s.ReadAttrStr("Value");
	return true;
}
void Materialise::Capabilities::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Capabilities");
	s.WriteAttr("Id", Id.c_str());
	for(int i = 0;i < Capability.size();i++)
	{
		Capability[i].Write(s); 
	}
	for(int i = 0;i < __Capabilities.size();i++)
	{
		__Capabilities[i].Write(s); 
	}
}
bool Materialise::Capabilities::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Capabilities");
	if (scope.exist() == false)
		return false;
	Id = s.ReadAttrStr("Id");
	while (true) { 
		Materialise::Capability __t;
		if (__t.Read(s) == false)
			break;
		Capability.push_back(__t);
	}
	while (true) { 
		Materialise::Capabilities __t;
		if (__t.Read(s) == false)
			break;
		__Capabilities.push_back(__t);
	}
	return true;
}
