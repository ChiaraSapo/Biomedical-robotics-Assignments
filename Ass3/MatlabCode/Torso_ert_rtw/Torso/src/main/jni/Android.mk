LOCAL_PATH := ..
include $(CLEAR_VARS)
LOCAL_MODULE := Torso
LOCAL_CFLAGS += -DMODEL=Torso -DNUMST=3 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DON_TARGET_WAIT_FOR_START=1 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=1 -DMULTI_INSTANCE_CODE=0 -DEXT_MODE=1 -DINTEGER_CODE=0 -DMT=0 -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT -DPORTABLE_WORDSIZES 
LOCAL_SRC_FILES := C:\PROGRA~3\MATLAB\SUPPOR~1\R2020b\toolbox\target\shared\FILE_L~1\src\ert_targets_logging.c ert_main.c Torso.c Torso_data.c rtGetInf.c rtGetNaN.c rt_nonfinite.c ext_svr.c updown.c ext_work.c rtiostream_utils.c androidinitialize.c rtiostream_interface.c rtiostream_tcpip.c driver_android_gyroscope.c driver_android_plot.c android_file_logging.c 
LOCAL_C_INCLUDES += C:/Users/sarar/OneDrive/Desktop/BIOMED~1/Ass3/MATLAB~1 C:/PROGRA~3/MATLAB/SUPPOR~1/R2020b/toolbox/target/SUPPOR~1/android/include C:/Users/sarar/OneDrive/Desktop/BIOMED~1/Ass3/MATLAB~1/TORSO_~1 C:/PROGRA~1/MATLAB/R2020b/extern/include C:/PROGRA~1/MATLAB/R2020b/simulink/include C:/PROGRA~1/MATLAB/R2020b/rtw/c/src C:/PROGRA~1/MATLAB/R2020b/rtw/c/src/ext_mode/common C:/PROGRA~1/MATLAB/R2020b/rtw/c/ert C:/PROGRA~1/MATLAB/R2020b/toolbox/coder/RTIOST~1/src C:/PROGRA~1/MATLAB/R2020b/toolbox/coder/RTIOST~1/src/utils C:\PROGRA~3\MATLAB\SUPPOR~1\R2020b\toolbox\target\shared\FILE_L~1\include C:\PROGRA~3\MATLAB\SUPPOR~1\R2020b\toolbox\target\SUPPOR~1\android\include 
LOCAL_LDLIBS  +=  -llog -ldl
include $(BUILD_SHARED_LIBRARY)
