isomer: isomer.cc file.cc file.h editor.cc editor.h
	$(CXX) isomer.cc file.cc editor.cc -o isomer -Wall -Wextra -pedantic
