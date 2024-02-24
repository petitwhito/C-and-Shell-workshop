#include "hash_map.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash_map *hash_map_init(size_t size)
{
    struct hash_map *res = malloc(sizeof(struct hash_map));
    if (!res)
    {
        return NULL;
    }
    res->size = size;
    res->data = malloc(sizeof(struct pair_list) * size);
    for (size_t i = 0; i < size; i++)
    {
        res->data[i] = NULL;
    }
    if (!res->data)
        return NULL;
    return res;
}

bool hash_map_insert(struct hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    if (!hash_map || hash_map->size == 0)
        return false;

    size_t hash_value = hash(key);

    hash_value = hash_value % hash_map->size;

    if (hash_map->data[hash_value]
        && strcmp(hash_map->data[hash_value]->key, key) == 0)
    {
        hash_map->data[hash_value]->key = key;
        hash_map->data[hash_value]->value = value;
        if (updated)
            *updated = true;
        return true;
    }

    struct pair_list *add = malloc(sizeof(struct pair_list));

    if (!add)
        return false;

    add->key = key;
    add->value = value;
    add->next = NULL;

    if (!hash_map->data[hash_value])
    {
        hash_map->data[hash_value] = add;
        if (updated)
            *updated = false;
        return true;
    }

    if (updated)
        *updated = false;
    add->next = hash_map->data[hash_value];
    hash_map->data[hash_value] = add;
    return true;
}

void hash_map_free(struct hash_map *hash_map)
{
    if (!hash_map)
        return;
    for (size_t i = 0; i < hash_map->size; i++)
    {
        struct pair_list *tmp = hash_map->data[i];
        struct pair_list *tmp1 = hash_map->data[i];
        while (tmp1)
        {
            tmp1 = tmp1->next;
            free(tmp);
            tmp = tmp1;
        }
    }
    free(hash_map->data);
    free(hash_map);
}

void hash_map_dump(struct hash_map *hash_map)
{
    for (size_t i = 0; i < hash_map->size; i++)
    {
        int escape = 0;
        struct pair_list *tmp = hash_map->data[i];
        if (tmp)
            escape = 1;
        while (tmp)
        {
            printf("%s: %s", tmp->key, tmp->value);
            tmp = tmp->next;
            if (tmp)
                printf(", ");
        }
        if (escape)
            printf("\n");
    }
}

const char *hash_map_get(const struct hash_map *hash_map, const char *key)
{
    if (!hash_map)
        return NULL;
    for (size_t i = 0; i < hash_map->size; i++)
    {
        struct pair_list *tmp = hash_map->data[i];
        while (tmp)
        {
            if (strcmp(tmp->key, key) == 0)
                return tmp->value;
            tmp = tmp->next;
        }
    }
    return NULL;
}

bool hash_map_remove(struct hash_map *hash_map, const char *key)
{
    if (!hash_map)
        return NULL;
    for (size_t i = 0; i < hash_map->size; i++)
    {
        if (!hash_map->data[i])
            continue;
        struct pair_list *tmp = hash_map->data[i]->next;
        struct pair_list *tmp2 = hash_map->data[i];
        while (tmp2)
        {
            if (strcmp(tmp2->key, key) == 0 && tmp)
            {
                free(tmp2);
                hash_map->data[i] = tmp;
                return true;
            }
            else if (strcmp(tmp2->key, key) == 0 && !tmp)
            {
                hash_map->data[i] = NULL;
                free(tmp2);
                return true;
            }
            else if (tmp && strcmp(tmp->key, key) == 0 && !tmp->next)
            {
                free(tmp);
                tmp2->next = NULL;
                return true;
            }
            else if (tmp && strcmp(tmp->key, key) == 0 && tmp->next)
            {
                tmp->key = NULL;
                tmp->value = NULL;
                tmp2->next = tmp->next;
                free(tmp);
                return true;
            }
            tmp2 = tmp2->next;
            if (tmp)
                tmp = tmp->next;
        }
    }
    return false;
}
