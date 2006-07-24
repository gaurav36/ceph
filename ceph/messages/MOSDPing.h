// -*- mode:C++; tab-width:4; c-basic-offset:2; indent-tabs-mode:t -*- 
/*
 * Ceph - scalable distributed file system
 *
 * Copyright (C) 2004-2006 Sage Weil <sage@newdream.net>
 *
 * This is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1, as published by the Free Software 
 * Foundation.  See file COPYING.
 * 
 */



#ifndef __MOSDPING_H
#define __MOSDPING_H

#include "msg/Message.h"


class MOSDPing : public Message {
 public:
  epoch_t map_epoch;

  MOSDPing(epoch_t e) : Message(MSG_OSD_PING), map_epoch(e) {
  }
  MOSDPing() {}

  virtual void decode_payload() {
	int off = 0;
	payload.copy(off, sizeof(map_epoch), (char*)&map_epoch);
	off += sizeof(map_epoch);
  }
  virtual void encode_payload() {
	payload.append((char*)&map_epoch, sizeof(map_epoch));
  }

  virtual char *get_type_name() { return "oping"; }
};

#endif
