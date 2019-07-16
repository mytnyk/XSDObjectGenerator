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
	const std::string schema_generated_files_3dmanufacturing_beamlattice_2017_02_namespace = "http://schemas.microsoft.com/3dmanufacturing/beamlattice/2017/02";
	enum class ST_CapMode {
		hemisphere,
		sphere,
		butt,
	};

	enum class ST_ClippingMode {
		none,
		inside,
		outside,
	};

	ST_CapMode ConvertStringToST_CapMode(std::string str) {
		if (str == "hemisphere") return ST_CapMode::hemisphere;
		if (str == "sphere") return ST_CapMode::sphere;
		if (str == "butt") return ST_CapMode::butt;
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertST_CapModeToString(ST_CapMode e) {
		if (e == ST_CapMode::hemisphere) return "hemisphere";
		if (e == ST_CapMode::sphere) return "sphere";
		if (e == ST_CapMode::butt) return "butt";
		throw std::exception("Can't convert enum value to string");
	}

	ST_ClippingMode ConvertStringToST_ClippingMode(std::string str) {
		if (str == "none") return ST_ClippingMode::none;
		if (str == "inside") return ST_ClippingMode::inside;
		if (str == "outside") return ST_ClippingMode::outside;
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertST_ClippingModeToString(ST_ClippingMode e) {
		if (e == ST_ClippingMode::none) return "none";
		if (e == ST_ClippingMode::inside) return "inside";
		if (e == ST_ClippingMode::outside) return "outside";
		throw std::exception("Can't convert enum value to string");
	}

	struct CT_Mesh;
	struct CT_BeamLattice;
	struct CT_Beam;
	struct CT_Beams;
	struct CT_BeamSet;
	struct CT_BeamSets;
	struct CT_Ref;
	struct beam;
	struct beams;
	struct _ref;
	struct beamset;
	struct beamsets;
	struct beamlattice;
	struct CT_Beams {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Beams(const CT_Beams&) = delete;
		CT_Beams& operator=(CT_Beams&&) = delete;
		CT_Beams& operator=(CT_Beams&) = delete;
		CT_Beams(CT_Beams&&) noexcept;
		CT_Beams() = default;
		~CT_Beams() = default;
		std::vector<beam> beam;
	};
	struct beams {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		beams(const beams&) = delete;
		beams& operator=(beams&&) = delete;
		beams& operator=(beams&) = delete;
		beams(beams&&) noexcept;
		beams() = default;
		~beams() = default;
		std::vector<beam> beam;
	};
	struct CT_BeamLattice {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_BeamLattice(const CT_BeamLattice&) = delete;
		CT_BeamLattice& operator=(CT_BeamLattice&&) = delete;
		CT_BeamLattice& operator=(CT_BeamLattice&) = delete;
		CT_BeamLattice(CT_BeamLattice&&) noexcept;
		CT_BeamLattice() = default;
		~CT_BeamLattice() = default;
		double minlength;
		double radius;
		std::optional<ST_ClippingMode> clippingmode;
		std::optional<unsigned int> clippingmesh;
		std::optional<unsigned int> representationmesh;
		std::optional<unsigned int> pid;
		std::optional<unsigned int> pindex;
		std::optional<ST_CapMode> cap;
		beams beams;
		std::optional<std::unique_ptr<beamsets>> beamsets;
	};
	struct beamlattice {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		beamlattice(const beamlattice&) = delete;
		beamlattice& operator=(beamlattice&&) = delete;
		beamlattice& operator=(beamlattice&) = delete;
		beamlattice(beamlattice&&) noexcept;
		beamlattice() = default;
		~beamlattice() = default;
		double minlength;
		double radius;
		std::optional<ST_ClippingMode> clippingmode;
		std::optional<unsigned int> clippingmesh;
		std::optional<unsigned int> representationmesh;
		std::optional<unsigned int> pid;
		std::optional<unsigned int> pindex;
		std::optional<ST_CapMode> cap;
		beams beams;
		std::optional<std::unique_ptr<beamsets>> beamsets;
	};
	struct CT_BeamSets {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_BeamSets(const CT_BeamSets&) = delete;
		CT_BeamSets& operator=(CT_BeamSets&&) = delete;
		CT_BeamSets& operator=(CT_BeamSets&) = delete;
		CT_BeamSets(CT_BeamSets&&) noexcept;
		CT_BeamSets() = default;
		~CT_BeamSets() = default;
		std::vector<beamset> beamset;
	};
	struct beamsets {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		beamsets(const beamsets&) = delete;
		beamsets& operator=(beamsets&&) = delete;
		beamsets& operator=(beamsets&) = delete;
		beamsets(beamsets&&) noexcept;
		beamsets() = default;
		~beamsets() = default;
		std::vector<beamset> beamset;
	};
	struct CT_BeamSet {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_BeamSet(const CT_BeamSet&) = delete;
		CT_BeamSet& operator=(CT_BeamSet&&) = delete;
		CT_BeamSet& operator=(CT_BeamSet&) = delete;
		CT_BeamSet(CT_BeamSet&&) noexcept;
		CT_BeamSet() = default;
		~CT_BeamSet() = default;
		std::optional<std::string> name;
		std::optional<std::string> identifier;
		std::vector<_ref> ref;
	};
	struct beamset {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		beamset(const beamset&) = delete;
		beamset& operator=(beamset&&) = delete;
		beamset& operator=(beamset&) = delete;
		beamset(beamset&&) noexcept;
		beamset() = default;
		~beamset() = default;
		std::optional<std::string> name;
		std::optional<std::string> identifier;
		std::vector<_ref> ref;
	};
	struct CT_Ref {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Ref(const CT_Ref&) = delete;
		CT_Ref& operator=(CT_Ref&&) = delete;
		CT_Ref& operator=(CT_Ref&) = delete;
		CT_Ref(CT_Ref&&) noexcept;
		CT_Ref() = default;
		~CT_Ref() = default;
		unsigned int index;
	};
	struct _ref {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		_ref(const _ref&) = delete;
		_ref& operator=(_ref&&) = delete;
		_ref& operator=(_ref&) = delete;
		_ref(_ref&&) noexcept;
		_ref() = default;
		~_ref() = default;
		unsigned int index;
	};
	struct CT_Beam {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		CT_Beam(const CT_Beam&) = delete;
		CT_Beam& operator=(CT_Beam&&) = delete;
		CT_Beam& operator=(CT_Beam&) = delete;
		CT_Beam(CT_Beam&&) noexcept;
		CT_Beam() = default;
		~CT_Beam() = default;
		unsigned int v1;
		unsigned int v2;
		std::optional<double> r1;
		std::optional<double> r2;
		std::optional<unsigned int> p1;
		std::optional<unsigned int> p2;
		std::optional<unsigned int> pid;
		std::optional<ST_CapMode> cap1;
		std::optional<ST_CapMode> cap2;
	};
	struct beam {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		beam(const beam&) = delete;
		beam& operator=(beam&&) = delete;
		beam& operator=(beam&) = delete;
		beam(beam&&) noexcept;
		beam() = default;
		~beam() = default;
		unsigned int v1;
		unsigned int v2;
		std::optional<double> r1;
		std::optional<double> r2;
		std::optional<unsigned int> p1;
		std::optional<unsigned int> p2;
		std::optional<unsigned int> pid;
		std::optional<ST_CapMode> cap1;
		std::optional<ST_CapMode> cap2;
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
		std::optional<std::unique_ptr<beamlattice>> beamlattice;
	};
}
Materialise::CT_Mesh::CT_Mesh(Materialise::CT_Mesh &&___CT_Mesh) noexcept
	: beamlattice(std::move(___CT_Mesh.beamlattice))
{ }
void Materialise::CT_Mesh::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (beamlattice.has_value())
		beamlattice.value().get()->Write(s, "beamlattice");
}
bool Materialise::CT_Mesh::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::unique_ptr<Materialise::beamlattice> __beamlattice = std::make_unique<Materialise::beamlattice>();
	if (__beamlattice->Read(s, "beamlattice"))
		beamlattice = std::make_optional(std::move(__beamlattice));
	return true;
}
Materialise::CT_BeamLattice::CT_BeamLattice(Materialise::CT_BeamLattice &&___CT_BeamLattice) noexcept
	: minlength(___CT_BeamLattice.minlength)
	, radius(___CT_BeamLattice.radius)
	, clippingmode(___CT_BeamLattice.clippingmode)
	, clippingmesh(___CT_BeamLattice.clippingmesh)
	, representationmesh(___CT_BeamLattice.representationmesh)
	, pid(___CT_BeamLattice.pid)
	, pindex(___CT_BeamLattice.pindex)
	, cap(___CT_BeamLattice.cap)
	, beams(std::move(___CT_BeamLattice.beams))
	, beamsets(std::move(___CT_BeamLattice.beamsets))
{ }
void Materialise::CT_BeamLattice::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("minlength", minlength);
	s.WriteAttr("radius", radius);
	if (clippingmode.has_value())
		s.WriteAttr("clippingmode", Materialise::ConvertST_ClippingModeToString(clippingmode.value()).c_str());
	if (clippingmesh.has_value())
		s.WriteAttr("clippingmesh", clippingmesh.value());
	if (representationmesh.has_value())
		s.WriteAttr("representationmesh", representationmesh.value());
	if (pid.has_value())
		s.WriteAttr("pid", pid.value());
	if (pindex.has_value())
		s.WriteAttr("pindex", pindex.value());
	if (cap.has_value())
		s.WriteAttr("cap", Materialise::ConvertST_CapModeToString(cap.value()).c_str());
	beams.Write(s, "beams");
	if (beamsets.has_value())
		beamsets.value().get()->Write(s, "beamsets");
}
bool Materialise::CT_BeamLattice::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	s.ReadAttrDouble("minlength", minlength);
	s.ReadAttrDouble("radius", radius);
	if (s.ReadAttrStr("clippingmode", __tmp_var)) 
		clippingmode = Materialise::ConvertStringToST_ClippingMode(__tmp_var);
	unsigned int __clippingmesh;
	if (s.ReadAttrUnsignedInt("clippingmesh", __clippingmesh))
		clippingmesh = std::optional<unsigned int> { __clippingmesh };
	unsigned int __representationmesh;
	if (s.ReadAttrUnsignedInt("representationmesh", __representationmesh))
		representationmesh = std::optional<unsigned int> { __representationmesh };
	unsigned int __pid;
	if (s.ReadAttrUnsignedInt("pid", __pid))
		pid = std::optional<unsigned int> { __pid };
	unsigned int __pindex;
	if (s.ReadAttrUnsignedInt("pindex", __pindex))
		pindex = std::optional<unsigned int> { __pindex };
	if (s.ReadAttrStr("cap", __tmp_var)) 
		cap = Materialise::ConvertStringToST_CapMode(__tmp_var);
	beams.Read(s, "beams");
	std::unique_ptr<Materialise::beamsets> __beamsets = std::make_unique<Materialise::beamsets>();
	if (__beamsets->Read(s, "beamsets"))
		beamsets = std::make_optional(std::move(__beamsets));
	return true;
}
Materialise::CT_Beam::CT_Beam(Materialise::CT_Beam &&___CT_Beam) noexcept
	: v1(___CT_Beam.v1)
	, v2(___CT_Beam.v2)
	, r1(___CT_Beam.r1)
	, r2(___CT_Beam.r2)
	, p1(___CT_Beam.p1)
	, p2(___CT_Beam.p2)
	, pid(___CT_Beam.pid)
	, cap1(___CT_Beam.cap1)
	, cap2(___CT_Beam.cap2)
{ }
void Materialise::CT_Beam::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("v1", v1);
	s.WriteAttr("v2", v2);
	if (r1.has_value())
		s.WriteAttr("r1", r1.value());
	if (r2.has_value())
		s.WriteAttr("r2", r2.value());
	if (p1.has_value())
		s.WriteAttr("p1", p1.value());
	if (p2.has_value())
		s.WriteAttr("p2", p2.value());
	if (pid.has_value())
		s.WriteAttr("pid", pid.value());
	if (cap1.has_value())
		s.WriteAttr("cap1", Materialise::ConvertST_CapModeToString(cap1.value()).c_str());
	if (cap2.has_value())
		s.WriteAttr("cap2", Materialise::ConvertST_CapModeToString(cap2.value()).c_str());
}
bool Materialise::CT_Beam::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	s.ReadAttrUnsignedInt("v1", v1);
	s.ReadAttrUnsignedInt("v2", v2);
	double __r1;
	if (s.ReadAttrDouble("r1", __r1))
		r1 = std::optional<double> { __r1 };
	double __r2;
	if (s.ReadAttrDouble("r2", __r2))
		r2 = std::optional<double> { __r2 };
	unsigned int __p1;
	if (s.ReadAttrUnsignedInt("p1", __p1))
		p1 = std::optional<unsigned int> { __p1 };
	unsigned int __p2;
	if (s.ReadAttrUnsignedInt("p2", __p2))
		p2 = std::optional<unsigned int> { __p2 };
	unsigned int __pid;
	if (s.ReadAttrUnsignedInt("pid", __pid))
		pid = std::optional<unsigned int> { __pid };
	if (s.ReadAttrStr("cap1", __tmp_var)) 
		cap1 = Materialise::ConvertStringToST_CapMode(__tmp_var);
	if (s.ReadAttrStr("cap2", __tmp_var)) 
		cap2 = Materialise::ConvertStringToST_CapMode(__tmp_var);
	return true;
}
Materialise::CT_Beams::CT_Beams(Materialise::CT_Beams &&___CT_Beams) noexcept
	: beam(std::move(___CT_Beams.beam))
{ }
void Materialise::CT_Beams::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : beam)
	{
		element.Write(s, "beam"); 
	}
}
bool Materialise::CT_Beams::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::beam __t;
		if (!__t.Read(s, "beam"))
			break;
		beam.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_BeamSet::CT_BeamSet(Materialise::CT_BeamSet &&___CT_BeamSet) noexcept
	: name(___CT_BeamSet.name)
	, identifier(___CT_BeamSet.identifier)
	, ref(std::move(___CT_BeamSet.ref))
{ }
void Materialise::CT_BeamSet::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (name.has_value())
		s.WriteAttr("name", name.value().c_str());
	if (identifier.has_value())
		s.WriteAttr("identifier", identifier.value().c_str());
	for(auto&& element : ref)
	{
		element.Write(s, "ref"); 
	}
}
bool Materialise::CT_BeamSet::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __name;
	if (s.ReadAttrStr("name", __name))
		name = std::optional<std::string> { __name };
	std::string __identifier;
	if (s.ReadAttrStr("identifier", __identifier))
		identifier = std::optional<std::string> { __identifier };
	while (true) { 
		Materialise::_ref __t;
		if (!__t.Read(s, "ref"))
			break;
		ref.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_BeamSets::CT_BeamSets(Materialise::CT_BeamSets &&___CT_BeamSets) noexcept
	: beamset(std::move(___CT_BeamSets.beamset))
{ }
void Materialise::CT_BeamSets::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : beamset)
	{
		element.Write(s, "beamset"); 
	}
}
bool Materialise::CT_BeamSets::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::beamset __t;
		if (!__t.Read(s, "beamset"))
			break;
		beamset.push_back(std::move(__t));
	}
	return true;
}
Materialise::CT_Ref::CT_Ref(Materialise::CT_Ref &&___CT_Ref) noexcept
	: index(___CT_Ref.index)
{ }
void Materialise::CT_Ref::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("index", index);
}
bool Materialise::CT_Ref::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("index", index);
	return true;
}
Materialise::beam::beam(Materialise::beam &&___beam) noexcept
	: v1(___beam.v1)
	, v2(___beam.v2)
	, r1(___beam.r1)
	, r2(___beam.r2)
	, p1(___beam.p1)
	, p2(___beam.p2)
	, pid(___beam.pid)
	, cap1(___beam.cap1)
	, cap2(___beam.cap2)
{ }
void Materialise::beam::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("v1", v1);
	s.WriteAttr("v2", v2);
	if (r1.has_value())
		s.WriteAttr("r1", r1.value());
	if (r2.has_value())
		s.WriteAttr("r2", r2.value());
	if (p1.has_value())
		s.WriteAttr("p1", p1.value());
	if (p2.has_value())
		s.WriteAttr("p2", p2.value());
	if (pid.has_value())
		s.WriteAttr("pid", pid.value());
	if (cap1.has_value())
		s.WriteAttr("cap1", Materialise::ConvertST_CapModeToString(cap1.value()).c_str());
	if (cap2.has_value())
		s.WriteAttr("cap2", Materialise::ConvertST_CapModeToString(cap2.value()).c_str());
}
bool Materialise::beam::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	s.ReadAttrUnsignedInt("v1", v1);
	s.ReadAttrUnsignedInt("v2", v2);
	double __r1;
	if (s.ReadAttrDouble("r1", __r1))
		r1 = std::optional<double> { __r1 };
	double __r2;
	if (s.ReadAttrDouble("r2", __r2))
		r2 = std::optional<double> { __r2 };
	unsigned int __p1;
	if (s.ReadAttrUnsignedInt("p1", __p1))
		p1 = std::optional<unsigned int> { __p1 };
	unsigned int __p2;
	if (s.ReadAttrUnsignedInt("p2", __p2))
		p2 = std::optional<unsigned int> { __p2 };
	unsigned int __pid;
	if (s.ReadAttrUnsignedInt("pid", __pid))
		pid = std::optional<unsigned int> { __pid };
	if (s.ReadAttrStr("cap1", __tmp_var)) 
		cap1 = Materialise::ConvertStringToST_CapMode(__tmp_var);
	if (s.ReadAttrStr("cap2", __tmp_var)) 
		cap2 = Materialise::ConvertStringToST_CapMode(__tmp_var);
	return true;
}
Materialise::beams::beams(Materialise::beams &&___beams) noexcept
	: beam(std::move(___beams.beam))
{ }
void Materialise::beams::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : beam)
	{
		element.Write(s, "beam"); 
	}
}
bool Materialise::beams::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::beam __t;
		if (!__t.Read(s, "beam"))
			break;
		beam.push_back(std::move(__t));
	}
	return true;
}
Materialise::_ref::_ref(Materialise::_ref &&____ref) noexcept
	: index(____ref.index)
{ }
void Materialise::_ref::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("index", index);
}
bool Materialise::_ref::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("index", index);
	return true;
}
Materialise::beamset::beamset(Materialise::beamset &&___beamset) noexcept
	: name(___beamset.name)
	, identifier(___beamset.identifier)
	, ref(std::move(___beamset.ref))
{ }
void Materialise::beamset::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (name.has_value())
		s.WriteAttr("name", name.value().c_str());
	if (identifier.has_value())
		s.WriteAttr("identifier", identifier.value().c_str());
	for(auto&& element : ref)
	{
		element.Write(s, "ref"); 
	}
}
bool Materialise::beamset::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __name;
	if (s.ReadAttrStr("name", __name))
		name = std::optional<std::string> { __name };
	std::string __identifier;
	if (s.ReadAttrStr("identifier", __identifier))
		identifier = std::optional<std::string> { __identifier };
	while (true) { 
		Materialise::_ref __t;
		if (!__t.Read(s, "ref"))
			break;
		ref.push_back(std::move(__t));
	}
	return true;
}
Materialise::beamsets::beamsets(Materialise::beamsets &&___beamsets) noexcept
	: beamset(std::move(___beamsets.beamset))
{ }
void Materialise::beamsets::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : beamset)
	{
		element.Write(s, "beamset"); 
	}
}
bool Materialise::beamsets::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::beamset __t;
		if (!__t.Read(s, "beamset"))
			break;
		beamset.push_back(std::move(__t));
	}
	return true;
}
Materialise::beamlattice::beamlattice(Materialise::beamlattice &&___beamlattice) noexcept
	: minlength(___beamlattice.minlength)
	, radius(___beamlattice.radius)
	, clippingmode(___beamlattice.clippingmode)
	, clippingmesh(___beamlattice.clippingmesh)
	, representationmesh(___beamlattice.representationmesh)
	, pid(___beamlattice.pid)
	, pindex(___beamlattice.pindex)
	, cap(___beamlattice.cap)
	, beams(std::move(___beamlattice.beams))
	, beamsets(std::move(___beamlattice.beamsets))
{ }
void Materialise::beamlattice::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("minlength", minlength);
	s.WriteAttr("radius", radius);
	if (clippingmode.has_value())
		s.WriteAttr("clippingmode", Materialise::ConvertST_ClippingModeToString(clippingmode.value()).c_str());
	if (clippingmesh.has_value())
		s.WriteAttr("clippingmesh", clippingmesh.value());
	if (representationmesh.has_value())
		s.WriteAttr("representationmesh", representationmesh.value());
	if (pid.has_value())
		s.WriteAttr("pid", pid.value());
	if (pindex.has_value())
		s.WriteAttr("pindex", pindex.value());
	if (cap.has_value())
		s.WriteAttr("cap", Materialise::ConvertST_CapModeToString(cap.value()).c_str());
	beams.Write(s, "beams");
	if (beamsets.has_value())
		beamsets.value().get()->Write(s, "beamsets");
}
bool Materialise::beamlattice::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	s.ReadAttrDouble("minlength", minlength);
	s.ReadAttrDouble("radius", radius);
	if (s.ReadAttrStr("clippingmode", __tmp_var)) 
		clippingmode = Materialise::ConvertStringToST_ClippingMode(__tmp_var);
	unsigned int __clippingmesh;
	if (s.ReadAttrUnsignedInt("clippingmesh", __clippingmesh))
		clippingmesh = std::optional<unsigned int> { __clippingmesh };
	unsigned int __representationmesh;
	if (s.ReadAttrUnsignedInt("representationmesh", __representationmesh))
		representationmesh = std::optional<unsigned int> { __representationmesh };
	unsigned int __pid;
	if (s.ReadAttrUnsignedInt("pid", __pid))
		pid = std::optional<unsigned int> { __pid };
	unsigned int __pindex;
	if (s.ReadAttrUnsignedInt("pindex", __pindex))
		pindex = std::optional<unsigned int> { __pindex };
	if (s.ReadAttrStr("cap", __tmp_var)) 
		cap = Materialise::ConvertStringToST_CapMode(__tmp_var);
	beams.Read(s, "beams");
	std::unique_ptr<Materialise::beamsets> __beamsets = std::make_unique<Materialise::beamsets>();
	if (__beamsets->Read(s, "beamsets"))
		beamsets = std::make_optional(std::move(__beamsets));
	return true;
}
