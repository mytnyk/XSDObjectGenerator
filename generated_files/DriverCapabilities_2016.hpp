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
	const std::string schema_generated_files_DriverCapabilities_2016_namespace = "http://schemas.materialise.com/BuildProcessor/2016";
	enum class DriverIssueId {
		Licensing,
		Configuration,
		Other,
	};

	enum class DriverIssueSeverity {
		Information,
		Warning,
		Critical,
	};

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
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		RelationType(const RelationType&) = delete;
		RelationType& operator=(RelationType&&) = delete;
		RelationType& operator=(RelationType&) = delete;
		RelationType(RelationType&&) noexcept;
		RelationType() = default;
		~RelationType() = default;
		std::string Id;
	};
	struct RelationTypes {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		RelationTypes(const RelationTypes&) = delete;
		RelationTypes& operator=(RelationTypes&&) = delete;
		RelationTypes& operator=(RelationTypes&) = delete;
		RelationTypes(RelationTypes&&) noexcept;
		RelationTypes() = default;
		~RelationTypes() = default;
		std::vector<RelationType> RelationType;
	};
	struct ContentType {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		ContentType(const ContentType&) = delete;
		ContentType& operator=(ContentType&&) = delete;
		ContentType& operator=(ContentType&) = delete;
		ContentType(ContentType&&) noexcept;
		ContentType() = default;
		~ContentType() = default;
		std::string Id;
	};
	struct ContentTypes {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		ContentTypes(const ContentTypes&) = delete;
		ContentTypes& operator=(ContentTypes&&) = delete;
		ContentTypes& operator=(ContentTypes&) = delete;
		ContentTypes(ContentTypes&&) noexcept;
		ContentTypes() = default;
		~ContentTypes() = default;
		std::vector<ContentType> ContentType;
	};
	struct _Namespace {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		_Namespace(const _Namespace&) = delete;
		_Namespace& operator=(_Namespace&&) = delete;
		_Namespace& operator=(_Namespace&) = delete;
		_Namespace(_Namespace&&) noexcept;
		_Namespace() = default;
		~_Namespace() = default;
		std::string Id;
	};
	struct Namespaces {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Namespaces(const Namespaces&) = delete;
		Namespaces& operator=(Namespaces&&) = delete;
		Namespaces& operator=(Namespaces&) = delete;
		Namespaces(Namespaces&&) noexcept;
		Namespaces() = default;
		~Namespaces() = default;
		std::vector<_Namespace> Namespace;
	};
	struct Format3mf {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Format3mf(const Format3mf&) = delete;
		Format3mf& operator=(Format3mf&&) = delete;
		Format3mf& operator=(Format3mf&) = delete;
		Format3mf(Format3mf&&) noexcept;
		Format3mf() = default;
		~Format3mf() = default;
		bool Supported;
		Namespaces Namespaces;
		ContentTypes ContentTypes;
		RelationTypes RelationTypes;
	};
	struct FileIO {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		FileIO(const FileIO&) = delete;
		FileIO& operator=(FileIO&&) = delete;
		FileIO& operator=(FileIO&) = delete;
		FileIO(FileIO&&) noexcept;
		FileIO() = default;
		~FileIO() = default;
		std::optional<std::unique_ptr<Format3mf>> Format3mf;
	};
	struct DriverCapabilities {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		DriverCapabilities(const DriverCapabilities&) = delete;
		DriverCapabilities& operator=(DriverCapabilities&&) = delete;
		DriverCapabilities& operator=(DriverCapabilities&) = delete;
		DriverCapabilities(DriverCapabilities&&) noexcept;
		DriverCapabilities() = default;
		~DriverCapabilities() = default;
		std::optional<std::unique_ptr<DriverIssues>> DriverIssues;
		std::optional<std::unique_ptr<FileIO>> FileIO;
		std::optional<bool> NonGenericProfiles {false};
		std::optional<bool> NoDefaultProfiles {false};
		std::optional<std::unique_ptr<Capabilities>> Capabilities;
	};
	struct Capability {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Capability(const Capability&) = delete;
		Capability& operator=(Capability&&) = delete;
		Capability& operator=(Capability&) = delete;
		Capability(Capability&&) noexcept;
		Capability() = default;
		~Capability() = default;
		std::string Id;
		std::optional<std::string> Value;
	};
	struct Capabilities {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Capabilities(const Capabilities&) = delete;
		Capabilities& operator=(Capabilities&&) = delete;
		Capabilities& operator=(Capabilities&) = delete;
		Capabilities(Capabilities&&) noexcept;
		Capabilities() = default;
		~Capabilities() = default;
		std::string Id;
		std::vector<Capability> Capability;
		std::vector<Capabilities> __Capabilities;
	};
	struct DriverIssue {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		DriverIssue(const DriverIssue&) = delete;
		DriverIssue& operator=(DriverIssue&&) = delete;
		DriverIssue& operator=(DriverIssue&) = delete;
		DriverIssue(DriverIssue&&) noexcept;
		DriverIssue() = default;
		~DriverIssue() = default;
		Materialise::DriverIssueId Id;
		std::string Title;
		std::optional<std::string> Description;
		Materialise::DriverIssueSeverity Severity;
	};
	struct DriverIssues {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		DriverIssues(const DriverIssues&) = delete;
		DriverIssues& operator=(DriverIssues&&) = delete;
		DriverIssues& operator=(DriverIssues&) = delete;
		DriverIssues(DriverIssues&&) noexcept;
		DriverIssues() = default;
		~DriverIssues() = default;
		std::vector<DriverIssue> DriverIssue;
	};
}
Materialise::DriverIssue::DriverIssue(Materialise::DriverIssue &&___DriverIssue) noexcept
	: Id(___DriverIssue.Id)
	, Title(___DriverIssue.Title)
	, Description(___DriverIssue.Description)
	, Severity(___DriverIssue.Severity)
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
Materialise::DriverIssues::DriverIssues(Materialise::DriverIssues &&___DriverIssues) noexcept
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
Materialise::Capability::Capability(Materialise::Capability &&___Capability) noexcept
	: Id(___Capability.Id)
	, Value(___Capability.Value)
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
Materialise::Capabilities::Capabilities(Materialise::Capabilities &&___Capabilities) noexcept
	: Id(___Capabilities.Id)
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
Materialise::DriverCapabilities::DriverCapabilities(Materialise::DriverCapabilities &&___DriverCapabilities) noexcept
	: DriverIssues(std::move(___DriverCapabilities.DriverIssues))
	, FileIO(std::move(___DriverCapabilities.FileIO))
	, NonGenericProfiles(___DriverCapabilities.NonGenericProfiles)
	, NoDefaultProfiles(___DriverCapabilities.NoDefaultProfiles)
	, Capabilities(std::move(___DriverCapabilities.Capabilities))
{ }
void Materialise::DriverCapabilities::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (DriverIssues.has_value())
		DriverIssues.value().get()->Write(s, "DriverIssues");
	if (FileIO.has_value())
		FileIO.value().get()->Write(s, "FileIO");
	if (NonGenericProfiles.has_value())
		s.Write("NonGenericProfiles", NonGenericProfiles.value());
	if (NoDefaultProfiles.has_value())
		s.Write("NoDefaultProfiles", NoDefaultProfiles.value());
	if (Capabilities.has_value())
		Capabilities.value().get()->Write(s, "Capabilities");
}
bool Materialise::DriverCapabilities::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::unique_ptr<Materialise::DriverIssues> __DriverIssues = std::make_unique<Materialise::DriverIssues>();
	if (__DriverIssues->Read(s, "DriverIssues"))
		DriverIssues = std::make_optional(std::move(__DriverIssues));
	std::unique_ptr<Materialise::FileIO> __FileIO = std::make_unique<Materialise::FileIO>();
	if (__FileIO->Read(s, "FileIO"))
		FileIO = std::make_optional(std::move(__FileIO));
	bool __NonGenericProfiles;
	if (s.ReadBool("NonGenericProfiles", __NonGenericProfiles))
		NonGenericProfiles = std::make_optional(__NonGenericProfiles);
	bool __NoDefaultProfiles;
	if (s.ReadBool("NoDefaultProfiles", __NoDefaultProfiles))
		NoDefaultProfiles = std::make_optional(__NoDefaultProfiles);
	std::unique_ptr<Materialise::Capabilities> __Capabilities = std::make_unique<Materialise::Capabilities>();
	if (__Capabilities->Read(s, "Capabilities"))
		Capabilities = std::make_optional(std::move(__Capabilities));
	return true;
}
Materialise::FileIO::FileIO(Materialise::FileIO &&___FileIO) noexcept
	: Format3mf(std::move(___FileIO.Format3mf))
{ }
void Materialise::FileIO::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (Format3mf.has_value())
		Format3mf.value().get()->Write(s, "Format3mf");
}
bool Materialise::FileIO::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::unique_ptr<Materialise::Format3mf> __Format3mf = std::make_unique<Materialise::Format3mf>();
	if (__Format3mf->Read(s, "Format3mf"))
		Format3mf = std::make_optional(std::move(__Format3mf));
	return true;
}
Materialise::Format3mf::Format3mf(Materialise::Format3mf &&___Format3mf) noexcept
	: Supported(___Format3mf.Supported)
	, Namespaces(std::move(___Format3mf.Namespaces))
	, ContentTypes(std::move(___Format3mf.ContentTypes))
	, RelationTypes(std::move(___Format3mf.RelationTypes))
{ }
void Materialise::Format3mf::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Supported", Supported);
	Namespaces.Write(s, "Namespaces");
	ContentTypes.Write(s, "ContentTypes");
	RelationTypes.Write(s, "RelationTypes");
}
bool Materialise::Format3mf::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrBool("Supported", Supported);
	Namespaces.Read(s, "Namespaces");
	ContentTypes.Read(s, "ContentTypes");
	RelationTypes.Read(s, "RelationTypes");
	return true;
}
Materialise::Namespaces::Namespaces(Materialise::Namespaces &&___Namespaces) noexcept
	: Namespace(std::move(___Namespaces.Namespace))
{ }
void Materialise::Namespaces::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Namespace)
	{
		element.Write(s, "Namespace"); 
	}
}
bool Materialise::Namespaces::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::_Namespace __t;
		if (!__t.Read(s, "Namespace"))
			break;
		Namespace.push_back(std::move(__t));
	}
	return true;
}
Materialise::_Namespace::_Namespace(Materialise::_Namespace &&____Namespace) noexcept
	: Id(____Namespace.Id)
{ }
void Materialise::_Namespace::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Id", Id.c_str());
}
bool Materialise::_Namespace::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("Id", Id);
	return true;
}
Materialise::ContentTypes::ContentTypes(Materialise::ContentTypes &&___ContentTypes) noexcept
	: ContentType(std::move(___ContentTypes.ContentType))
{ }
void Materialise::ContentTypes::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : ContentType)
	{
		element.Write(s, "ContentType"); 
	}
}
bool Materialise::ContentTypes::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::ContentType __t;
		if (!__t.Read(s, "ContentType"))
			break;
		ContentType.push_back(std::move(__t));
	}
	return true;
}
Materialise::ContentType::ContentType(Materialise::ContentType &&___ContentType) noexcept
	: Id(___ContentType.Id)
{ }
void Materialise::ContentType::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Id", Id.c_str());
}
bool Materialise::ContentType::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("Id", Id);
	return true;
}
Materialise::RelationTypes::RelationTypes(Materialise::RelationTypes &&___RelationTypes) noexcept
	: RelationType(std::move(___RelationTypes.RelationType))
{ }
void Materialise::RelationTypes::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : RelationType)
	{
		element.Write(s, "RelationType"); 
	}
}
bool Materialise::RelationTypes::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::RelationType __t;
		if (!__t.Read(s, "RelationType"))
			break;
		RelationType.push_back(std::move(__t));
	}
	return true;
}
Materialise::RelationType::RelationType(Materialise::RelationType &&___RelationType) noexcept
	: Id(___RelationType.Id)
{ }
void Materialise::RelationType::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Id", Id.c_str());
}
bool Materialise::RelationType::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("Id", Id);
	return true;
}
