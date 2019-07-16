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
	const std::string schema_CppTest_3dmanufacturing_slice_2015_07_namespace = "http://schemas.microsoft.com/3dmanufacturing/slice/2015/07";
	struct CT_SliceStack;
	struct CT_Slice;
	struct CT_SliceRef;
	struct CT_2DVertices;
	struct CT_2DVertex;
	struct CT_Polygon;
	struct CT_Segment;
	struct slicestack;
	struct sliceref;
	struct slice;
	struct vertices;
	struct vertex;
	struct polygon;
	struct segment;
	struct CT_Segment {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Segment(const CT_Segment&) = delete;
		CT_Segment& operator=(CT_Segment&&) = delete;
		CT_Segment& operator=(CT_Segment&) = delete;
		CT_Segment(CT_Segment&&) noexcept;
		CT_Segment() = default;
		~CT_Segment() = default;
		unsigned int v2;
		unsigned int p1;
		unsigned int p2;
		unsigned int pid;
	};
	struct segment {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		segment(const segment&) = delete;
		segment& operator=(segment&&) = delete;
		segment& operator=(segment&) = delete;
		segment(segment&&) noexcept;
		segment() = default;
		~segment() = default;
		unsigned int v2;
		unsigned int p1;
		unsigned int p2;
		unsigned int pid;
	};
	struct CT_Polygon {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Polygon(const CT_Polygon&) = delete;
		CT_Polygon& operator=(CT_Polygon&&) = delete;
		CT_Polygon& operator=(CT_Polygon&) = delete;
		CT_Polygon(CT_Polygon&&) noexcept;
		CT_Polygon() = default;
		~CT_Polygon() = default;
		unsigned int startv;
		std::vector<segment> segment;
	};
	struct polygon {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		polygon(const polygon&) = delete;
		polygon& operator=(polygon&&) = delete;
		polygon& operator=(polygon&) = delete;
		polygon(polygon&&) noexcept;
		polygon() = default;
		~polygon() = default;
		unsigned int startv;
		std::vector<segment> segment;
	};
	struct CT_2DVertex {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_2DVertex(const CT_2DVertex&) = delete;
		CT_2DVertex& operator=(CT_2DVertex&&) = delete;
		CT_2DVertex& operator=(CT_2DVertex&) = delete;
		CT_2DVertex(CT_2DVertex&&) noexcept;
		CT_2DVertex() = default;
		~CT_2DVertex() = default;
		double x;
		double y;
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
	};
	struct CT_2DVertices {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_2DVertices(const CT_2DVertices&) = delete;
		CT_2DVertices& operator=(CT_2DVertices&&) = delete;
		CT_2DVertices& operator=(CT_2DVertices&) = delete;
		CT_2DVertices(CT_2DVertices&&) noexcept;
		CT_2DVertices() = default;
		~CT_2DVertices() = default;
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
	struct CT_Slice {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Slice(const CT_Slice&) = delete;
		CT_Slice& operator=(CT_Slice&&) = delete;
		CT_Slice& operator=(CT_Slice&) = delete;
		CT_Slice(CT_Slice&&) noexcept;
		CT_Slice() = default;
		~CT_Slice() = default;
		double ztop;
		std::optional<std::unique_ptr<vertices>> vertices;
		std::vector<polygon> polygon;
	};
	struct slice {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		slice(const slice&) = delete;
		slice& operator=(slice&&) = delete;
		slice& operator=(slice&) = delete;
		slice(slice&&) noexcept;
		slice() = default;
		~slice() = default;
		double ztop;
		std::optional<std::unique_ptr<vertices>> vertices;
		std::vector<polygon> polygon;
	};
	struct CT_SliceRef {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_SliceRef(const CT_SliceRef&) = delete;
		CT_SliceRef& operator=(CT_SliceRef&&) = delete;
		CT_SliceRef& operator=(CT_SliceRef&) = delete;
		CT_SliceRef(CT_SliceRef&&) noexcept;
		CT_SliceRef() = default;
		~CT_SliceRef() = default;
		unsigned int slicestackid;
		std::string slicepath;
	};
	struct sliceref {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		sliceref(const sliceref&) = delete;
		sliceref& operator=(sliceref&&) = delete;
		sliceref& operator=(sliceref&) = delete;
		sliceref(sliceref&&) noexcept;
		sliceref() = default;
		~sliceref() = default;
		unsigned int slicestackid;
		std::string slicepath;
	};
	struct CT_SliceStack {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_SliceStack(const CT_SliceStack&) = delete;
		CT_SliceStack& operator=(CT_SliceStack&&) = delete;
		CT_SliceStack& operator=(CT_SliceStack&) = delete;
		CT_SliceStack(CT_SliceStack&&) noexcept;
		CT_SliceStack() = default;
		~CT_SliceStack() = default;
		unsigned int id;
		std::optional<double> zbottom;
		std::vector<slice> slice;
		std::vector<sliceref> sliceref;
	};
	struct slicestack {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		slicestack(const slicestack&) = delete;
		slicestack& operator=(slicestack&&) = delete;
		slicestack& operator=(slicestack&) = delete;
		slicestack(slicestack&&) noexcept;
		slicestack() = default;
		~slicestack() = default;
		unsigned int id;
		std::optional<double> zbottom;
		std::vector<slice> slice;
		std::vector<sliceref> sliceref;
	};
}
Materialise::CT_SliceStack::CT_SliceStack(Materialise::CT_SliceStack &&___CT_SliceStack) noexcept
	: id(std::move(___CT_SliceStack.id))
	, zbottom(std::move(___CT_SliceStack.zbottom))
	, slice(std::move(___CT_SliceStack.slice))
	, sliceref(std::move(___CT_SliceStack.sliceref))
{ }
void Materialise::CT_SliceStack::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id);
	if (zbottom.has_value())
		s.WriteAttr("zbottom", zbottom.value());
	for(auto&& element : slice)
	{
		element.Write(s, "slice"); 
	}
	for(auto&& element : sliceref)
	{
		element.Write(s, "sliceref"); 
	}
}
bool Materialise::CT_SliceStack::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("id", id);
	double __zbottom;
	if (s.ReadAttrDouble("zbottom", __zbottom))
		zbottom = std::optional<double> { __zbottom };
	while (true) { 
		Materialise::slice __t;
		if (!__t.Read(s, "slice"))
			break;
		slice.push_back(std::move(__t));
	}
	while (true) { 
		Materialise::sliceref __t;
		if (!__t.Read(s, "sliceref"))
			break;
		sliceref.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_Slice::CT_Slice(Materialise::CT_Slice &&___CT_Slice) noexcept
	: ztop(std::move(___CT_Slice.ztop))
	, vertices(std::move(___CT_Slice.vertices))
	, polygon(std::move(___CT_Slice.polygon))
{ }
void Materialise::CT_Slice::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("ztop", ztop);
	if (vertices.has_value())
		vertices.value().get()->Write(s, "vertices");
	for(auto&& element : polygon)
	{
		element.Write(s, "polygon"); 
	}
}
bool Materialise::CT_Slice::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrDouble("ztop", ztop);
	Materialise::vertices* __vertices = new Materialise::vertices();
	if (__vertices->Read(s, "vertices"))
		vertices = std::optional<std::unique_ptr<Materialise::vertices>> { __vertices };
	while (true) { 
		Materialise::polygon __t;
		if (!__t.Read(s, "polygon"))
			break;
		polygon.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_SliceRef::CT_SliceRef(Materialise::CT_SliceRef &&___CT_SliceRef) noexcept
	: slicestackid(std::move(___CT_SliceRef.slicestackid))
	, slicepath(std::move(___CT_SliceRef.slicepath))
{ }
void Materialise::CT_SliceRef::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("slicestackid", slicestackid);
	s.WriteAttr("slicepath", slicepath.c_str());
}
bool Materialise::CT_SliceRef::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("slicestackid", slicestackid);
	s.ReadAttrStr("slicepath", slicepath);
	return true;
}
Materialise::CT_2DVertices::CT_2DVertices(Materialise::CT_2DVertices &&___CT_2DVertices) noexcept
	: vertex(std::move(___CT_2DVertices.vertex))
{ }
void Materialise::CT_2DVertices::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : vertex)
	{
		element.Write(s, "vertex"); 
	}
}
bool Materialise::CT_2DVertices::Read(IXmlSerializerReader& s, const std::string& __name__) {
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
Materialise::CT_2DVertex::CT_2DVertex(Materialise::CT_2DVertex &&___CT_2DVertex) noexcept
	: x(std::move(___CT_2DVertex.x))
	, y(std::move(___CT_2DVertex.y))
{ }
void Materialise::CT_2DVertex::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("x", x);
	s.WriteAttr("y", y);
}
bool Materialise::CT_2DVertex::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrDouble("x", x);
	s.ReadAttrDouble("y", y);
	return true;
}
Materialise::CT_Polygon::CT_Polygon(Materialise::CT_Polygon &&___CT_Polygon) noexcept
	: startv(std::move(___CT_Polygon.startv))
	, segment(std::move(___CT_Polygon.segment))
{ }
void Materialise::CT_Polygon::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("startv", startv);
	for(auto&& element : segment)
	{
		element.Write(s, "segment"); 
	}
}
bool Materialise::CT_Polygon::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("startv", startv);
	while (true) { 
		Materialise::segment __t;
		if (!__t.Read(s, "segment"))
			break;
		segment.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_Segment::CT_Segment(Materialise::CT_Segment &&___CT_Segment) noexcept
	: v2(std::move(___CT_Segment.v2))
	, p1(std::move(___CT_Segment.p1))
	, p2(std::move(___CT_Segment.p2))
	, pid(std::move(___CT_Segment.pid))
{ }
void Materialise::CT_Segment::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("v2", v2);
	s.WriteAttr("p1", p1);
	s.WriteAttr("p2", p2);
	s.WriteAttr("pid", pid);
}
bool Materialise::CT_Segment::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("v2", v2);
	s.ReadAttrUnsignedInt("p1", p1);
	s.ReadAttrUnsignedInt("p2", p2);
	s.ReadAttrUnsignedInt("pid", pid);
	return true;
}
Materialise::slicestack::slicestack(Materialise::slicestack &&___slicestack) noexcept
	: id(std::move(___slicestack.id))
	, zbottom(std::move(___slicestack.zbottom))
	, slice(std::move(___slicestack.slice))
	, sliceref(std::move(___slicestack.sliceref))
{ }
void Materialise::slicestack::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id);
	if (zbottom.has_value())
		s.WriteAttr("zbottom", zbottom.value());
	for(auto&& element : slice)
	{
		element.Write(s, "slice"); 
	}
	for(auto&& element : sliceref)
	{
		element.Write(s, "sliceref"); 
	}
}
bool Materialise::slicestack::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("id", id);
	double __zbottom;
	if (s.ReadAttrDouble("zbottom", __zbottom))
		zbottom = std::optional<double> { __zbottom };
	while (true) { 
		Materialise::slice __t;
		if (!__t.Read(s, "slice"))
			break;
		slice.push_back(std::move(__t));
	}
	while (true) { 
		Materialise::sliceref __t;
		if (!__t.Read(s, "sliceref"))
			break;
		sliceref.push_back(std::move(__t));
	}
	return true;
}
Materialise::sliceref::sliceref(Materialise::sliceref &&___sliceref) noexcept
	: slicestackid(std::move(___sliceref.slicestackid))
	, slicepath(std::move(___sliceref.slicepath))
{ }
void Materialise::sliceref::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("slicestackid", slicestackid);
	s.WriteAttr("slicepath", slicepath.c_str());
}
bool Materialise::sliceref::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("slicestackid", slicestackid);
	s.ReadAttrStr("slicepath", slicepath);
	return true;
}
Materialise::slice::slice(Materialise::slice &&___slice) noexcept
	: ztop(std::move(___slice.ztop))
	, vertices(std::move(___slice.vertices))
	, polygon(std::move(___slice.polygon))
{ }
void Materialise::slice::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("ztop", ztop);
	if (vertices.has_value())
		vertices.value().get()->Write(s, "vertices");
	for(auto&& element : polygon)
	{
		element.Write(s, "polygon"); 
	}
}
bool Materialise::slice::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrDouble("ztop", ztop);
	Materialise::vertices* __vertices = new Materialise::vertices();
	if (__vertices->Read(s, "vertices"))
		vertices = std::optional<std::unique_ptr<Materialise::vertices>> { __vertices };
	while (true) { 
		Materialise::polygon __t;
		if (!__t.Read(s, "polygon"))
			break;
		polygon.push_back(std::move(__t));
	}
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
{ }
void Materialise::vertex::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("x", x);
	s.WriteAttr("y", y);
}
bool Materialise::vertex::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrDouble("x", x);
	s.ReadAttrDouble("y", y);
	return true;
}
Materialise::polygon::polygon(Materialise::polygon &&___polygon) noexcept
	: startv(std::move(___polygon.startv))
	, segment(std::move(___polygon.segment))
{ }
void Materialise::polygon::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("startv", startv);
	for(auto&& element : segment)
	{
		element.Write(s, "segment"); 
	}
}
bool Materialise::polygon::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("startv", startv);
	while (true) { 
		Materialise::segment __t;
		if (!__t.Read(s, "segment"))
			break;
		segment.push_back(std::move(__t));
	}
	return true;
}
Materialise::segment::segment(Materialise::segment &&___segment) noexcept
	: v2(std::move(___segment.v2))
	, p1(std::move(___segment.p1))
	, p2(std::move(___segment.p2))
	, pid(std::move(___segment.pid))
{ }
void Materialise::segment::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("v2", v2);
	s.WriteAttr("p1", p1);
	s.WriteAttr("p2", p2);
	s.WriteAttr("pid", pid);
}
bool Materialise::segment::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("v2", v2);
	s.ReadAttrUnsignedInt("p1", p1);
	s.ReadAttrUnsignedInt("p2", p2);
	s.ReadAttrUnsignedInt("pid", pid);
	return true;
}
