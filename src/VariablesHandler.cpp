#include "../headers/VariablesHandler.h"

void VariablesHandler::setPorts(T *i_ports, T *o_ports){
    this->i_ports = i_ports;
    this->o_ports = o_ports;
};

VariablesHandler::VariablesHandler(){
    v["Hand"] = new PortVariable(inputVariable, i_ports+0, 3);
    v["Dryer"] = new PortVariable(outputVariable, o_ports+0, 4);
};

void VariablesHandler::read(){
    for(auto pair: v)
        pair.second->saveValue();
}

void VariablesHandler::logVariables(std::ofstream& fout) {
	if(!fout) return;
    for(auto pair:  v)
        fout << pair.first << " = " << pair.second->post << " ";
    	//fprintf( pFile, "%s = %d\n", pair.first, pair.second->post);
};

