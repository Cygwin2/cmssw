// -*- C++ -*-
//
// Package:    OuterTrackerVClient
// Class:      OuterTrackerVClient
// 
/**\class OuterTrackerVClient OuterTrackerVClient.cc Validation/OuterTrackerVClient/plugins/OuterTrackerVClient.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Lieselotte Moreels
//         Created:  Fri, 13 Jun 2014 09:57:34 GMT
// 

// system include files
#include <memory>
#include <vector>
#include <numeric>
#include <fstream>
#include <math.h>
#include "TNamed.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "CalibTracker/Records/interface/SiStripDetCablingRcd.h"
#include "CalibFormats/SiStripObjects/interface/SiStripDetCabling.h"
#include "CondFormats/DataRecord/interface/SiStripCondDataRecords.h"
#include "CondFormats/SiStripObjects/interface/SiStripNoises.h"
#include "CalibFormats/SiStripObjects/interface/SiStripGain.h"
#include "CalibFormats/SiStripObjects/interface/SiStripQuality.h"
#include "DataFormats/SiStripCluster/interface/SiStripClusterCollection.h"
#include "DataFormats/Common/interface/DetSetVector.h"
#include "DataFormats/Common/interface/DetSetVectorNew.h"
#include "DataFormats/SiStripCluster/interface/SiStripCluster.h"
#include "DQM/SiStripCommon/interface/SiStripFolderOrganizer.h"
#include "DQM/SiStripCommon/interface/SiStripHistoId.h"
#include "Validation/OuterTrackerVClient/interface/OuterTrackerVClient.h"
#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/MonitorElement.h"
#include "DataFormats/SiStripDetId/interface/StripSubdetector.h"
#include "DataFormats/SiStripDetId/interface/SiStripSubStructure.h"
#include "CalibTracker/SiStripCommon/interface/SiStripDCSStatus.h"
#include "DataFormats/SiPixelCluster/interface/SiPixelCluster.h"

#include "DPGAnalysis/SiStripTools/interface/APVCyclePhaseCollection.h"
#include "DPGAnalysis/SiStripTools/interface/EventWithHistory.h"

#include "CommonTools/TriggerUtils/interface/GenericTriggerEventFlag.h"

#include "TMath.h"
#include <iostream>

//
// constructors and destructor
//
OuterTrackerVClient::OuterTrackerVClient(const edm::ParameterSet& iConfig)
{
 
}


OuterTrackerVClient::~OuterTrackerVClient()
{
 

}


//
// member functions
//

// ------------ method called for each event  ------------
void
OuterTrackerVClient::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  
}


// ------------ method called once each job just before starting event loop  ------------
void 
OuterTrackerVClient::beginRun(const edm::Run& run, const edm::EventSetup& es)
{


}//end of method


// ------------ method called once each job just after ending the event loop  ------------
void 
OuterTrackerVClient::endJob(void) 
{

}

DEFINE_FWK_MODULE(OuterTrackerVClient);
