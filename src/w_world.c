#include "w_world.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

W_Cave w_cave_make(
    int n_sections,
    ...
) {

    va_list valist;

    W_Cave_Section* sections = malloc(sizeof(W_Cave_Section) * n_sections);

    va_start(valist, n_sections);
    for (int s = 0; s < n_sections; s++) {
        sections[s] = va_arg(valist, W_Cave_Section);
    }
    va_end(valist);

    return (W_Cave) {
        n_sections,
        sections
    };
}

void w_cave_free(W_Cave cave)
{
    for (int s = 0; s < cave.n_sections; s++) w_cave_section_free(cave.sections[s]);
}

void w_cave_print(W_Cave cave)
{
    printf("- Cave with sections:\n");

    for (int s = 0; s < cave.n_sections; s++) w_cave_section_print(cave.sections[s]);
}

W_Cave_Section w_cave_section_make(
    W_Cave_Section_Type type,
    int n_resources,
    ...
) {

    va_list valist;

    W_Cave_Resource* resources = malloc(sizeof(W_Cave_Resource) * n_resources);

    va_start(valist, n_resources);
    for (int r = 0; r < n_resources; r++) {
        resources[r] = va_arg(valist, W_Cave_Resource);
    }
    va_end(valist);

    return (W_Cave_Section) {
        type,
        n_resources,
        resources
    };
}

void w_cave_section_free(W_Cave_Section section)
{
    free(section.resources);
}

void w_cave_section_print(W_Cave_Section section)
{
    switch (section.type) {
        case W_Cave_Section_Type_SAFE:
            printf("-- Safe");
            break;
        case W_Cave_Section_Type_DANGEROUS:
            printf("-- Dangerous");
            break;
    }

    printf(" section with resources:\n");

    for (int r = 0; r < section.n_resources; r++) {
        printf("--- %dx ", section.resources[r].amount);

        switch (section.resources[r].type) {
            case W_Cave_Resource_Copper:
                printf("Copper\n");
                break;
        }
    }
}

W_Cave_Resource w_cave_resource_make(int amount, W_Cave_Resource_Type type) {
    return (W_Cave_Resource) {
        type,
        amount
    };
}
