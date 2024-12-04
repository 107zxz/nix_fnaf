#include <stdio.h>
#include "../src/w_world.h"
#include "../src/w_rng.h"

int main() {

    W_Cave cave = w_cave_make(
        1,
        w_cave_section_make(
            W_Cave_Section_Type_DANGEROUS,
            2,
            w_cave_resource_make(
                32,
                W_Cave_Resource_Copper
            ),
            w_cave_resource_make(
                1,
                W_Cave_Resource_Copper
            )
        )
    );

    w_cave_print(cave);

    w_cave_free(cave);
}