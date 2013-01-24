#!/bin/bash
OOCORIGINAL="oo2c_32-1.5.9"
PATCH="avr-oo2c-patch.diff"
OOCBINARY="oo2c"
PREFIX="/usr/local/nmos6502-oo2c"
TARGET="atmos"
VERSION="0.1"
# build cross compiler for 8 bit platform
#tar jxvf $OOCORIGINAL.tar.bz2
#cp $PATCH $OOCORIGINAL
#cd  $OOCORIGINAL
#./configure --disable-libs --disable-gc
#patch -p1 < $PATCH
#make oo2crc.stage1
#make lib/__gc.h
#$OOCBINARY --config oo2crc.stage1 -Mv oo2c
#install crosscompiler
#mkdir $PREFIX
#cp stage1/oo2c $PREFIX/nmos6502-oo2c
#cd ..
mkdir obj
TARGETS="atmos apple2 atari c16 c64 c128 cbm510 cbm610 plus4 pet nes geos lunix"
for TARGET in $TARGETS
do
# oric-oo2c, apple2-oo2, script
echo "#!/bin/bash" >$TARGET-oo2c
echo "#this is a wrapper script to run compiler" >> $TARGET-oo2c
echo "#to compile hello.Mod run $PREFIX/$TARGET-oo2c hello" >> $TARGET-oo2c
echo "#this cript is automatically generated by build.sh" >> $TARGET-oo2c
echo "$PREFIX/nmos6502-oo2c --config $PREFIX/oo2crc.target.$TARGET -Mv \$1" >> $TARGET-oo2c
chmod 777 $TARGET-oo2c
./prep.sh $TARGET
cp $TARGET-oo2c $PREFIX
# building oric libraries
mkdir obj/$TARGET
#cl65 -t atmos -Os -Iobj/oric -Iminilib -Iminilib/oric -c minilib/__oo2c.c -o obj/oric/__oo2c.o
# oric specific
#cl65 -t atmos -Os -Iobj/oric -Iminilib -Iminilib/oric -c minilib/oric/Terminal.c -o obj/oric/Terminal.o
$PREFIX/nmos6502-oo2c --config oo2crc.target.$TARGET -Mv hello.Mod
# cl65 bug workaround
mv minilib/$TARGET/Terminal.o obj/$TARGET/
mv minilib/__oo2c.o obj/$TARGET
# rest of the libraries
$PREFIX/nmos6502-oo2c --config oo2crc.target.$TARGET -Mv hello.Mod
cp -a minilib $PREFIX
cp -a obj $PREFIX
cp $OOCORIGINAL/Errors.* $PREFIX
cp README LICENSE AUTHORS $PREFIX
cp ooptest.Mod hello.Mod $PREFIX
FILE=$PREFIX/oo2crc.target.$TARGET
echo "" >$FILE
echo "OPTIONS" >> $FILE
echo "  verbose := FALSE;" >> $FILE
echo "  errorMessages := \"$PREFIX/Errors.short\";" >> $FILE
echo "  optimize := TRUE;" >> $FILE
echo "" >> $FILE
echo "  cc := \"cl65 -t $TARGET\";" >> $FILE
echo "  cflags := \"-Os\";" >> $FILE
echo "  coptflags := \"\";" >>$FILE
echo "  ldflags := \"\";" >> $FILE
echo "  gcflags := \"\";" >> $FILE
echo "  valueStack := -1;" >> $FILE
echo "END" >> $FILE
echo "" >> $FILE
echo "PRAGMAS" >> $FILE
echo "  Warnings := TRUE;" >> $FILE
echo "  Assertions := TRUE;" >> $FILE
echo "  Initialize := FALSE;" >> $FILE
echo "  PoisonHeap := -1;" >> $FILE
echo "  StackCheck := FALSE;" >> $FILE
echo "  ConformantMode := FALSE;" >> $FILE
echo "" >> $FILE
echo "  CaseSelectCheck := TRUE;" >> $FILE
echo "  IndexCheck := FALSE;" >> $FILE
echo "  RangeCheck := FALSE;" >>$FILE
echo "  DerefCheck := FALSE;" >>$FILE
echo "  FunctResult := FALSE;" >>$FILE
echo "  TypeGuard := FALSE;" >> $FILE
echo "  OverflowCheck := FALSE;" >> $FILE
echo "  IntDivCheck := FALSE;" >>$FILE
echo "  RealOverflowCheck := FALSE;" >> $FILE
echo "  RealDivCheck := FALSE;" >> $FILE
echo " " >> $FILE
echo "  TARGET_OS := \"$TARGET\";"  >> $FILE
echo "  TARGET_INTEGER := 32;" >> $FILE
echo "  TARGET_BYTE_ORDER := \"1234\";" >> $FILE
echo "END" >> $FILE
echo " " >> $FILE
echo "PATHS" >> $FILE
echo "GET *.Mod [RCS] FROM" >> $FILE
echo "  .;" >> $FILE
echo "  $PREFIX/minilib;" >> $FILE
echo "  $PREFIX/src;" >>     $FILE
echo "GET *.Sym, *.Lib FROM " >> $FILE
echo "   .;" >> $FILE
echo "   $PREFIX/obj/$TARGET;" >> $FILE
echo "GET *.h, *.d, *.c FROM" >> $FILE
echo "  .;" >> $FILE
echo "  $PREFIX/obj/$TARGET;" >> $FILE
echo "  $PREFIX/minilib;" >> $FILE
echo "  $PREFIX/minilib/$TARGET;" >> $FILE
echo "GET *.o FROM" >> $FILE
echo "  .;" >> $FILE
echo "  $PREFIX/obj/$TARGET;" >> $FILE
echo "END" >> $FILE
echo ""     >> $FILE
echo "NEWFILES" >> $FILE
echo "  PUT * INTO  .;" >> $FILE
echo "END" >> $FILE
done
#tar -jcvpf $HOME/nmos6502-oo2c-bin-$VERSION.tar.bz2 $PREFIX
echo "to run compiler and compile hello.Mod type"
echo " $PREFIX/$TARGET-oo2c hello"
echo ""
