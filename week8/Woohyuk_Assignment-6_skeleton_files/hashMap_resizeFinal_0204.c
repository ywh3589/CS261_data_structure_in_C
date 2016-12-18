/*
 * CS 261 Data Structures
 * Assignment 6
 * Name: 
 * Date: 
 */

#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int hashFunction1(const char* key)
{
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        r += key[i];
    }
    return r;
}

int hashFunction2(const char* key)
{
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        r += (i + 1) * key[i];
    }
    return r;
}

/**
 * Creates a new hash table link with a copy of the key string.
 * @param key Key string to copy in the link.
 * @param value Value to set in the link.
 * @param next Pointer to set as the link's next.
 * @return Hash table link allocated on the heap.
 */
HashLink* hashLinkNew(const char* key, int value, HashLink* next)
{
    HashLink* link = malloc(sizeof(HashLink));
    link->key = malloc(sizeof(char) * (strlen(key) + 1));
    strcpy(link->key, key);
    link->value = value;
    link->next = next;
    return link;
}

/**
 * Free the allocated memory for a hash table link created with hashLinkNew.
 * @param link
 */
static void hashLinkDelete(HashLink* link)
{
    free(link->key);
    free(link);
}

/**
 * Initializes a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param map
 * @param capacity The number of table buckets.
 */
void hashMapInit(HashMap* map, int capacity)
{
    map->capacity = capacity;
    map->size = 0;
    map->table = malloc(sizeof(HashLink*) * capacity);
    for (int i = 0; i < capacity; i++)
    {
        map->table[i] = NULL;
    }
}

/**
 * Removes all links in the map and frees all allocated memory. You can use
 * hashLinkDelete to free the links.
 * @param map
 */
void hashMapCleanUp(HashMap* map)
{
    // FIXME: implement
    int capacity = map->capacity;
    HashLink *delNode; 
    //HashLink* pBucket = map->table[0];
    for(int i = 0; i < capacity; i++)
    {
    	HashLink* pLink = map->table[i];
    //	delNode = pLink;
    	while(pLink!=NULL)
    	{
    		delNode = pLink;
    		hashLinkDelete(delNode);
    		map->size--;
    		pLink = pLink->next;
    	}
    //		pBucket++;
    }
}

/**
 * Creates a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param capacity The number of buckets.
 * @return The allocated map.
 */
HashMap* hashMapNew(int capacity)
{
    HashMap* map = malloc(sizeof(HashMap));
    hashMapInit(map, capacity);
    return map;
}

/**
 * Removes all links in the map and frees all allocated memory, including the
 * map itself.
 * @param map
 */
void hashMapDelete(HashMap* map)
{
    hashMapCleanUp(map);
    free(map);
}

/**
 * Returns a pointer to the value of the link with the given key. Returns NULL
 * if no link with that key is in the table.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @return Link value or NULL if no matching link.
 */
int* hashMapGet(HashMap* map, const char* key)
{
    // FIXME: implement
    int idx = HASH_FUNCTION(key) % (map->capacity);
    if(idx < 0) idx += map->capacity;

    int* pInt = NULL;

	if(map->table[idx] != NULL)
	{
		HashLink* pLink = map->table[idx];
		while(pLink!=NULL)
		{
			if(!strcmp(pLink->key,key))
			{
				pInt = &(pLink->value);
				return pInt;
			}	
			
			pLink = pLink->next;
		} 
	}
	return NULL;   
}

/**
 * Resizes the hash table to have a number of buckets equal to the given
 * capacity. After allocating the new table, all of the links need to be
 * rehashed into it because the capacity has changed.
 * 
 * Remember to free the old table and any old links if you use hashMapPut to
 * rehash them.
 * 
 * @param map
 * @param capacity The new number of buckets.
 */
void resizeTable(HashMap* map, int capacity)
{
	printf("\nresize function being used\n");
    // FIXME: implement
    HashLink** oldTable = map->table;
    int size = map->size;

    HashMap* pNewHashMap = hashMapNew(capacity);
    HashLink** newTable = pNewHashMap->table;

    //printf("%d,inside_resize_function\n",__LINE__);
    //int newIdx;
    //HashLink* pBuckt = map->table[0];
    for(int i = 0 ; i < map->capacity; i++)
    {

    //	 printf("%d,inside_resize_function\n",__LINE__);
    	HashLink *pLink = map->table[i];
    //	 printf("%d,inside_resize_function\n",__LINE__);


    	while(pLink != NULL)
    	{ 
    		//new Index
    		//int newIdx = HASH_FUNCTION(pLink->key) % capacity;
    		//if(newIdx < 0) newIdx+=capacity;
    		HashLink *tempLink = pLink->next;

    		int newIdx = HASH_FUNCTION(pLink->key) % capacity;
    		if(newIdx < 0) newIdx += capacity;

    		pLink->next = newTable[newIdx];
    		newTable[newIdx] = pLink;
    		pLink = tempLink;  	
    	}
    	
	}
	
	free(oldTable);
	map->capacity = capacity;
	map->size = size;
	map->table = newTable;
	return;
}

/**
 * Updates the given key-value pair in the hash table. If a link with the given
 * key already exists, this will just update the value. Otherwise, it will
 * create a new link with the given key and value and add it to the table
 * bucket's linked list. You can use hashLinkNew to create the link.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @param value
 */
//HashLink* hashLinkNew(const char* key, int value, HashLink* next)
void hashMapPut(HashMap* map, const char* key, int value)
{
	//printf("%d,inside_hash_Map_put_FUnction\n",__LINE__);
	if(hashMapTableLoad(map) > MAX_TABLE_LOAD)
		resizeTable(map, 3 * map->capacity);
    // FIXME: implement
    int idx = HASH_FUNCTION(key) % (map->capacity);
    if(idx < 0) idx += map->capacity;

    	HashLink *pLink = map->table[idx]; 	
    	//printf("%d,inside_hash_Map_put_FUnction\n",__LINE__);
    	if(map->table[idx] == NULL) //if something does not exist
    	{
    		
    		
    		map->table[idx] = hashLinkNew(key, value, map->table[idx]);
    	//	printf("%d,inside_hash_Map_put_FUnction\n",__LINE__);
    		map->size++;
    	//	printf("%d,inside_hash_Map_put_FUnction\n",__LINE__);
    	}
    	else  //if something exists.
    	{	
    		
    		//time to iterate to find the value with the key
    		while(pLink != NULL)
    		{//printf("%d,inside_hash_Map_put_FUnction\n",__LINE__);
    			if(!strcmp(pLink->key, key)) //same key
    			{
    				pLink->value = value;
    			//	printf("%d,inside_hash_Map_put_FUnction\n",__LINE__);
    				return;
    			}
    			pLink = pLink->next;	
    			//printf("%d,inside_hash_Map_put_FUnction\n",__LINE__);
    		}

    		
    		
    		map->table[idx] = hashLinkNew(key, value, map->table[idx]);
    		//printf("%d,inside_hash_Map_put_FUnction\n",__LINE__);
    		map->size++;
    	//	printf("%d,inside_hash_Map_put_FUnction\n",__LINE__);
    			
    	}	
    	
    
}

/**
 * Removes and frees the link with the given key from the table. If no such link
 * exists, this does nothing. Remember to search the entire linked list at the
 * bucket. You can use hashLinkDelete to free the link.
 * @param map
 * @param key
 */
void hashMapRemove(HashMap* map, const char* key)
{
    // FIXME: implement
	int idx = HASH_FUNCTION(key) % (map->capacity);
	if(idx < 0) idx += map->capacity;
#if 0
	if(!hashMapContainsKey(map, key))
	{
		printf("there is no link with the given key\n");
		return;
	}
#endif
	HashLink *pLink = map->table[idx];
	HashLink *pBefore;
	HashLink *pDelete;
	HashLink *pNext = pLink->next;
	//case 0. there is no bucket with the index
	if(map->table[idx] == NULL)
	{
		printf("there is nothing which match with this key\n");
		return;
	}
	//case 1. there is only a link in the bucket and it matches
	//case 2. The first link in the bucket matches with the key but therer are other links in the bucket.
	else if(strcmp(pLink->key,key) == 0)
	{

			printf("only having first things\n");
				pDelete = pLink;
				map->table[idx] = pNext;
				hashLinkDelete(pDelete);
				map->size--;				

	}
	
	
	//case 3. there are bunch of links in the bucket
		//case3.1 there is nothing matches
		//case3.2 there is one among the lists.
	else
	{
		pBefore = pLink;
		pNext = pNext->next;
		pLink = pLink->next;

		while((pLink != NULL) && strcmp(pLink->key,key)!=0)
		{
			pBefore = pBefore->next;
			pLink = pLink->next;
			pNext = pNext->next;
		}
		if(pLink == NULL)
		{
			printf("there is nothing which match with this key\n");
			return;
		}
		else
		{	//found
			pBefore->next = pNext;
			hashLinkDelete(pLink);
			map->size--;

		}
	}
}	


/**
 * Returns 1 if a link with the given key is in the table and 0 otherwise.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @return 1 if the key is found, 0 otherwise.
 */
int hashMapContainsKey(HashMap* map, const char* key)
{
    // FIXME: implement
    int idx = HASH_FUNCTION(key) % (map->capacity);
    if(idx < 0) idx += map->capacity;
   // HashLink* pBucket = map->table[0];
    
    	HashLink* pLink = map->table[idx];
    	//printf("key = %s value = %d\n",pLink->key,pLink->value);
    	#if 0
    	if(pLink == NULL)
    	{
    		printf("%s, %d\n",__FILE__,__LINE__);

    		return 0;
    	}
    	#endif
    //	else
    //	{	
    	printf("%s,%d\n",__FILE__,__LINE__);
    		while(pLink!=NULL)
    		{
    			if(!strcmp(pLink->key,key))
    			{
    				printf("%s, %d\n",__FILE__,__LINE__);
    				printf("key = %s value = %d\n",pLink->key,pLink->value);
    				return 1;
    			}	
    			pLink = pLink->next;	
    		}
    		printf("%s,%d\n",__FILE__,__LINE__);
    		 return 0;
    //		pBucket++;
    //	}
    
   
}

/**
 * Returns the number of links in the table.
 * @param map
 * @return Number of links in the table.
 */
int hashMapSize(HashMap* map)
{
    // FIXME: implement
    return map->size;
}

/**
 * Returns the number of buckets in the table.
 * @param map
 * @return Number of buckets in the table.
 */
int hashMapCapacity(HashMap* map)
{
    // FIXME: implement
    return map->capacity;
}

/**
 * Returns the number of table buckets without any links.
 * @param map
 * @return Number of empty buckets.
 */
int hashMapEmptyBuckets(HashMap* map)
{
    // FIXME: implement
    int emptyCount = 0; 
    for(int i = 0 ; i < map->capacity; i++)
    {
    	if(map->table[i] == NULL)
    		emptyCount++;
    }
    return emptyCount;
}

/**
 * Returns the ratio of (number of links) / (number of buckets) in the table.
 * Remember that the buckets are linked lists, so this ratio tells you nothing
 * about the number of empty buckets. Remember also that the load is a floating
 * point number, so don't do integer division.
 * @param map
 * @return Table load.
 */
float hashMapTableLoad(HashMap* map)
{
    // FIXME: implement
    float numberOfLinks = (float)map->size;
    float numberOfBuckets = (float)map->capacity;

    return numberOfLinks/numberOfBuckets;
}

/**
 * Prints all the links in each of the buckets in the table.
 * @param map
 */
void hashMapPrint(HashMap* map)
{

	for (int i = 0; i < map->capacity; i++)
    {
        HashLink* link = map->table[i];
        if (link != NULL)
        {
            printf("\nBucket %i ->", i);
            while (link != NULL)
            {
                printf(" (%s, %d) ->", link->key, link->value);
                link = link->next;
            }
        }
    }
    printf("\n");
}