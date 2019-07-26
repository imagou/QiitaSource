#!/bin/bash

if [ $# -ne 2 ]; then
  echo "Usage: $0 ProjectDir BuildName"
  exit 1;
fi

ProjectName=`basename $1`

# Build Elf
/opt/st/stm32cubeide_1.0.2/headless-build.sh -cleanBuild $ProjectName/$2 -importAll $1

# Cleate Binary
#DateTime=`date +%y%m%d%H%M%S`
DateTime=`date +%y%m%d`
BinaryName=${DateTime}_${ProjectName}.bin
echo "Cleate Binary (${BinaryName})"
arm-none-eabi-objcopy -O binary $1/$2/${ProjectName}.elf $BinaryName

exit 0

