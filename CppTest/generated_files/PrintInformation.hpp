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
	struct PrintInformationMeterStates;
	struct States;
	struct PrintInformationMeterState;
	struct PrintInformationPrintedLayers;
	struct PrintInformationPrintedLayer;
	struct PrintInformation;
	struct PrintInformation {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::reference_wrapper<Materialise::MeterDefinitions>> Meters;
		std::optional<std::reference_wrapper<Materialise::Log>> Log;
		std::optional<std::reference_wrapper<Materialise::MeterValues>> MeterValues;
		std::optional<std::reference_wrapper<Materialise::PrintInformationMeterStates>> MeterStates;
		std::optional<std::reference_wrapper<Materialise::PrintInformationPrintedLayers>> PrintedLayers;
		PrintInformation() {}
		~PrintInformation() {}
	};
	struct PrintInformationPrintedLayer {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string index;
		std::optional<std::reference_wrapper<Materialise::MeterValues>> MeterValues;
		PrintInformationPrintedLayer() {}
		~PrintInformationPrintedLayer() {}
	};
	struct PrintInformationPrintedLayers {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::string> count {""};
		std::string total;
		std::vector<Materialise::PrintInformationPrintedLayer> Layer;
		PrintInformationPrintedLayers() {}
		~PrintInformationPrintedLayers() {}
	};
	struct PrintInformationMeterState {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		PrintInformationMeterState() {}
		~PrintInformationMeterState() {}
	};
	struct States {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string meter;
		std::optional<std::string> count {""};
		std::vector<Materialise::PrintInformationMeterState> State;
		States() {}
		~States() {}
	};
	struct PrintInformationMeterStates {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::string> count {""};
		std::vector<Materialise::States> States;
		PrintInformationMeterStates() {}
		~PrintInformationMeterStates() {}
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
void Materialise::PrintInformationMeterStates::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "PrintInformationMeterStates");
	s.WriteAttr("count", count.value().c_str());
	for(int i = 0;i < States.size();i++)
	{
		States[i].Write(s); 
	}
}
bool Materialise::PrintInformationMeterStates::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "PrintInformationMeterStates");
	if (scope.exist() == false)
		return false;
	count = s.ReadAttrStr("count");
	while (true) { 
		Materialise::States __t;
		if (__t.Read(s) == false)
			break;
		States.push_back(__t);
	}
	return true;
}
void Materialise::States::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "States");
	s.WriteAttr("meter", meter.c_str());
	s.WriteAttr("count", count.value().c_str());
	for(int i = 0;i < State.size();i++)
	{
		State[i].Write(s); 
	}
}
bool Materialise::States::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "States");
	if (scope.exist() == false)
		return false;
	meter = s.ReadAttrStr("meter");
	count = s.ReadAttrStr("count");
	while (true) { 
		Materialise::PrintInformationMeterState __t;
		if (__t.Read(s) == false)
			break;
		State.push_back(__t);
	}
	return true;
}
void Materialise::PrintInformationMeterState::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "PrintInformationMeterState");
}
bool Materialise::PrintInformationMeterState::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "PrintInformationMeterState");
	if (scope.exist() == false)
		return false;
	return true;
}
void Materialise::PrintInformationPrintedLayers::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "PrintInformationPrintedLayers");
	s.WriteAttr("count", count.value().c_str());
	s.WriteAttr("total", total.c_str());
	for(int i = 0;i < Layer.size();i++)
	{
		Layer[i].Write(s); 
	}
}
bool Materialise::PrintInformationPrintedLayers::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "PrintInformationPrintedLayers");
	if (scope.exist() == false)
		return false;
	count = s.ReadAttrStr("count");
	total = s.ReadAttrStr("total");
	while (true) { 
		Materialise::PrintInformationPrintedLayer __t;
		if (__t.Read(s) == false)
			break;
		Layer.push_back(__t);
	}
	return true;
}
void Materialise::PrintInformationPrintedLayer::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "PrintInformationPrintedLayer");
	s.WriteAttr("index", index.c_str());
	MeterValues.value().get().Write(s);
}
bool Materialise::PrintInformationPrintedLayer::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "PrintInformationPrintedLayer");
	if (scope.exist() == false)
		return false;
	index = s.ReadAttrStr("index");
	Materialise::MeterValues* __MeterValues = new Materialise::MeterValues();
	__MeterValues->Read(s);
	MeterValues = std::optional<std::reference_wrapper<Materialise::MeterValues>> { *__MeterValues };
	return true;
}
void Materialise::PrintInformation::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "PrintInformation");
	Meters.value().get().Write(s);
	Log.value().get().Write(s);
	MeterValues.value().get().Write(s);
	MeterStates.value().get().Write(s);
	PrintedLayers.value().get().Write(s);
}
bool Materialise::PrintInformation::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "PrintInformation");
	if (scope.exist() == false)
		return false;
	Materialise::MeterDefinitions* __Meters = new Materialise::MeterDefinitions();
	__Meters->Read(s);
	Meters = std::optional<std::reference_wrapper<Materialise::MeterDefinitions>> { *__Meters };
	Materialise::Log* __Log = new Materialise::Log();
	__Log->Read(s);
	Log = std::optional<std::reference_wrapper<Materialise::Log>> { *__Log };
	Materialise::MeterValues* __MeterValues = new Materialise::MeterValues();
	__MeterValues->Read(s);
	MeterValues = std::optional<std::reference_wrapper<Materialise::MeterValues>> { *__MeterValues };
	Materialise::PrintInformationMeterStates* __MeterStates = new Materialise::PrintInformationMeterStates();
	__MeterStates->Read(s);
	MeterStates = std::optional<std::reference_wrapper<Materialise::PrintInformationMeterStates>> { *__MeterStates };
	Materialise::PrintInformationPrintedLayers* __PrintedLayers = new Materialise::PrintInformationPrintedLayers();
	__PrintedLayers->Read(s);
	PrintedLayers = std::optional<std::reference_wrapper<Materialise::PrintInformationPrintedLayers>> { *__PrintedLayers };
	return true;
}
