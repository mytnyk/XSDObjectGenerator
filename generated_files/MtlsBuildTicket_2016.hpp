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
	const std::string schema_generated_files_MtlsBuildTicket_2016_namespace = "http://schemas.materialise.com/build_processing/2016/04";
	enum class ST_Version {
		_1_0,
	};

	enum class Shape {
		box,
		cylinder,
		custom,
	};

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

	ST_Version ConvertStringToST_Version(std::string str) {
		if (str == "1.0") return ST_Version::_1_0;
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertST_VersionToString(ST_Version e) {
		if (e == ST_Version::_1_0) return "1.0";
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
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Dim(const Dim&) = delete;
		Dim& operator=(Dim&&) = delete;
		Dim& operator=(Dim&) = delete;
		Dim(Dim&&) noexcept;
		Dim() = default;
		~Dim() = default;
		std::optional<double> x;
		std::optional<double> y;
		double z;
		std::optional<std::string> radius;
	};
	struct Pos {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Pos(const Pos&) = delete;
		Pos& operator=(Pos&&) = delete;
		Pos& operator=(Pos&) = delete;
		Pos(Pos&&) noexcept;
		Pos() = default;
		~Pos() = default;
		double x;
		double y;
		double z;
	};
	struct CT_MtlsMachineInfoComponent {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_MtlsMachineInfoComponent(const CT_MtlsMachineInfoComponent&) = delete;
		CT_MtlsMachineInfoComponent& operator=(CT_MtlsMachineInfoComponent&&) = delete;
		CT_MtlsMachineInfoComponent& operator=(CT_MtlsMachineInfoComponent&) = delete;
		CT_MtlsMachineInfoComponent(CT_MtlsMachineInfoComponent&&) noexcept;
		CT_MtlsMachineInfoComponent() = default;
		~CT_MtlsMachineInfoComponent() = default;
		Shape Shape;
		Pos Pos;
		Dim Dim;
		std::optional<std::unique_ptr<Mesh>> Mesh;
		bool Visible;
	};
	struct CT_MtlsMachineInfo {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_MtlsMachineInfo(const CT_MtlsMachineInfo&) = delete;
		CT_MtlsMachineInfo& operator=(CT_MtlsMachineInfo&&) = delete;
		CT_MtlsMachineInfo& operator=(CT_MtlsMachineInfo&) = delete;
		CT_MtlsMachineInfo(CT_MtlsMachineInfo&&) noexcept;
		CT_MtlsMachineInfo() = default;
		~CT_MtlsMachineInfo() = default;
		std::optional<ST_Version> version;
		CT_MtlsMachineInfoComponent BuildVolume;
		CT_MtlsMachineInfoComponent Tray;
		std::optional<std::unique_ptr<LockedAreas>> LockedAreas;
	};
	struct MtlsMachineInfo {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		MtlsMachineInfo(const MtlsMachineInfo&) = delete;
		MtlsMachineInfo& operator=(MtlsMachineInfo&&) = delete;
		MtlsMachineInfo& operator=(MtlsMachineInfo&) = delete;
		MtlsMachineInfo(MtlsMachineInfo&&) noexcept;
		MtlsMachineInfo() = default;
		~MtlsMachineInfo() = default;
		std::optional<ST_Version> version;
		CT_MtlsMachineInfoComponent BuildVolume;
		CT_MtlsMachineInfoComponent Tray;
		std::optional<std::unique_ptr<LockedAreas>> LockedAreas;
	};
	struct CT_PropertyTemplateTree {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_PropertyTemplateTree(const CT_PropertyTemplateTree&) = delete;
		CT_PropertyTemplateTree& operator=(CT_PropertyTemplateTree&&) = delete;
		CT_PropertyTemplateTree& operator=(CT_PropertyTemplateTree&) = delete;
		CT_PropertyTemplateTree(CT_PropertyTemplateTree&&) noexcept;
		CT_PropertyTemplateTree() = default;
		~CT_PropertyTemplateTree() = default;
		std::vector<CT_PropertyTemplateNode> PropertyNode;
	};
	struct BuildTicket {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		BuildTicket(const BuildTicket&) = delete;
		BuildTicket& operator=(BuildTicket&&) = delete;
		BuildTicket& operator=(BuildTicket&) = delete;
		BuildTicket(BuildTicket&&) noexcept;
		BuildTicket() = default;
		~BuildTicket() = default;
		CT_PropertyTemplateTree Defaults;
		std::optional<std::unique_ptr<CT_PropertyTemplateTree>> PartOverrides;
	};
	struct CT_MtlsPropertyTemplate {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_MtlsPropertyTemplate(const CT_MtlsPropertyTemplate&) = delete;
		CT_MtlsPropertyTemplate& operator=(CT_MtlsPropertyTemplate&&) = delete;
		CT_MtlsPropertyTemplate& operator=(CT_MtlsPropertyTemplate&) = delete;
		CT_MtlsPropertyTemplate(CT_MtlsPropertyTemplate&&) noexcept;
		CT_MtlsPropertyTemplate() = default;
		~CT_MtlsPropertyTemplate() = default;
		std::optional<ST_Version> version;
		CT_PropertyTemplateTree MachineParameters;
		BuildTicket BuildTicket;
	};
	struct MtlsPropertyTemplate {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		MtlsPropertyTemplate(const MtlsPropertyTemplate&) = delete;
		MtlsPropertyTemplate& operator=(MtlsPropertyTemplate&&) = delete;
		MtlsPropertyTemplate& operator=(MtlsPropertyTemplate&) = delete;
		MtlsPropertyTemplate(MtlsPropertyTemplate&&) noexcept;
		MtlsPropertyTemplate() = default;
		~MtlsPropertyTemplate() = default;
		std::optional<ST_Version> version;
		CT_PropertyTemplateTree MachineParameters;
		BuildTicket BuildTicket;
	};
	struct CT_PropertyTree {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_PropertyTree(const CT_PropertyTree&) = delete;
		CT_PropertyTree& operator=(CT_PropertyTree&&) = delete;
		CT_PropertyTree& operator=(CT_PropertyTree&) = delete;
		CT_PropertyTree(CT_PropertyTree&&) noexcept;
		CT_PropertyTree() = default;
		~CT_PropertyTree() = default;
		std::vector<CT_Property> Property;
	};
	struct MtlsMachineParameters {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		MtlsMachineParameters(const MtlsMachineParameters&) = delete;
		MtlsMachineParameters& operator=(MtlsMachineParameters&&) = delete;
		MtlsMachineParameters& operator=(MtlsMachineParameters&) = delete;
		MtlsMachineParameters(MtlsMachineParameters&&) noexcept;
		MtlsMachineParameters() = default;
		~MtlsMachineParameters() = default;
		std::optional<ST_Version> version;
		std::vector<CT_Property> Property;
	};
	struct CT_BuildTicket {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_BuildTicket(const CT_BuildTicket&) = delete;
		CT_BuildTicket& operator=(CT_BuildTicket&&) = delete;
		CT_BuildTicket& operator=(CT_BuildTicket&) = delete;
		CT_BuildTicket(CT_BuildTicket&&) noexcept;
		CT_BuildTicket() = default;
		~CT_BuildTicket() = default;
		std::optional<std::unique_ptr<CT_PropertyTree>> Defaults;
		std::optional<std::unique_ptr<PartOverrides>> PartOverrides;
		std::optional<std::unique_ptr<ObjectProperties>> ObjectProperties;
	};
	struct MtlsBuildTicket {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		MtlsBuildTicket(const MtlsBuildTicket&) = delete;
		MtlsBuildTicket& operator=(MtlsBuildTicket&&) = delete;
		MtlsBuildTicket& operator=(MtlsBuildTicket&) = delete;
		MtlsBuildTicket(MtlsBuildTicket&&) noexcept;
		MtlsBuildTicket() = default;
		~MtlsBuildTicket() = default;
		std::optional<std::unique_ptr<CT_PropertyTree>> Defaults;
		std::optional<std::unique_ptr<PartOverrides>> PartOverrides;
		std::optional<std::unique_ptr<ObjectProperties>> ObjectProperties;
	};
	struct Mesh {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Mesh(const Mesh&) = delete;
		Mesh& operator=(Mesh&&) = delete;
		Mesh& operator=(Mesh&) = delete;
		Mesh(Mesh&&) noexcept;
		Mesh() = default;
		~Mesh() = default;
		std::string uuid;
	};
	struct LockedAreas {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		LockedAreas(const LockedAreas&) = delete;
		LockedAreas& operator=(LockedAreas&&) = delete;
		LockedAreas& operator=(LockedAreas&) = delete;
		LockedAreas(LockedAreas&&) noexcept;
		LockedAreas() = default;
		~LockedAreas() = default;
		std::vector<std::string> Area;
	};
	struct CT_PropertyTemplateNode {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_PropertyTemplateNode(const CT_PropertyTemplateNode&) = delete;
		CT_PropertyTemplateNode& operator=(CT_PropertyTemplateNode&&) = delete;
		CT_PropertyTemplateNode& operator=(CT_PropertyTemplateNode&) = delete;
		CT_PropertyTemplateNode(CT_PropertyTemplateNode&&) noexcept;
		CT_PropertyTemplateNode() = default;
		~CT_PropertyTemplateNode() = default;
		std::string Name;
		std::optional<ST_PropertyType> Type;
		std::optional<std::string> DisplayName;
		std::optional<std::string> DisplayNameContainer;
		std::optional<std::string> PropertyName;
		std::optional<std::string> Default;
		std::optional<std::string> ProfileList;
		std::optional<std::string> List;
		std::optional<std::string> ProfileName;
		std::vector<CT_PropertyTemplateNode> PropertyNode;
	};
	struct CT_ProfileWithProperties {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_ProfileWithProperties(const CT_ProfileWithProperties&) = delete;
		CT_ProfileWithProperties& operator=(CT_ProfileWithProperties&&) = delete;
		CT_ProfileWithProperties& operator=(CT_ProfileWithProperties&) = delete;
		CT_ProfileWithProperties(CT_ProfileWithProperties&&) noexcept;
		CT_ProfileWithProperties() = default;
		~CT_ProfileWithProperties() = default;
		std::string Name;
		std::vector<CT_Property> Property;
	};
	struct CT_Property {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Property(const CT_Property&) = delete;
		CT_Property& operator=(CT_Property&&) = delete;
		CT_Property& operator=(CT_Property&) = delete;
		CT_Property(CT_Property&&) noexcept;
		CT_Property() = default;
		~CT_Property() = default;
		std::string Name;
		std::optional<ST_PropertyType> Type;
		std::optional<std::string> ProfileList;
		std::vector<CT_ProfileWithProperties> Profile;
		std::vector<CT_Property> Property;
	};
	struct ObjectProperties {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		ObjectProperties(const ObjectProperties&) = delete;
		ObjectProperties& operator=(ObjectProperties&&) = delete;
		ObjectProperties& operator=(ObjectProperties&) = delete;
		ObjectProperties(ObjectProperties&&) noexcept;
		ObjectProperties() = default;
		~ObjectProperties() = default;
		std::vector<CT_PropertyTreeWithUUID> Instance;
	};
	struct PartOverrides {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		PartOverrides(const PartOverrides&) = delete;
		PartOverrides& operator=(PartOverrides&&) = delete;
		PartOverrides& operator=(PartOverrides&) = delete;
		PartOverrides(PartOverrides&&) noexcept;
		PartOverrides() = default;
		~PartOverrides() = default;
		std::vector<CT_PropertyTreeWithComponents> Instance;
	};
	struct CT_PropertyTreeWithUUID {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_PropertyTreeWithUUID(const CT_PropertyTreeWithUUID&) = delete;
		CT_PropertyTreeWithUUID& operator=(CT_PropertyTreeWithUUID&&) = delete;
		CT_PropertyTreeWithUUID& operator=(CT_PropertyTreeWithUUID&) = delete;
		CT_PropertyTreeWithUUID(CT_PropertyTreeWithUUID&&) noexcept;
		CT_PropertyTreeWithUUID() = default;
		~CT_PropertyTreeWithUUID() = default;
		std::string uuid;
		std::optional<ST_PropertyTreeType> type;
		std::vector<CT_Property> Property;
	};
	struct CT_PropertyTreeWithComponents {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_PropertyTreeWithComponents(const CT_PropertyTreeWithComponents&) = delete;
		CT_PropertyTreeWithComponents& operator=(CT_PropertyTreeWithComponents&&) = delete;
		CT_PropertyTreeWithComponents& operator=(CT_PropertyTreeWithComponents&) = delete;
		CT_PropertyTreeWithComponents(CT_PropertyTreeWithComponents&&) noexcept;
		CT_PropertyTreeWithComponents() = default;
		~CT_PropertyTreeWithComponents() = default;
		std::vector<CT_PropertyTreeWithUUID> Component;
		std::string uuid;
		std::optional<ST_PropertyTreeType> type;
		std::vector<CT_Property> Property;
	};
}
Materialise::CT_PropertyTree::CT_PropertyTree(Materialise::CT_PropertyTree &&___CT_PropertyTree) noexcept
	: Property(std::move(___CT_PropertyTree.Property))
{ }
void Materialise::CT_PropertyTree::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Property)
	{
		element.Write(s, "Property"); 
	}
}
bool Materialise::CT_PropertyTree::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::CT_Property __t;
		if (!__t.Read(s, "Property"))
			break;
		Property.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_PropertyTreeWithUUID::CT_PropertyTreeWithUUID(Materialise::CT_PropertyTreeWithUUID &&___CT_PropertyTreeWithUUID) noexcept
	: uuid(___CT_PropertyTreeWithUUID.uuid)
	, type(___CT_PropertyTreeWithUUID.type)
	, Property(std::move(___CT_PropertyTreeWithUUID.Property))
{ }
void Materialise::CT_PropertyTreeWithUUID::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("uuid", uuid.c_str());
	if (type.has_value())
		s.WriteAttr("type", Materialise::ConvertST_PropertyTreeTypeToString(type.value()).c_str());
	for(auto&& element : Property)
	{
		element.Write(s, "Property"); 
	}
}
bool Materialise::CT_PropertyTreeWithUUID::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	s.ReadAttrStr("uuid", uuid);
	if (s.ReadAttrStr("type", __tmp_var)) 
		type = Materialise::ConvertStringToST_PropertyTreeType(__tmp_var);
	while (true) { 
		Materialise::CT_Property __t;
		if (!__t.Read(s, "Property"))
			break;
		Property.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_PropertyTreeWithComponents::CT_PropertyTreeWithComponents(Materialise::CT_PropertyTreeWithComponents &&___CT_PropertyTreeWithComponents) noexcept
	: Component(std::move(___CT_PropertyTreeWithComponents.Component))
	, uuid(___CT_PropertyTreeWithComponents.uuid)
	, type(___CT_PropertyTreeWithComponents.type)
	, Property(std::move(___CT_PropertyTreeWithComponents.Property))
{ }
void Materialise::CT_PropertyTreeWithComponents::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Component)
	{
		element.Write(s, "Component"); 
	}
	s.WriteAttr("uuid", uuid.c_str());
	if (type.has_value())
		s.WriteAttr("type", Materialise::ConvertST_PropertyTreeTypeToString(type.value()).c_str());
	for(auto&& element : Property)
	{
		element.Write(s, "Property"); 
	}
}
bool Materialise::CT_PropertyTreeWithComponents::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	while (true) { 
		Materialise::CT_PropertyTreeWithUUID __t;
		if (!__t.Read(s, "Component"))
			break;
		Component.push_back(std::move(__t));
	}
	s.ReadAttrStr("uuid", uuid);
	if (s.ReadAttrStr("type", __tmp_var)) 
		type = Materialise::ConvertStringToST_PropertyTreeType(__tmp_var);
	while (true) { 
		Materialise::CT_Property __t;
		if (!__t.Read(s, "Property"))
			break;
		Property.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_BuildTicket::CT_BuildTicket(Materialise::CT_BuildTicket &&___CT_BuildTicket) noexcept
	: Defaults(std::move(___CT_BuildTicket.Defaults))
	, PartOverrides(std::move(___CT_BuildTicket.PartOverrides))
	, ObjectProperties(std::move(___CT_BuildTicket.ObjectProperties))
{ }
void Materialise::CT_BuildTicket::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (Defaults.has_value())
		Defaults.value().get()->Write(s, "Defaults");
	if (PartOverrides.has_value())
		PartOverrides.value().get()->Write(s, "PartOverrides");
	if (ObjectProperties.has_value())
		ObjectProperties.value().get()->Write(s, "ObjectProperties");
}
bool Materialise::CT_BuildTicket::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::unique_ptr<Materialise::CT_PropertyTree> __Defaults = std::make_unique<Materialise::CT_PropertyTree>();
	if (__Defaults->Read(s, "Defaults"))
		Defaults = std::make_optional(std::move(__Defaults));
	std::unique_ptr<Materialise::PartOverrides> __PartOverrides = std::make_unique<Materialise::PartOverrides>();
	if (__PartOverrides->Read(s, "PartOverrides"))
		PartOverrides = std::make_optional(std::move(__PartOverrides));
	std::unique_ptr<Materialise::ObjectProperties> __ObjectProperties = std::make_unique<Materialise::ObjectProperties>();
	if (__ObjectProperties->Read(s, "ObjectProperties"))
		ObjectProperties = std::make_optional(std::move(__ObjectProperties));
	return true;
}
Materialise::PartOverrides::PartOverrides(Materialise::PartOverrides &&___PartOverrides) noexcept
	: Instance(std::move(___PartOverrides.Instance))
{ }
void Materialise::PartOverrides::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Instance)
	{
		element.Write(s, "Instance"); 
	}
}
bool Materialise::PartOverrides::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::CT_PropertyTreeWithComponents __t;
		if (!__t.Read(s, "Instance"))
			break;
		Instance.push_back(std::move(__t));
	}
	return true;
}
Materialise::ObjectProperties::ObjectProperties(Materialise::ObjectProperties &&___ObjectProperties) noexcept
	: Instance(std::move(___ObjectProperties.Instance))
{ }
void Materialise::ObjectProperties::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Instance)
	{
		element.Write(s, "Instance"); 
	}
}
bool Materialise::ObjectProperties::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::CT_PropertyTreeWithUUID __t;
		if (!__t.Read(s, "Instance"))
			break;
		Instance.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_MtlsPropertyTemplate::CT_MtlsPropertyTemplate(Materialise::CT_MtlsPropertyTemplate &&___CT_MtlsPropertyTemplate) noexcept
	: version(___CT_MtlsPropertyTemplate.version)
	, MachineParameters(std::move(___CT_MtlsPropertyTemplate.MachineParameters))
	, BuildTicket(std::move(___CT_MtlsPropertyTemplate.BuildTicket))
{ }
void Materialise::CT_MtlsPropertyTemplate::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (version.has_value())
		s.WriteAttr("version", Materialise::ConvertST_VersionToString(version.value()).c_str());
	MachineParameters.Write(s, "MachineParameters");
	BuildTicket.Write(s, "BuildTicket");
}
bool Materialise::CT_MtlsPropertyTemplate::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	if (s.ReadAttrStr("version", __tmp_var)) 
		version = Materialise::ConvertStringToST_Version(__tmp_var);
	MachineParameters.Read(s, "MachineParameters");
	BuildTicket.Read(s, "BuildTicket");
	return true;
}
Materialise::BuildTicket::BuildTicket(Materialise::BuildTicket &&___BuildTicket) noexcept
	: Defaults(std::move(___BuildTicket.Defaults))
	, PartOverrides(std::move(___BuildTicket.PartOverrides))
{ }
void Materialise::BuildTicket::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	Defaults.Write(s, "Defaults");
	if (PartOverrides.has_value())
		PartOverrides.value().get()->Write(s, "PartOverrides");
}
bool Materialise::BuildTicket::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	Defaults.Read(s, "Defaults");
	std::unique_ptr<Materialise::CT_PropertyTemplateTree> __PartOverrides = std::make_unique<Materialise::CT_PropertyTemplateTree>();
	if (__PartOverrides->Read(s, "PartOverrides"))
		PartOverrides = std::make_optional(std::move(__PartOverrides));
	return true;
}
Materialise::CT_Property::CT_Property(Materialise::CT_Property &&___CT_Property) noexcept
	: Name(___CT_Property.Name)
	, Type(___CT_Property.Type)
	, ProfileList(___CT_Property.ProfileList)
	, Profile(std::move(___CT_Property.Profile))
	, Property(std::move(___CT_Property.Property))
{ }
void Materialise::CT_Property::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Name", Name.c_str());
	if (Type.has_value())
		s.WriteAttr("Type", Materialise::ConvertST_PropertyTypeToString(Type.value()).c_str());
	if (ProfileList.has_value())
		s.WriteAttr("ProfileList", ProfileList.value().c_str());
	for(auto&& element : Profile)
	{
		element.Write(s, "Profile"); 
	}
	for(auto&& element : Property)
	{
		element.Write(s, "Property"); 
	}
}
bool Materialise::CT_Property::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	s.ReadAttrStr("Name", Name);
	if (s.ReadAttrStr("Type", __tmp_var)) 
		Type = Materialise::ConvertStringToST_PropertyType(__tmp_var);
	std::string __ProfileList;
	if (s.ReadAttrStr("ProfileList", __ProfileList))
		ProfileList = std::optional<std::string> { __ProfileList };
	while (true) { 
		Materialise::CT_ProfileWithProperties __t;
		if (!__t.Read(s, "Profile"))
			break;
		Profile.push_back(std::move(__t));
	}
	while (true) { 
		Materialise::CT_Property __t;
		if (!__t.Read(s, "Property"))
			break;
		Property.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_ProfileWithProperties::CT_ProfileWithProperties(Materialise::CT_ProfileWithProperties &&___CT_ProfileWithProperties) noexcept
	: Name(___CT_ProfileWithProperties.Name)
	, Property(std::move(___CT_ProfileWithProperties.Property))
{ }
void Materialise::CT_ProfileWithProperties::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Name", Name.c_str());
	for(auto&& element : Property)
	{
		element.Write(s, "Property"); 
	}
}
bool Materialise::CT_ProfileWithProperties::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("Name", Name);
	while (true) { 
		Materialise::CT_Property __t;
		if (!__t.Read(s, "Property"))
			break;
		Property.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_PropertyTemplateTree::CT_PropertyTemplateTree(Materialise::CT_PropertyTemplateTree &&___CT_PropertyTemplateTree) noexcept
	: PropertyNode(std::move(___CT_PropertyTemplateTree.PropertyNode))
{ }
void Materialise::CT_PropertyTemplateTree::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : PropertyNode)
	{
		element.Write(s, "PropertyNode"); 
	}
}
bool Materialise::CT_PropertyTemplateTree::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::CT_PropertyTemplateNode __t;
		if (!__t.Read(s, "PropertyNode"))
			break;
		PropertyNode.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_PropertyTemplateNode::CT_PropertyTemplateNode(Materialise::CT_PropertyTemplateNode &&___CT_PropertyTemplateNode) noexcept
	: Name(___CT_PropertyTemplateNode.Name)
	, Type(___CT_PropertyTemplateNode.Type)
	, DisplayName(___CT_PropertyTemplateNode.DisplayName)
	, DisplayNameContainer(___CT_PropertyTemplateNode.DisplayNameContainer)
	, PropertyName(___CT_PropertyTemplateNode.PropertyName)
	, Default(___CT_PropertyTemplateNode.Default)
	, ProfileList(___CT_PropertyTemplateNode.ProfileList)
	, List(___CT_PropertyTemplateNode.List)
	, ProfileName(___CT_PropertyTemplateNode.ProfileName)
	, PropertyNode(std::move(___CT_PropertyTemplateNode.PropertyNode))
{ }
void Materialise::CT_PropertyTemplateNode::Write(IXmlSerializerWriter& s, const std::string& __name__) {
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
	for(auto&& element : PropertyNode)
	{
		element.Write(s, "PropertyNode"); 
	}
}
bool Materialise::CT_PropertyTemplateNode::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	s.ReadAttrStr("Name", Name);
	if (s.ReadAttrStr("Type", __tmp_var)) 
		Type = Materialise::ConvertStringToST_PropertyType(__tmp_var);
	std::string __DisplayName;
	if (s.ReadAttrStr("DisplayName", __DisplayName))
		DisplayName = std::optional<std::string> { __DisplayName };
	std::string __DisplayNameContainer;
	if (s.ReadAttrStr("DisplayNameContainer", __DisplayNameContainer))
		DisplayNameContainer = std::optional<std::string> { __DisplayNameContainer };
	std::string __PropertyName;
	if (s.ReadAttrStr("PropertyName", __PropertyName))
		PropertyName = std::optional<std::string> { __PropertyName };
	std::string __Default;
	if (s.ReadAttrStr("Default", __Default))
		Default = std::optional<std::string> { __Default };
	std::string __ProfileList;
	if (s.ReadAttrStr("ProfileList", __ProfileList))
		ProfileList = std::optional<std::string> { __ProfileList };
	std::string __List;
	if (s.ReadAttrStr("List", __List))
		List = std::optional<std::string> { __List };
	std::string __ProfileName;
	if (s.ReadAttrStr("ProfileName", __ProfileName))
		ProfileName = std::optional<std::string> { __ProfileName };
	while (true) { 
		Materialise::CT_PropertyTemplateNode __t;
		if (!__t.Read(s, "PropertyNode"))
			break;
		PropertyNode.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_MtlsMachineInfo::CT_MtlsMachineInfo(Materialise::CT_MtlsMachineInfo &&___CT_MtlsMachineInfo) noexcept
	: version(___CT_MtlsMachineInfo.version)
	, BuildVolume(std::move(___CT_MtlsMachineInfo.BuildVolume))
	, Tray(std::move(___CT_MtlsMachineInfo.Tray))
	, LockedAreas(std::move(___CT_MtlsMachineInfo.LockedAreas))
{ }
void Materialise::CT_MtlsMachineInfo::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (version.has_value())
		s.WriteAttr("version", Materialise::ConvertST_VersionToString(version.value()).c_str());
	BuildVolume.Write(s, "BuildVolume");
	Tray.Write(s, "Tray");
	if (LockedAreas.has_value())
		LockedAreas.value().get()->Write(s, "LockedAreas");
}
bool Materialise::CT_MtlsMachineInfo::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	if (s.ReadAttrStr("version", __tmp_var)) 
		version = Materialise::ConvertStringToST_Version(__tmp_var);
	BuildVolume.Read(s, "BuildVolume");
	Tray.Read(s, "Tray");
	std::unique_ptr<Materialise::LockedAreas> __LockedAreas = std::make_unique<Materialise::LockedAreas>();
	if (__LockedAreas->Read(s, "LockedAreas"))
		LockedAreas = std::make_optional(std::move(__LockedAreas));
	return true;
}
Materialise::LockedAreas::LockedAreas(Materialise::LockedAreas &&___LockedAreas) noexcept
	: Area(std::move(___LockedAreas.Area))
{ }
void Materialise::LockedAreas::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Area)
	{
		s.Write("Area", element.c_str()); 
	}
}
bool Materialise::LockedAreas::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
Area = s.ReadVectorStr("Area");
	return true;
}
Materialise::CT_MtlsMachineInfoComponent::CT_MtlsMachineInfoComponent(Materialise::CT_MtlsMachineInfoComponent &&___CT_MtlsMachineInfoComponent) noexcept
	: Shape(std::move(___CT_MtlsMachineInfoComponent.Shape))
	, Pos(std::move(___CT_MtlsMachineInfoComponent.Pos))
	, Dim(std::move(___CT_MtlsMachineInfoComponent.Dim))
	, Mesh(std::move(___CT_MtlsMachineInfoComponent.Mesh))
	, Visible(___CT_MtlsMachineInfoComponent.Visible)
{ }
void Materialise::CT_MtlsMachineInfoComponent::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Shape", Materialise::ConvertShapeToString(Shape).c_str());
	Pos.Write(s, "Pos");
	Dim.Write(s, "Dim");
	if (Mesh.has_value())
		Mesh.value().get()->Write(s, "Mesh");
	s.Write("Visible", Visible);
}
bool Materialise::CT_MtlsMachineInfoComponent::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	if (s.ReadAttrStr("Shape", __tmp_var)) 
		Shape = Materialise::ConvertStringToShape(__tmp_var);
	Pos.Read(s, "Pos");
	Dim.Read(s, "Dim");
	std::unique_ptr<Materialise::Mesh> __Mesh = std::make_unique<Materialise::Mesh>();
	if (__Mesh->Read(s, "Mesh"))
		Mesh = std::make_optional(std::move(__Mesh));
	s.ReadBool("Visible", Visible);
	return true;
}
Materialise::Pos::Pos(Materialise::Pos &&___Pos) noexcept
	: x(___Pos.x)
	, y(___Pos.y)
	, z(___Pos.z)
{ }
void Materialise::Pos::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("x", x);
	s.WriteAttr("y", y);
	s.WriteAttr("z", z);
}
bool Materialise::Pos::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrDouble("x", x);
	s.ReadAttrDouble("y", y);
	s.ReadAttrDouble("z", z);
	return true;
}
Materialise::Dim::Dim(Materialise::Dim &&___Dim) noexcept
	: x(___Dim.x)
	, y(___Dim.y)
	, z(___Dim.z)
	, radius(___Dim.radius)
{ }
void Materialise::Dim::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (x.has_value())
		s.WriteAttr("x", x.value());
	if (y.has_value())
		s.WriteAttr("y", y.value());
	s.WriteAttr("z", z);
	if (radius.has_value())
		s.WriteAttr("radius", radius.value().c_str());
}
bool Materialise::Dim::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	double __x;
	if (s.ReadAttrDouble("x", __x))
		x = std::optional<double> { __x };
	double __y;
	if (s.ReadAttrDouble("y", __y))
		y = std::optional<double> { __y };
	s.ReadAttrDouble("z", z);
	std::string __radius;
	if (s.ReadAttrStr("radius", __radius))
		radius = std::optional<std::string> { __radius };
	return true;
}
Materialise::Mesh::Mesh(Materialise::Mesh &&___Mesh) noexcept
	: uuid(___Mesh.uuid)
{ }
void Materialise::Mesh::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("uuid", uuid.c_str());
}
bool Materialise::Mesh::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("uuid", uuid);
	return true;
}
Materialise::MtlsBuildTicket::MtlsBuildTicket(Materialise::MtlsBuildTicket &&___MtlsBuildTicket) noexcept
	: Defaults(std::move(___MtlsBuildTicket.Defaults))
	, PartOverrides(std::move(___MtlsBuildTicket.PartOverrides))
	, ObjectProperties(std::move(___MtlsBuildTicket.ObjectProperties))
{ }
void Materialise::MtlsBuildTicket::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (Defaults.has_value())
		Defaults.value().get()->Write(s, "Defaults");
	if (PartOverrides.has_value())
		PartOverrides.value().get()->Write(s, "PartOverrides");
	if (ObjectProperties.has_value())
		ObjectProperties.value().get()->Write(s, "ObjectProperties");
}
bool Materialise::MtlsBuildTicket::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::unique_ptr<Materialise::CT_PropertyTree> __Defaults = std::make_unique<Materialise::CT_PropertyTree>();
	if (__Defaults->Read(s, "Defaults"))
		Defaults = std::make_optional(std::move(__Defaults));
	std::unique_ptr<Materialise::PartOverrides> __PartOverrides = std::make_unique<Materialise::PartOverrides>();
	if (__PartOverrides->Read(s, "PartOverrides"))
		PartOverrides = std::make_optional(std::move(__PartOverrides));
	std::unique_ptr<Materialise::ObjectProperties> __ObjectProperties = std::make_unique<Materialise::ObjectProperties>();
	if (__ObjectProperties->Read(s, "ObjectProperties"))
		ObjectProperties = std::make_optional(std::move(__ObjectProperties));
	return true;
}
Materialise::MtlsMachineParameters::MtlsMachineParameters(Materialise::MtlsMachineParameters &&___MtlsMachineParameters) noexcept
	: version(___MtlsMachineParameters.version)
	, Property(std::move(___MtlsMachineParameters.Property))
{ }
void Materialise::MtlsMachineParameters::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (version.has_value())
		s.WriteAttr("version", Materialise::ConvertST_VersionToString(version.value()).c_str());
	for(auto&& element : Property)
	{
		element.Write(s, "Property"); 
	}
}
bool Materialise::MtlsMachineParameters::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	if (s.ReadAttrStr("version", __tmp_var)) 
		version = Materialise::ConvertStringToST_Version(__tmp_var);
	while (true) { 
		Materialise::CT_Property __t;
		if (!__t.Read(s, "Property"))
			break;
		Property.push_back(std::move(__t));
	}
	return true;
}
Materialise::MtlsPropertyTemplate::MtlsPropertyTemplate(Materialise::MtlsPropertyTemplate &&___MtlsPropertyTemplate) noexcept
	: version(___MtlsPropertyTemplate.version)
	, MachineParameters(std::move(___MtlsPropertyTemplate.MachineParameters))
	, BuildTicket(std::move(___MtlsPropertyTemplate.BuildTicket))
{ }
void Materialise::MtlsPropertyTemplate::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (version.has_value())
		s.WriteAttr("version", Materialise::ConvertST_VersionToString(version.value()).c_str());
	MachineParameters.Write(s, "MachineParameters");
	BuildTicket.Write(s, "BuildTicket");
}
bool Materialise::MtlsPropertyTemplate::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	if (s.ReadAttrStr("version", __tmp_var)) 
		version = Materialise::ConvertStringToST_Version(__tmp_var);
	MachineParameters.Read(s, "MachineParameters");
	BuildTicket.Read(s, "BuildTicket");
	return true;
}
Materialise::MtlsMachineInfo::MtlsMachineInfo(Materialise::MtlsMachineInfo &&___MtlsMachineInfo) noexcept
	: version(___MtlsMachineInfo.version)
	, BuildVolume(std::move(___MtlsMachineInfo.BuildVolume))
	, Tray(std::move(___MtlsMachineInfo.Tray))
	, LockedAreas(std::move(___MtlsMachineInfo.LockedAreas))
{ }
void Materialise::MtlsMachineInfo::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (version.has_value())
		s.WriteAttr("version", Materialise::ConvertST_VersionToString(version.value()).c_str());
	BuildVolume.Write(s, "BuildVolume");
	Tray.Write(s, "Tray");
	if (LockedAreas.has_value())
		LockedAreas.value().get()->Write(s, "LockedAreas");
}
bool Materialise::MtlsMachineInfo::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	if (s.ReadAttrStr("version", __tmp_var)) 
		version = Materialise::ConvertStringToST_Version(__tmp_var);
	BuildVolume.Read(s, "BuildVolume");
	Tray.Read(s, "Tray");
	std::unique_ptr<Materialise::LockedAreas> __LockedAreas = std::make_unique<Materialise::LockedAreas>();
	if (__LockedAreas->Read(s, "LockedAreas"))
		LockedAreas = std::make_optional(std::move(__LockedAreas));
	return true;
}
