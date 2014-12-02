#include "JetSubStructureMomentTools/EnergyCorrelatorTool.h"
#include "JetSubStructureUtils/EnergyCorrelator.h" 

using namespace std;
using fastjet::PseudoJet;

EnergyCorrelatorTool::EnergyCorrelatorTool(std::string name) : 
  JetSubStructureMomentToolsBase(name)
{
  ATH_MSG_DEBUG("Initializing EnergyCorrelator tool.");
  declareProperty("Beta", m_Beta = 1.0);
}

int EnergyCorrelatorTool::modifyJet(xAOD::Jet &jet) const {
	if(checkForConstituents(jet) == false) return 1;

  JetSubStructureUtils::EnergyCorrelator ECF1(1, m_Beta, JetSubStructureUtils::EnergyCorrelator::pt_R);
  JetSubStructureUtils::EnergyCorrelator ECF2(2, m_Beta, JetSubStructureUtils::EnergyCorrelator::pt_R);
  JetSubStructureUtils::EnergyCorrelator ECF3(3, m_Beta, JetSubStructureUtils::EnergyCorrelator::pt_R);
  jet.setAttribute("ECF1", ECF1.result(jet));
  jet.setAttribute("ECF2", ECF2.result(jet));
  jet.setAttribute("ECF3", ECF3.result(jet));
	cout << "ECF1=" << jet.getAttribute<float>("ECF1") << " " ;
	cout << "ECF2=" << jet.getAttribute<float>("ECF2") << " " ;
	cout << "ECF3=" << jet.getAttribute<float>("ECF3") << " " ;
	cout << endl;
  return 0;
}
