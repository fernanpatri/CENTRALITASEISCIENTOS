################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/sensores/calibracion/calibracion.c 

OBJS += \
./Core/Src/sensores/calibracion/calibracion.o 

C_DEPS += \
./Core/Src/sensores/calibracion/calibracion.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/sensores/calibracion/%.o Core/Src/sensores/calibracion/%.su Core/Src/sensores/calibracion/%.cyclo: ../Core/Src/sensores/calibracion/%.c Core/Src/sensores/calibracion/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-sensores-2f-calibracion

clean-Core-2f-Src-2f-sensores-2f-calibracion:
	-$(RM) ./Core/Src/sensores/calibracion/calibracion.cyclo ./Core/Src/sensores/calibracion/calibracion.d ./Core/Src/sensores/calibracion/calibracion.o ./Core/Src/sensores/calibracion/calibracion.su

.PHONY: clean-Core-2f-Src-2f-sensores-2f-calibracion

