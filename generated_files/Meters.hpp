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
	const std::string schema_generated_files_Meters_namespace = "urn:Print3D";
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
	struct _Value {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		_Value(const _Value&) = delete;
		_Value& operator=(_Value&&) = delete;
		_Value& operator=(_Value&) = delete;
		_Value(_Value&&) noexcept;
		_Value() = default;
		~_Value() = default;
		std::string meter;
	};
	struct MeterValues {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		MeterValues(const MeterValues&) = delete;
		MeterValues& operator=(MeterValues&&) = delete;
		MeterValues& operator=(MeterValues&) = delete;
		MeterValues(MeterValues&&) noexcept;
		MeterValues() = default;
		~MeterValues() = default;
		std::optional<unsigned int> count;
		std::vector<_Value> Value;
	};
	struct MeterDefinitions {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		MeterDefinitions(const MeterDefinitions&) = delete;
		MeterDefinitions& operator=(MeterDefinitions&&) = delete;
		MeterDefinitions& operator=(MeterDefinitions&) = delete;
		MeterDefinitions(MeterDefinitions&&) noexcept;
		MeterDefinitions() = default;
		~MeterDefinitions() = default;
		std::optional<unsigned int> count;
		std::vector<MeterDefinition> Meter;
	};
	struct MeterDefinition {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		MeterDefinition(const MeterDefinition&) = delete;
		MeterDefinition& operator=(MeterDefinition&&) = delete;
		MeterDefinition& operator=(MeterDefinition&) = delete;
		MeterDefinition(MeterDefinition&&) noexcept;
		MeterDefinition() = default;
		~MeterDefinition() = default;
		std::string id;
		std::string name;
		Materialise::MeterType type;
	};
	struct Meter {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Meter(const Meter&) = delete;
		Meter& operator=(Meter&&) = delete;
		Meter& operator=(Meter&) = delete;
		Meter(Meter&&) noexcept;
		Meter() = default;
		~Meter() = default;
		std::string id;
		std::string name;
		Materialise::MeterType type;
	};
	struct Meters {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Meters(const Meters&) = delete;
		Meters& operator=(Meters&&) = delete;
		Meters& operator=(Meters&) = delete;
		Meters(Meters&&) noexcept;
		Meters() = default;
		~Meters() = default;
		std::optional<unsigned int> count;
		std::vector<Meter> Meter;
	};
}
Materialise::Meters::Meters(Materialise::Meters &&___Meters) noexcept
	: count(___Meters.count)
	, Meter(std::move(___Meters.Meter))
{ }
void Materialise::Meters::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (count.has_value())
		s.WriteAttr("count", count.value());
	for(auto&& element : Meter)
	{
		element.Write(s, "Meter"); 
	}
}
bool Materialise::Meters::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	unsigned int __count;
	if (s.ReadAttrUnsignedInt("count", __count))
		count = std::optional<unsigned int> { __count };
	while (true) { 
		Materialise::Meter __t;
		if (!__t.Read(s, "Meter"))
			break;
		Meter.push_back(std::move(__t));
	}
	return true;
}
Materialise::Meter::Meter(Materialise::Meter &&___Meter) noexcept
	: id(___Meter.id)
	, name(___Meter.name)
	, type(___Meter.type)
{ }
void Materialise::Meter::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id.c_str());
	s.WriteAttr("name", name.c_str());
	s.WriteAttr("type", Materialise::ConvertMeterTypeToString(type).c_str());
}
bool Materialise::Meter::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	s.ReadAttrStr("id", id);
	s.ReadAttrStr("name", name);
	if (s.ReadAttrStr("type", __tmp_var)) 
		type = Materialise::ConvertStringToMeterType(__tmp_var);
	return true;
}
Materialise::MeterDefinition::MeterDefinition(Materialise::MeterDefinition &&___MeterDefinition) noexcept
	: id(___MeterDefinition.id)
	, name(___MeterDefinition.name)
	, type(___MeterDefinition.type)
{ }
void Materialise::MeterDefinition::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id.c_str());
	s.WriteAttr("name", name.c_str());
	s.WriteAttr("type", Materialise::ConvertMeterTypeToString(type).c_str());
}
bool Materialise::MeterDefinition::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	s.ReadAttrStr("id", id);
	s.ReadAttrStr("name", name);
	if (s.ReadAttrStr("type", __tmp_var)) 
		type = Materialise::ConvertStringToMeterType(__tmp_var);
	return true;
}
Materialise::MeterDefinitions::MeterDefinitions(Materialise::MeterDefinitions &&___MeterDefinitions) noexcept
	: count(___MeterDefinitions.count)
	, Meter(std::move(___MeterDefinitions.Meter))
{ }
void Materialise::MeterDefinitions::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (count.has_value())
		s.WriteAttr("count", count.value());
	for(auto&& element : Meter)
	{
		element.Write(s, "Meter"); 
	}
}
bool Materialise::MeterDefinitions::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	unsigned int __count;
	if (s.ReadAttrUnsignedInt("count", __count))
		count = std::optional<unsigned int> { __count };
	while (true) { 
		Materialise::MeterDefinition __t;
		if (!__t.Read(s, "Meter"))
			break;
		Meter.push_back(std::move(__t));
	}
	return true;
}
Materialise::MeterValues::MeterValues(Materialise::MeterValues &&___MeterValues) noexcept
	: count(___MeterValues.count)
	, Value(std::move(___MeterValues.Value))
{ }
void Materialise::MeterValues::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (count.has_value())
		s.WriteAttr("count", count.value());
	for(auto&& element : Value)
	{
		element.Write(s, "Value"); 
	}
}
bool Materialise::MeterValues::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	unsigned int __count;
	if (s.ReadAttrUnsignedInt("count", __count))
		count = std::optional<unsigned int> { __count };
	while (true) { 
		Materialise::_Value __t;
		if (!__t.Read(s, "Value"))
			break;
		Value.push_back(std::move(__t));
	}
	return true;
}
Materialise::_Value::_Value(Materialise::_Value &&____Value) noexcept
	: meter(____Value.meter)
{ }
void Materialise::_Value::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("meter", meter.c_str());
}
bool Materialise::_Value::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("meter", meter);
	return true;
}
