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
	enum class MeterType {
		undefined,
		boolean,
		integer,
		_double,
		_string,
		utcDateTime,
		duration,
		mm,
		degreesCelsius,
	};

	MeterType ConvertStringToMeterType(std::string str) {
		if (str == "undefined") return MeterType::undefined;
		if (str == "boolean") return MeterType::boolean;
		if (str == "integer") return MeterType::integer;
		if (str == "double") return MeterType::_double;
		if (str == "string") return MeterType::_string;
		if (str == "utcDateTime") return MeterType::utcDateTime;
		if (str == "duration") return MeterType::duration;
		if (str == "mm") return MeterType::mm;
		if (str == "degreesCelsius") return MeterType::degreesCelsius;
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertMeterTypeToString(MeterType e) {
		if (e == MeterType::undefined) return "undefined";
		if (e == MeterType::boolean) return "boolean";
		if (e == MeterType::integer) return "integer";
		if (e == MeterType::_double) return "double";
		if (e == MeterType::_string) return "string";
		if (e == MeterType::utcDateTime) return "utcDateTime";
		if (e == MeterType::duration) return "duration";
		if (e == MeterType::mm) return "mm";
		if (e == MeterType::degreesCelsius) return "degreesCelsius";
		throw std::exception("Can't convert enum value to string");
	}

	struct Meters;
	struct Meter;
	struct MeterDefinition;
	struct MeterDefinitions;
	struct MeterValues;
	struct _Value;
	struct DriverMeters;
	struct MeterDefinitions {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<std::string> count {""};
		std::vector<Materialise::MeterDefinition> Meter;
		MeterDefinitions() {}
		~MeterDefinitions() {}
	};
	struct DriverMeters {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		Materialise::MeterDefinitions Meters;
		DriverMeters() {}
		~DriverMeters() {}
	};
	struct _Value {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string meter;
		_Value() {}
		~_Value() {}
	};
	struct MeterValues {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<std::string> count {""};
		std::vector<Materialise::_Value> Value;
		MeterValues() {}
		~MeterValues() {}
	};
	struct MeterDefinition {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string id;
		std::string name;
		Materialise::MeterType type;
		MeterDefinition() {}
		~MeterDefinition() {}
	};
	struct Meter {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string id;
		std::string name;
		Materialise::MeterType type;
		Meter() {}
		~Meter() {}
	};
	struct Meters {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<std::string> count {""};
		std::vector<Materialise::Meter> Meter;
		Meters() {}
		~Meters() {}
	};
}
void Materialise::Meters::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (count.has_value())
		s.WriteAttr("count", count.value().c_str());
	for(int i = 0;i < Meter.size();i++)
	{
		Meter[i].Write(s, "Meter"); 
	}
}
bool Materialise::Meters::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	count = s.ReadAttrStr("count");
	while (true) { 
		Materialise::Meter __t;
		if (__t.Read(s, "Meter") == false)
			break;
		Meter.push_back(__t);
	}
	return true;
}
void Materialise::Meter::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id.c_str());
	s.WriteAttr("name", name.c_str());
	s.WriteAttr("type", Materialise::ConvertMeterTypeToString(type).c_str());
}
bool Materialise::Meter::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	id = s.ReadAttrStr("id");
	name = s.ReadAttrStr("name");
	type = Materialise::ConvertStringToMeterType(s.ReadAttrStr("type"));
	return true;
}
void Materialise::MeterDefinition::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id.c_str());
	s.WriteAttr("name", name.c_str());
	s.WriteAttr("type", Materialise::ConvertMeterTypeToString(type).c_str());
}
bool Materialise::MeterDefinition::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	id = s.ReadAttrStr("id");
	name = s.ReadAttrStr("name");
	type = Materialise::ConvertStringToMeterType(s.ReadAttrStr("type"));
	return true;
}
void Materialise::MeterDefinitions::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (count.has_value())
		s.WriteAttr("count", count.value().c_str());
	for(int i = 0;i < Meter.size();i++)
	{
		Meter[i].Write(s, "Meter"); 
	}
}
bool Materialise::MeterDefinitions::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	count = s.ReadAttrStr("count");
	while (true) { 
		Materialise::MeterDefinition __t;
		if (__t.Read(s, "Meter") == false)
			break;
		Meter.push_back(__t);
	}
	return true;
}
void Materialise::MeterValues::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (count.has_value())
		s.WriteAttr("count", count.value().c_str());
	for(int i = 0;i < Value.size();i++)
	{
		Value[i].Write(s, "Value"); 
	}
}
bool Materialise::MeterValues::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	count = s.ReadAttrStr("count");
	while (true) { 
		Materialise::_Value __t;
		if (__t.Read(s, "Value") == false)
			break;
		Value.push_back(__t);
	}
	return true;
}
void Materialise::_Value::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("meter", meter.c_str());
}
bool Materialise::_Value::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	meter = s.ReadAttrStr("meter");
	return true;
}
void Materialise::DriverMeters::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	Meters.Write(s, "Meters");
}
bool Materialise::DriverMeters::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	Meters.Read(s, "Meters");
	return true;
}
