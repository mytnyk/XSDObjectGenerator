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
	const std::string schema_generated_files3_PrintInformation_namespace = "urn:Print3D";
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
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<std::reference_wrapper<Materialise::MeterDefinitions>> Meters;
		std::optional<std::reference_wrapper<Materialise::Log>> Log;
		std::optional<std::reference_wrapper<Materialise::MeterValues>> MeterValues;
		std::optional<std::reference_wrapper<Materialise::PrintInformationMeterStates>> MeterStates;
		std::optional<std::reference_wrapper<Materialise::PrintInformationPrintedLayers>> PrintedLayers;
		PrintInformation() {}
		~PrintInformation() {}
	};
	struct PrintInformationPrintedLayer {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		unsigned int index;
		std::optional<std::reference_wrapper<Materialise::MeterValues>> MeterValues;
		PrintInformationPrintedLayer() {}
		~PrintInformationPrintedLayer() {}
	};
	struct PrintInformationPrintedLayers {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<unsigned int> count;
		unsigned int total;
		std::vector<Materialise::PrintInformationPrintedLayer> Layer;
		PrintInformationPrintedLayers() {}
		~PrintInformationPrintedLayers() {}
	};
	struct PrintInformationMeterState {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		PrintInformationMeterState() {}
		~PrintInformationMeterState() {}
	};
	struct States {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string meter;
		std::optional<unsigned int> count;
		std::vector<Materialise::PrintInformationMeterState> State;
		States() {}
		~States() {}
	};
	struct PrintInformationMeterStates {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<unsigned int> count;
		std::vector<Materialise::States> States;
		PrintInformationMeterStates() {}
		~PrintInformationMeterStates() {}
	};
	struct LogEntry {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		Materialise::LogEntryType type;
		std::optional<std::string> source;
		std::optional<std::string> category;
		std::optional<std::string> message;
		std::optional<std::reference_wrapper<Materialise::MeterValues>> Meters;
		LogEntry() {}
		~LogEntry() {}
	};
	struct Entries {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<unsigned int> count;
		std::vector<Materialise::LogEntry> Entry;
		Entries() {}
		~Entries() {}
	};
	struct Log {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<std::reference_wrapper<Materialise::MeterDefinitions>> Meters;
		std::optional<std::reference_wrapper<Materialise::Entries>> Entries;
		Log() {}
		~Log() {}
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
		std::optional<unsigned int> count;
		std::vector<Materialise::_Value> Value;
		MeterValues() {}
		~MeterValues() {}
	};
	struct MeterDefinitions {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<unsigned int> count;
		std::vector<Materialise::MeterDefinition> Meter;
		MeterDefinitions() {}
		~MeterDefinitions() {}
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
		std::optional<unsigned int> count;
		std::vector<Materialise::Meter> Meter;
		Meters() {}
		~Meters() {}
	};
}
void Materialise::Meters::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (count.has_value())
		s.WriteAttr("count", count.value());
	for(int i = 0;i < Meter.size();i++)
	{
		Meter[i].Write(s, "Meter"); 
	}
}
bool Materialise::Meters::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	unsigned int* __count = new unsigned int();
	if (s.ReadAttrUnsignedInt("count", *__count))
		count = std::optional<std::reference_wrapper<unsigned int>> { *__count };
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
	std::string __tmp_var;
	s.ReadAttrStr("id", id);
	s.ReadAttrStr("name", name);
	if (s.ReadAttrStr("type", __tmp_var)) 
		type = Materialise::ConvertStringToMeterType(__tmp_var);
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
	std::string __tmp_var;
	s.ReadAttrStr("id", id);
	s.ReadAttrStr("name", name);
	if (s.ReadAttrStr("type", __tmp_var)) 
		type = Materialise::ConvertStringToMeterType(__tmp_var);
	return true;
}
void Materialise::MeterDefinitions::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (count.has_value())
		s.WriteAttr("count", count.value());
	for(int i = 0;i < Meter.size();i++)
	{
		Meter[i].Write(s, "Meter"); 
	}
}
bool Materialise::MeterDefinitions::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	unsigned int* __count = new unsigned int();
	if (s.ReadAttrUnsignedInt("count", *__count))
		count = std::optional<std::reference_wrapper<unsigned int>> { *__count };
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
		s.WriteAttr("count", count.value());
	for(int i = 0;i < Value.size();i++)
	{
		Value[i].Write(s, "Value"); 
	}
}
bool Materialise::MeterValues::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	unsigned int* __count = new unsigned int();
	if (s.ReadAttrUnsignedInt("count", *__count))
		count = std::optional<std::reference_wrapper<unsigned int>> { *__count };
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
	s.ReadAttrStr("meter", meter);
	return true;
}
void Materialise::Log::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (Meters.has_value())
		Meters.value().get().Write(s, "Meters");
	if (Entries.has_value())
		Entries.value().get().Write(s, "Entries");
}
bool Materialise::Log::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	Materialise::MeterDefinitions* __Meters = new Materialise::MeterDefinitions();
	__Meters->Read(s, "Meters");
	Meters = std::optional<std::reference_wrapper<Materialise::MeterDefinitions>> { *__Meters };
	Materialise::Entries* __Entries = new Materialise::Entries();
	__Entries->Read(s, "Entries");
	Entries = std::optional<std::reference_wrapper<Materialise::Entries>> { *__Entries };
	return true;
}
void Materialise::Entries::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (count.has_value())
		s.WriteAttr("count", count.value());
	for(int i = 0;i < Entry.size();i++)
	{
		Entry[i].Write(s, "Entry"); 
	}
}
bool Materialise::Entries::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	unsigned int* __count = new unsigned int();
	if (s.ReadAttrUnsignedInt("count", *__count))
		count = std::optional<std::reference_wrapper<unsigned int>> { *__count };
	while (true) { 
		Materialise::LogEntry __t;
		if (__t.Read(s, "Entry") == false)
			break;
		Entry.push_back(__t);
	}
	return true;
}
void Materialise::LogEntry::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("type", Materialise::ConvertLogEntryTypeToString(type).c_str());
	if (source.has_value())
		s.WriteAttr("source", source.value().c_str());
	if (category.has_value())
		s.WriteAttr("category", category.value().c_str());
	if (message.has_value())
		s.WriteAttr("message", message.value().c_str());
	if (Meters.has_value())
		Meters.value().get().Write(s, "Meters");
}
bool Materialise::LogEntry::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	std::string __tmp_var;
	if (s.ReadAttrStr("type", __tmp_var)) 
		type = Materialise::ConvertStringToLogEntryType(__tmp_var);
	std::string* __source = new std::string();
	if (s.ReadAttrStr("source", *__source))
		source = std::optional<std::reference_wrapper<std::string>> { *__source };
	std::string* __category = new std::string();
	if (s.ReadAttrStr("category", *__category))
		category = std::optional<std::reference_wrapper<std::string>> { *__category };
	std::string* __message = new std::string();
	if (s.ReadAttrStr("message", *__message))
		message = std::optional<std::reference_wrapper<std::string>> { *__message };
	Materialise::MeterValues* __Meters = new Materialise::MeterValues();
	__Meters->Read(s, "Meters");
	Meters = std::optional<std::reference_wrapper<Materialise::MeterValues>> { *__Meters };
	return true;
}
void Materialise::PrintInformationMeterStates::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (count.has_value())
		s.WriteAttr("count", count.value());
	for(int i = 0;i < States.size();i++)
	{
		States[i].Write(s, "States"); 
	}
}
bool Materialise::PrintInformationMeterStates::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	unsigned int* __count = new unsigned int();
	if (s.ReadAttrUnsignedInt("count", *__count))
		count = std::optional<std::reference_wrapper<unsigned int>> { *__count };
	while (true) { 
		Materialise::States __t;
		if (__t.Read(s, "States") == false)
			break;
		States.push_back(__t);
	}
	return true;
}
void Materialise::States::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("meter", meter.c_str());
	if (count.has_value())
		s.WriteAttr("count", count.value());
	for(int i = 0;i < State.size();i++)
	{
		State[i].Write(s, "State"); 
	}
}
bool Materialise::States::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("meter", meter);
	unsigned int* __count = new unsigned int();
	if (s.ReadAttrUnsignedInt("count", *__count))
		count = std::optional<std::reference_wrapper<unsigned int>> { *__count };
	while (true) { 
		Materialise::PrintInformationMeterState __t;
		if (__t.Read(s, "State") == false)
			break;
		State.push_back(__t);
	}
	return true;
}
void Materialise::PrintInformationMeterState::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
}
bool Materialise::PrintInformationMeterState::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	return true;
}
void Materialise::PrintInformationPrintedLayers::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (count.has_value())
		s.WriteAttr("count", count.value());
	s.WriteAttr("total", total);
	for(int i = 0;i < Layer.size();i++)
	{
		Layer[i].Write(s, "Layer"); 
	}
}
bool Materialise::PrintInformationPrintedLayers::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	unsigned int* __count = new unsigned int();
	if (s.ReadAttrUnsignedInt("count", *__count))
		count = std::optional<std::reference_wrapper<unsigned int>> { *__count };
	s.ReadAttrUnsignedInt("total", total);
	while (true) { 
		Materialise::PrintInformationPrintedLayer __t;
		if (__t.Read(s, "Layer") == false)
			break;
		Layer.push_back(__t);
	}
	return true;
}
void Materialise::PrintInformationPrintedLayer::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("index", index);
	if (MeterValues.has_value())
		MeterValues.value().get().Write(s, "MeterValues");
}
bool Materialise::PrintInformationPrintedLayer::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrUnsignedInt("index", index);
	Materialise::MeterValues* __MeterValues = new Materialise::MeterValues();
	__MeterValues->Read(s, "MeterValues");
	MeterValues = std::optional<std::reference_wrapper<Materialise::MeterValues>> { *__MeterValues };
	return true;
}
void Materialise::PrintInformation::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (Meters.has_value())
		Meters.value().get().Write(s, "Meters");
	if (Log.has_value())
		Log.value().get().Write(s, "Log");
	if (MeterValues.has_value())
		MeterValues.value().get().Write(s, "MeterValues");
	if (MeterStates.has_value())
		MeterStates.value().get().Write(s, "MeterStates");
	if (PrintedLayers.has_value())
		PrintedLayers.value().get().Write(s, "PrintedLayers");
}
bool Materialise::PrintInformation::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	Materialise::MeterDefinitions* __Meters = new Materialise::MeterDefinitions();
	__Meters->Read(s, "Meters");
	Meters = std::optional<std::reference_wrapper<Materialise::MeterDefinitions>> { *__Meters };
	Materialise::Log* __Log = new Materialise::Log();
	__Log->Read(s, "Log");
	Log = std::optional<std::reference_wrapper<Materialise::Log>> { *__Log };
	Materialise::MeterValues* __MeterValues = new Materialise::MeterValues();
	__MeterValues->Read(s, "MeterValues");
	MeterValues = std::optional<std::reference_wrapper<Materialise::MeterValues>> { *__MeterValues };
	Materialise::PrintInformationMeterStates* __MeterStates = new Materialise::PrintInformationMeterStates();
	__MeterStates->Read(s, "MeterStates");
	MeterStates = std::optional<std::reference_wrapper<Materialise::PrintInformationMeterStates>> { *__MeterStates };
	Materialise::PrintInformationPrintedLayers* __PrintedLayers = new Materialise::PrintInformationPrintedLayers();
	__PrintedLayers->Read(s, "PrintedLayers");
	PrintedLayers = std::optional<std::reference_wrapper<Materialise::PrintInformationPrintedLayers>> { *__PrintedLayers };
	return true;
}
