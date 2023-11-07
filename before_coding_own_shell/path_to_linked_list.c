#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the linked list node
struct PathNode {
    char *directory;
    struct PathNode *next;
};

// Function to create a new linked list node
struct PathNode *createPathNode(const char *dir) {
    struct PathNode *node = (struct PathNode *)malloc(sizeof(struct PathNode));
    if (node) {
        node->directory = strdup(dir);
        node->next = NULL;
    }
    return node;
}

// Function to insert a new node at the end of the linked list
void insertPathNode(struct PathNode **head, const char *dir) {
    if (*head == NULL) {
        *head = createPathNode(dir);
    } else {
        struct PathNode *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = createPathNode(dir);
    }
}

// Function to print the linked list
void printPathList(struct PathNode *head) {
    struct PathNode *current = head;
    while (current != NULL) {
        printf("%s\n", current->directory);
        current = current->next;
    }
}

int main() {
    char *path = getenv("PATH");
    if (path == NULL) {
        printf("PATH environment variable not set.\n");
        return 1;
    }

    struct PathNode *pathList = NULL;
    char *token = strtok(path, ":");
    while (token != NULL) {
        insertPathNode(&pathList, token);
        token = strtok(NULL, ":");
    }

    printf("Linked list of directories in PATH:\n");
    printPathList(pathList);

    // Free memory allocated for the linked list
    struct PathNode *current = pathList;
    while (current != NULL) {
        struct PathNode *temp = current;
        current = current->next;
        free(temp->directory);
        free(temp);
    }

    return 0;
}
