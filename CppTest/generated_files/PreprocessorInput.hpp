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
	struct PartInstances;
	struct Instance;
	struct PartLabels;
	struct Label;
	struct PreprocessorInput;
	struct Labelling;
	struct PreliminaryPass;
	struct Parts;
	struct Part;
	struct Part {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string id;
		std::optional<std::string> FilePath {""};
		std::optional<std::reference_wrapper<Materialise::PartInstances>> Instances;
		Part() {}
		~Part() {}
	};
	struct Parts {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::Part> Part;
		Parts() {}
		~Parts() {}
	};
	struct PreliminaryPass {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<bool> enabled;
		PreliminaryPass() {}
		~PreliminaryPass() {}
	};
	struct Labelling {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<bool> enabled;
		Labelling() {}
		~Labelling() {}
	};
	struct PreprocessorInput {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::reference_wrapper<Materialise::Labelling>> Labelling;
		std::optional<std::reference_wrapper<Materialise::PreliminaryPass>> PreliminaryPass;
		std::optional<std::reference_wrapper<Materialise::Parts>> Parts;
		PreprocessorInput() {}
		~PreprocessorInput() {}
	};
	struct Label {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string id;
		std::string value;
		Label() {}
		~Label() {}
	};
	struct PartLabels {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::Label> Label;
		PartLabels() {}
		~PartLabels() {}
	};
	struct Instance {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string id;
		std::optional<std::reference_wrapper<Materialise::PartLabels>> Labels;
		Instance() {}
		~Instance() {}
	};
	struct PartInstances {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::Instance> Instance;
		PartInstances() {}
		~PartInstances() {}
	};
}
void Materialise::PartInstances::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "PartInstances");
	for(int i = 0;i < Instance.size();i++)
	{
		Instance[i].Write(s); 
	}
}
bool Materialise::PartInstances::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "PartInstances");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Instance __t;
		if (__t.Read(s) == false)
			break;
		Instance.push_back(__t);
	}
	return true;
}
void Materialise::Instance::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Instance");
	s.WriteAttr("id", id.c_str());
	Labels.value().get().Write(s);
}
bool Materialise::Instance::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Instance");
	if (scope.exist() == false)
		return false;
	id = s.ReadAttrStr("id");
	Materialise::PartLabels* __Labels = new Materialise::PartLabels();
	__Labels->Read(s);
	Labels = std::optional<std::reference_wrapper<Materialise::PartLabels>> { *__Labels };
	return true;
}
void Materialise::PartLabels::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "PartLabels");
	for(int i = 0;i < Label.size();i++)
	{
		Label[i].Write(s); 
	}
}
bool Materialise::PartLabels::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "PartLabels");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Label __t;
		if (__t.Read(s) == false)
			break;
		Label.push_back(__t);
	}
	return true;
}
void Materialise::Label::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Label");
	s.WriteAttr("id", id.c_str());
	s.WriteAttr("value", value.c_str());
}
bool Materialise::Label::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Label");
	if (scope.exist() == false)
		return false;
	id = s.ReadAttrStr("id");
	value = s.ReadAttrStr("value");
	return true;
}
void Materialise::PreprocessorInput::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "PreprocessorInput");
	Labelling.value().get().Write(s);
	PreliminaryPass.value().get().Write(s);
	Parts.value().get().Write(s);
}
bool Materialise::PreprocessorInput::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "PreprocessorInput");
	if (scope.exist() == false)
		return false;
	Materialise::Labelling* __Labelling = new Materialise::Labelling();
	__Labelling->Read(s);
	Labelling = std::optional<std::reference_wrapper<Materialise::Labelling>> { *__Labelling };
	Materialise::PreliminaryPass* __PreliminaryPass = new Materialise::PreliminaryPass();
	__PreliminaryPass->Read(s);
	PreliminaryPass = std::optional<std::reference_wrapper<Materialise::PreliminaryPass>> { *__PreliminaryPass };
	Materialise::Parts* __Parts = new Materialise::Parts();
	__Parts->Read(s);
	Parts = std::optional<std::reference_wrapper<Materialise::Parts>> { *__Parts };
	return true;
}
void Materialise::Labelling::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Labelling");
	s.WriteAttr("enabled", enabled.value());
}
bool Materialise::Labelling::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Labelling");
	if (scope.exist() == false)
		return false;
	enabled = s.ReadAttrBool("enabled");
	return true;
}
void Materialise::PreliminaryPass::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "PreliminaryPass");
	s.WriteAttr("enabled", enabled.value());
}
bool Materialise::PreliminaryPass::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "PreliminaryPass");
	if (scope.exist() == false)
		return false;
	enabled = s.ReadAttrBool("enabled");
	return true;
}
void Materialise::Parts::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Parts");
	for(int i = 0;i < Part.size();i++)
	{
		Part[i].Write(s); 
	}
}
bool Materialise::Parts::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Parts");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Part __t;
		if (__t.Read(s) == false)
			break;
		Part.push_back(__t);
	}
	return true;
}
void Materialise::Part::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Part");
	s.WriteAttr("id", id.c_str());
	s.Write("FilePath", FilePath.value().c_str());
	Instances.value().get().Write(s);
}
bool Materialise::Part::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Part");
	if (scope.exist() == false)
		return false;
	id = s.ReadAttrStr("id");
	s.ReadStr("FilePath", FilePath.value());
	Materialise::PartInstances* __Instances = new Materialise::PartInstances();
	__Instances->Read(s);
	Instances = std::optional<std::reference_wrapper<Materialise::PartInstances>> { *__Instances };
	return true;
}
