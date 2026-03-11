################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/control/rpm.c 

OBJS += \
./Core/Src/control/rpm.o 

C_DEPS += \
./Core/Src/control/rpm.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/control/%.o Core/Src/control/%.su Core/Src/control/%.cyclo: ../Core/Src/control/%.c Core/Src/control/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-control

clean-Core-2f-Src-2f-control:
	-$(RM) ./Core/Src/control/rpm.cyclo ./Core/Src/control/rpm.d ./Core/Src/control/rpm.o ./Core/Src/control/rpm.su

.PHONY: clean-Core-2f-Src-2f-control

