#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include "TMultiGraph.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <stdio.h>
#include <TF1.h>
#include <TDirectoryFile.h>
#include <TRandom3.h>
#include "TLorentzVector.h"
#include "TString.h"
#include "TLegend.h"
#include "TH1F.h"
#include "TKey.h"
#include "THashList.h"
#include "THStack.h"
#include "TPaveLabel.h"
#include "TFile.h"
#include "myHelper.h"
#include "tr_Tree.h"
#include "ScaleFactor.h"
#include "LumiReweightingStandAlone.h"
#include "btagSF.h"
#include "RooWorkspace.h"
#include "RooRealVar.h"
#include "RooFunctor.h"

using namespace std;

int main(int argc, char** argv) {

    std::string input = *(argv + 1);
    std::string output = *(argv + 2);
    std::string sample = *(argv + 3);
    std::string name = *(argv + 4);

    float tes=0;
    if (argc > 1) {
        tes = atof(argv[5]);
    }

    TFile *f_Double = new TFile(input.c_str());
    cout<<"XXXXXXXXXXXXX "<<input.c_str()<<" XXXXXXXXXXXX"<<endl;
    TTree *arbre = (TTree*) f_Double->Get("etau_tree");
    TH1F* nbevt = (TH1F*) f_Double->Get("nevents");
    float ngen = nbevt->GetBinContent(2);

    TFile *f_eTrk=new TFile("etracking.root");
    TH2F *h_eTrk=(TH2F*) f_eTrk->Get("EGamma_SF2D");

    reweight::LumiReWeighting* LumiWeights_12;
    LumiWeights_12 = new reweight::LumiReWeighting("MC_Moriond17_PU25ns_V1.root", "Data_Pileup_2016_271036-284044_80bins.root", "pileup", "pileup");

    //TFile *fZ=new TFile("zpt_weights_2016_BtoH.root");
    TFile *fZ=new TFile("zpt_weights_btag.root");
    TH2F *histZ=(TH2F*) fZ->Get("zptmass_histo");

    TFile fw("htt_scalefactors_v16_3.root");
    RooWorkspace *w = (RooWorkspace*)fw.Get("w");
    fw.Close();

    float xs=1.0; float weight=1.0; float luminosity=35870.0;
    if (sample=="ZL" or sample=="ZTT" or sample=="ZJ" or sample=="ZLL"){ xs=5765.4; weight=luminosity*xs/ngen;}
    else if (sample=="TTL" or sample=="TT" or sample=="TTT" or sample=="TTJ") {xs=831.76; weight=luminosity*xs/ngen;}
    else if (sample=="DYlow") {xs=18610; weight=luminosity*xs/ngen;}
    else if (sample=="DY1low") {xs=421.5; weight=luminosity*xs/ngen;}
    else if (sample=="DY2low") {xs=184.3; weight=luminosity*xs/ngen;}
    else if (sample=="W") {xs=61526.7; weight=luminosity*xs/ngen;}
    else if (sample=="QCD") {xs=720648000*0.00042; weight=luminosity*xs/ngen;}
    else if (sample=="data_obs"){weight=1.0;}
    else if (sample=="WZ1L1Nu2Q") {xs=10.71; weight=luminosity*xs/ngen;}
    else if (sample=="WZ1L3Nu") {xs=3.05; weight=luminosity*xs/ngen;}
    else if (sample=="WZJets") {xs=5.26; weight=luminosity*xs/ngen;}
    else if (sample=="WZLLLNu") {xs=4.708; weight=luminosity*xs/ngen;}
    else if (sample=="WZ2L2Q") {xs=5.595; weight=luminosity*xs/ngen;}
    else if (sample=="WW1L1Nu2Q") {xs=49.997; weight=luminosity*xs/ngen;}
    else if (sample=="ZZ4L") {xs=1.212; weight=luminosity*xs/ngen;}
    else if (sample=="ZZ2L2Q") {xs=3.22; weight=luminosity*xs/ngen;}
    else if (sample=="VV2L2Nu") {xs=11.95; weight=luminosity*xs/ngen;}
    else if (sample=="ST_tW_antitop") {xs=35.6; weight=luminosity*xs/ngen;}
    else if (sample=="ST_tW_top") {xs=35.6; weight=luminosity*xs/ngen;}
    else if (sample=="ST_t_antitop") {xs=26.23; weight=luminosity*xs/ngen;}
    else if (sample=="ST_t_top") {xs=44.07; weight=luminosity*xs/ngen;}
    else if (sample=="ggh") {xs=48.58*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="VBF") {xs=3.782*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt15") {xs=0.01*48.58*0.1475; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt20") {xs=0.01*48.58*0.1426; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt25") {xs=0.01*48.58*0.1381; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt30") {xs=0.01*48.58*0.1358; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt35") {xs=0.01*48.58*0.1338; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt40") {xs=0.01*48.58*0.1322; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt45") {xs=0.01*48.58*0.1282; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt50") {xs=0.01*48.58*0.1232; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt55") {xs=0.01*48.58*0.1193; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt60") {xs=0.01*48.58*0.1133; weight=luminosity*xs/ngen;}
    else if (sample=="VBFbbtt20") {xs=0.01*3.782*0.1983; weight=luminosity*xs/ngen;}
    else if (sample=="VBFbbtt40") {xs=0.01*3.782*0.1908; weight=luminosity*xs/ngen;}
    else if (sample=="VBFbbtt60") {xs=0.01*3.782*0.1799; weight=luminosity*xs/ngen;}
    /*else if (sample=="VBF125") {xs=3.782*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="ggH_WW125") {xs=48.58*0.2137*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH125") {xs=0.840*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH125") {xs=0.5328*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="ZH125") {xs=0.8839*0.0627; weight=luminosity*xs/ngen;}*/
    else if (sample=="ggH125") {xs=48.58*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="VBF125") {xs=3.782*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="ggH120") {xs=52.22*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="VBF120") {xs=3.935*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="ggH130") {xs=45.31*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="VBF130") {xs=3.637*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="ggH110") {xs=57.90*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="VBF110") {xs=4.434*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="ggH140") {xs=36.0*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="VBF140") {xs=3.492*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="ggHWW125") {xs=48.58*0.2137*0.3258*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="VBFWW125") {xs=3.782*0.2137*0.3258*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH120") {xs=0.9558*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH125") {xs=0.840*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="WplusHWW125") {xs=0.840*0.2137*0.3258*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH130") {xs=0.7414*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH110") {xs=1.335*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH140") {xs=0.6308*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH120") {xs=0.6092*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH125") {xs=0.5328*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="WminusHWW125") {xs=0.5328*0.2137*0.3258*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH130") {xs=0.4676*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH110") {xs=0.8587*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH140") {xs=0.394*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="ZH120") {xs=0.9939*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="ZH125") {xs=0.8839*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="ZHWW125") {xs=0.8839*0.2137*0.3258*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="ZH130") {xs=0.7899*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="ZH110") {xs=1.309*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="ZH140") {xs=0.6514*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="ttHnonbb") {xs=0.5085*(1-0.577); weight=luminosity*xs/ngen;}//FIXME
    else if (sample=="WGLNu") {xs=489.0; weight=luminosity*xs/ngen;}
    else if (sample=="WGstarMuMu") {xs=2.793; weight=luminosity*xs/ngen;}
    else if (sample=="WGstarEE") {xs=3.526; weight=luminosity*xs/ngen;}
    else if (sample=="EWKWminus") {xs=20.25; weight=luminosity*xs/ngen;}
    else if (sample=="EWKWplus") {xs=25.62; weight=luminosity*xs/ngen;}
    else if (sample=="EWKZLL" or sample=="EWKZLL_TT" or sample=="EWKZLL_J" or sample=="EWKZLL_L" or sample=="EWKZLL_LL") {xs=3.987; weight=luminosity*xs/ngen;}
    else if (sample=="EWKZNuNu" or sample=="EWKZNuNu_TT" or sample=="EWKZNuNu_J" or sample=="EWKZNuNu_L" or sample=="EWKZNuNu_LL") {xs=10.01; weight=luminosity*xs/ngen;}
    else cout<<"Attention!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    arbre->SetBranchAddress("run", &run);
    arbre->SetBranchAddress("lumi", &lumi);
    arbre->SetBranchAddress("evt", &evt);
    arbre->SetBranchAddress("NUP", &NUP);
    arbre->SetBranchAddress("npv", &npv);
    arbre->SetBranchAddress("bpt_1", &bpt_1);
    arbre->SetBranchAddress("bpt_1_JESDown", &bpt_1_JESDown);
    arbre->SetBranchAddress("bpt_1_JESUp", &bpt_1_JESUp);
    arbre->SetBranchAddress("bpt_2", &bpt_2);
    arbre->SetBranchAddress("beta_1", &beta_1);
    arbre->SetBranchAddress("beta_1_JESUp", &beta_1_JESUp);
    arbre->SetBranchAddress("beta_1_JESDown", &beta_1_JESDown);
    arbre->SetBranchAddress("bphi_1", &bphi_1);
    arbre->SetBranchAddress("bphi_1_JESUp", &bphi_1_JESUp);
    arbre->SetBranchAddress("bphi_1_JESDown", &bphi_1_JESDown);
    arbre->SetBranchAddress("beta_2", &beta_2);
    arbre->SetBranchAddress("bphi_2", &bphi_2);
    arbre->SetBranchAddress("bflavor_1", &bflavor_1);
    arbre->SetBranchAddress("bflavor_1_JESUp", &bflavor_1_JESUp);
    arbre->SetBranchAddress("bflavor_1_JESDown", &bflavor_1_JESDown);
    arbre->SetBranchAddress("bflavor_2", &bflavor_2);
    arbre->SetBranchAddress("px_1", &px_1);
    arbre->SetBranchAddress("py_1", &py_1);
    arbre->SetBranchAddress("pz_1", &pz_1);
    arbre->SetBranchAddress("pt_1", &pt_1);
    arbre->SetBranchAddress("pt_1_EScaleDown", &pt_1_EScaleDown);
    arbre->SetBranchAddress("pt_1_EScaleUp", &pt_1_EScaleUp);
    arbre->SetBranchAddress("phi_1", &phi_1);
    arbre->SetBranchAddress("eta_1", &eta_1);
    arbre->SetBranchAddress("iso_1", &iso_1);
    arbre->SetBranchAddress("m_1", &m_1);
    arbre->SetBranchAddress("q_1", &q_1);
    arbre->SetBranchAddress("nbtag", &nbtag);
    arbre->SetBranchAddress("nbtag_JESUp", &nbtag_JESUp);
    arbre->SetBranchAddress("nbtag_JESDown", &nbtag_JESDown);
    arbre->SetBranchAddress("nbtagL", &nbtagL);
    arbre->SetBranchAddress("nbtagT", &nbtagT);
    arbre->SetBranchAddress("nbtag15", &nbtag15);
    arbre->SetBranchAddress("nbtag15L", &nbtag15L);
    arbre->SetBranchAddress("nbtag15T", &nbtag15T);
    arbre->SetBranchAddress("bptL_1", &bptL_1);
    arbre->SetBranchAddress("betaL_1", &betaL_1);
    arbre->SetBranchAddress("bphiL_1", &bphiL_1);
    arbre->SetBranchAddress("bflavorL_1", &bflavorL_1);
    arbre->SetBranchAddress("bptL_2", &bptL_2);
    arbre->SetBranchAddress("betaL_2", &betaL_2);
    arbre->SetBranchAddress("bphiL_2", &bphiL_2);
    arbre->SetBranchAddress("bflavorL_2", &bflavorL_2);
    arbre->SetBranchAddress("bptT_1", &bptT_1);
    arbre->SetBranchAddress("betaT_1", &betaT_1);
    arbre->SetBranchAddress("bphiT_1", &bphiT_1);
    arbre->SetBranchAddress("bflavorT_1", &bflavorT_1);
    arbre->SetBranchAddress("bptT_2", &bptT_2);
    arbre->SetBranchAddress("betaT_2", &betaT_2);
    arbre->SetBranchAddress("bphiT_2", &bphiT_2);
    arbre->SetBranchAddress("bflavorT_2", &bflavorT_2);
    arbre->SetBranchAddress("q_2", &q_2);
    arbre->SetBranchAddress("px_2", &px_2);
    arbre->SetBranchAddress("py_2", &py_2);
    arbre->SetBranchAddress("pz_2", &pz_2);
    arbre->SetBranchAddress("pt_2", &pt_2);
    arbre->SetBranchAddress("eta_2", &eta_2);
    arbre->SetBranchAddress("m_2", &m_2);
    arbre->SetBranchAddress("mt_2", &mt_2);
    arbre->SetBranchAddress("phi_2", &phi_2);
    arbre->SetBranchAddress("met", &met);
    arbre->SetBranchAddress("metphi", &metphi);
    arbre->SetBranchAddress("met_UESDown", &met_UESDown);
    arbre->SetBranchAddress("metphi_UESDown", &metphi_UESDown);
    arbre->SetBranchAddress("met_UESUp", &met_UESUp);
    arbre->SetBranchAddress("metphi_UESUp", &metphi_UESUp);
    arbre->SetBranchAddress("met_JESDown", &met_JESDown);
    arbre->SetBranchAddress("metphi_JESDown", &metphi_JESDown);
    arbre->SetBranchAddress("met_JESUp", &met_JESUp);
    arbre->SetBranchAddress("metphi_JESUp", &metphi_JESUp);
    arbre->SetBranchAddress("njets", &njets);
    arbre->SetBranchAddress("jpt_1", &jpt_1);
    arbre->SetBranchAddress("jpt_2", &jpt_2);
    arbre->SetBranchAddress("jflavor_1", &jflavor_1);
    arbre->SetBranchAddress("jflavor_2", &jflavor_2);
    arbre->SetBranchAddress("jdeta", &jdeta);
    arbre->SetBranchAddress("mjj", &mjj);
    arbre->SetBranchAddress("genweight", &genweight);
    arbre->SetBranchAddress("mjj_JESDown", &mjj_JESDown);
    arbre->SetBranchAddress("mjj_JESUp", &mjj_JESUp);
    arbre->SetBranchAddress("jdeta_JESDown", &jdeta_JESDown);
    arbre->SetBranchAddress("jdeta_JESUp", &jdeta_JESUp);
    arbre->SetBranchAddress("metphi_JESDown", &metphi_JESDown);
    arbre->SetBranchAddress("metphi_JESUp", &metphi_JESUp);
    arbre->SetBranchAddress("met_JESDown", &met_JESDown);
    arbre->SetBranchAddress("met_JESUp", &met_JESUp);
    arbre->SetBranchAddress("metphi_UESDown", &metphi_UESDown);
    arbre->SetBranchAddress("metphi_UESUp", &metphi_UESUp);
    arbre->SetBranchAddress("met_UESDown", &met_UESDown);
    arbre->SetBranchAddress("met_UESUp", &met_UESUp);
    arbre->SetBranchAddress("njets_JESDown", &njets_JESDown);
    arbre->SetBranchAddress("njets_JESUp", &njets_JESUp);
    arbre->SetBranchAddress("byVLooseIsolationMVArun2v1DBoldDMwLT_2",&byVLooseIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byLooseIsolationMVArun2v1DBoldDMwLT_2",&byLooseIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byMediumIsolationMVArun2v1DBoldDMwLT_2",&byMediumIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byTightIsolationMVArun2v1DBoldDMwLT_2",&byTightIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byVTightIsolationMVArun2v1DBoldDMwLT_2",&byVTightIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byIsolationMVA3oldDMwLTraw_2",&byIsolationMVA3oldDMwLTraw_2);

    arbre->SetBranchAddress("passEle25eta2p1Tight", &passEle25eta2p1Tight);
    arbre->SetBranchAddress("passEle27eta2p1Loose", &passEle27eta2p1Loose);
    arbre->SetBranchAddress("passEle24Tau20sL1", &passEle24Tau20sL1);
    arbre->SetBranchAddress("passEle24Tau20", &passEle24Tau20);
    arbre->SetBranchAddress("passEle24Tau30", &passEle24Tau30);
    arbre->SetBranchAddress("matchEle25eta2p1Tight_1", &matchEle25eta2p1Tight_1);
    arbre->SetBranchAddress("matchEle27eta2p1Loose_1", &matchEle27eta2p1Loose_1);
    arbre->SetBranchAddress("matchEle24Tau20sL1_1", &matchEle24Tau20sL1_1);
    arbre->SetBranchAddress("matchEle24Tau20_1", &matchEle24Tau20_1);
    arbre->SetBranchAddress("matchEle24Tau30_1", &matchEle24Tau30_1);
    arbre->SetBranchAddress("filterEle25eta2p1Tight_1", &filterEle25eta2p1Tight_1);
    arbre->SetBranchAddress("filterEle27eta2p1Loose_1", &filterEle27eta2p1Loose_1);
    arbre->SetBranchAddress("filterEle24Tau20sL1_1", &filterEle24Tau20sL1_1);
    arbre->SetBranchAddress("filterEle24Tau20_1", &filterEle24Tau20_1);
    arbre->SetBranchAddress("filterEle24Tau30_1", &filterEle24Tau30_1);
    arbre->SetBranchAddress("matchEle24Tau20sL1_2", &matchEle24Tau20sL1_2);
    arbre->SetBranchAddress("matchEle24Tau20_2", &matchEle24Tau20_2);
    arbre->SetBranchAddress("matchEle24Tau30_2", &matchEle24Tau30_2);
    arbre->SetBranchAddress("filterEle24Tau20sL1_2", &filterEle24Tau20sL1_2);
    arbre->SetBranchAddress("filterEle24Tau20_2", &filterEle24Tau20_2);
    arbre->SetBranchAddress("filterEle24Tau30_2", &filterEle24Tau30_2);

    //arbre->SetBranchAddress("e_2",&e_2);
    arbre->SetBranchAddress("decayModeFindingNewDMs_2",&decayModeFindingNewDMs_2);
    arbre->SetBranchAddress("decayModeFinding_2",&decayModeFinding_2);
    arbre->SetBranchAddress("l2_decayMode",&l2_decayMode);
    arbre->SetBranchAddress("againstElectronVLooseMVA6_2",&againstElectronVLooseMVA6_2);
    arbre->SetBranchAddress("againstElectronLooseMVA6_2",&againstElectronLooseMVA6_2);
    arbre->SetBranchAddress("againstElectronMediumMVA6_2",&againstElectronMediumMVA6_2);
    arbre->SetBranchAddress("againstElectronTightMVA6_2",&againstElectronTightMVA6_2);
    arbre->SetBranchAddress("againstElectronVTightMVA6_2",&againstElectronVTightMVA6_2);
    arbre->SetBranchAddress("againstMuonLoose3_2",&againstMuonLoose3_2);
    arbre->SetBranchAddress("againstMuonTight3_2",&againstMuonTight3_2);
    arbre->SetBranchAddress("gen_match_1",&gen_match_1);
    arbre->SetBranchAddress("gen_match_2",&gen_match_2);
    arbre->SetBranchAddress("m_vis",&m_vis);
    arbre->SetBranchAddress("npu",&npu);
    arbre->SetBranchAddress("genpT",&genpT);
    arbre->SetBranchAddress("genM",&genM);
    arbre->SetBranchAddress("pt_top1",&pt_top1);
    arbre->SetBranchAddress("pt_top2",&pt_top2);
    arbre->SetBranchAddress("numGenJets",&numGenJets);

    arbre->SetBranchAddress("njets_JetAbsoluteFlavMapDown",&njets_JetAbsoluteFlavMapDown);
    arbre->SetBranchAddress("njets_JetAbsoluteFlavMapUp",&njets_JetAbsoluteFlavMapUp);
    arbre->SetBranchAddress("njets_JetAbsoluteMPFBiasDown",&njets_JetAbsoluteMPFBiasDown);
    arbre->SetBranchAddress("njets_JetAbsoluteMPFBiasUp",&njets_JetAbsoluteMPFBiasUp);
    arbre->SetBranchAddress("njets_JetAbsoluteScaleDown",&njets_JetAbsoluteScaleDown);
    arbre->SetBranchAddress("njets_JetAbsoluteScaleUp",&njets_JetAbsoluteScaleUp);
    arbre->SetBranchAddress("njets_JetAbsoluteStatDown",&njets_JetAbsoluteStatDown);
    arbre->SetBranchAddress("njets_JetAbsoluteStatUp",&njets_JetAbsoluteStatUp);
    arbre->SetBranchAddress("njets_JetFlavorQCDDown",&njets_JetFlavorQCDDown);
    arbre->SetBranchAddress("njets_JetFlavorQCDUp",&njets_JetFlavorQCDUp);
    arbre->SetBranchAddress("njets_JetFragmentationDown",&njets_JetFragmentationDown);
    arbre->SetBranchAddress("njets_JetFragmentationUp",&njets_JetFragmentationUp);
    arbre->SetBranchAddress("njets_JetPileUpDataMCDown",&njets_JetPileUpDataMCDown);
    arbre->SetBranchAddress("njets_JetPileUpDataMCUp",&njets_JetPileUpDataMCUp);
    arbre->SetBranchAddress("njets_JetPileUpPtBBDown",&njets_JetPileUpPtBBDown);
    arbre->SetBranchAddress("njets_JetPileUpPtBBUp",&njets_JetPileUpPtBBUp);
    arbre->SetBranchAddress("njets_JetPileUpPtEC1Down",&njets_JetPileUpPtEC1Down);
    arbre->SetBranchAddress("njets_JetPileUpPtEC1Up",&njets_JetPileUpPtEC1Up);
    arbre->SetBranchAddress("njets_JetPileUpPtEC2Down",&njets_JetPileUpPtEC2Down);
    arbre->SetBranchAddress("njets_JetPileUpPtEC2Up",&njets_JetPileUpPtEC2Up);
    arbre->SetBranchAddress("njets_JetPileUpPtHFDown",&njets_JetPileUpPtHFDown);
    arbre->SetBranchAddress("njets_JetPileUpPtHFUp",&njets_JetPileUpPtHFUp);
    arbre->SetBranchAddress("njets_JetPileUpPtRefDown",&njets_JetPileUpPtRefDown);
    arbre->SetBranchAddress("njets_JetPileUpPtRefUp",&njets_JetPileUpPtRefUp);
    arbre->SetBranchAddress("njets_JetRelativeBalDown",&njets_JetRelativeBalDown);
    arbre->SetBranchAddress("njets_JetRelativeBalUp",&njets_JetRelativeBalUp);
    arbre->SetBranchAddress("njets_JetRelativeFSRDown",&njets_JetRelativeFSRDown);
    arbre->SetBranchAddress("njets_JetRelativeFSRUp",&njets_JetRelativeFSRUp);
    arbre->SetBranchAddress("njets_JetRelativeJEREC1Down",&njets_JetRelativeJEREC1Down);
    arbre->SetBranchAddress("njets_JetRelativeJEREC1Up",&njets_JetRelativeJEREC1Up);
    arbre->SetBranchAddress("njets_JetRelativeJEREC2Down",&njets_JetRelativeJEREC2Down);
    arbre->SetBranchAddress("njets_JetRelativeJEREC2Up",&njets_JetRelativeJEREC2Up);
    arbre->SetBranchAddress("njets_JetRelativeJERHFDown",&njets_JetRelativeJERHFDown);
    arbre->SetBranchAddress("njets_JetRelativeJERHFUp",&njets_JetRelativeJERHFUp);
    arbre->SetBranchAddress("njets_JetRelativePtBBDown",&njets_JetRelativePtBBDown);
    arbre->SetBranchAddress("njets_JetRelativePtBBUp",&njets_JetRelativePtBBUp);
    arbre->SetBranchAddress("njets_JetRelativePtEC1Down",&njets_JetRelativePtEC1Down);
    arbre->SetBranchAddress("njets_JetRelativePtEC1Up",&njets_JetRelativePtEC1Up);
    arbre->SetBranchAddress("njets_JetRelativePtEC2Down",&njets_JetRelativePtEC2Down);
    arbre->SetBranchAddress("njets_JetRelativePtEC2Up",&njets_JetRelativePtEC2Up);
    arbre->SetBranchAddress("njets_JetRelativePtHFDown",&njets_JetRelativePtHFDown);
    arbre->SetBranchAddress("njets_JetRelativePtHFUp",&njets_JetRelativePtHFUp);
    arbre->SetBranchAddress("njets_JetRelativeStatECDown",&njets_JetRelativeStatECDown);
    arbre->SetBranchAddress("njets_JetRelativeStatECUp",&njets_JetRelativeStatECUp);
    arbre->SetBranchAddress("njets_JetRelativeStatFSRDown",&njets_JetRelativeStatFSRDown);
    arbre->SetBranchAddress("njets_JetRelativeStatFSRUp",&njets_JetRelativeStatFSRUp);
    arbre->SetBranchAddress("njets_JetRelativeStatHFDown",&njets_JetRelativeStatHFDown);
    arbre->SetBranchAddress("njets_JetRelativeStatHFUp",&njets_JetRelativeStatHFUp);
    arbre->SetBranchAddress("njets_JetSinglePionECALDown",&njets_JetSinglePionECALDown);
    arbre->SetBranchAddress("njets_JetSinglePionECALUp",&njets_JetSinglePionECALUp);
    arbre->SetBranchAddress("njets_JetSinglePionHCALDown",&njets_JetSinglePionHCALDown);
    arbre->SetBranchAddress("njets_JetSinglePionHCALUp",&njets_JetSinglePionHCALUp);
    arbre->SetBranchAddress("njets_JetTimePtEtaDown",&njets_JetTimePtEtaDown);
    arbre->SetBranchAddress("njets_JetTimePtEtaUp",&njets_JetTimePtEtaUp);

    arbre->SetBranchAddress("mjj_JetAbsoluteFlavMapDown",&mjj_JetAbsoluteFlavMapDown);
    arbre->SetBranchAddress("mjj_JetAbsoluteFlavMapUp",&mjj_JetAbsoluteFlavMapUp);
    arbre->SetBranchAddress("mjj_JetAbsoluteMPFBiasDown",&mjj_JetAbsoluteMPFBiasDown);
    arbre->SetBranchAddress("mjj_JetAbsoluteMPFBiasUp",&mjj_JetAbsoluteMPFBiasUp);
    arbre->SetBranchAddress("mjj_JetAbsoluteScaleDown",&mjj_JetAbsoluteScaleDown);
    arbre->SetBranchAddress("mjj_JetAbsoluteScaleUp",&mjj_JetAbsoluteScaleUp);
    arbre->SetBranchAddress("mjj_JetAbsoluteStatDown",&mjj_JetAbsoluteStatDown);
    arbre->SetBranchAddress("mjj_JetAbsoluteStatUp",&mjj_JetAbsoluteStatUp);
    arbre->SetBranchAddress("mjj_JetFlavorQCDDown",&mjj_JetFlavorQCDDown);
    arbre->SetBranchAddress("mjj_JetFlavorQCDUp",&mjj_JetFlavorQCDUp);
    arbre->SetBranchAddress("mjj_JetFragmentationDown",&mjj_JetFragmentationDown);
    arbre->SetBranchAddress("mjj_JetFragmentationUp",&mjj_JetFragmentationUp);
    arbre->SetBranchAddress("mjj_JetPileUpDataMCDown",&mjj_JetPileUpDataMCDown);
    arbre->SetBranchAddress("mjj_JetPileUpDataMCUp",&mjj_JetPileUpDataMCUp);
    arbre->SetBranchAddress("mjj_JetPileUpPtBBDown",&mjj_JetPileUpPtBBDown);
    arbre->SetBranchAddress("mjj_JetPileUpPtBBUp",&mjj_JetPileUpPtBBUp);
    arbre->SetBranchAddress("mjj_JetPileUpPtEC1Down",&mjj_JetPileUpPtEC1Down);
    arbre->SetBranchAddress("mjj_JetPileUpPtEC1Up",&mjj_JetPileUpPtEC1Up);
    arbre->SetBranchAddress("mjj_JetPileUpPtEC2Down",&mjj_JetPileUpPtEC2Down);
    arbre->SetBranchAddress("mjj_JetPileUpPtEC2Up",&mjj_JetPileUpPtEC2Up);
    arbre->SetBranchAddress("mjj_JetPileUpPtHFDown",&mjj_JetPileUpPtHFDown);
    arbre->SetBranchAddress("mjj_JetPileUpPtHFUp",&mjj_JetPileUpPtHFUp);
    arbre->SetBranchAddress("mjj_JetPileUpPtRefDown",&mjj_JetPileUpPtRefDown);
    arbre->SetBranchAddress("mjj_JetPileUpPtRefUp",&mjj_JetPileUpPtRefUp);
    arbre->SetBranchAddress("mjj_JetRelativeBalDown",&mjj_JetRelativeBalDown);
    arbre->SetBranchAddress("mjj_JetRelativeBalUp",&mjj_JetRelativeBalUp);
    arbre->SetBranchAddress("mjj_JetRelativeFSRDown",&mjj_JetRelativeFSRDown);
    arbre->SetBranchAddress("mjj_JetRelativeFSRUp",&mjj_JetRelativeFSRUp);
    arbre->SetBranchAddress("mjj_JetRelativeJEREC1Down",&mjj_JetRelativeJEREC1Down);
    arbre->SetBranchAddress("mjj_JetRelativeJEREC1Up",&mjj_JetRelativeJEREC1Up);
    arbre->SetBranchAddress("mjj_JetRelativeJEREC2Down",&mjj_JetRelativeJEREC2Down);
    arbre->SetBranchAddress("mjj_JetRelativeJEREC2Up",&mjj_JetRelativeJEREC2Up);
    arbre->SetBranchAddress("mjj_JetRelativeJERHFDown",&mjj_JetRelativeJERHFDown);
    arbre->SetBranchAddress("mjj_JetRelativeJERHFUp",&mjj_JetRelativeJERHFUp);
    arbre->SetBranchAddress("mjj_JetRelativePtBBDown",&mjj_JetRelativePtBBDown);
    arbre->SetBranchAddress("mjj_JetRelativePtBBUp",&mjj_JetRelativePtBBUp);
    arbre->SetBranchAddress("mjj_JetRelativePtEC1Down",&mjj_JetRelativePtEC1Down);
    arbre->SetBranchAddress("mjj_JetRelativePtEC1Up",&mjj_JetRelativePtEC1Up);
    arbre->SetBranchAddress("mjj_JetRelativePtEC2Down",&mjj_JetRelativePtEC2Down);
    arbre->SetBranchAddress("mjj_JetRelativePtEC2Up",&mjj_JetRelativePtEC2Up);
    arbre->SetBranchAddress("mjj_JetRelativePtHFDown",&mjj_JetRelativePtHFDown);
    arbre->SetBranchAddress("mjj_JetRelativePtHFUp",&mjj_JetRelativePtHFUp);
    arbre->SetBranchAddress("mjj_JetRelativeStatECDown",&mjj_JetRelativeStatECDown);
    arbre->SetBranchAddress("mjj_JetRelativeStatECUp",&mjj_JetRelativeStatECUp);
    arbre->SetBranchAddress("mjj_JetRelativeStatFSRDown",&mjj_JetRelativeStatFSRDown);
    arbre->SetBranchAddress("mjj_JetRelativeStatFSRUp",&mjj_JetRelativeStatFSRUp);
    arbre->SetBranchAddress("mjj_JetRelativeStatHFDown",&mjj_JetRelativeStatHFDown);
    arbre->SetBranchAddress("mjj_JetRelativeStatHFUp",&mjj_JetRelativeStatHFUp);
    arbre->SetBranchAddress("mjj_JetSinglePionECALDown",&mjj_JetSinglePionECALDown);
    arbre->SetBranchAddress("mjj_JetSinglePionECALUp",&mjj_JetSinglePionECALUp);
    arbre->SetBranchAddress("mjj_JetSinglePionHCALDown",&mjj_JetSinglePionHCALDown);
    arbre->SetBranchAddress("mjj_JetSinglePionHCALUp",&mjj_JetSinglePionHCALUp);
    arbre->SetBranchAddress("mjj_JetTimePtEtaDown",&mjj_JetTimePtEtaDown);
    arbre->SetBranchAddress("mjj_JetTimePtEtaUp",&mjj_JetTimePtEtaUp);

   //float bins0[] = {0,20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360,380,400,420,440,460,480,500};
   //float bins1[] = {0,20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360,380,400,420,440,460,480,500};
   //float bins0[] = {0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80};
   //float bins1[] = {0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80};

   //float bins0[] = {20,30,40,50,60,70,80,90,100,110,120,130};
   float bins0[] = {0,20,40,60,80,100,120,140,160,180,200};
   //float bins1[] = {10,15,20,25,30,35,40,45,50,55,60};
   float bins1[] = {10,18,26,34,42,50,58};
   float bins2[] = {10,15,20,25,30,35,40,45,50,55,60,65,70};
   float bins3[] = {10,15,20,25,30,35,40,45,50,55,60,65,70,75,80};

   //float bins0[] = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180};
   //float bins1[] = {0,10,15,20,25,30,35,40,45,50,55,60,80};

   int  binnum1 = sizeof(bins1)/sizeof(Float_t) - 1;
   int  binnum0 = sizeof(bins0)/sizeof(Float_t) - 1;
   int  binnum2 = sizeof(bins2)/sizeof(Float_t) - 1;
   int  binnum3 = sizeof(bins3)/sizeof(Float_t) - 1;

   TH1F *nlowhigh=new TH1F ("nlowhigh", "nlowhigh", 6,0,6);nlowhigh->Sumw2();

   std::vector<TH1F*> n70;
   std::vector<TH1F*> n70SS;

   std::vector<TH1F*> h0_OS;
   std::vector<TH1F*> h1_OS;
   std::vector<TH1F*> h0_SS;
   std::vector<TH1F*> h1_SS;
   std::vector<TH1F*> h0_AI;
   std::vector<TH1F*> h1_AI;
   std::vector<TH1F*> h0_QCD;
   std::vector<TH1F*> h1_QCD;
   std::vector<TH1F*> h0_WOS;
   std::vector<TH1F*> h1_WOS;
   std::vector<TH1F*> h0_WSS;
   std::vector<TH1F*> h1_WSS;

   std::vector<TH1F*> h2_OS;
   std::vector<TH1F*> h3_OS;
   std::vector<TH1F*> h2_SS;
   std::vector<TH1F*> h3_SS;
   std::vector<TH1F*> h2_AI;
   std::vector<TH1F*> h3_AI;
   std::vector<TH1F*> h2_QCD;
   std::vector<TH1F*> h3_QCD;
   std::vector<TH1F*> h2_WOS;
   std::vector<TH1F*> h3_WOS;
   std::vector<TH1F*> h2_WSS;
   std::vector<TH1F*> h3_WSS;

   std::vector<TH1F*> h4_OS;
   std::vector<TH1F*> h5_OS;
   std::vector<TH1F*> h4_SS;
   std::vector<TH1F*> h5_SS;
   std::vector<TH1F*> h4_AI;
   std::vector<TH1F*> h5_AI;
   std::vector<TH1F*> h4_QCD;
   std::vector<TH1F*> h5_QCD;
   std::vector<TH1F*> h4_WOS;
   std::vector<TH1F*> h5_WOS;
   std::vector<TH1F*> h4_WSS;
   std::vector<TH1F*> h5_WSS;
   std::vector<TH1F*> h6_OS;
   std::vector<TH1F*> h6_SS;
   std::vector<TH1F*> h6_AI;
   std::vector<TH1F*> h6_QCD;
   std::vector<TH1F*> h6_WOS;
   std::vector<TH1F*> h6_WSS;


   int nbhist=1;
   if (tes==100) nbhist=56;
   if (tes==1) nbhist=18;
   if (tes==30) nbhist=12;
   if (tes==16) nbhist=6;// Tau DM uncert
   if (tes==17) nbhist=10;// ZL shape
   if (tes==18) nbhist=4;

   for (int k=0; k<nbhist; ++k){
        ostringstream HNn70; HNn70 << "n70" << k;
        ostringstream HNn70SS; HNn70SS << "n70SS" << k;
        n70.push_back(new TH1F (HNn70.str().c_str(),"InvMa",18,0,18)); n70[k]->Sumw2();
        n70SS.push_back(new TH1F (HNn70SS.str().c_str(),"InvMa",18,0,18)); n70SS[k]->Sumw2();

        ostringstream HNS0OS; HNS0OS << "h0_OS" << k;
        ostringstream HNS1OS; HNS1OS << "h1_OS" << k;
        h0_OS.push_back(new TH1F (HNS0OS.str().c_str(),"InvMa",binnum0,bins0)); h0_OS[k]->Sumw2();
        h1_OS.push_back(new TH1F (HNS1OS.str().c_str(),"InvMa",binnum1,bins1)); h1_OS[k]->Sumw2();
        ostringstream HNS2OS; HNS2OS << "h2_OS" << k;
        ostringstream HNS3OS; HNS3OS << "h3_OS" << k;
        h2_OS.push_back(new TH1F (HNS2OS.str().c_str(),"InvMa",binnum0,bins0)); h2_OS[k]->Sumw2();
        h3_OS.push_back(new TH1F (HNS3OS.str().c_str(),"InvMa",binnum1,bins1)); h3_OS[k]->Sumw2();
        ostringstream HNS4OS; HNS4OS << "h4_OS" << k;
        ostringstream HNS5OS; HNS5OS << "h5_OS" << k;
        ostringstream HNS6OS; HNS6OS << "h6_OS" << k;
        h4_OS.push_back(new TH1F (HNS4OS.str().c_str(),"InvMa",binnum1,bins1)); h4_OS[k]->Sumw2();
        h5_OS.push_back(new TH1F (HNS5OS.str().c_str(),"InvMa",binnum2,bins2)); h5_OS[k]->Sumw2();
        h6_OS.push_back(new TH1F (HNS6OS.str().c_str(),"InvMa",binnum3,bins3)); h6_OS[k]->Sumw2();

        ostringstream HNS0SS; HNS0SS << "h0_SS" << k;
        ostringstream HNS1SS; HNS1SS << "h1_SS" << k;
        h0_SS.push_back(new TH1F (HNS0SS.str().c_str(),"InvMa",binnum0,bins0)); h0_SS[k]->Sumw2();
        h1_SS.push_back(new TH1F (HNS1SS.str().c_str(),"InvMa",binnum1,bins1)); h1_SS[k]->Sumw2();
        ostringstream HNS2SS; HNS2SS << "h2_SS" << k;
        ostringstream HNS3SS; HNS3SS << "h3_SS" << k;
        h2_SS.push_back(new TH1F (HNS2SS.str().c_str(),"InvMa",binnum0,bins0)); h2_SS[k]->Sumw2();
        h3_SS.push_back(new TH1F (HNS3SS.str().c_str(),"InvMa",binnum1,bins1)); h3_SS[k]->Sumw2();
        ostringstream HNS4SS; HNS4SS << "h4_SS" << k;
        ostringstream HNS5SS; HNS5SS << "h5_SS" << k;
        ostringstream HNS6SS; HNS6SS << "h6_SS" << k;
        h4_SS.push_back(new TH1F (HNS4SS.str().c_str(),"InvMa",binnum1,bins1)); h4_SS[k]->Sumw2();
        h5_SS.push_back(new TH1F (HNS5SS.str().c_str(),"InvMa",binnum2,bins2)); h5_SS[k]->Sumw2();
        h6_SS.push_back(new TH1F (HNS6SS.str().c_str(),"InvMa",binnum3,bins3)); h6_SS[k]->Sumw2();

        ostringstream HNS0AI; HNS0AI << "h0_AI" << k;
        ostringstream HNS1AI; HNS1AI << "h1_AI" << k;
        h0_AI.push_back(new TH1F (HNS0AI.str().c_str(),"InvMa",binnum0,bins0)); h0_AI[k]->Sumw2();
        h1_AI.push_back(new TH1F (HNS1AI.str().c_str(),"InvMa",binnum1,bins1)); h1_AI[k]->Sumw2();
        ostringstream HNS2AI; HNS2AI << "h2_AI" << k;
        ostringstream HNS3AI; HNS3AI << "h3_AI" << k;
        h2_AI.push_back(new TH1F (HNS2AI.str().c_str(),"InvMa",binnum0,bins0)); h2_AI[k]->Sumw2();
        h3_AI.push_back(new TH1F (HNS3AI.str().c_str(),"InvMa",binnum1,bins1)); h3_AI[k]->Sumw2();
        ostringstream HNS4AI; HNS4AI << "h4_AI" << k;
        ostringstream HNS5AI; HNS5AI << "h5_AI" << k;
        ostringstream HNS6AI; HNS6AI << "h6_AI" << k;
        h4_AI.push_back(new TH1F (HNS4AI.str().c_str(),"InvMa",binnum1,bins1)); h4_AI[k]->Sumw2();
        h5_AI.push_back(new TH1F (HNS5AI.str().c_str(),"InvMa",binnum2,bins2)); h5_AI[k]->Sumw2();
        h6_AI.push_back(new TH1F (HNS6AI.str().c_str(),"InvMa",binnum3,bins3)); h6_AI[k]->Sumw2();

        ostringstream HNS0QCD; HNS0QCD << "h0_QCD" << k;
        ostringstream HNS1QCD; HNS1QCD << "h1_QCD" << k;
        h0_QCD.push_back(new TH1F (HNS0QCD.str().c_str(),"InvMa",binnum0,bins0)); h0_QCD[k]->Sumw2();
        h1_QCD.push_back(new TH1F (HNS1QCD.str().c_str(),"InvMa",binnum1,bins1)); h1_QCD[k]->Sumw2();
        ostringstream HNS2QCD; HNS2QCD << "h2_QCD" << k;
        ostringstream HNS3QCD; HNS3QCD << "h3_QCD" << k;
        h2_QCD.push_back(new TH1F (HNS2QCD.str().c_str(),"InvMa",binnum0,bins0)); h2_QCD[k]->Sumw2();
        h3_QCD.push_back(new TH1F (HNS3QCD.str().c_str(),"InvMa",binnum1,bins1)); h3_QCD[k]->Sumw2();
        ostringstream HNS4QCD; HNS4QCD << "h4_QCD" << k;
        ostringstream HNS5QCD; HNS5QCD << "h5_QCD" << k;
        ostringstream HNS6QCD; HNS6QCD << "h6_QCD" << k;
        h4_QCD.push_back(new TH1F (HNS4QCD.str().c_str(),"InvMa",binnum1,bins1)); h4_QCD[k]->Sumw2();
        h5_QCD.push_back(new TH1F (HNS5QCD.str().c_str(),"InvMa",binnum2,bins2)); h5_QCD[k]->Sumw2();
        h6_QCD.push_back(new TH1F (HNS6QCD.str().c_str(),"InvMa",binnum3,bins3)); h6_QCD[k]->Sumw2();

        ostringstream HNS0WSS; HNS0WSS << "h0_WSS" << k;
        ostringstream HNS1WSS; HNS1WSS << "h1_WSS" << k;
        h0_WSS.push_back(new TH1F (HNS0WSS.str().c_str(),"InvMa",binnum0,bins0)); h0_WSS[k]->Sumw2();
        h1_WSS.push_back(new TH1F (HNS1WSS.str().c_str(),"InvMa",binnum1,bins1));h1_WSS[k]->Sumw2();
        ostringstream HNS2WSS; HNS2WSS << "h2_WSS" << k;
        ostringstream HNS3WSS; HNS3WSS << "h3_WSS" << k;
        h2_WSS.push_back(new TH1F (HNS2WSS.str().c_str(),"InvMa",binnum0,bins0)); h2_WSS[k]->Sumw2();
        h3_WSS.push_back(new TH1F (HNS3WSS.str().c_str(),"InvMa",binnum1,bins1)); h3_WSS[k]->Sumw2();
        ostringstream HNS4WSS; HNS4WSS << "h4_WSS" << k;
        ostringstream HNS5WSS; HNS5WSS << "h5_WSS" << k;
        ostringstream HNS6WSS; HNS6WSS << "h6_WSS" << k;
        h4_WSS.push_back(new TH1F (HNS4WSS.str().c_str(),"InvMa",binnum1,bins1)); h4_WSS[k]->Sumw2();
        h5_WSS.push_back(new TH1F (HNS5WSS.str().c_str(),"InvMa",binnum2,bins2)); h5_WSS[k]->Sumw2();
        h6_WSS.push_back(new TH1F (HNS6WSS.str().c_str(),"InvMa",binnum3,bins3)); h6_WSS[k]->Sumw2();

        ostringstream HNS0WOS; HNS0WOS << "h0_WOS" << k;
        ostringstream HNS1WOS; HNS1WOS << "h1_WOS" << k;
        h0_WOS.push_back(new TH1F (HNS0WOS.str().c_str(),"InvMa",binnum0,bins0)); h0_WOS[k]->Sumw2();
        h1_WOS.push_back(new TH1F (HNS1WOS.str().c_str(),"InvMa",binnum1,bins1)); h1_WOS[k]->Sumw2();
        ostringstream HNS2WOS; HNS2WOS << "h2_WOS" << k;
        ostringstream HNS3WOS; HNS3WOS << "h3_WOS" << k;
        h2_WOS.push_back(new TH1F (HNS2WOS.str().c_str(),"InvMa",binnum0,bins0)); h2_WOS[k]->Sumw2();
        h3_WOS.push_back(new TH1F (HNS3WOS.str().c_str(),"InvMa",binnum1,bins1)); h3_WOS[k]->Sumw2();
        ostringstream HNS4WOS; HNS4WOS << "h4_WOS" << k;
        ostringstream HNS5WOS; HNS5WOS << "h5_WOS" << k;
        ostringstream HNS6WOS; HNS6WOS << "h6_WOS" << k;
        h4_WOS.push_back(new TH1F (HNS4WOS.str().c_str(),"InvMa",binnum1,bins1)); h4_WOS[k]->Sumw2();
        h5_WOS.push_back(new TH1F (HNS5WOS.str().c_str(),"InvMa",binnum2,bins2)); h5_WOS[k]->Sumw2();
        h6_WOS.push_back(new TH1F (HNS6WOS.str().c_str(),"InvMa",binnum3,bins3)); h6_WOS[k]->Sumw2();
   }


    TFile *fEleRec=new TFile("EGammaRec.root");
    TH2F *histEleRec=(TH2F*) fEleRec->Get("EGamma_SF2D");

    TFile *fEleWP80=new TFile("EGammaWP80.root");
    TH2F *histEleWP80=(TH2F*) fEleWP80->Get("EGamma_SF2D");

    TFile *fEleWP90=new TFile("EGammaWP90.root");
    TH2F *histEleWP90=(TH2F*) fEleWP90->Get("EGamma_SF2D");

   ScaleFactor * myScaleFactor_trgEle25 = new ScaleFactor();
   myScaleFactor_trgEle25->init_ScaleFactor("LeptonEfficiencies/Electron/Run2016BtoH/Electron_Ele25WPTight_eff.root");
   ScaleFactor * myScaleFactor_trgEle24Leg = new ScaleFactor();
   myScaleFactor_trgEle24Leg->init_ScaleFactor("LeptonEfficiencies/Electron/Run2016BtoH/Electron_Ele24_eff.root");
   ScaleFactor * myScaleFactor_id = new ScaleFactor();
   myScaleFactor_id->init_ScaleFactor("LeptonEfficiencies/Electron/Run2016BtoH/Electron_IdIso_IsoLt0p1_eff.root");

   TString postfixTES[18]={"_CMS_scale_t_13TeVDown","_CMS_scale_t_13TeVUp","_CMS_scale_t_1prong_13TeVDown","_CMS_scale_t_1prong_13TeVUp","_CMS_scale_t_1prong1pizero_13TeVDown","_CMS_scale_t_1prong1pizero_13TeVUp","_CMS_scale_t_3prong_13TeVDown","_CMS_scale_t_3prong_13TeVUp","_CMS_scale_e_13TeVUp","_CMS_scale_e_13TeVDown","_CMS_btag_heavy_13TeVUp","_CMS_btag_heavy_13TeVDown","_CMS_btag_light_13TeVUp","_CMS_btag_light_13TeVDown","_CMS_scale_met_unclustered_13TeVDown","_CMS_scale_met_unclustered_13TeVUp","_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp"};
   TString postfixDM[6]={"_CMS_tauDMReco_1prong_13TeVUp","_CMS_tauDMReco_1prong_13TeVDown","_CMS_tauDMReco_1prong1pizero_13TeVUp","_CMS_tauDMReco_1prong1pizero_13TeVDown","_CMS_tauDMReco_3prong_13TeVUp","_CMS_tauDMReco_3prong_13TeVDown"};
   TString postfixFakeDM[6]={"_CMS_jetToTauDMReco_1prong_13TeVUp","_CMS_jetToTauDMReco_1prong_13TeVDown","_CMS_jetToTauDMReco_1prong1pizero_13TeVUp","_CMS_jetToTauDMReco_1prong1pizero_13TeVDown","_CMS_jetToTauDMReco_3prong_13TeVUp","_CMS_jetToTauDMReco_3prong_13TeVDown"};
   TString postfixZLshape[12]={"_CMS_htt_ZLShape_et_13TeVUp","_CMS_htt_ZLShape_et_13TeVDown","_CMS_ZLShape_et_0jet_1prong_13TeVUp","_CMS_ZLShape_et_0jet_1prong_13TeVDown","_CMS_ZLShape_et_0jet_1prong1pizero_13TeVUp","_CMS_ZLShape_et_0jet_1prong1pizero_13TeVDown", "_CMS_ZLShape_et_1prong_13TeVUp","_CMS_ZLShape_et_1prong_13TeVDown", "_CMS_ZLShape_et_1prong1pizero_13TeVUp","_CMS_ZLShape_et_1prong1pizero_13TeVDown","_CMS_ZLShape_et_3prong_13TeVUp","_CMS_ZLShape_et_3prong_13TeVDown"};
   TString postfixZLnorm[4]={"_CMS_eFakeTau_1prong_13TeVUp","_CMS_eFakeTau_1prong_13TeVDown","_CMS_eFakeTau_1prong1pizero_13TeVUp","_CMS_eFakeTau_1prong1pizero_13TeVDown"};
   TString postfixJES[56]={"_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"};
   TString postfixFake[12]={"_CMS_fakeRate10_var1_13TeVUp","_CMS_fakeRate10_var1_13TeVDown","_CMS_fakeRate10_var2_13TeVUp","_CMS_fakeRate10_var2_13TeVDown","_CMS_fakeRate1_var1_13TeVUp","_CMS_fakeRate1_var1_13TeVDown","_CMS_fakeRate1_var2_13TeVUp","_CMS_fakeRate1_var2_13TeVDown","_CMS_fakeRate0_var1_13TeVUp","_CMS_fakeRate0_var1_13TeVDown","_CMS_fakeRate0_var2_13TeVUp","_CMS_fakeRate0_var2_13TeVDown"};

   Int_t nentries_wtn = (Int_t) arbre->GetEntries();
   for (Int_t i = 0; i < nentries_wtn; i++) {
        arbre->GetEntry(i);
        if (i % 20000000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
        fflush(stdout);
//if (evt==315090045 or evt==451961707 or evt==514710233 or evt==512106324) cout<<evt<<" "<<pt_2<<" "<<m_sv<<" "<<m_sv_UP<<" "<<m_sv_DOWN<<" "<<met<<endl;
	if (fabs(eta_1)>2.1) continue;

	bool isSingleLep=passEle25eta2p1Tight && matchEle25eta2p1Tight_1 && filterEle25eta2p1Tight_1;
	//bool isCrossTrigger = ((passEle24Tau20sL1 && matchEle24Tau20sL1_1 && filterEle24Tau20sL1_1 && filterEle24Tau20sL1_2) or (passEle24Tau20 && matchEle24Tau20_1 && filterEle24Tau20_1 && filterEle24Tau20_2) or (passEle24Tau30 && matchEle24Tau30_1 && filterEle24Tau30_1 && filterEle24Tau30_2));
	if (!isSingleLep or pt_1<26) continue;

        if ((sample=="ZL" or sample=="EWKZNuNu_L" or sample=="EWKZLL_L") && gen_match_2>4) continue;
        if ((sample=="ZTT" or sample=="EWKZNuNu_TT" or sample=="EWKZLL_TT") && gen_match_2!=5) continue;
	//if (sample=="TTT" and gen_match_2==6) continue;
        if (sample=="TTJ" and gen_match_2!=6) continue;
        if (sample=="TTT" and gen_match_2!=5) continue;
        if (sample=="TTL" and gen_match_2>4) continue;
        if ((sample=="ZLL" or sample=="ZL" or sample=="EWKZNuNu_LL" or sample=="EWKZLL_LL") && gen_match_2==5) continue;
        if ((sample=="ZJ" or sample=="EWKZNuNu_J" or sample=="EWKZLL_J") && gen_match_2!=6) continue;

	if (!againstElectronVLooseMVA6_2 or !againstMuonLoose3_2) continue;

        float sf_trg=1.0;
        float sf_id=1.0;
	float sf_id_anti=1.0;
	float sf_trg_anti=1.0;
	float eff_tau=1.0;

        if (sample!="data_obs"){ //Ele25 only
           sf_trg=myScaleFactor_trgEle25->get_ScaleFactor(pt_1,eta_1);
           sf_id=myScaleFactor_id->get_ScaleFactor(pt_1,eta_1);
        }

	float signalRegion=(byTightIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.10);
        float aiRegion=(byVLooseIsolationMVArun2v1DBoldDMwLT_2 && !byTightIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.10);
	float qcdRegion=(byMediumIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.30);
        float wRegion=(byMediumIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.10);
        float wsfRegion=(byMediumIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.10);

	TLorentzVector mytau; 
	mytau.SetPtEtaPhiM(pt_2,eta_2,phi_2,m_2);
        TLorentzVector myele;
        myele.SetPtEtaPhiM(pt_1,eta_1,phi_1,m_1);
        TLorentzVector mybjet1L;
        mybjet1L.SetPtEtaPhiM(bptL_1,betaL_1,bphiL_1,0);
        TLorentzVector mybjet2L;
        mybjet2L.SetPtEtaPhiM(bptL_2,betaL_2,bphiL_2,0);
        TLorentzVector mybjet1;
        mybjet1.SetPtEtaPhiM(bpt_1,beta_1,bphi_1,0);
        TLorentzVector mybjet2;
        mybjet2.SetPtEtaPhiM(bpt_2,beta_2,bphi_2,0);

	//***************** Visible mass between the muon and the tau **************
        
        if (sample=="W"){
            weight=25.44;
            if (numGenJets==1) weight=6.82;
            else if (numGenJets==2) weight=2.099;
            else if (numGenJets==3) weight=0.689;
            else if (numGenJets==4) weight=0.690;
        }

        if (sample=="ZTT" or sample=="ZLL" or sample=="ZL" or sample=="ZJ"){
            weight=1.418;
            if (numGenJets==1)
                weight=0.457;
            else if (numGenJets==2)
                weight=0.467;
            else if (numGenJets==3)
                weight=0.480;
            else if (numGenJets==4)
                weight=0.393;
        }

        if (sample=="DYlow" or sample=="DYlowll" or sample=="DY1low" or sample=="DY1lowll" or sample=="DY2low" or sample=="DY2lowll"){
            weight=0.0;
            if (numGenJets==1) weight=0.74;
            else if (numGenJets==2) weight=0.823;
        }

	float correction=sf_trg*sf_id*LumiWeights_12->weight(npu);

	float aweight=genweight*weight*correction;
	if (gen_match_2==5) aweight=aweight*0.95;

	if (sample!="data_obs"){
           w->var("e_pt")->setVal(myele.Pt());
           w->var("e_eta")->setVal(myele.Eta());
           aweight=aweight*w->function("e_trk_ratio")->getVal();
        }

        if (sample=="ZTT" or sample=="ZLL" or sample=="ZL" or sample=="ZJ"){
            //float zpt_corr=histZ->GetBinContent(histZ->GetXaxis()->FindBin(genM),histZ->GetYaxis()->FindBin(genpT));
            float zpt_corr=histZ->GetBinContent(histZ->GetXaxis()->FindBin(90),histZ->GetYaxis()->FindBin(genpT));
            if (fabs(tes)!=10) //nominal
                 aweight=aweight*zpt_corr;
            else if (tes==10) // up
                 aweight=aweight*(1+1.10*(zpt_corr-1));
            else if (tes==-10) // down
                 aweight=aweight*(1+0.90*(zpt_corr-1));
        }

	//************************ Jet to tau FR shape **************************
	if (tes==14 && (sample=="TTJ" or sample=="ZJ" or sample=="W") && gen_match_2==6){
	    float jtotau=1-(0.2*mytau.Pt()/100);
	    if (mytau.Pt()>200) jtotau=1-(0.2*200.0/100);
	    aweight=aweight*jtotau;
	}
        if (tes==-14 && (sample=="TTJ" or sample=="ZJ" or sample=="W") && gen_match_2==6){
            float jtotau=1+(0.2*mytau.Pt()/100);
            if (mytau.Pt()>200) jtotau=1+(0.2*200.0/100);
            aweight=aweight*jtotau;
        }

	//*********************** Top pT reweighting ****************************
        float pttop1=pt_top1;
        if (pttop1>400) pttop1=400;
        float pttop2=pt_top2;
        if (pttop2>400) pttop2=400;

        if ((sample=="TTJ" or sample=="TTT" or sample=="TT" or sample=="TTL") && fabs(tes)!=11) aweight*=sqrt(exp(0.0615-0.0005*pttop1)*exp(0.0615-0.0005*pttop2));
        if ((sample=="TTJ" or sample=="TTT" or sample=="TT" or sample=="TTL") && tes==11) aweight*=(1+2*(sqrt(exp(0.0615-0.0005*pttop1)*exp(0.0615-0.0005*pttop2))-1));

        if (gen_match_2==1 or gen_match_2==3){//Yiwen
            if (fabs(eta_2)<1.460) aweight=aweight*1.213;
            else if (fabs(eta_2)>1.558) aweight=aweight*1.375;
        }
        else if (gen_match_2==2 or gen_match_2==4){
            if (fabs(mytau.Eta())<0.4) aweight=aweight*1.012;
            else if (fabs(mytau.Eta())<0.8) aweight=aweight*1.007;
            else if (fabs(mytau.Eta())<1.2) aweight=aweight*0.870;
            else if (fabs(mytau.Eta())<1.7) aweight=aweight*1.154;
            else aweight=aweight*2.281;
        }

        if (sample=="data_obs") aweight=1.0;

        float weight_btag_1b=1.0;
        float weight_btag_2b=1.0;
	float probMC_2b=1.0;
        float probData_2b=1.0;
        float probMC_1b=1.0;
        float probData_1b=1.0;
        if (sample!="data_obs"){
            weight_btag_1b=GetSF_M(1,bpt_1,bflavor_1,0);
            weight_btag_2b=GetSF_L(1,bptL_1,bflavorL_1,0)*GetSF_L(1,bptL_2,bflavorL_2,0);
        }

	//************************* Fill histograms **********************

        if (sample=="data_obs") aweight=1.0;

        TLorentzVector myrawmet;
        myrawmet.SetPtEtaPhiM(met,0,metphi,0);
	TLorentzVector myrawtau=mytau;
        TLorentzVector myrawele=myele;
	TLorentzVector myrawbjet1=mybjet1;

        for (int k=0; k<nbhist; ++k){
	    TLorentzVector mymet=myrawmet;
	    mytau=myrawtau;
	    myele=myrawele;
	    mybjet1=myrawbjet1;

            if (sample!="data_obs"){
              weight_btag_1b=GetSF_M(1,bpt_1,bflavor_1,0);
              weight_btag_2b=GetSF_L(1,bptL_1,bflavorL_1,0)*GetSF_L(1,bptL_2,bflavorL_2,0);
            }

	    float weight2=1.0;

            if (tes==1 && gen_match_2==5){
               if (k==0){ mytau*=0.988; mymet=mymet+(0.012/0.988)*mytau;}
               else if (k==1){ mytau*=1.012; mymet=mymet-(0.012/1.012)*mytau;}
               else if (k==2 && l2_decayMode==0){ mytau*=0.988; mymet=mymet+(0.012/0.988)*mytau;}
               else if (k==3 && l2_decayMode==0){ mytau*=1.012; mymet=mymet-(0.012/1.012)*mytau;}
               else if (k==4 && l2_decayMode==1){ mytau*=0.988; mymet=mymet+(0.012/0.988)*mytau;}
               else if (k==5 && l2_decayMode==1){ mytau*=1.012; mymet=mymet-(0.012/1.012)*mytau;}
               else if (k==6 && l2_decayMode==10){ mytau*=0.988; mymet=mymet+(0.012/0.988)*mytau;}
               else if (k==7 && l2_decayMode==10){ mytau*=1.012; mymet=mymet-(0.012/1.012)*mytau;}
            }

            if (tes==1){
               if (k==8){ myele.SetPtEtaPhiM(pt_1_EScaleUp,eta_1,phi_1,m_1); mymet=mymet+((pt_1-pt_1_EScaleUp)/myele.Pt())*myele;}
               else if (k==9){ myele.SetPtEtaPhiM(pt_1_EScaleDown,eta_1,phi_1,m_1); mymet=mymet+((pt_1-pt_1_EScaleDown)/myele.Pt())*myele;}
	       else if (k==14){ mymet.SetPtEtaPhiM(met_UESDown,0,metphi_UESDown,0);}
               else if (k==15){ mymet.SetPtEtaPhiM(met_UESUp,0,metphi_UESUp,0);}
               else if (k==16){ mymet.SetPtEtaPhiM(met_JESDown,0,metphi_JESDown,0);}
               else if (k==17){ mymet.SetPtEtaPhiM(met_JESUp,0,metphi_JESUp,0);}
	    }

            if (tes==1){
               if (k==10 && bflavor_1>4) weight_btag_1b=GetSF_M(1,bpt_1,bflavor_1,1);
               if (k==11 && bflavor_1>4) weight_btag_1b=GetSF_M(1,bpt_1,bflavor_1,-1);
               if (k==12 && bflavor_1<5) weight_btag_1b=GetSF_M(1,bpt_1,bflavor_1,1);
               if (k==13 && bflavor_1<5) weight_btag_1b=GetSF_M(1,bpt_1,bflavor_1,-1);
            }

	    bool has_1b=nbtag>=1;//FIXME
	    if (tes==1 and k==16) {has_1b=nbtag_JESDown>=1; mybjet1.SetPtEtaPhiM(bpt_1_JESDown,beta_1_JESDown,bphi_1_JESDown,0); weight_btag_1b=GetSF_M(1,bpt_1_JESDown,bflavor_1_JESDown,0);}
            if (tes==1 and k==17) {has_1b=nbtag_JESUp>=1; mybjet1.SetPtEtaPhiM(bpt_1_JESUp,beta_1_JESUp,bphi_1_JESUp,0); weight_btag_1b=GetSF_M(1,bpt_1_JESUp,bflavor_1_JESUp,0);}

            if (tes==17 && sample=="ZL"){
                if (k==0){ 
		    mytau*=1.030; 
		    mymet=mymet-(0.030/1.030)*mytau;
		}
                else if (k==1) { 
		    mytau*=0.97; 
		    mymet=mymet+(0.030/0.97)*mytau;
		}
                else if (k==6 && l2_decayMode==0){ 
                    mytau*=1.030; 
                    mymet=mymet-(0.030/1.030)*mytau;
                }
                else if (k==7 && l2_decayMode==0) { 
                    mytau*=0.97; 
                    mymet=mymet+(0.030/0.97)*mytau;
                }
                else if (k==8 && l2_decayMode==1){ 
                    mytau*=1.030; 
                    mymet=mymet-(0.030/1.030)*mytau;
                } 
                else if (k==9 && l2_decayMode==1) {
                    mytau*=0.97;
                    mymet=mymet+(0.030/0.97)*mytau;
                }
                else if (k==9 && l2_decayMode==10){
                    mytau*=1.030;
                    mymet=mymet-(0.030/1.030)*mytau;
                }
                else if (k==11 && l2_decayMode==10) {
                    mytau*=0.97;
                    mymet=mymet+(0.030/0.97)*mytau;
                }

	    }

            if (mytau.Pt()<25.0) continue; 

	    float mbbtt=(myele+mytau+mybjet1L+mybjet2L).M();
            float mbtt=(myele+mytau+mybjet1).M();
            float mt1=TMass_F(myele.Pt(),mymet.Pt(),myele.Px(),mymet.Px(),myele.Py(),mymet.Py());
            float mt2=TMass_F(mytau.Pt(),mymet.Pt(),mytau.Px(),mymet.Px(),mytau.Py(),mymet.Py());
            float mt12=TMass_F((myele+mytau).Pt(),mymet.Pt(),(myele+mytau).Px(),mymet.Px(),(myele+mytau).Py(),mymet.Py());

            float norm_zeta=norm_F(myele.Px()/myele.Pt()+mytau.Px()/mytau.Pt(),myele.Py()/myele.Pt()+mytau.Py()/mytau.Pt());
            float x_zeta= (myele.Px()/myele.Pt()+mytau.Px()/mytau.Pt())/norm_zeta;
            float y_zeta= (myele.Py()/myele.Pt()+mytau.Py()/mytau.Pt())/norm_zeta;
            float p_zeta_mis=mymet.Px()*x_zeta+mymet.Py()*y_zeta;
            float pzeta_vis=(myele.Px()+mytau.Px())*x_zeta+(myele.Py()+mytau.Py())*y_zeta;
            float pzeta=p_zeta_mis-0.85*pzeta_vis;

            float var_1b=(myele+mytau).M();//mbtt;
            float var_2b=(myele+mytau).M();//mbbtt;
//var_2b=mbbtt;

            float fr=1.0;

            if (l2_decayMode==0) fr= 0.2401 - 0.000614282 * (mytau.Pt()-40);
            if (l2_decayMode==1) fr= 0.230823 - 0.000918427 * (mytau.Pt()-40);
            if (l2_decayMode==10) fr= 0.17867 + 0.000316496 * (mytau.Pt()-40);

            if (tes==30 && l2_decayMode==10){//FIXME
                if (k==0) fr= 0.18166+0.000239627 * (mytau.Pt()-40);
                if (k==1) fr= 0.175687 + 0.000393365 * (mytau.Pt()-40);
                if (k==2) fr= 0.178668 +0.000523315 * (mytau.Pt()-40);
                if (k==3) fr= 0.178679 +0.000109677 * (mytau.Pt()-40);
            }
            if (tes==30 && l2_decayMode==1){
                if (k==4) fr= 0.234162 -0.000943962 * (mytau.Pt()-40);
                if (k==5) fr= 0.227485 -0.000892892 * (mytau.Pt()-40);
                if (k==6) fr= 0.230822 -0.000712327 * (mytau.Pt()-40);
                if (k==7) fr= 0.230825 -0.00112453 * (mytau.Pt()-40);
            }
            if (tes==30 && l2_decayMode==0){
                if (k==8) fr= 0.246021 -0.000686205 * (mytau.Pt()-40);
                if (k==9) fr= 0.234195 -0.00054236 * (mytau.Pt()-40);
                if (k==10) fr= 0.240103 -0.00024351 * (mytau.Pt()-40);
                if (k==11) fr= 0.240112 -0.000985054 * (mytau.Pt()-40);
            }

	    float wfr=fr/(1-fr);

            if (sample=="data_obs") aweight=1.0;

//bool selection_1b = (mymet.Pt()<80 and mt1<50 and mt12<60 and mt2<50 and pzeta>-90);
//bool selection_1b = mt1<40 and mt2<50;
bool selection_1b = mt1<60 and mt2<60;
bool selection_2b = (mymet.Pt()<75 and mt1<60 and mt12<60 and mt2<60 and pzeta>-70);
            bool is_incl_2b=mbbtt>=160 and nbtagL>=2 and selection_2b;
            bool is_2b=mbbtt<160 and nbtagL>=2 and selection_2b;
            bool is_incl_1b=mbtt>=90 and nbtag>=1 and selection_1b;
            bool is_1b=mbtt<90 and nbtag>=1 and selection_1b;
	    bool is_1b_lt80 = mbtt<80 and nbtag>=1 and selection_1b;
            bool is_1b_80to100 = mbtt>=80 and mbtt<100 and nbtag>=1 and selection_1b;
            bool is_1b_100to120 = mbtt>=100 and mbtt<120 and nbtag>=1 and selection_1b;
            bool is_1b_gt120 = mbtt>=120 and nbtag>=1 and selection_1b;

//is_1b=nbtag>=1 and nbtagL<2;
//is_2b=nbtagL>=2;

/*            bool is_incl_2b=mbbtt>=160 and (nbtag15L>=2) and (mymet.Pt()<80 and mt1<60 and mt12<70 and mt2<60 and pzeta>-70);
            bool is_2b=(mbbtt<160 and nbtag15L>=2) and (mymet.Pt()<80 and mt1<60 and mt12<70 and mt2<60 and pzeta>-70);
            bool is_incl_1b=mbtt>=100 and (nbtag>=1 and !is_2b) and (mymet.Pt()<80 and mt1<60 and mt12<70 and mt2<60 and pzeta>-70);
            bool is_1b=(mymet.Pt()<80 and mt1<60 and mt12<70 and mt2<60 and pzeta>-70) and (mbtt<100 and (nbtag15L<2 or mbbtt>=140) and nbtag>=1);
*/
	    //************************** Actual filling *******************************
	    float antiratio=(sf_id_anti*sf_trg_anti)/(sf_id*sf_trg);

	    if (is_incl_2b){
                if (signalRegion && q_1*q_2<0)
                    h0_OS[k]->Fill(var_2b,aweight*weight2*weight_btag_2b);
                if (aiRegion && q_1*q_2<0 && (sample=="data_obs" or gen_match_2<6))
                    h0_AI[k]->Fill(var_2b,aweight*weight2*weight_btag_2b*wfr);
                if (signalRegion && q_1*q_2>0)
                    h0_SS[k]->Fill(var_2b,aweight*weight2*weight_btag_2b);
                if (wRegion && q_1*q_2<0)
                    h0_WOS[k]->Fill(var_2b,aweight*weight2*weight_btag_2b);
                if (wRegion && q_1*q_2>0)
                    h0_WSS[k]->Fill(var_2b,aweight*weight2*weight_btag_2b);
                if (qcdRegion && q_1*q_2>0)
                    h0_QCD[k]->Fill(var_2b,aweight*weight2*weight_btag_2b);
	    }

            if (is_2b){
                if (signalRegion && q_1*q_2<0)
                    h1_OS[k]->Fill(var_2b,aweight*weight2*weight_btag_2b);
                if (aiRegion && q_1*q_2<0 && (sample=="data_obs" or gen_match_2<6))
                    h1_AI[k]->Fill(var_2b,aweight*weight2*weight_btag_2b*wfr);
                if (signalRegion && q_1*q_2>0)
                    h1_SS[k]->Fill(var_2b,aweight*weight2*weight_btag_2b);
                if (wRegion && q_1*q_2<0)
                    h1_WOS[k]->Fill(var_2b,aweight*weight2*weight_btag_2b);
                if (wRegion && q_1*q_2>0)
                    h1_WSS[k]->Fill(var_2b,aweight*weight2*weight_btag_2b);
                if (qcdRegion && q_1*q_2>0)
                    h1_QCD[k]->Fill(var_2b,aweight*weight2*weight_btag_2b);
            }
            if (is_1b_gt120 && mt1<40 && mt2<50){
                if (signalRegion && q_1*q_2<0)
                    h2_OS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (aiRegion && q_1*q_2<0 && (sample=="data_obs" or gen_match_2<6))
                    h2_AI[k]->Fill(var_1b,aweight*weight2*weight_btag_1b*wfr);
                if (signalRegion && q_1*q_2>0)
                    h2_SS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (wRegion && q_1*q_2<0)
                    h2_WOS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (wRegion && q_1*q_2>0)
                    h2_WSS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (qcdRegion && q_1*q_2>0)
                    h2_QCD[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
            }
            if (is_1b){
                if (signalRegion && q_1*q_2<0)
                    h3_OS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (aiRegion && q_1*q_2<0 && (sample=="data_obs" or gen_match_2<6))
                    h3_AI[k]->Fill(var_1b,aweight*weight2*weight_btag_1b*wfr);
                if (signalRegion && q_1*q_2>0)
                    h3_SS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (wRegion && q_1*q_2<0)
                    h3_WOS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (wRegion && q_1*q_2>0)
                    h3_WSS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (qcdRegion && q_1*q_2>0)
                    h3_QCD[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
            }
            if (is_1b_lt80 && mt1<40 && mt2<50){
                if (signalRegion && q_1*q_2<0)
                    h4_OS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (aiRegion && q_1*q_2<0 && (sample=="data_obs" or gen_match_2<6))
                    h4_AI[k]->Fill(var_1b,aweight*weight2*weight_btag_1b*wfr);
                if (signalRegion && q_1*q_2>0)
                    h4_SS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (wRegion && q_1*q_2<0)
                    h4_WOS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (wRegion && q_1*q_2>0)
                    h4_WSS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (qcdRegion && q_1*q_2>0)
                    h4_QCD[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
            }
            if (is_1b_80to100 and pzeta<0 and mt2<50 and mt1<40){
                if (signalRegion && q_1*q_2<0)
                    h5_OS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (aiRegion && q_1*q_2<0 && (sample=="data_obs" or gen_match_2<6))
                    h5_AI[k]->Fill(var_1b,aweight*weight2*weight_btag_1b*wfr);
                if (signalRegion && q_1*q_2>0)
                    h5_SS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (wRegion && q_1*q_2<0)
                    h5_WOS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (wRegion && q_1*q_2>0)
                    h5_WSS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (qcdRegion && q_1*q_2>0)
                    h5_QCD[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
            }
            if (is_1b_100to120 and pzeta<0){
                if (signalRegion && q_1*q_2<0)
                    h6_OS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (aiRegion && q_1*q_2<0 && (sample=="data_obs" or gen_match_2<6))
                    h6_AI[k]->Fill(var_1b,aweight*weight2*weight_btag_1b*wfr);
                if (signalRegion && q_1*q_2>0)
                    h6_SS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (wRegion && q_1*q_2<0)
                    h6_WOS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (wRegion && q_1*q_2>0)
                    h6_WSS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (qcdRegion && q_1*q_2>0)
                    h6_QCD[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
            }
	}
				
    } // end of loop over events

    for (int k=0; k<nbhist; ++k){
       h0_WOS[k]->Scale(h0_OS[k]->Integral()/h0_WOS[k]->Integral());
       h1_WOS[k]->Scale(h1_OS[k]->Integral()/h1_WOS[k]->Integral());
       h0_WSS[k]->Scale(h0_SS[k]->Integral()/h0_WSS[k]->Integral());
       h1_WSS[k]->Scale(h1_SS[k]->Integral()/h1_WSS[k]->Integral());
       h2_WSS[k]->Scale(h2_SS[k]->Integral()/h2_WSS[k]->Integral());
       h3_WSS[k]->Scale(h3_SS[k]->Integral()/h3_WSS[k]->Integral());
       h2_WOS[k]->Scale(h2_OS[k]->Integral()/h2_WOS[k]->Integral());
       h3_WOS[k]->Scale(h3_OS[k]->Integral()/h3_WOS[k]->Integral());
       h4_WOS[k]->Scale(h4_OS[k]->Integral()/h4_WOS[k]->Integral());
       h5_WOS[k]->Scale(h5_OS[k]->Integral()/h5_WOS[k]->Integral());
       h6_WOS[k]->Scale(h6_OS[k]->Integral()/h6_WOS[k]->Integral());
       h4_WSS[k]->Scale(h4_SS[k]->Integral()/h4_WSS[k]->Integral());
       h5_WSS[k]->Scale(h5_SS[k]->Integral()/h5_WSS[k]->Integral());
       h6_WSS[k]->Scale(h6_SS[k]->Integral()/h6_WSS[k]->Integral());
    }

    TFile *fout = TFile::Open(output.c_str(), "RECREATE");
    fout->cd();
    nlowhigh->Write();

    TString postfix="";
    if (tes==1)
	postfix="_CMS_scale_t_et_13TeVUp";
    if (tes==-1)
        postfix="_CMS_scale_t_et_13TeVDown";
    if (tes==15)
        postfix="_CMS_htt_ZLShape_et_13TeVUp";
    if (tes==-15)
        postfix="_CMS_htt_ZLShape_et_13TeVDown";
    if (tes==3)
        postfix="_CMS_scale_met_13TeVUp";
    if (tes==-3)
        postfix="_CMS_scale_met_13TeVDown";
    if (tes==100)
        postfix="_CMS_scale_j_13TeVUp";
    if (tes==-100)
        postfix="_CMS_scale_j_13TeVDown";
    if (tes==11)
        postfix="_CMS_htt_ttbarShape_13TeVUp";
    if (tes==-11)
        postfix="_CMS_htt_ttbarShape_13TeVDown";
    if (tes==-13)
        postfix="_CMS_htt_zmumuShape_VBF_13TeVDown";
    if (tes==13)
        postfix="_CMS_htt_zmumuShape_VBF_13TeVUp";
    if (tes==10)
        postfix="_CMS_htt_dyShape_13TeVUp";
    if (tes==-10)
        postfix="_CMS_htt_dyShape_13TeVDown";
    if (tes==-14)
        postfix="_CMS_htt_jetToTauFake_13TeVDown";
    if (tes==14)
        postfix="_CMS_htt_jetToTauFake_13TeVUp";

    TDirectory *OS0jet =fout->mkdir("et_incl_2b");
    TDirectory *SS0jet =fout->mkdir("SSincl_2b");
    TDirectory *QCD0jet =fout->mkdir("QCDincl_2b");
    TDirectory *OS1jet =fout->mkdir("et_2b");
    TDirectory *SS1jet =fout->mkdir("SS2b");
    TDirectory *QCD1jet =fout->mkdir("QCD2b");
    TDirectory *OS2jet =fout->mkdir("et_incl_1b");
    TDirectory *SS2jet =fout->mkdir("SSincl_1b");
    TDirectory *QCD2jet =fout->mkdir("QCDincl_1b");
    TDirectory *OS3jet =fout->mkdir("et_1b");
    TDirectory *SS3jet =fout->mkdir("SS1b");
    TDirectory *QCD3jet =fout->mkdir("QCD1b");
    TDirectory *AI0jet =fout->mkdir("AIincl_2b");
    TDirectory *AI1jet =fout->mkdir("AI2b");
    TDirectory *AI2jet =fout->mkdir("AIincl_1b");
    TDirectory *AI3jet =fout->mkdir("AI1b");

    TDirectory *OS4jet =fout->mkdir("et_1b_lt80");
    TDirectory *SS4jet =fout->mkdir("SS1b_lt80");
    TDirectory *QCD4jet =fout->mkdir("QCD1b_lt80");
    TDirectory *AI4jet =fout->mkdir("AI1b_lt80");
    TDirectory *OS5jet =fout->mkdir("et_1b_80to100");
    TDirectory *SS5jet =fout->mkdir("SS1b_80to100");
    TDirectory *QCD5jet =fout->mkdir("QCD1b_80to100");
    TDirectory *AI5jet =fout->mkdir("AI1b_80to100");
    TDirectory *OS6jet =fout->mkdir("et_1b_100to120");
    TDirectory *SS6jet =fout->mkdir("SS1b_100to120");
    TDirectory *QCD6jet =fout->mkdir("QCD1b_100to120");
    TDirectory *AI6jet =fout->mkdir("AI1b_100to120");

    for (int k=0; k<nbhist; ++k){
	if (tes==100) postfix=postfixJES[k];
        if (tes==1) postfix=postfixTES[k];
        if (tes==17) postfix=postfixZLshape[k];
        if (tes==18) postfix=postfixZLnorm[k];
	fout->cd();
	n70[k]->SetName("n70"+postfix);
        n70[k]->Write();
        n70SS[k]->SetName("n70SS"+postfix);
        n70SS[k]->Write();
    }

    for (int k=0; k<nbhist; ++k){
        if (tes==100) postfix=postfixJES[k];
        if (tes==1) postfix=postfixTES[k];
        if (tes==17) postfix=postfixZLshape[k];
        if (tes==18) postfix=postfixZLnorm[k];
        if (tes==30) postfix=postfixFake[k];

        for (int nn=1; nn<h0_OS[k]->GetSize()-1; ++nn){
           if (h0_OS[k]->GetBinContent(nn)<=0) h0_OS[k]->SetBinContent(nn,0.00001);
           if (h0_SS[k]->GetBinContent(nn)<=0) h0_SS[k]->SetBinContent(nn,0.00001);
           if (h0_QCD[k]->GetBinContent(nn)<=0) h0_QCD[k]->SetBinContent(nn,0.00001);
           if (h0_WOS[k]->GetBinContent(nn)<=0) h0_WOS[k]->SetBinContent(nn,0.00001);
           if (h0_WSS[k]->GetBinContent(nn)<=0) h0_WSS[k]->SetBinContent(nn,0.00001);
           if (h1_OS[k]->GetBinContent(nn)<=0) h1_OS[k]->SetBinContent(nn,0.00001);
           if (h1_SS[k]->GetBinContent(nn)<=0) h1_SS[k]->SetBinContent(nn,0.00001);
           if (h1_QCD[k]->GetBinContent(nn)<=0) h1_QCD[k]->SetBinContent(nn,0.00001);
           if (h1_WOS[k]->GetBinContent(nn)<=0) h1_WOS[k]->SetBinContent(nn,0.00001);
           if (h1_WSS[k]->GetBinContent(nn)<=0) h1_WSS[k]->SetBinContent(nn,0.00001);

           if (h2_OS[k]->GetBinContent(nn)<=0) h2_OS[k]->SetBinContent(nn,0.00001);
           if (h2_SS[k]->GetBinContent(nn)<=0) h2_SS[k]->SetBinContent(nn,0.00001);
           if (h2_QCD[k]->GetBinContent(nn)<=0) h2_QCD[k]->SetBinContent(nn,0.00001);
           if (h2_WOS[k]->GetBinContent(nn)<=0) h2_WOS[k]->SetBinContent(nn,0.00001);
           if (h2_WSS[k]->GetBinContent(nn)<=0) h2_WSS[k]->SetBinContent(nn,0.00001);
           if (h3_OS[k]->GetBinContent(nn)<=0) h3_OS[k]->SetBinContent(nn,0.00001);
           if (h3_SS[k]->GetBinContent(nn)<=0) h3_SS[k]->SetBinContent(nn,0.00001);
           if (h3_QCD[k]->GetBinContent(nn)<=0) h3_QCD[k]->SetBinContent(nn,0.00001);
           if (h3_WOS[k]->GetBinContent(nn)<=0) h3_WOS[k]->SetBinContent(nn,0.00001);
           if (h3_WSS[k]->GetBinContent(nn)<=0) h3_WSS[k]->SetBinContent(nn,0.00001);

           if (h2_AI[k]->GetBinContent(nn)<=0) h2_AI[k]->SetBinContent(nn,0.00001);
           if (h3_AI[k]->GetBinContent(nn)<=0) h3_AI[k]->SetBinContent(nn,0.00001);
           if (h0_AI[k]->GetBinContent(nn)<=0) h0_AI[k]->SetBinContent(nn,0.00001);
           if (h1_AI[k]->GetBinContent(nn)<=0) h1_AI[k]->SetBinContent(nn,0.00001);

           if (h4_AI[k]->GetBinContent(nn)<=0) h4_AI[k]->SetBinContent(nn,0.00001);
           if (h4_OS[k]->GetBinContent(nn)<=0) h4_OS[k]->SetBinContent(nn,0.00001);
           if (h4_SS[k]->GetBinContent(nn)<=0) h4_SS[k]->SetBinContent(nn,0.00001);
           if (h4_QCD[k]->GetBinContent(nn)<=0) h4_QCD[k]->SetBinContent(nn,0.00001);
           if (h4_WOS[k]->GetBinContent(nn)<=0) h4_WOS[k]->SetBinContent(nn,0.00001);
           if (h4_WSS[k]->GetBinContent(nn)<=0) h4_WSS[k]->SetBinContent(nn,0.00001);
           if (h5_AI[k]->GetBinContent(nn)<=0) h5_AI[k]->SetBinContent(nn,0.00001);
           if (h5_OS[k]->GetBinContent(nn)<=0) h5_OS[k]->SetBinContent(nn,0.00001);
           if (h5_SS[k]->GetBinContent(nn)<=0) h5_SS[k]->SetBinContent(nn,0.00001);
           if (h5_QCD[k]->GetBinContent(nn)<=0) h5_QCD[k]->SetBinContent(nn,0.00001);
           if (h5_WOS[k]->GetBinContent(nn)<=0) h5_WOS[k]->SetBinContent(nn,0.00001);
           if (h5_WSS[k]->GetBinContent(nn)<=0) h5_WSS[k]->SetBinContent(nn,0.00001);
           if (h6_AI[k]->GetBinContent(nn)<=0) h6_AI[k]->SetBinContent(nn,0.00001);
           if (h6_OS[k]->GetBinContent(nn)<=0) h6_OS[k]->SetBinContent(nn,0.00001);
           if (h6_SS[k]->GetBinContent(nn)<=0) h6_SS[k]->SetBinContent(nn,0.00001);
           if (h6_QCD[k]->GetBinContent(nn)<=0) h6_QCD[k]->SetBinContent(nn,0.00001);
           if (h6_WOS[k]->GetBinContent(nn)<=0) h6_WOS[k]->SetBinContent(nn,0.00001);
           if (h6_WSS[k]->GetBinContent(nn)<=0) h6_WSS[k]->SetBinContent(nn,0.00001);
        }

        OS0jet->cd();
        h0_OS[k]->SetName(name.c_str()+postfix);
        h0_WOS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h0_WOS[k]->Write();
        else
           h0_OS[k]->Write();
        SS0jet->cd();
        h0_SS[k]->SetName(name.c_str()+postfix);
        h0_WSS[k]->SetName(name.c_str()+postfix);
        h0_SS[k]->Write();
        QCD0jet->cd();
        h0_QCD[k]->SetName(name.c_str()+postfix);
        h0_QCD[k]->Write();
        AI0jet->cd();
        h0_AI[k]->SetName(name.c_str()+postfix);
        h0_AI[k]->Write();

        OS1jet->cd();
        h1_OS[k]->SetName(name.c_str()+postfix);
        h1_WOS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h1_WOS[k]->Write();
        else
           h1_OS[k]->Write();
        SS1jet->cd();
        h1_SS[k]->SetName(name.c_str()+postfix);
        h1_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h1_WSS[k]->Write();
        else
           h1_SS[k]->Write();
        QCD1jet->cd();
        h1_QCD[k]->SetName(name.c_str()+postfix);
        h1_QCD[k]->Write();
        AI1jet->cd();
        h1_AI[k]->SetName(name.c_str()+postfix);
        h1_AI[k]->Write();

        OS2jet->cd();
        h2_OS[k]->SetName(name.c_str()+postfix);
        h2_WOS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h2_WOS[k]->Write();
        else
           h2_OS[k]->Write();
        SS2jet->cd();
        h2_SS[k]->SetName(name.c_str()+postfix);
        h2_WSS[k]->SetName(name.c_str()+postfix);
        h2_SS[k]->Write();
        QCD2jet->cd();
        h2_QCD[k]->SetName(name.c_str()+postfix);
        h2_QCD[k]->Write();
        AI2jet->cd();
        h2_AI[k]->SetName(name.c_str()+postfix);
        h2_AI[k]->Write();

        OS3jet->cd();
        h3_OS[k]->SetName(name.c_str()+postfix);
        h3_WOS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h3_WOS[k]->Write();
        else
           h3_OS[k]->Write();
        SS3jet->cd();
        h3_SS[k]->SetName(name.c_str()+postfix);
        h3_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h3_WSS[k]->Write();
        else
           h3_SS[k]->Write();
        QCD3jet->cd();
        h3_QCD[k]->SetName(name.c_str()+postfix);
        h3_QCD[k]->Write();
        AI3jet->cd();
        h3_AI[k]->SetName(name.c_str()+postfix);
        h3_AI[k]->Write();

        OS4jet->cd();
        h4_OS[k]->SetName(name.c_str()+postfix);
        h4_WOS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h4_WOS[k]->Write();
        else
           h4_OS[k]->Write();
        SS4jet->cd();
        h4_SS[k]->SetName(name.c_str()+postfix);
        h4_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h4_WSS[k]->Write();
        else
           h4_SS[k]->Write();
        QCD4jet->cd();
        h4_QCD[k]->SetName(name.c_str()+postfix);
        h4_QCD[k]->Write();
        AI4jet->cd();
        h4_AI[k]->SetName(name.c_str()+postfix);
        h4_AI[k]->Write();

        OS5jet->cd();
        h5_OS[k]->SetName(name.c_str()+postfix);
        h5_WOS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h5_WOS[k]->Write();
        else
           h5_OS[k]->Write();
        SS5jet->cd();
        h5_SS[k]->SetName(name.c_str()+postfix);
        h5_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h5_WSS[k]->Write();
        else
           h5_SS[k]->Write();
        QCD5jet->cd();
        h5_QCD[k]->SetName(name.c_str()+postfix);
        h5_QCD[k]->Write();
        AI5jet->cd();
        h5_AI[k]->SetName(name.c_str()+postfix);
        h5_AI[k]->Write();

        OS6jet->cd();
        h6_OS[k]->SetName(name.c_str()+postfix);
        h6_WOS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h6_WOS[k]->Write();
        else
           h6_OS[k]->Write();
        SS6jet->cd();
        h6_SS[k]->SetName(name.c_str()+postfix);
        h6_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h6_WSS[k]->Write();
        else
           h6_SS[k]->Write();
        QCD6jet->cd();
        h6_QCD[k]->SetName(name.c_str()+postfix);
        h6_QCD[k]->Write();
        AI6jet->cd();
        h6_AI[k]->SetName(name.c_str()+postfix);
        h6_AI[k]->Write();

    }

    fout->Close();
} 


