#define HEAP_SIZE 1000000
char heap [HEAP_SIZE];

#include <stdio.h>

// This can be generic with macros

typedef struct {
    char name [256];
    unsigned int age;
} Person;

typedef enum {IS_NULL, NOT_NULL} IsNull;

typedef struct 
{
    IsNull is_null;
    Person person;
} PersonRow;

#define ROW_SIZE sizeof(PersonRow)
#define MAX_ROWS HEAP_SIZE / sizeof(PersonRow)
// TODO: extract table_heap.h
// TODO: implement leaf_nodes.h
// TODO: implement b_tree
// TODO: extract to elixir-style
// Generics would be
// add_row(table_heap_config, table_heap) :: char *, allow client table to wrap
Person * add_row(unsigned int age)
{
    char * heap_ptr = heap;
    const char * last_heap_prt = heap_ptr + HEAP_SIZE - 1;
    while(heap_ptr < last_heap_prt)
    {
        PersonRow * row = (PersonRow *) heap_ptr;
        if(row->is_null == IS_NULL){
            row->is_null = NOT_NULL;
            // Temporary init here
            row->person.age = age;
            row->person.name[0] = 'L';
            row->person.name[1] = 'u';
            row->person.name[2] = 'c';
            row->person.name[3] = 'a';
            row->person.name[4] = '\0';
            return &row->person;
        }
        heap_ptr += ROW_SIZE;
    }
    // return a result instead
    return 0x00;
}

// for development use, not to be part of the main use case
void delete_row(unsigned int row_number)
{
    if(row_number >= MAX_ROWS)
    {
        return;
    }
    PersonRow * row = (PersonRow *) (row_number * ROW_SIZE + heap);
    row->is_null = IS_NULL;
}

Person * checker [50];

int main()
{
    Person * result = (Person *)0x01;
    unsigned int counter = 0;
    while(result != 0x00)
    {
        result = add_row(29);
        if(counter < 50)
        {
            checker[counter] = result;
            counter++;
        }
    }

    delete_row(2);
    add_row(20);
    for(int i = 0; i < 50; i++)
    {
        printf("%d", checker[i]->age);
    }
}