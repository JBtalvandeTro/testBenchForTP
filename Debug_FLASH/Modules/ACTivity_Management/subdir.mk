################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modules/ACTivity_Management/ACT.c \
../Modules/ACTivity_Management/ACTupdat.c 

OBJS += \
./Modules/ACTivity_Management/ACT.o \
./Modules/ACTivity_Management/ACTupdat.o 

C_DEPS += \
./Modules/ACTivity_Management/ACT.d \
./Modules/ACTivity_Management/ACTupdat.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/ACTivity_Management/%.o: ../Modules/ACTivity_Management/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Modules/ACTivity_Management/ACT.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


