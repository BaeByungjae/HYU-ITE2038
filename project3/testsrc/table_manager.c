// #include <stdlib.h>

// #include "table_manager.h"
// #include "test.h"

// TEST_SUITE(table_searching_policy, {
//     const int capacity = 5;
//     struct table_vec_t vec;
//     TEST_SUCCESS(table_vec_init(&vec, capacity));

//     int i;
//     struct table_t table;
//     for (i = 0; i < 3 * capacity; ++i) {
//         table.table_id = i;
//         TEST_SUCCESS(table_vec_append(&vec, &table));
//     }

//     for (i = 0; i < 3 * capacity; ++i) {
//         TEST(table_searching_policy(&vec, i) == i);
//     }
//     TEST(table_searching_policy(&vec, 100) == -1);
//     TEST(table_searching_policy(&vec, -100) == -1);
//     free(vec.array);
// })

// TEST_SUITE(table_vec_init, {
//     struct table_vec_t vec;
//     TEST_SUCCESS(table_vec_init(&vec, 5));
//     TEST(vec.size == 0);
//     TEST(vec.capacity == 5);
//     TEST(vec.array != NULL);
//     free(vec.array);
// })

// TEST_SUITE(table_vec_extend, {
//     const int capacity = 5;
//     struct table_vec_t vec;
//     TEST_SUCCESS(table_vec_init(&vec, capacity));

//     vec.size += 2;
//     vec.array[0] = malloc(sizeof(struct table_t));
//     vec.array[0]->table_id = 100;

//     vec.array[1] = malloc(sizeof(struct table_t));
//     vec.array[1]->table_id = 200;

//     struct table_t** prev = vec.array;
//     TEST_SUCCESS(table_vec_extend(&vec));

//     TEST(vec.capacity == 2 * capacity);
//     TEST(vec.size == 2);
//     TEST(vec.array != prev);
//     TEST(vec.array[0]->table_id == 100);
//     TEST(vec.array[1]->table_id == 200);

//     TEST_SUCCESS(table_vec_extend(&vec));
//     TEST(vec.capacity == 4 * capacity);

//     free(vec.array);
// })

// TEST_SUITE(table_vec_append, {
//     const int capacity = 5;
//     struct table_vec_t vec;
//     TEST_SUCCESS(table_vec_init(&vec, capacity));

//     int i;
//     struct table_t table;
//     for (i = 0; i < capacity * 3; ++i) {
//         table.table_id = i;
//         TEST_SUCCESS(table_vec_append(&vec, &table));
//     }

//     TEST(vec.capacity == 4 * capacity);
//     TEST(vec.size == 3 * capacity);

//     for (i = 0; i < capacity * 3; ++i) {
//         TEST(vec.array[i]->table_id == i);
//     }
//     free(vec.array);
// })

// TEST_SUITE(table_vec_find, {
//     const int capacity = 5;
//     struct table_vec_t vec;
//     TEST_SUCCESS(table_vec_init(&vec, capacity));

//     int i;
//     struct table_t table;
//     for (i = 0; i < capacity * 3; ++i) {
//         table.table_id = i;
//         TEST_SUCCESS(table_vec_append(&vec, &table));
//     }

//     struct table_t* found;
//     for (i = 0; i < capacity * 3; ++i) {
//         found = table_vec_find(&vec, i);
//         TEST(found != NULL);
//         TEST(found->table_id == i);
//     }

//     TEST(table_vec_find(&vec, -100) == NULL);
//     TEST(table_vec_find(&vec, 100) == NULL);

//     free(vec.array);
// })

// TEST_SUITE(table_vec_remove, {
//     const int capacity = 5;
//     struct table_vec_t vec;
//     TEST_SUCCESS(table_vec_init(&vec, capacity));

//     const int size = capacity * 3;

//     int i;
//     struct table_t table;
//     for (i = 0; i < size; ++i) {
//         table.table_id = i;
//         TEST_SUCCESS(table_vec_append(&vec, &table));
//     }

//     int* origin = malloc(sizeof(int) * size);
//     for (i = 0; i < size; ++i) {
//         origin[i] = i;
//     }

//     int j;
//     int idx;
//     int rest = size;
//     int* shuffled = malloc(sizeof(int) * size);

//     srand(1024);
//     for (i = 0; i < size; ++i) {
//         idx = rand() % rest;
//         shuffled[i] = origin[idx];
//         for (j = idx; j < rest - 1; ++j) {
//             origin[j] = origin[j + 1];
//         }
//         rest -= 1;
//     }

//     for (i = 0; i < size; ++i) {
//         TEST_SUCCESS(table_vec_remove(&vec, shuffled[i]));
//         TEST(table_vec_find(&vec, shuffled[i]) == NULL);
//         TEST(vec.size == size - i - 1);
//     }

//     TEST(table_vec_remove(&vec, 0) == FAILURE);

//     free(origin);
//     free(shuffled);
//     free(vec.array);
// })

// TEST_SUITE(table_vec_shrink, {
//     const int capacity = 5;
//     struct table_vec_t vec;
//     TEST_SUCCESS(table_vec_init(&vec, capacity));

//     int i;
//     struct table_t table;
//     for (i = 0; i < capacity * 3; ++i) {
//         table.table_id = i;
//         TEST_SUCCESS(table_vec_append(&vec, &table));
//     }

//     TEST(vec.size != vec.capacity);

//     struct table_t** prev = vec.array;
//     TEST_SUCCESS(table_vec_shrink(&vec));
//     TEST(vec.size == capacity * 3);
//     TEST(vec.size == vec.capacity);
//     TEST(vec.array != prev);

//     for (i = 0; i < capacity * 3; ++i) {
//         TEST(vec.array[i]->table_id == i);
//     }

//     free(vec.array);
// })

// TEST_SUITE(table_vec_release, {
//     const int capacity = 5;
//     struct table_vec_t vec;
//     TEST_SUCCESS(table_vec_init(&vec, capacity));
//     TEST_SUCCESS(table_vec_release(&vec));
//     TEST(vec.size == 0);
//     TEST(vec.capacity == 0);
//     TEST(vec.array == NULL);
// })

// TEST_SUITE(table_manager_init, {
//     const int capacity = 5;
//     struct table_manager_t manager;
//     TEST_SUCCESS(table_manager_init(&manager, capacity));

//     TEST(manager.vec.size == 0);
//     TEST(manager.vec.capacity == capacity);
//     TEST(manager.vec.array != NULL);

//     TEST_SUCCESS(table_vec_release(&manager.vec));
// })

// TEST_SUITE(table_manager_load, {
//     const int capacity = 5;
//     struct table_manager_t manager;
//     TEST_SUCCESS(table_manager_init(&manager, capacity));

//     tablenum_t res = table_manager_load(&manager, "testfile");
//     TEST(res != INVALID_TABLENUM);

//     struct table_t* table = table_vec_find(&manager.vec, res);
//     TEST(table != NULL);
//     TEST(table->table_id == res);

//     TEST_SUCCESS(table_vec_release(&manager.vec));
//     remove("testfile");
// })

// TEST_SUITE(table_manager_find, {
//     const int capacity = 5;
//     struct table_manager_t manager;
//     TEST_SUCCESS(table_manager_init(&manager, capacity));

//     int i;
//     char str[] = "testfile0";
//     tablenum_t arr[10];
//     for (i = 0; i < 10; ++i) {
//         str[8] = i + 0x30;
//         arr[i] = table_manager_load(&manager, str);
//         TEST(arr[i] != INVALID_TABLENUM);
//     }

//     for (i = 0; i < 10; ++i) {
//         TEST(table_manager_find(&manager, arr[i]) != NULL);
//     }

//     TEST_SUCCESS(table_vec_release(&manager.vec));
//     for (i = 0; i < 10; ++i) {
//         str[8] = i + 0x30;
//         remove(str);
//     }
// })

// TEST_SUITE(table_manager_remove, {
//     const int capacity = 5;
//     struct table_manager_t manager;
//     TEST_SUCCESS(table_manager_init(&manager, capacity));

//     int i;
//     char str[] = "testfile0";
//     tablenum_t arr[10];
//     for (i = 0; i < 10; ++i) {
//         str[8] = i + 0x30;
//         arr[i] = table_manager_load(&manager, str);
//         TEST(arr[i] != INVALID_TABLENUM);
//     }

//     for (i = 0; i < 10; ++i) {
//         TEST_SUCCESS(table_manager_remove(&manager, arr[i]));
//         TEST(table_manager_find(&manager, arr[i]) == NULL);
//     }

//     TEST_SUCCESS(table_vec_release(&manager.vec));
//     for (i = 0; i < 10; ++i) {
//         str[8] = i + 0x30;
//         remove(str);
//     }
// })

// TEST_SUITE(table_manager_release, {
//     const int capacity = 5;
//     struct table_manager_t manager;
//     TEST_SUCCESS(table_manager_init(&manager, capacity));
//     TEST_SUCCESS(table_manager_release(&manager));
//     TEST(manager.vec.size == 0);
//     TEST(manager.vec.capacity == 0);
//     TEST(manager.vec.array == NULL);
// })

// int table_manager_test() {
//     return table_searching_policy_test()
//         && table_vec_init_test()
//         && table_vec_extend_test()
//         && table_vec_append_test()
//         && table_vec_find_test()
//         && table_vec_remove_test()
//         && table_vec_shrink_test()
//         && table_vec_release_test()
//         && table_manager_init_test()
//         && table_manager_load_test()
//         && table_manager_find_test()
//         && table_manager_remove_test()
//         && table_manager_release_test();
// }