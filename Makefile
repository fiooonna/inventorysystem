updateinfo.o:updateinfo.cpp datastructure.h
	g++ -c $<
updatestatus.o:updatestatus.cpp datastructure.h
	g++ -c $<
procurement.o:procurement.cpp updatestatus.cpp  datastructure.h
	g++ -c $<
main.o:main.cpp updateinfo.cpp updatestatus.cpp procurement.cpp
	g++ -c $<
alert.o: alert.cpp datastructure.h
	g++ -c $<
pos.o: pos.cpp datastructure.h
	g++ -c $<
deleteitem.o: deleteitem.cpp datastructure.h
	g++ -c $<
view_record.o: view_record.cpp getinfo.cpp datastructure.h
	g++ -c $<
getinfo.o:getinfo.cpp datastructure.h
	g++ -c $<
view_search.o: view_search.cpp sorting.cpp datastructure.h
	g++ -c $<
sorting.o: sorting.cpp datastructure.h
	g++ -c $<
build:main.o updateinfo.o updatestatus.o procurement.o alert.o pos.o deleteitem.o view_record.o getinfo.o view_search.o sorting.o
	g++ $^ -o $@
clean:
	rm main.o updateinfo.o updatestatus.o procurement.o build alert.o pos.o deleteitem.o view_record.o getinfo.o view_search.o sorting.o
