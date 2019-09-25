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
	${OBJECTDIR}/include/drawgroup.o \
	${OBJECTDIR}/src/AssetManager.o \
	${OBJECTDIR}/src/BaseScene.o \
	${OBJECTDIR}/src/ChunkSound.o \
	${OBJECTDIR}/src/DrawableTexture.o \
	${OBJECTDIR}/src/FontSurface.o \
	${OBJECTDIR}/src/ManagedScene.o \
	${OBJECTDIR}/src/SceneManager.o \
	${OBJECTDIR}/src/SurfaceMaker.o \
	${OBJECTDIR}/src/app/AppClass.o \
	${OBJECTDIR}/src/drawable.o \
	${OBJECTDIR}/src/entities/entity.o \
	${OBJECTDIR}/src/entities/player/bob.o \
	${OBJECTDIR}/src/entities/projectiles.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/menuoptions.o \
	${OBJECTDIR}/src/painter.o \
	${OBJECTDIR}/src/scene/BackgroundScene.o \
	${OBJECTDIR}/src/scene/menuscene.o \
	${OBJECTDIR}/src/scene/proofofconcept/scene.o


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
LDLIBSOPTIONS=`pkg-config --libs SDL2_ttf` `pkg-config --libs SDL2_image` `pkg-config --libs sdl2` `pkg-config --libs SDL2_mixer`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppsdl1

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppsdl1: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppsdl1 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/include/drawgroup.o: include/drawgroup.cpp
	${MKDIR} -p ${OBJECTDIR}/include
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/drawgroup.o include/drawgroup.cpp

${OBJECTDIR}/src/AssetManager.o: src/AssetManager.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/AssetManager.o src/AssetManager.cpp

${OBJECTDIR}/src/BaseScene.o: src/BaseScene.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/BaseScene.o src/BaseScene.cpp

${OBJECTDIR}/src/ChunkSound.o: src/ChunkSound.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ChunkSound.o src/ChunkSound.cpp

${OBJECTDIR}/src/DrawableTexture.o: src/DrawableTexture.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/DrawableTexture.o src/DrawableTexture.cpp

${OBJECTDIR}/src/FontSurface.o: src/FontSurface.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/FontSurface.o src/FontSurface.cpp

${OBJECTDIR}/src/ManagedScene.o: src/ManagedScene.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ManagedScene.o src/ManagedScene.cpp

${OBJECTDIR}/src/SceneManager.o: src/SceneManager.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SceneManager.o src/SceneManager.cpp

${OBJECTDIR}/src/SurfaceMaker.o: src/SurfaceMaker.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SurfaceMaker.o src/SurfaceMaker.cpp

${OBJECTDIR}/src/app/AppClass.o: src/app/AppClass.cpp
	${MKDIR} -p ${OBJECTDIR}/src/app
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/app/AppClass.o src/app/AppClass.cpp

${OBJECTDIR}/src/drawable.o: src/drawable.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/drawable.o src/drawable.cpp

${OBJECTDIR}/src/entities/entity.o: src/entities/entity.cpp
	${MKDIR} -p ${OBJECTDIR}/src/entities
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/entities/entity.o src/entities/entity.cpp

${OBJECTDIR}/src/entities/player/bob.o: src/entities/player/bob.cpp
	${MKDIR} -p ${OBJECTDIR}/src/entities/player
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/entities/player/bob.o src/entities/player/bob.cpp

${OBJECTDIR}/src/entities/projectiles.o: src/entities/projectiles.cpp
	${MKDIR} -p ${OBJECTDIR}/src/entities
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/entities/projectiles.o src/entities/projectiles.cpp

${OBJECTDIR}/src/main.o: src/main.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/menuoptions.o: src/menuoptions.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/menuoptions.o src/menuoptions.cpp

${OBJECTDIR}/src/painter.o: src/painter.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/painter.o src/painter.cpp

${OBJECTDIR}/src/scene/BackgroundScene.o: src/scene/BackgroundScene.cpp
	${MKDIR} -p ${OBJECTDIR}/src/scene
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/scene/BackgroundScene.o src/scene/BackgroundScene.cpp

${OBJECTDIR}/src/scene/menuscene.o: src/scene/menuscene.cpp
	${MKDIR} -p ${OBJECTDIR}/src/scene
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/scene/menuscene.o src/scene/menuscene.cpp

${OBJECTDIR}/src/scene/proofofconcept/scene.o: src/scene/proofofconcept/scene.cpp
	${MKDIR} -p ${OBJECTDIR}/src/scene/proofofconcept
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude/ `pkg-config --cflags SDL2_ttf` `pkg-config --cflags SDL2_image` `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/scene/proofofconcept/scene.o src/scene/proofofconcept/scene.cpp

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
