################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/FLA/FLA.c 

OBJS += \
./Middlewares/FLA/FLA.o 

C_DEPS += \
./Middlewares/FLA/FLA.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/FLA/%.o: ../Middlewares/FLA/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Middlewares/FLA/FLA.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


