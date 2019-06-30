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
		_enum,
		Complex,
		ProfileName,
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
		if (str == "enum") return ST_PropertyType::_enum;
		if (str == "Complex") return ST_PropertyType::Complex;
		if (str == "ProfileName") return ST_PropertyType::ProfileName;
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertST_PropertyTypeToString(ST_PropertyType e) {
		if (e == ST_PropertyType::_bool) return "bool";
		if (e == ST_PropertyType::integer) return "integer";
		if (e == ST_PropertyType::_unsigned) return "unsigned";
		if (e == ST_PropertyType::_string) return "string";
		if (e == ST_PropertyType::number) return "number";
		if (e == ST_PropertyType::_enum) return "enum";
		if (e == ST_PropertyType::Complex) return "Complex";
		if (e == ST_PropertyType::ProfileName) return "ProfileName";
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
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<double> x;
		std::optional<double> y;
		double z;
		std::optional<std::string> radius;
		Dim() {}
		~Dim() {}
	};
	struct Pos {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		double x;
		double y;
		double z;
		Pos() {}
		~Pos() {}
	};
	struct CT_MtlsMachineInfoComponent {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		Shape Shape;
		Materialise::Pos Pos;
		Materialise::Dim Dim;
		std::optional<std::reference_wrapper<Materialise::Mesh>> Mesh;
		bool Visible;
		CT_MtlsMachineInfoComponent() {}
		~CT_MtlsMachineInfoComponent() {}
	};
	struct CT_MtlsMachineInfo {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<Materialise::ST_Version> version;
		Materialise::CT_MtlsMachineInfoComponent BuildVolume;
		Materialise::CT_MtlsMachineInfoComponent Tray;
		std::optional<std::reference_wrapper<Materialise::LockedAreas>> LockedAreas;
		CT_MtlsMachineInfo() {}
		~CT_MtlsMachineInfo() {}
	};
	struct MtlsMachineInfo {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<Materialise::ST_Version> version;
		Materialise::CT_MtlsMachineInfoComponent BuildVolume;
		Materialise::CT_MtlsMachineInfoComponent Tray;
		std::optional<std::reference_wrapper<Materialise::LockedAreas>> LockedAreas;
		MtlsMachineInfo() {}
		~MtlsMachineInfo() {}
	};
	struct CT_PropertyTemplateTree {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::CT_PropertyTemplateNode> PropertyNode;
		CT_PropertyTemplateTree() {}
		~CT_PropertyTemplateTree() {}
	};
	struct BuildTicket {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		Materialise::CT_PropertyTemplateTree Defaults;
		std::optional<std::reference_wrapper<Materialise::CT_PropertyTemplateTree>> PartOverrides;
		BuildTicket() {}
		~BuildTicket() {}
	};
	struct CT_MtlsPropertyTemplate {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<Materialise::ST_Version> version;
		Materialise::CT_PropertyTemplateTree MachineParameters;
		Materialise::BuildTicket BuildTicket;
		CT_MtlsPropertyTemplate() {}
		~CT_MtlsPropertyTemplate() {}
	};
	struct MtlsPropertyTemplate {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<Materialise::ST_Version> version;
		Materialise::CT_PropertyTemplateTree MachineParameters;
		Materialise::BuildTicket BuildTicket;
		MtlsPropertyTemplate() {}
		~MtlsPropertyTemplate() {}
	};
	struct CT_PropertyTree {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::CT_Property> Property;
		CT_PropertyTree() {}
		~CT_PropertyTree() {}
	};
	struct MtlsMachineParameters {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<Materialise::ST_Version> version;
		std::vector<Materialise::CT_Property> Property;
		MtlsMachineParameters() {}
		~MtlsMachineParameters() {}
	};
	struct CT_BuildTicket {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<std::reference_wrapper<Materialise::CT_PropertyTree>> Defaults;
		std::optional<std::reference_wrapper<Materialise::PartOverrides>> PartOverrides;
		std::optional<std::reference_wrapper<Materialise::ObjectProperties>> ObjectProperties;
		CT_BuildTicket() {}
		~CT_BuildTicket() {}
	};
	struct MtlsBuildTicket {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<std::reference_wrapper<Materialise::CT_PropertyTree>> Defaults;
		std::optional<std::reference_wrapper<Materialise::PartOverrides>> PartOverrides;
		std::optional<std::reference_wrapper<Materialise::ObjectProperties>> ObjectProperties;
		MtlsBuildTicket() {}
		~MtlsBuildTicket() {}
	};
	struct Mesh {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string uuid;
		Mesh() {}
		~Mesh() {}
	};
	struct LockedAreas {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<std::string> Area;
		LockedAreas() {}
		~LockedAreas() {}
	};
	struct CT_PropertyTemplateNode {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string Name;
		std::optional<Materialise::ST_PropertyType> Type;
		std::optional<std::string> DisplayName;
		std::optional<std::string> DisplayNameContainer;
		std::optional<std::string> PropertyName;
		std::optional<std::string> Default;
		std::optional<std::string> ProfileList;
		std::optional<std::string> List;
		std::optional<std::string> ProfileName;
		std::vector<Materialise::CT_PropertyTemplateNode> PropertyNode;
		CT_PropertyTemplateNode() {}
		~CT_PropertyTemplateNode() {}
	};
	struct CT_ProfileWithProperties {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string Name;
		std::vector<Materialise::CT_Property> Property;
		CT_ProfileWithProperties() {}
		~CT_ProfileWithProperties() {}
	};
	struct CT_Property {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string Name;
		std::optional<Materialise::ST_PropertyType> Type;
		std::optional<std::string> ProfileList;
		std::vector<Materialise::CT_ProfileWithProperties> Profile;
		std::vector<Materialise::CT_Property> Property;
		CT_Property() {}
		~CT_Property() {}
	};
	struct ObjectProperties {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::CT_PropertyTreeWithUUID> Instance;
		ObjectProperties() {}
		~ObjectProperties() {}
	};
	struct PartOverrides {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::CT_PropertyTreeWithComponents> Instance;
		PartOverrides() {}
		~PartOverrides() {}
	};
	struct CT_PropertyTreeWithUUID {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string uuid;
		std::optional<Materialise::ST_PropertyTreeType> type;
		std::vector<Materialise::CT_Property> Property;
		CT_PropertyTreeWithUUID() {}
		~CT_PropertyTreeWithUUID() {}
	};
	struct CT_PropertyTreeWithComponents {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::CT_PropertyTreeWithUUID> Component;
		std::string uuid;
		std::optional<Materialise::ST_PropertyTreeType> type;
		std::vector<Materialise::CT_Property> Property;
		CT_PropertyTreeWithComponents() {}
		~CT_PropertyTreeWithComponents() {}
	};
}
void Materialise::CT_PropertyTree::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < Property.size();i++)
	{
		Property[i].Write(s, "Property"); 
	}
}
bool Materialise::CT_PropertyTree::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::CT_Property __t;
		if (__t.Read(s, "Property") == false)
			break;
		Property.push_back(__t);
	}
	return true;
}
void Materialise::CT_PropertyTreeWithUUID::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("uuid", uuid.c_str());
	if (type.has_value())
		s.WriteAttr("type", Materialise::ConvertST_PropertyTreeTypeToString(type.value()).c_str());
	for(int i = 0;i < Property.size();i++)
	{
		Property[i].Write(s, "Property"); 
	}
}
bool Materialise::CT_PropertyTreeWithUUID::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	std::string __tmp_var;
	s.ReadAttrStr("uuid", uuid);
	if (s.ReadAttrStr("type", __tmp_var)) 
		type = Materialise::ConvertStringToST_PropertyTreeType(__tmp_var);
	while (true) { 
		Materialise::CT_Property __t;
		if (__t.Read(s, "Property") == false)
			break;
		Property.push_back(__t);
	}
	return true;
}
void Materialise::CT_PropertyTreeWithComponents::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < Component.size();i++)
	{
		Component[i].Write(s, "Component"); 
	}
	s.WriteAttr("uuid", uuid.c_str());
	if (type.has_value())
		s.WriteAttr("type", Materialise::ConvertST_PropertyTreeTypeToString(type.value()).c_str());
	for(int i = 0;i < Property.size();i++)
	{
		Property[i].Write(s, "Property"); 
	}
}
bool Materialise::CT_PropertyTreeWithComponents::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	std::string __tmp_var;
	while (true) { 
		Materialise::CT_PropertyTreeWithUUID __t;
		if (__t.Read(s, "Component") == false)
			break;
		Component.push_back(__t);
	}
	s.ReadAttrStr("uuid", uuid);
	if (s.ReadAttrStr("type", __tmp_var)) 
		type = Materialise::ConvertStringToST_PropertyTreeType(__tmp_var);
	while (true) { 
		Materialise::CT_Property __t;
		if (__t.Read(s, "Property") == false)
			break;
		Property.push_back(__t);
	}
	return true;
}
void Materialise::CT_BuildTicket::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (Defaults.has_value())
		Defaults.value().get().Write(s, "Defaults");
	if (PartOverrides.has_value())
		PartOverrides.value().get().Write(s, "PartOverrides");
	if (ObjectProperties.has_value())
		ObjectProperties.value().get().Write(s, "ObjectProperties");
}
bool Materialise::CT_BuildTicket::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	Materialise::CT_PropertyTree* __Defaults = new Materialise::CT_PropertyTree();
	__Defaults->Read(s, "Defaults");
	Defaults = std::optional<std::reference_wrapper<Materialise::CT_PropertyTree>> { *__Defaults };
	Materialise::PartOverrides* __PartOverrides = new Materialise::PartOverrides();
	__PartOverrides->Read(s, "PartOverrides");
	PartOverrides = std::optional<std::reference_wrapper<Materialise::PartOverrides>> { *__PartOverrides };
	Materialise::ObjectProperties* __ObjectProperties = new Materialise::ObjectProperties();
	__ObjectProperties->Read(s, "ObjectProperties");
	ObjectProperties = std::optional<std::reference_wrapper<Materialise::ObjectProperties>> { *__ObjectProperties };
	return true;
}
void Materialise::PartOverrides::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < Instance.size();i++)
	{
		Instance[i].Write(s, "Instance"); 
	}
}
bool Materialise::PartOverrides::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::CT_PropertyTreeWithComponents __t;
		if (__t.Read(s, "Instance") == false)
			break;
		Instance.push_back(__t);
	}
	return true;
}
void Materialise::ObjectProperties::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < Instance.size();i++)
	{
		Instance[i].Write(s, "Instance"); 
	}
}
bool Materialise::ObjectProperties::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::CT_PropertyTreeWithUUID __t;
		if (__t.Read(s, "Instance") == false)
			break;
		Instance.push_back(__t);
	}
	return true;
}
void Materialise::CT_MtlsPropertyTemplate::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (version.has_value())
		s.WriteAttr("version", Materialise::ConvertST_VersionToString(version.value()).c_str());
	MachineParameters.Write(s, "MachineParameters");
	BuildTicket.Write(s, "BuildTicket");
}
bool Materialise::CT_MtlsPropertyTemplate::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	std::string __tmp_var;
	if (s.ReadAttrStr("version", __tmp_var)) 
		version = Materialise::ConvertStringToST_Version(__tmp_var);
	MachineParameters.Read(s, "MachineParameters");
	BuildTicket.Read(s, "BuildTicket");
	return true;
}
void Materialise::BuildTicket::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	Defaults.Write(s, "Defaults");
	if (PartOverrides.has_value())
		PartOverrides.value().get().Write(s, "PartOverrides");
}
bool Materialise::BuildTicket::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	Defaults.Read(s, "Defaults");
	Materialise::CT_PropertyTemplateTree* __PartOverrides = new Materialise::CT_PropertyTemplateTree();
	__PartOverrides->Read(s, "PartOverrides");
	PartOverrides = std::optional<std::reference_wrapper<Materialise::CT_PropertyTemplateTree>> { *__PartOverrides };
	return true;
}
void Materialise::CT_Property::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Name", Name.c_str());
	if (Type.has_value())
		s.WriteAttr("Type", Materialise::ConvertST_PropertyTypeToString(Type.value()).c_str());
	if (ProfileList.has_value())
		s.WriteAttr("ProfileList", ProfileList.value().c_str());
	for(int i = 0;i < Profile.size();i++)
	{
		Profile[i].Write(s, "Profile"); 
	}
	for(int i = 0;i < Property.size();i++)
	{
		Property[i].Write(s, "Property"); 
	}
}
bool Materialise::CT_Property::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	std::string __tmp_var;
	s.ReadAttrStr("Name", Name);
	if (s.ReadAttrStr("Type", __tmp_var)) 
		Type = Materialise::ConvertStringToST_PropertyType(__tmp_var);
	s.ReadAttrStr("ProfileList", ProfileList.value());
	while (true) { 
		Materialise::CT_ProfileWithProperties __t;
		if (__t.Read(s, "Profile") == false)
			break;
		Profile.push_back(__t);
	}
	while (true) { 
		Materialise::CT_Property __t;
		if (__t.Read(s, "Property") == false)
			break;
		Property.push_back(__t);
	}
	return true;
}
void Materialise::CT_ProfileWithProperties::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Name", Name.c_str());
	for(int i = 0;i < Property.size();i++)
	{
		Property[i].Write(s, "Property"); 
	}
}
bool Materialise::CT_ProfileWithProperties::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("Name", Name);
	while (true) { 
		Materialise::CT_Property __t;
		if (__t.Read(s, "Property") == false)
			break;
		Property.push_back(__t);
	}
	return true;
}
void Materialise::CT_PropertyTemplateTree::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < PropertyNode.size();i++)
	{
		PropertyNode[i].Write(s, "PropertyNode"); 
	}
}
bool Materialise::CT_PropertyTemplateTree::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::CT_PropertyTemplateNode __t;
		if (__t.Read(s, "PropertyNode") == false)
			break;
		PropertyNode.push_back(__t);
	}
	return true;
}
void Materialise::CT_PropertyTemplateNode::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Name", Name.c_str());
	if (Type.has_value())
		s.WriteAttr("Type", Materialise::ConvertST_PropertyTypeToString(Type.value()).c_str());
	if (DisplayName.has_value())
		s.WriteAttr("DisplayName", DisplayName.value().c_str());
	if (DisplayNameContainer.has_value())
		s.WriteAttr("DisplayNameContainer", DisplayNameContainer.value().c_str());
	if (PropertyName.has_value())
		s.WriteAttr("PropertyName", PropertyName.value().c_str());
	if (Default.has_value())
		s.WriteAttr("Default", Default.value().c_str());
	if (ProfileList.has_value())
		s.WriteAttr("ProfileList", ProfileList.value().c_str());
	if (List.has_value())
		s.WriteAttr("List", List.value().c_str());
	if (ProfileName.has_value())
		s.WriteAttr("ProfileName", ProfileName.value().c_str());
	for(int i = 0;i < PropertyNode.size();i++)
	{
		PropertyNode[i].Write(s, "PropertyNode"); 
	}
}
bool Materialise::CT_PropertyTemplateNode::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	std::string __tmp_var;
	s.ReadAttrStr("Name", Name);
	if (s.ReadAttrStr("Type", __tmp_var)) 
		Type = Materialise::ConvertStringToST_PropertyType(__tmp_var);
	s.ReadAttrStr("DisplayName", DisplayName.value());
	s.ReadAttrStr("DisplayNameContainer", DisplayNameContainer.value());
	s.ReadAttrStr("PropertyName", PropertyName.value());
	s.ReadAttrStr("Default", Default.value());
	s.ReadAttrStr("ProfileList", ProfileList.value());
	s.ReadAttrStr("List", List.value());
	s.ReadAttrStr("ProfileName", ProfileName.value());
	while (true) { 
		Materialise::CT_PropertyTemplateNode __t;
		if (__t.Read(s, "PropertyNode") == false)
			break;
		PropertyNode.push_back(__t);
	}
	return true;
}
void Materialise::CT_MtlsMachineInfo::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (version.has_value())
		s.WriteAttr("version", Materialise::ConvertST_VersionToString(version.value()).c_str());
	BuildVolume.Write(s, "BuildVolume");
	Tray.Write(s, "Tray");
	if (LockedAreas.has_value())
		LockedAreas.value().get().Write(s, "LockedAreas");
}
bool Materialise::CT_MtlsMachineInfo::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	std::string __tmp_var;
	if (s.ReadAttrStr("version", __tmp_var)) 
		version = Materialise::ConvertStringToST_Version(__tmp_var);
	BuildVolume.Read(s, "BuildVolume");
	Tray.Read(s, "Tray");
	Materialise::LockedAreas* __LockedAreas = new Materialise::LockedAreas();
	__LockedAreas->Read(s, "LockedAreas");
	LockedAreas = std::optional<std::reference_wrapper<Materialise::LockedAreas>> { *__LockedAreas };
	return true;
}
void Materialise::LockedAreas::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < Area.size();i++)
	{
		s.Write("Area", Area[i].c_str()); 
	}
}
bool Materialise::LockedAreas::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
Area = s.ReadVectorStr("Area");
	return true;
}
void Materialise::CT_MtlsMachineInfoComponent::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Shape", Materialise::ConvertShapeToString(Shape).c_str());
	Pos.Write(s, "Pos");
	Dim.Write(s, "Dim");
	if (Mesh.has_value())
		Mesh.value().get().Write(s, "Mesh");
	s.Write("Visible", Visible);
}
bool Materialise::CT_MtlsMachineInfoComponent::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	std::string __tmp_var;
	if (s.ReadAttrStr("Shape", __tmp_var)) 
		Shape = Materialise::ConvertStringToShape(__tmp_var);
	Pos.Read(s, "Pos");
	Dim.Read(s, "Dim");
	Materialise::Mesh* __Mesh = new Materialise::Mesh();
	__Mesh->Read(s, "Mesh");
	Mesh = std::optional<std::reference_wrapper<Materialise::Mesh>> { *__Mesh };
	s.ReadBool("Visible", Visible);
	return true;
}
void Materialise::Pos::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("x", x);
	s.WriteAttr("y", y);
	s.WriteAttr("z", z);
}
bool Materialise::Pos::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrDouble("x", x);
	s.ReadAttrDouble("y", y);
	s.ReadAttrDouble("z", z);
	return true;
}
void Materialise::Dim::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (x.has_value())
		s.WriteAttr("x", x.value());
	if (y.has_value())
		s.WriteAttr("y", y.value());
	s.WriteAttr("z", z);
	if (radius.has_value())
		s.WriteAttr("radius", radius.value().c_str());
}
bool Materialise::Dim::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrDouble("x", x.value());
	s.ReadAttrDouble("y", y.value());
	s.ReadAttrDouble("z", z);
	s.ReadAttrStr("radius", radius.value());
	return true;
}
void Materialise::Mesh::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("uuid", uuid.c_str());
}
bool Materialise::Mesh::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("uuid", uuid);
	return true;
}
void Materialise::MtlsBuildTicket::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (Defaults.has_value())
		Defaults.value().get().Write(s, "Defaults");
	if (PartOverrides.has_value())
		PartOverrides.value().get().Write(s, "PartOverrides");
	if (ObjectProperties.has_value())
		ObjectProperties.value().get().Write(s, "ObjectProperties");
}
bool Materialise::MtlsBuildTicket::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	Materialise::CT_PropertyTree* __Defaults = new Materialise::CT_PropertyTree();
	__Defaults->Read(s, "Defaults");
	Defaults = std::optional<std::reference_wrapper<Materialise::CT_PropertyTree>> { *__Defaults };
	Materialise::PartOverrides* __PartOverrides = new Materialise::PartOverrides();
	__PartOverrides->Read(s, "PartOverrides");
	PartOverrides = std::optional<std::reference_wrapper<Materialise::PartOverrides>> { *__PartOverrides };
	Materialise::ObjectProperties* __ObjectProperties = new Materialise::ObjectProperties();
	__ObjectProperties->Read(s, "ObjectProperties");
	ObjectProperties = std::optional<std::reference_wrapper<Materialise::ObjectProperties>> { *__ObjectProperties };
	return true;
}
void Materialise::MtlsMachineParameters::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (version.has_value())
		s.WriteAttr("version", Materialise::ConvertST_VersionToString(version.value()).c_str());
	for(int i = 0;i < Property.size();i++)
	{
		Property[i].Write(s, "Property"); 
	}
}
bool Materialise::MtlsMachineParameters::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	std::string __tmp_var;
	if (s.ReadAttrStr("version", __tmp_var)) 
		version = Materialise::ConvertStringToST_Version(__tmp_var);
	while (true) { 
		Materialise::CT_Property __t;
		if (__t.Read(s, "Property") == false)
			break;
		Property.push_back(__t);
	}
	return true;
}
void Materialise::MtlsPropertyTemplate::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (version.has_value())
		s.WriteAttr("version", Materialise::ConvertST_VersionToString(version.value()).c_str());
	MachineParameters.Write(s, "MachineParameters");
	BuildTicket.Write(s, "BuildTicket");
}
bool Materialise::MtlsPropertyTemplate::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	std::string __tmp_var;
	if (s.ReadAttrStr("version", __tmp_var)) 
		version = Materialise::ConvertStringToST_Version(__tmp_var);
	MachineParameters.Read(s, "MachineParameters");
	BuildTicket.Read(s, "BuildTicket");
	return true;
}
void Materialise::MtlsMachineInfo::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (version.has_value())
		s.WriteAttr("version", Materialise::ConvertST_VersionToString(version.value()).c_str());
	BuildVolume.Write(s, "BuildVolume");
	Tray.Write(s, "Tray");
	if (LockedAreas.has_value())
		LockedAreas.value().get().Write(s, "LockedAreas");
}
bool Materialise::MtlsMachineInfo::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	std::string __tmp_var;
	if (s.ReadAttrStr("version", __tmp_var)) 
		version = Materialise::ConvertStringToST_Version(__tmp_var);
	BuildVolume.Read(s, "BuildVolume");
	Tray.Read(s, "Tray");
	Materialise::LockedAreas* __LockedAreas = new Materialise::LockedAreas();
	__LockedAreas->Read(s, "LockedAreas");
	LockedAreas = std::optional<std::reference_wrapper<Materialise::LockedAreas>> { *__LockedAreas };
	return true;
}
