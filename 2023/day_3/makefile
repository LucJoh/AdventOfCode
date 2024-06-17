vim:noet

.PHONY : all
all : part_1 part_2 

part_1 : part_1.cpp
	g++ -o $@ $< 

part_2 : part_2.cpp
	g++ -o $@ $<

clean:
	rm -f part_1 part_2

help:
	@echo "$$HEADER"
	@echo "Usage: make [all|part_1|part_2|clean|help]"
	@echo ""

define HEADER
                     _         __ _ _         __
     _ __ ___   __ _| | _____ / _(_) | ___   / _| ___  _ __  
    | '_ ` _ \ / _` | |/ / _ \ |_| | |/ _ \ | |_ / _ \| '__| 
    | | | | | | (_| |   <  __/  _| | |  __/ |  _| (_) | |    
    |_| |_| |_|\__,_|_|\_\___|_| |_|_|\___| |_|  \___/|_|  
      ___  _     _
     / __|| |_ _| |_
    | (_|_   _|_   _|
     \___||_|   |_|


endef

export HEADER
