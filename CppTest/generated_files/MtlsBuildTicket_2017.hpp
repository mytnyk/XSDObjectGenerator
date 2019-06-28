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
	enum class ST_PropertyType {
		_bool,
		integer,
		_unsigned,
		_string,
		number,
		_bool,
		_enum,
		ProfileName,
		Complex,
		Complex2,
		ComplexArray,
	};

	enum class ST_PropertyTreeType {
		_object,
		component,
		build,
		builditem,
	};

	enum class Shape {
		box,
		cylinder,
		custom,
	};

	enum class ST_Version {
		_1_0,
	};

	ST_PropertyType ConvertStringToST_PropertyType(std::string str) {
		if (str == "bool") return ST_PropertyType::_bool;
		if (str == "integer") return ST_PropertyType::integer;
		if (str == "unsigned") return ST_PropertyType::_unsigned;
		if (str == "string") return ST_PropertyType::_string;
		if (str == "number") return ST_PropertyType::number;
		if (str == "bool") return ST_PropertyType::_bool;
		if (str == "enum") return ST_PropertyType::_enum;
		if (str == "ProfileName") return ST_PropertyType::ProfileName;
		if (str == "Complex") return ST_PropertyType::Complex;
		if (str == "Complex2") return ST_PropertyType::Complex2;
		if (str == "ComplexArray") return ST_PropertyType::ComplexArray;
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertST_PropertyTypeToString(ST_PropertyType e) {
		if (e == ST_PropertyType::_bool) return "bool";
		if (e == ST_PropertyType::integer) return "integer";
		if (e == ST_PropertyType::_unsigned) return "unsigned";
		if (e == ST_PropertyType::_string) return "string";
		if (e == ST_PropertyType::number) return "number";
		if (e == ST_PropertyType::_bool) return "bool";
		if (e == ST_PropertyType::_enum) return "enum";
		if (e == ST_PropertyType::ProfileName) return "ProfileName";
		if (e == ST_PropertyType::Complex) return "Complex";
		if (e == ST_PropertyType::Complex2) return "Complex2";
		if (e == ST_PropertyType::ComplexArray) return "ComplexArray";
		throw std::exception("Can't convert enum value to string");
	}

	ST_PropertyTreeType ConvertStringToST_PropertyTreeType(std::string str) {
		if (str == "object") return ST_PropertyTreeType::_object;
		if (str == "component") return ST_PropertyTreeType::component;
		if (str == "build") return ST_PropertyTreeType::build;
		if (str == "builditem") return ST_PropertyTreeType::builditem;
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertST_PropertyTreeTypeToString(ST_PropertyTreeType e) {
		if (e == ST_PropertyTreeType::_object) return "object";
		if (e == ST_PropertyTreeType::component) return "component";
		if (e == ST_PropertyTreeType::build) return "build";
		if (e == ST_PropertyTreeType::builditem) return "builditem";
		throw std::exception("Can't convert enum value to string");
	}

	Shape ConvertStringToShape(std::string str) {
		if (str == "box") return Shape::box;
		if (str == "cylinder") return Shape::cylinder;
		if (str == "custom") return Shape::custom;
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertShapeToString(Shape e) {
		if (e == Shape::box) return "box";
		if (e == Shape::cylinder) return "cylinder";
		if (e == Shape::custom) return "custom";
		throw std::exception("Can't convert enum value to string");
	}

	ST_Version ConvertStringToST_Version(std::string str) {
		if (str == "1.0") return ST_Version::_1_0;
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertST_VersionToString(ST_Version e) {
		if (e == ST_Version::_1_0) return "1.0";
		throw std::exception("Can't convert enum value to string");
	}

	struct CT_PropertyTree;
	struct CT_PropertyTreeWithUUID;
	struct CT_PropertyTreeWithComponents;
	struct CT_BuildTicket;
	struct Info;
	struct Source;
	struct PartOverrides;
	struct ObjectProperties;
	struct CT_MtlsPropertyTemplate;
	struct BuildTicket;
	struct CT_Property;
	struct CT_ProfileWithProperties;
	struct CT_PropertyTemplateTree;
	struct CT_PropertyTemplateNode;
	struct CT_MtlsMachineInfo;
	struct LockedAreas;
	struct CT_MtlsMachineInfoComponent;
	struct Pos;
	struct Dim;
	struct Mesh;
	struct MtlsBuildTicket;
	struct MtlsMachineParameters;
	struct MtlsPropertyTemplate;
	struct MtlsMachineInfo;
	struct Dim {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<double> x;
		std::optional<double> y;
		double z;
		std::optional<std::string> radius {""};
		Dim() {}
		~Dim() {}
	};
	struct Pos {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		double x;
		double y;
		double z;
		Pos() {}
		~Pos() {}
	};
	struct CT_MtlsMachineInfoComponent {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		Shape Shape;
		Materialise::Pos Pos;
		Materialise::Dim Dim;
		std::optional<std::reference_wrapper<Materialise::Mesh>> Mesh;
		CT_MtlsMachineInfoComponent() {}
		~CT_MtlsMachineInfoComponent() {}
	};
	struct CT_MtlsMachineInfo {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<Materialise::ST_Version> version;
		Materialise::CT_MtlsMachineInfoComponent BuildVolume;
		Materialise::CT_MtlsMachineInfoComponent Tray;
		std::optional<std::reference_wrapper<Materialise::LockedAreas>> LockedAreas;
		CT_MtlsMachineInfo() {}
		~CT_MtlsMachineInfo() {}
	};
	struct MtlsMachineInfo {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<Materialise::ST_Version> version;
		Materialise::CT_MtlsMachineInfoComponent BuildVolume;
		Materialise::CT_MtlsMachineInfoComponent Tray;
		std::optional<std::reference_wrapper<Materialise::LockedAreas>> LockedAreas;
		MtlsMachineInfo() {}
		~MtlsMachineInfo() {}
	};
	struct CT_PropertyTemplateTree {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::CT_PropertyTemplateNode> PropertyNode;
		CT_PropertyTemplateTree() {}
		~CT_PropertyTemplateTree() {}
	};
	struct BuildTicket {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		Materialise::CT_PropertyTemplateTree Defaults;
		std::optional<std::reference_wrapper<Materialise::CT_PropertyTemplateTree>> PartOverrides;
		BuildTicket() {}
		~BuildTicket() {}
	};
	struct CT_MtlsPropertyTemplate {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<Materialise::ST_Version> version;
		Materialise::CT_PropertyTemplateTree MachineParameters;
		Materialise::BuildTicket BuildTicket;
		CT_MtlsPropertyTemplate() {}
		~CT_MtlsPropertyTemplate() {}
	};
	struct MtlsPropertyTemplate {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<Materialise::ST_Version> version;
		Materialise::CT_PropertyTemplateTree MachineParameters;
		Materialise::BuildTicket BuildTicket;
		MtlsPropertyTemplate() {}
		~MtlsPropertyTemplate() {}
	};
	struct CT_PropertyTree {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::CT_Property> Property;
		CT_PropertyTree() {}
		~CT_PropertyTree() {}
	};
	struct MtlsMachineParameters {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<Materialise::ST_Version> version;
		std::vector<Materialise::CT_Property> Property;
		MtlsMachineParameters() {}
		~MtlsMachineParameters() {}
	};
	struct Source {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::string> Id {""};
		std::optional<bool> PropertyTemplate;
		Source() {}
		~Source() {}
	};
	struct Info {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		Materialise::Source Source;
		Info() {}
		~Info() {}
	};
	struct CT_BuildTicket {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<bool> has_property_template;
		Materialise::Info Info;
		std::optional<std::reference_wrapper<Materialise::CT_PropertyTree>> Defaults;
		std::optional<std::reference_wrapper<Materialise::PartOverrides>> PartOverrides;
		std::optional<std::reference_wrapper<Materialise::ObjectProperties>> ObjectProperties;
		CT_BuildTicket() {}
		~CT_BuildTicket() {}
	};
	struct MtlsBuildTicket {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<bool> has_property_template;
		Materialise::Info Info;
		std::optional<std::reference_wrapper<Materialise::CT_PropertyTree>> Defaults;
		std::optional<std::reference_wrapper<Materialise::PartOverrides>> PartOverrides;
		std::optional<std::reference_wrapper<Materialise::ObjectProperties>> ObjectProperties;
		MtlsBuildTicket() {}
		~MtlsBuildTicket() {}
	};
	struct Mesh {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string uuid;
		Mesh() {}
		~Mesh() {}
	};
	struct LockedAreas {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<std::string> Area;
		LockedAreas() {}
		~LockedAreas() {}
	};
	struct CT_PropertyTemplateNode {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Name;
		std::optional<Materialise::ST_PropertyType> Type;
		std::optional<std::string> DisplayName {""};
		std::optional<std::string> DisplayNameContainer {""};
		std::optional<std::string> PropertyName {""};
		std::optional<std::string> Default {""};
		std::optional<std::string> ProfileList {""};
		std::optional<std::string> List {""};
		std::optional<std::string> ProfileName {""};
		std::vector<Materialise::CT_PropertyTemplateNode> PropertyNode;
		CT_PropertyTemplateNode() {}
		~CT_PropertyTemplateNode() {}
	};
	struct CT_ProfileWithProperties {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Name;
		std::vector<Materialise::CT_Property> Property;
		CT_ProfileWithProperties() {}
		~CT_ProfileWithProperties() {}
	};
	struct CT_Property {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Name;
		std::optional<Materialise::ST_PropertyType> Type;
		std::optional<std::string> ProfileList {""};
		std::vector<Materialise::CT_ProfileWithProperties> Profile;
		std::vector<Materialise::CT_Property> Property;
		CT_Property() {}
		~CT_Property() {}
	};
	struct ObjectProperties {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::CT_PropertyTreeWithUUID> Instance;
		ObjectProperties() {}
		~ObjectProperties() {}
	};
	struct PartOverrides {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::CT_PropertyTreeWithComponents> Instance;
		PartOverrides() {}
		~PartOverrides() {}
	};
	struct CT_PropertyTreeWithUUID {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string uuid;
		std::optional<Materialise::ST_PropertyTreeType> type;
		std::vector<Materialise::CT_Property> Property;
		CT_PropertyTreeWithUUID() {}
		~CT_PropertyTreeWithUUID() {}
	};
	struct CT_PropertyTreeWithComponents {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::CT_PropertyTreeWithUUID> Component;
		std::string uuid;
		std::optional<Materialise::ST_PropertyTreeType> type;
		std::vector<Materialise::CT_Property> Property;
		CT_PropertyTreeWithComponents() {}
		~CT_PropertyTreeWithComponents() {}
	};
}
void Materialise::CT_PropertyTree::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "CT_PropertyTree");
	for(int i = 0;i < Property.size();i++)
	{
		Property[i].Write(s); 
	}
}
bool Materialise::CT_PropertyTree::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "CT_PropertyTree");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::CT_Property __t;
		if (__t.Read(s) == false)
			break;
		Property.push_back(__t);
	}
	return true;
}
void Materialise::CT_PropertyTreeWithUUID::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "CT_PropertyTreeWithUUID");
	s.WriteAttr("uuid", uuid.c_str());
	s.WriteAttr("type", Materialise::ConvertST_PropertyTreeTypeToString(type.value()).c_str());
	for(int i = 0;i < Property.size();i++)
	{
		Property[i].Write(s); 
	}
}
bool Materialise::CT_PropertyTreeWithUUID::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "CT_PropertyTreeWithUUID");
	if (scope.exist() == false)
		return false;
	uuid = s.ReadAttrStr("uuid");
	type = Materialise::ConvertStringToST_PropertyTreeType(s.ReadAttrStr("type"));
	while (true) { 
		Materialise::CT_Property __t;
		if (__t.Read(s) == false)
			break;
		Property.push_back(__t);
	}
	return true;
}
void Materialise::CT_PropertyTreeWithComponents::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "CT_PropertyTreeWithComponents");
	for(int i = 0;i < Component.size();i++)
	{
		Component[i].Write(s); 
	}
	s.WriteAttr("uuid", uuid.c_str());
	s.WriteAttr("type", Materialise::ConvertST_PropertyTreeTypeToString(type.value()).c_str());
	for(int i = 0;i < Property.size();i++)
	{
		Property[i].Write(s); 
	}
}
bool Materialise::CT_PropertyTreeWithComponents::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "CT_PropertyTreeWithComponents");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::CT_PropertyTreeWithUUID __t;
		if (__t.Read(s) == false)
			break;
		Component.push_back(__t);
	}
	uuid = s.ReadAttrStr("uuid");
	type = Materialise::ConvertStringToST_PropertyTreeType(s.ReadAttrStr("type"));
	while (true) { 
		Materialise::CT_Property __t;
		if (__t.Read(s) == false)
			break;
		Property.push_back(__t);
	}
	return true;
}
void Materialise::CT_BuildTicket::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "CT_BuildTicket");
	s.WriteAttr("has_property_template", has_property_template.value());
	Info.Write(s);
	Defaults.value().get().Write(s);
	PartOverrides.value().get().Write(s);
	ObjectProperties.value().get().Write(s);
}
bool Materialise::CT_BuildTicket::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "CT_BuildTicket");
	if (scope.exist() == false)
		return false;
	has_property_template = s.ReadAttrBool("has_property_template");
	Info.Read(s);
	Materialise::CT_PropertyTree* __Defaults = new Materialise::CT_PropertyTree();
	__Defaults->Read(s);
	Defaults = std::optional<std::reference_wrapper<Materialise::CT_PropertyTree>> { *__Defaults };
	Materialise::PartOverrides* __PartOverrides = new Materialise::PartOverrides();
	__PartOverrides->Read(s);
	PartOverrides = std::optional<std::reference_wrapper<Materialise::PartOverrides>> { *__PartOverrides };
	Materialise::ObjectProperties* __ObjectProperties = new Materialise::ObjectProperties();
	__ObjectProperties->Read(s);
	ObjectProperties = std::optional<std::reference_wrapper<Materialise::ObjectProperties>> { *__ObjectProperties };
	return true;
}
void Materialise::Info::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Info");
	Source.Write(s);
}
bool Materialise::Info::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Info");
	if (scope.exist() == false)
		return false;
	Source.Read(s);
	return true;
}
void Materialise::Source::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Source");
	s.WriteAttr("Id", Id.value().c_str());
	s.WriteAttr("PropertyTemplate", PropertyTemplate.value());
}
bool Materialise::Source::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Source");
	if (scope.exist() == false)
		return false;
	Id = s.ReadAttrStr("Id");
	PropertyTemplate = s.ReadAttrBool("PropertyTemplate");
	return true;
}
void Materialise::PartOverrides::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "PartOverrides");
	for(int i = 0;i < Instance.size();i++)
	{
		Instance[i].Write(s); 
	}
}
bool Materialise::PartOverrides::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "PartOverrides");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::CT_PropertyTreeWithComponents __t;
		if (__t.Read(s) == false)
			break;
		Instance.push_back(__t);
	}
	return true;
}
void Materialise::ObjectProperties::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "ObjectProperties");
	for(int i = 0;i < Instance.size();i++)
	{
		Instance[i].Write(s); 
	}
}
bool Materialise::ObjectProperties::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "ObjectProperties");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::CT_PropertyTreeWithUUID __t;
		if (__t.Read(s) == false)
			break;
		Instance.push_back(__t);
	}
	return true;
}
void Materialise::CT_MtlsPropertyTemplate::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "CT_MtlsPropertyTemplate");
	s.WriteAttr("version", Materialise::ConvertST_VersionToString(version.value()).c_str());
	MachineParameters.Write(s);
	BuildTicket.Write(s);
}
bool Materialise::CT_MtlsPropertyTemplate::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "CT_MtlsPropertyTemplate");
	if (scope.exist() == false)
		return false;
	version = Materialise::ConvertStringToST_Version(s.ReadAttrStr("version"));
	MachineParameters.Read(s);
	BuildTicket.Read(s);
	return true;
}
void Materialise::BuildTicket::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "BuildTicket");
	Defaults.Write(s);
	PartOverrides.value().get().Write(s);
}
bool Materialise::BuildTicket::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "BuildTicket");
	if (scope.exist() == false)
		return false;
	Defaults.Read(s);
	Materialise::CT_PropertyTemplateTree* __PartOverrides = new Materialise::CT_PropertyTemplateTree();
	__PartOverrides->Read(s);
	PartOverrides = std::optional<std::reference_wrapper<Materialise::CT_PropertyTemplateTree>> { *__PartOverrides };
	return true;
}
void Materialise::CT_Property::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "CT_Property");
	s.WriteAttr("Name", Name.c_str());
	s.WriteAttr("Type", Materialise::ConvertST_PropertyTypeToString(Type.value()).c_str());
	s.WriteAttr("ProfileList", ProfileList.value().c_str());
	for(int i = 0;i < Profile.size();i++)
	{
		Profile[i].Write(s); 
	}
	for(int i = 0;i < Property.size();i++)
	{
		Property[i].Write(s); 
	}
}
bool Materialise::CT_Property::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "CT_Property");
	if (scope.exist() == false)
		return false;
	Name = s.ReadAttrStr("Name");
	Type = Materialise::ConvertStringToST_PropertyType(s.ReadAttrStr("Type"));
	ProfileList = s.ReadAttrStr("ProfileList");
	while (true) { 
		Materialise::CT_ProfileWithProperties __t;
		if (__t.Read(s) == false)
			break;
		Profile.push_back(__t);
	}
	while (true) { 
		Materialise::CT_Property __t;
		if (__t.Read(s) == false)
			break;
		Property.push_back(__t);
	}
	return true;
}
void Materialise::CT_ProfileWithProperties::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "CT_ProfileWithProperties");
	s.WriteAttr("Name", Name.c_str());
	for(int i = 0;i < Property.size();i++)
	{
		Property[i].Write(s); 
	}
}
bool Materialise::CT_ProfileWithProperties::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "CT_ProfileWithProperties");
	if (scope.exist() == false)
		return false;
	Name = s.ReadAttrStr("Name");
	while (true) { 
		Materialise::CT_Property __t;
		if (__t.Read(s) == false)
			break;
		Property.push_back(__t);
	}
	return true;
}
void Materialise::CT_PropertyTemplateTree::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "CT_PropertyTemplateTree");
	for(int i = 0;i < PropertyNode.size();i++)
	{
		PropertyNode[i].Write(s); 
	}
}
bool Materialise::CT_PropertyTemplateTree::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "CT_PropertyTemplateTree");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::CT_PropertyTemplateNode __t;
		if (__t.Read(s) == false)
			break;
		PropertyNode.push_back(__t);
	}
	return true;
}
void Materialise::CT_PropertyTemplateNode::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "CT_PropertyTemplateNode");
	s.WriteAttr("Name", Name.c_str());
	s.WriteAttr("Type", Materialise::ConvertST_PropertyTypeToString(Type.value()).c_str());
	s.WriteAttr("DisplayName", DisplayName.value().c_str());
	s.WriteAttr("DisplayNameContainer", DisplayNameContainer.value().c_str());
	s.WriteAttr("PropertyName", PropertyName.value().c_str());
	s.WriteAttr("Default", Default.value().c_str());
	s.WriteAttr("ProfileList", ProfileList.value().c_str());
	s.WriteAttr("List", List.value().c_str());
	s.WriteAttr("ProfileName", ProfileName.value().c_str());
	for(int i = 0;i < PropertyNode.size();i++)
	{
		PropertyNode[i].Write(s); 
	}
}
bool Materialise::CT_PropertyTemplateNode::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "CT_PropertyTemplateNode");
	if (scope.exist() == false)
		return false;
	Name = s.ReadAttrStr("Name");
	Type = Materialise::ConvertStringToST_PropertyType(s.ReadAttrStr("Type"));
	DisplayName = s.ReadAttrStr("DisplayName");
	DisplayNameContainer = s.ReadAttrStr("DisplayNameContainer");
	PropertyName = s.ReadAttrStr("PropertyName");
	Default = s.ReadAttrStr("Default");
	ProfileList = s.ReadAttrStr("ProfileList");
	List = s.ReadAttrStr("List");
	ProfileName = s.ReadAttrStr("ProfileName");
	while (true) { 
		Materialise::CT_PropertyTemplateNode __t;
		if (__t.Read(s) == false)
			break;
		PropertyNode.push_back(__t);
	}
	return true;
}
void Materialise::CT_MtlsMachineInfo::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "CT_MtlsMachineInfo");
	s.WriteAttr("version", Materialise::ConvertST_VersionToString(version.value()).c_str());
	BuildVolume.Write(s);
	Tray.Write(s);
	LockedAreas.value().get().Write(s);
}
bool Materialise::CT_MtlsMachineInfo::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "CT_MtlsMachineInfo");
	if (scope.exist() == false)
		return false;
	version = Materialise::ConvertStringToST_Version(s.ReadAttrStr("version"));
	BuildVolume.Read(s);
	Tray.Read(s);
	Materialise::LockedAreas* __LockedAreas = new Materialise::LockedAreas();
	__LockedAreas->Read(s);
	LockedAreas = std::optional<std::reference_wrapper<Materialise::LockedAreas>> { *__LockedAreas };
	return true;
}
void Materialise::LockedAreas::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "LockedAreas");
	for(int i = 0;i < Area.size();i++)
	{
		s.Write("Area", Area[i].c_str()); 
	}
}
bool Materialise::LockedAreas::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "LockedAreas");
	if (scope.exist() == false)
		return false;
Area = s.ReadVectorStr("Area");
	return true;
}
void Materialise::CT_MtlsMachineInfoComponent::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "CT_MtlsMachineInfoComponent");
	s.WriteAttr("Shape", Materialise::ConvertShapeToString(Shape).c_str());
	Pos.Write(s);
	Dim.Write(s);
	Mesh.value().get().Write(s);
}
bool Materialise::CT_MtlsMachineInfoComponent::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "CT_MtlsMachineInfoComponent");
	if (scope.exist() == false)
		return false;
	Shape = Materialise::ConvertStringToShape(s.ReadAttrStr("Shape"));
	Pos.Read(s);
	Dim.Read(s);
	Materialise::Mesh* __Mesh = new Materialise::Mesh();
	__Mesh->Read(s);
	Mesh = std::optional<std::reference_wrapper<Materialise::Mesh>> { *__Mesh };
	return true;
}
void Materialise::Pos::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Pos");
	s.WriteAttr("x", x);
	s.WriteAttr("y", y);
	s.WriteAttr("z", z);
}
bool Materialise::Pos::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Pos");
	if (scope.exist() == false)
		return false;
	x = s.ReadAttrDouble("x");
	y = s.ReadAttrDouble("y");
	z = s.ReadAttrDouble("z");
	return true;
}
void Materialise::Dim::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Dim");
	s.WriteAttr("x", x.value());
	s.WriteAttr("y", y.value());
	s.WriteAttr("z", z);
	s.WriteAttr("radius", radius.value().c_str());
}
bool Materialise::Dim::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Dim");
	if (scope.exist() == false)
		return false;
	x = s.ReadAttrDouble("x");
	y = s.ReadAttrDouble("y");
	z = s.ReadAttrDouble("z");
	radius = s.ReadAttrStr("radius");
	return true;
}
void Materialise::Mesh::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Mesh");
	s.WriteAttr("uuid", uuid.c_str());
}
bool Materialise::Mesh::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Mesh");
	if (scope.exist() == false)
		return false;
	uuid = s.ReadAttrStr("uuid");
	return true;
}
void Materialise::MtlsBuildTicket::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "MtlsBuildTicket");
	s.WriteAttr("has_property_template", has_property_template.value());
	Info.Write(s);
	Defaults.value().get().Write(s);
	PartOverrides.value().get().Write(s);
	ObjectProperties.value().get().Write(s);
}
bool Materialise::MtlsBuildTicket::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "MtlsBuildTicket");
	if (scope.exist() == false)
		return false;
	has_property_template = s.ReadAttrBool("has_property_template");
	Info.Read(s);
	Materialise::CT_PropertyTree* __Defaults = new Materialise::CT_PropertyTree();
	__Defaults->Read(s);
	Defaults = std::optional<std::reference_wrapper<Materialise::CT_PropertyTree>> { *__Defaults };
	Materialise::PartOverrides* __PartOverrides = new Materialise::PartOverrides();
	__PartOverrides->Read(s);
	PartOverrides = std::optional<std::reference_wrapper<Materialise::PartOverrides>> { *__PartOverrides };
	Materialise::ObjectProperties* __ObjectProperties = new Materialise::ObjectProperties();
	__ObjectProperties->Read(s);
	ObjectProperties = std::optional<std::reference_wrapper<Materialise::ObjectProperties>> { *__ObjectProperties };
	return true;
}
void Materialise::MtlsMachineParameters::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "MtlsMachineParameters");
	s.WriteAttr("version", Materialise::ConvertST_VersionToString(version.value()).c_str());
	for(int i = 0;i < Property.size();i++)
	{
		Property[i].Write(s); 
	}
}
bool Materialise::MtlsMachineParameters::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "MtlsMachineParameters");
	if (scope.exist() == false)
		return false;
	version = Materialise::ConvertStringToST_Version(s.ReadAttrStr("version"));
	while (true) { 
		Materialise::CT_Property __t;
		if (__t.Read(s) == false)
			break;
		Property.push_back(__t);
	}
	return true;
}
void Materialise::MtlsPropertyTemplate::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "MtlsPropertyTemplate");
	s.WriteAttr("version", Materialise::ConvertST_VersionToString(version.value()).c_str());
	MachineParameters.Write(s);
	BuildTicket.Write(s);
}
bool Materialise::MtlsPropertyTemplate::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "MtlsPropertyTemplate");
	if (scope.exist() == false)
		return false;
	version = Materialise::ConvertStringToST_Version(s.ReadAttrStr("version"));
	MachineParameters.Read(s);
	BuildTicket.Read(s);
	return true;
}
void Materialise::MtlsMachineInfo::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "MtlsMachineInfo");
	s.WriteAttr("version", Materialise::ConvertST_VersionToString(version.value()).c_str());
	BuildVolume.Write(s);
	Tray.Write(s);
	LockedAreas.value().get().Write(s);
}
bool Materialise::MtlsMachineInfo::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "MtlsMachineInfo");
	if (scope.exist() == false)
		return false;
	version = Materialise::ConvertStringToST_Version(s.ReadAttrStr("version"));
	BuildVolume.Read(s);
	Tray.Read(s);
	Materialise::LockedAreas* __LockedAreas = new Materialise::LockedAreas();
	__LockedAreas->Read(s);
	LockedAreas = std::optional<std::reference_wrapper<Materialise::LockedAreas>> { *__LockedAreas };
	return true;
}
