################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modules/DBG/DBG.c 

OBJS += \
./Modules/DBG/DBG.o 

C_DEPS += \
./Modules/DBG/DBG.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/DBG/%.o: ../Modules/DBG/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Modules/DBG/DBG.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


