./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/Data.root files_fakeES/Data.root data_obs data_obs 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY.root files_fakeES/ZTTall.root ZTT ZTT 30 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY.root files_fakeES/ZLall.root ZL ZL 30 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY.root files_fakeES/ZJall.root ZJ ZJ 30 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY1.root files_fakeES/ZTT1.root ZTT ZTT 30 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY1.root files_fakeES/ZL1.root ZL ZL 30 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY1.root files_fakeES/ZJ1.root ZJ ZJ 30 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY2.root files_fakeES/ZTT2.root ZTT ZTT 30 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY2.root files_fakeES/ZL2.root ZL ZL 30 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY2.root files_fakeES/ZJ2.root ZJ ZJ 30 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY3.root files_fakeES/ZTT3.root ZTT ZTT 30 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY3.root files_fakeES/ZL3.root ZL ZL 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY3.root files_fakeES/ZJ3.root ZJ ZJ 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY4.root files_fakeES/ZTT4.root ZTT ZTT 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY4.root files_fakeES/ZL4.root ZL ZL 30 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY4.root files_fakeES/ZJ4.root ZJ ZJ 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY1low.root files_fakeES/DY1low.root DY1low ZTT 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/DY2low.root files_fakeES/DY2low.root DY2low ZTT 30
hadd -f files_fakeES/ZTT.root files_fakeES/ZTTall.root files_fakeES/ZTT1.root files_fakeES/ZTT2.root files_fakeES/ZTT3.root files_fakeES/ZTT4.root files_fakeES/DY1low.root files_fakeES/DY2low.root
hadd -f files_fakeES/ZTT.root files_fakeES/ZTTall.root files_fakeES/ZTT1.root files_fakeES/ZTT2.root files_fakeES/ZTT3.root files_fakeES/ZTT4.root
hadd -f files_fakeES/ZJ.root files_fakeES/ZJall.root files_fakeES/ZJ1.root files_fakeES/ZJ2.root files_fakeES/ZJ3.root files_fakeES/ZJ4.root
hadd -f files_fakeES/ZL.root files_fakeES/ZLall.root files_fakeES/ZL1.root files_fakeES/ZL2.root files_fakeES/ZL3.root files_fakeES/ZL4.root
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/TT.root files_fakeES/TTJ.root TTJ TTJ 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/TT.root files_fakeES/TTT.root TTT TTT 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/TT.root files_fakeES/TTL.root TTL TTL 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/W.root files_fakeES/Wincl.root W W 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/W1.root files_fakeES/W1.root W W 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/W2.root files_fakeES/W2.root W W 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/W3.root files_fakeES/W3.root W W 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/W4.root files_fakeES/W4.root W W 30
hadd -f files_fakeES/W.root files_fakeES/W4.root files_fakeES/W3.root files_fakeES/W2.root files_fakeES/W1.root files_fakeES/Wincl.root 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/WW1L1Nu2Q.root files_fakeES/WW1L1Nu2Q.root WW1L1Nu2Q VV 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/VV2L2Nu.root files_fakeES/VV2L2Nu.root VV2L2Nu VV 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/WZLLLNu.root files_fakeES/WZLLLNu.root WZLLLNu VV 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ZZ2L2Q.root files_fakeES/ZZ2L2Q.root ZZ2L2Q VV 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ZZ4L.root files_fakeES/ZZ4L.root ZZ4L VV 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/WZ2L2Q.root files_fakeES/WZ2L2Q.root WZ2L2Q VV 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/WZ1L3Nu.root files_fakeES/WZ1L3Nu.root WZ1L3Nu VV 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/WZ1L1Nu2Q.root files_fakeES/WZ1L1Nu2Q.root WZ1L1Nu2Q VV 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ST_t_top.root files_fakeES/ST_t_top.root ST_t_top ST 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ST_t_antitop.root files_fakeES/ST_t_antitop.root ST_t_antitop ST 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ST_tW_top.root files_fakeES/ST_tW_top.root ST_tW_top ST 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ST_tW_antitop.root files_fakeES/ST_tW_antitop.root ST_tW_antitop ST 30
hadd -f files_fakeES/VV.root files_fakeES/WW1L1Nu2Q.root files_fakeES/WZLLLNu.root files_fakeES/ZZ2L2Q.root files_fakeES/ZZ4L.root files_fakeES/WZ2L2Q.root files_fakeES/WZ1L3Nu.root files_fakeES/WZ1L1Nu2Q.root files_fakeES/VV2L2Nu.root
hadd -f files_fakeES/ST.root files_fakeES/ST_t_top.root files_fakeES/ST_t_antitop.root files_fakeES/ST_tW_top.root files_fakeES/ST_tW_antitop.root

./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ggH125.root files_fakeES/ggH125.root ggH125 ggH_htt125 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ggHWW125.root files_fakeES/ggHWW125.root ggHWW125 ggH_hww125 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/VBF125.root files_fakeES/VBFH125.root VBF125 qqH_htt125 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/VBFWW125.root files_fakeES/VBFHWW125.root VBFWW125 qqH_hww125 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ZH125.root files_fakeES/ZH125.root ZH125 ZH_htt125 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ZHWW125.root files_fakeES/ZHWW125.root ZHWW125 ZH_hww125 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/WplusH125.root files_fakeES/WplusH125.root WplusH125 WH_htt125 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/WplusHWW125.root files_fakeES/WplusHWW125.root WplusHWW125 WH_hww125 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/WminusH125.root files_fakeES/WminusH125.root WminusH125 WH_htt125 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/WminusHWW125.root files_fakeES/WminusHWW125.root WminusHWW125 WH_hww125 30
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_11august/ttHnonbb.root files_fakeES/ttHnonbb.root ttHnonbb ttH_nonbb125 30
hadd -f files_fakeES/SMH.root files_fakeES/ggH125.root files_fakeES/ggHWW125.root files_fakeES/VBFH125.root files_fakeES/VBFHWW125.root files_fakeES/ZH125.root files_fakeES/ZHWW125.root files_fakeES/WplusH125.root files_fakeES/WplusHWW125.root files_fakeES/WminusH125.root files_fakeES/WminusHWW125.root files_fakeES/ttHnonbb.root


python Create_fake.py --scale fakeES
