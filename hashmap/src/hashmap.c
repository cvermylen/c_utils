#include "hashmap.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

hashmap_t* hashmap_init(int initial_capacity)
{
	hashmap_t* res = (hashmap_t*)malloc(sizeof(hashmap_t));
	res->capacity = initial_capacity;
	res->kvp = (key_value_pair_t**)malloc(sizeof(key_value_pair_t*) * initial_capacity);
	bzero(res->kvp, sizeof(key_value_pair_t*) * initial_capacity);
	return res;
}

void hashmap_release(hashmap_t* hashmap)
{
	for(int i=0; i < hashmap->capacity; i++){
		key_value_pair_t* tmp = hashmap->kvp[i];
		key_value_pair_t* pred = NULL;
		while(tmp){
			pred = tmp;
			tmp = tmp->next;
			free(pred->key);
			free(pred->value);
			free(pred);
		}
	}
	free(hashmap->kvp);
	free(hashmap);
}

int hashmap_capacity(const hashmap_t* hashmap)
{
	return hashmap->capacity;
}

unsigned long p_hashmap_hash(int capacity, char* key)
{
	//long on 64 bits
	unsigned long res = 5381;
	int c;
	while((c = *key++)){
		res = ((res << 5) + res) + c;
	}
	return res % capacity;
}

void p_hashmap_add_to_list(hashmap_t* hashmap, unsigned long hash, char* key, char* value)
{
	key_value_pair_t* elem = (key_value_pair_t*)malloc(sizeof(key_value_pair_t));
	elem->key = (char*)malloc(sizeof(char) * (strlen(key) + 1));
	strcpy(elem->key, key);
	elem->value = (char*)malloc(sizeof(char) * (strlen(value) + 1));
	strcpy(elem->value, value);
	elem->next = hashmap->kvp[hash];
	hashmap->kvp[hash] = elem;
}

key_value_pair_t* p_hashmap_get_in_list(hashmap_t* hashmap, unsigned long hash, char* key)
{
	key_value_pair_t* res = hashmap->kvp[hash];
	while(res && strcmp(res->key, key)){
		res = res->next;
	}
	return res;
}

void hashmap_put(hashmap_t* hashmap, char* key, char* value)
{
	unsigned long hash = p_hashmap_hash(hashmap->capacity, key);
	key_value_pair_t* elem = p_hashmap_get_in_list(hashmap, hash, key);
	if(elem == NULL){
		p_hashmap_add_to_list(hashmap, hash, key, value);
	}else{
		free(elem->value);
		elem->value = (char*)malloc(sizeof(char) * (strlen(value) + 1));
		strcpy(elem->value, value);
	}
}

char* hashmap_get(hashmap_t* hashmap, char* key)
{
	unsigned long hash = p_hashmap_hash(hashmap->capacity, key);
	key_value_pair_t* kv = p_hashmap_get_in_list(hashmap, hash, key);
	char* res = NULL;
	if(kv){
		res = (char*)malloc(sizeof(char) *(strlen(kv->value) +1));
		strcpy(res, kv->value);
	}
	return res;
}
