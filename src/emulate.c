#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "emulate.h"
#include "emulate_utils.h"

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Please provide only 1 argument\n");
		return EXIT_FAILURE;
	}
	char *file = argv[1];

	// Create variable and set it to return of init_state,
	// initialise based on the spec (use malloc)
	// Anything thats a pointer needs to mallocated (start_state needs to be
	// mallocated)
	
	arm11_state_t *start_state = init_state();

	read_file(file, start_state);
  
  // TODO: Remove i and set condition to check if execute is HALT
  int i = 0;
  while (i < 100) {
    // Execute an instruction
    if (start_state->pipeline->executed != 0) {
      // execute()
      free(start_state->pipeline->executed);
    }

    // Decode an instruction
    if (start_state->pipeline->decoded != 0) {
      // decode()
    }
    start_state->pipeline->executed = start_state->pipeline->decoded;
    start_state->pipeline->decoded = start_state->pipeline->fetched;

    // Fetch an instruction
    fetch_next(start_state);

    // Increment the PC
    start_state->register_file[15] += 4;
    i++;
  }


  // Once everything is done, free state memory and pipeline
  free_all_pipeline(start_state->pipeline);
  free_state_memory(start_state);
}
