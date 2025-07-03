QT = `pkg-config --cflags --libs Qt5Widgets`
CXX = g++
CXXFLAGS = -std=c++11 -Wall -fPIC
SOURCES = main.cpp mainwindow.cpp
HEADERS = mainwindow.h
UI = mainwindow.ui
MOC = moc_mainwindow.cpp
UIC = ui_mainwindow.h

all: $(UIC) $(MOC) app

$(UIC): $(UI)
	uic $(UI) -o ui_mainwindow.h

$(MOC): mainwindow.h
	moc mainwindow.h -o moc_mainwindow.cpp

app: main.cpp mainwindow.cpp $(UIC) $(MOC)
	$(CXX) $(CXXFLAGS) main.cpp mainwindow.cpp moc_mainwindow.cpp -o app $(QT)

run: all
	./app

# clean:
# 	rm -f app moc_mainwindow.cpp ui_mainwindow.h
