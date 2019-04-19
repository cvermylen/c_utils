#include <criterion/criterion.h>
#include "../src/hashmap.h"

Test(hashmap, init)
{
	hashmap_t *hm = hashmap_init(100);
	cr_assert(hashmap_capacity(hm) == 100, "Initial capacity should be 100, not:%d", hashmap_capacity(hm));
}

Test(hashmap, key)
{
	unsigned long k = p_hashmap_hash(100, "aKey");
	cr_assert(k == 19, "Calculated key for 'aKey' should be 19, not: %ld", k);
}

Test(hashmap, put_1)
{
	hashmap_t *hm = hashmap_init(100);
	hashmap_put(hm, "aKey", "aValue");
	cr_assert(hashmap_capacity(hm) == 100, "Adding an element should not impact the capacity, not:%d", hashmap_capacity(hm));
}

Test(hashmap, get_1)
{
	hashmap_t *hm = hashmap_init(100);
	hashmap_put(hm, "aKey", "aValue");
	char* value = hashmap_get(hm, "aKey");
	cr_assert(strcmp("aValue", value)==0, "Should have returned the value previously stored:%s", value);
	free(value);
}



Test(hashmap, collision_1)
{
	hashmap_t *hm = hashmap_init(1);
	hashmap_put(hm, "aFirstKey", "aValue");
	hashmap_put(hm, "aSecondKey", "anotherValue");
	char* res = hashmap_get(hm, "aFirstKey");
	cr_assert(strcmp("aValue", res)==0, "Should have returned the first entry, not:%s", res);
	free(res);
	res = hashmap_get(hm, "aSecondKey");
	cr_assert(strcmp("anotherValue", res)==0, "Should have returned the second entry, not:%s", res);
	free(res);
}

Test(hashmap, get_3)
{
	hashmap_t* hm = hashmap_init(10);
	hashmap_put(hm, "key1", "value1");
	hashmap_put(hm, "key2", "value2");
	hashmap_put(hm, "key3", "value3");
	char* res = hashmap_get(hm, "key2");
	cr_assert(strcmp("value2", res) == 0, "Expected second value, not:%s", res);
	free(res);
	res = hashmap_get(hm, "key1");
	cr_assert(strcmp("value1", res) == 0, "Expected first value, not:%s", res);
	free(res);
	res = hashmap_get(hm, "key3");
	cr_assert(strcmp("value3", res) == 0, "Expected third value, not:%s", res);
	hashmap_release(hm);
}

Test(hashmap, immutable)
{
	hashmap_t* hm = hashmap_init(10);
	char* str = "Hello World";
	hashmap_put(hm, "key", str);
	str = "Nice day";
	char* res = hashmap_get(hm, "key");
	cr_assert(strcmp("Hello World", res) == 0, "Expected to return first value, not: %s", res);
}
