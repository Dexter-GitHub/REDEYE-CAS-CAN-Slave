################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Module/Src/%.obj: ../Module/Src/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1250/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/workspace/DSP/6. REDEYE-CAS/workspace/REDEYE-CAS-Slave" --include_path="C:/ti/ccs1250/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --include_path="D:/workspace/DSP/6. REDEYE-CAS/workspace/REDEYE-CAS-Slave/Module/Inc" --include_path="C:/ti/c2000/C2000Ware_5_01_00_00/device_support/f2833x/headers/include" --include_path="C:/ti/c2000/C2000Ware_5_01_00_00/device_support/f2833x/common/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="Module/Src/$(basename $(<F)).d_raw" --obj_directory="Module/Src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


