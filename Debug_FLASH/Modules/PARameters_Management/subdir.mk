################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modules/PARameters_Management/PAR.c \
../Modules/PARameters_Management/PARcheck.c \
../Modules/PARameters_Management/PARconfig.c \
../Modules/PARameters_Management/PARupdat.c 

OBJS += \
./Modules/PARameters_Management/PAR.o \
./Modules/PARameters_Management/PARcheck.o \
./Modules/PARameters_Management/PARconfig.o \
./Modules/PARameters_Management/PARupdat.o 

C_DEPS += \
./Modules/PARameters_Management/PAR.d \
./Modules/PARameters_Management/PARcheck.d \
./Modules/PARameters_Management/PARconfig.d \
./Modules/PARameters_Management/PARupdat.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/PARameters_Management/%.o: ../Modules/PARameters_Management/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Modules/PARameters_Management/PAR.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


