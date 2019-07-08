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
	const std::string schema_generated_files3_PreprocessorCapabilities_namespace = "http://www.materialise.com/BuildProcessor/2014";
	struct PreprocessorCapabilities;
	struct PreprocessorCapabilities {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<bool> Labelling {false};
		std::optional<bool> DeferredLabelling {false};
		PreprocessorCapabilities() {}
		~PreprocessorCapabilities() {}
	};
}
void Materialise::PreprocessorCapabilities::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (Labelling.has_value())
		s.Write("Labelling", Labelling.value());
	if (DeferredLabelling.has_value())
		s.Write("DeferredLabelling", DeferredLabelling.value());
}
bool Materialise::PreprocessorCapabilities::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadBool("Labelling", Labelling.value());
	s.ReadBool("DeferredLabelling", DeferredLabelling.value());
	return true;
}
