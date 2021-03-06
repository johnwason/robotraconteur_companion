#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::signal::SignalInfoPtr>{
		static Node encode(const com::robotraconteur::signal::SignalInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::signal::SignalInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::signal::SignalInfo);
			rhs->signal_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"signal_identifier",true);
			rhs->signal_class = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceClassPtr>(node,"signal_class",true);
			rhs->units = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::units::SIUnitPtr>(node,"units",true);
			rhs->data_type = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::datatype::DataTypePtr>(node,"data_type",true);
			rhs->signal_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::signal::SignalType::SignalType>(node,"signal_type",true);
			rhs->access_level = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::signal::SignalAccessLevel::SignalAccessLevel>(node,"access_level",true);
			rhs->address = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint32_t>(node,"address",true,true,0);
			rhs->user_description = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"user_description",true);
			// TODO: parse field varvalue min_value
			// TODO: parse field varvalue max_value
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::signal::SignalGroupInfoPtr>{
		static Node encode(const com::robotraconteur::signal::SignalGroupInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::signal::SignalGroupInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::signal::SignalGroupInfo);
			rhs->signal_group_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"signal_group_identifier",true);
			rhs->description = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"description",true);
			return true;
		}
	};



}