

if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal', 'up', 'down', 'wup', 'wdown','qcdup','qcddown','JESup','JESdown','allJES','allTES','fakeES'], help="Which TES?")

    nbhist=1

    options = parser.parse_args()
    postfix=""

    fnom=ROOT.TFile("files_nominal/ZTT.root","r")
    fup=ROOT.TFile("files_nominal/DYtt_mbttup.root","r")
    fdown=ROOT.TFile("files_nominal/DYtt_mbttdown.root","r")
    fout=ROOT.TFile("files_nominal/ZTT_mbtt.root","recreate")

    mydir1=fout.mkdir("et_incl_1b")
    mydir2=fout.mkdir("et_1b_lt80")
    mydir3=fout.mkdir("et_1b_80to100")
    mydir4=fout.mkdir("et_1b_100to120")

    hist1up=fup.Get("et_incl_1b").Get("ZTT_CMS_mbttShape_13TeVUp").Clone()
    hist1down=fdown.Get("et_incl_1b").Get("ZTT_CMS_mbttShape_13TeVDown").Clone()
    hist2up=fnom.Get("et_1b_lt80").Get("ZTT").Clone()
    hist2down=fnom.Get("et_1b_lt80").Get("ZTT").Clone()
    hist2up.SetName("ZTT_CMS_mbttShape_13TeVUp")
    hist2down.SetName("ZTT_CMS_mbttShape_13TeVDown")
    for i in range(5,8):
       hist2up.SetBinContent(i,fup.Get("et_1b_lt80").Get("ZTT_CMS_mbttShape_13TeVUp").GetBinContent(i))
       hist2up.SetBinError(i,fup.Get("et_1b_lt80").Get("ZTT_CMS_mbttShape_13TeVUp").GetBinError(i))
       hist2down.SetBinContent(i,fdown.Get("et_1b_lt80").Get("ZTT_CMS_mbttShape_13TeVDown").GetBinContent(i))
       hist2down.SetBinError(i,fdown.Get("et_1b_lt80").Get("ZTT_CMS_mbttShape_13TeVDown").GetBinError(i))
    hist3up=fup.Get("et_1b_80to100").Get("ZTT_CMS_mbttShape_13TeVUp").Clone()
    hist3down=fdown.Get("et_1b_80to100").Get("ZTT_CMS_mbttShape_13TeVDown").Clone()
    hist4up=fup.Get("et_1b_100to120").Get("ZTT_CMS_mbttShape_13TeVUp").Clone()
    hist4down=fdown.Get("et_1b_100to120").Get("ZTT_CMS_mbttShape_13TeVDown").Clone()

    fout.cd()
    mydir1.cd()
    hist1up.Write()
    hist1down.Write()

    mydir2.cd()
    hist2up.Write()
    hist2down.Write()

    mydir3.cd()
    hist3up.Write()
    hist3down.Write()

    mydir4.cd()
    hist4up.Write()
    hist4down.Write()

