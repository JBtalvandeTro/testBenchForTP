################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modules/CNV/CNV.c 

OBJS += \
./Modules/CNV/CNV.o 

C_DEPS += \
./Modules/CNV/CNV.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/CNV/%.o: ../Modules/CNV/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Modules/CNV/CNV.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


