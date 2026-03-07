################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/sensores/sensores.c 

OBJS += \
./Core/Src/sensores/sensores.o 

C_DEPS += \
./Core/Src/sensores/sensores.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/sensores/%.o Core/Src/sensores/%.su Core/Src/sensores/%.cyclo: ../Core/Src/sensores/%.c Core/Src/sensores/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-sensores

clean-Core-2f-Src-2f-sensores:
	-$(RM) ./Core/Src/sensores/sensores.cyclo ./Core/Src/sensores/sensores.d ./Core/Src/sensores/sensores.o ./Core/Src/sensores/sensores.su

.PHONY: clean-Core-2f-Src-2f-sensores

