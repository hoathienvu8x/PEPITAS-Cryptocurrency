#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdint.h>

/**
 * @brief The design of a node that can be stored in the linked list. It stores
 * a line in the given file as an instr_t type or as tokens, and also stores the
 * address of that line.
 */
typedef struct node {
  void *value;
  uint32_t address;
  struct node *next;
} node;

/**
 * @brief The linked list of nodes that will contain lines of the file as
 * instr_t or as tokens.
 */
typedef struct linked_list {
  struct node *root;
  int size;
} linked_list;

/**
 * @brief Initialises a new linked list with a null root node and size of 0.
 */
linked_list *init_linked_list(void);

/**
 * @brief Adds a new node to the linked list. Generally used when the file is
 * first read and the lines of the file must be seperated into nodes as strings.
 *
 * @param list The list to which the node must be added.
 * @param val The value of the node to be appended.
 * @param addr The address of the value.
 */
void append_to_linked_list(linked_list *list, void *val, uint32_t addr);

/**
 * @brief Traverses the given linked list and returns the node at a specified
 * position.
 *
 * @param list The linked list to be traversed.
 * @param pos The position of the node that must be returned.
 *
 * @return A pointer to node at specified position 'pos'.
 */
node *traverse_linked_list(linked_list *list, int pos);

/**
 * @brief Changes the value of the node in tge given linked list at a specified
 * position.
 *
 * @param list The linked list to where the node to be changed is present.
 * @param pos The position of the node to be changed.
 * @param val The new value to be assigned to the node.
 */
void change_node(linked_list *list, int pos, void *val);

#endif
