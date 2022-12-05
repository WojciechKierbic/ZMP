__start__: obj __lines_for_space__ interp __plugin__
	export LD_LIBRARY_PATH="./libs"; ./interp ./opis_dzialan/opis_dzialan.cmd

obj:
	mkdir obj


__lines_for_space__:
	@echo
	@echo
	@echo
	@echo
	@echo


__plugin__:
	cd plugin; make

CPPFLAGS=-Wall -pedantic -std=c++17 -Iinc
LDFLAGS=-Wall




interp: obj/main.o obj/Set4Libinterfaces.o obj/Scene.o obj/Libinterface.o obj/Reader.o obj/Sender.o obj/xmlinterp.o
	g++ ${LDFLAGS} -o interp  obj/main.o obj/Set4Libinterfaces.o obj/Scene.o obj/Libinterface.o obj/Reader.o obj/Sender.o obj/xmlinterp.o  -ldl -lxerces-c -lpthread

obj/main.o: src/main.cpp inc/Interp4Command.hh 
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/xmlinterp.o: src/xmlinterp.cpp inc/xmlinterp.hh inc/Configuration.hh 
	g++ -c ${CPPFLAGS} -o obj/xmlinterp.o src/xmlinterp.cpp	
	
obj/Set4Libinterfaces.o: src/Set4Libinterfaces.cpp inc/Set4Libinterfaces.hh  inc/Libinterface.hh inc/Interp4Command.hh
	g++ -c ${CPPFLAGS} -o obj/Set4Libinterfaces.o src/Set4Libinterfaces.cpp

obj/Scene.o: src/main.cpp inc/Scene.hh inc/MobileObj.hh inc/AccessControl.hh inc/Vector3D.hh
	g++ -c ${CPPFLAGS} -o obj/Scene.o src/Scene.cpp

obj/Libinterface.o: src/Libinterface.cpp inc/Libinterface.hh inc/Interp4Command.hh
	g++ -c ${CPPFLAGS} -o obj/Libinterface.o src/Libinterface.cpp

obj/Reader.o: src/Reader.cpp inc/Reader.hh inc/xmlinterp.hh inc/Configuration.hh 
	g++ -c ${CPPFLAGS} -o obj/Reader.o src/Reader.cpp 

obj/Sender.o: src/Sender.cpp inc/Sender.hh inc/Scene.hh inc/Port.hh 
	g++ -c ${CPPFLAGS} -o obj/Sender.o src/Sender.cpp	



clean:
	rm -f obj/* interp core*


clean_plugin:
	cd plugin; make clean

cleanall: clean
	cd plugin; make cleanall
	cd dox; make cleanall
	rm -f libs/*
	find . -name \*~ -print -exec rm {} \;

help:
	@echo
	@echo "  Lista podcelow dla polecenia make"
	@echo 
	@echo "        - (wywolanie bez specyfikacji celu) wymusza"
	@echo "          kompilacje i uruchomienie programu."
	@echo "  clean    - usuwa produkty kompilacji oraz program"
	@echo "  clean_plugin - usuwa plugin"
	@echo "  cleanall - wykonuje wszystkie operacje dla podcelu clean oraz clean_plugin"
	@echo "             oprocz tego usuwa wszystkie kopie (pliki, ktorych nazwa "
	@echo "             konczy sie znakiem ~)."
	@echo "  help  - wyswietla niniejszy komunikat"
	@echo
	@echo " Przykladowe wywolania dla poszczegolnych wariantow. "
	@echo "  make           # kompilacja i uruchomienie programu."
	@echo "  make clean     # usuwa produkty kompilacji."
	@echo
 
