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
	struct RelationType {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Id;
		RelationType() {}
		~RelationType() {}
	};
	struct RelationTypes {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::RelationType> RelationType;
		RelationTypes() {}
		~RelationTypes() {}
	};
	struct ContentType {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Id;
		ContentType() {}
		~ContentType() {}
	};
	struct ContentTypes {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::ContentType> ContentType;
		ContentTypes() {}
		~ContentTypes() {}
	};
	struct _Namespace {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Id;
		_Namespace() {}
		~_Namespace() {}
	};
	struct Namespaces {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::_Namespace> Namespace;
		Namespaces() {}
		~Namespaces() {}
	};
	struct Format3mf {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		bool Supported;
		Materialise::Namespaces Namespaces;
		Materialise::ContentTypes ContentTypes;
		Materialise::RelationTypes RelationTypes;
		Format3mf() {}
		~Format3mf() {}
	};
	struct FileIO {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::reference_wrapper<Materialise::Format3mf>> Format3mf;
		FileIO() {}
		~FileIO() {}
	};
	struct DriverCapabilities {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::reference_wrapper<Materialise::DriverIssues>> DriverIssues;
		std::optional<std::reference_wrapper<Materialise::FileIO>> FileIO;
		std::optional<bool> NonGenericProfiles {false};
		std::optional<bool> NoDefaultProfiles {false};
		std::optional<bool> NoMeshSupport {false};
		std::optional<bool> NoStandaloneSupport {false};
		std::optional<bool> SubcomponentProfileAssignment {true};
		std::optional<bool> SupportsBeamLatticeCapModesButtAndSphere {true};
		std::optional<std::reference_wrapper<Materialise::Capabilities>> Capabilities;
		DriverCapabilities() {}
		~DriverCapabilities() {}
	};
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
void Materialise::DriverCapabilities::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "DriverCapabilities");
	DriverIssues.value().get().Write(s);
	FileIO.value().get().Write(s);
	s.Write("NonGenericProfiles", NonGenericProfiles.value());
	s.Write("NoDefaultProfiles", NoDefaultProfiles.value());
	s.Write("NoMeshSupport", NoMeshSupport.value());
	s.Write("NoStandaloneSupport", NoStandaloneSupport.value());
	s.Write("SubcomponentProfileAssignment", SubcomponentProfileAssignment.value());
	s.Write("SupportsBeamLatticeCapModesButtAndSphere", SupportsBeamLatticeCapModesButtAndSphere.value());
	Capabilities.value().get().Write(s);
}
bool Materialise::DriverCapabilities::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "DriverCapabilities");
	if (scope.exist() == false)
		return false;
	Materialise::DriverIssues* __DriverIssues = new Materialise::DriverIssues();
	__DriverIssues->Read(s);
	DriverIssues = std::optional<std::reference_wrapper<Materialise::DriverIssues>> { *__DriverIssues };
	Materialise::FileIO* __FileIO = new Materialise::FileIO();
	__FileIO->Read(s);
	FileIO = std::optional<std::reference_wrapper<Materialise::FileIO>> { *__FileIO };
	s.ReadBool("NonGenericProfiles", NonGenericProfiles.value());
	s.ReadBool("NoDefaultProfiles", NoDefaultProfiles.value());
	s.ReadBool("NoMeshSupport", NoMeshSupport.value());
	s.ReadBool("NoStandaloneSupport", NoStandaloneSupport.value());
	s.ReadBool("SubcomponentProfileAssignment", SubcomponentProfileAssignment.value());
	s.ReadBool("SupportsBeamLatticeCapModesButtAndSphere", SupportsBeamLatticeCapModesButtAndSphere.value());
	Materialise::Capabilities* __Capabilities = new Materialise::Capabilities();
	__Capabilities->Read(s);
	Capabilities = std::optional<std::reference_wrapper<Materialise::Capabilities>> { *__Capabilities };
	return true;
}
void Materialise::FileIO::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "FileIO");
	Format3mf.value().get().Write(s);
}
bool Materialise::FileIO::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "FileIO");
	if (scope.exist() == false)
		return false;
	Materialise::Format3mf* __Format3mf = new Materialise::Format3mf();
	__Format3mf->Read(s);
	Format3mf = std::optional<std::reference_wrapper<Materialise::Format3mf>> { *__Format3mf };
	return true;
}
void Materialise::Format3mf::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Format3mf");
	s.WriteAttr("Supported", Supported);
	Namespaces.Write(s);
	ContentTypes.Write(s);
	RelationTypes.Write(s);
}
bool Materialise::Format3mf::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Format3mf");
	if (scope.exist() == false)
		return false;
	Supported = s.ReadAttrBool("Supported");
	Namespaces.Read(s);
	ContentTypes.Read(s);
	RelationTypes.Read(s);
	return true;
}
void Materialise::Namespaces::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Namespaces");
	for(int i = 0;i < Namespace.size();i++)
	{
		Namespace[i].Write(s); 
	}
}
bool Materialise::Namespaces::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Namespaces");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::_Namespace __t;
		if (__t.Read(s) == false)
			break;
		Namespace.push_back(__t);
	}
	return true;
}
void Materialise::_Namespace::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "_Namespace");
	s.WriteAttr("Id", Id.c_str());
}
bool Materialise::_Namespace::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "_Namespace");
	if (scope.exist() == false)
		return false;
	Id = s.ReadAttrStr("Id");
	return true;
}
void Materialise::ContentTypes::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "ContentTypes");
	for(int i = 0;i < ContentType.size();i++)
	{
		ContentType[i].Write(s); 
	}
}
bool Materialise::ContentTypes::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "ContentTypes");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::ContentType __t;
		if (__t.Read(s) == false)
			break;
		ContentType.push_back(__t);
	}
	return true;
}
void Materialise::ContentType::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "ContentType");
	s.WriteAttr("Id", Id.c_str());
}
bool Materialise::ContentType::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "ContentType");
	if (scope.exist() == false)
		return false;
	Id = s.ReadAttrStr("Id");
	return true;
}
void Materialise::RelationTypes::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "RelationTypes");
	for(int i = 0;i < RelationType.size();i++)
	{
		RelationType[i].Write(s); 
	}
}
bool Materialise::RelationTypes::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "RelationTypes");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::RelationType __t;
		if (__t.Read(s) == false)
			break;
		RelationType.push_back(__t);
	}
	return true;
}
void Materialise::RelationType::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "RelationType");
	s.WriteAttr("Id", Id.c_str());
}
bool Materialise::RelationType::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "RelationType");
	if (scope.exist() == false)
		return false;
	Id = s.ReadAttrStr("Id");
	return true;
}
