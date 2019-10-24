#include "bpt.h"
#include "test.h"

TEST_SUITE(swap_ubuffer, {

})

TEST_SUITE(enqueue, {

})

TEST_SUITE(dequeue, {

})

TEST_SUITE(record_vec_init, {

})

TEST_SUITE(record_vec_free, {

})

TEST_SUITE(record_vec_expand, {

})

TEST_SUITE(record_vec_append, {

})

TEST_SUITE(height, {

})

TEST_SUITE(path_to_root, {

})

TEST_SUITE(cut, {

})

TEST_SUITE(find_leaf, {

})

TEST_SUITE(find_key_from_leaf, {

})

TEST_SUITE(bpt_find, {

})

TEST_SUITE(bpt_find_range, {

})

TEST_SUITE(print_leaves, {

})

TEST_SUITE(print_tree, {

})

TEST_SUITE(find_and_print, {

})

TEST_SUITE(find_and_print_range, {

})

TEST_SUITE(make_record, {

})

TEST_SUITE(make_node, {

})

TEST_SUITE(get_index, {

})

TEST_SUITE(insert_into_leaf, {

})

TEST_SUITE(insert_into_leaf_after_splitting, {

})

TEST_SUITE(insert_into_node, {

})

TEST_SUITE(insert_into_node_after_splitting, {

})

TEST_SUITE(insert_into_parent, {

})

TEST_SUITE(insert_into_new_root, {

})

TEST_SUITE(start_new_tree, {

})

TEST_SUITE(bpt_insert, {

})

TEST_SUITE(shrink_root, {

})

TEST_SUITE(merge_nodes, {

})

TEST_SUITE(redistribute_nodes, {

})

TEST_SUITE(delete_entry, {

})

TEST_SUITE(bpt_delete, {

})

TEST_SUITE(destroy_tree, {
    
})

int bpt_test() {
    return swap_ubuffer_test()
        && enqueue_test()
        && dequeue_test()
        && record_vec_init_test()
        && record_vec_free_test()
        && record_vec_expand_test()
        && record_vec_append_test()
        && height_test()
        && path_to_root_test()
        && cut_test()
        && find_leaf_test()
        && find_key_from_leaf_test()
        && bpt_find_test()
        && bpt_find_range_test()
        && print_leaves_test()
        && print_tree_test()
        && find_and_print_test()
        && find_and_print_range_test()
        && make_record_test()
        && make_node_test()
        && get_index_test()
        && insert_into_leaf_test()
        && insert_into_leaf_after_splitting_test()
        && insert_into_node_test()
        && insert_into_node_after_splitting_test()
        && insert_into_parent_test()
        && insert_into_new_root_test()
        && start_new_tree_test()
        && bpt_insert_test()
        && shrink_root_test()
        && merge_nodes_test()
        && redistribute_nodes_test()
        && delete_entry_test()
        && bpt_delete_test()
        && destroy_tree_test();
}
