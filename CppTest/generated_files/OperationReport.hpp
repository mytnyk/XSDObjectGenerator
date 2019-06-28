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

	enum class LogEntryType {
		Information,
		Warning,
		Error,
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

	LogEntryType ConvertStringToLogEntryType(std::string str) {
		if (str == "Information") return LogEntryType::Information;
		if (str == "Warning") return LogEntryType::Warning;
		if (str == "Error") return LogEntryType::Error;
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertLogEntryTypeToString(LogEntryType e) {
		if (e == LogEntryType::Information) return "Information";
		if (e == LogEntryType::Warning) return "Warning";
		if (e == LogEntryType::Error) return "Error";
		throw std::exception("Can't convert enum value to string");
	}

	struct Meters;
	struct Meter;
	struct MeterDefinition;
	struct MeterDefinitions;
	struct MeterValues;
	struct _Value;
	struct Log;
	struct Entries;
	struct LogEntry;
	struct OperationReport;
	struct OperationReportMeterValues;
	struct OperationReportMeterValuesValue;
	struct OperationReportMeterValuesValue {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string meter;
		OperationReportMeterValuesValue() {}
		~OperationReportMeterValuesValue() {}
	};
	struct OperationReportMeterValues {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::string> count {""};
		std::vector<Materialise::OperationReportMeterValuesValue> Value;
		OperationReportMeterValues() {}
		~OperationReportMeterValues() {}
	};
	struct OperationReport {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Title;
		std::optional<std::string> Description {""};
		double Progress;
		std::optional<std::string> UploadId {""};
		std::optional<std::string> UploadLocation {""};
		std::optional<std::reference_wrapper<Materialise::OperationReportMeterValues>> MeterValues;
		std::optional<std::reference_wrapper<Materialise::Log>> Log;
		OperationReport() {}
		~OperationReport() {}
	};
	struct LogEntry {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		Materialise::LogEntryType type;
		std::optional<std::string> source {""};
		std::optional<std::string> category {""};
		std::optional<std::string> message {""};
		std::optional<std::reference_wrapper<Materialise::MeterValues>> Meters;
		LogEntry() {}
		~LogEntry() {}
	};
	struct Entries {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::string> count {""};
		std::vector<Materialise::LogEntry> Entry;
		Entries() {}
		~Entries() {}
	};
	struct Log {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::reference_wrapper<Materialise::MeterDefinitions>> Meters;
		std::optional<std::reference_wrapper<Materialise::Entries>> Entries;
		Log() {}
		~Log() {}
	};
	struct _Value {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string meter;
		_Value() {}
		~_Value() {}
	};
	struct MeterValues {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::string> count {""};
		std::vector<Materialise::_Value> Value;
		MeterValues() {}
		~MeterValues() {}
	};
	struct MeterDefinitions {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::string> count {""};
		std::vector<Materialise::MeterDefinition> Meter;
		MeterDefinitions() {}
		~MeterDefinitions() {}
	};
	struct MeterDefinition {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string id;
		std::string name;
		Materialise::MeterType type;
		MeterDefinition() {}
		~MeterDefinition() {}
	};
	struct Meter {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string id;
		std::string name;
		Materialise::MeterType type;
		Meter() {}
		~Meter() {}
	};
	struct Meters {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::string> count {""};
		std::vector<Materialise::Meter> Meter;
		Meters() {}
		~Meters() {}
	};
}
void Materialise::Meters::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Meters");
	s.WriteAttr("count", count.value().c_str());
	for(int i = 0;i < Meter.size();i++)
	{
		Meter[i].Write(s); 
	}
}
bool Materialise::Meters::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Meters");
	if (scope.exist() == false)
		return false;
	count = s.ReadAttrStr("count");
	while (true) { 
		Materialise::Meter __t;
		if (__t.Read(s) == false)
			break;
		Meter.push_back(__t);
	}
	return true;
}
void Materialise::Meter::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Meter");
	s.WriteAttr("id", id.c_str());
	s.WriteAttr("name", name.c_str());
	s.WriteAttr("type", Materialise::ConvertMeterTypeToString(type).c_str());
}
bool Materialise::Meter::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Meter");
	if (scope.exist() == false)
		return false;
	id = s.ReadAttrStr("id");
	name = s.ReadAttrStr("name");
	type = Materialise::ConvertStringToMeterType(s.ReadAttrStr("type"));
	return true;
}
void Materialise::MeterDefinition::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "MeterDefinition");
	s.WriteAttr("id", id.c_str());
	s.WriteAttr("name", name.c_str());
	s.WriteAttr("type", Materialise::ConvertMeterTypeToString(type).c_str());
}
bool Materialise::MeterDefinition::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "MeterDefinition");
	if (scope.exist() == false)
		return false;
	id = s.ReadAttrStr("id");
	name = s.ReadAttrStr("name");
	type = Materialise::ConvertStringToMeterType(s.ReadAttrStr("type"));
	return true;
}
void Materialise::MeterDefinitions::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "MeterDefinitions");
	s.WriteAttr("count", count.value().c_str());
	for(int i = 0;i < Meter.size();i++)
	{
		Meter[i].Write(s); 
	}
}
bool Materialise::MeterDefinitions::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "MeterDefinitions");
	if (scope.exist() == false)
		return false;
	count = s.ReadAttrStr("count");
	while (true) { 
		Materialise::MeterDefinition __t;
		if (__t.Read(s) == false)
			break;
		Meter.push_back(__t);
	}
	return true;
}
void Materialise::MeterValues::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "MeterValues");
	s.WriteAttr("count", count.value().c_str());
	for(int i = 0;i < Value.size();i++)
	{
		Value[i].Write(s); 
	}
}
bool Materialise::MeterValues::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "MeterValues");
	if (scope.exist() == false)
		return false;
	count = s.ReadAttrStr("count");
	while (true) { 
		Materialise::_Value __t;
		if (__t.Read(s) == false)
			break;
		Value.push_back(__t);
	}
	return true;
}
void Materialise::_Value::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "_Value");
	s.WriteAttr("meter", meter.c_str());
}
bool Materialise::_Value::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "_Value");
	if (scope.exist() == false)
		return false;
	meter = s.ReadAttrStr("meter");
	return true;
}
void Materialise::Log::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Log");
	Meters.value().get().Write(s);
	Entries.value().get().Write(s);
}
bool Materialise::Log::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Log");
	if (scope.exist() == false)
		return false;
	Materialise::MeterDefinitions* __Meters = new Materialise::MeterDefinitions();
	__Meters->Read(s);
	Meters = std::optional<std::reference_wrapper<Materialise::MeterDefinitions>> { *__Meters };
	Materialise::Entries* __Entries = new Materialise::Entries();
	__Entries->Read(s);
	Entries = std::optional<std::reference_wrapper<Materialise::Entries>> { *__Entries };
	return true;
}
void Materialise::Entries::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Entries");
	s.WriteAttr("count", count.value().c_str());
	for(int i = 0;i < Entry.size();i++)
	{
		Entry[i].Write(s); 
	}
}
bool Materialise::Entries::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Entries");
	if (scope.exist() == false)
		return false;
	count = s.ReadAttrStr("count");
	while (true) { 
		Materialise::LogEntry __t;
		if (__t.Read(s) == false)
			break;
		Entry.push_back(__t);
	}
	return true;
}
void Materialise::LogEntry::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "LogEntry");
	s.WriteAttr("type", Materialise::ConvertLogEntryTypeToString(type).c_str());
	s.WriteAttr("source", source.value().c_str());
	s.WriteAttr("category", category.value().c_str());
	s.WriteAttr("message", message.value().c_str());
	Meters.value().get().Write(s);
}
bool Materialise::LogEntry::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "LogEntry");
	if (scope.exist() == false)
		return false;
	type = Materialise::ConvertStringToLogEntryType(s.ReadAttrStr("type"));
	source = s.ReadAttrStr("source");
	category = s.ReadAttrStr("category");
	message = s.ReadAttrStr("message");
	Materialise::MeterValues* __Meters = new Materialise::MeterValues();
	__Meters->Read(s);
	Meters = std::optional<std::reference_wrapper<Materialise::MeterValues>> { *__Meters };
	return true;
}
void Materialise::OperationReport::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "OperationReport");
	s.Write("Title", Title.c_str());
	s.Write("Description", Description.value().c_str());
	s.Write("Progress", Progress);
	s.Write("UploadId", UploadId.value().c_str());
	s.Write("UploadLocation", UploadLocation.value().c_str());
	MeterValues.value().get().Write(s);
	Log.value().get().Write(s);
}
bool Materialise::OperationReport::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "OperationReport");
	if (scope.exist() == false)
		return false;
	s.ReadStr("Title", Title);
	s.ReadStr("Description", Description.value());
	s.ReadDouble("Progress", Progress);
	s.ReadStr("UploadId", UploadId.value());
	s.ReadStr("UploadLocation", UploadLocation.value());
	Materialise::OperationReportMeterValues* __MeterValues = new Materialise::OperationReportMeterValues();
	__MeterValues->Read(s);
	MeterValues = std::optional<std::reference_wrapper<Materialise::OperationReportMeterValues>> { *__MeterValues };
	Materialise::Log* __Log = new Materialise::Log();
	__Log->Read(s);
	Log = std::optional<std::reference_wrapper<Materialise::Log>> { *__Log };
	return true;
}
void Materialise::OperationReportMeterValues::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "OperationReportMeterValues");
	s.WriteAttr("count", count.value().c_str());
	for(int i = 0;i < Value.size();i++)
	{
		Value[i].Write(s); 
	}
}
bool Materialise::OperationReportMeterValues::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "OperationReportMeterValues");
	if (scope.exist() == false)
		return false;
	count = s.ReadAttrStr("count");
	while (true) { 
		Materialise::OperationReportMeterValuesValue __t;
		if (__t.Read(s) == false)
			break;
		Value.push_back(__t);
	}
	return true;
}
void Materialise::OperationReportMeterValuesValue::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "OperationReportMeterValuesValue");
	s.WriteAttr("meter", meter.c_str());
}
bool Materialise::OperationReportMeterValuesValue::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "OperationReportMeterValuesValue");
	if (scope.exist() == false)
		return false;
	meter = s.ReadAttrStr("meter");
	return true;
}
