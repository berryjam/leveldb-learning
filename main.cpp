#include <iostream>
#include "leveldb/db.h"

int main(int argc, char **argv)
{
    leveldb::DB *db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    assert(status.ok());

    std::string key = "key";
    std::string value = "value";
    db->Put(leveldb::WriteOptions(), key, value);

    for (int i = 0; i < 1000; i++)
    {
        char str[100];
        snprintf(str, sizeof(str), "%d", i);
        status = db->Put(leveldb::WriteOptions(), str, str);
    }
    status = db->Get(leveldb::ReadOptions(), key, &value);
    assert(status.ok());
    std::cout << value << std::endl;
    std::string key2 = "key2";

    status = db->Put(leveldb::WriteOptions(), key2, value);
    assert(status.ok());
    status = db->Delete(leveldb::WriteOptions(), key);

    assert(status.ok());

    status = db->Get(leveldb::ReadOptions(), key2, &value);

    assert(status.ok());
    std::cout << key2 << "===" << value << std::endl;

    status = db->Get(leveldb::ReadOptions(), key, &value);

    if (!status.ok())
        std::cerr << key << " " << status.ToString() << std::endl;
    else
        std::cout << key << "===" << value << std::endl;

    delete db;

    return 0;
}