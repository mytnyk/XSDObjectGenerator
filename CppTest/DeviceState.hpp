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
	enum class DeviceStatusValue {
		None,
		Offline,
		Free,
		ReadyToPrint,
		Printing,
		PrintingPaused,
		PrintingAborted,
		Error,
		Printed,
		UserIntervention,
		Busy,
	};

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

	DeviceStatusValue ConvertStringToDeviceStatusValue(std::string str) {
		if (str == "None") return DeviceStatusValue::None;
		if (str == "Offline") return DeviceStatusValue::Offline;
		if (str == "Free") return DeviceStatusValue::Free;
		if (str == "ReadyToPrint") return DeviceStatusValue::ReadyToPrint;
		if (str == "Printing") return DeviceStatusValue::Printing;
		if (str == "PrintingPaused") return DeviceStatusValue::PrintingPaused;
		if (str == "PrintingAborted") return DeviceStatusValue::PrintingAborted;
		if (str == "Error") return DeviceStatusValue::Error;
		if (str == "Printed") return DeviceStatusValue::Printed;
		if (str == "UserIntervention") return DeviceStatusValue::UserIntervention;
		if (str == "Busy") return DeviceStatusValue::Busy;
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertDeviceStatusValueToString(DeviceStatusValue e) {
		if (e == DeviceStatusValue::None) return "None";
		if (e == DeviceStatusValue::Offline) return "Offline";
		if (e == DeviceStatusValue::Free) return "Free";
		if (e == DeviceStatusValue::ReadyToPrint) return "ReadyToPrint";
		if (e == DeviceStatusValue::Printing) return "Printing";
		if (e == DeviceStatusValue::PrintingPaused) return "PrintingPaused";
		if (e == DeviceStatusValue::PrintingAborted) return "PrintingAborted";
		if (e == DeviceStatusValue::Error) return "Error";
		if (e == DeviceStatusValue::Printed) return "Printed";
		if (e == DeviceStatusValue::UserIntervention) return "UserIntervention";
		if (e == DeviceStatusValue::Busy) return "Busy";
		throw std::exception("Can't convert enum value to string");
	}

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
	struct DeviceStatus;
	struct DeviceState;
	struct DeviceStatus {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		Materialise::DeviceStatusValue value;
		std::optional<std::string> description {""};
		DeviceStatus() {}
		~DeviceStatus() {}
	};
	struct DeviceState {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		Materialise::DeviceStatus Status;
		std::optional<std::reference_wrapper<Materialise::Meters>> Meters;
		std::optional<std::reference_wrapper<Materialise::OperationReport>> PrintOperationReport;
		std::optional<std::reference_wrapper<Materialise::Log>> Log;
		DeviceState() {}
		~DeviceState() {}
	};
	struct OperationReportMeterValuesValue {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string meter;
		OperationReportMeterValuesValue() {}
		~OperationReportMeterValuesValue() {}
	};
	struct OperationReportMeterValues {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<std::string> count {""};
		std::vector<Materialise::OperationReportMeterValuesValue> Value;
		OperationReportMeterValues() {}
		~OperationReportMeterValues() {}
	};
	struct OperationReport {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
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
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		Materialise::LogEntryType type;
		std::optional<std::string> source {""};
		std::optional<std::string> category {""};
		std::optional<std::string> message {""};
		std::optional<std::reference_wrapper<Materialise::MeterValues>> Meters;
		LogEntry() {}
		~LogEntry() {}
	};
	struct Entries {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<std::string> count {""};
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
		std::optional<std::string> count {""};
		std::vector<Materialise::_Value> Value;
		MeterValues() {}
		~MeterValues() {}
	};
	struct MeterDefinitions {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<std::string> count {""};
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
		s.WriteAttr("count", count.value().c_str());
	for(int i = 0;i < Entry.size();i++)
	{
		Entry[i].Write(s, "Entry"); 
	}
}
bool Materialise::Entries::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	count = s.ReadAttrStr("count");
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
	type = Materialise::ConvertStringToLogEntryType(s.ReadAttrStr("type"));
	source = s.ReadAttrStr("source");
	category = s.ReadAttrStr("category");
	message = s.ReadAttrStr("message");
	Materialise::MeterValues* __Meters = new Materialise::MeterValues();
	__Meters->Read(s, "Meters");
	Meters = std::optional<std::reference_wrapper<Materialise::MeterValues>> { *__Meters };
	return true;
}
void Materialise::OperationReport::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.Write("Title", Title.c_str());
	if (Description.has_value())
		s.Write("Description", Description.value().c_str());
	s.Write("Progress", Progress);
	if (UploadId.has_value())
		s.Write("UploadId", UploadId.value().c_str());
	if (UploadLocation.has_value())
		s.Write("UploadLocation", UploadLocation.value().c_str());
	if (MeterValues.has_value())
		MeterValues.value().get().Write(s, "MeterValues");
	if (Log.has_value())
		Log.value().get().Write(s, "Log");
}
bool Materialise::OperationReport::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadStr("Title", Title);
	s.ReadStr("Description", Description.value());
	s.ReadDouble("Progress", Progress);
	s.ReadStr("UploadId", UploadId.value());
	s.ReadStr("UploadLocation", UploadLocation.value());
	Materialise::OperationReportMeterValues* __MeterValues = new Materialise::OperationReportMeterValues();
	__MeterValues->Read(s, "MeterValues");
	MeterValues = std::optional<std::reference_wrapper<Materialise::OperationReportMeterValues>> { *__MeterValues };
	Materialise::Log* __Log = new Materialise::Log();
	__Log->Read(s, "Log");
	Log = std::optional<std::reference_wrapper<Materialise::Log>> { *__Log };
	return true;
}
void Materialise::OperationReportMeterValues::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (count.has_value())
		s.WriteAttr("count", count.value().c_str());
	for(int i = 0;i < Value.size();i++)
	{
		Value[i].Write(s, "Value"); 
	}
}
bool Materialise::OperationReportMeterValues::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	count = s.ReadAttrStr("count");
	while (true) { 
		Materialise::OperationReportMeterValuesValue __t;
		if (__t.Read(s, "Value") == false)
			break;
		Value.push_back(__t);
	}
	return true;
}
void Materialise::OperationReportMeterValuesValue::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("meter", meter.c_str());
}
bool Materialise::OperationReportMeterValuesValue::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	meter = s.ReadAttrStr("meter");
	return true;
}
void Materialise::DeviceStatus::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("value", Materialise::ConvertDeviceStatusValueToString(value).c_str());
	if (description.has_value())
		s.WriteAttr("description", description.value().c_str());
}
bool Materialise::DeviceStatus::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	value = Materialise::ConvertStringToDeviceStatusValue(s.ReadAttrStr("value"));
	description = s.ReadAttrStr("description");
	return true;
}
void Materialise::DeviceState::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	Status.Write(s, "Status");
	if (Meters.has_value())
		Meters.value().get().Write(s, "Meters");
	if (PrintOperationReport.has_value())
		PrintOperationReport.value().get().Write(s, "PrintOperationReport");
	if (Log.has_value())
		Log.value().get().Write(s, "Log");
}
bool Materialise::DeviceState::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	Status.Read(s, "Status");
	Materialise::Meters* __Meters = new Materialise::Meters();
	__Meters->Read(s, "Meters");
	Meters = std::optional<std::reference_wrapper<Materialise::Meters>> { *__Meters };
	Materialise::OperationReport* __PrintOperationReport = new Materialise::OperationReport();
	__PrintOperationReport->Read(s, "PrintOperationReport");
	PrintOperationReport = std::optional<std::reference_wrapper<Materialise::OperationReport>> { *__PrintOperationReport };
	Materialise::Log* __Log = new Materialise::Log();
	__Log->Read(s, "Log");
	Log = std::optional<std::reference_wrapper<Materialise::Log>> { *__Log };
	return true;
}
