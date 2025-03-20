###########################################################################
## Makefile generated for component 'sads_balance_cubemodel'. 
## 
## Makefile     : sads_balance_cubemodel.mk
## Generated on : Tue Mar 18 18:42:00 2025
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/sads_balance_cubemodel.elf
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file

PRODUCT_NAME              = sads_balance_cubemodel
MAKEFILE                  = sads_balance_cubemodel.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2024b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2024b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/camer/OneDrive/Desktop/SADSBA~1
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ARM Cortex-M
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
COMPILER_COMMAND_FILE     = sads_balance_cubemodel_comp.rsp
CMD_FILE                  = sads_balance_cubemodel.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU Tools for ARM Embedded Processors
# Supported Version(s):    
# ToolchainInfo Version:   2024b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# TARGET_LOAD_CMD_ARGS
# TARGET_LOAD_CMD
# MW_GNU_ARM_TOOLS_PATH
# FDATASECTIONS_FLG

#-----------
# MACROS
#-----------

LIBGCC                    = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-libgcc-file-name}
LIBC                      = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-file-name=libc.a}
LIBM                      = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-file-name=libm.a}
PRODUCT_NAME_WITHOUT_EXTN = $(basename $(PRODUCT))
PRODUCT_BIN               = $(PRODUCT_NAME_WITHOUT_EXTN).bin
PRODUCT_HEX               = $(PRODUCT_NAME_WITHOUT_EXTN).hex
CPFLAGS                   = -O binary
SHELL                     = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: GNU ARM Assembler
AS_PATH = $(MW_GNU_ARM_TOOLS_PATH)
AS = "$(AS_PATH)/arm-none-eabi-gcc"

# C Compiler: GNU ARM C Compiler
CC_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CC = "$(CC_PATH)/arm-none-eabi-gcc"

# Linker: GNU ARM Linker
LD_PATH = $(MW_GNU_ARM_TOOLS_PATH)
LD = "$(LD_PATH)/arm-none-eabi-g++"

# C++ Compiler: GNU ARM C++ Compiler
CPP_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CPP = "$(CPP_PATH)/arm-none-eabi-g++"

# C++ Linker: GNU ARM C++ Linker
CPP_LD_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CPP_LD = "$(CPP_LD_PATH)/arm-none-eabi-g++"

# Archiver: GNU ARM Archiver
AR_PATH = $(MW_GNU_ARM_TOOLS_PATH)
AR = "$(AR_PATH)/arm-none-eabi-ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Binary Converter: Binary Converter
OBJCOPYPATH = $(MW_GNU_ARM_TOOLS_PATH)
OBJCOPY = "$(OBJCOPYPATH)/arm-none-eabi-objcopy"

# Hex Converter: Hex Converter
OBJCOPYPATH = $(MW_GNU_ARM_TOOLS_PATH)
OBJCOPY = "$(OBJCOPYPATH)/arm-none-eabi-objcopy"

# Executable Size: Executable Size
EXESIZEPATH = $(MW_GNU_ARM_TOOLS_PATH)
EXESIZE = "$(EXESIZEPATH)/arm-none-eabi-size"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /f/q
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = ruvs
ASFLAGS              = -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -Wall \
                       -x assembler-with-cpp \
                       $(ASFLAGS_ADDITIONAL) \
                       $(DEFINES) \
                       $(INCLUDES) \
                       -c
OBJCOPYFLAGS_BIN     = -O binary $(PRODUCT) $(PRODUCT_BIN)
CFLAGS               = $(FDATASECTIONS_FLG) \
                       -Wall \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -c \
                       -O0
CPPFLAGS             = -std=gnu++14 \
                       -fno-rtti \
                       -fno-exceptions \
                       $(FDATASECTIONS_FLG) \
                       -Wall \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -c \
                       -O0
CPP_LDFLAGS          = -Wl,--gc-sections \
                       -Wl,-Map="$(PRODUCT_NAME).map"
CPP_SHAREDLIB_LDFLAGS  =
DOWNLOAD_FLAGS       =
EXESIZE_FLAGS        = $(PRODUCT)
EXECUTE_FLAGS        =
OBJCOPYFLAGS_HEX     = -O ihex $(PRODUCT) $(PRODUCT_HEX)
LDFLAGS              = -Wl,--gc-sections \
                       -Wl,-Map="$(PRODUCT_NAME).map"
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/sads_balance_cubemodel.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -DMW_TIM2_ENABLED=1 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DUSE_FULL_LL_DRIVER -DSTM32F446xx -DUSE_HAL_DRIVER -DMW_TIMEBASESOURCE=TIM5
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=0
DEFINES_SKIPFORSIL = -DMW_SCHEDULER_PRIORITY=3 -DXCP_CUSTOM_PLATFORM -DXCP_MEM_DAQ_RESERVED_POOL_BLOCKS_NUMBER=10 -D__FPU_PRESENT=1U -D__FPU_USED=1U -DSTACK_SIZE=512 -DRT -DHWI_TIM2_IRQHandler
DEFINES_STANDARD = -DMODEL=sads_balance_cubemodel -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/src/StepperDrive.cpp C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/mw_stm32_i2c_v1_ll.c C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/mw_stm32_utils.c $(START_DIR)/src/MTi_Driver.c $(START_DIR)/src/xbus.c C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/stm_timer_ll.c C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/mw_stm32_nvic.c $(START_DIR)/sads_balance_cubemodel_ert_rtw/rtGetInf.c $(START_DIR)/sads_balance_cubemodel_ert_rtw/rtGetNaN.c $(START_DIR)/sads_balance_cubemodel_ert_rtw/rt_nonfinite.c $(START_DIR)/sads_balance_cubemodel_ert_rtw/sads_balance_cubemodel.c $(START_DIR)/sads_balance_cubemodel_ert_rtw/sads_balance_cubemodel_data.c C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/overrideHALDelay.c C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/platform_timer.c $(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/scheduler/src/SysTickScheduler.c $(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/scheduler/src/m3m4m4f_multitasking.c $(START_DIR)/sads_balance_cubemx/Core/Src/main.c $(START_DIR)/sads_balance_cubemx/Core/Src/gpio.c $(START_DIR)/sads_balance_cubemx/Core/Src/dma.c $(START_DIR)/sads_balance_cubemx/Core/Src/i2c.c $(START_DIR)/sads_balance_cubemx/Core/Src/tim.c $(START_DIR)/sads_balance_cubemx/Core/Src/usart.c $(START_DIR)/sads_balance_cubemx/Core/Src/stm32f4xx_it.c $(START_DIR)/sads_balance_cubemx/Core/Src/stm32f4xx_hal_msp.c $(START_DIR)/sads_balance_cubemx/Core/Src/stm32f4xx_hal_timebase_tim.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_i2c.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_tim.c $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usart.c $(START_DIR)/sads_balance_cubemx/Core/Src/system_stm32f4xx.c $(START_DIR)/sads_balance_cubemx/STM32CubeIDE/Application/User/Core/syscalls.c $(START_DIR)/sads_balance_cubemx/STM32CubeIDE/Application/User/Core/sysmem.c $(START_DIR)/sads_balance_cubemx/STM32CubeIDE/Application/User/Startup/startup_stm32f446retx.s

MAIN_SRC = $(START_DIR)/sads_balance_cubemodel_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = StepperDrive.o mw_stm32_i2c_v1_ll.o mw_stm32_utils.o MTi_Driver.o xbus.o stm_timer_ll.o mw_stm32_nvic.o rtGetInf.o rtGetNaN.o rt_nonfinite.o sads_balance_cubemodel.o sads_balance_cubemodel_data.o overrideHALDelay.o platform_timer.o SysTickScheduler.o m3m4m4f_multitasking.o main.o gpio.o dma.o i2c.o tim.o usart.o stm32f4xx_it.o stm32f4xx_hal_msp.o stm32f4xx_hal_timebase_tim.o stm32f4xx_ll_gpio.o stm32f4xx_ll_dma.o stm32f4xx_ll_i2c.o stm32f4xx_ll_rcc.o stm32f4xx_ll_utils.o stm32f4xx_ll_exti.o stm32f4xx_hal_rcc.o stm32f4xx_hal_rcc_ex.o stm32f4xx_hal_flash.o stm32f4xx_hal_flash_ex.o stm32f4xx_hal_flash_ramfunc.o stm32f4xx_hal_gpio.o stm32f4xx_hal_dma_ex.o stm32f4xx_hal_dma.o stm32f4xx_hal_pwr.o stm32f4xx_hal_pwr_ex.o stm32f4xx_hal_cortex.o stm32f4xx_hal.o stm32f4xx_hal_exti.o stm32f4xx_hal_tim.o stm32f4xx_hal_tim_ex.o stm32f4xx_ll_tim.o stm32f4xx_ll_usart.o system_stm32f4xx.o syscalls.o sysmem.o startup_stm32f446retx.o

MAIN_OBJ = ert_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = C:/ProgramData/MATLAB/SupportPackages/R2024b/3P.instrset/cmsis_dsp.instrset/Lib/GCC/arm_cortexm4ldfsp_math/libCMSISDSP.a C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/lib/GCC/libmw_pdmfilter_m4_spfp.lib

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard
CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = --specs=nano.specs
CPP_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry Reset_Handler --specs=nosys.specs  -T"C:\Users\camer\OneDrive\Desktop\SADS Balance\sads_balance_cubemx\STM32CubeIDE\STM32F446RETX_FLASH.ld"

CPP_LDFLAGS += $(CPP_LDFLAGS_) $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = --specs=nano.specs
CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry Reset_Handler --specs=nosys.specs  -T"C:\Users\camer\OneDrive\Desktop\SADS Balance\sads_balance_cubemx\STM32CubeIDE\STM32F446RETX_FLASH.ld"

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_) $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------
# Linker
#-----------

LDFLAGS_ = --specs=nano.specs
LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry Reset_Handler --specs=nosys.specs  -T"C:\Users\camer\OneDrive\Desktop\SADS Balance\sads_balance_cubemx\STM32CubeIDE\STM32F446RETX_FLASH.ld"

LDFLAGS += $(LDFLAGS_) $(LDFLAGS_SKIPFORSIL)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = --specs=nano.specs
SHAREDLIB_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry Reset_Handler --specs=nosys.specs  -T"C:\Users\camer\OneDrive\Desktop\SADS Balance\sads_balance_cubemx\STM32CubeIDE\STM32F446RETX_FLASH.ld"

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_) $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


ALL_DEPS:=$(patsubst %.o,%.dep,$(ALL_OBJS))
all:

ifndef DISABLE_GCC_FUNCTION_DATA_SECTIONS
FDATASECTIONS_FLG := -ffunction-sections -fdata-sections
endif



-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk
-include ../../codertarget_assembly_flags.mk
-include mw_gnu_arm_tools_path.mk
-include ../mw_gnu_arm_tools_path.mk
-include ../../mw_gnu_arm_tools_path.mk
-include $(ALL_DEPS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild postbuild download execute


all : build postbuild
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


postbuild : $(PRODUCT)
	@echo "### Invoking postbuild tool "Binary Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_BIN)
	@echo "### Done invoking postbuild tool."
	@echo "### Invoking postbuild tool "Hex Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_HEX)
	@echo "### Done invoking postbuild tool."
	@echo "### Invoking postbuild tool "Executable Size" ..."
	$(EXESIZE) $(EXESIZE_FLAGS)
	@echo "### Done invoking postbuild tool."


download : postbuild


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) @$(CMD_FILE) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : %.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/sads_balance_cubemodel_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/sads_balance_cubemodel_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/sads_balance_cubemodel_ert_rtw/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/sads_balance_cubemodel_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/sads_balance_cubemodel_ert_rtw/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/sads_balance_cubemodel_ert_rtw/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/sads_balance_cubemodel_ert_rtw/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


StepperDrive.o : $(START_DIR)/src/StepperDrive.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mw_stm32_i2c_v1_ll.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/mw_stm32_i2c_v1_ll.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mw_stm32_utils.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/mw_stm32_utils.c
	$(CC) $(CFLAGS) -o "$@" "$<"


MTi_Driver.o : $(START_DIR)/src/MTi_Driver.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xbus.o : $(START_DIR)/src/xbus.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm_timer_ll.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/stm_timer_ll.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mw_stm32_nvic.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/mw_stm32_nvic.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ert_main.o : $(START_DIR)/sads_balance_cubemodel_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetInf.o : $(START_DIR)/sads_balance_cubemodel_ert_rtw/rtGetInf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetNaN.o : $(START_DIR)/sads_balance_cubemodel_ert_rtw/rtGetNaN.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_nonfinite.o : $(START_DIR)/sads_balance_cubemodel_ert_rtw/rt_nonfinite.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sads_balance_cubemodel.o : $(START_DIR)/sads_balance_cubemodel_ert_rtw/sads_balance_cubemodel.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sads_balance_cubemodel_data.o : $(START_DIR)/sads_balance_cubemodel_ert_rtw/sads_balance_cubemodel_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


overrideHALDelay.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/overrideHALDelay.c
	$(CC) $(CFLAGS) -o "$@" "$<"


platform_timer.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/platform_timer.c
	$(CC) $(CFLAGS) -o "$@" "$<"


SysTickScheduler.o : $(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/scheduler/src/SysTickScheduler.c
	$(CC) $(CFLAGS) -o "$@" "$<"


m3m4m4f_multitasking.o : $(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/scheduler/src/m3m4m4f_multitasking.c
	$(CC) $(CFLAGS) -o "$@" "$<"


main.o : $(START_DIR)/sads_balance_cubemx/Core/Src/main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


gpio.o : $(START_DIR)/sads_balance_cubemx/Core/Src/gpio.c
	$(CC) $(CFLAGS) -o "$@" "$<"


dma.o : $(START_DIR)/sads_balance_cubemx/Core/Src/dma.c
	$(CC) $(CFLAGS) -o "$@" "$<"


i2c.o : $(START_DIR)/sads_balance_cubemx/Core/Src/i2c.c
	$(CC) $(CFLAGS) -o "$@" "$<"


tim.o : $(START_DIR)/sads_balance_cubemx/Core/Src/tim.c
	$(CC) $(CFLAGS) -o "$@" "$<"


usart.o : $(START_DIR)/sads_balance_cubemx/Core/Src/usart.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_it.o : $(START_DIR)/sads_balance_cubemx/Core/Src/stm32f4xx_it.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_msp.o : $(START_DIR)/sads_balance_cubemx/Core/Src/stm32f4xx_hal_msp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_timebase_tim.o : $(START_DIR)/sads_balance_cubemx/Core/Src/stm32f4xx_hal_timebase_tim.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_gpio.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_dma.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_i2c.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_i2c.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_rcc.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_utils.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_exti.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_rcc.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_rcc_ex.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_flash.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_flash_ex.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_flash_ramfunc.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_gpio.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_dma_ex.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_dma.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_pwr.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_pwr_ex.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_cortex.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_exti.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_tim.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_tim_ex.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_tim.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_tim.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_usart.o : $(START_DIR)/sads_balance_cubemx/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usart.c
	$(CC) $(CFLAGS) -o "$@" "$<"


system_stm32f4xx.o : $(START_DIR)/sads_balance_cubemx/Core/Src/system_stm32f4xx.c
	$(CC) $(CFLAGS) -o "$@" "$<"


syscalls.o : $(START_DIR)/sads_balance_cubemx/STM32CubeIDE/Application/User/Core/syscalls.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sysmem.o : $(START_DIR)/sads_balance_cubemx/STM32CubeIDE/Application/User/Core/sysmem.c
	$(CC) $(CFLAGS) -o "$@" "$<"


startup_stm32f446retx.o : $(START_DIR)/sads_balance_cubemx/STM32CubeIDE/Application/User/Startup/startup_stm32f446retx.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### OBJCOPYFLAGS_BIN = $(OBJCOPYFLAGS_BIN)"
	@echo "### OBJCOPYFLAGS_HEX = $(OBJCOPYFLAGS_HEX)"
	@echo "### EXESIZE_FLAGS = $(EXESIZE_FLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *.dep
	$(ECHO) "### Deleted all derived files."


