#include "minesweeper.h"

int main(int argc, char *argv[]){
	
	//Map mapSrc = generateMap();
	if(argc > 1){
		std::string arg = argv[1];
		if(arg == "-h" || arg == "--help"){
			//showHelp();
		}
	}
	if(argc > 2){
		std::string arg = argv[1];
		std::string arg2 = argv[2];
		if(arg == "-d" || arg == "--difficulty"){
			if(arg2 == "b" || arg2 == "beginner"){
				
			}
			else if(arg2 == "i" || arg2 == "intermediary"){
				
			}
			else if(arg2 == "a" || arg2 == "advanced"){
				
			}
		}
		
	}
	return 0;
}