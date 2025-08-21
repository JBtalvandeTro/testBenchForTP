################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modules/MPM/MPM.c 

OBJS += \
./Modules/MPM/MPM.o 

C_DEPS += \
./Modules/MPM/MPM.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/MPM/%.o: ../Modules/MPM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Modules/MPM/MPM.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


