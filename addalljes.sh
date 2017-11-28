./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/DY.root files_JESup/ZTTall.root ZTT ZTT 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/DY.root files_JESup/ZLall.root ZL ZL 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/DY.root files_JESup/ZJall.root ZJ ZJ 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/DY1.root files_JESup/ZTT1.root ZTT ZTT 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/DY1.root files_JESup/ZL1.root ZL ZL 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/DY1.root files_JESup/ZJ1.root ZJ ZJ 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/DY2.root files_JESup/ZTT2.root ZTT ZTT 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/DY2.root files_JESup/ZL2.root ZL ZL 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/DY2.root files_JESup/ZJ2.root ZJ ZJ 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/DY3.root files_JESup/ZTT3.root ZTT ZTT 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/DY3.root files_JESup/ZL3.root ZL ZL 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/DY3.root files_JESup/ZJ3.root ZJ ZJ 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/DY4.root files_JESup/ZTT4.root ZTT ZTT 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/DY4.root files_JESup/ZL4.root ZL ZL 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/DY4.root files_JESup/ZJ4.root ZJ ZJ 100
hadd -f files_JESup/ZTT.root files_JESup/ZTTall.root files_JESup/ZTT1.root files_JESup/ZTT2.root files_JESup/ZTT3.root files_JESup/ZTT4.root
hadd -f files_JESup/ZJ.root files_JESup/ZJall.root files_JESup/ZJ1.root files_JESup/ZJ2.root files_JESup/ZJ3.root files_JESup/ZJ4.root
hadd -f files_JESup/ZL.root files_JESup/ZLall.root files_JESup/ZL1.root files_JESup/ZL2.root files_JESup/ZL3.root files_JESup/ZL4.root
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/TT.root files_JESup/TTJ.root TTJ TTJ 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/TT.root files_JESup/TTT.root TTT TTT 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/W.root files_JESup/Wincl.root W W 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/W1.root files_JESup/W1.root W W 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/W2.root files_JESup/W2.root W W 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/W3.root files_JESup/W3.root W W 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/W4.root files_JESup/W4.root W W 100
hadd -f files_JESup/Wunscaled.root files_JESup/W4.root files_JESup/W3.root files_JESup/W2.root files_JESup/W1.root files_JESup/Wincl.root 
#./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/SMH_gg125.root files_JESup/ggH125.root ggH125 ggH_htt125 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/SMH_VBF125.root files_JESup/VBF125.root VBF125 qqH_htt125 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/WW1L1Nu2Q.root files_JESup/WW1L1Nu2Q.root WW1L1Nu2Q VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/VV2L2Nu.root files_JESup/VV2L2Nu.root VV2L2Nu VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/WZLLLNu.root files_JESup/WZLLLNu.root WZLLLNu VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/ZZ2L2Q.root files_JESup/ZZ2L2Q.root ZZ2L2Q VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/ZZ4L.root files_JESup/ZZ4L.root ZZ4L VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/WZ2L2Q.root files_JESup/WZ2L2Q.root WZ2L2Q VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/WZ1L3Nu.root files_JESup/WZ1L3Nu.root WZ1L3Nu VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/WZ1L1Nu2Q.root files_JESup/WZ1L1Nu2Q.root WZ1L1Nu2Q VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/ST_t_top.root files_JESup/ST_t_top.root ST_t_top ST 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/ST_t_antitop.root files_JESup/ST_t_antitop.root ST_t_antitop ST 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/ST_tW_top.root files_JESup/ST_tW_top.root ST_tW_top ST 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/ST_tW_antitop.root files_JESup/ST_tW_antitop.root ST_tW_antitop ST 100
hadd -f files_JESup/VV.root files_JESup/WW1L1Nu2Q.root files_JESup/WZLLLNu.root files_JESup/ZZ2L2Q.root files_JESup/ZZ4L.root files_JESup/WZ2L2Q.root files_JESup/WZ1L3Nu.root files_JESup/WZ1L1Nu2Q.root files_JESup/VV2L2Nu.root
hadd -f files_JESup/ST.root files_JESup/ST_t_top.root files_JESup/ST_t_antitop.root files_JESup/ST_tW_top.root files_JESup/ST_tW_antitop.root

./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/bbtt15.root files_JESup/bbtt15.root bbtt15 bbtt15 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/bbtt20.root files_JESup/bbtt20.root bbtt20 bbtt20 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/bbtt25.root files_JESup/bbtt25.root bbtt25 bbtt25 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/bbtt30.root files_JESup/bbtt30.root bbtt30 bbtt30 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/bbtt40.root files_JESup/bbtt35.root bbtt35 bbtt35 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/bbtt40.root files_JESup/bbtt40.root bbtt40 bbtt40 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/bbtt45.root files_JESup/bbtt45.root bbtt45 bbtt45 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/bbtt50.root files_JESup/bbtt50.root bbtt50 bbtt50 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/bbtt55.root files_JESup/bbtt55.root bbtt55 bbtt55 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_et_3august/bbtt60.root files_JESup/bbtt60.root bbtt60 bbtt60 100
hadd -f files_JESup/signal.root files_JESup/bbtt15.root files_JESup/bbtt20.root files_JESup/bbtt25.root files_JESup/bbtt30.root files_JESup/bbtt35.root files_JESup/bbtt40.root files_JESup/bbtt45.root files_JESup/bbtt50.root files_JESup/bbtt55.root files_JESup/bbtt60.root


python Create_QCD_2Drelaxed.py --scale allJES
python Create_fake.py --scale allJES
hadd -f final_JESup.root files_JESup/W.root files_JESup/ZJ.root files_JESup/ZL.root files_JESup/ZTT.root files_JESup/TTJ.root files_JESup/TTT.root files_JESup/QCD.root files_JESup/VV.root files_JESup/signal.root files_JESup/ST.root files_JESup/Fake.root #files_JESup/ggH125.root files_JESup/VBF125.root 
