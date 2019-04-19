#ifndef HASHMAP_C
#define HASHMAP_C

typedef struct key_value_pair key_value_pair_t;
struct key_value_pair {
	char* key;
	char* value;
	key_value_pair_t* next;
};

typedef struct {
	int capacity;
	key_value_pair_t** kvp;
}hashmap_t;

hashmap_t* hashmap_init(const int initial_capacity);

int hashmap_capacity(const hashmap_t* hashmap);

unsigned long p_hashmap_hash(int capacity, char* key);

void hashmap_put(hashmap_t* hashmap, char* key, char* value);

char* hashmap_get(hashmap_t* hashmap, char* key);

void hashmap_release(hashmap_t* hashmap);

#endif
