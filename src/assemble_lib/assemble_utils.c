#include <stdlib.h>
#include <stdio.h>
#include "definitions.h"

void write_file(uint32_t *instr_array, char *save_name) {
  FILE *file = fopen(save_name, "wb");

  for (int i = 0; i < sizeof(instr_array); i++) {
    fwrite(&instr_array[i], INSTR_SIZE, 1, file);
  }

  fclose(file);
}