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
	const std::string schema_generated_files_PrintInformation_namespace = "urn:Print3D";
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
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		PrintInformation(const PrintInformation&) = delete;
		PrintInformation& operator=(PrintInformation&&) = delete;
		PrintInformation& operator=(PrintInformation&) = delete;
		PrintInformation(PrintInformation&&) noexcept;
		PrintInformation() = default;
		~PrintInformation() = default;
		std::optional<std::unique_ptr<MeterDefinitions>> Meters;
		std::optional<std::unique_ptr<Log>> Log;
		std::optional<std::unique_ptr<MeterValues>> MeterValues;
		std::optional<std::unique_ptr<PrintInformationMeterStates>> MeterStates;
		std::optional<std::unique_ptr<PrintInformationPrintedLayers>> PrintedLayers;
	};
	struct PrintInformationPrintedLayer {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		PrintInformationPrintedLayer(const PrintInformationPrintedLayer&) = delete;
		PrintInformationPrintedLayer& operator=(PrintInformationPrintedLayer&&) = delete;
		PrintInformationPrintedLayer& operator=(PrintInformationPrintedLayer&) = delete;
		PrintInformationPrintedLayer(PrintInformationPrintedLayer&&) noexcept;
		PrintInformationPrintedLayer() = default;
		~PrintInformationPrintedLayer() = default;
		unsigned int index;
		std::optional<std::unique_ptr<MeterValues>> MeterValues;
	};
	struct PrintInformationPrintedLayers {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		PrintInformationPrintedLayers(const PrintInformationPrintedLayers&) = delete;
		PrintInformationPrintedLayers& operator=(PrintInformationPrintedLayers&&) = delete;
		PrintInformationPrintedLayers& operator=(PrintInformationPrintedLayers&) = delete;
		PrintInformationPrintedLayers(PrintInformationPrintedLayers&&) noexcept;
		PrintInformationPrintedLayers() = default;
		~PrintInformationPrintedLayers() = default;
		std::optional<unsigned int> count;
		unsigned int total;
		std::vector<PrintInformationPrintedLayer> Layer;
	};
	struct PrintInformationMeterState {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		PrintInformationMeterState(const PrintInformationMeterState&) = delete;
		PrintInformationMeterState& operator=(PrintInformationMeterState&&) = delete;
		PrintInformationMeterState& operator=(PrintInformationMeterState&) = delete;
		PrintInformationMeterState(PrintInformationMeterState&&) noexcept;
		PrintInformationMeterState() = default;
		~PrintInformationMeterState() = default;
	};
	struct States {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		States(const States&) = delete;
		States& operator=(States&&) = delete;
		States& operator=(States&) = delete;
		States(States&&) noexcept;
		States() = default;
		~States() = default;
		std::string meter;
		std::optional<unsigned int> count;
		std::vector<PrintInformationMeterState> State;
	};
	struct PrintInformationMeterStates {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		PrintInformationMeterStates(const PrintInformationMeterStates&) = delete;
		PrintInformationMeterStates& operator=(PrintInformationMeterStates&&) = delete;
		PrintInformationMeterStates& operator=(PrintInformationMeterStates&) = delete;
		PrintInformationMeterStates(PrintInformationMeterStates&&) noexcept;
		PrintInformationMeterStates() = default;
		~PrintInformationMeterStates() = default;
		std::optional<unsigned int> count;
		std::vector<States> States;
	};
	struct LogEntry {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		LogEntry(const LogEntry&) = delete;
		LogEntry& operator=(LogEntry&&) = delete;
		LogEntry& operator=(LogEntry&) = delete;
		LogEntry(LogEntry&&) noexcept;
		LogEntry() = default;
		~LogEntry() = default;
		Materialise::LogEntryType type;
		std::optional<std::string> source;
		std::optional<std::string> category;
		std::optional<std::string> message;
		std::optional<std::unique_ptr<MeterValues>> Meters;
	};
	struct Entries {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Entries(const Entries&) = delete;
		Entries& operator=(Entries&&) = delete;
		Entries& operator=(Entries&) = delete;
		Entries(Entries&&) noexcept;
		Entries() = default;
		~Entries() = default;
		std::optional<unsigned int> count;
		std::vector<LogEntry> Entry;
	};
	struct Log {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Log(const Log&) = delete;
		Log& operator=(Log&&) = delete;
		Log& operator=(Log&) = delete;
		Log(Log&&) noexcept;
		Log() = default;
		~Log() = default;
		std::optional<std::unique_ptr<MeterDefinitions>> Meters;
		std::optional<std::unique_ptr<Entries>> Entries;
	};
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
Materialise::Log::Log(Materialise::Log &&___Log) noexcept
	: Meters(std::move(___Log.Meters))
	, Entries(std::move(___Log.Entries))
{ }
void Materialise::Log::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (Meters.has_value())
		Meters.value().get()->Write(s, "Meters");
	if (Entries.has_value())
		Entries.value().get()->Write(s, "Entries");
}
bool Materialise::Log::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::unique_ptr<Materialise::MeterDefinitions> __Meters = std::make_unique<Materialise::MeterDefinitions>();
	if (__Meters->Read(s, "Meters"))
		Meters = std::make_optional(std::move(__Meters));
	std::unique_ptr<Materialise::Entries> __Entries = std::make_unique<Materialise::Entries>();
	if (__Entries->Read(s, "Entries"))
		Entries = std::make_optional(std::move(__Entries));
	return true;
}
Materialise::Entries::Entries(Materialise::Entries &&___Entries) noexcept
	: count(___Entries.count)
	, Entry(std::move(___Entries.Entry))
{ }
void Materialise::Entries::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (count.has_value())
		s.WriteAttr("count", count.value());
	for(auto&& element : Entry)
	{
		element.Write(s, "Entry"); 
	}
}
bool Materialise::Entries::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	unsigned int __count;
	if (s.ReadAttrUnsignedInt("count", __count))
		count = std::optional<unsigned int> { __count };
	while (true) { 
		Materialise::LogEntry __t;
		if (!__t.Read(s, "Entry"))
			break;
		Entry.push_back(std::move(__t));
	}
	return true;
}
Materialise::LogEntry::LogEntry(Materialise::LogEntry &&___LogEntry) noexcept
	: type(___LogEntry.type)
	, source(___LogEntry.source)
	, category(___LogEntry.category)
	, message(___LogEntry.message)
	, Meters(std::move(___LogEntry.Meters))
{ }
void Materialise::LogEntry::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("type", Materialise::ConvertLogEntryTypeToString(type).c_str());
	if (source.has_value())
		s.WriteAttr("source", source.value().c_str());
	if (category.has_value())
		s.WriteAttr("category", category.value().c_str());
	if (message.has_value())
		s.WriteAttr("message", message.value().c_str());
	if (Meters.has_value())
		Meters.value().get()->Write(s, "Meters");
}
bool Materialise::LogEntry::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	if (s.ReadAttrStr("type", __tmp_var)) 
		type = Materialise::ConvertStringToLogEntryType(__tmp_var);
	std::string __source;
	if (s.ReadAttrStr("source", __source))
		source = std::optional<std::string> { __source };
	std::string __category;
	if (s.ReadAttrStr("category", __category))
		category = std::optional<std::string> { __category };
	std::string __message;
	if (s.ReadAttrStr("message", __message))
		message = std::optional<std::string> { __message };
	std::unique_ptr<Materialise::MeterValues> __Meters = std::make_unique<Materialise::MeterValues>();
	if (__Meters->Read(s, "Meters"))
		Meters = std::make_optional(std::move(__Meters));
	return true;
}
Materialise::PrintInformationMeterStates::PrintInformationMeterStates(Materialise::PrintInformationMeterStates &&___PrintInformationMeterStates) noexcept
	: count(___PrintInformationMeterStates.count)
	, States(std::move(___PrintInformationMeterStates.States))
{ }
void Materialise::PrintInformationMeterStates::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (count.has_value())
		s.WriteAttr("count", count.value());
	for(auto&& element : States)
	{
		element.Write(s, "States"); 
	}
}
bool Materialise::PrintInformationMeterStates::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	unsigned int __count;
	if (s.ReadAttrUnsignedInt("count", __count))
		count = std::optional<unsigned int> { __count };
	while (true) { 
		Materialise::States __t;
		if (!__t.Read(s, "States"))
			break;
		States.push_back(std::move(__t));
	}
	return true;
}
Materialise::States::States(Materialise::States &&___States) noexcept
	: meter(___States.meter)
	, count(___States.count)
	, State(std::move(___States.State))
{ }
void Materialise::States::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("meter", meter.c_str());
	if (count.has_value())
		s.WriteAttr("count", count.value());
	for(auto&& element : State)
	{
		element.Write(s, "State"); 
	}
}
bool Materialise::States::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("meter", meter);
	unsigned int __count;
	if (s.ReadAttrUnsignedInt("count", __count))
		count = std::optional<unsigned int> { __count };
	while (true) { 
		Materialise::PrintInformationMeterState __t;
		if (!__t.Read(s, "State"))
			break;
		State.push_back(std::move(__t));
	}
	return true;
}
Materialise::PrintInformationMeterState::PrintInformationMeterState(Materialise::PrintInformationMeterState &&___PrintInformationMeterState) noexcept
{ }
void Materialise::PrintInformationMeterState::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
}
bool Materialise::PrintInformationMeterState::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	return true;
}
Materialise::PrintInformationPrintedLayers::PrintInformationPrintedLayers(Materialise::PrintInformationPrintedLayers &&___PrintInformationPrintedLayers) noexcept
	: count(___PrintInformationPrintedLayers.count)
	, total(___PrintInformationPrintedLayers.total)
	, Layer(std::move(___PrintInformationPrintedLayers.Layer))
{ }
void Materialise::PrintInformationPrintedLayers::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (count.has_value())
		s.WriteAttr("count", count.value());
	s.WriteAttr("total", total);
	for(auto&& element : Layer)
	{
		element.Write(s, "Layer"); 
	}
}
bool Materialise::PrintInformationPrintedLayers::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	unsigned int __count;
	if (s.ReadAttrUnsignedInt("count", __count))
		count = std::optional<unsigned int> { __count };
	s.ReadAttrUnsignedInt("total", total);
	while (true) { 
		Materialise::PrintInformationPrintedLayer __t;
		if (!__t.Read(s, "Layer"))
			break;
		Layer.push_back(std::move(__t));
	}
	return true;
}
Materialise::PrintInformationPrintedLayer::PrintInformationPrintedLayer(Materialise::PrintInformationPrintedLayer &&___PrintInformationPrintedLayer) noexcept
	: index(___PrintInformationPrintedLayer.index)
	, MeterValues(std::move(___PrintInformationPrintedLayer.MeterValues))
{ }
void Materialise::PrintInformationPrintedLayer::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("index", index);
	if (MeterValues.has_value())
		MeterValues.value().get()->Write(s, "MeterValues");
}
bool Materialise::PrintInformationPrintedLayer::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrUnsignedInt("index", index);
	std::unique_ptr<Materialise::MeterValues> __MeterValues = std::make_unique<Materialise::MeterValues>();
	if (__MeterValues->Read(s, "MeterValues"))
		MeterValues = std::make_optional(std::move(__MeterValues));
	return true;
}
Materialise::PrintInformation::PrintInformation(Materialise::PrintInformation &&___PrintInformation) noexcept
	: Meters(std::move(___PrintInformation.Meters))
	, Log(std::move(___PrintInformation.Log))
	, MeterValues(std::move(___PrintInformation.MeterValues))
	, MeterStates(std::move(___PrintInformation.MeterStates))
	, PrintedLayers(std::move(___PrintInformation.PrintedLayers))
{ }
void Materialise::PrintInformation::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (Meters.has_value())
		Meters.value().get()->Write(s, "Meters");
	if (Log.has_value())
		Log.value().get()->Write(s, "Log");
	if (MeterValues.has_value())
		MeterValues.value().get()->Write(s, "MeterValues");
	if (MeterStates.has_value())
		MeterStates.value().get()->Write(s, "MeterStates");
	if (PrintedLayers.has_value())
		PrintedLayers.value().get()->Write(s, "PrintedLayers");
}
bool Materialise::PrintInformation::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::unique_ptr<Materialise::MeterDefinitions> __Meters = std::make_unique<Materialise::MeterDefinitions>();
	if (__Meters->Read(s, "Meters"))
		Meters = std::make_optional(std::move(__Meters));
	std::unique_ptr<Materialise::Log> __Log = std::make_unique<Materialise::Log>();
	if (__Log->Read(s, "Log"))
		Log = std::make_optional(std::move(__Log));
	std::unique_ptr<Materialise::MeterValues> __MeterValues = std::make_unique<Materialise::MeterValues>();
	if (__MeterValues->Read(s, "MeterValues"))
		MeterValues = std::make_optional(std::move(__MeterValues));
	std::unique_ptr<Materialise::PrintInformationMeterStates> __MeterStates = std::make_unique<Materialise::PrintInformationMeterStates>();
	if (__MeterStates->Read(s, "MeterStates"))
		MeterStates = std::make_optional(std::move(__MeterStates));
	std::unique_ptr<Materialise::PrintInformationPrintedLayers> __PrintedLayers = std::make_unique<Materialise::PrintInformationPrintedLayers>();
	if (__PrintedLayers->Read(s, "PrintedLayers"))
		PrintedLayers = std::make_optional(std::move(__PrintedLayers));
	return true;
}
