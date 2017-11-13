if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal', 'allJES','up', 'down', 'wup', 'wdown','qcdup','qcddown','JESup','JESdown','allTES'], help="Which TES?")
    options = parser.parse_args()

    factor=1.06

    postfix=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_JetAbsoluteFlavMap_13TeVDown","_CMS_scale_j_JetAbsoluteFlavMap_13TeVUp","_CMS_scale_j_JetAbsoluteMPFBias_13TeVDown","_CMS_scale_j_JetAbsoluteMPFBias_13TeVUp","_CMS_scale_j_JetAbsoluteScale_13TeVDown","_CMS_scale_j_JetAbsoluteScale_13TeVUp","_CMS_scale_j_JetAbsoluteStat_13TeVDown","_CMS_scale_j_JetAbsoluteStat_13TeVUp","_CMS_scale_j_JetFlavorQCD_13TeVDown","_CMS_scale_j_JetFlavorQCD_13TeVUp","_CMS_scale_j_JetFragmentation_13TeVDown","_CMS_scale_j_JetFragmentation_13TeVUp","_CMS_scale_j_JetPileUpDataMC_13TeVDown","_CMS_scale_j_JetPileUpDataMC_13TeVUp","_CMS_scale_j_JetPileUpPtBB_13TeVDown","_CMS_scale_j_JetPileUpPtBB_13TeVUp","_CMS_scale_j_JetPileUpPtEC1_13TeVDown","_CMS_scale_j_JetPileUpPtEC1_13TeVUp","_CMS_scale_j_JetPileUpPtEC2_13TeVDown","_CMS_scale_j_JetPileUpPtEC2_13TeVUp","_CMS_scale_j_JetPileUpPtHF_13TeVDown","_CMS_scale_j_JetPileUpPtHF_13TeVUp","_CMS_scale_j_JetPileUpPtRef_13TeVDown","_CMS_scale_j_JetPileUpPtRef_13TeVUp","_CMS_scale_j_JetRelativeBal_13TeVDown","_CMS_scale_j_JetRelativeBal_13TeVUp","_CMS_scale_j_JetRelativeFSR_13TeVDown","_CMS_scale_j_JetRelativeFSR_13TeVUp","_CMS_scale_j_JetRelativeJEREC1_13TeVDown","_CMS_scale_j_JetRelativeJEREC1_13TeVUp","_CMS_scale_j_JetRelativeJEREC2_13TeVDown","_CMS_scale_j_JetRelativeJEREC2_13TeVUp","_CMS_scale_j_JetRelativeJERHF_13TeVDown","_CMS_scale_j_JetRelativeJERHF_13TeVUp","_CMS_scale_j_JetRelativePtBB_13TeVDown","_CMS_scale_j_JetRelativePtBB_13TeVUp","_CMS_scale_j_JetRelativePtEC1_13TeVDown","_CMS_scale_j_JetRelativePtEC1_13TeVUp","_CMS_scale_j_JetRelativePtEC2_13TeVDown","_CMS_scale_j_JetRelativePtEC2_13TeVUp","_CMS_scale_j_JetRelativePtHF_13TeVDown","_CMS_scale_j_JetRelativePtHF_13TeVUp","_CMS_scale_j_JetRelativeStatEC_13TeVDown","_CMS_scale_j_JetRelativeStatEC_13TeVUp","_CMS_scale_j_JetRelativeStatFSR_13TeVDown","_CMS_scale_j_JetRelativeStatFSR_13TeVUp","_CMS_scale_j_JetRelativeStatHF_13TeVDown","_CMS_scale_j_JetRelativeStatHF_13TeVUp","_CMS_scale_j_JetSinglePionECAL_13TeVDown","_CMS_scale_j_JetSinglePionECAL_13TeVUp","_CMS_scale_j_JetSinglePionHCAL_13TeVDown","_CMS_scale_j_JetSinglePionHCAL_13TeVUp","_CMS_scale_j_JetTimePtEta_13TeVDown","_CMS_scale_j_JetTimePtEta_13TeVUp"]
    post2=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfix0=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfix1=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfix2=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfixTES=["_CMS_scale_t_13TeVDown","_CMS_scale_t_13TeVUp","_CMS_scale_t_1prong_13TeVDown","_CMS_scale_t_1prong_13TeVUp","_CMS_scale_t_1prong1pizero_13TeVDown","_CMS_scale_t_1prong1pizero_13TeVUp","_CMS_scale_t_3prong_13TeVDown","_CMS_scale_t_3prong_13TeVUp","_CMS_scale_e_13TeVUp","_CMS_scale_e_13TeVDown","_CMS_btag_heavy_13TeVUp","_CMS_btag_heavy_13TeVDown","_CMS_btag_light_13TeVUp","_CMS_btag_light_13TeVDown","_CMS_scale_met_unclustered_13TeVDown","_CMS_scale_met_unclustered_13TeVUp","_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp"]

    if options.scale!="allJES":
        postfix[0]=""

    if (options.scale!='allJES'):
       postfix0[0]=""
       postfix1[0]=""
       postfix2[0]=""
    if (options.scale=="up"):
        postfix0[0]="_CMS_scale_t_et_13TeVUp"
        postfix1[0]="_CMS_scale_t_et_13TeVUp"
        postfix2[0]="_CMS_scale_t_et_13TeVUp"
    if (options.scale=="down"):
        postfix0[0]="_CMS_scale_t_et_13TeVDown"
        postfix1[0]="_CMS_scale_t_et_13TeVDown"
        postfix2[0]="_CMS_scale_t_et_13TeVDown"
    if (options.scale=="JESup"):
        postfix0[0]="_CMS_scale_j_13TeVUp"
        postfix1[0]="_CMS_scale_j_13TeVUp"
        postfix2[0]="_CMS_scale_j_13TeVUp"
    if (options.scale=="JESdown"):
        postfix0[0]="_CMS_scale_j_13TeVDown"
        postfix1[0]="_CMS_scale_j_13TeVDown"
        postfix2[0]="_CMS_scale_j_13TeVDown"
    if (options.scale=="qcdup"):
        postfix0[0]="_QCDSFUncert_et_incl_1b_13TeVUp"
        postfix1[0]="_QCDSFUncert_et_1b_13TeVUp"
        postfix2[0]="_QCDSFUncert_et_2b_13TeVUp"
    if (options.scale=="qcddown"):
        postfix0[0]="_QCDSFUncert_et_incl_1b_13TeVDown"
        postfix1[0]="_QCDSFUncert_et_1b_13TeVDown"
        postfix2[0]="_QCDSFUncert_et_2b_13TeVDown"
    if (options.scale=="wup"):
        postfix0[0]="_WSFUncert_et_incl_1b_13TeVUp"
        postfix1[0]="_WSFUncert_et_1b_13TeVUp"
        postfix2[0]="_WSFUncert_et_2b_13TeVUp"
    if (options.scale=="wdown"):
        postfix0[0]="_WSFUncert_et_incl_1b_13TeVDown"
        postfix1[0]="_WSFUncert_et_1b_13TeVDown"
        postfix2[0]="_WSFUncert_et_2b_13TeVDown"

    if (options.scale=="JESup"):
        post2[0]="_CMS_scale_j_13TeVUp"
    if (options.scale=="JESdown"):
        post2[0]="_CMS_scale_j_13TeVDown"
    if (options.scale=="up"):
        post2[0]="_CMS_scale_t_et_13TeVUp"
    if (options.scale=="down"):
        post2[0]="_CMS_scale_t_et_13TeVDown"
    if (options.scale=="qcdup"):
        post2[0]=""
    if (options.scale=="qcddown"):
        post2[0]=""
    if (options.scale=="wup"):
        post2[0]=""
    if (options.scale=="wdown"):
        post2[0]=""
    if (options.scale=="nominal"):
        post2[0]=""
        postfix0[0]=""
        postfix1[0]=""
        postfix2[0]=""

    facteur=1.0

    mydir=options.scale
    if options.scale=="allJES":
       mydir="JESup"
    if options.scale=="nominal":
       mydir="nominal"

    if options.scale=="allTES":
      for j in range(0,14):
         post2[j]=postfixTES[j]
         postfix0[j]=postfixTES[j]
         postfix1[j]=postfixTES[j]
         postfix2[j]=postfixTES[j]

    if options.scale=="up" or options.scale=="down" or options.scale=="JESup" or options.scale=="JESdown" or options.scale=="allJES" or options.scale=="allTES":
       fDYJ=ROOT.TFile("files_"+mydir+"/ZJ.root","r")
       fDYL=ROOT.TFile("files_"+mydir+"/ZL.root","r")
       fDYS=ROOT.TFile("files_"+mydir+"/ZTT.root","r")
       fW=ROOT.TFile("files_"+mydir+"/W.root","r")
       fTTJ=ROOT.TFile("files_"+mydir+"/TTJ.root","r")
       fTTT=ROOT.TFile("files_"+mydir+"/TTT.root","r")
       fTTL=ROOT.TFile("files_"+mydir+"/TTL.root","r")
       fVV=ROOT.TFile("files_"+mydir+"/VV.root","r")
       fST=ROOT.TFile("files_"+mydir+"/ST.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
       fout=ROOT.TFile("files_"+mydir+"/QCD.root","recreate")
    else:
       fDYJ=ROOT.TFile("files_nominal/ZJ.root","r")
       fDYL=ROOT.TFile("files_nominal/ZL.root","r")
       fDYS=ROOT.TFile("files_nominal/ZTT.root","r")
       fW=ROOT.TFile("files_nominal/W.root","r")
       fTTJ=ROOT.TFile("files_nominal/TTJ.root","r")
       fTTT=ROOT.TFile("files_nominal/TTT.root","r")
       fTTL=ROOT.TFile("files_nominal/TTL.root","r")
       fVV=ROOT.TFile("files_nominal/VV.root","r")
       fST=ROOT.TFile("files_nominal/ST.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
       fout=ROOT.TFile("files_nominal/QCD.root","recreate")

    fout.cd()
    dir_incl_1b=fout.mkdir("et_incl_1b")
    dir_1b=fout.mkdir("et_1b")
    dir_4b=fout.mkdir("et_1b_lt80")
    dir_5b=fout.mkdir("et_1b_80to100")
    dir_6b=fout.mkdir("et_1b_100to120")
    dir_incl_2b=fout.mkdir("et_incl_2b")
    dir_2b=fout.mkdir("et_2b")

    nbhist=1
    if options.scale=="allJES":
       nbhist=56
    if options.scale=="allTES":
       nbhist=18

    for k in range(0,nbhist):
        hSS_incl_2b=fData.Get("SSincl_2b/data_obs")
        hSS_incl_2b.Add(fDYJ.Get("SSincl_2b/ZJ"+post2[k]),-1)
        hSS_incl_2b.Add(fDYL.Get("SSincl_2b/ZL"+post2[k]),-1)
        hSS_incl_2b.Add(fTTJ.Get("SSincl_2b/TTJ"+post2[k]),-1)
        hSS_incl_2b.Add(fTTT.Get("SSincl_2b/TTT"+post2[k]),-1)
        hSS_incl_2b.Add(fTTL.Get("SSincl_2b/TTL"+post2[k]),-1)
        hSS_incl_2b.Add(fW.Get("SSincl_2b/W"+postfix0[k]),-1)
        hSS_incl_2b.Add(fVV.Get("SSincl_2b/VV"+post2[k]),-1)
        hSS_incl_2b.Add(fST.Get("SSincl_2b/ST"+post2[k]),-1)
        hSS_incl_2b.Add(fDYS.Get("SSincl_2b/ZTT"+post2[k]),-1)
        hSS_incl_2b.SetName("QCD"+postfix0[k])
        hSS_incl_2b.Scale(factor)
        for i in range(0,hSS_incl_2b.GetSize()-2):
            if hSS_incl_2b.GetBinContent(i)<0:
                hSS_incl_2b.SetBinError(i,max(0,hSS_incl_2b.GetBinError(i)+hSS_incl_2b.GetBinError(i)))
                hSS_incl_2b.SetBinContent(i,0)

        hSS_incl_1b=fData.Get("SSincl_1b/data_obs")
        hSS_incl_1b.Add(fDYJ.Get("SSincl_1b/ZJ"+post2[k]),-1)
        hSS_incl_1b.Add(fDYL.Get("SSincl_1b/ZL"+post2[k]),-1)
        hSS_incl_1b.Add(fTTJ.Get("SSincl_1b/TTJ"+post2[k]),-1)
        hSS_incl_1b.Add(fTTT.Get("SSincl_1b/TTT"+post2[k]),-1)
        hSS_incl_1b.Add(fTTL.Get("SSincl_1b/TTL"+post2[k]),-1)
        hSS_incl_1b.Add(fW.Get("SSincl_1b/W"+postfix0[k]),-1)
        hSS_incl_1b.Add(fVV.Get("SSincl_1b/VV"+post2[k]),-1)
        hSS_incl_1b.Add(fST.Get("SSincl_1b/ST"+post2[k]),-1)
        hSS_incl_1b.Add(fDYS.Get("SSincl_1b/ZTT"+post2[k]),-1)
        hSS_incl_1b.SetName("QCD"+postfix0[k])
        hSS_incl_1b.Scale(factor)
        for i in range(0,hSS_incl_1b.GetSize()-2):
            if hSS_incl_1b.GetBinContent(i)<0:
                hSS_incl_1b.SetBinError(i,max(0,hSS_incl_1b.GetBinError(i)+hSS_incl_1b.GetBinError(i)))
                hSS_incl_1b.SetBinContent(i,0)

        hQCD_incl_2b=fData.Get("QCDincl_2b/data_obs")
        hQCD_incl_2b.Add(fDYJ.Get("QCDincl_2b/ZJ"+post2[k]),-1)
        hQCD_incl_2b.Add(fDYL.Get("QCDincl_2b/ZL"+post2[k]),-1)
        hQCD_incl_2b.Add(fTTJ.Get("QCDincl_2b/TTJ"+post2[k]),-1)
        hQCD_incl_2b.Add(fTTT.Get("QCDincl_2b/TTT"+post2[k]),-1)
        hQCD_incl_2b.Add(fTTL.Get("QCDincl_2b/TTL"+post2[k]),-1)
        hQCD_incl_2b.Add(fW.Get("QCDincl_2b/W"+postfix0[k]),-1)
        hQCD_incl_2b.Add(fVV.Get("QCDincl_2b/VV"+post2[k]),-1)
        hQCD_incl_2b.Add(fST.Get("QCDincl_2b/ST"+post2[k]),-1)
        hQCD_incl_2b.Add(fDYS.Get("QCDincl_2b/ZTT"+post2[k]),-1)
        hQCD_incl_2b.SetName("QCD"+postfix0[k])
        hQCD_incl_2b.Scale(factor)
        for i in range(0,hQCD_incl_2b.GetSize()-2):
            if hQCD_incl_2b.GetBinContent(i)<0:
                hQCD_incl_2b.SetBinError(i,max(0,hQCD_incl_2b.GetBinError(i)+hQCD_incl_2b.GetBinError(i)))
                hQCD_incl_2b.SetBinContent(i,0)

        hQCD_incl_1b=fData.Get("QCDincl_1b/data_obs")
        hQCD_incl_1b.Add(fDYJ.Get("QCDincl_1b/ZJ"+post2[k]),-1)
        hQCD_incl_1b.Add(fDYL.Get("QCDincl_1b/ZL"+post2[k]),-1)
        hQCD_incl_1b.Add(fTTJ.Get("QCDincl_1b/TTJ"+post2[k]),-1)
        hQCD_incl_1b.Add(fTTT.Get("QCDincl_1b/TTT"+post2[k]),-1)
        hQCD_incl_1b.Add(fTTL.Get("QCDincl_1b/TTL"+post2[k]),-1)
        hQCD_incl_1b.Add(fW.Get("QCDincl_1b/W"+postfix0[k]),-1)
        hQCD_incl_1b.Add(fVV.Get("QCDincl_1b/VV"+post2[k]),-1)
        hQCD_incl_1b.Add(fST.Get("QCDincl_1b/ST"+post2[k]),-1)
        hQCD_incl_1b.Add(fDYS.Get("QCDincl_1b/ZTT"+post2[k]),-1)
        hQCD_incl_1b.SetName("QCD"+postfix0[k])
        hQCD_incl_1b.Scale(factor)
        for i in range(0,hQCD_incl_1b.GetSize()-2):
            if hQCD_incl_1b.GetBinContent(i)<0:
                hQCD_incl_1b.SetBinError(i,max(0,hQCD_incl_1b.GetBinError(i)+hQCD_incl_1b.GetBinError(i)))
                hQCD_incl_1b.SetBinContent(i,0)

        hSS2b=fData.Get("SS2b/data_obs")
        hSS2b.Add(fDYJ.Get("SS2b/ZJ"+post2[k]),-1)
        hSS2b.Add(fDYL.Get("SS2b/ZL"+post2[k]),-1)
        hSS2b.Add(fTTJ.Get("SS2b/TTJ"+post2[k]),-1)
        hSS2b.Add(fTTT.Get("SS2b/TTT"+post2[k]),-1)
        hSS2b.Add(fTTL.Get("SS2b/TTL"+post2[k]),-1)
        hSS2b.Add(fW.Get("SS2b/W"+postfix1[k]),-1)
        hSS2b.Add(fVV.Get("SS2b/VV"+post2[k]),-1)
        hSS2b.Add(fST.Get("SS2b/ST"+post2[k]),-1)
        hSS2b.Add(fDYS.Get("SS2b/ZTT"+post2[k]),-1)
        hSS2b.SetName("QCD"+postfix1[k])
        hSS2b.Scale(factor)
        for i in range(0,hSS2b.GetSize()-2):
            if hSS2b.GetBinContent(i)<0:
                hSS2b.SetBinError(i,max(0,hSS2b.GetBinError(i)+hSS2b.GetBinError(i)))
                hSS2b.SetBinContent(i,0)

        hSS1b=fData.Get("SS1b/data_obs")
        hSS1b.Add(fDYJ.Get("SS1b/ZJ"+post2[k]),-1)
        hSS1b.Add(fDYL.Get("SS1b/ZL"+post2[k]),-1)
        hSS1b.Add(fTTJ.Get("SS1b/TTJ"+post2[k]),-1)
        hSS1b.Add(fTTT.Get("SS1b/TTT"+post2[k]),-1)
        hSS1b.Add(fTTL.Get("SS1b/TTL"+post2[k]),-1)
        hSS1b.Add(fW.Get("SS1b/W"+postfix1[k]),-1)
        hSS1b.Add(fVV.Get("SS1b/VV"+post2[k]),-1)
        hSS1b.Add(fST.Get("SS1b/ST"+post2[k]),-1)
        hSS1b.Add(fDYS.Get("SS1b/ZTT"+post2[k]),-1)
        hSS1b.SetName("QCD"+postfix1[k])
        hSS1b.Scale(factor)
        for i in range(0,hSS1b.GetSize()-2):
            if hSS1b.GetBinContent(i)<0:
                hSS1b.SetBinError(i,max(0,hSS1b.GetBinError(i)+hSS1b.GetBinError(i)))
                hSS1b.SetBinContent(i,0)

        hSS4b=fData.Get("SS1b_lt80/data_obs")
        hSS4b.Add(fDYJ.Get("SS1b_lt80/ZJ"+post2[k]),-1)
        hSS4b.Add(fDYL.Get("SS1b_lt80/ZL"+post2[k]),-1)
        hSS4b.Add(fTTJ.Get("SS1b_lt80/TTJ"+post2[k]),-1)
        hSS4b.Add(fTTT.Get("SS1b_lt80/TTT"+post2[k]),-1)
        hSS4b.Add(fTTL.Get("SS1b_lt80/TTL"+post2[k]),-1)
        hSS4b.Add(fW.Get("SS1b_lt80/W"+postfix1[k]),-1)
        hSS4b.Add(fVV.Get("SS1b_lt80/VV"+post2[k]),-1)
        hSS4b.Add(fST.Get("SS1b_lt80/ST"+post2[k]),-1)
        hSS4b.Add(fDYS.Get("SS1b_lt80/ZTT"+post2[k]),-1)
        hSS4b.SetName("QCD"+postfix1[k])
        hSS4b.Scale(factor)
        for i in range(0,hSS4b.GetSize()-2):
            if hSS4b.GetBinContent(i)<0:
                hSS4b.SetBinError(i,max(0,hSS4b.GetBinError(i)+hSS4b.GetBinError(i)))
                hSS4b.SetBinContent(i,0)

        hSS5b=fData.Get("SS1b_80to100/data_obs")
        hSS5b.Add(fDYJ.Get("SS1b_80to100/ZJ"+post2[k]),-1)
        hSS5b.Add(fDYL.Get("SS1b_80to100/ZL"+post2[k]),-1)
        hSS5b.Add(fTTJ.Get("SS1b_80to100/TTJ"+post2[k]),-1)
        hSS5b.Add(fTTT.Get("SS1b_80to100/TTT"+post2[k]),-1)
        hSS5b.Add(fTTL.Get("SS1b_80to100/TTL"+post2[k]),-1)
        hSS5b.Add(fW.Get("SS1b_80to100/W"+postfix1[k]),-1)
        hSS5b.Add(fVV.Get("SS1b_80to100/VV"+post2[k]),-1)
        hSS5b.Add(fST.Get("SS1b_80to100/ST"+post2[k]),-1)
        hSS5b.Add(fDYS.Get("SS1b_80to100/ZTT"+post2[k]),-1)
        hSS5b.SetName("QCD"+postfix1[k])
        hSS5b.Scale(factor)
        for i in range(0,hSS5b.GetSize()-2):
            if hSS5b.GetBinContent(i)<0:
                hSS5b.SetBinError(i,max(0,hSS5b.GetBinError(i)+hSS5b.GetBinError(i)))
                hSS5b.SetBinContent(i,0)

        hSS6b=fData.Get("SS1b_100to120/data_obs")
        hSS6b.Add(fDYJ.Get("SS1b_100to120/ZJ"+post2[k]),-1)
        hSS6b.Add(fDYL.Get("SS1b_100to120/ZL"+post2[k]),-1)
        hSS6b.Add(fTTJ.Get("SS1b_100to120/TTJ"+post2[k]),-1)
        hSS6b.Add(fTTT.Get("SS1b_100to120/TTT"+post2[k]),-1)
        hSS6b.Add(fTTL.Get("SS1b_100to120/TTL"+post2[k]),-1)
        hSS6b.Add(fW.Get("SS1b_100to120/W"+postfix1[k]),-1)
        hSS6b.Add(fVV.Get("SS1b_100to120/VV"+post2[k]),-1)
        hSS6b.Add(fST.Get("SS1b_100to120/ST"+post2[k]),-1)
        hSS6b.Add(fDYS.Get("SS1b_100to120/ZTT"+post2[k]),-1)
        hSS6b.SetName("QCD"+postfix1[k])
        hSS6b.Scale(factor)
        for i in range(0,hSS6b.GetSize()-2):
            if hSS6b.GetBinContent(i)<0:
                hSS6b.SetBinError(i,max(0,hSS6b.GetBinError(i)+hSS6b.GetBinError(i)))
                hSS6b.SetBinContent(i,0)

        hQCD2b=fData.Get("QCD2b/data_obs")
        hQCD2b.Add(fDYJ.Get("QCD2b/ZJ"+post2[k]),-1)
        hQCD2b.Add(fDYL.Get("QCD2b/ZL"+post2[k]),-1)
        hQCD2b.Add(fTTJ.Get("QCD2b/TTJ"+post2[k]),-1)
        hQCD2b.Add(fTTT.Get("QCD2b/TTT"+post2[k]),-1)
        hQCD2b.Add(fTTL.Get("QCD2b/TTL"+post2[k]),-1)
        hQCD2b.Add(fW.Get("QCD2b/W"+postfix1[k]),-1)
        hQCD2b.Add(fVV.Get("QCD2b/VV"+post2[k]),-1)
        hQCD2b.Add(fST.Get("QCD2b/ST"+post2[k]),-1)
        hQCD2b.Add(fDYS.Get("QCD2b/ZTT"+post2[k]),-1)
        hQCD2b.SetName("QCD"+postfix1[k])
        hQCD2b.Scale(factor)
        for i in range(0,hQCD2b.GetSize()-2):
            if hQCD2b.GetBinContent(i)<0:
                hQCD2b.SetBinError(i,max(0,hQCD2b.GetBinError(i)+hQCD2b.GetBinError(i)))
                hQCD2b.SetBinContent(i,0)

        hQCD1b=fData.Get("QCD1b/data_obs")
        hQCD1b.Add(fDYJ.Get("QCD1b/ZJ"+post2[k]),-1)
        hQCD1b.Add(fDYL.Get("QCD1b/ZL"+post2[k]),-1)
        hQCD1b.Add(fTTJ.Get("QCD1b/TTJ"+post2[k]),-1)
        hQCD1b.Add(fTTT.Get("QCD1b/TTT"+post2[k]),-1)
        hQCD1b.Add(fTTL.Get("QCD1b/TTL"+post2[k]),-1)
        hQCD1b.Add(fW.Get("QCD1b/W"+postfix1[k]),-1)
        hQCD1b.Add(fVV.Get("QCD1b/VV"+post2[k]),-1)
        hQCD1b.Add(fST.Get("QCD1b/ST"+post2[k]),-1)
        hQCD1b.Add(fDYS.Get("QCD1b/ZTT"+post2[k]),-1)
        hQCD1b.SetName("QCD"+postfix1[k])
        hQCD1b.Scale(factor)
        for i in range(0,hQCD1b.GetSize()-2):
            if hQCD1b.GetBinContent(i)<0:
                hQCD1b.SetBinError(i,max(0,hQCD1b.GetBinError(i)+hQCD1b.GetBinError(i)))
                hQCD1b.SetBinContent(i,0)

        hQCD4b=fData.Get("QCD1b_lt80/data_obs")
        hQCD4b.Add(fDYJ.Get("QCD1b_lt80/ZJ"+post2[k]),-1)
        hQCD4b.Add(fDYL.Get("QCD1b_lt80/ZL"+post2[k]),-1)
        hQCD4b.Add(fTTJ.Get("QCD1b_lt80/TTJ"+post2[k]),-1)
        hQCD4b.Add(fTTT.Get("QCD1b_lt80/TTT"+post2[k]),-1)
        hQCD4b.Add(fTTL.Get("QCD1b_lt80/TTL"+post2[k]),-1)
        hQCD4b.Add(fW.Get("QCD1b_lt80/W"+postfix1[k]),-1)
        hQCD4b.Add(fVV.Get("QCD1b_lt80/VV"+post2[k]),-1)
        hQCD4b.Add(fST.Get("QCD1b_lt80/ST"+post2[k]),-1)
        hQCD4b.Add(fDYS.Get("QCD1b_lt80/ZTT"+post2[k]),-1)
        hQCD4b.SetName("QCD"+postfix1[k])
        hQCD4b.Scale(factor)
        for i in range(0,hQCD4b.GetSize()-2):
            if hQCD4b.GetBinContent(i)<0:
                hQCD4b.SetBinError(i,max(0,hQCD4b.GetBinError(i)+hQCD4b.GetBinError(i)))
                hQCD4b.SetBinContent(i,0)

        hQCD5b=fData.Get("QCD1b_80to100/data_obs")
        hQCD5b.Add(fDYJ.Get("QCD1b_80to100/ZJ"+post2[k]),-1)
        hQCD5b.Add(fDYL.Get("QCD1b_80to100/ZL"+post2[k]),-1)
        hQCD5b.Add(fTTJ.Get("QCD1b_80to100/TTJ"+post2[k]),-1)
        hQCD5b.Add(fTTT.Get("QCD1b_80to100/TTT"+post2[k]),-1)
        hQCD5b.Add(fTTL.Get("QCD1b_80to100/TTL"+post2[k]),-1)
        hQCD5b.Add(fW.Get("QCD1b_80to100/W"+postfix1[k]),-1)
        hQCD5b.Add(fVV.Get("QCD1b_80to100/VV"+post2[k]),-1)
        hQCD5b.Add(fST.Get("QCD1b_80to100/ST"+post2[k]),-1)
        hQCD5b.Add(fDYS.Get("QCD1b_80to100/ZTT"+post2[k]),-1)
        hQCD5b.SetName("QCD"+postfix1[k])
        hQCD5b.Scale(factor)
        for i in range(0,hQCD5b.GetSize()-2):
            if hQCD5b.GetBinContent(i)<0:
                hQCD5b.SetBinError(i,max(0,hQCD5b.GetBinError(i)+hQCD5b.GetBinError(i)))
                hQCD5b.SetBinContent(i,0)

        hQCD6b=fData.Get("QCD1b_100to120/data_obs")
        hQCD6b.Add(fDYJ.Get("QCD1b_100to120/ZJ"+post2[k]),-1)
        hQCD6b.Add(fDYL.Get("QCD1b_100to120/ZL"+post2[k]),-1)
        hQCD6b.Add(fTTJ.Get("QCD1b_100to120/TTJ"+post2[k]),-1)
        hQCD6b.Add(fTTT.Get("QCD1b_100to120/TTT"+post2[k]),-1)
        hQCD6b.Add(fTTL.Get("QCD1b_100to120/TTL"+post2[k]),-1)
        hQCD6b.Add(fW.Get("QCD1b_100to120/W"+postfix1[k]),-1)
        hQCD6b.Add(fVV.Get("QCD1b_100to120/VV"+post2[k]),-1)
        hQCD6b.Add(fST.Get("QCD1b_100to120/ST"+post2[k]),-1)
        hQCD6b.Add(fDYS.Get("QCD1b_100to120/ZTT"+post2[k]),-1)
        hQCD6b.SetName("QCD"+postfix1[k])
        hQCD6b.Scale(factor)
        for i in range(0,hQCD6b.GetSize()-2):
            if hQCD6b.GetBinContent(i)<0:
                hQCD6b.SetBinError(i,max(0,hQCD6b.GetBinError(i)+hQCD6b.GetBinError(i)))
                hQCD6b.SetBinContent(i,0)

        fout.cd()
        dir_incl_1b.cd()
        hQCD_incl_1b.Scale(hSS_incl_1b.Integral()/(0.0001+hQCD_incl_1b.Integral()))
        hQCD_incl_1b.Write()

        dir_1b.cd()
        hQCD1b.Scale(hSS1b.Integral()/(hQCD1b.Integral()+0.00001))
        hQCD1b.Write()

        dir_4b.cd()
        hQCD4b.Scale(hSS4b.Integral()/(hQCD4b.Integral()+0.00001))
        hQCD4b.Write()

        dir_5b.cd()
        hQCD5b.Scale(hSS5b.Integral()/(hQCD5b.Integral()+0.00001))
        hQCD5b.Write()

        dir_6b.cd()
        hQCD6b.Scale(hSS6b.Integral()/(hQCD6b.Integral()+0.00001))
        hQCD6b.Write()

        dir_incl_2b.cd()
        hQCD_incl_2b.Scale(hSS_incl_2b.Integral()/(0.0001+hQCD_incl_2b.Integral()))
        hQCD_incl_2b.Write()

        dir_2b.cd()
        hQCD2b.Scale(hSS2b.Integral()/(hQCD2b.Integral()+0.00001))
        hQCD2b.Write()
