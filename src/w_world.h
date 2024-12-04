#pragma once

typedef enum W_Cave_Resource_Type {
    W_Cave_Resource_Copper
} W_Cave_Resource_Type;

typedef struct W_Cave_Resource {
    W_Cave_Resource_Type type;
    int amount;
} W_Cave_Resource;

typedef enum W_Cave_Section_Type {
    W_Cave_Section_Type_SAFE,
    W_Cave_Section_Type_DANGEROUS,
} W_Cave_Section_Type;

typedef struct W_Cave_Section {
    W_Cave_Section_Type type;
    int n_resources;
    W_Cave_Resource* resources;
} W_Cave_Section;

// A cave system to be explored.
typedef struct W_Cave {
    int n_sections;
    W_Cave_Section* sections;
} W_Cave;

W_Cave w_cave_make(int n_sections, ...);
void w_cave_free(W_Cave cave);
void w_cave_print(W_Cave cave);

W_Cave_Section w_cave_section_make(W_Cave_Section_Type type, int n_resources, ...);
void w_cave_section_free(W_Cave_Section section);
void w_cave_section_print(W_Cave_Section section);

W_Cave_Resource w_cave_resource_make(int amount, W_Cave_Resource_Type type);