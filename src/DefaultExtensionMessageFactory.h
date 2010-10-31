/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2006 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
/* copyright --> */
#ifndef D_DEFAULT_EXTENSION_MESSAGE_FACTORY_H
#define D_DEFAULT_EXTENSION_MESSAGE_FACTORY_H

#include "ExtensionMessageFactory.h"

namespace aria2 {

class PeerStorage;
class Peer;
class Logger;
class ExtensionMessageRegistry;
class DownloadContext;
class BtMessageFactory;
class BtMessageDispatcher;
class UTMetadataRequestTracker;

class DefaultExtensionMessageFactory:public ExtensionMessageFactory {
private:
  SharedHandle<PeerStorage> peerStorage_;

  SharedHandle<Peer> peer_;

  SharedHandle<ExtensionMessageRegistry> registry_;

  SharedHandle<DownloadContext> dctx_;

  WeakHandle<BtMessageFactory> messageFactory_;

  WeakHandle<BtMessageDispatcher> dispatcher_;

  WeakHandle<UTMetadataRequestTracker> tracker_;

  Logger* logger_;

public:
  DefaultExtensionMessageFactory();

  DefaultExtensionMessageFactory
  (const SharedHandle<Peer>& peer,
   const SharedHandle<ExtensionMessageRegistry>& registry);

  virtual ~DefaultExtensionMessageFactory();

  virtual SharedHandle<ExtensionMessage>
  createMessage(const unsigned char* data, size_t length);

  void setPeerStorage(const SharedHandle<PeerStorage>& peerStorage);

  void setPeer(const SharedHandle<Peer>& peer);

  void setExtensionMessageRegistry
  (const SharedHandle<ExtensionMessageRegistry>& registry)
  {
    registry_ = registry;
  }

  void setDownloadContext(const SharedHandle<DownloadContext>& dctx)
  {
    dctx_ = dctx;
  }

  void setBtMessageFactory(const WeakHandle<BtMessageFactory>& factory)
  {
    messageFactory_ = factory;
  }

  void setBtMessageDispatcher(const WeakHandle<BtMessageDispatcher>& disp)
  {
    dispatcher_ = disp;
  }
  
  void setUTMetadataRequestTracker
  (const WeakHandle<UTMetadataRequestTracker>& tracker)
  {
    tracker_ = tracker;
  }
};

typedef SharedHandle<DefaultExtensionMessageFactory> DefaultExtensionMessageFactoryHandle;

} // namespace aria2

#endif // D_DEFAULT_EXTENSION_MESSAGE_FACTORY_H
