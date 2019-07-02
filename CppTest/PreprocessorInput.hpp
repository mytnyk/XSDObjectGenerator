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
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string id;
		std::optional<std::string> FilePath;
		std::optional<std::reference_wrapper<Materialise::PartInstances>> Instances;
		Part() {}
		~Part() {}
	};
	struct Parts {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::Part> Part;
		Parts() {}
		~Parts() {}
	};
	struct PreliminaryPass {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<bool> enabled;
		PreliminaryPass() {}
		~PreliminaryPass() {}
	};
	struct Labelling {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<bool> enabled;
		Labelling() {}
		~Labelling() {}
	};
	struct PreprocessorInput {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<std::reference_wrapper<Materialise::Labelling>> Labelling;
		std::optional<std::reference_wrapper<Materialise::PreliminaryPass>> PreliminaryPass;
		std::optional<std::reference_wrapper<Materialise::Parts>> Parts;
		PreprocessorInput() {}
		~PreprocessorInput() {}
	};
	struct Label {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string id;
		std::string value;
		Label() {}
		~Label() {}
	};
	struct PartLabels {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::Label> Label;
		PartLabels() {}
		~PartLabels() {}
	};
	struct Instance {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string id;
		std::optional<std::reference_wrapper<Materialise::PartLabels>> Labels;
		Instance() {}
		~Instance() {}
	};
	struct PartInstances {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::Instance> Instance;
		PartInstances() {}
		~PartInstances() {}
	};
}
void Materialise::PartInstances::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < Instance.size();i++)
	{
		Instance[i].Write(s, "Instance"); 
	}
}
bool Materialise::PartInstances::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Instance __t;
		if (__t.Read(s, "Instance") == false)
			break;
		Instance.push_back(__t);
	}
	return true;
}
void Materialise::Instance::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id.c_str());
	if (Labels.has_value())
		Labels.value().get().Write(s, "Labels");
}
bool Materialise::Instance::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("id", id);
	Materialise::PartLabels* __Labels = new Materialise::PartLabels();
	__Labels->Read(s, "Labels");
	Labels = std::optional<std::reference_wrapper<Materialise::PartLabels>> { *__Labels };
	return true;
}
void Materialise::PartLabels::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < Label.size();i++)
	{
		Label[i].Write(s, "Label"); 
	}
}
bool Materialise::PartLabels::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Label __t;
		if (__t.Read(s, "Label") == false)
			break;
		Label.push_back(__t);
	}
	return true;
}
void Materialise::Label::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id.c_str());
	s.WriteAttr("value", value.c_str());
}
bool Materialise::Label::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("id", id);
	s.ReadAttrStr("value", value);
	return true;
}
void Materialise::PreprocessorInput::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (Labelling.has_value())
		Labelling.value().get().Write(s, "Labelling");
	if (PreliminaryPass.has_value())
		PreliminaryPass.value().get().Write(s, "PreliminaryPass");
	if (Parts.has_value())
		Parts.value().get().Write(s, "Parts");
}
bool Materialise::PreprocessorInput::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	Materialise::Labelling* __Labelling = new Materialise::Labelling();
	__Labelling->Read(s, "Labelling");
	Labelling = std::optional<std::reference_wrapper<Materialise::Labelling>> { *__Labelling };
	Materialise::PreliminaryPass* __PreliminaryPass = new Materialise::PreliminaryPass();
	__PreliminaryPass->Read(s, "PreliminaryPass");
	PreliminaryPass = std::optional<std::reference_wrapper<Materialise::PreliminaryPass>> { *__PreliminaryPass };
	Materialise::Parts* __Parts = new Materialise::Parts();
	__Parts->Read(s, "Parts");
	Parts = std::optional<std::reference_wrapper<Materialise::Parts>> { *__Parts };
	return true;
}
void Materialise::Labelling::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (enabled.has_value())
		s.WriteAttr("enabled", enabled.value());
}
bool Materialise::Labelling::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	bool* __enabled = new bool();
	if (s.ReadAttrBool("enabled", *__enabled))
		enabled = std::optional<std::reference_wrapper<bool>> { *__enabled };
	return true;
}
void Materialise::PreliminaryPass::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (enabled.has_value())
		s.WriteAttr("enabled", enabled.value());
}
bool Materialise::PreliminaryPass::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	bool* __enabled = new bool();
	if (s.ReadAttrBool("enabled", *__enabled))
		enabled = std::optional<std::reference_wrapper<bool>> { *__enabled };
	return true;
}
void Materialise::Parts::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < Part.size();i++)
	{
		Part[i].Write(s, "Part"); 
	}
}
bool Materialise::Parts::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Part __t;
		if (__t.Read(s, "Part") == false)
			break;
		Part.push_back(__t);
	}
	return true;
}
void Materialise::Part::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id.c_str());
	if (FilePath.has_value())
		s.Write("FilePath", FilePath.value().c_str());
	if (Instances.has_value())
		Instances.value().get().Write(s, "Instances");
}
bool Materialise::Part::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("id", id);
	s.ReadStr("FilePath", FilePath.value());
	Materialise::PartInstances* __Instances = new Materialise::PartInstances();
	__Instances->Read(s, "Instances");
	Instances = std::optional<std::reference_wrapper<Materialise::PartInstances>> { *__Instances };
	return true;
}
