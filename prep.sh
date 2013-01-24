#!/bin/bash
#TARGET="apple2"
TARGET=$1
echo "
# this configuration is used to build C code and makefiles for the oo2c
# distribution

OPTIONS
  verbose := FALSE;
  errorMessages := \"oo2c_32-1.5.9/Errors.short\";
  optimize := TRUE;

  cc := \"cl65 -t $TARGET\";
  cflags := \"-Os\";
  coptflags := \"\";
  ldflags := \"\";
  gcflags := \"\";
  valueStack := -1;
END

PRAGMAS
  Warnings := TRUE;
  Assertions := TRUE;
  Initialize := FALSE;
  PoisonHeap := -1;
  StackCheck := FALSE;
  ConformantMode := FALSE;

  CaseSelectCheck := TRUE;
  IndexCheck := FALSE;
  RangeCheck := FALSE;
  DerefCheck := FALSE;
  FunctResult := FALSE;
  TypeGuard := FALSE;
  OverflowCheck := FALSE;
  IntDivCheck := FALSE;
  RealOverflowCheck := FALSE;
  RealDivCheck := FALSE;

  TARGET_OS := \"$TARGET\";
  TARGET_INTEGER := 32;
  TARGET_BYTE_ORDER := \"1234\";
END

PATHS
GET *.Mod [RCS] FROM
  .;
  minilib;
  src;
GET *.Sym, *.Lib FROM 
  obj/$TARGET;
GET *.h, *.d, *.c FROM
  obj/$TARGET;
  minilib;
  minilib/$TARGET;
GET *.o FROM
  obj/$TARGET
END

NEWFILES
  PUT * INTO  obj/$TARGET;
END
" > oo2crc.target.$TARGET

echo ""
