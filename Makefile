#adapted from canvas lecture: https://oregonstate.instructure.com/courses/1719543/pages/lecture-makefiles?module_item_id=18712398

#Kirsten Carter - cs162-400 Spring 2019 OreSU

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g #debugging
CXXFLAGS += -Wall #warnings
CXXFLAGS += -pedantic-errors

LDFLAGS = -lboost_date_time 
#haven't used the above yet, included for reference

#names of the .o files go here 

OBJS = charText.o Courtyard.o DracoMalfoy.o EntranceHall.o ForbiddenForest.o Game.o HagridHut.o HarryPotter.o HermioneGrainger.o HospitalWing.o itemsHelper.o Menu.o Path.o People.o PumpkinPatch.o Space.o main.o


#names of source files go here, all of them
SRCS = charText.cpp Courtyard.cpp DracoMalfoy.cpp EntranceHall.cpp ForbiddenForest.cpp Game.cpp HagridHut.cpp HarryPotter.cpp HermioneGrainger.cpp HospitalWing.cpp itemsHelper.cpp Menu.cpp Path.cpp People.cpp PumpkinPatch.cpp Space.cpp main.cpp


#Headers for the source files go here
HEADERS = charText.hpp Courtyard.hpp DracoMalfoy.hpp EntranceHall.hpp ForbiddenForest.hpp Game.hpp HagridHut.hpp HarryPotter.hpp HermioneGrainger.hpp HospitalWing.hpp itemsHelper.hpp Menu.hpp Path.hpp People.hpp PumpkinPatch.hpp Space.hpp


play: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o play
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

zip:
	zip FinalProject_Carter_Kirsten.zip *.cpp *.hpp Makefile FinalProject-Reflection_Carter_Kirsten.pdf FinalProject-TestRubric_Carter_Kirsten.xlsx

clean:
	rm *.o play

#Adapted from cs162 lecture on Makefiles https://oregonstate.instructure.com/courses/1719543/pages/lecture-makefiles?module_item_id=18712398


#GENERAL FORM

#target: dependencies
#	rule to build
