#include "pch.h"
#include "Serializers.hpp"
#include <pugixml.hpp>
#include "../generated_files/DeviceState.hpp"
#include "../generated_files/DriverDefinition.hpp"

void write2() {
	PugiXmlSerializerWriter s;
	Materialise::DeviceState ds;

	ds.Log = std::make_unique<Materialise::Log>();// new Materialise::Log());
	ds.Log.value()->Entries = std::make_unique<Materialise::Entries>();//(entries);
	ds.Log.value()->Entries.value()->count = 23786238;

	Materialise::LogEntry le;
	le.source = "AAAAA";
	le.type = Materialise::LogEntryType::Information;
	ds.Log.value()->Entries.value()->Entry.push_back(std::move(le));


	Materialise::LogEntry le2;
	le2.source = "BB";
	le2.message = "Hi";
	le2.type = Materialise::LogEntryType::Warning;
	ds.Log.value()->Entries.value()->Entry.push_back(std::move(le2));

	Materialise::LogEntry le3;
	le3.source = "AAAAA";
	le3.message = "Hi2";
	le3.type = Materialise::LogEntryType::Error;
	ds.Log.value()->Entries.value()->Entry.push_back(std::move(le3));

	ds.Status.description = "AA";
	ds.Status.value = Materialise::DeviceStatusValue::ReadyToPrint;

	ds.Write(s, "DeviceState");

	s.SetSchemaTargetNamespace(Materialise::schema_generated_files_DeviceState_namespace);
	s.SaveToFile("simple_xml.xml");
}

void read2() {
	PugiXmlSerializerReader s;
	s.Load("simple_xml.xml");
	Materialise::DeviceState bt;
	bt.Read(s, "DeviceState");
	auto g = bt.Log.value().get();
	auto jj = bt.Log.value()->Entries.value().get();
	std::string ns = s.getSchemaTargetNamespace();
	EXPECT_EQ(3, jj->Entry.size());
	EXPECT_EQ(Materialise::DeviceStatusValue::ReadyToPrint, bt.Status.value);
}

void driver_definition_read() {
	PugiXmlSerializerReader s;
	s.Load("DriverDefinition.xml");
	Materialise::Driver driver;
	driver.Read(s, "Driver");
	EXPECT_EQ("1.0.0.0", driver.Version);
	EXPECT_EQ("ABSOLUTE-PATH-PLACEHOLDER-306762F5-F824-42FF-A3B3-B91F957B4734\\UserDriver.dll", driver.UserDriverDll.value());
	EXPECT_EQ("BP.HelpLink.Name.1", driver.Properties.value().get()->Property[1].Name);
}

TEST(WriteRead, DeviceStateTest) {
	write2();
	read2();
}

TEST(Read, DriverDefinitionTest) {
	driver_definition_read();
}