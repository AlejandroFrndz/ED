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
	${OBJECTDIR}/src/ingrediente.o \
	${OBJECTDIR}/src/ingredientes.o \
	${OBJECTDIR}/src/nutricion_receta.o \
	${OBJECTDIR}/src/receta.o \
	${OBJECTDIR}/src/recetas.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pr_ctica_3

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pr_ctica_3: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pr_ctica_3 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/ingrediente.o: src/ingrediente.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ingrediente.o src/ingrediente.cpp

${OBJECTDIR}/src/ingredientes.o: src/ingredientes.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ingredientes.o src/ingredientes.cpp

${OBJECTDIR}/src/nutricion_receta.o: src/nutricion_receta.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/nutricion_receta.o src/nutricion_receta.cpp

${OBJECTDIR}/src/receta.o: src/receta.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/receta.o src/receta.cpp

${OBJECTDIR}/src/recetas.o: src/recetas.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/recetas.o src/recetas.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
