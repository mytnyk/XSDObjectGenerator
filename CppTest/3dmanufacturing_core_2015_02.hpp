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
	const std::string schema_CppTest_3dmanufacturing_core_2015_02_namespace = "http://schemas.microsoft.com/3dmanufacturing/core/2015/02";
	enum class ST_ObjectType {
		model,
		solidsupport,
		support,
		surface,
		other,
	};

	enum class ST_Unit {
		micron,
		millimeter,
		centimeter,
		inch,
		foot,
		meter,
	};

	enum class lang {
	};

	ST_ObjectType ConvertStringToST_ObjectType(std::string str) {
		if (str == "model") return ST_ObjectType::model;
		if (str == "solidsupport") return ST_ObjectType::solidsupport;
		if (str == "support") return ST_ObjectType::support;
		if (str == "surface") return ST_ObjectType::surface;
		if (str == "other") return ST_ObjectType::other;
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertST_ObjectTypeToString(ST_ObjectType e) {
		if (e == ST_ObjectType::model) return "model";
		if (e == ST_ObjectType::solidsupport) return "solidsupport";
		if (e == ST_ObjectType::support) return "support";
		if (e == ST_ObjectType::surface) return "surface";
		if (e == ST_ObjectType::other) return "other";
		throw std::exception("Can't convert enum value to string");
	}

	ST_Unit ConvertStringToST_Unit(std::string str) {
		if (str == "micron") return ST_Unit::micron;
		if (str == "millimeter") return ST_Unit::millimeter;
		if (str == "centimeter") return ST_Unit::centimeter;
		if (str == "inch") return ST_Unit::inch;
		if (str == "foot") return ST_Unit::foot;
		if (str == "meter") return ST_Unit::meter;
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertST_UnitToString(ST_Unit e) {
		if (e == ST_Unit::micron) return "micron";
		if (e == ST_Unit::millimeter) return "millimeter";
		if (e == ST_Unit::centimeter) return "centimeter";
		if (e == ST_Unit::inch) return "inch";
		if (e == ST_Unit::foot) return "foot";
		if (e == ST_Unit::meter) return "meter";
		throw std::exception("Can't convert enum value to string");
	}

	lang ConvertStringTolang(std::string str) {
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertlangToString(lang e) {
		throw std::exception("Can't convert enum value to string");
	}

	struct CT_Model;
	struct CT_Resources;
	struct CT_Build;
	struct CT_BaseMaterials;
	struct CT_Base;
	struct CT_MetadataGroup;
	struct CT_Object;
	struct CT_Mesh;
	struct CT_Vertices;
	struct CT_Vertex;
	struct CT_Triangles;
	struct CT_Triangle;
	struct CT_Components;
	struct CT_Component;
	struct CT_Metadata;
	struct CT_Item;
	struct metadatagroup;
	struct model;
	struct resources;
	struct build;
	struct basematerials;
	struct _base;
	struct _object;
	struct mesh;
	struct vertices;
	struct vertex;
	struct triangles;
	struct triangle;
	struct components;
	struct component;
	struct metadata;
	struct item;
	struct CT_Item {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Item(const CT_Item&) = delete;
		CT_Item& operator=(CT_Item&&) = delete;
		CT_Item& operator=(CT_Item&) = delete;
		CT_Item(CT_Item&&) noexcept;
		CT_Item() = default;
		~CT_Item() = default;
		unsigned int objectid;
		std::optional<std::string> transform;
		std::optional<std::string> partnumber;
		std::optional<std::unique_ptr<metadatagroup>> metadatagroup;
	};
	struct item {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		item(const item&) = delete;
		item& operator=(item&&) = delete;
		item& operator=(item&) = delete;
		item(item&&) noexcept;
		item() = default;
		~item() = default;
		unsigned int objectid;
		std::optional<std::string> transform;
		std::optional<std::string> partnumber;
		std::optional<std::unique_ptr<metadatagroup>> metadatagroup;
	};
	struct CT_Metadata {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Metadata(const CT_Metadata&) = delete;
		CT_Metadata& operator=(CT_Metadata&&) = delete;
		CT_Metadata& operator=(CT_Metadata&) = delete;
		CT_Metadata(CT_Metadata&&) noexcept;
		CT_Metadata() = default;
		~CT_Metadata() = default;
		string name;
		std::optional<bool> preserve;
		std::optional<std::string> type;
	};
	struct metadata {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		metadata(const metadata&) = delete;
		metadata& operator=(metadata&&) = delete;
		metadata& operator=(metadata&) = delete;
		metadata(metadata&&) noexcept;
		metadata() = default;
		~metadata() = default;
		string name;
		std::optional<bool> preserve;
		std::optional<std::string> type;
	};
	struct CT_Component {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Component(const CT_Component&) = delete;
		CT_Component& operator=(CT_Component&&) = delete;
		CT_Component& operator=(CT_Component&) = delete;
		CT_Component(CT_Component&&) noexcept;
		CT_Component() = default;
		~CT_Component() = default;
		unsigned int objectid;
		std::optional<std::string> transform;
	};
	struct component {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		component(const component&) = delete;
		component& operator=(component&&) = delete;
		component& operator=(component&) = delete;
		component(component&&) noexcept;
		component() = default;
		~component() = default;
		unsigned int objectid;
		std::optional<std::string> transform;
	};
	struct CT_Components {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Components(const CT_Components&) = delete;
		CT_Components& operator=(CT_Components&&) = delete;
		CT_Components& operator=(CT_Components&) = delete;
		CT_Components(CT_Components&&) noexcept;
		CT_Components() = default;
		~CT_Components() = default;
		std::vector<component> component;
	};
	struct components {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		components(const components&) = delete;
		components& operator=(components&&) = delete;
		components& operator=(components&) = delete;
		components(components&&) noexcept;
		components() = default;
		~components() = default;
		std::vector<component> component;
	};
	struct CT_Triangle {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Triangle(const CT_Triangle&) = delete;
		CT_Triangle& operator=(CT_Triangle&&) = delete;
		CT_Triangle& operator=(CT_Triangle&) = delete;
		CT_Triangle(CT_Triangle&&) noexcept;
		CT_Triangle() = default;
		~CT_Triangle() = default;
		unsigned int v1;
		unsigned int v2;
		unsigned int v3;
		std::optional<unsigned int> p1;
		std::optional<unsigned int> p2;
		std::optional<unsigned int> p3;
		std::optional<unsigned int> pid;
	};
	struct triangle {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		triangle(const triangle&) = delete;
		triangle& operator=(triangle&&) = delete;
		triangle& operator=(triangle&) = delete;
		triangle(triangle&&) noexcept;
		triangle() = default;
		~triangle() = default;
		unsigned int v1;
		unsigned int v2;
		unsigned int v3;
		std::optional<unsigned int> p1;
		std::optional<unsigned int> p2;
		std::optional<unsigned int> p3;
		std::optional<unsigned int> pid;
	};
	struct CT_Triangles {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Triangles(const CT_Triangles&) = delete;
		CT_Triangles& operator=(CT_Triangles&&) = delete;
		CT_Triangles& operator=(CT_Triangles&) = delete;
		CT_Triangles(CT_Triangles&&) noexcept;
		CT_Triangles() = default;
		~CT_Triangles() = default;
		std::vector<triangle> triangle;
	};
	struct triangles {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		triangles(const triangles&) = delete;
		triangles& operator=(triangles&&) = delete;
		triangles& operator=(triangles&) = delete;
		triangles(triangles&&) noexcept;
		triangles() = default;
		~triangles() = default;
		std::vector<triangle> triangle;
	};
	struct CT_Vertex {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Vertex(const CT_Vertex&) = delete;
		CT_Vertex& operator=(CT_Vertex&&) = delete;
		CT_Vertex& operator=(CT_Vertex&) = delete;
		CT_Vertex(CT_Vertex&&) noexcept;
		CT_Vertex() = default;
		~CT_Vertex() = default;
		double x;
		double y;
		double z;
	};
	struct vertex {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		vertex(const vertex&) = delete;
		vertex& operator=(vertex&&) = delete;
		vertex& operator=(vertex&) = delete;
		vertex(vertex&&) noexcept;
		vertex() = default;
		~vertex() = default;
		double x;
		double y;
		double z;
	};
	struct CT_Vertices {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Vertices(const CT_Vertices&) = delete;
		CT_Vertices& operator=(CT_Vertices&&) = delete;
		CT_Vertices& operator=(CT_Vertices&) = delete;
		CT_Vertices(CT_Vertices&&) noexcept;
		CT_Vertices() = default;
		~CT_Vertices() = default;
		std::vector<vertex> vertex;
	};
	struct vertices {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		vertices(const vertices&) = delete;
		vertices& operator=(vertices&&) = delete;
		vertices& operator=(vertices&) = delete;
		vertices(vertices&&) noexcept;
		vertices() = default;
		~vertices() = default;
		std::vector<vertex> vertex;
	};
	struct CT_Mesh {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Mesh(const CT_Mesh&) = delete;
		CT_Mesh& operator=(CT_Mesh&&) = delete;
		CT_Mesh& operator=(CT_Mesh&) = delete;
		CT_Mesh(CT_Mesh&&) noexcept;
		CT_Mesh() = default;
		~CT_Mesh() = default;
		vertices vertices;
		triangles triangles;
	};
	struct mesh {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		mesh(const mesh&) = delete;
		mesh& operator=(mesh&&) = delete;
		mesh& operator=(mesh&) = delete;
		mesh(mesh&&) noexcept;
		mesh() = default;
		~mesh() = default;
		vertices vertices;
		triangles triangles;
	};
	struct CT_Object {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Object(const CT_Object&) = delete;
		CT_Object& operator=(CT_Object&&) = delete;
		CT_Object& operator=(CT_Object&) = delete;
		CT_Object(CT_Object&&) noexcept;
		CT_Object() = default;
		~CT_Object() = default;
		unsigned int id;
		std::optional<ST_ObjectType> type;
		std::optional<std::string> thumbnail;
		std::optional<std::string> partnumber;
		std::optional<std::string> name;
		std::optional<unsigned int> pid;
		std::optional<unsigned int> pindex;
		std::optional<std::unique_ptr<metadatagroup>> metadatagroup;
		mesh mesh;
		components components;
	};
	struct _object {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		_object(const _object&) = delete;
		_object& operator=(_object&&) = delete;
		_object& operator=(_object&) = delete;
		_object(_object&&) noexcept;
		_object() = default;
		~_object() = default;
		unsigned int id;
		std::optional<ST_ObjectType> type;
		std::optional<std::string> thumbnail;
		std::optional<std::string> partnumber;
		std::optional<std::string> name;
		std::optional<unsigned int> pid;
		std::optional<unsigned int> pindex;
		std::optional<std::unique_ptr<metadatagroup>> metadatagroup;
		mesh mesh;
		components components;
	};
	struct CT_Base {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Base(const CT_Base&) = delete;
		CT_Base& operator=(CT_Base&&) = delete;
		CT_Base& operator=(CT_Base&) = delete;
		CT_Base(CT_Base&&) noexcept;
		CT_Base() = default;
		~CT_Base() = default;
		std::string name;
		std::string displaycolor;
	};
	struct _base {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		_base(const _base&) = delete;
		_base& operator=(_base&&) = delete;
		_base& operator=(_base&) = delete;
		_base(_base&&) noexcept;
		_base() = default;
		~_base() = default;
		std::string name;
		std::string displaycolor;
	};
	struct CT_BaseMaterials {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_BaseMaterials(const CT_BaseMaterials&) = delete;
		CT_BaseMaterials& operator=(CT_BaseMaterials&&) = delete;
		CT_BaseMaterials& operator=(CT_BaseMaterials&) = delete;
		CT_BaseMaterials(CT_BaseMaterials&&) noexcept;
		CT_BaseMaterials() = default;
		~CT_BaseMaterials() = default;
		unsigned int id;
		std::vector<_base> base;
	};
	struct basematerials {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		basematerials(const basematerials&) = delete;
		basematerials& operator=(basematerials&&) = delete;
		basematerials& operator=(basematerials&) = delete;
		basematerials(basematerials&&) noexcept;
		basematerials() = default;
		~basematerials() = default;
		unsigned int id;
		std::vector<_base> base;
	};
	struct CT_Build {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Build(const CT_Build&) = delete;
		CT_Build& operator=(CT_Build&&) = delete;
		CT_Build& operator=(CT_Build&) = delete;
		CT_Build(CT_Build&&) noexcept;
		CT_Build() = default;
		~CT_Build() = default;
		std::vector<item> item;
	};
	struct build {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		build(const build&) = delete;
		build& operator=(build&&) = delete;
		build& operator=(build&) = delete;
		build(build&&) noexcept;
		build() = default;
		~build() = default;
		std::vector<item> item;
	};
	struct CT_Resources {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Resources(const CT_Resources&) = delete;
		CT_Resources& operator=(CT_Resources&&) = delete;
		CT_Resources& operator=(CT_Resources&) = delete;
		CT_Resources(CT_Resources&&) noexcept;
		CT_Resources() = default;
		~CT_Resources() = default;
		std::vector<basematerials> basematerials;
		std::vector<_object> object;
	};
	struct resources {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		resources(const resources&) = delete;
		resources& operator=(resources&&) = delete;
		resources& operator=(resources&) = delete;
		resources(resources&&) noexcept;
		resources() = default;
		~resources() = default;
		std::vector<basematerials> basematerials;
		std::vector<_object> object;
	};
	struct CT_Model {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Model(const CT_Model&) = delete;
		CT_Model& operator=(CT_Model&&) = delete;
		CT_Model& operator=(CT_Model&) = delete;
		CT_Model(CT_Model&&) noexcept;
		CT_Model() = default;
		~CT_Model() = default;
		std::optional<ST_Unit> unit;
		std::optional<std::string> lang;
		std::optional<std::string> requiredextensions;
		std::vector<metadata> metadata;
		resources resources;
		build build;
	};
	struct model {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		model(const model&) = delete;
		model& operator=(model&&) = delete;
		model& operator=(model&) = delete;
		model(model&&) noexcept;
		model() = default;
		~model() = default;
		std::optional<ST_Unit> unit;
		std::optional<std::string> lang;
		std::optional<std::string> requiredextensions;
		std::vector<metadata> metadata;
		resources resources;
		build build;
	};
	struct CT_MetadataGroup {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_MetadataGroup(const CT_MetadataGroup&) = delete;
		CT_MetadataGroup& operator=(CT_MetadataGroup&&) = delete;
		CT_MetadataGroup& operator=(CT_MetadataGroup&) = delete;
		CT_MetadataGroup(CT_MetadataGroup&&) noexcept;
		CT_MetadataGroup() = default;
		~CT_MetadataGroup() = default;
		std::vector<metadata> metadata;
	};
	struct metadatagroup {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		metadatagroup(const metadatagroup&) = delete;
		metadatagroup& operator=(metadatagroup&&) = delete;
		metadatagroup& operator=(metadatagroup&) = delete;
		metadatagroup(metadatagroup&&) noexcept;
		metadatagroup() = default;
		~metadatagroup() = default;
		std::vector<metadata> metadata;
	};
}
Materialise::CT_Model::CT_Model(Materialise::CT_Model &&___CT_Model) noexcept
	: unit(std::move(___CT_Model.unit))
	, lang(std::move(___CT_Model.lang))
	, requiredextensions(std::move(___CT_Model.requiredextensions))
	, metadata(std::move(___CT_Model.metadata))
	, resources(std::move(___CT_Model.resources))
	, build(std::move(___CT_Model.build))
{ }
void Materialise::CT_Model::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (unit.has_value())
		s.WriteAttr("unit", Materialise::ConvertST_UnitToString(unit.value()).c_str());
	if (lang.has_value())
		s.WriteAttr("lang", lang.value().c_str());
	if (requiredextensions.has_value())
		s.WriteAttr("requiredextensions", requiredextensions.value().c_str());
	for(auto&& element : metadata)
	{
		element.Write(s, "metadata"); 
	}
	resources.Write(s, "resources");
	build.Write(s, "build");
}
bool Materialise::CT_Model::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	if (s.ReadAttrStr("unit", __tmp_var)) 
		unit = Materialise::ConvertStringToST_Unit(__tmp_var);
	std::string __lang;
	if (s.ReadAttrStr("lang", __lang))
		lang = std::optional<std::string> { __lang };
	std::string __requiredextensions;
	if (s.ReadAttrStr("requiredextensions", __requiredextensions))
		requiredextensions = std::optional<std::string> { __requiredextensions };
	while (true) { 
		Materialise::metadata __t;
		if (!__t.Read(s, "metadata"))
			break;
		metadata.push_back(std::move(__t));
	}
	resources.Read(s, "resources");
	build.Read(s, "build");
	return true;
}
Materialise::CT_Resources::CT_Resources(Materialise::CT_Resources &&___CT_Resources) noexcept
	: basematerials(std::move(___CT_Resources.basematerials))
	, object(std::move(___CT_Resources.object))
{ }
void Materialise::CT_Resources::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : basematerials)
	{
		element.Write(s, "basematerials"); 
	}
	for(auto&& element : object)
	{
		element.Write(s, "object"); 
	}
}
bool Materialise::CT_Resources::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::basematerials __t;
		if (!__t.Read(s, "basematerials"))
			break;
		basematerials.push_back(std::move(__t));
	}
	while (true) { 
		Materialise::_object __t;
		if (!__t.Read(s, "object"))
			break;
		object.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_Build::CT_Build(Materialise::CT_Build &&___CT_Build) noexcept
	: item(std::move(___CT_Build.item))
{ }
void Materialise::CT_Build::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : item)
	{
		element.Write(s, "item"); 
	}
}
bool Materialise::CT_Build::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::item __t;
		if (!__t.Read(s, "item"))
			break;
		item.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_BaseMaterials::CT_BaseMaterials(Materialise::CT_BaseMaterials &&___CT_BaseMaterials) noexcept
	: id(std::move(___CT_BaseMaterials.id))
	, base(std::move(___CT_BaseMaterials.base))
{ }
void Materialise::CT_BaseMaterials::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id);
	for(auto&& element : base)
	{
		element.Write(s, "base"); 
	}
}
bool Materialise::CT_BaseMaterials::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("id", id);
	while (true) { 
		Materialise::_base __t;
		if (!__t.Read(s, "base"))
			break;
		base.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_Base::CT_Base(Materialise::CT_Base &&___CT_Base) noexcept
	: name(std::move(___CT_Base.name))
	, displaycolor(std::move(___CT_Base.displaycolor))
{ }
void Materialise::CT_Base::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("name", name.c_str());
	s.WriteAttr("displaycolor", displaycolor.c_str());
}
bool Materialise::CT_Base::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("name", name);
	s.ReadAttrStr("displaycolor", displaycolor);
	return true;
}
Materialise::CT_MetadataGroup::CT_MetadataGroup(Materialise::CT_MetadataGroup &&___CT_MetadataGroup) noexcept
	: metadata(std::move(___CT_MetadataGroup.metadata))
{ }
void Materialise::CT_MetadataGroup::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : metadata)
	{
		element.Write(s, "metadata"); 
	}
}
bool Materialise::CT_MetadataGroup::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::metadata __t;
		if (!__t.Read(s, "metadata"))
			break;
		metadata.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_Object::CT_Object(Materialise::CT_Object &&___CT_Object) noexcept
	: id(std::move(___CT_Object.id))
	, type(std::move(___CT_Object.type))
	, thumbnail(std::move(___CT_Object.thumbnail))
	, partnumber(std::move(___CT_Object.partnumber))
	, name(std::move(___CT_Object.name))
	, pid(std::move(___CT_Object.pid))
	, pindex(std::move(___CT_Object.pindex))
	, metadatagroup(std::move(___CT_Object.metadatagroup))
	, mesh(std::move(___CT_Object.mesh))
	, components(std::move(___CT_Object.components))
{ }
void Materialise::CT_Object::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id);
	if (type.has_value())
		s.WriteAttr("type", Materialise::ConvertST_ObjectTypeToString(type.value()).c_str());
	if (thumbnail.has_value())
		s.WriteAttr("thumbnail", thumbnail.value().c_str());
	if (partnumber.has_value())
		s.WriteAttr("partnumber", partnumber.value().c_str());
	if (name.has_value())
		s.WriteAttr("name", name.value().c_str());
	if (pid.has_value())
		s.WriteAttr("pid", pid.value());
	if (pindex.has_value())
		s.WriteAttr("pindex", pindex.value());
	if (metadatagroup.has_value())
		metadatagroup.value().get()->Write(s, "metadatagroup");
	mesh.Write(s, "mesh");
	components.Write(s, "components");
}
bool Materialise::CT_Object::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	s.ReadAttrUnsignedInt("id", id);
	if (s.ReadAttrStr("type", __tmp_var)) 
		type = Materialise::ConvertStringToST_ObjectType(__tmp_var);
	std::string __thumbnail;
	if (s.ReadAttrStr("thumbnail", __thumbnail))
		thumbnail = std::optional<std::string> { __thumbnail };
	std::string __partnumber;
	if (s.ReadAttrStr("partnumber", __partnumber))
		partnumber = std::optional<std::string> { __partnumber };
	std::string __name;
	if (s.ReadAttrStr("name", __name))
		name = std::optional<std::string> { __name };
	unsigned int __pid;
	if (s.ReadAttrUnsignedInt("pid", __pid))
		pid = std::optional<unsigned int> { __pid };
	unsigned int __pindex;
	if (s.ReadAttrUnsignedInt("pindex", __pindex))
		pindex = std::optional<unsigned int> { __pindex };
	Materialise::metadatagroup* __metadatagroup = new Materialise::metadatagroup();
	if (__metadatagroup->Read(s, "metadatagroup"))
		metadatagroup = std::optional<std::unique_ptr<Materialise::metadatagroup>> { __metadatagroup };
	mesh.Read(s, "mesh");
	components.Read(s, "components");
	return true;
}
Materialise::CT_Mesh::CT_Mesh(Materialise::CT_Mesh &&___CT_Mesh) noexcept
	: vertices(std::move(___CT_Mesh.vertices))
	, triangles(std::move(___CT_Mesh.triangles))
{ }
void Materialise::CT_Mesh::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	vertices.Write(s, "vertices");
	triangles.Write(s, "triangles");
}
bool Materialise::CT_Mesh::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	vertices.Read(s, "vertices");
	triangles.Read(s, "triangles");
	return true;
}
Materialise::CT_Vertices::CT_Vertices(Materialise::CT_Vertices &&___CT_Vertices) noexcept
	: vertex(std::move(___CT_Vertices.vertex))
{ }
void Materialise::CT_Vertices::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : vertex)
	{
		element.Write(s, "vertex"); 
	}
}
bool Materialise::CT_Vertices::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::vertex __t;
		if (!__t.Read(s, "vertex"))
			break;
		vertex.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_Vertex::CT_Vertex(Materialise::CT_Vertex &&___CT_Vertex) noexcept
	: x(std::move(___CT_Vertex.x))
	, y(std::move(___CT_Vertex.y))
	, z(std::move(___CT_Vertex.z))
{ }
void Materialise::CT_Vertex::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("x", x);
	s.WriteAttr("y", y);
	s.WriteAttr("z", z);
}
bool Materialise::CT_Vertex::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrDouble("x", x);
	s.ReadAttrDouble("y", y);
	s.ReadAttrDouble("z", z);
	return true;
}
Materialise::CT_Triangles::CT_Triangles(Materialise::CT_Triangles &&___CT_Triangles) noexcept
	: triangle(std::move(___CT_Triangles.triangle))
{ }
void Materialise::CT_Triangles::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : triangle)
	{
		element.Write(s, "triangle"); 
	}
}
bool Materialise::CT_Triangles::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::triangle __t;
		if (!__t.Read(s, "triangle"))
			break;
		triangle.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_Triangle::CT_Triangle(Materialise::CT_Triangle &&___CT_Triangle) noexcept
	: v1(std::move(___CT_Triangle.v1))
	, v2(std::move(___CT_Triangle.v2))
	, v3(std::move(___CT_Triangle.v3))
	, p1(std::move(___CT_Triangle.p1))
	, p2(std::move(___CT_Triangle.p2))
	, p3(std::move(___CT_Triangle.p3))
	, pid(std::move(___CT_Triangle.pid))
{ }
void Materialise::CT_Triangle::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("v1", v1);
	s.WriteAttr("v2", v2);
	s.WriteAttr("v3", v3);
	if (p1.has_value())
		s.WriteAttr("p1", p1.value());
	if (p2.has_value())
		s.WriteAttr("p2", p2.value());
	if (p3.has_value())
		s.WriteAttr("p3", p3.value());
	if (pid.has_value())
		s.WriteAttr("pid", pid.value());
}
bool Materialise::CT_Triangle::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("v1", v1);
	s.ReadAttrUnsignedInt("v2", v2);
	s.ReadAttrUnsignedInt("v3", v3);
	unsigned int __p1;
	if (s.ReadAttrUnsignedInt("p1", __p1))
		p1 = std::optional<unsigned int> { __p1 };
	unsigned int __p2;
	if (s.ReadAttrUnsignedInt("p2", __p2))
		p2 = std::optional<unsigned int> { __p2 };
	unsigned int __p3;
	if (s.ReadAttrUnsignedInt("p3", __p3))
		p3 = std::optional<unsigned int> { __p3 };
	unsigned int __pid;
	if (s.ReadAttrUnsignedInt("pid", __pid))
		pid = std::optional<unsigned int> { __pid };
	return true;
}
Materialise::CT_Components::CT_Components(Materialise::CT_Components &&___CT_Components) noexcept
	: component(std::move(___CT_Components.component))
{ }
void Materialise::CT_Components::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : component)
	{
		element.Write(s, "component"); 
	}
}
bool Materialise::CT_Components::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::component __t;
		if (!__t.Read(s, "component"))
			break;
		component.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_Component::CT_Component(Materialise::CT_Component &&___CT_Component) noexcept
	: objectid(std::move(___CT_Component.objectid))
	, transform(std::move(___CT_Component.transform))
{ }
void Materialise::CT_Component::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("objectid", objectid);
	if (transform.has_value())
		s.WriteAttr("transform", transform.value().c_str());
}
bool Materialise::CT_Component::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("objectid", objectid);
	std::string __transform;
	if (s.ReadAttrStr("transform", __transform))
		transform = std::optional<std::string> { __transform };
	return true;
}
Materialise::CT_Metadata::CT_Metadata(Materialise::CT_Metadata &&___CT_Metadata) noexcept
	: name(std::move(___CT_Metadata.name))
	, preserve(std::move(___CT_Metadata.preserve))
	, type(std::move(___CT_Metadata.type))
{ }
void Materialise::CT_Metadata::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("name", name.c_str());
	if (preserve.has_value())
		s.WriteAttr("preserve", preserve.value());
	if (type.has_value())
		s.WriteAttr("type", type.value().c_str());
}
bool Materialise::CT_Metadata::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("name", name);
	bool __preserve;
	if (s.ReadAttrBool("preserve", __preserve))
		preserve = std::optional<bool> { __preserve };
	std::string __type;
	if (s.ReadAttrStr("type", __type))
		type = std::optional<std::string> { __type };
	return true;
}
Materialise::CT_Item::CT_Item(Materialise::CT_Item &&___CT_Item) noexcept
	: objectid(std::move(___CT_Item.objectid))
	, transform(std::move(___CT_Item.transform))
	, partnumber(std::move(___CT_Item.partnumber))
	, metadatagroup(std::move(___CT_Item.metadatagroup))
{ }
void Materialise::CT_Item::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("objectid", objectid);
	if (transform.has_value())
		s.WriteAttr("transform", transform.value().c_str());
	if (partnumber.has_value())
		s.WriteAttr("partnumber", partnumber.value().c_str());
	if (metadatagroup.has_value())
		metadatagroup.value().get()->Write(s, "metadatagroup");
}
bool Materialise::CT_Item::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("objectid", objectid);
	std::string __transform;
	if (s.ReadAttrStr("transform", __transform))
		transform = std::optional<std::string> { __transform };
	std::string __partnumber;
	if (s.ReadAttrStr("partnumber", __partnumber))
		partnumber = std::optional<std::string> { __partnumber };
	Materialise::metadatagroup* __metadatagroup = new Materialise::metadatagroup();
	if (__metadatagroup->Read(s, "metadatagroup"))
		metadatagroup = std::optional<std::unique_ptr<Materialise::metadatagroup>> { __metadatagroup };
	return true;
}
Materialise::metadatagroup::metadatagroup(Materialise::metadatagroup &&___metadatagroup) noexcept
	: metadata(std::move(___metadatagroup.metadata))
{ }
void Materialise::metadatagroup::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : metadata)
	{
		element.Write(s, "metadata"); 
	}
}
bool Materialise::metadatagroup::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::metadata __t;
		if (!__t.Read(s, "metadata"))
			break;
		metadata.push_back(std::move(__t));
	}
	return true;
}
Materialise::model::model(Materialise::model &&___model) noexcept
	: unit(std::move(___model.unit))
	, lang(std::move(___model.lang))
	, requiredextensions(std::move(___model.requiredextensions))
	, metadata(std::move(___model.metadata))
	, resources(std::move(___model.resources))
	, build(std::move(___model.build))
{ }
void Materialise::model::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (unit.has_value())
		s.WriteAttr("unit", Materialise::ConvertST_UnitToString(unit.value()).c_str());
	if (lang.has_value())
		s.WriteAttr("lang", lang.value().c_str());
	if (requiredextensions.has_value())
		s.WriteAttr("requiredextensions", requiredextensions.value().c_str());
	for(auto&& element : metadata)
	{
		element.Write(s, "metadata"); 
	}
	resources.Write(s, "resources");
	build.Write(s, "build");
}
bool Materialise::model::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	if (s.ReadAttrStr("unit", __tmp_var)) 
		unit = Materialise::ConvertStringToST_Unit(__tmp_var);
	std::string __lang;
	if (s.ReadAttrStr("lang", __lang))
		lang = std::optional<std::string> { __lang };
	std::string __requiredextensions;
	if (s.ReadAttrStr("requiredextensions", __requiredextensions))
		requiredextensions = std::optional<std::string> { __requiredextensions };
	while (true) { 
		Materialise::metadata __t;
		if (!__t.Read(s, "metadata"))
			break;
		metadata.push_back(std::move(__t));
	}
	resources.Read(s, "resources");
	build.Read(s, "build");
	return true;
}
Materialise::resources::resources(Materialise::resources &&___resources) noexcept
	: basematerials(std::move(___resources.basematerials))
	, object(std::move(___resources.object))
{ }
void Materialise::resources::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : basematerials)
	{
		element.Write(s, "basematerials"); 
	}
	for(auto&& element : object)
	{
		element.Write(s, "object"); 
	}
}
bool Materialise::resources::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::basematerials __t;
		if (!__t.Read(s, "basematerials"))
			break;
		basematerials.push_back(std::move(__t));
	}
	while (true) { 
		Materialise::_object __t;
		if (!__t.Read(s, "object"))
			break;
		object.push_back(std::move(__t));
	}
	return true;
}
Materialise::build::build(Materialise::build &&___build) noexcept
	: item(std::move(___build.item))
{ }
void Materialise::build::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : item)
	{
		element.Write(s, "item"); 
	}
}
bool Materialise::build::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::item __t;
		if (!__t.Read(s, "item"))
			break;
		item.push_back(std::move(__t));
	}
	return true;
}
Materialise::basematerials::basematerials(Materialise::basematerials &&___basematerials) noexcept
	: id(std::move(___basematerials.id))
	, base(std::move(___basematerials.base))
{ }
void Materialise::basematerials::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id);
	for(auto&& element : base)
	{
		element.Write(s, "base"); 
	}
}
bool Materialise::basematerials::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("id", id);
	while (true) { 
		Materialise::_base __t;
		if (!__t.Read(s, "base"))
			break;
		base.push_back(std::move(__t));
	}
	return true;
}
Materialise::_base::_base(Materialise::_base &&____base) noexcept
	: name(std::move(____base.name))
	, displaycolor(std::move(____base.displaycolor))
{ }
void Materialise::_base::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("name", name.c_str());
	s.WriteAttr("displaycolor", displaycolor.c_str());
}
bool Materialise::_base::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("name", name);
	s.ReadAttrStr("displaycolor", displaycolor);
	return true;
}
Materialise::_object::_object(Materialise::_object &&____object) noexcept
	: id(std::move(____object.id))
	, type(std::move(____object.type))
	, thumbnail(std::move(____object.thumbnail))
	, partnumber(std::move(____object.partnumber))
	, name(std::move(____object.name))
	, pid(std::move(____object.pid))
	, pindex(std::move(____object.pindex))
	, metadatagroup(std::move(____object.metadatagroup))
	, mesh(std::move(____object.mesh))
	, components(std::move(____object.components))
{ }
void Materialise::_object::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id);
	if (type.has_value())
		s.WriteAttr("type", Materialise::ConvertST_ObjectTypeToString(type.value()).c_str());
	if (thumbnail.has_value())
		s.WriteAttr("thumbnail", thumbnail.value().c_str());
	if (partnumber.has_value())
		s.WriteAttr("partnumber", partnumber.value().c_str());
	if (name.has_value())
		s.WriteAttr("name", name.value().c_str());
	if (pid.has_value())
		s.WriteAttr("pid", pid.value());
	if (pindex.has_value())
		s.WriteAttr("pindex", pindex.value());
	if (metadatagroup.has_value())
		metadatagroup.value().get()->Write(s, "metadatagroup");
	mesh.Write(s, "mesh");
	components.Write(s, "components");
}
bool Materialise::_object::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	s.ReadAttrUnsignedInt("id", id);
	if (s.ReadAttrStr("type", __tmp_var)) 
		type = Materialise::ConvertStringToST_ObjectType(__tmp_var);
	std::string __thumbnail;
	if (s.ReadAttrStr("thumbnail", __thumbnail))
		thumbnail = std::optional<std::string> { __thumbnail };
	std::string __partnumber;
	if (s.ReadAttrStr("partnumber", __partnumber))
		partnumber = std::optional<std::string> { __partnumber };
	std::string __name;
	if (s.ReadAttrStr("name", __name))
		name = std::optional<std::string> { __name };
	unsigned int __pid;
	if (s.ReadAttrUnsignedInt("pid", __pid))
		pid = std::optional<unsigned int> { __pid };
	unsigned int __pindex;
	if (s.ReadAttrUnsignedInt("pindex", __pindex))
		pindex = std::optional<unsigned int> { __pindex };
	Materialise::metadatagroup* __metadatagroup = new Materialise::metadatagroup();
	if (__metadatagroup->Read(s, "metadatagroup"))
		metadatagroup = std::optional<std::unique_ptr<Materialise::metadatagroup>> { __metadatagroup };
	mesh.Read(s, "mesh");
	components.Read(s, "components");
	return true;
}
Materialise::mesh::mesh(Materialise::mesh &&___mesh) noexcept
	: vertices(std::move(___mesh.vertices))
	, triangles(std::move(___mesh.triangles))
{ }
void Materialise::mesh::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	vertices.Write(s, "vertices");
	triangles.Write(s, "triangles");
}
bool Materialise::mesh::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	vertices.Read(s, "vertices");
	triangles.Read(s, "triangles");
	return true;
}
Materialise::vertices::vertices(Materialise::vertices &&___vertices) noexcept
	: vertex(std::move(___vertices.vertex))
{ }
void Materialise::vertices::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : vertex)
	{
		element.Write(s, "vertex"); 
	}
}
bool Materialise::vertices::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::vertex __t;
		if (!__t.Read(s, "vertex"))
			break;
		vertex.push_back(std::move(__t));
	}
	return true;
}
Materialise::vertex::vertex(Materialise::vertex &&___vertex) noexcept
	: x(std::move(___vertex.x))
	, y(std::move(___vertex.y))
	, z(std::move(___vertex.z))
{ }
void Materialise::vertex::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("x", x);
	s.WriteAttr("y", y);
	s.WriteAttr("z", z);
}
bool Materialise::vertex::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrDouble("x", x);
	s.ReadAttrDouble("y", y);
	s.ReadAttrDouble("z", z);
	return true;
}
Materialise::triangles::triangles(Materialise::triangles &&___triangles) noexcept
	: triangle(std::move(___triangles.triangle))
{ }
void Materialise::triangles::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : triangle)
	{
		element.Write(s, "triangle"); 
	}
}
bool Materialise::triangles::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::triangle __t;
		if (!__t.Read(s, "triangle"))
			break;
		triangle.push_back(std::move(__t));
	}
	return true;
}
Materialise::triangle::triangle(Materialise::triangle &&___triangle) noexcept
	: v1(std::move(___triangle.v1))
	, v2(std::move(___triangle.v2))
	, v3(std::move(___triangle.v3))
	, p1(std::move(___triangle.p1))
	, p2(std::move(___triangle.p2))
	, p3(std::move(___triangle.p3))
	, pid(std::move(___triangle.pid))
{ }
void Materialise::triangle::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("v1", v1);
	s.WriteAttr("v2", v2);
	s.WriteAttr("v3", v3);
	if (p1.has_value())
		s.WriteAttr("p1", p1.value());
	if (p2.has_value())
		s.WriteAttr("p2", p2.value());
	if (p3.has_value())
		s.WriteAttr("p3", p3.value());
	if (pid.has_value())
		s.WriteAttr("pid", pid.value());
}
bool Materialise::triangle::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("v1", v1);
	s.ReadAttrUnsignedInt("v2", v2);
	s.ReadAttrUnsignedInt("v3", v3);
	unsigned int __p1;
	if (s.ReadAttrUnsignedInt("p1", __p1))
		p1 = std::optional<unsigned int> { __p1 };
	unsigned int __p2;
	if (s.ReadAttrUnsignedInt("p2", __p2))
		p2 = std::optional<unsigned int> { __p2 };
	unsigned int __p3;
	if (s.ReadAttrUnsignedInt("p3", __p3))
		p3 = std::optional<unsigned int> { __p3 };
	unsigned int __pid;
	if (s.ReadAttrUnsignedInt("pid", __pid))
		pid = std::optional<unsigned int> { __pid };
	return true;
}
Materialise::components::components(Materialise::components &&___components) noexcept
	: component(std::move(___components.component))
{ }
void Materialise::components::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : component)
	{
		element.Write(s, "component"); 
	}
}
bool Materialise::components::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::component __t;
		if (!__t.Read(s, "component"))
			break;
		component.push_back(std::move(__t));
	}
	return true;
}
Materialise::component::component(Materialise::component &&___component) noexcept
	: objectid(std::move(___component.objectid))
	, transform(std::move(___component.transform))
{ }
void Materialise::component::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("objectid", objectid);
	if (transform.has_value())
		s.WriteAttr("transform", transform.value().c_str());
}
bool Materialise::component::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("objectid", objectid);
	std::string __transform;
	if (s.ReadAttrStr("transform", __transform))
		transform = std::optional<std::string> { __transform };
	return true;
}
Materialise::metadata::metadata(Materialise::metadata &&___metadata) noexcept
	: name(std::move(___metadata.name))
	, preserve(std::move(___metadata.preserve))
	, type(std::move(___metadata.type))
{ }
void Materialise::metadata::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("name", name.c_str());
	if (preserve.has_value())
		s.WriteAttr("preserve", preserve.value());
	if (type.has_value())
		s.WriteAttr("type", type.value().c_str());
}
bool Materialise::metadata::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("name", name);
	bool __preserve;
	if (s.ReadAttrBool("preserve", __preserve))
		preserve = std::optional<bool> { __preserve };
	std::string __type;
	if (s.ReadAttrStr("type", __type))
		type = std::optional<std::string> { __type };
	return true;
}
Materialise::item::item(Materialise::item &&___item) noexcept
	: objectid(std::move(___item.objectid))
	, transform(std::move(___item.transform))
	, partnumber(std::move(___item.partnumber))
	, metadatagroup(std::move(___item.metadatagroup))
{ }
void Materialise::item::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("objectid", objectid);
	if (transform.has_value())
		s.WriteAttr("transform", transform.value().c_str());
	if (partnumber.has_value())
		s.WriteAttr("partnumber", partnumber.value().c_str());
	if (metadatagroup.has_value())
		metadatagroup.value().get()->Write(s, "metadatagroup");
}
bool Materialise::item::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("objectid", objectid);
	std::string __transform;
	if (s.ReadAttrStr("transform", __transform))
		transform = std::optional<std::string> { __transform };
	std::string __partnumber;
	if (s.ReadAttrStr("partnumber", __partnumber))
		partnumber = std::optional<std::string> { __partnumber };
	Materialise::metadatagroup* __metadatagroup = new Materialise::metadatagroup();
	if (__metadatagroup->Read(s, "metadatagroup"))
		metadatagroup = std::optional<std::unique_ptr<Materialise::metadatagroup>> { __metadatagroup };
	return true;
}
