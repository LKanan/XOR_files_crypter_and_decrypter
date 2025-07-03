QT = `pkg-config --cflags --libs Qt5Widgets`
CXX = g++
CXXFLAGS = -std=c++11 -Wall -fPIC

SRC_VIEW = ./view/mainwindow.cpp
SRC_MODEL = ./model/cryptomodel.cpp
SRC_CONTROLLER = ./controller/main.cpp
HEADERS = ./view/mainwindow.h ./model/cryptomodel.h
UI = ./view/mainwindow.ui
MOC = ./view/moc_mainwindow.cpp
UIC = ./view/ui_mainwindow.h

run: all
	./app

all: $(UIC) $(MOC) app

$(UIC): $(UI)
	uic $(UI) -o view/ui_mainwindow.h

$(MOC): view/mainwindow.h
	moc view/mainwindow.h -o view/moc_mainwindow.cpp

app: $(SRC_CONTROLLER) $(SRC_VIEW) $(SRC_MODEL) $(UIC) $(MOC)
	$(CXX) $(CXXFLAGS) $(SRC_CONTROLLER) $(SRC_VIEW) $(SRC_MODEL) view/moc_mainwindow.cpp -o app $(QT)

# clean:
# 	rm -f app view/moc_mainwindow.cpp view/ui_mainwindow.h
