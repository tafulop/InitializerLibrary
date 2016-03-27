#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/InitializationManager.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/InitializerTest.o \
	${TESTDIR}/tests/InitializerTestRunner.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libinitializerlibrary.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libinitializerlibrary.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libinitializerlibrary.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libinitializerlibrary.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libinitializerlibrary.a

${OBJECTDIR}/InitializationManager.o: InitializationManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -include /mnt/seagate_1TB/Development/Robotkar_reboot/PartContainerLibrary/PartContainerManager.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/InitializationManager.o InitializationManager.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:
	cd /mnt/seagate_1TB/Development/Robotkar_reboot/PartContainerLibrary && ${MAKE}  -f Makefile CONF=Debug
	cd /mnt/seagate_1TB/Development/Robotkar_reboot/RoboticArmPartLibrary && ${MAKE}  -f Makefile CONF=Debug

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/InitializerTest.o ${TESTDIR}/tests/InitializerTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} /mnt/seagate_1TB/Development/Robotkar_reboot/PartContainerLibrary/dist/Debug/GNU-Linux/libpartcontainerlibrary.a /mnt/seagate_1TB/Development/Robotkar_reboot/RoboticArmPartLibrary/dist/Debug/GNU-Linux/libroboticarmpartlibrary.a `cppunit-config --libs`   


${TESTDIR}/tests/InitializerTest.o: tests/InitializerTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -include /mnt/seagate_1TB/Development/Robotkar_reboot/PartContainerLibrary/PartContainerManager.h -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/InitializerTest.o tests/InitializerTest.cpp


${TESTDIR}/tests/InitializerTestRunner.o: tests/InitializerTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -include /mnt/seagate_1TB/Development/Robotkar_reboot/PartContainerLibrary/PartContainerManager.h -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/InitializerTestRunner.o tests/InitializerTestRunner.cpp


${OBJECTDIR}/InitializationManager_nomain.o: ${OBJECTDIR}/InitializationManager.o InitializationManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/InitializationManager.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -include /mnt/seagate_1TB/Development/Robotkar_reboot/PartContainerLibrary/PartContainerManager.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/InitializationManager_nomain.o InitializationManager.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/InitializationManager.o ${OBJECTDIR}/InitializationManager_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libinitializerlibrary.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
