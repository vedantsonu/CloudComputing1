################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application.cpp \
../EmulNet.cpp \
../Log.cpp \
../MP1Node.cpp \
../Member.cpp \
../Params.cpp 

OBJS += \
./Application.o \
./EmulNet.o \
./Log.o \
./MP1Node.o \
./Member.o \
./Params.o 

CPP_DEPS += \
./Application.d \
./EmulNet.d \
./Log.d \
./MP1Node.d \
./Member.d \
./Params.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


