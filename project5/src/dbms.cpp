#include "dbms.hpp"

Database::Database(int num_buffer) :
    tables(), buffers(num_buffer), locks(), logs(), trxs(locks)
{
    locks.set_database(*this);
}

tableid_t Database::open_table(std::string const& filename) {
    return tables.load(filename, buffers);
}

Status Database::close_table(tableid_t id) {
    Table const* table = tables.find(id);
    CHECK_NULL(table);

    buffers.release_file(table->fileid());
    return tables.remove(id);
}

Status Database::print_tree(tableid_t id) {
    return wrapper(id, Status::FAILURE, &Table::print_tree);
}

Status Database::find(tableid_t id, prikey_t key, Record* record, trxid_t xid) {
    return wrapper(id, Status::FAILURE, &Table::find, key, record);
}

std::vector<Record> Database::find_range(
    tableid_t id, prikey_t start, prikey_t end
) {
    return wrapper(id, std::vector<Record>(), &Table::find_range, start, end);
}

Status Database::insert(
    tableid_t id, prikey_t key, uint8_t const* value, int value_size
) {
    return wrapper(id, Status::FAILURE, &Table::insert, key, value, value_size);
}

Status Database::remove(tableid_t id, prikey_t key) {
    return wrapper(id, Status::FAILURE, &Table::remove, key);
}

Status Database::destroy_tree(tableid_t id) {
    return wrapper(id, Status::FAILURE, &Table::destroy_tree);
}

Table const* Database::operator[](tableid_t id) const {
    return tables.find(id);
}

trxid_t Database::begin_trx() {
    return trxs.new_trx();
}

Status Database::end_trx(trxid_t id) {
    return trxs.end_trx(id);
}

Status Database::abort_trx(trxid_t id) {
    return trxs.abort_trx(id, logs);
}
