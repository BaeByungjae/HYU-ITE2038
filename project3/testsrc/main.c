#include "test.h"

TEST_SUITE(unit, {
    TEST(fileio_test());
    TEST(headers_test());
    TEST(disk_manager_test());
})

int main() {
    remove("testfile");
    unit_test();
}
