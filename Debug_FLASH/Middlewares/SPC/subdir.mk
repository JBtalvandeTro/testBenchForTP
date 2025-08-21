################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/SPC/SPC.c 

OBJS += \
./Middlewares/SPC/SPC.o 

C_DEPS += \
./Middlewares/SPC/SPC.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/SPC/%.o: ../Middlewares/SPC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Middlewares/SPC/SPC.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


