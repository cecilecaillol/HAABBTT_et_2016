./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY.root files_allTES/ZTTall.root ZTT ZTT 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY.root files_allTES/ZLall.root ZL ZL 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY.root files_allTES/ZJall.root ZJ ZJ 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY1.root files_allTES/ZTT1.root ZTT ZTT 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY1.root files_allTES/ZL1.root ZL ZL 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY1.root files_allTES/ZJ1.root ZJ ZJ 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY2.root files_allTES/ZTT2.root ZTT ZTT 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY2.root files_allTES/ZL2.root ZL ZL 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY2.root files_allTES/ZJ2.root ZJ ZJ 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY3.root files_allTES/ZTT3.root ZTT ZTT 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY3.root files_allTES/ZL3.root ZL ZL 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY3.root files_allTES/ZJ3.root ZJ ZJ 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY4.root files_allTES/ZTT4.root ZTT ZTT 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY4.root files_allTES/ZL4.root ZL ZL 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY4.root files_allTES/ZJ4.root ZJ ZJ 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DYlow.root files_allTES/DYlow.root DYlow ZTT 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY1low.root files_allTES/DY1low.root DY1low ZTT 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY2low.root files_allTES/DY2low.root DY2low ZTT 1
hadd -f files_allTES/ZTT.root files_allTES/ZTTall.root files_allTES/ZTT1.root files_allTES/ZTT2.root files_allTES/ZTT3.root files_allTES/ZTT4.root files_allTES/DY1low.root files_allTES/DY2low.root files_allTES/DYlow.root
hadd -f files_allTES/ZTT.root files_allTES/ZTTall.root files_allTES/ZTT1.root files_allTES/ZTT2.root files_allTES/ZTT3.root files_allTES/ZTT4.root
hadd -f files_allTES/ZJ.root files_allTES/ZJall.root files_allTES/ZJ1.root files_allTES/ZJ2.root files_allTES/ZJ3.root files_allTES/ZJ4.root
hadd -f files_allTES/ZL.root files_allTES/ZLall.root files_allTES/ZL1.root files_allTES/ZL2.root files_allTES/ZL3.root files_allTES/ZL4.root
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/TT.root files_allTES/TTJ.root TTJ TTJ 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/TT.root files_allTES/TTT.root TTT TTT 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/TT.root files_allTES/TTL.root TTL TTL 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/W.root files_allTES/Wincl.root W W 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/W1.root files_allTES/W1.root W W 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/W2.root files_allTES/W2.root W W 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/W3.root files_allTES/W3.root W W 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/W4.root files_allTES/W4.root W W 1
hadd -f files_allTES/W.root files_allTES/W4.root files_allTES/W3.root files_allTES/W2.root files_allTES/W1.root files_allTES/Wincl.root 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/WW1L1Nu2Q.root files_allTES/WW1L1Nu2Q.root WW1L1Nu2Q VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/VV2L2Nu.root files_allTES/VV2L2Nu.root VV2L2Nu VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/WZLLLNu.root files_allTES/WZLLLNu.root WZLLLNu VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ZZ2L2Q.root files_allTES/ZZ2L2Q.root ZZ2L2Q VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ZZ4L.root files_allTES/ZZ4L.root ZZ4L VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/WZ2L2Q.root files_allTES/WZ2L2Q.root WZ2L2Q VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/WZ1L3Nu.root files_allTES/WZ1L3Nu.root WZ1L3Nu VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/WZ1L1Nu2Q.root files_allTES/WZ1L1Nu2Q.root WZ1L1Nu2Q VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ST_t_top.root files_allTES/ST_t_top.root ST_t_top ST 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ST_t_antitop.root files_allTES/ST_t_antitop.root ST_t_antitop ST 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ST_tW_top.root files_allTES/ST_tW_top.root ST_tW_top ST 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ST_tW_antitop.root files_allTES/ST_tW_antitop.root ST_tW_antitop ST 1
hadd -f files_allTES/VV.root files_allTES/WW1L1Nu2Q.root files_allTES/WZLLLNu.root files_allTES/ZZ2L2Q.root files_allTES/ZZ4L.root files_allTES/WZ2L2Q.root files_allTES/WZ1L3Nu.root files_allTES/WZ1L1Nu2Q.root files_allTES/VV2L2Nu.root
hadd -f files_allTES/ST.root files_allTES/ST_t_top.root files_allTES/ST_t_antitop.root files_allTES/ST_tW_top.root files_allTES/ST_tW_antitop.root

./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/bbtt15.root files_allTES/bbtt15.root bbtt15 ggH_haa_bbtt15 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/bbtt20.root files_allTES/bbtt20.root bbtt20 ggH_haa_bbtt20 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/bbtt25.root files_allTES/bbtt25.root bbtt25 ggH_haa_bbtt25 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/bbtt30.root files_allTES/bbtt30.root bbtt30 ggH_haa_bbtt30 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/bbtt40.root files_allTES/bbtt35.root bbtt35 ggH_haa_bbtt35 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/bbtt40.root files_allTES/bbtt40.root bbtt40 ggH_haa_bbtt40 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/bbtt45.root files_allTES/bbtt45.root bbtt45 ggH_haa_bbtt45 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/bbtt50.root files_allTES/bbtt50.root bbtt50 ggH_haa_bbtt50 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/bbtt55.root files_allTES/bbtt55.root bbtt55 ggH_haa_bbtt55 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/bbtt60.root files_allTES/bbtt60.root bbtt60 ggH_haa_bbtt60 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/VBFbbtt20.root files_allTES/VBFbbtt20.root VBFbbtt20 VBFbbtt20 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/VBFbbtt40.root files_allTES/VBFbbtt40.root VBFbbtt40 VBFbbtt40 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/VBFbbtt60.root files_allTES/VBFbbtt60.root VBFbbtt60 VBFbbtt60 1
hadd -f files_allTES/signal.root files_allTES/bbtt15.root files_allTES/bbtt20.root files_allTES/bbtt25.root files_allTES/bbtt30.root files_allTES/bbtt35.root files_allTES/bbtt40.root files_allTES/bbtt45.root files_allTES/bbtt50.root files_allTES/bbtt55.root files_allTES/bbtt60.root
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ggH125.root files_allTES/ggH125.root ggH125 ggH_htt125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ggHWW125.root files_allTES/ggHWW125.root ggHWW125 ggH_hww125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/VBF125.root files_allTES/VBFH125.root VBF125 qqH_htt125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/VBFWW125.root files_allTES/VBFHWW125.root VBFWW125 qqH_hww125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ZH125.root files_allTES/ZH125.root ZH125 ZH_htt125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ZHWW125.root files_allTES/ZHWW125.root ZHWW125 ZH_hww125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/WplusH125.root files_allTES/WplusH125.root WplusH125 WH_htt125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/WplusHWW125.root files_allTES/WplusHWW125.root WplusHWW125 WH_hww125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/WminusH125.root files_allTES/WminusH125.root WminusH125 WH_htt125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/WminusHWW125.root files_allTES/WminusHWW125.root WminusHWW125 WH_hww125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ttHnonbb.root files_allTES/ttHnonbb.root ttHnonbb ttH_nonbb125 1
hadd -f files_allTES/SMH.root files_allTES/ggH125.root files_allTES/ggHWW125.root files_allTES/VBFH125.root files_allTES/VBFHWW125.root files_allTES/ZH125.root files_allTES/ZHWW125.root files_allTES/WplusH125.root files_allTES/WplusHWW125.root files_allTES/WminusH125.root files_allTES/WminusHWW125.root files_allTES/ttHnonbb.root


python Create_QCD_2Drelaxed.py --scale allTES
python Create_fake.py --scale allTES
python Create_VBF.py --scale allTES

hadd -f final_up.root files_allTES/W.root files_allTES/ZJ.root files_allTES/ZL.root files_allTES/ZTT.root files_allTES/TTT.root files_allTES/TTJ.root files_allTES/QCD.root files_allTES/VV.root files_allTES/signal.root files_allTES/ST.root files_allTES/Fake.root files_allTES/SMH.root files_allTES/VBFsignal.root files_allTES/TTL.root
