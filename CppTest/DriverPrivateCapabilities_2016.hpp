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
	struct DriverCapabilities;
	struct FileIO;
	struct Format3mf;
	struct Namespaces;
	struct _Namespace;
	struct ContentTypes;
	struct ContentType;
	struct RelationTypes;
	struct RelationType;
	struct DriverPrivateCapabilities;
	struct DriverCapabilities {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<std::reference_wrapper<Materialise::DriverIssues>> DriverIssues;
		std::optional<std::reference_wrapper<Materialise::FileIO>> FileIO;
		std::optional<bool> NonGenericProfiles {false};
		std::optional<bool> NoDefaultProfiles {false};
		std::optional<std::reference_wrapper<Materialise::Capabilities>> Capabilities;
		DriverCapabilities() {}
		~DriverCapabilities() {}
	};
	struct DriverPrivateCapabilities {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<bool> NoSupportsAsSubcomponents {false};
		std::optional<bool> SupportsToolpathGeneration {false};
		std::optional<std::reference_wrapper<Materialise::DriverIssues>> DriverIssues;
		std::optional<std::reference_wrapper<Materialise::FileIO>> FileIO;
		std::optional<bool> NonGenericProfiles {false};
		std::optional<bool> NoDefaultProfiles {false};
		std::optional<std::reference_wrapper<Materialise::Capabilities>> Capabilities;
		DriverPrivateCapabilities() {}
		~DriverPrivateCapabilities() {}
	};
	struct RelationType {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string Id;
		RelationType() {}
		~RelationType() {}
	};
	struct RelationTypes {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::RelationType> RelationType;
		RelationTypes() {}
		~RelationTypes() {}
	};
	struct ContentType {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string Id;
		ContentType() {}
		~ContentType() {}
	};
	struct ContentTypes {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::ContentType> ContentType;
		ContentTypes() {}
		~ContentTypes() {}
	};
	struct _Namespace {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string Id;
		_Namespace() {}
		~_Namespace() {}
	};
	struct Namespaces {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::_Namespace> Namespace;
		Namespaces() {}
		~Namespaces() {}
	};
	struct Format3mf {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		bool Supported;
		Materialise::Namespaces Namespaces;
		Materialise::ContentTypes ContentTypes;
		Materialise::RelationTypes RelationTypes;
		Format3mf() {}
		~Format3mf() {}
	};
	struct FileIO {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<std::reference_wrapper<Materialise::Format3mf>> Format3mf;
		FileIO() {}
		~FileIO() {}
	};
	struct Capability {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string Id;
		std::optional<std::string> Value {""};
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
		std::optional<std::string> Description {""};
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
	Id = Materialise::ConvertStringToDriverIssueId(s.ReadAttrStr("Id"));
	Title = s.ReadAttrStr("Title");
	Description = s.ReadAttrStr("Description");
	Severity = Materialise::ConvertStringToDriverIssueSeverity(s.ReadAttrStr("Severity"));
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
	Id = s.ReadAttrStr("Id");
	Value = s.ReadAttrStr("Value");
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
		__Capabilities[i].Write(s, "__Capabilities"); 
	}
}
bool Materialise::Capabilities::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	Id = s.ReadAttrStr("Id");
	while (true) { 
		Materialise::Capability __t;
		if (__t.Read(s, "Capability") == false)
			break;
		Capability.push_back(__t);
	}
	while (true) { 
		Materialise::Capabilities __t;
		if (__t.Read(s, "__Capabilities") == false)
			break;
		__Capabilities.push_back(__t);
	}
	return true;
}
void Materialise::DriverCapabilities::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (DriverIssues.has_value())
		DriverIssues.value().get().Write(s, "DriverIssues");
	if (FileIO.has_value())
		FileIO.value().get().Write(s, "FileIO");
	if (NonGenericProfiles.has_value())
		s.Write("NonGenericProfiles", NonGenericProfiles.value());
	if (NoDefaultProfiles.has_value())
		s.Write("NoDefaultProfiles", NoDefaultProfiles.value());
	if (Capabilities.has_value())
		Capabilities.value().get().Write(s, "Capabilities");
}
bool Materialise::DriverCapabilities::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	Materialise::DriverIssues* __DriverIssues = new Materialise::DriverIssues();
	__DriverIssues->Read(s, "DriverIssues");
	DriverIssues = std::optional<std::reference_wrapper<Materialise::DriverIssues>> { *__DriverIssues };
	Materialise::FileIO* __FileIO = new Materialise::FileIO();
	__FileIO->Read(s, "FileIO");
	FileIO = std::optional<std::reference_wrapper<Materialise::FileIO>> { *__FileIO };
	s.ReadBool("NonGenericProfiles", NonGenericProfiles.value());
	s.ReadBool("NoDefaultProfiles", NoDefaultProfiles.value());
	Materialise::Capabilities* __Capabilities = new Materialise::Capabilities();
	__Capabilities->Read(s, "Capabilities");
	Capabilities = std::optional<std::reference_wrapper<Materialise::Capabilities>> { *__Capabilities };
	return true;
}
void Materialise::FileIO::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (Format3mf.has_value())
		Format3mf.value().get().Write(s, "Format3mf");
}
bool Materialise::FileIO::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	Materialise::Format3mf* __Format3mf = new Materialise::Format3mf();
	__Format3mf->Read(s, "Format3mf");
	Format3mf = std::optional<std::reference_wrapper<Materialise::Format3mf>> { *__Format3mf };
	return true;
}
void Materialise::Format3mf::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Supported", Supported);
	Namespaces.Write(s, "Namespaces");
	ContentTypes.Write(s, "ContentTypes");
	RelationTypes.Write(s, "RelationTypes");
}
bool Materialise::Format3mf::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	Supported = s.ReadAttrBool("Supported");
	Namespaces.Read(s, "Namespaces");
	ContentTypes.Read(s, "ContentTypes");
	RelationTypes.Read(s, "RelationTypes");
	return true;
}
void Materialise::Namespaces::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < Namespace.size();i++)
	{
		Namespace[i].Write(s, "Namespace"); 
	}
}
bool Materialise::Namespaces::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::_Namespace __t;
		if (__t.Read(s, "Namespace") == false)
			break;
		Namespace.push_back(__t);
	}
	return true;
}
void Materialise::_Namespace::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Id", Id.c_str());
}
bool Materialise::_Namespace::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	Id = s.ReadAttrStr("Id");
	return true;
}
void Materialise::ContentTypes::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < ContentType.size();i++)
	{
		ContentType[i].Write(s, "ContentType"); 
	}
}
bool Materialise::ContentTypes::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::ContentType __t;
		if (__t.Read(s, "ContentType") == false)
			break;
		ContentType.push_back(__t);
	}
	return true;
}
void Materialise::ContentType::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Id", Id.c_str());
}
bool Materialise::ContentType::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	Id = s.ReadAttrStr("Id");
	return true;
}
void Materialise::RelationTypes::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < RelationType.size();i++)
	{
		RelationType[i].Write(s, "RelationType"); 
	}
}
bool Materialise::RelationTypes::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::RelationType __t;
		if (__t.Read(s, "RelationType") == false)
			break;
		RelationType.push_back(__t);
	}
	return true;
}
void Materialise::RelationType::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Id", Id.c_str());
}
bool Materialise::RelationType::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	Id = s.ReadAttrStr("Id");
	return true;
}
void Materialise::DriverPrivateCapabilities::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (NoSupportsAsSubcomponents.has_value())
		s.Write("NoSupportsAsSubcomponents", NoSupportsAsSubcomponents.value());
	if (SupportsToolpathGeneration.has_value())
		s.Write("SupportsToolpathGeneration", SupportsToolpathGeneration.value());
	if (DriverIssues.has_value())
		DriverIssues.value().get().Write(s, "DriverIssues");
	if (FileIO.has_value())
		FileIO.value().get().Write(s, "FileIO");
	if (NonGenericProfiles.has_value())
		s.Write("NonGenericProfiles", NonGenericProfiles.value());
	if (NoDefaultProfiles.has_value())
		s.Write("NoDefaultProfiles", NoDefaultProfiles.value());
	if (Capabilities.has_value())
		Capabilities.value().get().Write(s, "Capabilities");
}
bool Materialise::DriverPrivateCapabilities::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadBool("NoSupportsAsSubcomponents", NoSupportsAsSubcomponents.value());
	s.ReadBool("SupportsToolpathGeneration", SupportsToolpathGeneration.value());
	Materialise::DriverIssues* __DriverIssues = new Materialise::DriverIssues();
	__DriverIssues->Read(s, "DriverIssues");
	DriverIssues = std::optional<std::reference_wrapper<Materialise::DriverIssues>> { *__DriverIssues };
	Materialise::FileIO* __FileIO = new Materialise::FileIO();
	__FileIO->Read(s, "FileIO");
	FileIO = std::optional<std::reference_wrapper<Materialise::FileIO>> { *__FileIO };
	s.ReadBool("NonGenericProfiles", NonGenericProfiles.value());
	s.ReadBool("NoDefaultProfiles", NoDefaultProfiles.value());
	Materialise::Capabilities* __Capabilities = new Materialise::Capabilities();
	__Capabilities->Read(s, "Capabilities");
	Capabilities = std::optional<std::reference_wrapper<Materialise::Capabilities>> { *__Capabilities };
	return true;
}
