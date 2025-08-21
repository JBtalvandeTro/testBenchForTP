################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include generate/src/subdir.mk
-include generate/IntCtrl_Ip/subdir.mk
-include board/subdir.mk
-include SCHeduler/subdir.mk
-include RTD/src/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include Modules/PWB/subdir.mk
-include Modules/PARameters_Management/subdir.mk
-include Modules/MPM/subdir.mk
-include Modules/FSM/subdir.mk
-include Modules/DBG/subdir.mk
-include Modules/CTB/subdir.mk
-include Modules/COM_Management/subdir.mk
-include Modules/CNV/subdir.mk
-include Modules/ACTivity_Management/subdir.mk
-include Middlewares/WDO_Management/subdir.mk
-include Middlewares/SPC/subdir.mk
-include Middlewares/FLA/subdir.mk
-include Middlewares/CAN/subdir.mk
-include INI/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
TRO_50147DC333_SW001.hex \

SECONDARY_SIZE += \
TRO_50147DC333_SW001.siz \


# All Target
all: TRO_50147DC333_SW001.elf secondary-outputs

# Tool invocations
TRO_50147DC333_SW001.elf: $(OBJS) C:/Users/jbtalvande/Documents/Tronico/Team-Power/01_Projet/02_MTU/02-Code/01_MCU/50073-50147DC333-SW001/trunk/Project_Settings/Linker_Files/linker_flash_s32k148_debug.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "TRO_50147DC333_SW001.elf" "@TRO_50147DC333_SW001.args"  $(USER_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

TRO_50147DC333_SW001.hex: TRO_50147DC333_SW001.elf
	@echo 'Invoking: Standard S32DS Create Flash Image'
	arm-none-eabi-objcopy -O ihex TRO_50147DC333_SW001.elf  "TRO_50147DC333_SW001.hex"
	@echo 'Finished building: $@'
	@echo ' '

TRO_50147DC333_SW001.siz: TRO_50147DC333_SW001.elf
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley TRO_50147DC333_SW001.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
