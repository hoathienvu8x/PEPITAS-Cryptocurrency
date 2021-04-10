#include "gen/GEN_validators_file.c"
#include "core/validation/validations.h"
#include "tests_macros.h"

void validations_test()
{
    gen_validators_file("validators.state");

    size_t nb_validators;
    if (get_next_committee(&nb_validators) != NULL && nb_validators != 0)
    {
        TEST_PASSED("Getting next validators");
    }
    else
    {
        TEST_FAILED("Getting next validators", "get_next_validators() returned NULL (error) or nb_validators == 0");
    }
}