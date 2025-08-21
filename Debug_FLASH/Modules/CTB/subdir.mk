################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modules/CTB/CTB.c \
../Modules/CTB/CTBCbit.c \
../Modules/CTB/CTBPbit.c \
../Modules/CTB/CTBio.c 

OBJS += \
./Modules/CTB/CTB.o \
./Modules/CTB/CTBCbit.o \
./Modules/CTB/CTBPbit.o \
./Modules/CTB/CTBio.o 

C_DEPS += \
./Modules/CTB/CTB.d \
./Modules/CTB/CTBCbit.d \
./Modules/CTB/CTBPbit.d \
./Modules/CTB/CTBio.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/CTB/%.o: ../Modules/CTB/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Modules/CTB/CTB.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


