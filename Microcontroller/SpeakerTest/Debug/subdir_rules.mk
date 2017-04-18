################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-38813361:
	@$(MAKE) -Onone -f subdir_rules.mk build-38813361-inproc

build-38813361-inproc: ../SpeakerTest.ino
	@echo 'Building file: $<'
	@echo 'Invoking: Resource Custom Build Step'
	
	@echo 'Finished building: $<'
	@echo ' '

SpeakerTest.cpp: build-38813361 ../SpeakerTest.ino
main.cpp: build-38813361

%.o: ./%.cpp $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Compiler'
	"C:/Users/cdgja/AppData/Local/Energia15/packages/energia/tools/arm-none-eabi-gcc/4.8.4-20140725/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fno-exceptions -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_target_name__=M4F -Dxdc_cfg__xheader__=\"configPkg/package/cfg/energia_pm4fg.h\" -DTARGET_IS_MSP432P4XX -DBOARD_MSP_EXP432P401R -Dxdc__nolocalstring=1 -D__MSP432P401R__ -DCORE_VERSION=380 -DF_CPU=48000000L -DENERGIA_MSP_EXP432P401R -DENERGIA_ARCH_MSP432 -DENERGIA=18 -DARDUINO=10610 -I"C:/Users/cdgja/AppData/Local/Energia15/packages/energia/hardware/msp432/3.8.0/cores/msp432/ti/runtime/wiring/" -I"C:/Users/cdgja/AppData/Local/Energia15/packages/energia/hardware/msp432/3.8.0/cores/msp432/ti/runtime/wiring/msp432" -I"C:/Users/cdgja/AppData/Local/Energia15/packages/energia/hardware/msp432/3.8.0" -I"C:/Users/cdgja/AppData/Local/Energia15/packages/energia/hardware/msp432/3.8.0/system/driverlib/MSP432P4xx" -I"C:/Users/cdgja/AppData/Local/Energia15/packages/energia/hardware/msp432/3.8.0/system/driverlib" -I"C:/Users/cdgja/AppData/Local/Energia15/packages/energia/hardware/msp432/3.8.0/system/inc" -I"C:/Users/cdgja/AppData/Local/Energia15/packages/energia/hardware/msp432/3.8.0/system/inc/CMSIS/" -I"C:/Users/cdgja/AppData/Local/Energia15/packages/energia/hardware/msp432/3.8.0/system" -I"C:/Users/cdgja/AppData/Local/Energia15/packages/energia/hardware/msp432/3.8.0/cores/msp432" -I"C:/Users/cdgja/AppData/Local/Energia15/packages/energia/hardware/msp432/3.8.0/variants/MSP_EXP432P401R" -I"C:/Users/cdgja/Documents/University of Pittsburgh/COE 1188 Cyber Physical Systems/BopIt/Microcontroller/SpeakerTest" -I"C:/Users/cdgja/AppData/Local/Energia15/packages/energia/tools/arm-none-eabi-gcc/4.8.4-20140725/arm-none-eabi/include" -Os -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -w -Wall -mabi=aapcs -fno-threadsafe-statics -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -fno-rtti -o"$@" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


