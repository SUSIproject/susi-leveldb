/*
 * Copyright (c) 2016, Tino Rusch
 *
 * This file is released under the terms of the MIT license. You can find the
 * complete text in the attached LICENSE file or online at:
 *
 * http://www.opensource.org/licenses/mit-license.php
 *
 * @author: Tino Rusch (tino.rusch@webvariants.de)
 */

#include "leveldb/db.h"
#include "susi/SusiClient.h"

namespace Susi {
class LevelDBComponent {

public:
  LevelDBComponent(Susi::SusiClient &susi, std::string dbPath);
  void join();

protected:
  Susi::SusiClient &susi_;
  leveldb::Options dbOptions_;
  std::string dbPath_;
  std::shared_ptr<leveldb::DB> db_;

  bool validateFieldsForPut(const Susi::EventPtr &event);
  bool validateFieldsForGet(const Susi::EventPtr &event);
  bool validateFieldsForGetRange(const Susi::EventPtr &event);

  void handlePut(Susi::EventPtr event);
  void handleGet(Susi::EventPtr event);
  void handleDelete(Susi::EventPtr event);
  void handleGetPrefix(Susi::EventPtr event);
  void handleGetRange(Susi::EventPtr event);
};
}
