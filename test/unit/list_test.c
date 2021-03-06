#include "container.h"
#include <stdio.h>

void assert(int, int, char *);

int main() {
  int source[10];

  ListNode head;
  ListNode *list = &head;
  for (int i = 0; i < sizeof(source) / sizeof(int); i++)
    list = list_push_back(list, &source[i]);

  list = &head;
  int count = 0;
  while (list->next) {
    list = list->next;
    assert(1, list->body == &source[count], "list->body == &source[count]");
    count++;
  }

  assert(10, count, "list->body == &source[count]");

  return 0;
}
